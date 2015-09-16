////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:2015/07/09
// Describe:
////////////////////////////////////////////////////////////////////////
#include "DbJob.h"
#include "DbTableDef.h"

CDbJob::CDbJob(DbConfig_t* pDbConfig, int nIndex) : ThreadPoolJob(juce::String() << DB_JOB_NAME_PREFIX << nIndex)
{
	m_pDb = NULL;
	this->Reset();

	if (pDbConfig == NULL)
	{
		return;
	}

	m_pDb = CGameDatabase::CreateGameDatabase(pDbConfig->strServer.c_str(), pDbConfig->strUser.c_str(), pDbConfig->strPassword.c_str(), pDbConfig->strDatabase.c_str());
	m_pMapLoaded = NULL;
}

CDbJob::~CDbJob()
{
	SAFE_RELEASE(m_pDb);
	if (m_pMapLoaded)
	{
		for (LOADED_USER_DATA_MAP::iterator it = m_pMapLoaded->begin(); it != m_pMapLoaded->end(); ++it)
		{
			SAFE_DELETE(it->second);
		}
		m_pMapLoaded->clear();
		SAFE_DELETE(m_pMapLoaded);
	}
	
}

ThreadPoolJob::JobStatus CDbJob::runJob()
{
	if (this->shouldExit())
	{
		return ThreadPoolJob::jobNeedsRunningAgain;
	}

	IF_NOT (this->PreLoadUserData())
	{
		return ThreadPoolJob::jobHasFinished;
	}

	if (this->shouldExit())
	{
		return ThreadPoolJob::jobNeedsRunningAgain;
	}

	IF_NOT(this->LoadUserData())
	{
		return ThreadPoolJob::jobHasFinished;
	}

	if (this->shouldExit())
	{
		return ThreadPoolJob::jobNeedsRunningAgain;
	}

	IF_NOT(this->PostLoadUserData())
	{
		return ThreadPoolJob::jobHasFinished;
	}

	return ThreadPoolJob::jobHasFinished;
}

bool CDbJob::PreLoadUserData()
{
	CHECK_RETURN(m_pDb, false);

	return true;
}

bool CDbJob::LoadUserData()
{
	CHECK_RETURN(m_pDb, false);

	SQLBUF strSQL;

	//异步加载玩家数据的方式参考此条
	strSQL << "SELECT * FROM " << TBL_USER << " WHERE id=" << m_stUserParm.idUser << " LIMIT 1";

	this->LoadUserRecordSet(DB_LOAD_USER_DATA, strSQL);

	return true;
}

bool CDbJob::PostLoadUserData()
{
	CHECK_RETURN(m_pDb, false);

	return true;
}

bool CDbJob::IsInitOK()
{
	return m_pDb != NULL;
}

void CDbJob::Reset()
{
	m_stUserParm.idAccount = ID_NONE;
	m_stUserParm.idUser = ID_NONE;
	m_stUserParm.idPeer = ID_NONE;
	m_stUserParm.strIP.clear();
	//这里MAP不释放，只是直接重置掉
	//将数据发送到GameKernel去创建CUser，成功后再释放
	//这种做法很不好，但是为了效率先这么做
	m_pMapLoaded = NULL;
}

bool CDbJob::StartToLoadUserData(const UserParm_t& rParm, ThreadPool& objPool)
{
	CHECK_RETURN(m_stUserParm.idUser == ID_NONE, false);

	m_stUserParm = rParm;

	m_pMapLoaded = new LOADED_USER_DATA_MAP;
	CHECK_RETURN(m_pMapLoaded, false);

	objPool.addJob(this, false);

	return true;
}

const UserParm_t& CDbJob::GetUserParm()
{
	return m_stUserParm;
}

LOADED_USER_DATA_MAP* CDbJob::GetLoadedUserMap()
{
	CHECK_RETURN(m_pMapLoaded, NULL);

	return m_pMapLoaded;
}

bool CDbJob::LoadUserRecordSet(DB_LOAD_DATA_TYPE eType, const SQLBUF& strSQL)
{
	const CGameRecordset& rRes = m_pDb->Select(strSQL);
	if (rRes.empty())
	{
		return true;
	}

	CGameRecordset* pResSet = new CGameRecordset(rRes);
	CHECK_RETURN2(pResSet, eType, false);
	m_pMapLoaded->insert(std::make_pair(eType, pResSet));

	return true;
}
