////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:2015/08/18
// Describe:¼¼ÄÜ
////////////////////////////////////////////////////////////////////////
#ifndef _MAGIC_H_
#define _MAGIC_H_

#include "MagicDef.h"
#include "MagicData.h"
#include "MagicTypeData.h"
#include "GameDatabase.h"

class CMagic
{
protected:
	CMagic();
	virtual ~CMagic() {}
public:
	static CMagic* CreateNew(OBJECT_TYPE eObjectType);
	virtual OBJID GetID() = 0;
	virtual void Release() { delete this; }
	virtual bool Create(const CGameRecordRow& rRow) = 0;
	virtual bool Cast(MagicCastInfo* pInfo) = 0;
	virtual bool IsCastable(MagicCastInfo* pInfo) = 0;
	virtual void CollectTargets() = 0;
	virtual void CalcDamage() = 0;
	virtual void MoveCaster() = 0;
	virtual void MoveVictim() = 0;
	virtual void AddStatus() = 0;
	virtual void AddMagicExp() = 0;
	virtual bool IsInCD();
	virtual void Reset() = 0;
protected:
	time_t m_tLastCastTime;
	CMagicTypeData* m_pTypeData;
	MagicCastInfo m_objMagicCastInfo;
	TARGET_ROLE_VEC m_vecTargets;
};

#endif	//end of define _MAGIC_H_