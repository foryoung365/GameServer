////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:	2015/06/30
// Describe:和账服链接的SOCKET线程
////////////////////////////////////////////////////////////////////////
#ifndef _ACCOUNTSOCKETKERNEL_H_
#define _ACCOUNTSOCKETKERNEL_H_

#include "Kernel.h"

class CAccountSocketKernel : public IKernel
{
private:
	CAccountSocketKernel();
	~CAccountSocketKernel();
public:
	juce_DeclareSingleton_SingleThreaded(CAccountSocketKernel, true);
	virtual bool Create();
	virtual void Release();
protected:
	virtual void OnRun();
	virtual void OnTimer();
	virtual void OnTimeTrigger(const TimeTrigger_t& pTrigger);
};

#endif	//end of define _ACCOUNTSOCKETKERNEL_H_