////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:	2015/06/15
// Describe:
////////////////////////////////////////////////////////////////////////
#include <algorithm>
#include "TimerMgr.h"
#include "BaseDefine.h"

static bool CompareTimerHandlerLess(ITimerHandler* pLhs, ITimerHandler* pRhs)
{
	if (pLhs == NULL && pRhs == NULL)
	{
		return false;
	}

	if (pLhs == NULL)
	{
		return true;
	}

	if (pRhs == NULL)
	{
		return false;
	}

	ITimer* pTimerLhs = pLhs->GetTimer();
	ITimer* pTimerRhs = pRhs->GetTimer();

	if (pTimerLhs == NULL && pTimerRhs == NULL)
	{
		return false;
	}

	if (pTimerLhs == NULL)
	{
		return true;
	}

	if (pTimerRhs == NULL)
	{
		return false;
	}

	return pTimerLhs->GetEndTime() < pTimerRhs->GetEndTime();
}

ITimerHandler::ITimerHandler(TIMER_PRECISION ePrecision, time_t tInterval, bool bPeriodic)
{
	if (ePrecision == TIMER_PRECISION_SECOND)
	{
		m_pTimer = new CTimer(tInterval, bPeriodic);
	}
	else
	{
		m_pTimer = new CTimerMS(tInterval, bPeriodic);
	}

	CTimerMgr::GetInstance()->RegisterTimer(this);
}

ITimerHandler::~ITimerHandler()
{
	CTimerMgr::GetInstance()->UnregisterTimer(this);

	SAFE_DELETE(m_pTimer);
}


//=========================================================================

CTimerMgr::CTimerMgr()
{
	this->InitTimeTrigger();
	
	m_tTimerMS.StartTimer(TIMER_LIST_MS_MIN_PERIOD, TIMER_PERIODIC_TRUE);
	m_tTimerSec.StartTimer(TIMER_LIST_SEC_MIN_PERIOD, TIMER_PERIODIC_TRUE);
	m_tTimerTigger.StartTimer(TIMER_LIST_TIGGER_MIN_PERIOD, TIMER_PERIODIC_TRUE);
}

CTimerMgr::~CTimerMgr()
{

}

CTimerMgr* CTimerMgr::GetInstance()
{
	static CTimerMgr sTimerMgr;

	return &sTimerMgr;
}

bool CTimerMgr::RegisterTimer(ITimerHandler* pNewTimerHandler)
{
	if (pNewTimerHandler == NULL)
	{
		return false;
	}

	ITimer* pNewTimer = pNewTimerHandler->GetTimer();
	if (pNewTimer == NULL)
	{
		return false;
	}

	TIMER_LIST* pTimerList = this->GetFitTimerList(pNewTimerHandler);
	if (pTimerList == NULL)
	{
		return false;
	}

	TIMER_LIST::iterator it = pTimerList->begin();
	for (; it != pTimerList->end(); ++it)
	{
		ITimerHandler* pTimerHandler = *it;
		if (pTimerHandler == NULL)
		{
			continue;
		}

		ITimer* pTimer = pTimerHandler->GetTimer();
		if (pTimer == NULL)
		{
			continue;
		}

		if (pNewTimer->GetEndTime() >= pTimer->GetEndTime())
		{
			break;
		}
	}

	pTimerList->insert(it, pNewTimerHandler);

	return true;
}

bool CTimerMgr::UnregisterTimer(ITimerHandler* pTimerHandler)
{
	if (pTimerHandler == NULL)
	{
		return false;
	}

	TIMER_LIST* pTimerList = this->GetFitTimerList(pTimerHandler);
	if (pTimerList == NULL)
	{
		return false;
	}
	TIMER_LIST::iterator it = pTimerList->begin();
	for (; it != pTimerList->end(); ++it)
	{
		ITimerHandler* pHandler = *it;
		if (pHandler == NULL)
		{
			continue;
		}

		if (pHandler == pTimerHandler)
		{
			break;
		}
	}

	pTimerList->erase(it);

	return true;
}

CTimerMgr::TIMER_LIST* CTimerMgr::GetFitTimerList(ITimerHandler* pTimerHandler)
{
	if (pTimerHandler == NULL)
	{
		return NULL;
	}

	ITimer* pTimer = pTimerHandler->GetTimer();
	if (pTimer == NULL)
	{
		return NULL;
	}

	if (pTimer->GetPrecision() == TIMER_PRECISION_SECOND)
	{
		return &m_lstTimerSec;
	}
	else if (pTimer->GetPrecision() == TIMER_PRECISION_MS)
	{
		return &m_lstTimerMS;
	}

	return NULL;
}

