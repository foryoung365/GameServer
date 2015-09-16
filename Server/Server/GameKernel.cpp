////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:	2015/06/29
// Describe:
////////////////////////////////////////////////////////////////////////
#include "GameKernel.h"
#include "Time.h"
#include "GameServerDef.h"
#include "INIReader.h"
#include "GameServer.h"
#include "GameConfig.h"
#include "SceneMgr.h"
#include "DbTableDef.h"
#include "MemRecordset.h"
#include "RoleTypeSet.h"
#include "UserMgr.h"
#include "BasicDataSet.h"
#include "RoleMgr.h"

juce_ImplementSingleton_SingleThreaded(CGameKernel);

CGameKernel::CGameKernel() : IKernel(THREAD_INDEX_GAME)
{
	m_pDatabase = NULL;
}

CGameKernel::~CGameKernel()
{
	//各类管理器，数据集的释放，请放到OnRelease
	CGameKernel::clearSingletonInstance();
}

void CGameKernel::OnTimer()
{
	CMemRecordset::getInstance()->OnTimer();
	CUserMgr::getInstance()->OnTimer();
}


void CGameKernel::OnTimeTrigger(const TimeTrigger_t& pTrigger)
{

}

bool CGameKernel::Create()
{
	bool bSucc = IKernel::Create();
	CHECK_RETURN(bSucc, false);

	INIReader objIni(CONFIG_FILE_NAME);
	DbConfig_t stDbConfig;
	CHECK_RETURN(GameServer()->GetGameDbConfig(stDbConfig), false);

	m_pDatabase = CGameDatabase::CreateGameDatabase(stDbConfig.strServer.c_str(), stDbConfig.strUser.c_str(), stDbConfig.strPassword.c_str(), stDbConfig.strDatabase.c_str());
	CHECK_RETURN(m_pDatabase, false);

	InsertReservedDbRecord();

	//创建各类基础数据集合
	SQLBUF strSQL;
	IF_NOT(CGameConfigSet::getInstance()->Create())
	{
		return false;
	}

	IF_NOT(CSceneMgr::getInstance()->Create())
	{
		return false;
	}

	IF_NOT(CRoleTypeSet::getInstance()->Create())
	{
		return false;
	}

	strSQL.formatted("SELECT * FROM %s", TBL_MAGIC_TYPE);
	IF_NOT(MAGIC_TYPE_SET::getInstance()->Create(this->GetDatabase(), strSQL))
	{
		return false;
	}

	//创建各类管理器
	IF_NOT(CMemRecordset::getInstance()->Create())
	{
		return false;
	}	

	IF_NOT(CUserMgr::getInstance()->Create())
	{
		return false;
	}

	IF_NOT(CRoleMgr::getInstance()->Create())
	{
		return false;
	}

	return true;
}

void CGameKernel::OnRun()
{
DEBUG_TRY
	this->RecvPipeMessage();
DEBUG_CATCH
}

void CGameKernel::Release()
{
	this->OnRelease();
	CGameKernel::deleteInstance();
}

CGameDatabase* CGameKernel::GetDatabase()
{
	return CGameKernel::getInstance()->GetDatabasePriv();
}

CGameDatabase* CGameKernel::GetDatabasePriv()
{
	CHECK_RETURN(m_pDatabase, NULL);

	return m_pDatabase;
}

void CGameKernel::InsertReservedDbRecord()
{
	OBJID idReserved = CGameServer::getInstance()->GetServerID();
	idReserved <<= OBJID_REAL_ID_BITS;

	SQLBUF strSQL;
	strSQL << "INSERT INTO " << TBL_USER << "(`id`, `name`) VALUES(" << idReserved << ", 'RESERVE_ID')";
	CGameKernel::GetDatabase()->ExecuteSQL(strSQL);
}

void CGameKernel::OnRelease()
{
	//删除各类管理器
	CRoleMgr::deleteInstance();
	CUserMgr::deleteInstance();
	CMemRecordset::deleteInstance();
	MAGIC_TYPE_SET::deleteInstance();

	//删除各类基础数据集合
	CSceneMgr::deleteInstance();
	CRoleTypeSet::deleteInstance();
	CGameConfigSet::deleteInstance();

	SAFE_RELEASE(m_pDatabase);
}

void CGameKernel::DebugCommand(juce::String strCmd)
{
	if (strCmd.startsWithIgnoreCase("TestUtf8"))
	{
		SQLBUF strSQL;
		strSQL << "INSERT INTO " << TBL_USER << "(`name`) VALUES('" << "中文TEST" << "')";
		this->GetDatabase()->InsertBySQL(strSQL);
	}
}


