////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:2015/07/14
// Describe:
////////////////////////////////////////////////////////////////////////
#include <algorithm>
#include "User.h"
#include "Scene.h"
#include "Region.h"
#include "MemRecordset.h"
#include "GameKernel.h"
#include "SceneMgr.h"
#include "RoleTypeSet.h"

using namespace std;

CUser::CUser() : CRole(OBJ_USER)
{

}


CUser::~CUser()
{
	this->SaveInfo();

	//这行保持在最后
	masterReference.clear();
}


bool CUser::Create(const UserParm_t& rUserParm)
{
	CHECK_RETURN(rUserParm.idUser, false);
	CHECK_RETURN(rUserParm.idPeer, false);
	//TO-DO:
	CGameRecordset* pRes = CMemRecordset::getInstance()->QueryRecordset(rUserParm.idUser, DB_LOAD_USER_DATA);
	CHECK_RETURN(pRes, false);
	CHECK_RETURN(pRes->size() == 1, false);

	m_objUserData = pRes->at(0);

	m_pRoleTypeData = CRoleTypeSet::getInstance()->QueryRoleType(m_objUserData.role_type);
	CHECK_RETURN(m_pRoleTypeData, false);

	m_idPeer = rUserParm.idPeer;
	m_strIP = rUserParm.strIP;

	CHECK_RETURN(CSceneMovable::Create(CSceneMgr::getInstance()->QueryScene(this->GetSceneID()), Point3f(m_objUserData.pos_x, m_objUserData.pos_y, m_objUserData.pos_z)), false);

	return true;
}

bool CUser::ClientMoveTo(MoveActionInfo_t* pMoveInfo)
{
	CHECK_RETURN(pMoveInfo, false);
	CHECK_RETURN(m_pScene, false);
	CHECK_RETURN(m_pMoveList, false);

	if (!this->IsMovable())
	{
		return false;
	}

	float fMaxVelocity = this->GetMaxSpeed();
	if (pMoveInfo->fVelocity > fMaxVelocity)
	{
		return false;
	}

	if (pMoveInfo->tEndTime < pMoveInfo->tStartTime)
	{
		return false;
	}

	Point3f ptStartPos(pMoveInfo->fStartX, pMoveInfo->fStartY, pMoveInfo->fStartZ);
	Point3f ptCurPos = this->GetPosition();

	if (!m_pScene->IsTolerablePoint(ptCurPos, ptStartPos))
	{
		return false;
	}

	Point3f ptEndPos(pMoveInfo->fEndX, pMoveInfo->fEndY, pMoveInfo->fEndZ);
	if (!m_pScene->IsStandablePoint(ptEndPos))
	{
		return false;
	}

	//客户端每次移动距离不能超过上限
	float fDistance = (ptEndPos - ptStartPos).len();
	if (fDistance > SCENE_OBJECT_CLIENT_MOVE_RANGE)
	{
		return false;
	}

	//0速度表示停下，起点和终点必须相同
	if (pMoveInfo->fVelocity == 0)
	{
		if (ptStartPos != ptEndPos)
		{
			return false;
		}
	}
	else//移动到目标点的时间和速度是否合法
	{
		//如果用最高的速度移动，都无法在指定时间内移动到目标点，则认为是非法移动
		time_t tOffsetTime = (pMoveInfo->tEndTime - pMoveInfo->tStartTime);
		if ((fDistance / fMaxVelocity) * 1000 > tOffsetTime)
		{
			return false;
		}
	}

	return this->MoveTo(pMoveInfo);
}

OBJID64 CUser::GetPeerID()
{
	CHECK_RETURN(m_idPeer, ID_NONE);

	return m_idPeer;
}

const char* CUser::GetName()
{
	return m_objUserData.name.c_str();
}

float CUser::GetWidth()
{
	return m_objUserData.width;
}

float CUser::GetHeight()
{
	return m_objUserData.height;
}

uint32_t CUser::GetFace()
{
	return ID_NONE;
}

uint32_t CUser::GetHair()
{
	return ID_NONE;
}

int CUser::GetLife()
{
	return m_objUserData.life;
}

int CUser::GetMaxLife()
{
	CHECK_RETURN(m_pRoleTypeData, 0);

	//TO-DO:
	return m_pRoleTypeData->base_life;
}

