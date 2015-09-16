////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:2015/07/09
// Describe:数据库线程池的工人线程
////////////////////////////////////////////////////////////////////////
#ifndef _DBJOB_H_
#define _DBJOB_H_

#include <map>
#include "BaseDefine.h"
#include "juce_core/juce_core.h"
#include "GameObject.h"
#include "GameDatabase.h"
#include "DbTableDef.h"
#include "BasicTypeDef.h"

#define DB_JOB_NAME_PREFIX		"DB_JOB_"

using namespace juce;

class CDbJob : public ThreadPoolJob
{
public:
	CDbJob(DbConfig_t* pDbConfig, int nIndex);
	virtual ~CDbJob();
public:
	bool IsInitOK();
	virtual JobStatus runJob();
	void Reset();
	bool StartToLoadUserData(const UserParm_t& rParm, ThreadPool& objPool);
	const UserParm_t& GetUserParm();
	LOADED_USER_DATA_MAP* GetLoadedUserMap();
private:
	bool PreLoadUserData();
	bool LoadUserData();
	bool PostLoadUserData();
	bool LoadUserRecordSet(DB_LOAD_DATA_TYPE eType, const SQLBUF& strSQL);
private:
	CGameDatabase* m_pDb;
	LOADED_USER_DATA_MAP* m_pMapLoaded;
	UserParm_t m_stUserParm;
};

#endif	//end of define _DBJOB_H_