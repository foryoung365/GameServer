////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:2015/07/16
// Describe:
////////////////////////////////////////////////////////////////////////
#include "BaseDefine.h"
#include "MsgErrorHandler.h"
#include "MsgNetwork.pb.h"

CMsgErrorHandler CMsgErrorHandler::s_Handler;

CMsgErrorHandler::CMsgErrorHandler() : IMsgHandler(CMsgNetwork::kMsgError)
{
}

void CMsgErrorHandler::Process(CMsgNetwork* pMsgNetwork)
{
	DEBUG_TRY
		CHECK_TRACE2(0, pMsgNetwork->RealMessage_case());
	DEBUG_CATCH
}


