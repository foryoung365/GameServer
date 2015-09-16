// ==================================================================
// Copyright 2014-2015 foryoung365@gmail.com, All rights Reserved. 
// Describe:
// ==================================================================
#include "Kernel.h"
#include "zmq.h"
#include "MsgNetwork.pb.h"
#include "MsgHandler.h"
#include "BaseDefine.h"
#include "TimeFormatter.h"

#define KERNEL_ON_TIMER_PERIOD			500 //500ms
#define KERNEL_ON_TIME_TRIGGER_PERIOD	1	//1so

const std::string g_stThreadInfos[THREAD_INDEX_MAX] = {
	"MainThread",
 	"ServerSocketThread",
	"AccountSocketThread",
	"LoginThread",
	"DbThread",
 	"GameThread",
};

bool IKernel::SendPipeMessage(THREAD_INDEX idxThread, CMsgNetwork* pMsgNetwork)
{
	
	if (idxThread < 0 || idxThread >= THREAD_INDEX_MAX)
	{
		return false;
	}

	if (pMsgNetwork == NULL)
	{
		return false;
	}

	if (m_pPipe == NULL)
	{
		return false;
	}

	try
	{
		zmq_msg_t stMsg;
		int nSize = pMsgNetwork->ByteSize();
		zmq_msg_init_size(&stMsg, nSize);
		bool bSucc = pMsgNetwork->SerializeToArray(zmq_msg_data(&stMsg), nSize);
		CHECK_RETURN_TRACE2(bSucc, pMsgNetwork->RealMessage_case(), false);

		m_pPipe->SendPipeMessage(g_stThreadInfos[idxThread].c_str(), &stMsg);
		zmq_msg_close(&stMsg);

		return true;
	}
	catch (...)
	{
		TRACE_STACK();
		juce::String strErr;
		strErr << "SendPipeMessage Failed! Type[" << pMsgNetwork->RealMessage_case() << "] Size:[" << pMsgNetwork->ByteSize() << "].";
		LogErr(strErr);
	}

	return false;
}

bool IKernel::RecvPipeMessage()
{
	DEBUG_TRY
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
			IMsgHandler::ProcessMessage(&msgNetwork);
		}
	
		m_pPipe->ReleasePipeMessage();

		return true;
	DEBUG_CATCH

	return false;
}

IKernel::IKernel(THREAD_INDEX idxThread) : Thread(g_stThreadInfos[idxThread])
{
	m_pPipe = NULL;
	m_idxThread = idxThread;
	memset(&m_stTrigger, 0, sizeof(TimeTrigger_t));
}

IKernel::~IKernel()
{
	SAFE_RELEASE(m_pPipe);
}

void IKernel::OnTimeTrigger()
{
	DEBUG_TRY
		time_t tCurrTime = CTimeFormatter::TimeGet(TIME_SECOND);
		tm stTimeZone;
		localtime_s(&stTimeZone, &tCurrTime);

		TimeTrigger_t stTrigger;
		this->FillTimeTrigger(&stTrigger, &stTimeZone);

		if (memcmp(&stTrigger, &m_stTrigger, sizeof(TimeTrigger_t) == 0))
		{
			return;
		}

		memcpy(&m_stTrigger, &stTrigger, sizeof(TimeTrigger_t));

		this->OnTimeTrigger(m_stTrigger);
	DEBUG_CATCH
}

bool IKernel::Create()
{
	CHECK_RETURN(m_idxThread >= 0 && m_idxThread < THREAD_INDEX_MAX, false);

	MessagePipeInfo_t stPipeInfo;
	for (int i = 0; i < THREAD_INDEX_MAX; ++i)
	{
		if (i == m_idxThread)
		{
			stPipeInfo.strMyThreadName = g_stThreadInfos[i];
		}
		else
		{
			stPipeInfo.vecOtherThreadNames.push_back(g_stThreadInfos[i]);
		}
	}

	m_pPipe = CMessagePipe::CreateNew();
	if (m_pPipe == NULL || !m_pPipe->Create(&stPipeInfo))
	{
		SAFE_RELEASE(m_pPipe);
		return false;
	}

	return true;
}

void IKernel::run()
{
	CHECK_TRACE(m_pPipe->Startup());
	CHECK(m_tTimer.StartTimer(this->GetOnTimerInterval(), TIMER_PERIODIC_TRUE));
	CHECK(m_tTimeTrigger.StartTimer(this->GetOnTimeTriggerInterval(), TIMER_PERIODIC_TRUE));

	while (!this->threadShouldExit())
	{
		if (m_tTimer.IsValid() && m_tTimer.IsTimeEnd())
		{
			this->OnTimer();
		}

		if (m_tTimeTrigger.IsValid() && m_tTimeTrigger.IsTimeEnd())
		{
			this->OnTimeTrigger();
		}

		this->OnRun();
	}
}

time_t IKernel::GetOnTimerInterval()
{
	return KERNEL_ON_TIMER_PERIOD;
}

time_t IKernel::GetOnTimeTriggerInterval()
{
	return KERNEL_ON_TIME_TRIGGER_PERIOD;
}

void IKernel::FillTimeTrigger(TimeTrigger_t* pTrigger, tm* pTimeZone)
{
	if (pTimeZone == NULL || pTrigger == NULL)
	{
		return;
	}

	pTrigger->nYear = pTimeZone->tm_year + 1900;
	pTrigger->nMonth = pTimeZone->tm_mon + 1;
	pTrigger->nMday = pTimeZone->tm_mday;
	pTrigger->nWday = pTimeZone->tm_wday + 1;
	pTrigger->nHour = pTimeZone->tm_hour;
	pTrigger->nMinute = pTimeZone->tm_min;
}
