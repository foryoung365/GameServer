////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:	2015/06/30
// Describe:
////////////////////////////////////////////////////////////////////////
#include "GameServer.h"
#include "INIReader.h"
#include "BaseDefine.h"
#include "AccountSocketKernel.h"
#include "ServerSocketKernel.h"
#include "DatabaseKernel.h"
#include "GameKernel.h"
#include "LoginKernel.h"
#include "MsgHandler.h"
#include "GameObject.h"

using namespace juce;

juce_ImplementSingleton_SingleThreaded(CGameServer);

CGameServer::CGameServer()
{
	m_pPipe = NULL;
	m_bIsRunning = false;
}

CGameServer::~CGameServer()
{
	this->Shutdown();

	SAFE_RELEASE(m_pPipe);

	for (int i = 0; i < m_vecKernels.size(); ++i)
	{
		SAFE_RELEASE(m_vecKernels.at(i));
	}

	Logger::setCurrentLogger(NULL);
	SAFE_DELETE(m_pLogFile);

	this->clearSingletonInstance();

	CMessagePipeContext::deleteInstance();

	google::protobuf::ShutdownProtobufLibrary();
}

bool CGameServer::StartServer()
{
	for (int i = 0; i < m_vecKernels.size(); ++i)
	{
		IKernel* pKernel = m_vecKernels.at(i);
		if (pKernel == NULL)
		{
			continue;
		}

		pKernel->startThread();
	}

	m_bIsRunning = true;

	juce::String strText;
	strText << "All Thread Start OK, Game Server is running now..." << newLine;
	LogBoth(strText);
	std::cout << CMD_PROMT;

	return true;
}

void CGameServer::StopServer()
{
	m_bIsRunning = false;
}

bool CGameServer::Create()
{
	CreateLogDirectories();

	CHECK_RETURN(this->CreateLogFile(), false);

	INIReader objIni(CONFIG_FILE_NAME);

	int nErr = objIni.ParseError();
	CHECK_RETURN(nErr == 0, false);

	m_u16ServerID = (OBJID16)(objIni.GetInteger(GAME_SERVER_SECTION, GAME_SERVER_ID, 0));

	//初始化消息管道上下文
	CMessagePipeContext::getInstance();

	MessagePipeInfo_t stPipeInfo;
	for (int i = 0; i < THREAD_INDEX_MAX; ++i)
	{
		if (i == THREAD_INDEX_MAIN)
		{
			stPipeInfo.strMyThreadName = g_stThreadInfos[i];
		}
		else
		{
			stPipeInfo.vecOtherThreadNames.push_back(g_stThreadInfos[i]);
		}
	}

	m_pPipe = CMessagePipe::CreateNew();
	IF_NOT (m_pPipe && m_pPipe->Create(&stPipeInfo))
	{
		SAFE_RELEASE(m_pPipe);
		return false;
	}

	//主线程是自己，设为空
	m_vecKernels.push_back(NULL);

	for (int i = THREAD_INDEX_SERVER_SOCKET; i < THREAD_INDEX_MAX; ++i)
	{
		IKernel* pKernel = NULL;
		switch (i)
		{
		case THREAD_INDEX_SERVER_SOCKET:
		{
			pKernel = CServerSocketKernel::getInstance();
		}
		break;
		case THREAD_INDEX_AS_SOCKET:
		{
			pKernel = CAccountSocketKernel::getInstance();
		}
		break;
		case THREAD_INDEX_LOGIN:
		{
			pKernel = CLoginKernel::getInstance();
		}
		break;
		case THREAD_INDEX_DATABASE:
		{
			pKernel = CDatabaseKernel::getInstance();
		}
		break;
		case THREAD_INDEX_GAME:
		{
			pKernel = CGameKernel::getInstance();
		}
		break;
		default:
			break;
		}

		IF_NOT2 (pKernel && pKernel->Create(), i)
		{
			SAFE_RELEASE(pKernel);
			return false;
		}
		
		m_vecKernels.push_back(pKernel);

		String strText;
		strText << "Thread " << pKernel->getThreadName() << " init OK..." << newLine;
		LogBoth(strText);
	}

	return true;
}

bool CGameServer::CreateLogFile()
{
	CHECK_RETURN(m_pLogFile == NULL, false);
	String strFileName = GAME_SERVER_LOG_FILENAME;
	strFileName += Time::getCurrentTime().formatted("%Y-%m-%d") + GAME_SERVER_LOG_SUFFIX; 
	String strWelcomeMsg = "\t\t\tGAME SERVER ";
	strWelcomeMsg += GAME_SERVER_VERSION;
	strWelcomeMsg += newLine;
	strWelcomeMsg += "**********************************************************";
	m_pLogFile = new FileLogger(File::getCurrentWorkingDirectory().getChildFile(GAME_SERVER_SYSLOG_DIR).getChildFile(strFileName), strWelcomeMsg, -1);
	CHECK_RETURN(m_pLogFile != NULL, false);

	Logger::setCurrentLogger(m_pLogFile);

	std::cout << strWelcomeMsg << std::endl;

	return true;
}

