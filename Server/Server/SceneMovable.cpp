////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:	2015/06/03
// Describe:
////////////////////////////////////////////////////////////////////////
#include <time.h>
#include "BaseDefine.h"
#include "SceneMovable.h"
#include "MoveAction.h"
#include "SceneDef.h"
#include "Scene.h"
#include "Region.h"
#include "TimeFormatter.h"

CSceneMovable::CSceneMovable(OBJECT_TYPE eType) : CSceneObject(eType)
{
	m_pMoveList = NULL;
}

CSceneMovable::~CSceneMovable()
{
	SAFE_RELEASE(m_pMoveList);
}

bool CSceneMovable::Create(CScene* pScene, const Point3f& ptPos)
{
	CHECK_RETURN(CSceneObject::Create(pScene, ptPos), false);

	m_pMoveList = CMoveList::CreateNew();
	IF_NOT (m_pMoveList && m_pMoveList->Create())
	{
		SAFE_RELEASE(m_pMoveList);

		return false;
	}

	return true;
}

const Point3f& CSceneMovable::GetPosition()
{
	if (m_pMoveList != NULL)
	{
		Point3f ptPos;
		if (m_pMoveList->RunActions(ptPos))
		{
			this->SetPosition(ptPos);
		}
		
	}

	return CSceneObject::GetPosition();
}

bool CSceneMovable::MoveTo(const Point3f& ptTargetPos, float fVelocity)
{
	CHECK_RETURN(m_pScene, false);
	CHECK_RETURN(m_pMoveList, false);
	CHECK_RETURN(fVelocity != 0, false);
	CHECK_RETURN(fVelocity <= this->GetMaxSpeed(), false);

	if (!this->IsMovable())
	{
		return false;
	}

	Point3f ptCurPos = this->GetPosition();

	MoveActionInfo_t infoAction;
	memset(&infoAction, 0, sizeof(MoveActionInfo_t));
	infoAction.fEndX = ptTargetPos.x;
	infoAction.fEndY = ptTargetPos.y;
	infoAction.fEndZ = ptTargetPos.z;

	infoAction.fStartX = ptCurPos.x;
	infoAction.fStartY = ptCurPos.y;
	infoAction.fStartZ = ptCurPos.z;

	infoAction.fVelocity = fVelocity;

	infoAction.tStartTime = CTimeFormatter::TimeGet(TIME_MILLISECOND);
	infoAction.tEndTime = infoAction.tStartTime + clock_t(((ptTargetPos - ptCurPos).len() / fVelocity) * 1000);

	return this->MoveTo(&infoAction);
}

void CSceneMovable::OnTimer()
{
	CSceneObject::OnTimer();
	
	const Point3f& ptCurPos = this->GetPosition();
	if (m_pScene)
	{
		if (m_pRegion)
		{
			//发生区域切换
			if (!m_pRegion->IsInRegion(ptCurPos))
			{
				this->SyncRegion();
			}
		}
	}
	
}

bool CSceneMovable::SyncRegion()
{
	CHECK_RETURN(m_pScene, false);
	CHECK_RETURN(m_pRegion, false);

	CRegion* pRealRegion = m_pScene->QueryRegionByPosition(this->GetPosition());
	if (pRealRegion == NULL)
	{
		return false;
	}

	if (pRealRegion == m_pRegion)
	{
		return true;
	}

	this->TravelToRegion(pRealRegion);

	return true;
}

bool CSceneMovable::IsMovable()
{
	return true;
}

bool CSceneMovable::IsTeleportable()
{
	return true;
}

bool CSceneMovable::MoveTo(MoveActionInfo_t* pMoveInfo)
{
	CHECK_RETURN(pMoveInfo, false);
	CHECK_RETURN(m_pScene, false);

	//根据当前位置和目标位置，算出移动方向
	Vec3f v3MoveDir = Point3f(pMoveInfo->fEndX, pMoveInfo->fEndY, pMoveInfo->fEndZ) - Point3f(pMoveInfo->fStartX, pMoveInfo->fStartY, pMoveInfo->fStartZ);

	//更新移动方向
	this->SetMoveDirection(v3MoveDir);

	this->BroadcastMoveMsg(MOVEACT_WALK, pMoveInfo);

	return m_pMoveList->AppendMoveActionByInfo(pMoveInfo);
}

void CSceneMovable::SetMoveDirection(const Vec3f& v3Direction)
{
	m_v3MoveDirection = v3Direction; 
	m_v3MoveDirection.normalize();
	
	//目前强制面向和移动方向相同
	this->SetFaceDirection(m_v3MoveDirection);
}

void CSceneMovable::BroadcastMoveMsg(int nAction, MoveActionInfo_t* pMoveInfo)
{
	CHECK(nAction != MOVEACT_NONE);
	CHECK(m_pScene);

	CMsgNetwork msgNetwork;
	CMsgMove* pMsgMove = msgNetwork.mutable_msgmove();
	CHECK(pMsgMove);
	pMsgMove->set_naction(nAction);
	pMsgMove->set_idrole(this->GetID());
	pMsgMove->set_fstartx(pMoveInfo->fStartX);
	pMsgMove->set_fstarty(pMoveInfo->fStartY);
	pMsgMove->set_fstartz(pMoveInfo->fStartZ);
	pMsgMove->set_fendx(pMoveInfo->fEndX);
	pMsgMove->set_fendy(pMoveInfo->fEndY);
	pMsgMove->set_fendz(pMoveInfo->fEndZ);
	pMsgMove->set_tstarttime(pMoveInfo->tStartTime);
	pMsgMove->set_tendtime(pMoveInfo->tEndTime);
	pMsgMove->set_fvelecity(pMoveInfo->fVelocity);

	m_pScene->BroadcastMsg(&msgNetwork);
}

void CSceneMovable::OnEnterScene()
{
	CSceneObject::OnEnterScene();
}

void CSceneMovable::OnLeaveScene()
{
	CSceneObject::OnLeaveScene();
}

