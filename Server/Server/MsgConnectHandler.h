////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:	2015/07/03
// Describe:MsgConnect¥¶¿Ì¿‡
////////////////////////////////////////////////////////////////////////
#ifndef _MSGCONNECTHANDLER_H_
#define _MSGCONNECTHANDLER_H_

#include "MsgHandler.h"

class CMsgConnectHandler : public IMsgHandler
{
public:
	CMsgConnectHandler();
	virtual void Process(CMsgNetwork* pMsgNetwork);
private:
	static CMsgConnectHandler s_Handler;
};

#endif	//end of define _MSGCONNECTHANDLER_H_