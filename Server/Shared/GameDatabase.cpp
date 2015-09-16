////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:2015/07/09
// Describe:
////////////////////////////////////////////////////////////////////////
#include "GameDatabase.h"

CGameDatabase::CGameDatabase()
{

}

CGameDatabase::~CGameDatabase()
{

}

bool CGameDatabase::Create(const char* szServer, const char* szUser, const char* szPassword, const char* szDb, unsigned int nPort /*= 0*/)
{
	DEBUG_TRY
	CHECK_RETURN(szServer, false);
	CHECK_RETURN(szUser, false);
	CHECK_RETURN(szPassword, false);
	CHECK_RETURN(szDb, false);

	IF_NOT(m_objConn.connect(szDb, szServer, szUser, szPassword, nPort))
	{
		return false;
	}

	m_objConn.set_option(new mysqlpp::ReconnectOption(true));

	m_tPingTimer.StartTimer(GAMEDATABASE_PING_TIMER_PERIOD, TIMER_PERIODIC_TRUE);

	return true;
	DEBUG_CATCH
		return false;
}

void CGameDatabase::OnTimer()
{
	if (m_tPingTimer.IsTimeEnd() && m_objConn.connected())
	{
		m_objConn.ping();
	}
}

const CGameRecordset& CGameDatabase::Select(const SQLBUF& strSQL)
{
	m_res.clear();
	DEBUG_TRY
		CHECK_RETURN(strSQL.isNotEmpty(), m_res);
		CHECK_RETURN(m_objConn.connected(), m_res);
		CHECK_RETURN(strSQL.startsWithIgnoreCase("SELECT"), m_res);

		mysqlpp::Query objQuery = m_objConn.query(strSQL.toUTF8());

		DEBUGSQL(objQuery);
		m_res = objQuery.store();
	DEBUG_CATCH

	return m_res;
}

bool CGameDatabase::ExecuteSQL(const SQLBUF& strSQL)
{
	DEBUG_TRY
		CHECK_RETURN(strSQL.isNotEmpty(), false);

		mysqlpp::Query objQuery = m_objConn.query(strSQL.toUTF8());
		DEBUGSQL(objQuery);
		return objQuery.exec();
	DEBUG_CATCH
		return false;
}

CGameDatabase* CGameDatabase::CreateGameDatabase(const char* szServer, const char* szUser, const char* szPassword, const char* szDb, unsigned int nPort /*= 0*/)
{
	CHECK_RETURN(szServer, false);
	CHECK_RETURN(szUser, false);
	CHECK_RETURN(szPassword, false);
	CHECK_RETURN(szDb, false);

	CGameDatabase* pDb = CGameDatabase::CreateNew();
	IF_NOT(pDb && pDb->Create(szServer, szUser, szPassword, szDb, nPort))
	{
		SAFE_RELEASE(pDb);
		return NULL;
	}

	return pDb;
}

void CGameDatabase::DebugSQL(mysqlpp::Query& objQuery)
{
	std::cout << objQuery << std::endl;
}

OBJID64 CGameDatabase::InsertBySQL(const SQLBUF& strSQL)
{
	DEBUG_TRY
		CHECK_RETURN(strSQL.isNotEmpty(), ID_NONE);
		CHECK_RETURN(strSQL.startsWithIgnoreCase("INSERT"), ID_NONE);

		mysqlpp::Query objQuery = m_objConn.query(strSQL.toUTF8());
		DEBUGSQL(objQuery);
		if (objQuery.exec())
		{
			return objQuery.insert_id();
		}
	
	DEBUG_CATCH

	return ID_NONE;
}

