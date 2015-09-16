////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:	2015/06/29
// Describe:
////////////////////////////////////////////////////////////////////////
#include "MsgHandler.h"
#include "BaseDefine.h"

IMsgHandler::IMsgHandler(CMsgNetwork::RealMessageCase eType)
{
	m_eType = eType;
	IMsgHandler::RegisterHandler(this);
}

IMsgHandler::~IMsgHandler()
{

}

void IMsgHandler::RegisterHandler(IMsgHandler* pHandler)
{
	if (pHandler == NULL)
	{
		return;
	}
	MSG_HANDLER_MAP& rMapHandlers = IMsgHandler::GetHandlerMap();
	rMapHandlers[pHandler->GetType()] = pHandler;
}

void IMsgHandler::ProcessMessage(CMsgNetwork* pMsgNetwork)
{
	CHECK(pMsgNetwork);
	CHECK(pMsgNetwork->RealMessage_case() != CMsgNetwork::REALMESSAGE_NOT_SET);
	
	DEBUG_TRY
		MSG_HANDLER_MAP& rMapHandlers = IMsgHandler::GetHandlerMap();

		MSG_HANDLER_MAP::iterator it = rMapHandlers.find(pMsgNetwork->RealMessage_case());
		if (it == rMapHandlers.end())
		{
			return;
		}

		IMsgHandler* pMsgHandler = it->second;
		if (pMsgHandler == NULL)
		{
			return;
		}

		pMsgHandler->Process(pMsgNetwork);
	DEBUG_CATCH
}

CMsgNetwork::RealMessageCase IMsgHandler::GetType()
{
	return m_eType;
}

IMsgHandler::MSG_HANDLER_MAP& IMsgHandler::GetHandlerMap()
{
	static MSG_HANDLER_MAP s_mapHandlers;

	return s_mapHandlers;
}