void CTimerMgr::OnTimer()
{
	if (m_tTimerMS.IsTimeEnd())
	{
		this->OnTimerPriv(m_lstTimerMS);
	}

	if (m_tTimerSec.IsTimeEnd())
	{
		this->OnTimerPriv(m_lstTimerSec);
	}

	if (m_tTimerTigger.IsTimeEnd())
	{
		this->OnTimeTrigger();
	}
}

void CTimerMgr::OnTimerPriv(TIMER_LIST& lstTimer)
{
	TIMER_VEC vecRemoved;
	for (TIMER_LIST::iterator it = lstTimer.begin(); it != lstTimer.end(); it = lstTimer.erase(it))
	{
		ITimerHandler* pTimerHandler = *it;
		if (pTimerHandler == NULL)
		{
			continue;
		}

		ITimer* pTimer = pTimerHandler->GetTimer();
		if (pTimer == NULL)
		{
			continue;
		}

		if (!pTimer->IsTimeEnd())
		{
			break;
		}

		pTimerHandler->OnTimer();
		if (!pTimer->IsPeriodic())
		{
			continue;
		}

		vecRemoved.push_back(pTimerHandler);
	}

	if (vecRemoved.empty())
	{
		return;
	}
	std::sort(vecRemoved.begin(), vecRemoved.end(), CompareTimerHandlerLess);

	//vecRemoved里面是有序的，lstTimer里面也是有序的，因此每次插入到lstTimer之后，只要从插入位置继续向后遍历查找即可
	//如果vecRemoved的某个元素，在lstTimer里找不到比它更大的元素，那么就将vecRemoved中剩余的所有元素插入lstTimer
	TIMER_LIST::iterator it = lstTimer.begin();
	for (TIMER_VEC::iterator iter = vecRemoved.begin(); iter != vecRemoved.end(); ++iter)
	{
		bool bInserted = false;

		ITimerHandler* pHandlerRemoved = *iter;
		if (pHandlerRemoved == NULL)
		{
			continue;
		}

		ITimer* pTimerRemoved = pHandlerRemoved->GetTimer();
		if (pTimerRemoved == NULL)
		{
			continue;
		}

		for (; it != lstTimer.end(); ++it)
		{
			ITimerHandler* pTimerHandler = *it;
			if (pTimerHandler == NULL)
			{
				continue;
			}

			ITimer* pTimer = pTimerHandler->GetTimer();
			if (pTimer == NULL)
			{
				continue;
			}

			if (pTimerRemoved->GetEndTime() < pTimer->GetEndTime())
			{
				it = lstTimer.insert(it, pHandlerRemoved);
				bInserted = true;
				break;
			}
		}

		if (!bInserted)
		{
			lstTimer.insert(lstTimer.end(), iter, vecRemoved.end());
			break;
		}
	}
}

void CTimerMgr::OnTimeTrigger()
{
	time_t tCurrTime = time(NULL);
	tm stTimeZone;
	localtime_s(&stTimeZone, &tCurrTime);

	TimeTrigger_t stTrigger;
	this->FillTimeTrigger(&stTrigger, &stTimeZone);

	if (memcmp(&stTrigger, &m_stTrigger, sizeof(TimeTrigger_t) == 0))
	{
		return;
	}

	memcpy(&m_stTrigger, &stTrigger, sizeof(TimeTrigger_t));
	for (TIMER_LIST::iterator it = m_lstTimerMS.begin(); it != m_lstTimerMS.end(); ++it)
	{
		ITimerHandler* pHandler = *it;
		if (pHandler == NULL)
		{
			continue;
		}

		pHandler->OnTimeTrigger(m_stTrigger);
	}

	for (TIMER_LIST::iterator it = m_lstTimerSec.begin(); it != m_lstTimerSec.end(); ++it)
	{
		ITimerHandler* pHandler = *it;
		if (pHandler == NULL)
		{
			continue;
		}

		pHandler->OnTimeTrigger(m_stTrigger);
	}
}

void CTimerMgr::InitTimeTrigger()
{
	memset(&m_stTrigger, 0, sizeof(TimeTrigger_t));
	time_t tCurrTime = time(NULL);
	tm stTimeZone;
	localtime_s(&stTimeZone, &tCurrTime);

	this->FillTimeTrigger(&m_stTrigger, &stTimeZone);
}

void CTimerMgr::FillTimeTrigger(TimeTrigger_t* pTrigger, tm* pTimeZone)
{
	if (pTimeZone == NULL)
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
