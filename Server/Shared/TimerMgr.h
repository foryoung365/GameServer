////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:	2015/06/15
// Describe:定时器管理器
////////////////////////////////////////////////////////////////////////
#ifndef _TIMERMGR_H_
#define _TIMERMGR_H_

#include <list>
#include <vector>
#include "Timer.h"

#define TIMER_LIST_MS_MIN_PERIOD		10	//10毫秒
#define TIMER_LIST_SEC_MIN_PERIOD		1	//1秒
#define TIMER_LIST_TIGGER_MIN_PERIOD	1	//1秒

//定时器句柄接口类，所有需要触发定时器的类都要继承本接口
//如果某种类型的对象，定时器间隔都完全相同，那么可以让对象的manager继承本接口，在manager的OnTimer里面遍历每个对象调用定时器处理函数，
//这样可以减少TimerMgr里面定时器队列的长度，如CUser对象，只需让UserMgr继承本接口，然后再OnTimer中遍历每个CUser调用CUser::OnTimer即可
class ITimerHandler
{
public:
	//指定定时器的精度，和触发的间隔，这里只是触发OnTimer的间隔，尽可能取大的值
	ITimerHandler(TIMER_PRECISION ePrecision, time_t tInterval, bool bPeriodic);
	//反注册定时器
	virtual ~ITimerHandler();

public:
	//定时器触发时回调
	virtual void OnTimer() = 0;
	//时间点触发回调
	virtual void OnTimeTrigger(const TimeTrigger_t& pTrigger) = 0;
	virtual ITimer* GetTimer() = 0;
private:
	ITimer* m_pTimer;
};

//管理所有的定时器，按需触发
//没有达到触发时间的类，不会调用OnTimer，这样可以有效减少浪费在OnTimer里面的时间
class CTimerMgr
{
private:
	typedef std::list<ITimerHandler*> TIMER_LIST;
	typedef std::vector<ITimerHandler*> TIMER_VEC;
	CTimerMgr();
	~CTimerMgr();
public:
	static CTimerMgr* GetInstance();
	bool RegisterTimer(ITimerHandler* pNewTimerHandler);
	bool UnregisterTimer(ITimerHandler* pTimerHandler);
	void OnTimer();
private:
	TIMER_LIST* GetFitTimerList(ITimerHandler* pTimerHandler);
	void OnTimerPriv(TIMER_LIST& lstTimer);
	void OnTimeTrigger();
	void InitTimeTrigger();
	void FillTimeTrigger(TimeTrigger_t* pTrigger, tm* pTimeZone);
private:
	TIMER_LIST m_lstTimerMS;
	TIMER_LIST m_lstTimerSec;
	TimeTrigger_t m_stTrigger;
	CTimerMS m_tTimerMS;
	CTimer m_tTimerSec;
	CTimer m_tTimerTigger;
};

#endif	//end of define _TIMERMGR_H_
