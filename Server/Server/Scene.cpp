////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:	2015/05/14
// Describe:
////////////////////////////////////////////////////////////////////////
#include "Scene.h"
#include "ozcollide/Sphere.h"
#include "Region.h"
#include "User.h"
#include "GameKernel.h"

using namespace ozcollide;

CScene::CScene()
{
	m_pSceneOctree = NULL;
	m_nMaxOctreeDepth = 0;
	m_fRegionSize = 0.0f;
	m_pSceneData = NULL;
}

CScene::~CScene()
{
	for (int i = 0; i < m_vecRegions.size(); ++i)
	{
		SAFE_RELEASE(m_vecRegions.at(i));
	}
	COctree::DestroyOctree(m_pSceneOctree);

	SAFE_DELETE(m_pSceneData);
}

bool CScene::Create(const CGameRecordRow& rRow)
{
	m_pSceneData = new CSceneData(rRow);
	CHECK_RETURN(m_pSceneData, false);
	//TO-DO：读取场景地图，获得BoundBox

	m_SceneBoundBox.setFromPoints(Point3f(0.0f, 0.0f, 0.0f), Point3f(10000, 8000, 9000));

	//建立八叉树，八叉树的边界必须是立方体
	Box OctreeBox;
	Sphere s(m_SceneBoundBox.center, m_SceneBoundBox.extent.len() / 2);
	Vec3f v3Extent(s.radius, s.radius, s.radius);
	OctreeBox.center = s.center;
	OctreeBox.extent = v3Extent;
	Box LeafBox;
	LeafBox.setFromPoints(Point3f(0.0f, 0.0f, 0.0f), SCENE_REGION_SIZE);
	m_pSceneOctree = COctree::CreateFullOctree(OctreeBox, SCENE_OCTREE_MAX_DEPTH, LeafBox);

	CHECK_RETURN(m_pSceneOctree, false);

	//初始化深度
	COctree* pOctree = m_pSceneOctree;
	for (; !pOctree->IsLeaf(); pOctree = pOctree->GetChildByIndex(0, 0, 0));
	m_nMaxOctreeDepth = pOctree->GetDepth();

	//初始化边长
	m_fRegionSize = pOctree->GetEdgeLength();

	//建立广播域
	this->BuildNeighborSet();

	return true;
}

void CScene::BuildNeighborSet()
{
	uint32_t u32NeighborAmount = (uint32_t)pow(8, m_nMaxOctreeDepth);
	int nRange = (int)pow(2, m_nMaxOctreeDepth);
	m_vecRegions.resize(u32NeighborAmount);
	this->BuildNeighborImpl(m_pSceneOctree);

	//为每个叶节点收集邻居节点，建立广播域
	for (int i = 0; i < m_vecRegions.size(); ++i)
	{
		CRegion* pRegion = m_vecRegions.at(i);
		if (pRegion == NULL)
		{
			continue;
		}

		const COctreeIndex& idxTree = pRegion->GetIndex();
		for (int x = -1; x < 2; ++x)
		{
			if (idxTree.x + x < 0 || idxTree.x + x >= nRange)
			{
				continue;
			}
			for (int y = -1; y < 2; ++y)
			{
				if (idxTree.y + y < 0 || idxTree.y + y >= nRange)
				{
					continue;
				}
				for (int z = -1; z < 2; ++z)
				{
					if (idxTree.z + z < 0 || idxTree.z + z >= nRange)
					{
						continue;
					}
					COctreeIndex idxNeighbor(idxTree.x + x, idxTree.y + y, idxTree.z + z);
					OBJID32 idRegion = this->OctreeIndexToRegionID(idxNeighbor);
					pRegion->AddNeighbor(m_vecRegions.at(idRegion));
				}
			}
		}
	}
}

