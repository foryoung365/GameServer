////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:2015/08/19
// Describe:Íæ¼Ò¼¼ÄÜ
////////////////////////////////////////////////////////////////////////
#ifndef _USERMAGIC_H_
#define _USERMAGIC_H_

#include "Magic.h"
#include "MagicData.h"

class CUserMagic : public CMagic
{
protected:
	CUserMagic();
	virtual ~CUserMagic();
public:
	virtual OBJID GetID();
	static CUserMagic* CreateNew() { return new CUserMagic; }
	virtual bool Create(const CGameRecordRow& rRow);
	virtual bool Cast(MagicCastInfo* pInfo);
	virtual bool IsCastable(MagicCastInfo* pInfo);
	virtual void CollectTargets();
	virtual void CalcDamage();
	virtual void MoveCaster();
	virtual void MoveVictim();
	virtual void AddStatus();
	virtual void AddMagicExp();
	virtual void Reset();
	bool HasTargetType(MAGIC_TARGET_TYPE eTaregetType);
	bool CheckCost(MAGIC_COST_TYPE eCostType, CRole* pCaster, int nCostValue);
protected:
	CMagicData* m_pMagicData;
};

#endif	//end of define _USERMAGIC_H_