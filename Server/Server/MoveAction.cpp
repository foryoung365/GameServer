////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:	2015/06/01
// Describe:
////////////////////////////////////////////////////////////////////////
#include "MoveAction.h"
#include "BaseDefine.h"

CMoveAction::CMoveAction()
{
	m_tStartTime = 0;
	m_tEndTime = 0;
	m_fVelocity = 0.0f;
}

CMoveAction::~CMoveAction()
{

}

bool CMoveAction::Create(MoveActionInfo_t* pActionInfo)
{
	CHECK_RETURN(pActionInfo, false);

	m_ptStart.x = pActionInfo->fStartX;
	m_ptStart.y = pActionInfo->fStartY;
	m_ptStart.z = pActionInfo->fStartZ;
	
	m_ptEnd.x = pActionInfo->fEndX;
	m_ptEnd.y = pActionInfo->fEndY;
	m_ptEnd.z = pActionInfo->fEndZ;

	m_tStartTime = pActionInfo->tStartTime;
	m_tEndTime = pActionInfo->tEndTime;
	m_fVelocity = pActionInfo->fVelocity;

	return true;
}