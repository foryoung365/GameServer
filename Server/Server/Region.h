////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:	2015/06/23
// Describe:广播域，一个广播域由一颗叶子八叉树和它的26个邻居节点组成。
////////////////////////////////////////////////////////////////////////
#ifndef _REGION_H_
#define _REGION_H_

#include "Octree.h"
#include "SceneObject.h"
#include "BaseDefine.h"
#include "GameObject.h"
#include "MsgNetwork.pb.h"

typedef std::set<CRegion*> REGION_SET;

class CScene;
class CRegion
{
private:
	CRegion();
	~CRegion();
public:
	static CRegion* CreateNew() { return new CRegion; }
	void Release() { delete this; }
	OBJID32 GetID() { return m_idRegion; }
	bool Create(OBJID32 idRegion, COctree* pLeafOctree, CScene* pScene);
	void AddNeighbor(CRegion* pNeighborRegion);
	const REGION_SET& GetBroadcastArea() { return m_setNeighborRegions; }
	const COctree* GetCenterOctree() { return m_pCenterOctree; }
	const COctreeIndex& GetIndex();
	bool IsNeighbor(CRegion* pRegion);
	bool IsInRegion(const Point3f& ptPos);
	CSceneObject* QuerySceneObject(OBJID idObject);
	bool CollectSceneObjects(CObjectType objType, SCENE_OBJECT_MAP& mapObjects);
	bool CollectSceneObjects(const Point3f& ptPos, CObjectType objType, SCENE_OBJECT_MAP& mapObjects);
	virtual bool CollectSceneObjectsInCircle(const Point3f& ptCenter, float fRadius, CObjectType objType, SCENE_OBJECT_MAP& mapObjects);

	bool AddSceneObject(CSceneObject* pSceneObject);
	bool RemoveSceneObject(CSceneObject* pSceneObject);
	void BroadcastMsg(CMsgNetwork* pMsg);
	void BroadcastAreaMsg(CMsgNetwork* pMsg);
	void AddBroadcastPeerToMsg(CMsgNetwork* pMsg);
private:
	COctree* m_pCenterOctree;
	REGION_SET m_setNeighborRegions;		//所有邻居区域，包括自己
	SCENE_OBJECT_MAP m_mapSceneObjects;
	CScene* m_pScene;
	OBJID32 m_idRegion;
};

#endif	//end of define _REGION_H_