////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:	2015/06/30
// Describe:
////////////////////////////////////////////////////////////////////////
#include "AccountSocketKernel.h"

juce_ImplementSingleton_SingleThreaded(CAccountSocketKernel);

CAccountSocketKernel::CAccountSocketKernel() : IKernel(THREAD_INDEX_AS_SOCKET)
{

}

CAccountSocketKernel::~CAccountSocketKernel()
{
	CAccountSocketKernel::clearSingletonInstance();
}

bool CAccountSocketKernel::Create()
{
	bool bSucc = IKernel::Create();
	CHECK_RETURN(bSucc, false);

	return true;
}

void CAccountSocketKernel::OnRun()
{
DEBUG_TRY
	sleep(100);
DEBUG_CATCH
}

void CAccountSocketKernel::OnTimer()
{

}

void CAccountSocketKernel::OnTimeTrigger(const TimeTrigger_t& pTrigger)
{

}

void CAccountSocketKernel::Release()
{
	CAccountSocketKernel::deleteInstance();
}
