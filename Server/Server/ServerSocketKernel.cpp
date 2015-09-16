////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:	2015/06/29
// Describe:
////////////////////////////////////////////////////////////////////////
#include <vector>
#include "ServerSocketKernel.h"
#include "time.h"
#include "GameServerDef.h"
#include "INIReader.h"
#include "MsgHandler.h"

juce_ImplementSingleton_SingleThreaded(CServerSocketKernel);

CServerSocketKernel::CServerSocketKernel() : IKernel(THREAD_INDEX_SERVER_SOCKET)
{
	m_pIntfPeer = NULL;
	m_bufMsg = NULL;
}

CServerSocketKernel::~CServerSocketKernel()
{
	for (CLIENT_MAP::iterator it = m_mapClient.begin(); it != m_mapClient.end(); ++it)
	{
		SAFE_RELEASE(it->second);
	}

	if (m_pIntfPeer)
	{
		RakPeerInterface::DestroyInstance(m_pIntfPeer);
	}

	SAFE_DELETE(m_bufMsg);

	CServerSocketKernel::clearSingletonInstance();
}

void CServerSocketKernel::OnTimer()
{

}

void CServerSocketKernel::OnTimeTrigger(const TimeTrigger_t& pTrigger)
{

}

bool CServerSocketKernel::Create()
{
	bool bSucc = IKernel::Create();
	CHECK_RETURN(bSucc, false);

	m_bufMsg = new char[MSGBUF_SIZE];
	CHECK_RETURN(m_bufMsg, false);

	m_pIntfPeer = RakPeerInterface::GetInstance();
	CHECK_RETURN(m_pIntfPeer, false);

	INIReader objIni(CONFIG_FILE_NAME);
	int nMaxClient = objIni.GetInteger(GAME_SERVER_SOCKET_SECTION, GAME_SERVER_SOCKET_MAXCLIENT, 0);
	int nPort = objIni.GetInteger(GAME_SERVER_SOCKET_SECTION, GAME_SERVER_SOCKET_PORT, 0);

	CHECK_RETURN(nMaxClient > 0 && nPort > 0, false);

	m_pIntfPeer->Startup(nMaxClient, &RakNet::SocketDescriptor(nPort, NULL), 1);
	m_pIntfPeer->SetMaximumIncomingConnections(nMaxClient);

	return true;
}

bool CServerSocketKernel::RecvClientMessage()
{
	CHECK_RETURN(m_pIntfPeer, false);
	Packet* pPacket = m_pIntfPeer->Receive();
	if (pPacket)
	{
		if (pPacket->length > 0)
		{
			//使用protobuf解析收到的报文，如果能解析成功，说明是自定义的数据包，否则就是RakNet的预定义包
			CMsgNetwork msgNetwork;
			if (msgNetwork.ParseFromArray(pPacket->data, pPacket->length))
			{
				//标记消息是哪个客户端发来的
				OBJID64 idClient = pPacket->guid.g;
				CClient* pClient = this->QueryClient(idClient);
				if (pClient)
				{
					pClient->SendPipeMsg(&msgNetwork);
				}
				else
				{
					ASSERT2(0, idClient);
				}
			}
			else
			{
				uint8_t u8MsgId = pPacket->data[0];
				switch (u8MsgId)
				{
				case ID_NEW_INCOMING_CONNECTION:
				{
					this->AddClient(pPacket);
				}
				break;
				case ID_CONNECTION_LOST:
				{
					//TO-DO:通知其他线程，连接丢失
					this->NotifyClientDisconnected(pPacket->guid.g);
					this->CloseConnection(pPacket->guid.g);
				}
				break;
				default:
					break;
				}
			}
		}
		m_pIntfPeer->DeallocatePacket(pPacket);
	}

	return true;
}

void CServerSocketKernel::OnRun()
{
DEBUG_TRY
	//从网络收包
	this->RecvClientMessage();

	//从消息管道收包
	this->RecvPipeMessage();
DEBUG_CATCH
}