int CUser::GetMana()
{
	return m_objUserData.mana;
}

int CUser::GetMaxMana()
{
	CHECK_RETURN(m_pRoleTypeData, 0);

	//TO-DO:
	return m_pRoleTypeData->base_mana;
}


float CUser::GetMaxSpeed()
{
	CHECK_RETURN(m_pRoleTypeData, 0);

	return m_pRoleTypeData->base_speed;
}

void CUser::SaveInfo()
{
	CGameKernel::GetDatabase()->Update(m_objUserData);
	this->ClearUpdateDirtyMask();
}

OBJID32 CUser::GetSceneID()
{
	return m_objUserData.scene_id;
}

float CUser::GetLength()
{
	return m_objUserData.length;
}

OBJID32 CUser::GetRecordSceneID()
{
	return m_objUserData.record_scene_id;
}

OBJID CUser::GetID()
{
	return m_objUserData.id;
}

int CUser::GetLevel()
{
	return m_objUserData.level;
}

bool CUser::IsNameValid(juce::String strName)
{
	return true;
}

void CUser::SetPeerID(OBJID64 idPeer)
{
	m_idPeer = idPeer;
}

void CUser::LoginOK()
{

}

void CUser::CreateOK()
{

}


void CUser::SendUserInfo()
{
	CMsgNetwork msgNetwork;
	CMsgRoleInfo* pMsgRoleInfo = msgNetwork.mutable_msgroleinfo();
	CHECK(pMsgRoleInfo);
	this->FillMsgRoleInfo(pMsgRoleInfo, ROLEINFOACT_SELF_NEW);

	this->SendMsg(&msgNetwork);
}

OBJID64 CUser::GetAccountID()
{
	return m_objUserData.account_id;
}

int64_t CUser::GetExp()
{
	return m_objUserData.exp;
}

void CUser::SendShow(CUser* pUser)
{
	CHECK(pUser);
	CMsgNetwork msgNetwork;
	
	CMsgRoleInfo* pMsgRoleInfo = msgNetwork.mutable_msgroleinfo();
	CHECK(this->FillMsgRoleInfo(pMsgRoleInfo, ROLEINFOACT_OTHER_NEW));

	pUser->SendMsg(&msgNetwork);
}

void CUser::SendShow(const USER_SET& setUsers)
{
	CHECK(!setUsers.empty());

	CMsgNetwork msgNetwork;

	CMsgRoleInfo* pMsgRoleInfo = msgNetwork.mutable_msgroleinfo();
	CHECK(this->FillMsgRoleInfo(pMsgRoleInfo, ROLEINFOACT_OTHER_NEW));

	for (USER_SET::iterator it = setUsers.begin(); it != setUsers.end(); ++it)
	{
		CUser* pUser = *it;
		if (pUser == NULL)
		{
			continue;
		}
		msgNetwork.add_idpeer(pUser->GetID());
	}

	CGameKernel::getInstance()->SendPipeMessage(THREAD_INDEX_SERVER_SOCKET, &msgNetwork);
}

void CUser::SendMsg(CMsgNetwork* pMsgNetwork)
{
	CHECK(pMsgNetwork->RealMessage_case() != CMsgNetwork::REALMESSAGE_NOT_SET);

	pMsgNetwork->add_idpeer(this->GetPeerID());
	CGameKernel::getInstance()->SendPipeMessage(THREAD_INDEX_SERVER_SOCKET, pMsgNetwork);
}

void CUser::OnEnterScene()
{
	CHECK(m_pScene);
	CSceneMovable::OnEnterScene();
	CMsgNetwork msgNetwork;
	CMsgRoleInfo* pMsgRoleInfo = msgNetwork.mutable_msgroleinfo();
	CHECK(pMsgRoleInfo);
	this->FillMsgRoleInfo(pMsgRoleInfo, ROLEINFOACT_OTHER_NEW);

	m_pScene->BroadcastMsg(m_pRegion, &msgNetwork);
}