void CScene::BuildNeighborImpl(COctree* pOctree)
{
	CHECK(pOctree);

	if (pOctree->IsLeaf())
	{
		OBJID32 idRegion = this->OctreeIndexToRegionID(pOctree->GetIndex());
		CRegion* pRegion = CRegion::CreateNew();
		IF_NOT (pRegion && pRegion->Create(idRegion, pOctree, this))
		{
			SAFE_RELEASE(pRegion);
			return;
		}
		
		m_vecRegions[idRegion] = pRegion;
		return;
	}

	for (int x = 0; x < 2; ++x)
	{
		for (int y = 0; y < 2; ++y)
		{
			for (int z = 0; z < 2; ++z)
			{
				this->BuildNeighborImpl(pOctree->GetChildByIndex(x, y, z));
			}
		}
	}
}

OBJID32 CScene::OctreeIndexToRegionID(const COctreeIndex& idxTree)
{
	//idx = x * 4^nDepth + y * 2^nDepth + z
	OBJID32 idRegion;

	idRegion = (OBJID32)(idxTree.x * pow(4, m_nMaxOctreeDepth) + idxTree.y * pow(2, m_nMaxOctreeDepth) + idxTree.z);

	return idRegion;
}

void CScene::OnTimer()
{
	
}

void CScene::OnTimeTrigger(const TimeTrigger_t& pTrigger)
{

}

bool CScene::IsValidPoint(const Point3f& ptPos)
{
	return m_SceneBoundBox.isInside(ptPos);
}

CRegion* CScene::QueryRegion(OBJID32 idRegion)
{
	return m_vecRegions.at(idRegion);
}

CRegion* CScene::QueryRegionByIndex(const COctreeIndex& idxTree)
{
	OBJID32 idRegion = this->OctreeIndexToRegionID(idxTree);

	return this->QueryRegion(idRegion);
}

CRegion* CScene::QueryRegionByPosition(const Point3f& ptPos)
{
	CHECK_RETURN(m_pSceneOctree, NULL);

	COctree* pOctree = m_pSceneOctree->GetOctreeByPoint(ptPos);
	if (pOctree == NULL || !pOctree->IsLeaf())
	{
		return NULL;
	}

	return this->QueryRegionByIndex(pOctree->GetIndex());
}

void CScene::BroadcastMsg(CMsgNetwork* pMsg)
{
	CHECK(pMsg);

	for (SCENE_OBJECT_MAP::iterator it = m_mapSceneObjects.begin(); it != m_mapSceneObjects.end(); ++it)
	{
		CSceneObject* pSceneObject = it->second;
		if (pSceneObject == NULL)
		{
			continue;
		}

		if (!pSceneObject->IsType(OBJ_USER))
		{
			continue;
		}

		CUser* pUser = NULL;
		IF_NOT (pSceneObject->QueryObject(OBJ_USER, IPP_OF(pUser)) && pUser)
		{
			continue;
		}

		pMsg->add_idpeer(pUser->GetPeerID());
	}

	CGameKernel::getInstance()->SendPipeMessage(THREAD_INDEX_SERVER_SOCKET, pMsg);
}

void CScene::BroadcastMsg(CRegion* pRegion, CMsgNetwork* pMsg)
{
	CHECK(pRegion);
	CHECK(pMsg);

	pRegion->BroadcastAreaMsg(pMsg);
}

void CScene::BroadcastMsg(const REGION_SET& setRegions, CMsgNetwork* pMsg)
{
	CHECK(pMsg);

	for (REGION_SET::iterator it = setRegions.begin(); it != setRegions.end(); ++it)
	{
		CRegion* pRegion = *it;
		if (pRegion == NULL)
		{
			continue;
		}

		pRegion->AddBroadcastPeerToMsg(pMsg);
	}

	CGameKernel::getInstance()->SendPipeMessage(THREAD_INDEX_SERVER_SOCKET, pMsg);
}

bool CScene::AddSceneObject(CSceneObject* pSceneObject)
{
	CHECK_RETURN(pSceneObject, false);

	m_mapSceneObjects.insert(std::make_pair(pSceneObject->GetID(), pSceneObject));

	return true;
}

bool CScene::RemoveSceneObject(CSceneObject* pSceneObject)
{
	CHECK_RETURN(pSceneObject, false);

	m_mapSceneObjects.erase(pSceneObject->GetID());

	return true;
}

