////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:2015/08/20
// Describe:技能目标收集器
////////////////////////////////////////////////////////////////////////
#ifndef _MAGICTARGETCOLLECTOR_H_
#define _MAGICTARGETCOLLECTOR_H_

#include "BaseDefine.h"
#include "MagicDef.h"
#include "GameObject.h"
#include "MagicTypeData.h"

class CRole;

class CMagicTargetCollector
{
private:
	CMagicTargetCollector();
	~CMagicTargetCollector();
public:
	juce_DeclareSingleton_SingleThreaded(CMagicTargetCollector, true);
	bool Create();
	bool IsValidTarget(CRole* pCaster, CRole* pTargetRole, uint64_t u64TargetMask);
	CObjectType GetObjectTypeByMask(uint64_t u64TargetMask);
	bool HasTargetMask(uint64_t u64TargetMask, uint64_t u64TestMask);
	bool CollectTargets(CMagicTypeData* pTypeData, MagicCastInfo* pInfo, TARGET_ROLE_VEC& vecTargets);
private:
	void CollectTargetAroundPosition(CMagicTypeData* pTypeData, CRole* pCaster, Point3f ptTargetPos, TARGET_ROLE_VEC& vecTargets);
	void CollectTargetAroundRole(CMagicTypeData* pTypeData, CRole* pCaster, CRole* pTargetRole, TARGET_ROLE_VEC& vecTargets);
};

#endif	//end of define _MAGICTARGETCOLLECTOR_H_