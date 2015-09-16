////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:	2015/06/23
// Describe:
////////////////////////////////////////////////////////////////////////
#include "Region.h"
#include "Scene.h"
#include "User.h"
#include "GameKernel.h"

CRegion::CRegion()
{
	m_pCenterOctree = NULL;
	m_pScene = NULL;
	m_idRegion = ID_NONE;
}

CRegion::~CRegion()
{

}

bool CRegion::Create(OBJID32 idRegion, COctree* pLeafOctree, CScene* pScene)
{
	CHECK_RETURN(pLeafOctree, false);
	CHECK_RETURN(pScene, false);

	m_idRegion = idRegion;

	m_pCenterOctree = pLeafOctree;

	m_pScene = pScene;

	return true;
}

void CRegion::AddNeighbor(CRegion* pNeighborRegion)
{
	CHECK(pNeighborRegion);

	m_setNeighborRegions.insert(pNeighborRegion);
}

const COctreeIndex& CRegion::GetIndex()
{
	return m_pCenterOctree->GetIndex();
}

bool CRegion::IsNeighbor(CRegion* pRegion)
{
	CHECK_RETURN(pRegion, false);

	if (m_setNeighborRegions.find(pRegion) == m_setNeighborRegions.end())
	{
		return false;
	}

	return true;
}

bool CRegion::IsInRegion(const Point3f& ptPos)
{
	CHECK_RETURN(m_pCenterOctree, false);

	ozcollide::Box boxBound;
	m_pCenterOctree->GetActualBounds(&boxBound);

	return boxBound.isInside(ptPos);
}

bool CRegion::CollectSceneObjects(CObjectType objType, SCENE_OBJECT_MAP& mapObjects)
{
	CHECK_RETURN(objType != OBJ_NONE, false);

	for (SCENE_OBJECT_MAP::iterator it = m_mapSceneObjects.begin(); it != m_mapSceneObjects.end(); ++it)
	{
		CSceneObject* pSceneObject = it->second;
		if (pSceneObject == NULL)
		{
			continue;
		}

		if (!objType.IsContain(pSceneObject->GetType()))
		{
			continue;
		}

		mapObjects.insert(std::make_pair(pSceneObject->GetID(), pSceneObject));
	}

	return true;
}

bool CRegion::CollectSceneObjects(const Point3f& ptPos, CObjectType objType, SCENE_OBJECT_MAP& mapObjects)
{
	CHECK_RETURN(objType != OBJ_NONE, false);

	if (this->IsInRegion(ptPos))
	{
		return false;
	}

	for (SCENE_OBJECT_MAP::iterator it = m_mapSceneObjects.begin(); it != m_mapSceneObjects.end(); ++it)
	{
		CSceneObject* pSceneObject = it->second;
		if (pSceneObject == NULL)
		{
			continue;
		}

		if (!objType.IsContain(pSceneObject->GetType()))
		{
			continue;
		}

		if (pSceneObject->GetPosition() != ptPos)
		{
			continue;
		}

		mapObjects.insert(std::make_pair(pSceneObject->GetID(), pSceneObject));
	}

	return true;
}

CSceneObject* CRegion::QuerySceneObject(OBJID idObject)
{
	CHECK_RETURN(idObject, NULL);

	SCENE_OBJECT_MAP::iterator it = m_mapSceneObjects.find(idObject);
	if (it == m_mapSceneObjects.end())
	{
		return NULL;
	}

	return it->second;
}

bool CRegion::AddSceneObject(CSceneObject* pSceneObject)
{
	CHECK_RETURN(pSceneObject, false);

	m_mapSceneObjects.insert(std::make_pair(pSceneObject->GetID(), pSceneObject));

	return true;
}

bool CRegion::RemoveSceneObject(CSceneObject* pSceneObject)
{
	CHECK_RETURN(pSceneObject, false);

	m_mapSceneObjects.erase(pSceneObject->GetID());

	return true;
}

bool CRegion::CollectSceneObjectsInCircle(const Point3f& ptCenter, float fRadius, CObjectType objType, SCENE_OBJECT_MAP& mapObjects)
{
	//即使圆心不在区域内，也要继续搜索
	CHECK_RETURN(objType != OBJ_NONE, false);

	for (SCENE_OBJECT_MAP::iterator it = m_mapSceneObjects.begin(); it != m_mapSceneObjects.end(); ++it)
	{
		CSceneObject* pSceneObject = it->second;
		if (pSceneObject == NULL)
		{
			continue;
		}

		if (!objType.IsContain(pSceneObject->GetType()))
		{
			continue;
		}

		if ((pSceneObject->GetPosition() - ptCenter).len() > fRadius)
		{
			continue;
		}

		mapObjects.insert(std::make_pair(pSceneObject->GetID(), pSceneObject));
	}

	return true;
}

void CRegion::BroadcastMsg(CMsgNetwork* pMsg)
{
	CHECK(pMsg);

	for (SCENE_OBJECT_MAP::iterator it = m_mapSceneObjects.begin(); it != m_mapSceneObjects.end(); ++it)
	{
		CSceneObject* pSceneObject = it->second;
		if (pSceneObject == NULL)
		{
			continue;
		}

		if (pSceneObject->IsType(OBJ_USER))
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

void CRegion::BroadcastAreaMsg(CMsgNetwork* pMsg)
{
	CHECK(pMsg);

	for (REGION_SET::iterator it = m_setNeighborRegions.begin(); it != m_setNeighborRegions.end(); ++it)
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

void CRegion::AddBroadcastPeerToMsg(CMsgNetwork* pMsg)
{
	CHECK(pMsg);

	for (SCENE_OBJECT_MAP::iterator it = m_mapSceneObjects.begin(); it != m_mapSceneObjects.end(); ++it)
	{
		CSceneObject* pSceneObject = it->second;
		if (pSceneObject == NULL)
		{
			continue;
		}

		if (pSceneObject->IsType(OBJ_USER))
		{
			continue;
		}

		CUser* pUser = NULL;
		IF_NOT(pSceneObject->QueryObject(OBJ_USER, IPP_OF(pUser)) && pUser)
		{
			continue;
		}

		pMsg->add_idpeer(pUser->GetPeerID());
	}
}
