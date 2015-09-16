////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:	2015/05/05
// Describe:≤‚ ‘
////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include "TimeFormatter.h"
#include "juce_core/juce_core.h"
#include "BaseDefine.h"

int main(void)
{
	printf("%lld\n%lld\n%lld\n%lld\n%lld\n%lld\n%lld\n%lld\n", 
		CTimeFormatter::TimeGet(TIME_MILLISECOND), CTimeFormatter::TimeGet(TIME_SECOND), 
		CTimeFormatter::TimeGet(TIME_HHMMSS), CTimeFormatter::TimeGet(TIME_WHHMMSS), 
		CTimeFormatter::TimeGet(TIME_YYMMDDHHMM), CTimeFormatter::TimeGet(TIME_YYYYMMDD),
		CTimeFormatter::TimeGet(TIME_YYYYMMDDHH), CTimeFormatter::TimeGet(TIME_YYYYMMDDHHMMSS));

	OBJID64 idAccount = 12345;
	OBJID32 idRoleType = 1;

	juce::String strSQL;
	strSQL << idRoleType;

	getchar();

	return 0;
}