bool CScene::CollectSceneObjects(CObjectType objType, SCENE_OBJECT_MAP& mapObjects)
{
	CHECK_RETURN(objType != OBJ_NONE, false);

	for (SCENE_OBJECT_MAP::iterator it = m_mapSceneObjects.begin(); it != m_mapSceneObjects.end(); ++it)
	{
		CSceneObject* pSceneObject = it->second;
		if (pSceneObject == NULL)
		{
			continue;
		}

		if (!pSceneObject->IsType(objType))
		{
			continue;
		}

		m_mapSceneObjects.insert(std::make_pair(pSceneObject->GetID(), pSceneObject));
	}

	return true;
}

bool CScene::CollectSceneObjects(const Point3f& ptPos, CObjectType objType, SCENE_OBJECT_MAP& mapObjects)
{
	CHECK_RETURN(objType != OBJ_NONE, false);

	if (!this->IsValidPoint(ptPos))
	{
		return false;
	}

	//只需要处理该点对应的Region即可
	CRegion* pRegion = this->QueryRegionByPosition(ptPos);
	if (pRegion == NULL)
	{
		return false;
	}

	return pRegion->CollectSceneObjects(ptPos, objType, mapObjects);
}

bool CScene::CollectSceneObjectsInSphere(const Point3f& ptCenter, float fRadius, CObjectType objType, SCENE_OBJECT_MAP& mapObjects)
{
	CHECK_RETURN(objType != OBJ_NONE, false);

	if (!this->IsValidPoint(ptCenter))
	{
		return false;
	}

	//圆形收集，先根据圆心计算出对应的Region，然后根据半径确定需要搜索的空间范围
	//只在这个区域进行收集以提高效率
	CRegion* pRegion = this->QueryRegionByPosition(ptCenter);
	if (pRegion == NULL)
	{
		return false;
	}

	int nCross = this->GetCrossRegionAmount(fRadius);
	int nRange = (int)pow(2, m_nMaxOctreeDepth);

	const COctreeIndex& idxRegion = pRegion->GetIndex();

	for (int x = -1 * nCross; x < nCross + 1; ++x)
	{
		if (idxRegion.x + x < 0 || idxRegion.x + x >= nRange)
		{
			continue;
		}
		for (int y = -1 * nCross; y < nCross + 1; ++y)
		{
			if (idxRegion.y + y < 0 || idxRegion.y + y >= nRange)
			{
				continue;
			}
			for (int z = -1 * nCross; z < nCross + 1; ++z)
			{
				if (idxRegion.z + z < 0 || idxRegion.z + z >= nRange)
				{
					continue;
				}
				COctreeIndex idxNeighbor(idxRegion.x + x, idxRegion.y + y, idxRegion.z + z);
				OBJID32 idRegion = this->OctreeIndexToRegionID(idxNeighbor);
				CRegion* pRegion = this->QueryRegion(idRegion);
				if (pRegion)
				{
					pRegion->CollectSceneObjectsInCircle(ptCenter, fRadius, objType, mapObjects);
				}
			}
		}
	}

	return true;
}

CSceneObject* CScene::QuerySceneObject(OBJID idObject)
{
	CHECK_RETURN(idObject, NULL);

	SCENE_OBJECT_MAP::iterator it = m_mapSceneObjects.find(idObject);
	if (it == m_mapSceneObjects.end())
	{
		return NULL;
	}

	return it->second;
}

int CScene::GetCrossRegionAmount(float fRadius)
{
	return (int)(ceil(fRadius/this->GetPerRegionSize()));
}

bool CScene::IsStandablePoint(const Point3f& ptPos)
{
	if (!this->IsValidPoint(ptPos))
	{
		return false;
	}

	//TO-DO:检查是否在导航网格上

	return true;
}

bool CScene::IsTolerablePoint(const Point3f& ptServerPos, const Point3f& ptClientPos)
{
	if (!this->IsStandablePoint(ptClientPos))
	{
		return false;
	}

	Vec3f vecDiff = ptClientPos - ptServerPos;
	if (vecDiff.len() > SCENE_MOVE_DISTANCE_TOLERANCE)
	{
		return false;
	}

	return true;
}

OBJID32 CScene::GetID()
{
	CHECK_RETURN(m_pSceneData, ID_NONE);

	return m_pSceneData->id;
}
