////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:2015/07/13
// Describe:角色类型接口类
////////////////////////////////////////////////////////////////////////
#ifndef _ROLETYPE_H_
#define _ROLETYPE_H_

#include "BaseDefine.h"
#include "GameObject.h"
#include "GameDatabase.h"
#include "RoleTypeData.h"

class CRoleTypeSet
{
private:
	CRoleTypeSet();
	~CRoleTypeSet();
public:
	juce_DeclareSingleton_SingleThreaded(CRoleTypeSet, true);
	bool Create();
	CRoleTypeData* QueryRoleType(OBJID32 idRoleType);
protected:
	typedef std::map<OBJID32, CRoleTypeData*> ROLE_TYPE_SET;
	ROLE_TYPE_SET m_mapRoleType;
};

#endif	//end of define _ROLETYPE_H_