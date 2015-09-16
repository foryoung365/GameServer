////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:	2015/05/14
// Describe:场景类
////////////////////////////////////////////////////////////////////////
#ifndef _SCENE_H_
#define _SCENE_H_

#include <map>
#include "BaseDefine.h"
#include "SceneObject.h"
#include "Octree.h"
#include "ozcollide/Box.h"
#include "SceneDef.h"
#include "TimerMgr.h"
#include "Region.h"
#include "MsgNetwork.pb.h"
#include "SceneData.h"
#include "GameDatabase.h"

using namespace ozcollide;

class CScene
{
protected:
	CScene();
	virtual ~CScene();
public:
	OBJID32 GetID();
	static CScene* CreateNew() { return new CScene; }
	bool Create(const CGameRecordRow& rRow);
	virtual void Release() { delete this; }
	void BuildNeighborSet();
	OBJID32 OctreeIndexToRegionID(const COctreeIndex& idxTree);
	virtual COctree* GetSceneOctree() { return m_pSceneOctree; }
	virtual void OnTimer();
	virtual void OnTimeTrigger(const TimeTrigger_t& pTrigger);

public://Region操作
	virtual CRegion* QueryRegion(OBJID32 idRegion);
	virtual CRegion* QueryRegionByIndex(const COctreeIndex& idxTree);
	virtual CRegion* QueryRegionByPosition(const Point3f& ptPos);
	virtual bool AddSceneObject(CSceneObject* pSceneObject);
	virtual bool RemoveSceneObject(CSceneObject* pSceneObject);
	int GetMaxOctreeDepth() { return m_nMaxOctreeDepth; }
	float GetPerRegionSize() { return m_fRegionSize; }

public://坐标有效性检查
	//坐标是否在地图范围内
	virtual bool IsValidPoint(const Point3f& ptPos);
	//坐标是否可站立
	virtual bool IsStandablePoint(const Point3f& ptPos);
	//给定坐标是否在原坐标的误差许可范围内
	virtual bool IsTolerablePoint(const Point3f& ptServerPos, const Point3f& ptClientPos);

public://消息广播
	//全地图广播
	virtual void BroadcastMsg(CMsgNetwork* pMsg);
	//广播指定区域（包含整个广播域）
	virtual void BroadcastMsg(CRegion* pRegion, CMsgNetwork* pMsg);
	//广播指定多个区域
	virtual void BroadcastMsg(const REGION_SET& setRegions, CMsgNetwork* pMsg);

public://对象收集
	virtual CSceneObject* QuerySceneObject(OBJID idObject);
	virtual bool CollectSceneObjects(CObjectType objType, SCENE_OBJECT_MAP& mapObjects);
	virtual bool CollectSceneObjects(const Point3f& ptPos, CObjectType objType, SCENE_OBJECT_MAP& mapObjects);
	virtual bool CollectSceneObjectsInSphere(const Point3f& ptCenter, float fRadius, CObjectType objType, SCENE_OBJECT_MAP& mapObjects);

protected:
	void BuildNeighborImpl(COctree* pOctree);
	//根据圆形的半径计算会横跨多少个区域
	int GetCrossRegionAmount(float fRadius);
protected:
	COctree* m_pSceneOctree;			//场景八叉树的根
	Box m_SceneBoundBox;
	typedef std::vector<CRegion*> REGION_VEC;
	REGION_VEC m_vecRegions;
	int m_nMaxOctreeDepth;
	SCENE_OBJECT_MAP m_mapSceneObjects;
	float m_fRegionSize;				//每个区域的边长
	CSceneData* m_pSceneData;
};

#endif	//end of define _SCENE_H_