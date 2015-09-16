////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:	2015/07/03
// Describe:
////////////////////////////////////////////////////////////////////////
#include "Client.h"
#include "ServerSocketKernel.h"

CClient::CClient()
{
	m_idClient = ID_NONE;
	m_idxThreadSendTo = THREAD_INDEX_LOGIN;
}

CClient::~CClient()
{

}

bool CClient::Create(RakNet::Packet* pPacket)
{
	CHECK_RETURN(pPacket, false);

	m_idClient = pPacket->guid.g;
	m_objAddr = pPacket->systemAddress;

	return true;
}

const char* CClient::GetIP()
{
	return m_objAddr.ToString(false);
}

const RakNet::SystemAddress& CClient::GetSystemAddr()
{
	return m_objAddr;
}

void CClient::SendPipeMsg(CMsgNetwork* pMsgNetwork)
{
	CHECK(pMsgNetwork);

	pMsgNetwork->add_idpeer(this->GetID());

	CServerSocketKernel::getInstance()->SendPipeMessage(this->GetIdxThreadSendTo(), pMsgNetwork);
}

