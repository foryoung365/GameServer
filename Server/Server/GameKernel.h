////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:	2015/06/29
// Describe:
////////////////////////////////////////////////////////////////////////
#ifndef _GAMEKERNEL_H_
#define _GAMEKERNEL_H_

#include "Kernel.h"
#include "GameDatabase.h"

class CGameKernel : public IKernel
{
private:
	CGameKernel();
	virtual ~CGameKernel();
public:
	juce_DeclareSingleton_SingleThreaded(CGameKernel, true);
	virtual bool Create();
	virtual void Release();
public:
	static CGameDatabase* GetDatabase();
	void InsertReservedDbRecord();
	void DebugCommand(juce::String strCmd);
protected:
	virtual void OnRun();
	virtual void OnTimer();
	virtual void OnTimeTrigger(const TimeTrigger_t& pTrigger);
	CGameDatabase* GetDatabasePriv();
	void OnRelease();
private:
	CGameDatabase* m_pDatabase;
};

#endif	//end of define _GAMEKERNEL_H_