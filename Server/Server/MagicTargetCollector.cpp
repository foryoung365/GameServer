////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:2015/08/20
// Describe:
////////////////////////////////////////////////////////////////////////
#include "MagicTargetCollector.h"
#include "Role.h"
#include "BasicDataSet.h"
#include "RoleMgr.h"
#include "Scene.h"
#include "ozcollide/sphere.h"

juce_ImplementSingleton_SingleThreaded(CMagicTargetCollector);

CMagicTargetCollector::CMagicTargetCollector()
{

}

CMagicTargetCollector::~CMagicTargetCollector()
{
	CMagicTargetCollector::clearSingletonInstance();
}

bool CMagicTargetCollector::Create()
{
	return true;
}

CObjectType CMagicTargetCollector::GetObjectTypeByMask(uint64_t u64TargetMask)
{
	CHECK_RETURN(u64TargetMask, OBJ_NONE);

	CObjectType objType(OBJ_NONE);

	if (this->HasTargetMask(u64TargetMask, MAGIC_TARGET_TYPE_MONSTER))
	{
		objType.AddType(OBJ_MONSTER);
	}
	if (this->HasTargetMask(u64TargetMask, MAGIC_TARGET_TYPE_PLAYER))
	{
		objType.AddType(OBJ_USER);
	}

	return objType;
}

bool CMagicTargetCollector::HasTargetMask(uint64_t u64TargetMask, uint64_t u64TestMask)
{
	if ((u64TargetMask & u64TestMask) == 0)
	{
		return false;
	}

	return true;
}

bool CMagicTargetCollector::IsValidTarget(CRole* pCaster, CRole* pTargetRole, uint64_t u64TargetMask)
{
	CHECK_RETURN(pCaster, false);
	CHECK_RETURN(pTargetRole, false);
	CHECK_RETURN(u64TargetMask, false);

	if (pCaster == pTargetRole)
	{
		if (this->HasTargetMask(u64TargetMask, MAGIC_TARGET_TYPE_SELF))
		{
			return true;
		}
	}
	else
	{
		CObjectType objType = this->GetObjectTypeByMask(u64TargetMask);
		if (objType.IsType(pTargetRole->GetType()))
		{
			return true;
		}
	}

	return false;
}

bool CMagicTargetCollector::CollectTargets(CMagicTypeData* pTypeData, MagicCastInfo* pInfo, TARGET_ROLE_VEC& vecTargets)
{
	CHECK_RETURN(pTypeData, false);
	CHECK_RETURN(pInfo, false);

	vecTargets.clear();

	uint64_t u64TargetMask = pTypeData->target_type;
	if (this->HasTargetMask(u64TargetMask, MAGIC_TARGET_TYPE_GROUND))
	{
		this->CollectTargetAroundPosition(pTypeData, pInfo->pCasterRole, pInfo->ptTargetPos, vecTargets);
	}
	else
	{
		CRole* pTargetRole = CRoleMgr::getInstance()->QueryRole(pInfo->idTargetRole, pInfo->eObjectType);
		CHECK_RETURN(pTargetRole, false);
		this->CollectTargetAroundRole(pTypeData, pInfo->pCasterRole, pTargetRole, vecTargets);
	}

	return true;
}

void CMagicTargetCollector::CollectTargetAroundPosition(CMagicTypeData* pTypeData, CRole* pCaster, Point3f ptTargetPos, TARGET_ROLE_VEC& vecTargets)
{
	CHECK(pTypeData);
	CHECK(pCaster);

	CScene* pScene = pCaster->GetScene();
	CHECK(pScene);

	MAGIC_RANGE_TYPE eRangeType = (MAGIC_RANGE_TYPE)pTypeData->range_type;
	uint64_t u64TargetMask = pTypeData->target_type;
	CObjectType objType = this->GetObjectTypeByMask(u64TargetMask);

	SCENE_OBJECT_MAP mapSceneObjects;

	switch (eRangeType)
	{
	case MAGIC_RANGE_TYPE_SINGLE:
	case MAGIC_RANGE_TYPE_SPHERE:
	{
		pScene->CollectSceneObjectsInSphere(ptTargetPos, pTypeData->range_x, objType, mapSceneObjects);
	}
	break;
	case MAGIC_RANGE_TYPE_LINE:
	{

	}
	break;
	default:
	{
		LogErr(juce::String().formatted("MagicType[%llu] RangeType[%lld] invalid!", pTypeData->id, eRangeType));
	}
	break;
	}

	if (this->HasTargetMask(u64TargetMask, MAGIC_TARGET_TYPE_SELF))
	{
		Sphere objMagicSphere(ptTargetPos, pTypeData->range_x);
		
		if (objMagicSphere.isPointInside(pCaster->GetPosition()) && this->IsValidTarget(pCaster, pCaster, u64TargetMask))
		{
			vecTargets.push_back(pCaster);
		}
	}

	for (SCENE_OBJECT_MAP::iterator it = mapSceneObjects.begin(); it != mapSceneObjects.end(); ++it)
	{
		CRole* pRole = (CRole*)it->second;
		if (pRole == NULL)
		{
			continue;
		}
		if (!this->IsValidTarget(pCaster, pRole, u64TargetMask))
		{
			continue;
		}

		vecTargets.push_back(pRole);
	}
}

void CMagicTargetCollector::CollectTargetAroundRole(CMagicTypeData* pTypeData, CRole* pCaster, CRole* pTargetRole, TARGET_ROLE_VEC& vecTargets)
{
	CHECK(pTypeData);
	CHECK(pCaster);
	CHECK(pTargetRole);

	CScene* pScene = pCaster->GetScene();
	CHECK(pScene);

	MAGIC_RANGE_TYPE eRangeType = (MAGIC_RANGE_TYPE)pTypeData->range_type;
	uint64_t u64TargetMask = pTypeData->target_type;
	CObjectType objType = this->GetObjectTypeByMask(u64TargetMask);

	SCENE_OBJECT_MAP mapSceneObjects;

	switch (eRangeType)
	{
	case MAGIC_RANGE_TYPE_SPHERE:
	{
		pScene->CollectSceneObjectsInSphere(pTargetRole->GetPosition(), pTypeData->range_x, objType, mapSceneObjects);
	}
	break;
	case MAGIC_RANGE_TYPE_LINE:
	{

	}
	break;
	default:
	{
		LogErr(juce::String().formatted("MagicType[%llu] RangeType[%lld] invalid!", pTypeData->id, eRangeType));
	}
	break;
	}

	if (this->IsValidTarget(pCaster, pTargetRole, u64TargetMask))
	{
		vecTargets.push_back(pTargetRole);
	}

	if (this->HasTargetMask(u64TargetMask, MAGIC_TARGET_TYPE_SELF))
	{
		Sphere objMagicSphere(pTargetRole->GetPosition(), pTypeData->range_x);

		if (objMagicSphere.isPointInside(pCaster->GetPosition()) && this->IsValidTarget(pCaster, pCaster, u64TargetMask))
		{
			vecTargets.push_back(pCaster);
		}
	}

	for (SCENE_OBJECT_MAP::iterator it = mapSceneObjects.begin(); it != mapSceneObjects.end(); ++it)
	{
		CRole* pRole = (CRole*)it->second;
		if (pRole == NULL)
		{
			continue;
		}
		if (!this->IsValidTarget(pCaster, pRole, u64TargetMask))
		{
			continue;
		}

		vecTargets.push_back(pRole);
	}
}

