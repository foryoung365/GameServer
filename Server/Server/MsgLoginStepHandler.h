////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:2015/07/21
// Describe:登录步骤消息处理类
////////////////////////////////////////////////////////////////////////
#ifndef _MSGLOGINSTEPHANDLER_H_
#define _MSGLOGINSTEPHANDLER_H_

#include "MsgHandler.h"

class CMsgLoginStepHandler : public IMsgHandler
{
public:
	CMsgLoginStepHandler();
	virtual void Process(CMsgNetwork* pMsgNetwork);
private:
	static CMsgLoginStepHandler s_Handler;
};

#endif	//end of define _MSGLOGINSTEPHANDLER_H_

