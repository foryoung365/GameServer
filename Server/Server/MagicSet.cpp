////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:2015/08/17
// Describe:
////////////////////////////////////////////////////////////////////////
#include "MagicSet.h"
#include "DbTableDef.h"
#include "GameKernel.h"
#include "User.h"

CMagicSet::CMagicSet()
{
	m_pOwner = false;
}

CMagicSet::~CMagicSet()
{
	MAP_RELEASE_ALL(m_mapMagics, MAGIC_MAP::iterator);
}

bool CMagicSet::Create(CRole* pRole)
{
	CHECK_RETURN(pRole, false);

	m_pOwner = pRole;

	SQLBUF strSQL;
	strSQL.formatted("SELECT * FROM %s WHERE onwer_id = %llu", TBL_MAGIC, pRole->GetID());

	const CGameRecordset& rRes = CGameKernel::getInstance()->GetDatabase()->Select(strSQL);
	for (int i = 0; i < rRes.size(); ++i)
	{
		CMagic* pMagic = CMagic::CreateNew(pRole->GetType());
		IF_NOT (pMagic && pMagic->Create(rRes.at(i)))
		{
			SAFE_RELEASE(pMagic);
			continue;
		}

		m_mapMagics[pMagic->GetID()] = pMagic;
	}

	return true;
}

bool CMagicSet::CastMagic(OBJID idMagic, CRole* pTargetRole, Point3f ptTargetPos)
{
	DEBUG_TRY
		CHECK_RETURN(idMagic, false);

		CMagic* pMagic = this->QueryMagic(idMagic);
		CHECK_RETURN2(pMagic, idMagic, false);

		MagicCastInfo stCastInfo;
		
		stCastInfo.eObjectType = pTargetRole->GetType();
		stCastInfo.idTargetRole = pTargetRole->GetID();
		stCastInfo.pCasterRole = pTargetRole;
		stCastInfo.ptTargetPos = ptTargetPos;

		if (!pMagic->IsCastable(&stCastInfo))
		{
			return false;
		}

		return pMagic->Cast(&stCastInfo);
	DEBUG_CATCH

	return false;
}

bool CMagicSet::HasMagic(OBJID idMagic)
{
	CHECK_RETURN(idMagic, false);

	CMagic* pMagic = this->QueryMagic(idMagic);
	if (pMagic == NULL)
	{
		return false;
	}

	return true;
}

CMagic* CMagicSet::QueryMagic(OBJID idMagic)
{
	CHECK_RETURN(idMagic, NULL);

	MAP_FIND_IMPL(m_mapMagics, idMagic, MAGIC_MAP::iterator);
}
