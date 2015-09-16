////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:2015/07/09
// Describe:
////////////////////////////////////////////////////////////////////////
#ifndef _MSGINPROCHANDLER_H_
#define _MSGINPROCHANDLER_H_

#include "MsgHandler.h"

class CMsgInprocHandler : public IMsgHandler
{
public:
	CMsgInprocHandler();
	virtual ~CMsgInprocHandler();
	virtual void Process(CMsgNetwork* pMsgNetwork);
private:
	static CMsgInprocHandler s_Handler;
};

#endif	//end of define _MSGINPROCHANDLER_H_

