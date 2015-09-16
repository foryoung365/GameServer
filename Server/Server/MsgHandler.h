////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:	2015/06/29
// Describe:消息处理器的接口类
////////////////////////////////////////////////////////////////////////
#ifndef _MSGHANDLER_H_
#define _MSGHANDLER_H_

#include <map>
#include "MsgNetwork.pb.h"

class IMsgHandler
{
public:
	typedef std::map<CMsgNetwork::RealMessageCase, IMsgHandler*> MSG_HANDLER_MAP;
	IMsgHandler(CMsgNetwork::RealMessageCase eType);
	virtual ~IMsgHandler();
	virtual void Process(CMsgNetwork* pMsgNetwork) = 0;
	CMsgNetwork::RealMessageCase GetType();
	static MSG_HANDLER_MAP& GetHandlerMap();
	static void RegisterHandler(IMsgHandler* pHandler);
	static void ProcessMessage(CMsgNetwork* pMsgNetwork);
private:
	CMsgNetwork::RealMessageCase m_eType;
};

#endif	//end of define _MSGHANDLER_H_