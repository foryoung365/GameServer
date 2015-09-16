////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:2015/07/13
// Describe:
////////////////////////////////////////////////////////////////////////
#include "GameConfig.h"
#include "GameDatabase.h"
#include "GameKernel.h"
#include "DbTableDef.h"

juce_ImplementSingleton_SingleThreaded(CGameConfigSet);

CGameConfigSet::CGameConfigSet()
{

}

CGameConfigSet::~CGameConfigSet()
{
	MAP_DELETE_ALL(m_mapConfig, CONFIG_DATA_MAP::iterator);
	CGameConfigSet::clearSingletonInstance();
}

bool CGameConfigSet::Create()
{
	SQLBUF strSQL;

	strSQL << "SELECT * FROM " << TBL_CONFIG;
	
	const CGameRecordset&  rRes = CGameKernel::GetDatabase()->Select(strSQL);

	for (int id = 0; id < rRes.size(); ++id)
	{
		CConfigData* pData = new CConfigData(rRes.at(id));
		if (pData == NULL)
		{
			continue;
		}

		switch (pData->type)
		{
		default:
			m_mapConfig.insert(std::make_pair(pData->id, pData));
			break;
		}
	}

	return true;
}

CConfigData* CGameConfigSet::QueryConfigType(OBJID32 idType)
{
	MAP_FIND_IMPL(m_mapConfig, idType, CONFIG_DATA_MAP::iterator);
}
