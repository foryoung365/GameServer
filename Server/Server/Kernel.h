////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:2015/07/27
// Describe:Ïß³ÌºËÐÄ²ã
////////////////////////////////////////////////////////////////////////
#ifndef _KERNEL_H_
#define _KERNEL_H_

#include "KernelDef.h"
#include "MsgNetwork.pb.h"
#include "MessagePipe.h"
#include "juce_core/juce_core.h"
#include "BaseDefine.h"
#include "Timer.h"

class IKernel : public juce::Thread
{
protected:
	IKernel(THREAD_INDEX idxThread);
	virtual ~IKernel();
public:
	virtual bool Create();
	virtual void Release() = 0;
	virtual bool SendPipeMessage(THREAD_INDEX idxThread, CMsgNetwork* pMsgNetwork);
	virtual bool RecvPipeMessage();	
	virtual void OnTimeTrigger();
	virtual void run();
	virtual time_t GetOnTimerInterval();
	virtual time_t GetOnTimeTriggerInterval();
protected:
	virtual void OnRun() = 0;
	virtual void OnTimer() = 0;
	virtual void OnTimeTrigger(const TimeTrigger_t& pTrigger) = 0;
	void FillTimeTrigger(TimeTrigger_t* pTrigger, tm* pTimeZone);
protected:
	CMessagePipe* m_pPipe;
	THREAD_INDEX m_idxThread;
	CTimerMS m_tTimer;
	CTimer m_tTimeTrigger;
	TimeTrigger_t m_stTrigger;
};

#endif //end of _KERNEL_H_