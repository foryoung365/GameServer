////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:2015/08/18
// Describe:技能相关定义
////////////////////////////////////////////////////////////////////////
#ifndef _MAGICDEF_H_
#define _MAGICDEF_H_

#include <vector>
#include "BaseDefine.h"
#include "GameObject.h"
#include "ozcollide/vec3f.h"

using namespace ozcollide;

using juce::WeakReference;

class CRole;

struct MagicCastInfo
{
	CRole* pCasterRole;	//施法者
	OBJID idTargetRole;	//目标角色ID
	OBJECT_TYPE eObjectType; //目标角色类型
	Point3f ptTargetPos;	//目标地点

	void Clear()
	{
		pCasterRole = NULL;
		idTargetRole = ID_NONE;
		ptTargetPos = ZEROVEC3F;
		eObjectType = OBJ_NONE;
	}

	MagicCastInfo()
	{
		this->Clear();
	}	
};

//技能施法类型
enum MAGIC_CAST_TYPE
{
	MAGIC_CAST_TYPE_NONE				= 0,	//无需施法（瞬发）
	MAGIC_CAST_TYPE_SING				= 1,	//吟唱

	MAGIC_CAST_TYPE_MAX
};

//技能消耗类型
enum MAGIC_COST_TYPE
{
	MAGIC_COST_TYPE_NONE				= 0,	//无消耗
	MAGIC_COST_TYPE_MP_VALUE			= 1,	//MP值
	MAGIC_COST_TYPE_MP_PERCENT		= 2,	//MP百分比
	MAGIC_COST_TYPE_HP_VALUE			= 3,	//HP值
	MAGIC_COST_TYPE_HP_PERCENT		= 4,	//HP百分比

	MAGIC_COST_TYPE_MAX
};

//技能目标类型，掩码叠加方式
enum MAGIC_TARGET_TYPE
{
	MAGIC_TARGET_TYPE_NONE			= 0,	//无效
	MAGIC_TARGET_TYPE_MONSTER		= 0x1,	//对怪
	MAGIC_TARGET_TYPE_GROUND			= 0x2,	//对地
	MAGIC_TARGET_TYPE_PLAYER			= 0x4,	//对玩家
	MAGIC_TARGET_TYPE_SELF			= 0x8,	//对自己
	MAGIC_TARGET_TYPE_EUDEMON		= 0x10,	//对幻兽

	MAGIC_TARGET_TYPE_MAX,
};

//技能范围类型
enum MAGIC_RANGE_TYPE
{
	MAGIC_RANGE_TYPE_SINGLE			= 0,	//单体
	MAGIC_RANGE_TYPE_LINE				= 1,	//线型
	MAGIC_RANGE_TYPE_SPHERE			= 2,	//球形

	MAGIC_RANGE_TYPE_MAX,
};

typedef std::vector<CRole*> TARGET_ROLE_VEC;

#endif	//end of define _MAGICDEF_H_