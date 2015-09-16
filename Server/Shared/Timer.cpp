////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:	2015/06/11
// Describe:
////////////////////////////////////////////////////////////////////////
#include "Timer.h"

ITimer::ITimer()
{
	this->ResetTimer();
}

ITimer::ITimer(time_t tInterval, bool bPeriodic)
{
	this->ResetTimer();
	m_bPeriodic = bPeriodic;
	m_tInterval = tInterval;
}

bool ITimer::IsValid()
{
	return (m_tEndTime != 0);
}

bool ITimer::StartTimer()
{
	if (m_tInterval <= 0)
	{
		return false;
	}

	m_tEndTime = this->GetCurrTime() + m_tInterval;

	return true;
}

bool ITimer::StartTimer(time_t tInterval, bool bPeriodic)
{
	m_tInterval = tInterval;
	m_bPeriodic = bPeriodic;

	return this->StartTimer();
}

void ITimer::StopTimer()
{
	m_tEndTime = 0;
}

bool ITimer::IsTimeEnd(bool bCompensation/* = TIMER_COMPENSATION_FALSE */)
{
	if (!this->IsValid())
	{
		return false;
	}

	time_t tCurr = this->GetCurrTime();
	bool bEnd = (tCurr >= m_tEndTime);
	if (bEnd)
	{
		if (this->IsPeriodic())
		{
			m_tEndTime += m_tInterval;
			//如果不补偿触发定时器，则直接跳到当前时间点
			if (m_tEndTime < tCurr && !bCompensation)
			{
				m_tEndTime = tCurr + m_tInterval;
			}
		}
		else
		{
			this->StopTimer();
		}
	}

	return bEnd;
}

bool ITimer::ResetTimer()
{
	m_bPeriodic = false;
	m_tEndTime = 0;
	m_tInterval = 0;

	return true;
}

bool ITimer::IsPeriodic()
{
	return m_bPeriodic;
}

time_t ITimer::GetRemainTime()
{
	if (!this->IsValid())
	{
		return 0;
	}

	time_t tCurr = this->GetCurrTime();
	if (tCurr >= m_tEndTime)
	{
		return 0;
	}

	return (m_tEndTime - tCurr);
}

time_t ITimer::GetInterval()
{
	return m_tInterval;
}

time_t ITimer::GetEndTime()
{
	return m_tEndTime;
}

//========================================================================

time_t CTimer::GetCurrTime()
{
	return time(NULL);
}

time_t CTimer::GetPrecision()
{
	return TIMER_PRECISION_SECOND;
}

CTimer::CTimer() 
	: ITimer()
{

}

CTimer::CTimer(time_t tInterval, bool bPeriodic)
	: ITimer(tInterval, bPeriodic)
{

}

//========================================================================
time_t CTimerMS::GetCurrTime()
{
	return clock();
}

time_t CTimerMS::GetPrecision()
{
	return TIMER_PRECISION_MS;
}

CTimerMS::CTimerMS()
	: ITimer()
{

}

CTimerMS::CTimerMS(time_t tInterval, bool bPeriodic)
	: ITimer(tInterval, bPeriodic)
{

}
