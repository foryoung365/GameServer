////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:	2015/06/01
// Describe:行动列表
////////////////////////////////////////////////////////////////////////
#ifndef _MOVELIST_H_
#define _MOVELIST_H_

#include <list>
#include "ozcollide/vec3f.h"
#include "MoveAction.h"

using namespace ozcollide;

class CMoveAction;

typedef std::list<CMoveAction*> MOVEACTION_LIST;
typedef std::list<CMoveAction*>::iterator MOVELIST_ITERATOR;

class CMoveList
{
private:
	CMoveList();
	~CMoveList();
public:
	static CMoveList* CreateNew() { return new CMoveList; }
	void Release() { delete this; }
	bool Create();
	bool AppendMoveAction(CMoveAction* pMoveAction);
	bool AppendMoveActionByInfo(MoveActionInfo_t* pInfo);
	bool HasPendingMove();
	bool RunActions(Point3f& ptEndPos);
	void ClearAllActions();
	void InterruptAllActions(Point3f& ptEndPos);
	bool GetMoveAction(CMoveAction* pMoveAction);
	bool GetCurMoveAction(CMoveAction* pMoveAction);
private:
	MOVEACTION_LIST m_lstActions;
};

#endif	//end of define _MOVELIST_H_