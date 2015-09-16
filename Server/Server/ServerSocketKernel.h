////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:	2015/06/29
// Describe:服务端SOCKET线程
////////////////////////////////////////////////////////////////////////
#ifndef _SERVERSOCKETKERNEL_H_
#define _SERVERSOCKETKERNEL_H_

#include "BaseDefine.h"
#include "Kernel.h"
#include "RakPeerInterface.h"
#include "RakNetTypes.h"
#include "MessageIdentifiers.h"
#include "Client.h"

using namespace RakNet;

class CServerSocketKernel : public IKernel
{
private:
	CServerSocketKernel();
	virtual ~CServerSocketKernel();
public:
	juce_DeclareSingleton_SingleThreaded(CServerSocketKernel, true);
	virtual bool Create();
	virtual void Release();
	virtual bool RecvClientMessage();
	virtual bool RecvPipeMessage();
protected:
	virtual void OnRun();
	virtual void OnTimer();
	virtual void OnTimeTrigger(const TimeTrigger_t& pTrigger);
public:
	CClient* QueryClient(OBJID64 idClient);
	bool AddClient(RakNet::Packet* pPacket);
	void RemoveClient(OBJID64 idClient);
	void CloseConnection(OBJID64 idClient);
	void NotifyClientDisconnected(OBJID64 idClient);
private:
	RakPeerInterface* m_pIntfPeer;
	typedef std::map<OBJID64, CClient*> CLIENT_MAP;
	CLIENT_MAP m_mapClient;
	char* m_bufMsg;
};

#endif	//end of define _SERVERSOCKETKERNEL_H_