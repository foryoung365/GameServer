////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:2015/07/14
// Describe:
////////////////////////////////////////////////////////////////////////
#include "RoleTypeSet.h"
#include "GameKernel.h"
#include "DbTableDef.h"

juce_ImplementSingleton_SingleThreaded(CRoleTypeSet);


CRoleTypeSet::CRoleTypeSet()
{

}

CRoleTypeSet::~CRoleTypeSet()
{
	MAP_DELETE_ALL(m_mapRoleType, ROLE_TYPE_SET::iterator);
	CRoleTypeSet::clearSingletonInstance();
}

CRoleTypeData* CRoleTypeSet::QueryRoleType(OBJID32 idRoleType)
{
	MAP_FIND_IMPL(m_mapRoleType, idRoleType,  ROLE_TYPE_SET::iterator);
}

bool CRoleTypeSet::Create()
{
	CGameDatabase* pDb = CGameKernel::getInstance()->GetDatabase();
	CHECK_RETURN(pDb, false);

	SQLBUF szSQL;
	szSQL << "SELECT * FROM " << TBL_ROLE_TYPE;

	const CGameRecordset& rRes = pDb->Select(szSQL);
	for (int i = 0; i < rRes.size(); ++i)
	{
		CRoleTypeData* pData = new CRoleTypeData;
		*pData = rRes.at(i);
		m_mapRoleType.insert(std::make_pair(pData->id, pData));
	}

	return true;
}
