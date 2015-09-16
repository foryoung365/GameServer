////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:2015/08/19
// Describe:
////////////////////////////////////////////////////////////////////////
#include "UserMagic.h"
#include "BasicDataSet.h"
#include "GameKernel.h"
#include "RoleMgr.h"
#include "TimeFormatter.h"
#include "MagicTargetCollector.h"

CUserMagic::CUserMagic()
{
	m_pMagicData = NULL;
}

CUserMagic::~CUserMagic()
{
	if (m_pMagicData)
	{
		CGameKernel::getInstance()->GetDatabase()->Update(m_pMagicData);
	}
	SAFE_DELETE(m_pMagicData);
}

bool CUserMagic::Create(const CGameRecordRow& rRow)
{
	m_pMagicData = new CMagicData(rRow);
	CHECK_RETURN(m_pMagicData, false);

	m_pTypeData = MAGIC_TYPE_SET::getInstance()->QueryData(m_pMagicData->magic_type);
	CHECK_RETURN2(m_pTypeData, m_pMagicData->magic_type, false);

	return true;
}

bool CUserMagic::Cast(MagicCastInfo* pInfo)
{
	CHECK_RETURN(m_pTypeData, false);
	CHECK_RETURN(m_pMagicData, false);
	CHECK_RETURN(pInfo, false);
	
	m_objMagicCastInfo = *pInfo;

	m_tLastCastTime = CTimeFormatter::TimeGet(TIME_MILLISECOND);

	this->CollectTargets();
	this->CalcDamage();
	this->MoveCaster();
	this->MoveVictim();
	this->AddStatus();
	this->AddMagicExp();
	this->Reset();

	return true;
}

bool CUserMagic::IsCastable(MagicCastInfo* pInfo)
{
	CHECK_RETURN(m_pTypeData, false);
	CHECK_RETURN(m_pMagicData, false);
	CHECK_RETURN(pInfo, false);
	CHECK_RETURN(pInfo->pCasterRole, false);

	if (this->IsInCD())
	{
		return false;
	}

	if (this->HasTargetType(MAGIC_TARGET_TYPE_GROUND))
	{
		CHECK_RETURN(pInfo->ptTargetPos != ZEROVEC3F, false);
	}
	else
	{
		CHECK_RETURN(pInfo->idTargetRole, false);
		CHECK_RETURN(pInfo->eObjectType != OBJ_NONE, false);
		CRole* pTargetRole = CRoleMgr::getInstance()->QueryRole(pInfo->idTargetRole, pInfo->eObjectType);
		CHECK_RETURN(pTargetRole, false);
		if (!pTargetRole->IsBeAttackedEnable())
		{
			return false;
		}

		pInfo->ptTargetPos = pTargetRole->GetPosition();
		CHECK_RETURN(pInfo->pCasterRole->GetSceneID() == pTargetRole->GetSceneID(), false);
	}

	Vec3f v3Distance = pInfo->ptTargetPos - pInfo->pCasterRole->GetPosition();
	if (v3Distance.len() > m_pTypeData->range_distance)
	{
		return false;
	}

	//TO-DO:施法条件检查
	MAGIC_COST_TYPE eCostType1 = MAGIC_COST_TYPE(m_pTypeData->cost_type1);
	if (!this->CheckCost(eCostType1, pInfo->pCasterRole, m_pTypeData->cost_value1))
	{
		return false;
	}

	MAGIC_COST_TYPE eCostType2 = MAGIC_COST_TYPE(m_pTypeData->cost_type2);
	if (!this->CheckCost(eCostType2, pInfo->pCasterRole, m_pTypeData->cost_value2))
	{
		return false;
	}

	return true;
}

void CUserMagic::CollectTargets()
{
	CMagicTargetCollector::getInstance()->CollectTargets(m_pTypeData, &m_objMagicCastInfo, m_vecTargets);
}

void CUserMagic::CalcDamage()
{

}

void CUserMagic::MoveCaster()
{

}

void CUserMagic::MoveVictim()
{

}

void CUserMagic::AddStatus()
{

}

void CUserMagic::AddMagicExp()
{

}

bool CUserMagic::HasTargetType(MAGIC_TARGET_TYPE eTaregetType)
{
	CHECK_RETURN(m_pTypeData, false);

	return (m_pTypeData->target_type & eTaregetType) != 0;
}

bool CUserMagic::CheckCost(MAGIC_COST_TYPE eCostType, CRole* pCaster, int nCostValue)
{
	CHECK_RETURN(pCaster, false);

	if (nCostValue <= 0)
	{
		return true;
	}

	switch (eCostType)
	{
	case MAGIC_COST_TYPE_NONE:
	{
		//do nothing
	}
	break;
	case MAGIC_COST_TYPE_MP_VALUE:
	{
		if (pCaster->GetMana() < nCostValue)
		{
			return false;
		}
	}
	break;
	case MAGIC_COST_TYPE_MP_PERCENT:
	{
		int nMp = pCaster->GetMana();
		int nMaxMp = pCaster->GetMaxMana();
		int nMpPercent = MulDiv(nMp, 100, nMaxMp);
		if (nMpPercent < nCostValue)
		{
			return false;
		}
	}
	break;
	case MAGIC_COST_TYPE_HP_VALUE:
	{
		if (pCaster->GetLife() < nCostValue)
		{
			return false;
		}
	}
	break;
	case MAGIC_COST_TYPE_HP_PERCENT:
	{
		int nHp = pCaster->GetLife();
		int nMaxHp = pCaster->GetMaxLife();
		int nHpPercent = MulDiv(nHp, 100, nMaxHp);
		if (nHpPercent < nCostValue)
		{
			return false;
		}
	}
	break;
	default:
	{
		LogErr(juce::String().formatted("CostType[%lld] CostValue[%d] invalid.", eCostType, nCostValue));
		return false;
	}
	break;
	}

	return true;
}

OBJID CUserMagic::GetID()
{
	CHECK_RETURN(m_pMagicData, ID_NONE);

	return m_pMagicData->id;
}

void CUserMagic::Reset()
{
	m_vecTargets.clear();
	m_objMagicCastInfo.Clear();
}
