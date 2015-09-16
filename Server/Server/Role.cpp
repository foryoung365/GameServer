////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:2015/07/09
// Describe:
////////////////////////////////////////////////////////////////////////
#include "Role.h"

CRole::CRole(OBJECT_TYPE eType) : CSceneMovable(eType)
{
	m_pRoleTypeData = NULL;
}

CRole::~CRole()
{
}

OBJID32 CRole::GetRoleTypeId()
{
	CHECK_RETURN(m_pRoleTypeData, ID_NONE);

	return m_pRoleTypeData->id;
}

CRoleTypeData* CRole::GetRoleType()
{
	CHECK_RETURN(m_pRoleTypeData, NULL);

	return m_pRoleTypeData;
}

int CRole::GetMaxLevel()
{
	CHECK_RETURN(m_pRoleTypeData, NULL);

	return m_pRoleTypeData->max_level;
}

void CRole::OnTimer()
{
	CSceneMovable::OnTimer();
}

void CRole::OnEnterScene()
{
	CSceneMovable::OnEnterScene();
}

void CRole::OnLeaveScene()
{
	CSceneMovable::OnLeaveScene();
}
