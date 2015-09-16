////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:	2015/07/03
// Describe:
////////////////////////////////////////////////////////////////////////
#include "TimeFormatter.h"
#include "time.h"

int64_t CTimeFormatter::TimeGet(TIME_FORMATTER_TYPE eType)
{
	juce::Time TimeCurr = juce::Time::getCurrentTime();
	return CTimeFormatter::TimeConvert(TimeCurr, eType);
}

int64_t CTimeFormatter::TimeConvert(juce::Time& tTime, TIME_FORMATTER_TYPE eType)
{
	int64_t dwTimeFormatted = 0;
	switch (eType)
	{
	case TIME_MILLISECOND:
	{
		dwTimeFormatted = tTime.toMilliseconds();
	}
	break;
	case TIME_SECOND:
	{
		dwTimeFormatted = time(NULL);
	}
	break;
	case TIME_YYMMDDHHMM:
	{
		juce::String strTime = tTime.formatted("%y%m%d%H%M");
		dwTimeFormatted = strTime.getLargeIntValue();
	}
	break;
	case TIME_YYYYMMDDHH:
	{
		juce::String strTime = tTime.formatted("%Y%m%d%H");
		dwTimeFormatted = strTime.getLargeIntValue();
	}
	break;
	case TIME_YYYYMMDD:
	{
		juce::String strTime = tTime.formatted("%Y%m%d");
		dwTimeFormatted = strTime.getLargeIntValue();
	}
	break;
	case TIME_HHMMSS:
	{
		juce::String strTime = tTime.formatted("%H%M%S");
		dwTimeFormatted = strTime.getLargeIntValue();
	}
	break;
	case TIME_WHHMMSS:
	{
		dwTimeFormatted = tTime.getDayOfWeek();
		if (dwTimeFormatted == 0)
		{
			dwTimeFormatted = 7;
		}
		dwTimeFormatted *= 1000000;
		juce::String strTime = tTime.formatted("%H%M%S");
		dwTimeFormatted += strTime.getLargeIntValue();
	}
	break;
	case TIME_YYYYMMDDHHMMSS:
	{
		juce::String strTime = tTime.formatted("%Y%m%d%H%M%S");
		dwTimeFormatted = strTime.getLargeIntValue();
	}
	break;
	default:
		break;
	}

	return dwTimeFormatted;
}

juce::String CTimeFormatter::TimeGetString(juce::Time& tTime, const char* szFormat)
{
	return tTime.formatted(szFormat);
}

juce::String CTimeFormatter::TimeGetString(const char* szFormat)
{
	juce::Time TimeCurr = juce::Time::getCurrentTime();

	return TimeCurr.formatted(szFormat);
}

juce::Time CTimeFormatter::MakeTime(TIME_FORMATTER_TYPE eType, int64_t tTime)
{
	juce::Time retTime;
	switch (eType)
	{
	case TIME_MILLISECOND:
	{
		retTime = juce::Time(tTime);
	}
	break;
	case TIME_SECOND:
	{
		retTime = juce::Time(tTime * 1000);
	}
	break;
	case TIME_YYMMDDHHMM:
	{
		retTime = juce::Time(tTime / 100000000+2000, (tTime / 1000000) % 100, (tTime / 10000) % 100, (tTime / 100) % 100, tTime % 100);
	}
	break;
	case TIME_YYYYMMDDHH:
	{
		retTime = juce::Time(tTime / 1000000, (tTime / 10000) % 100, (tTime / 100) % 100, tTime % 100, 0);
	}
	break;
	case TIME_YYYYMMDD:
	{
		retTime = juce::Time(tTime / 10000, (tTime / 100) % 100, tTime % 100, 0, 0);
	}
	break;
	case TIME_HHMMSS:
	{
		uint64_t tCurr = CTimeFormatter::TimeGet(TIME_YYYYMMDD);
		retTime = juce::Time(tCurr / 10000, (tCurr / 100) % 100, tCurr % 100, tTime/10000, (tTime/100)%100, tTime%100);
	}
	break;
	case TIME_WHHMMSS:
	{
		ASSERT_FALSE;
	}
	break;
	case TIME_YYYYMMDDHHMMSS:
	{
		retTime = juce::Time(tTime / 10000000000, (tTime / 100000000) % 100, (tTime / 1000000) % 100, (tTime / 10000) % 100, (tTime / 100) % 100, tTime % 100);
	}
	break;
	default:
		break;
	}

	return retTime;
}

