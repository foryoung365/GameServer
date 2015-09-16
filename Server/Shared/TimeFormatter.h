////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:	2015/07/03
// Describe:时间格式化器
////////////////////////////////////////////////////////////////////////
#ifndef _TIMEFORMATTER_H_
#define _TIMEFORMATTER_H_

#include "BaseDefine.h"

enum TIME_FORMATTER_TYPE
{
	TIME_MILLISECOND,			//从1970年1月1日到现在经过的毫秒数
	TIME_SECOND,				//从1970年1月1日到现在经过的秒数
	TIME_YYMMDDHHMM,
	TIME_YYYYMMDDHH,
	TIME_YYYYMMDD,
	TIME_HHMMSS,
	TIME_WHHMMSS,				//weekday(1-7)+HHMMSS
	TIME_YYYYMMDDHHMMSS,
};

class CTimeFormatter
{
public:
	//将当前时间转换为指定格式
	static int64_t TimeGet(TIME_FORMATTER_TYPE eType);
	//将指定时间转换为指定格式
	//用法：先使用Time (int year,	int month, int day, int hours, int minutes,	int seconds = 0, int milliseconds = 0, bool useLocalTime = true)创建一个需要转化的时间
	static int64_t TimeConvert(juce::Time& tTime, TIME_FORMATTER_TYPE eType);

	static juce::Time MakeTime(TIME_FORMATTER_TYPE eType, int64_t tTime);

	/** Converts this date/time to a string with a user-defined format.

	This uses the C strftime() function to format this time as a string. To save you
	looking it up, these are the escape codes that strftime uses (other codes might
	work on some platforms and not others, but these are the common ones):

	%a  is replaced by the locale's abbreviated weekday name.
	%A  is replaced by the locale's full weekday name.
	%b  is replaced by the locale's abbreviated month name.
	%B  is replaced by the locale's full month name.
	%c  is replaced by the locale's appropriate date and time representation.
	%d  is replaced by the day of the month as a decimal number [01,31].
	%H  is replaced by the hour (24-hour clock) as a decimal number [00,23].
	%I  is replaced by the hour (12-hour clock) as a decimal number [01,12].
	%j  is replaced by the day of the year as a decimal number [001,366].
	%m  is replaced by the month as a decimal number [01,12].
	%M  is replaced by the minute as a decimal number [00,59].
	%p  is replaced by the locale's equivalent of either a.m. or p.m.
	%S  is replaced by the second as a decimal number [00,61].
	%U  is replaced by the week number of the year (Sunday as the first day of the week) as a decimal number [00,53].
	%w  is replaced by the weekday as a decimal number [0,6], with 0 representing Sunday.
	%W  is replaced by the week number of the year (Monday as the first day of the week) as a decimal number [00,53]. All days in a new year preceding the first Monday are considered to be in week 0.
	%x  is replaced by the locale's appropriate date representation.
	%X  is replaced by the locale's appropriate time representation.
	%y  is replaced by the year without century as a decimal number [00,99].
	%Y  is replaced by the year with century as a decimal number.
	%Z  is replaced by the timezone name or abbreviation, or by no bytes if no timezone information exists.
	%%  is replaced by %.
	*/
	static juce::String TimeGetString(const char* szFormat);
	static juce::String TimeGetString(juce::Time& tTime, const char* szFormat);
};

#endif	//end of define _TIMEFORMATTER_H_
