////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:	2015/07/07
// Describe:游戏数据库,基于mysql++的简单封装
////////////////////////////////////////////////////////////////////////
#ifndef _GAMEDATABASE_H_
#define _GAMEDATABASE_H_

#include <string>
#include "BaseDefine.h"
#include "Timer.h"
#include "mysql++.h"
#include "GameObject.h"

#define GAMEDATABASE_PING_TIMER_PERIOD		3600	//每小时PING一次，防止MYSQL连接timeout

typedef struct DbConfig_s
{
	std::string strServer;
	std::string strUser;
	std::string strPassword;
	std::string strDatabase;
}DbConfig_t;

typedef mysqlpp::StoreQueryResult CGameRecordset;
typedef mysqlpp::Row CGameRecordRow;
typedef std::map<OBJID, CGameRecordset*> LOADED_USER_DATA_MAP;

#ifndef _DEBUG
#define DEBUGSQL(q) 
#else
#define DEBUGSQL(q) DebugSQL(q)
#endif

class CGameDatabase
{
private:
	CGameDatabase();
	~CGameDatabase();
public:
	//创建一个数据库对象，退出程序前必须手动释放
	static CGameDatabase* CreateGameDatabase(const char* szServer, const char* szUser, const char* szPassword, const char* szDb, unsigned int nPort = 0);
private:
	static CGameDatabase* CreateNew() { return new CGameDatabase; }
	bool Create(const char* szServer, const char* szUser, const char* szPassword, const char* szDb, unsigned int nPort = 0);
public:
	void Release() { delete this; }

	//查询并返回默认结果集，效率较高，CRecordSet& res可以使用res[0][0]的方式访问，也可以使用类似res[0]["id"]的方式访问，接口类似vector
	//结果集临时数据，如果再次执行其他查询语句，结果集将会被覆盖掉
	//如果只是马上用完结果集就抛弃，请使用const CRecordSet& rRes = Select(strSQL)，这样不需要将数据复制一遍
	//如果需要保存默认结果集，可以直接使用CRecordSet objRes = Select(strSQL)来复制结果集的内容
	//如果不需要创建和保存表数据的话，尽量使用本接口
	const CGameRecordset& Select(const SQLBUF& strSQL);

	//执行指定的SQL语句，返回执行结果
	bool ExecuteSQL(const SQLBUF& strSQL);

	//执行SELECT语句，并将结果集保存到给定的vector容器中，效率较const CRecordSet& Select(const SQLBUF& strSQL)要低
	//类型T是对应的CXXXData类
	//如果需要保存结果集，才使用本接口，否则尽量使用const CRecordSet& Select(const SQLBUF& strSQL)
	template<class T>
	bool SelectAndSaveTo(const SQLBUF& strSQL, std::vector<T>& vecData);

	//执行Update，类型T是对应的CXXXData类
	template<class T>
	bool Update(T& rData);

	//执行Update，类型T是对应的CXXXData类
	template<class T>
	bool Update(T* pData);

	//插入数据，类型T是对应的CXXXData类，如果成功，会更新insert_id字段的值
	template<class T>
	bool Insert(T& rData);

	//插入数据，类型T是对应的CXXXData类，如果成功，会更新insert_id字段的值
	template<class T>
	bool Insert(T* pData);

	//使用SQL语句insert数据，返回插入记录的ID
	OBJID64 InsertBySQL(const SQLBUF& strSQL);

	//删除记录，类型T是对应的CXXXData类
	template<class T>
	bool Delete(T& rData);

	//删除记录，类型T是对应的CXXXData类
	template<class T>
	bool Delete(T* pData);

	//定时器，如果服务器要较长时间开放，为了防止MYSQL连接空闲超时，请调用Ontimer
	//默认是每隔一个小时会执行一次ping来保持连接
	void OnTimer();

	OBJID64 GetInsertedId();
private:
	void DebugSQL(mysqlpp::Query& objQuery);
private:
	mysqlpp::Connection m_objConn;
	CTimer m_tPingTimer;
	CGameRecordset m_res;
};

template<class T>
bool CGameDatabase::SelectAndSaveTo(const SQLBUF& strSQL, std::vector<T>& vecData)
{
	DEBUG_TRY
	bool bSucc = this->Select(strSQL);
	if (!bSucc)
	{
		return false;
	}

	for (int i = 0; i < m_res.size(); ++i)
	{
		vecData.push_back(m_res[i]);
	}

	m_res.clear();

	return true;
	DEBUG_CATCH

		return false;
}

template<class T>
bool CGameDatabase::Update(T& rData)
{
	DEBUG_TRY
	mysqlpp::Query objQuery = m_objConn.query();
	objQuery.update(rData);

	DEBUGSQL(objQuery);
	return objQuery.exec();
	DEBUG_CATCH

		return false;
}

template<class T>
bool CGameDatabase::Update(T* pData)
{
	CHECK_RETURN(pData, false);
	DEBUG_TRY
		mysqlpp::Query objQuery = m_objConn.query();
		objQuery.update(*pData);

		DEBUGSQL(objQuery);
		return objQuery.exec();
	DEBUG_CATCH

	return false;
}

template<class T>
bool CGameDatabase::Insert(T& rData)
{
DEBUG_TRY
	mysqlpp::Query objQuery = m_objConn.query();
	objQuery.insert(rData);

	DEBUGSQL(objQuery);
	bool bSucc = objQuery.exec();
	if (bSucc)
	{
		rData.set(objQuery.insert_id());
	}

	return bSucc;
DEBUG_CATCH

	return false;
}

template<class T>
bool CGameDatabase::Insert(T* pData)
{
	CHECK_RETURN(pData, false);
	DEBUG_TRY
		mysqlpp::Query objQuery = m_objConn.query();
		objQuery.insert(*pData);

		DEBUGSQL(objQuery);
		bool bSucc = objQuery.exec();
		if (bSucc)
		{
			pData->set(objQuery.insert_id());
		}

		return bSucc;
	DEBUG_CATCH

	return false;
}

template<class T>
bool CGameDatabase::Delete(T& rData)
{
	DEBUG_TRY
	mysqlpp::Query objQuery = m_objConn.query();
	objQuery << "DELETE FROM `" << rData.table() << "` WHERE " << rData.equal_list(true);

	DEBUGSQL(objQuery);
	return objQuery.exec();
	DEBUG_CATCH

		return false;
}

template<class T>
bool CGameDatabase::Delete(T* pData)
{
	CHECK_RETURN(pData, false);
	DEBUG_TRY
	mysqlpp::Query objQuery = m_objConn.query();
	objQuery << "DELETE FROM `" << pData->table() << "` WHERE " << pData->equal_list(true);

	DEBUGSQL(objQuery);
	return objQuery.exec();
	DEBUG_CATCH

		return false;
}


#endif	//end of define _GAMEDATABASE_H_