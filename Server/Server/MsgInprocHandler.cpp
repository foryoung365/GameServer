////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:2015/07/09
// Describe:
////////////////////////////////////////////////////////////////////////
#include "MsgInprocHandler.h"
#include "BaseDefine.h"
#include "DatabaseKernel.h"
#include "GameKernel.h"
#include "LoginKernel.h"
#include "ServerSocketKernel.h"
#include "AccountSocketKernel.h"
#include "MemRecordset.h"
#include "User.h"
#include "UserMgr.h"
#include "BasicTypeDef.h"

CMsgInprocHandler CMsgInprocHandler::s_Handler;

CMsgInprocHandler::CMsgInprocHandler() : IMsgHandler(CMsgNetwork::kMsgInproc)
{
}


CMsgInprocHandler::~CMsgInprocHandler()
{
}

void CMsgInprocHandler::Process(CMsgNetwork* pMsgNetwork)
{
	DEBUG_TRY
		CHECK(pMsgNetwork);

		const CMsgInproc& rMsgInproc = pMsgNetwork->msginproc();
		switch (rMsgInproc.naction())
		{
		//--------------------ServerSocketKernel------------------
		case INPROCACT_SS_BEGIN:
		break;
		case INPROCACT_SS_USER_LOGIN_TO_GAME:
		{
			CHECK(rMsgInproc.idrole());
			CHECK(rMsgInproc.u64data_size() > 0);
			OBJID64 idClient = rMsgInproc.u64data(0);
			CClient* pClient = CServerSocketKernel::getInstance()->QueryClient(idClient);
			CHECK(pClient);
			pClient->SetIdxThreadSendTo(THREAD_INDEX_GAME);
			CMsgNetwork msgLogin;
			CMsgInproc* pMsgInproc = msgLogin.mutable_msginproc();
			CHECK(pMsgInproc);
			OBJID64 idAccount = rMsgInproc.u64data(1);
			pMsgInproc->set_naction(INPROCACT_GAME_USER_REQUEST_LOGIN);
			pMsgInproc->set_idrole(rMsgInproc.idrole());
			pMsgInproc->add_u64data(idClient);
			pMsgInproc->add_u64data(idAccount);
			pMsgInproc->add_strdata(pClient->GetIP());
			CServerSocketKernel::getInstance()->SendPipeMessage(THREAD_INDEX_GAME, &msgLogin);
		}
		break;
		case INPROCACT_SS_CLOSE_CONNECTION:
		{
			CServerSocketKernel::getInstance()->CloseConnection(pMsgNetwork->idpeer(0));
		}
		break;
		case INPROCACT_SS_END:
		break;

		//--------------------LoginKernel------------------------
		case INPROCACT_LOGIN_BEGIN:
		break;
	

		case INPROCACT_LOGIN_END:
		break;


		//--------------------DbKernel-----------------------------
		case INRPOCACT_DB_BEGIN:
		break;
		case INPROCACT_DB_LOAD_USER:
		{
			CHECK(rMsgInproc.has_idrole());
			CDatabaseKernel* pDbKernel = CDatabaseKernel::getInstance();
			UserParm_t stParm;
			stParm.idUser = rMsgInproc.idrole();
			stParm.idAccount = rMsgInproc.u64data(0);
			stParm.idPeer = rMsgInproc.u64data(1);
			stParm.strIP = rMsgInproc.strdata(0);
			pDbKernel->AddLoadUserParm(stParm);
		}
		break;

		case INRPOCACT_DB_END:
		break;

		//-------------------GameKernel-----------------------------
		case INPROCACT_GAME_BEGIN:
		break;
		case INPROCACT_GAME_LOAD_USER_FINISHED:
		{
			CHECK(rMsgInproc.has_idrole());
			CHECK(rMsgInproc.u64data_size() > 0);
			OBJID64 idRecordsetMap = rMsgInproc.u64data(0);
			CMemRecordset::getInstance()->AddRecordsetMap(rMsgInproc.idrole(), idRecordsetMap);
			UserParm_t stParm;
			stParm.idUser = rMsgInproc.idrole();
			stParm.idAccount = rMsgInproc.u64data(1);
			stParm.idPeer = rMsgInproc.u64data(2);
			stParm.strIP = rMsgInproc.strdata(0);
			CUserMgr::getInstance()->CreateNewUser(stParm);
		}
		break;
		case INPROCACT_GAME_USER_REQUEST_LOGIN:
		{
			CHECK(rMsgInproc.idrole());
			CHECK(rMsgInproc.u64data_size() >= 2);
			UserParm_t stParm;
			stParm.idUser = rMsgInproc.idrole();
			stParm.idPeer = rMsgInproc.u64data(0);
			stParm.idAccount = rMsgInproc.u64data(1);
			stParm.strIP = rMsgInproc.strdata(0);
			CUserMgr::getInstance()->ReadyToLoginUser(stParm);
		}
		break;
		case INPROCACT_GAME_USER_DISCONNECTED:
		{
			OBJID64 idPeer = pMsgNetwork->idpeer(0);
			CUserMgr::getInstance()->KickoutUserByPeerId(idPeer);
		}
		break;
		case INPROCACT_GAME_TEST_CMD:
		{
			juce::String strCmd;
			strCmd = rMsgInproc.strdata(0);
			CGameKernel::getInstance()->DebugCommand(strCmd);
		}
		break;
		case INPROCACT_GAME_END:
		break;

		//-------------------AccoutSocketKernel----------------------
		case INPROCACT_AS_BEGIN:
		break;
		case INPROCACT_AS_END:
		break;

		default:
		{
			ASSERT_FALSE;
		}
		break;
		}
	DEBUG_CATCH
}
