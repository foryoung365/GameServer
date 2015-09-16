////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:2015/07/14
// Describe:
////////////////////////////////////////////////////////////////////////
#include <vector>
#include "MemRecordset.h"

#define MEM_RECORDSET_SCAN_PERIOD			60	//数据过期扫描周期
#define MEM_RECORDSET_TIMEOUT_PERIOD		600	//数据过期时间

juce_ImplementSingleton_SingleThreaded(CMemRecordset);

CMemRecordset::CMemRecordset()
{
	
}

CMemRecordset::~CMemRecordset()
{
	for (RECORDSET_MAP::iterator it = m_mapRecordsets.begin(); it != m_mapRecordsets.end(); ++it)
	{
		LOADED_USER_DATA_MAP* pMap = it->second;
		if (pMap == NULL)
		{
			continue;
		}

		for (LOADED_USER_DATA_MAP::iterator iter = pMap->begin(); iter != pMap->end(); ++iter)
		{
			CGameRecordset* pRes = iter->second;
			if (pRes == NULL)
			{
				continue;
			}

			SAFE_DELETE(pRes);
		}
		pMap->clear();
		SAFE_DELETE(pMap);
	}

	m_mapRecordsets.clear();

	CMemRecordset::clearSingletonInstance();
}

void CMemRecordset::ReleaseRecordset(OBJID idUser)
{
	CHECK(idUser);

	LOADED_USER_DATA_MAP* pMap = this->QueryRecordsetMap(idUser);
	if (pMap == NULL)
	{
		return;
	}

	for (LOADED_USER_DATA_MAP::iterator iter = pMap->begin(); iter != pMap->end(); ++iter)
	{
		CGameRecordset* pRes = iter->second;
		if (pRes == NULL)
		{
			continue;
		}

		SAFE_DELETE(pRes);
	}
	pMap->clear();

	m_mapRecordsets.erase(idUser);
	m_mapUserTime.erase(idUser);
}

void CMemRecordset::AddRecordsetMap(OBJID idUser, OBJID64 idRecordsetMap)
{
	CHECK(idRecordsetMap);

	LOADED_USER_DATA_MAP* pMap = (LOADED_USER_DATA_MAP*)idRecordsetMap;
	m_mapRecordsets.insert(std::make_pair(idUser, pMap));
	m_mapUserTime[idUser] = CTimeFormatter::TimeGet(TIME_SECOND);
}

CGameRecordset* CMemRecordset::QueryRecordset(OBJID idUser, DB_LOAD_DATA_TYPE eType)
{
	CHECK_RETURN(idUser, NULL);
	
	LOADED_USER_DATA_MAP* pMap = this->QueryRecordsetMap(idUser);
	if (pMap == NULL)
	{
		return NULL;
	}

	LOADED_USER_DATA_MAP::iterator it = pMap->find(eType);
	if (it == pMap->end())
	{
		return NULL;
	}

	return it->second;
}

LOADED_USER_DATA_MAP* CMemRecordset::QueryRecordsetMap(OBJID idUser)
{
	MAP_FIND_IMPL(m_mapRecordsets, idUser, RECORDSET_MAP::iterator);
}

bool CMemRecordset::Create()
{
	m_tTimer.StartTimer(MEM_RECORDSET_SCAN_PERIOD, TIMER_PERIODIC_TRUE);

	return true;
}

void CMemRecordset::OnTimer()
{
	if (m_tTimer.IsTimeEnd())
	{
		std::vector<OBJID> vecId;
		time_t tCurrTime = CTimeFormatter::TimeGet(TIME_SECOND);
		for (USER_TIME_MAP::iterator it = m_mapUserTime.begin(); it != m_mapUserTime.end(); ++it)
		{
			if (it->second + MEM_RECORDSET_TIMEOUT_PERIOD < tCurrTime)
			{
				vecId.push_back(it->first);
			}
		}

		for (int i = 0; i < vecId.size(); ++i)
		{
			OBJID idUser = vecId.at(i);
			this->ReleaseRecordset(idUser);
		}
	}
}
