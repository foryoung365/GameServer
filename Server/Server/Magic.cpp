////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:2015/08/18
// Describe:
////////////////////////////////////////////////////////////////////////
#include "Magic.h"
#include "UserMagic.h"
#include "TimeFormatter.h"

CMagic::CMagic()
{
	m_tLastCastTime = 0;
	m_pTypeData = NULL;
}

CMagic* CMagic::CreateNew(OBJECT_TYPE eObjectType)
{
	CMagic* pMagic = NULL;
	switch (eObjectType)
	{
	case OBJ_USER:
	{
		pMagic = CUserMagic::CreateNew();
	}
	break;
	default:
	{
		LogErr(juce::String().formatted("Bad ObjectType[%lld] while create magic.", eObjectType));
	}
	break;
	}

	CHECK_RETURN2(pMagic, eObjectType, NULL);

	return pMagic;
}

bool CMagic::IsInCD()
{
	CHECK_RETURN(m_pTypeData, true);

	time_t tCurTimeMs = CTimeFormatter::TimeGet(TIME_MILLISECOND);
	if (m_tLastCastTime + m_pTypeData->cool_down_ms > tCurTimeMs)
	{
		return true;
	}

	return false;
}

