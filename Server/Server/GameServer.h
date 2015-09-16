////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:	2015/06/30
// Describe:ÓÎ·þÊµÀý
////////////////////////////////////////////////////////////////////////
#ifndef _GAMESERVER_H_
#define _GAMESERVER_H_

#include <vector>
#include "juce_core/juce_core.h"
#include "Kernel.h"
#include "GameServerDef.h"
#include "MessagePipe.h"
#include "MsgNetwork.pb.h"
#include "GameDatabase.h"

class CGameServer
{
public:
	CGameServer();
	~CGameServer();
public:
	static bool GetGameDbConfig(DbConfig_t& rDbConfig);

public:
	juce_DeclareSingleton_SingleThreaded(CGameServer, true);
	bool StartServer();
	void Run();
	void StopServer();
	OBJID16 GetServerID() { return m_u16ServerID; }
	bool Create();
private:
	void CreateLogDirectories();
	bool CreateLogFile();
	bool IsRunning() { return m_bIsRunning; }
	void Shutdown();
	void GetCmd();
	void ProcCmd();
	bool SendPipeMessage(THREAD_INDEX idxThread, CMsgNetwork* pMsgNetwork);
	bool RecvPipeMessage();
private:
	typedef std::vector<IKernel*> KERNEL_VEC;
	KERNEL_VEC m_vecKernels;
	OBJID16 m_u16ServerID;
	juce::FileLogger* m_pLogFile;
	bool m_bInitOK;
	bool m_bIsRunning;
	CMessagePipe* m_pPipe;
	std::string m_strCmdText;
};

#define GameServer	CGameServer::getInstance

#endif	//end of define _GAMESERVER_H_