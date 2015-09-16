////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:2015/08/19
// Describe:角色管理器
////////////////////////////////////////////////////////////////////////
#ifndef _ROLEMGR_H_
#define _ROLEMGR_H_

#include "BaseDefine.h"
#include "Role.h"

//角色管理器
//这个管理器本身并不管理对象，只是一个方便操作的接口类
//各类角色对象实际上还是分布在各个类型的角色的专有管理器中，如UserMgr,NpcMgr等
class CRoleMgr
{
private:
	CRoleMgr();
	~CRoleMgr();
public:
	juce_DeclareSingleton_SingleThreaded(CRoleMgr, true);
	bool Create();
	bool AddRole(CRole* pRole);
	CRole* QueryRole(OBJID idRole, OBJECT_TYPE eObjectType);
	void DelRole(CRole* pRole);
	void DelRole(OBJID idRole, OBJECT_TYPE eObjectType);
};

#endif	//end of define _ROLEMGR_H_