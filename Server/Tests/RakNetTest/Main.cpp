////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:	2015/05/05
// Describe:²âÊÔ
////////////////////////////////////////////////////////////////////////
//#include "vld.h"
#include "juce_core/juce_core.h"
#include "BaseDefine.h"
#include "MessageIdentifiers.h"
#include "RakPeerInterface.h"
#include "RakNetTypes.h"

using namespace RakNet;

int main(void)
{

	juce::Time tCurr = juce::Time::getCurrentTime();
	printf("%s\n", tCurr.toString(true, true, true, true));

	juce::IPAddress objIPAddr("192.168.1.1");
	printf("%s %u\n", objIPAddr.toString(), ntohl(*((unsigned int*)(objIPAddr.address))));

	RakNet::RakPeerInterface* pIntfPeer = RakNet::RakPeerInterface::GetInstance();
	pIntfPeer->Startup(1, &RakNet::SocketDescriptor(), 1);
	pIntfPeer->Connect("127.0.0.1", 5816, 0, 0);

	char szMsg[1024];
	while (1)
	{
		scanf("%s", szMsg);
		pIntfPeer->Send(szMsg, strlen(szMsg) + 1, HIGH_PRIORITY, RELIABLE_ORDERED, 0, UNASSIGNED_RAKNET_GUID, true);
		for (Packet* pPacket = pIntfPeer->Receive(); pPacket; pIntfPeer->DeallocatePacket(pPacket), pPacket = pIntfPeer->Receive())
		{
			printf("Client Received Packet[size:%u] from [%s][%s]:%s\n", pPacket->length, pPacket->systemAddress.ToString(), pPacket->guid.ToString(), pPacket->data);
		}
	}

	getchar();

	return 0;
}