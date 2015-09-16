////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:2015/07/16
// Describe:MsgError´¦ÀíÆ÷
////////////////////////////////////////////////////////////////////////
#ifndef _MSGERRORHANDLER_H_
#define _MSGERRORHANDLER_H_

#include "MsgHandler.h"

class CMsgErrorHandler :	public IMsgHandler
{
public:
	CMsgErrorHandler();
	virtual void Process(CMsgNetwork* pMsgNetwork);
private:
	static CMsgErrorHandler s_Handler;
};


#endif	//end of define _MSGERRORHANDLER_H_