CClient* CServerSocketKernel::QueryClient(OBJID64 idClient)
{
	MAP_FIND_IMPL(m_mapClient, idClient, CLIENT_MAP::iterator);
}

void CServerSocketKernel::RemoveClient(OBJID64 idClient)
{
	CHECK(idClient);

	CClient* pClient = this->QueryClient(idClient);
	if (pClient == NULL)
	{
		return;
	}

	SAFE_RELEASE(pClient);
	m_mapClient.erase(idClient);
}

void CServerSocketKernel::Release()
{
	CServerSocketKernel::deleteInstance();
}

bool CServerSocketKernel::RecvPipeMessage()
{
	if (m_pPipe == NULL)
	{
		return false;
	}

	zmq_msg_t* pMsg = m_pPipe->GetPipeMessage();
	if (pMsg == NULL)
	{
		return false;
	}

	CMsgNetwork msgNetwork;
	bool bSucc = msgNetwork.ParseFromArray(zmq_msg_data(pMsg), zmq_msg_size(pMsg));
	if (bSucc)
	{
		//如果是内部通信消息，则继续处理，否则转发到客户端
		if (msgNetwork.has_msginproc())
		{
			IMsgHandler::ProcessMessage(&msgNetwork);
		}
		else
		{
			::google::protobuf::RepeatedField< ::google::protobuf::uint64 > idPeers(msgNetwork.idpeer());
			bool bBroadcast = msgNetwork.bbroadcast();
			//发送前，把客户端不需要的信息清除掉
			msgNetwork.clear_idpeer();
			msgNetwork.clear_bbroadcast();

			IF_NOT(msgNetwork.SerializeToArray(m_bufMsg, MSGBUF_SIZE))
			{
				return false;
			}

			if (bBroadcast)
			{
				m_pIntfPeer->Send(m_bufMsg, msgNetwork.ByteSize(), MEDIUM_PRIORITY, RELIABLE_ORDERED, 0, UNASSIGNED_SYSTEM_ADDRESS, true);
			}
			else
			{
				for (int i = 0; i < idPeers.size(); ++i)
				{
					CClient* pClient = this->QueryClient(idPeers.Get(i));
					if (pClient == NULL)
					{
						continue;
					}

					m_pIntfPeer->Send(m_bufMsg, msgNetwork.ByteSize(), MEDIUM_PRIORITY, RELIABLE_ORDERED, 0, pClient->GetSystemAddr(), false);
				}
			}
		}
	}

	m_pPipe->ReleasePipeMessage();

	return true;
}

bool CServerSocketKernel::AddClient(RakNet::Packet* pPacket)
{
	CHECK_RETURN(pPacket, false);
	CHECK_RETURN(this->QueryClient(pPacket->guid.g) == NULL, false);

	CClient* pClient = CClient::CreateNew();
	IF_NOT(pClient && pClient->Create(pPacket))
	{
		SAFE_RELEASE(pClient);

		return false;
	}

	m_mapClient.insert(std::make_pair(pClient->GetID(), pClient));

	return true;
}

void CServerSocketKernel::CloseConnection(OBJID64 idClient)
{
	CHECK(idClient);

	m_pIntfPeer->CloseConnection(RakNet::RakNetGUID(idClient), true);
	this->RemoveClient(idClient);
}

void CServerSocketKernel::NotifyClientDisconnected(OBJID64 idClient)
{
	CHECK(idClient);

	CClient* pClient = this->QueryClient(idClient);
	CHECK(pClient);

	//还未登录到GameKernel，就不用通知了
	if (pClient->GetIdxThreadSendTo() != THREAD_INDEX_GAME)
	{
		return;
	}

	CMsgNetwork msgNetwork;
	CMsgInproc* pMsgInproc = msgNetwork.mutable_msginproc();
	CHECK(pMsgInproc);
	pMsgInproc->set_naction(INPROCACT_GAME_USER_DISCONNECTED);

	pClient->SendPipeMsg(&msgNetwork);
}

