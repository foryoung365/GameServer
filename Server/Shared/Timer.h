////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:	2015/06/11
// Describe:定时器的实现
////////////////////////////////////////////////////////////////////////
#ifndef _TIMER_H_
#define _TIMER_H_

#include <time.h>

//定时器精度
enum TIMER_PRECISION
{
	TIMER_PRECISION_MS		= 1,		//1毫秒
	TIMER_PRECISION_SECOND	= 1000,		//1秒=1000毫秒
};

//时间发生跳跃时，定时器是否补偿触发(如时间往后调1个小时，是否要将这一个小时的时间补偿触发)
enum TIMER_COMPENSATION
{
	TIMER_COMPENSATION_FALSE	= 0,		//不补偿
	TIMER_COMPENSATION_TRUE	= 1,		//补偿
};

enum TIMER_PERIODIC
{
	TIMER_PERIODIC_FALSE	= 0,
	TIMER_PERIODIC_TRUE	= 1,
};

typedef struct TimeTrigger_s
{
	int nYear;				//年份，不用+1900
	int nMonth;				//月份 1-12
	int nMday;				//一个月中的天数 1-31
	int nWday;				//星期几 1-7
	int nHour;				//小时 0-23
	int nMinute;			//分钟 0-59
}TimeTrigger_t;

//定时器接口类
class ITimer
{
public:
	ITimer();
	ITimer(time_t tInterval, bool bPeriodic);
	virtual ~ITimer() {}
public:
	virtual bool IsValid();
	virtual bool StartTimer();
	virtual bool StartTimer(time_t tInterval, bool bPeriodic);
	virtual void StopTimer();
	virtual bool IsTimeEnd(bool bCompensation = TIMER_COMPENSATION_FALSE);
	virtual bool ResetTimer();
	virtual bool IsPeriodic();
	virtual time_t GetRemainTime();
	virtual time_t GetInterval();
	virtual time_t GetEndTime();
public:
	//获得定时器的精确度，单位毫秒
	virtual time_t GetPrecision() = 0;
protected:
	//获得当前计时器精度表示的当前时间
	virtual time_t GetCurrTime() = 0;
protected:
	bool m_bPeriodic;		//是否周期定时器
	time_t m_tEndTime;		//本次结束时间
	time_t m_tInterval;		//触发间隔
};

//秒级定时器
class CTimer : public ITimer
{
public:
	CTimer();
	CTimer(time_t tInterval, bool bPeriodic);
public:
	//获得定时器的精确度，单位毫秒
	virtual time_t GetPrecision();
protected:
	//获得当前计时器精度表示的当前时间
	virtual time_t GetCurrTime();
};

//毫秒级定时器
class CTimerMS : public ITimer
{
public:
	CTimerMS();
	CTimerMS(time_t tInterval, bool bPeriodic);
public:
	//获得定时器的精确度，单位毫秒
	virtual time_t GetPrecision();
protected:
	//获得当前计时器精度表示的当前时间
	virtual time_t GetCurrTime();
};


#endif	//end of define _TIMER_H_