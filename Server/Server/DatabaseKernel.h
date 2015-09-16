////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:	2015/06/30
// Describe:数据库线程
////////////////////////////////////////////////////////////////////////
#ifndef _DATABASEKERNEL_H_
#define _DATABASEKERNEL_H_

#include <vector>
#include <list>
#include "Kernel.h"
#include "DbJob.h"
#include "GameObject.h"
#include "juce_core/juce_core.h"
#include "BasicTypeDef.h"

class CDatabaseKernel : public IKernel
{
private:
	CDatabaseKernel();
	~CDatabaseKernel();
public:
	juce_DeclareSingleton_SingleThreaded(CDatabaseKernel, true);
	virtual bool Create();
	virtual void Release();
	void AddLoadUserParm(const UserParm_t& rParm);
protected:
	virtual void OnRun();
	virtual void OnTimer();
	virtual void OnTimeTrigger(const TimeTrigger_t& pTrigger);
private:
	std::vector<CDbJob*> m_vecJobs;
	std::list<UserParm_t> m_lstLoginUserParms;
	juce::ThreadPool m_objThreadPool;
};

#endif	//end of define _DATABASEKERNEL_H_