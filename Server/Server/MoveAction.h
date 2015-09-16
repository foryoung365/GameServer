////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:	2015/05/27
// Describe:移动指令动作
////////////////////////////////////////////////////////////////////////
#ifndef _MOVEACTION_H_
#define _MOVEACTION_H_

#include <time.h>
#include "ozcollide/vec3f.h"

using namespace ozcollide;

typedef struct MoveActionInfo_s
{
	float fStartX;
	float fStartY;
	float fStartZ;
	float fEndX;
	float fEndY;
	float fEndZ;
	time_t tStartTime;	//单位ms
	time_t tEndTime;	//单位ms
	float fVelocity;
}MoveActionInfo_t;

class CMoveAction
{
protected:
	CMoveAction();
	~CMoveAction();
public:
	static CMoveAction* CreateNew() { return new CMoveAction; }
	void Release() { delete this; }
	bool Create(MoveActionInfo_t* pActionInfo);

public:
	const Point3f& GetStartPos() { return m_ptStart; }
	void SetStartPos(const Point3f& ptStartPos) { m_ptStart = ptStartPos; }

	const Point3f& GetEndPos() { return m_ptEnd; }
	void SetEndPos(const Point3f& ptEndPos) { m_ptEnd = ptEndPos; }

	clock_t GetStartTime() { return m_tStartTime; }
	void SetStartTime(const clock_t tStartTime) { m_tStartTime = tStartTime; }

	clock_t GetEndTime() { return m_tEndTime; }
	void SetEndTime(const clock_t tEndTime) { m_tEndTime = tEndTime; }

	float GetVelocity() { return m_fVelocity; }
	void SetVelocity(const float fVelocity) { m_fVelocity = fVelocity; }

protected:
	Point3f m_ptStart;
	Point3f m_ptEnd;
	clock_t m_tStartTime;
	clock_t m_tEndTime;
	float m_fVelocity;
};

#endif	//end of define _MOVEACTION_H_
