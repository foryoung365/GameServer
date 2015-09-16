////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:2015/08/18
// Describe:
////////////////////////////////////////////////////////////////////////
#include "MsgCommonHandler.h"
#include "MsgNetwork.pb.h"
#include "User.h"
#include "UserMgr.h"


CMsgCommonHandler CMsgCommonHandler::s_Handler;


CMsgCommonHandler::CMsgCommonHandler() : IMsgHandler(CMsgNetwork::kMsgCommon)
{

}

void CMsgCommonHandler::Process(CMsgNetwork* pMsgNetwork)
{
	DEBUG_TRY
		CHECK(pMsgNetwork);
		CHECK(pMsgNetwork->has_msgcommon());

		const CMsgCommon& rMsgCommon = pMsgNetwork->msgcommon();
		CUser* pUser = CUserMgr::getInstance()->QueryOnlineUserByPeerId(pMsgNetwork->idpeer(0));
		CHECK(pUser);
	DEBUG_CATCH
}
