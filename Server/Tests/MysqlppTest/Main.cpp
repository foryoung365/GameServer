////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:	2015/05/05
// Describe:≤‚ ‘
////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <vector>
#include "GameDatabase.h"
#include "mysql++.h"
#include "UserData.h"
#include "time.h"
#include "StockData.h"
#include "ServerListData.h"


using namespace std;

int UserDataTest()
{
	clock_t t1 = clock();
	mysqlpp::Connection objConn;
	if (!objConn.connect("sjmy3d001_base", "127.0.0.1", "root", "root"))
	{
		return -1;
	}

	objConn.set_option(new mysqlpp::ReconnectOption(true));

	clock_t t2 = clock();
	clock_t t21 = clock();
	mysqlpp::Query objQuery = objConn.query("SELECT * FROM cq_user");
	vector<CUserData> res;
	objQuery.storein(res);
	clock_t t22 = clock();
	mysqlpp::StoreQueryResult res2;
	objQuery = objConn.query("SELECT * FROM cq_user");
	res2 = objQuery.store();
	clock_t t23 = clock();
	vector<CUserData> vecData;
	for (int i = 0; i < res2.size(); ++i)
	{
		vecData.push_back(res2[i]);
	}
	clock_t t3 = clock();

	// 	for (vector<CUserData>::iterator it = res.begin(); it != res.end(); ++it)
	// 	{
	// 		clock_t t4 = clock();
	// 		CUserData row = *it;
	// 		clock_t t5 = clock();
	// 		cout << row.id << ", " << row.name << ", " << row.level << "," << t5 - t4 << endl;
	// 	}

	CUserData n = res[0];
	clock_t t31 = clock();
	n.name = "123";
	clock_t t32 = clock();
	objQuery.update(res[0], n);
	cout << objQuery << endl;
	clock_t t33 = clock();
	objQuery.exec();

	clock_t t6 = clock();

	cout << t2 - t1 << ", " << t3 - t2 << ", " << t6 - t3 << endl;
	cout << t21 - t2 << ", " << t22 - t21 << ", " << t23-t22 << ", " << t3 - t23 << endl;
	cout << t31 - t3 << ", " << t32 - t31 << ", " << t33 - t32 << ", " << t6-t33 << endl;

	return 0;
}

int StockDataTest()
{
	clock_t t1 = clock();
	mysqlpp::Connection objConn;

	if (!objConn.connect("mysql_cpp_data", "127.0.0.1", "root", "root"))
	{
		return -1;
	}

	objConn.set_option(new mysqlpp::ReconnectOption(true));

	clock_t t2 = clock();
	clock_t t21 = clock();
	mysqlpp::Query objQuery = objConn.query("SELECT * FROM stock");
	vector<CStockData> res;
	objQuery.storein(res);
	clock_t t22 = clock();
	mysqlpp::StoreQueryResult res2;
	objQuery = objConn.query("SELECT * FROM stock");
	res2 = objQuery.store();
	clock_t t23 = clock();
	vector<CStockData> vecData;
	for (int i = 0; i < res2.size(); ++i)
	{
		vecData.push_back(res2[i]);
	}
	clock_t t3 = clock();

	// 	for (vector<CUserData>::iterator it = res.begin(); it != res.end(); ++it)
	// 	{
	// 		clock_t t4 = clock();
	// 		CUserData row = *it;
	// 		clock_t t5 = clock();
	// 		cout << row.id << ", " << row.name << ", " << row.level << "," << t5 - t4 << endl;
	// 	}

	CStockData n = res[0];
	clock_t t31 = clock();
	n.item = "123";
	clock_t t32 = clock();
	objQuery.update(res[0], n);
	clock_t t33 = clock();
	cout << objQuery << endl;
	objQuery.exec();

	clock_t t6 = clock();

	cout << t2 - t1 << ", " << t3 - t2 << ", " << t6 - t3 << endl;
	cout << t21 - t2 << ", " << t22 - t21 << ", " << t23 - t22 << ", " << t3 - t23 << endl;
	cout << t31 - t3 << ", " << t32 - t31 << ", " << t33 - t32 << ", " << t6 - t33 << endl;

	return 0;
}

int ServerListDataTest()
{
	CServerListData row(0);
	row.section_id = 1;
	row.name = "Test123";
	row.real_name = "Test123";
	row.domain_name = "123.com";
	row.server_index = 123;
	row.mask = 1;
	row.subsection = 1;
	row.order_time = 0;
	row.flag = 0;

	mysqlpp::Connection objConn;

	if (!objConn.connect("sjmy3d001_base", "127.0.0.1", "root", "root"))
	{
		return -1;
	}

	mysqlpp::Query objQuery = objConn.query();

	objQuery.insert(row);

	cout << objQuery << endl;

	objQuery.exec();

	row.id = objQuery.insert_id();

	row.name = "test245";
	objQuery.update(row);

	cout << objQuery << endl;

	objQuery.exec();

	return 0;
}

int GameDbTest()
{
	CGameDatabase* pDb = CGameDatabase::CreateGameDatabase("127.0.0.1", "root", "root", "sjmy3d001_base");
	if (pDb == NULL)
	{
		return -1;
	}

	SQLBUF strSQL;
	strSQL << "SELECT * FROM cq_server_list";
	const StoreQueryResult& res = pDb->Select(strSQL);

	for (int i = 0; i < res.size(); ++i)
	{
		for (int j = 0; j < res[i].size(); ++j)
		{
			cout << res[i][j] << ",";
		}
		cout << endl;
	}

	std::vector<CServerListData> vecData;

	pDb->SelectAndSaveTo(strSQL, vecData);

	for (int i = 0; i < vecData.size(); ++i)
	{
		CServerListData& rData = vecData[i];

		cout << rData.id << rData.name << endl;
	}

	CServerListData objData;

	objData.id = 0;
	objData.section_id = 2;
	objData.name = "GameDb";
	objData.real_name = "Db";
	objData.domain_name = "Db.com";
	objData.server_index = 333;
	objData.mask = 1;
	objData.subsection = 5;
	objData.order_time = 0;
	objData.flag = 0;

	pDb->Insert(objData);

	cout << objData.id << endl;

	objData.name = "Db2";
	pDb->Update(objData);

	pDb->Delete(objData);

	SAFE_RELEASE(pDb);

	return 0;
}

int main(void)
{
	GameDbTest();
	
	getchar();

	return 0;
}