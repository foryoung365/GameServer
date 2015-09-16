////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:	2015/06/26
// Describe:
////////////////////////////////////////////////////////////////////////
#include "MessagePipe.h"
#include "BaseDefine.h"

#define ZMQ_INPROC_PROTOCOL_NAME	"inproc://"

juce_ImplementSingleton_SingleThreaded(CMessagePipeContext);

CMessagePipeContext::CMessagePipeContext()
{
	m_pContext = zmq_ctx_new();
}


CMessagePipeContext::~CMessagePipeContext()
{
	zmq_ctx_destroy(m_pContext);
	clearSingletonInstance();
}

CMessagePipe::CMessagePipe()
{
	m_nPollIndex = 0;
	m_arrPollItems = NULL;
	m_nSocketNum = 0;
}

CMessagePipe::~CMessagePipe()
{
	this->Shutdown();
}

bool CMessagePipe::Create(MessagePipeInfo_t* pInfo)
{
	if (pInfo == NULL)
	{
		return false;
	}

	if (pInfo->strMyThreadName.empty() || pInfo->vecOtherThreadNames.empty())
	{
		return false;
	}

	if (m_nSocketNum != 0)
	{
		return false;
	}

	void* pContext = CMessagePipeContext::getInstance()->GetContext();
	if (pContext == NULL)
	{
		return false;
	}

	m_strName = pInfo->strMyThreadName;
	
	m_nSocketNum = (int)(pInfo->vecOtherThreadNames.size());
	m_arrPollItems = new zmq_pollitem_t[m_nSocketNum];
	if (m_arrPollItems == NULL)
	{
		return false;
	}
	memset(m_arrPollItems, 0, m_nSocketNum * sizeof(zmq_pollitem_t));

	int nItemCount = 0;
	//只要有一个管道失败，则所有都失败
	for (int i = 0; i < pInfo->vecOtherThreadNames.size(); ++i)
	{
		std::string strBindSocketName = ZMQ_INPROC_PROTOCOL_NAME + pInfo->strMyThreadName + pInfo->vecOtherThreadNames.at(i);
		void* pBindSocket = zmq_socket(pContext, ZMQ_PAIR);
		if (pBindSocket == NULL)
		{
			return false;
		}

		zmq_bind(pBindSocket, strBindSocketName.c_str());

		zmq_pollitem_t& rBindPollItem = m_arrPollItems[nItemCount++];
		rBindPollItem.socket = pBindSocket;
		rBindPollItem.fd = 0;
		rBindPollItem.events = ZMQ_POLLIN;
		rBindPollItem.revents = 0;
		
		void* pConnectSocket = zmq_socket(pContext, ZMQ_PAIR);
		if (pConnectSocket == NULL)
		{
			return false;
		}

		m_mapSockets.insert(std::make_pair(pInfo->vecOtherThreadNames.at(i), pConnectSocket));
	}

	return true;
}

void CMessagePipe::Shutdown()
{
	for (int i = 0; i < m_nSocketNum; ++i)
	{
		zmq_pollitem_t& rPollItem = m_arrPollItems[i];
		if (rPollItem.socket == NULL)
		{
			continue;
		}

		zmq_close(rPollItem.socket);
	}

	for (SOCKET_MAP::iterator it = m_mapSockets.begin(); it != m_mapSockets.end(); ++it)
	{
		zmq_close(it->second);
	}

	SAFE_DELETE_ARRAY(m_arrPollItems);
	m_nSocketNum = 0;
	m_nPollIndex = 0;
	m_strName.clear();
}

zmq_msg_t* CMessagePipe::GetPipeMessage()
{
	bool bPolled = false;
	if (m_nPollIndex == 0)
	{
		if (zmq_poll(m_arrPollItems, m_nSocketNum, ZMQ_DONTWAIT) <= 0)
		{
			return NULL;
		}
		bPolled = true;
	}

	for (m_nPollIndex; m_nPollIndex < m_nSocketNum; ++m_nPollIndex)
	{
		zmq_pollitem_t& rPollItem = m_arrPollItems[m_nPollIndex];
		if (rPollItem.revents & ZMQ_POLLIN)
		{
			zmq_msg_init(&m_stMessage);
			int nSize = zmq_msg_recv(&m_stMessage, rPollItem.socket, ZMQ_DONTWAIT);
			if (nSize <= 0)
			{
				this->ReleasePipeMessage();
				++m_nPollIndex;
				return NULL;
			}
			++m_nPollIndex;
			return &m_stMessage;
		}
	}

	if ((m_nPollIndex >= m_nSocketNum) && !bPolled)
	{
		m_nPollIndex = 0;
		return this->GetPipeMessage();
	}

	return NULL;
}

void CMessagePipe::ReleasePipeMessage()
{
	zmq_msg_close(&m_stMessage);
}

bool CMessagePipe::SendPipeMessage(const char* szThreadName, zmq_msg_t* pMsg)
{
	if (szThreadName == NULL || pMsg == NULL)
	{
		return false;
	}

	void* pSocket = this->QuerySocket(szThreadName);
	if (pSocket == NULL)
	{
		return false;
	}

	zmq_msg_send(pMsg, pSocket, ZMQ_DONTWAIT);

	return true;
}

void* CMessagePipe::QuerySocket(const char* szThreadName)
{
	MAP_FIND_IMPL(m_mapSockets, szThreadName, SOCKET_MAP::iterator);
}

bool CMessagePipe::Startup()
{
	for (SOCKET_MAP::iterator it = m_mapSockets.begin(); it != m_mapSockets.end(); ++it)
	{
		void* pSocket = it->second;
		if (pSocket == NULL)
		{
			continue;
		}

		std::string strConnectSocketName = ZMQ_INPROC_PROTOCOL_NAME + it->first + m_strName;
		if (zmq_connect(pSocket, strConnectSocketName.c_str()) != 0)
		{
			return false;
		}
	}
	
	return true;
}
