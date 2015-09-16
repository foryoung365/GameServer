////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:2015/08/19
// Describe:
////////////////////////////////////////////////////////////////////////
#include "RoleMgr.h"
#include "UserMgr.h"

juce_ImplementSingleton_SingleThreaded(CRoleMgr);

CRoleMgr::CRoleMgr()
{

}

CRoleMgr::~CRoleMgr()
{
	CRoleMgr::clearSingletonInstance();
}

bool CRoleMgr::Create()
{
	return true;
}

bool CRoleMgr::AddRole(CRole* pRole)
{
	CHECK_RETURN(pRole, false);

	OBJECT_TYPE eObjectType = pRole->GetType();
	switch (eObjectType)
	{
	case OBJ_USER:
	{
		CUser* pUser = NULL;
		CHECK_RETURN(pRole->QueryObject(OBJ_USER, IPP_OF(pUser)), false);
		return CUserMgr::getInstance()->AddOnlineUser(pUser);
	}
	break;
	case OBJ_MONSTER:
		break;
	case OBJ_NPC:
		break;
	case OBJ_EUDEMON:
		break;
	default:
		break;
	}

	return false;
}

CRole* CRoleMgr::QueryRole(OBJID idRole, OBJECT_TYPE eObjectType)
{
	CHECK_RETURN(idRole, NULL);
	CHECK_RETURN(eObjectType != OBJ_NONE, NULL);

	CRole* pRole = NULL;
	switch (eObjectType)
	{
	case OBJ_USER:
	{
		pRole = CUserMgr::getInstance()->QueryOnlineUser(idRole);
	}
	break;
	case OBJ_MONSTER:
		break;
	case OBJ_NPC:
		break;
	case OBJ_EUDEMON:
		break;
	default:
		break;
	}

	return pRole;
}

void CRoleMgr::DelRole(CRole* pRole)
{
	CHECK(pRole);

	OBJECT_TYPE eObjectType = pRole->GetType();
	switch (eObjectType)
	{
	case OBJ_USER:
	{
		CUserMgr::getInstance()->DeleteOnlineUser(pRole->GetID());
	}
	break;
	case OBJ_MONSTER:
		break;
	case OBJ_NPC:
		break;
	case OBJ_EUDEMON:
		break;
	default:
		break;
	}
}

void CRoleMgr::DelRole(OBJID idRole, OBJECT_TYPE eObjectType)
{
	CHECK(idRole);
	CHECK(eObjectType != OBJ_NONE);

	switch (eObjectType)
	{
	case OBJ_USER:
	{
		CUserMgr::getInstance()->DeleteOnlineUser(idRole);
	}
	break;
	case OBJ_MONSTER:
		break;
	case OBJ_NPC:
		break;
	case OBJ_EUDEMON:
		break;
	default:
		break;
	}
}
