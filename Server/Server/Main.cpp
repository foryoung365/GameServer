////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:	2015/05/05
// Describe:游服主程序
////////////////////////////////////////////////////////////////////////
#include "GameServer.h"
#ifdef _DEBUG
#include "MemLeakDetect.h"

CMemLeakDetect objMemLeakDetect;
#endif

int main(void)
{
	if(CGameServer::getInstance() && CGameServer::getInstance()->Create())
	{
		CGameServer::getInstance()->StartServer();
		CGameServer::getInstance()->Run();
		CGameServer::getInstance()->StopServer();
	}

	CGameServer::deleteInstance();

	return 0;
}