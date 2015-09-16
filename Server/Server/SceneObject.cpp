////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:	2015/05/18
// Describe:
////////////////////////////////////////////////////////////////////////
#include <algorithm>
#include <iterator>
#include "Scene.h"
#include "SceneObject.h"
#include "Region.h"
#include "SceneMgr.h"
#include "BaseDefine.h"
#include "MsgNetwork.pb.h"

CSceneObject::CSceneObject(OBJECT_TYPE eType) : CGameObject(eType)
{
	m_pRegion = NULL;
}

CSceneObject::~CSceneObject()
{
	
}

bool CSceneObject::Create(CScene* pScene, const Point3f& ptPos)
{
	CHECK_RETURN(pScene, false);

	CHECK_RETURN(pScene->IsStandablePoint(ptPos), false);

	m_pScene = pScene;

	m_pRegion = m_pScene->QueryRegionByPosition(ptPos);
	CHECK_RETURN(m_pRegion, false);

	this->SetPosition(ptPos);

	return true;
}

const Point3f& CSceneObject::GetPosition()
{
	return m_LocalBox.center;
}

void CSceneObject::SetPosition(const Point3f& ptPos)
{
	m_LocalBox.center = ptPos;
}

void CSceneObject::OnTimer()
{

}

bool CSceneObject::IsIn(Box &box)
{
	return m_LocalBox.isInside(box);
}

void CSceneObject::OnTimeTrigger(const TimeTrigger_t& pTrigger)
{

}

bool CSceneObject::TravelToRegion(CRegion* pTargetRegion)
{
	CHECK_RETURN(pTargetRegion, false);
	CHECK_RETURN(m_pRegion, false);
	CHECK_RETURN(m_pScene, false);

	//跨场景不能直接做区域切换
	if (m_pScene->QueryRegion(pTargetRegion->GetID()) == NULL)
	{
		return false;
	}

	const REGION_SET& setOldArea = m_pRegion->GetBroadcastArea();
	const REGION_SET& setNewArea = pTargetRegion->GetBroadcastArea();

	REGION_SET setLeave;
	set_difference(setOldArea.begin(), setOldArea.end(), setNewArea.begin(), setNewArea.end(), std::inserter(setLeave, setLeave.begin()));

	REGION_SET setEnter;
	set_difference(setNewArea.begin(), setNewArea.end(), setOldArea.begin(), setOldArea.end(), std::inserter(setEnter, setEnter.begin()));

	if (!setLeave.empty())
	{
		//离开的区域，广播离开的消息
		
	}

	if (!setEnter.empty())
	{
		//新进入的区域,广播进入的消息
		
	}

	m_pRegion = pTargetRegion;

	return true;
}

bool CSceneObject::TeleportTo(OBJID idScene, const Point3f& ptTargetPos)
{
	CHECK_RETURN(idScene, false);

	if (!this->IsTeleportable())
	{
		return false;
	}

	CScene* pScene = CSceneMgr::getInstance()->QueryScene(idScene);
	if (pScene == NULL)
	{
		return false;
	}

	if (!pScene->IsStandablePoint(ptTargetPos))
	{
		return false;
	}

	if (m_pScene)
	{
		this->LeaveScene();
	}

	m_pScene = pScene;
	this->SetPosition(ptTargetPos);

	return this->EnterScene();
}

bool CSceneObject::IsTeleportable()
{
	return true;
}

bool CSceneObject::LeaveScene()
{
	CHECK_RETURN(m_pScene, false);

	this->OnLeaveScene();

	if (m_pRegion)
	{
		m_pRegion->RemoveSceneObject(this);
		m_pRegion = NULL;
	}
	m_pScene->RemoveSceneObject(this);

	return true;
}

bool CSceneObject::EnterScene()
{
	CHECK_RETURN(m_pScene, false);

	Point3f ptPos = this->GetPosition();
	if (!m_pScene->IsStandablePoint(ptPos))
	{
		return false;
	}

	m_pRegion = m_pScene->QueryRegionByPosition(ptPos);
	if (m_pRegion == NULL)
	{
		return false;
	}

	this->OnEnterScene();

	return true;
}

void CSceneObject::OnEnterScene()
{
	//TO-DO：广播进入地图消息
}

void CSceneObject::OnLeaveScene()
{
	//TO-DO:广播离开场景的消息给周围玩家
}

bool CSceneObject::IsMovable()
{
	return false;
}

OBJID32 CSceneObject::GetSceneID()
{
	CHECK_RETURN(m_pScene, ID_NONE);

	return m_pScene->GetID();
}

OBJID32 CSceneObject::GetRegionID()
{
	CHECK_RETURN(m_pRegion, ID_NONE);

	return m_pRegion->GetID();
}

