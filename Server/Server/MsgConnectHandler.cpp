////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:	2015/07/03
// Describe:
////////////////////////////////////////////////////////////////////////
#include "MsgConnectHandler.h"
#include "BaseDefine.h"
#include "LoginKernel.h"
#include "DbTableDef.h"
#include "StrDef.h"
#include "MsgNetwork.pb.h"

CMsgConnectHandler CMsgConnectHandler::s_Handler;

CMsgConnectHandler::CMsgConnectHandler() : IMsgHandler(CMsgNetwork::kMsgConnect)
{

}

void CMsgConnectHandler::Process(CMsgNetwork* pMsgNetwork)
{
DEBUG_TRY
	CHECK(pMsgNetwork && pMsgNetwork->has_msgconnect());

	const CMsgConnect& rMsgConnect = pMsgNetwork->msgconnect();

	OBJID64 idAccount = rMsgConnect.idaccount();
	CHECK(idAccount);

	//开服时间检查，人数在ServerSocketKernel通过连接数控制，这里不再检查了
	time_t tCurrTime = CTimeFormatter::TimeGet(TIME_YYMMDDHHMM);
	time_t tOpenTime = CLoginKernel::getInstance()->GetOpenTime();
	if (tCurrTime < tOpenTime)
	{
		juce::String strReason = CTimeFormatter::TimeGetString(CTimeFormatter::MakeTime(TIME_YYMMDDHHMM, tOpenTime), STRDEF_SERVER_NOT_OPEN);
		CLoginKernel::getInstance()->SendErrorMsg(pMsgNetwork->idpeer(0), ERRACT_LOGIN_FAILED, strReason.toStdString().c_str());
		return;
	}

	//TO-DO:测试代码，账服还未接，都允许登录
	{
		ClientInfo_t* pInfo = new ClientInfo_t;
		pInfo->idAccount = idAccount;
		pInfo->idPeer = pMsgNetwork->idpeer(0);
		pInfo->bVerified = true;
		CLoginKernel::getInstance()->DeleteClientInfo(idAccount);
		CLoginKernel::getInstance()->AddClientInfo(pInfo);
		CLoginKernel::getInstance()->SendRoleInfo(pInfo);
		return;
	}

	//正式流程，查找账服是否已经发来验证信息
	ClientInfo_t* pInfo = CLoginKernel::getInstance()->QueryClientInfo(idAccount);
	if (pInfo = NULL)
	{
		pInfo = new ClientInfo_t;
		pInfo->idAccount = idAccount;
		pInfo->idPeer = pMsgNetwork->idpeer(0);
		CLoginKernel::getInstance()->AddClientInfo(pInfo);
		return;
	}
	else
	{
		IF_NOT(pInfo->strSessionId == rMsgConnect.szsessionid())
		{
			CLoginKernel::getInstance()->DeleteClientInfo(idAccount);
			CLoginKernel::getInstance()->SendErrorMsg(pMsgNetwork->idpeer(0), ERRACT_LOGIN_FAILED, STRDEF_SESSION_ID_INVALID);

			CLoginKernel::getInstance()->DeleteClientInfo(idAccount);
		}
		pInfo->bVerified = true;
	}

	CLoginKernel::getInstance()->SendRoleInfo(pInfo);
DEBUG_CATCH
}