void CUser::OnLeaveScene()
{
	CHECK(m_pScene);
	CSceneMovable::OnLeaveScene();

	CMsgNetwork msg;
	CMsgRoleInfo* pMsgRoleInfo = msg.mutable_msgroleinfo();
	CHECK(pMsgRoleInfo);
	pMsgRoleInfo->set_naction(ROLEINFOACT_LEAVE_SCENE);
	pMsgRoleInfo->set_idrole(this->GetID());
	pMsgRoleInfo->set_ntype(this->GetType());

	m_pScene->BroadcastMsg(m_pRegion, &msg);
}

bool CUser::FillMsgRoleInfo(CMsgRoleInfo* pMsgRoleInfo, int nAction)
{
	CHECK_RETURN(pMsgRoleInfo, false);
	CHECK_RETURN(nAction, false);

	bool bToSelf = (nAction == ROLEINFOACT_SELF_NEW) || (nAction == ROLEINFOACT_SELF_UPDATE);

	pMsgRoleInfo->set_naction(nAction);
	pMsgRoleInfo->set_ntype(this->GetType());
	pMsgRoleInfo->set_idrole(this->GetID());
	pMsgRoleInfo->set_strname(this->GetName());
	pMsgRoleInfo->set_idroletype(this->GetRoleTypeId());
	pMsgRoleInfo->set_nlevel(this->GetLevel());
	pMsgRoleInfo->set_nexp(this->GetExp());
	
	pMsgRoleInfo->set_fpos_x(this->GetPosition().x);
	pMsgRoleInfo->set_fpos_y(this->GetPosition().y);
	pMsgRoleInfo->set_fpos_z(this->GetPosition().z);
	pMsgRoleInfo->set_nlife(this->GetLife());
	pMsgRoleInfo->set_nmaxlife(this->GetMaxLife());
	pMsgRoleInfo->set_nmana(this->GetMana());
	pMsgRoleInfo->set_nmaxmana(this->GetMaxMana());

	if (bToSelf)
	{
		pMsgRoleInfo->set_idscene(this->GetSceneID());
	}

	return true;
}

void CUser::SetLife(int nLife)
{
	nLife = max(0, nLife);
	int nMaxLife = this->GetMaxLife();
	m_objUserData.life = min(nLife, nMaxLife);

	this->SetDirtyMask(USERDATA_LIFE);
}

void CUser::AddLife(int nAddLife)
{
	int nNewLife = this->GetLife() + nAddLife;
	this->SetLife(nNewLife);
}

void CUser::SetDirtyMask(CUserData_enum eDirtyField)
{
	CHECK(eDirtyField >= USERDATA_ID && eDirtyField < USERDATA_NULL);

	m_bsSyncDirtyMask.set(eDirtyField);
	m_bsUpdateDirtyMask.set(eDirtyField);
}

void CUser::ClearSyncDirtyMask()
{
	m_bsSyncDirtyMask.reset();
}

void CUser::ClearUpdateDirtyMask()
{
	m_bsUpdateDirtyMask.reset();
}

void CUser::SetMana(int nMana)
{
	nMana = max(0, nMana);
	int nMaxMana = this->GetMaxMana();
	m_objUserData.mana = min(nMana, nMaxMana);

	this->SetDirtyMask(USERDATA_MANA);
}

void CUser::AddMana(int nAddMana)
{
	int nNewMana = this->GetMana() + nAddMana;
	this->SetMana(nNewMana);
}

void CUser::SetLevel(int nLevel)
{
	nLevel = max(1, nLevel);

	int nMaxLevel = this->GetMaxLevel();
	m_objUserData.level = min(nLevel, nMaxLevel);

	this->SetDirtyMask(USERDATA_LEVEL);
}

void CUser::UpLevel()
{
	int nNewLevel = this->GetLevel() + 1;
	this->SetLevel(nNewLevel);
}

void CUser::SetExp(int64_t nExp)
{
	nExp = max(0i64, nExp);
	
	//TO-DO:获得当前等级最大经验值

	m_objUserData.exp = nExp;
	this->SetDirtyMask(USERDATA_EXP);
}

void CUser::OnTimer()
{
	CRole::OnTimer();
}

void CUser::AwardExp(int64_t nExp)
{
	//TO-DO:
}

bool CUser::IsInvulnerable()
{
	return false;
}

bool CUser::IsBeAttackedEnable()
{
	return true;
}


