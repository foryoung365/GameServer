////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:	2015/06/29
// Describe:MsgWalk¥¶¿Ì¿‡
////////////////////////////////////////////////////////////////////////
#ifndef _MSGWALKHANDLER_H_
#define _MSGWALKHANDLER_H_

#include "MsgHandler.h"

class CMsgMoveHanlder : public IMsgHandler
{
public:
	CMsgMoveHanlder();
	virtual void Process(CMsgNetwork* pMsgNetwork);
private:
	static CMsgMoveHanlder s_Handler;
};

#endif	//end of define _MSGWALKHANDLER_H_