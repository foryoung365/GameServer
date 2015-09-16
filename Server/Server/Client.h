////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:	2015/07/03
// Describe:øÕªß∂À¿‡
////////////////////////////////////////////////////////////////////////
#ifndef _CLIENT_H_
#define _CLIENT_H_

#include "BaseDefine.h"
#include "RakNetTypes.h"
#include "KernelDef.h"
#include "MsgNetwork.pb.h"

class CClient
{
private:
	CClient();
	~CClient();
public:
	OBJID64 GetID() { return m_idClient; }
	static CClient* CreateNew() { return new CClient; }
	void Release() { delete this; }
	bool Create(RakNet::Packet* pPacket);
	const char* GetIP();
	const RakNet::SystemAddress& GetSystemAddr();
	THREAD_INDEX GetIdxThreadSendTo() const { return m_idxThreadSendTo; }
	void SetIdxThreadSendTo(THREAD_INDEX idx) { m_idxThreadSendTo = idx; }
	void SendPipeMsg(CMsgNetwork* pMsgNetwork);
private:
	OBJID64 m_idClient;
	RakNet::SystemAddress m_objAddr;
	THREAD_INDEX m_idxThreadSendTo;
	
};

#endif	//end of define _CLIENT_H_