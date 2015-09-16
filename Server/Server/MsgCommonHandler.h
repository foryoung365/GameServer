////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:2015/08/18
// Describe:通用消息，如果适用的情况尽量走本消息
////////////////////////////////////////////////////////////////////////
#ifndef _MSGCOMMONHANDLER_H_
#define _MSGCOMMONHANDLER_H_

#include "MsgHandler.h"

class CMsgCommonHandler : public IMsgHandler
{
public:
	CMsgCommonHandler();
	virtual void Process(CMsgNetwork* pMsgNetwork);
private:
	static CMsgCommonHandler s_Handler;
};

#endif	//end of define _MSGCOMMONHANDLER_H_