void CGameServer::Shutdown()
{
	juce::String strText;
	strText << "Game Server is shutting down..." << newLine;
	LogBoth(strText);

	for (int i = 0; i < m_vecKernels.size(); ++i)
	{
		IKernel* pKernel = m_vecKernels.at(i);
		if (pKernel == NULL)
		{
			continue;
		}

		strText.clear();
		strText << "Attempt to stop thread " << pKernel->getThreadName() << "..." << newLine;
		LogBoth(strText);

		pKernel->stopThread(-1);

		strText.clear();
		strText << "Thread " << pKernel->getThreadName() << " exited successfully..." << newLine;
		LogBoth(strText);
	}

	strText.clear();
	strText << "All thread exited, Server closed, Goodbye..." << newLine;
	LogBoth(strText);
}

void CGameServer::Run()
{
	if (!this->IsRunning())
	{
		return;
	}

	m_pPipe->Startup();
	while (this->IsRunning())
	{
		this->GetCmd();
		this->ProcCmd();
		std::cout << CMD_PROMT;
	}
}

void CGameServer::GetCmd()
{
	m_strCmdText.clear();
	std::getline(std::cin, m_strCmdText);
}

bool CGameServer::SendPipeMessage(THREAD_INDEX idxThread, CMsgNetwork* pMsgNetwork)
{
	if (idxThread < 0 || idxThread >= THREAD_INDEX_MAX)
	{
		return false;
	}

	if (pMsgNetwork == 0)
	{
		return false;
	}

	if (m_pPipe == NULL)
	{
		return false;
	}

	zmq_msg_t stMsg;
	int nSize = pMsgNetwork->ByteSize();
	zmq_msg_init_size(&stMsg, nSize);
	bool bSucc = pMsgNetwork->SerializeToArray(zmq_msg_data(&stMsg), nSize);
	if (!bSucc)
	{
		return false;
	}

	m_pPipe->SendPipeMessage(g_stThreadInfos[idxThread].c_str(), &stMsg);
	zmq_msg_close(&stMsg);

	return true;
}

bool CGameServer::RecvPipeMessage()
{
	if (m_pPipe == NULL)
	{
		return false;
	}

	zmq_msg_t* pMsg = m_pPipe->GetPipeMessage();
	if (pMsg == NULL)
	{
		return false;
	}

	CMsgNetwork msgNetwork;
	bool bSucc = msgNetwork.ParseFromArray(zmq_msg_data(pMsg), zmq_msg_size(pMsg));
	if (bSucc)
	{
		IMsgHandler::ProcessMessage(&msgNetwork);
	}

	m_pPipe->ReleasePipeMessage();

	return bSucc;
}

void CGameServer::ProcCmd()
{
	juce::String strCmdText = m_strCmdText;
	if (strCmdText.startsWithIgnoreCase("Shutdown"))
	{
		juce::String strText = "Shutdown command accepted, game server will stop in a few socends...";
		LogBoth(strText);
		this->StopServer();
	}
	else if (strCmdText.startsWithIgnoreCase("TestType"))
	{
		CObjectType eType1(OBJ_USER);
		CObjectType eType2(OBJ_USER, OBJ_MONSTER, OBJ_NPC, OBJ_NONE);
		CObjectType eType3(eType2);
		printf("etype1:%d, etype2:%d, 1isUser:%d, 1ismonster:%d, 1isNpc:%d, 2isUser:%d, 2ismonster:%d, 2isNpc:%d, 2is1:%d, 2isContain1:%d, 2isContainMonster:%d, 3is2:%d",
			eType1.GetType(), eType2.GetType(), eType1== OBJ_USER, eType1.IsType(OBJ_MONSTER), eType1.IsType(OBJ_NPC),
			eType2.IsType(OBJ_USER), eType2.IsType(OBJ_MONSTER), eType2 == OBJ_NPC, eType2 == eType1, eType2.IsContain(eType1.GetType()), eType2.IsContain(OBJ_MONSTER), eType3 == eType2);
	}
	else
	{
		CMsgNetwork msg;
		CMsgInproc* pMsgInproc = msg.mutable_msginproc();
		CHECK(pMsgInproc);
		pMsgInproc->set_naction(INPROCACT_GAME_TEST_CMD);
		pMsgInproc->add_strdata(strCmdText.toUTF8());
		this->SendPipeMessage(THREAD_INDEX_GAME, &msg);
	}
}

bool CGameServer::GetGameDbConfig(DbConfig_t& rDbConfig)
{
	INIReader objIni(CONFIG_FILE_NAME);
	rDbConfig.strServer = objIni.Get(DATABASE_SECTRION, DATABASE_IP, "");
	rDbConfig.strUser = objIni.Get(DATABASE_SECTRION, DATABASE_USER, "");
	rDbConfig.strPassword = objIni.Get(DATABASE_SECTRION, DATABASE_PASSWORD, "");
	rDbConfig.strDatabase = objIni.Get(DATABASE_SECTRION, DATABASE_DATABASE, "");

	if (rDbConfig.strServer.empty() || rDbConfig.strUser.empty() || rDbConfig.strPassword.empty() || rDbConfig.strDatabase.empty())
	{
		return false;
	}

	return true;
}

void CGameServer::CreateLogDirectories()
{
	File::getCurrentWorkingDirectory().getChildFile(GAME_SERVER_SYSLOG_DIR).createDirectory();
	File::getCurrentWorkingDirectory().getChildFile(GAME_SERVER_GMLOG_DIR).createDirectory();
}
