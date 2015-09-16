////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:	2015/05/20
// Describe:基础类型定义
////////////////////////////////////////////////////////////////////////
#ifndef _BASEDEFINE_H_
#define _BASEDEFINE_H_

#include <iostream>
#include <set>
#include <stdint.h>
#include <winsock2.h>		//防止出现winsock重定义
#include "call_stack.hpp"
#include "juce_core/juce_core.h"

#ifndef SAFE_DELETE
#define SAFE_DELETE(p)	if (p) { delete p; p = NULL; }
#endif


#define SAFE_RELEASE(p)	if (p) { p->Release(); p = NULL; }

#define SAFE_DELETE_ARRAY(p) if (p) { delete[] p; p = NULL; }

#define UNUSED_PARM(x)	(void(x))

typedef uint16_t OBJID16;
typedef uint32_t OBJID32;
typedef uint64_t OBJID64;

#define ID_NONE		0

#define LogMsg(x) juce::Logger::writeToLog(x, "Message: ")
#define LogErr(x) juce::Logger::writeToLog(x, juce::String() << "Error: " << __FILE__ << "[" << __LINE__ << "][" << __FUNCTION__ << "]  ")

#define LogBoth(x) MACRO_WITH_FORCED_SEMICOLON(LogMsg(x); std::cout << x;)

#define MY_DUMP_BEGIN		"{DUMP:"
#define MY_DUMP_END		"}"

#define ASSERT(x) MACRO_WITH_FORCED_SEMICOLON(if (!(x)) { juce::String strText; strText << "ASSERT(" << #x << ") FAILED!"; LogErr(strText); } )
#define ASSERT2(x, n) MACRO_WITH_FORCED_SEMICOLON(if (!(x)) { juce::String strText; strText << "ASSERT2(" << #x << "," << #n << "=" << n << ") FAILED!"; LogErr(strText); })
#define ASSERT_FALSE MACRO_WITH_FORCED_SEMICOLON(juce::String strText; strText << "ASSERT FAILED!"; LogErr(strText);)
#define CHECK(x) MACRO_WITH_FORCED_SEMICOLON(if (!(x)) { juce::String strText; strText << "CHECK(" << #x << ") FAILED!"; LogErr(strText); return; })
#define CHECK2(x, n) MACRO_WITH_FORCED_SEMICOLON(if (!(x)) { juce::String strText; strText << "CHECK2(" << #x << "," << #n << "=" << n << ") FAILED!"; LogErr(strText); return; })
#define CHECK_RETURN(x, ret) MACRO_WITH_FORCED_SEMICOLON(if (!(x)) { juce::String strText; strText << "CHECK_RETURN(" << #x <<"," << #ret  << ") FAILED!"; LogErr(strText); return ret; })
#define CHECK_RETURN2(x, n, ret) MACRO_WITH_FORCED_SEMICOLON(if (!(x)) { juce::String strText; strText << "CHECK_RETURN2(" << #x << "," << #n << "=" << n <<"," << #ret << ") FAILED!"; LogErr(strText); return ret; })
#define TRACE_STACK() MACRO_WITH_FORCED_SEMICOLON(stacktrace::call_stack st; juce::Logger::writeToLog(st.to_string());)
#define CHECK_TRACE(x) MACRO_WITH_FORCED_SEMICOLON(if (!(x)) { stacktrace::call_stack st; juce::String strText; strText << "CHECK_TRACE(" << #x << ") FAILED!" << MY_DUMP_BEGIN << st.to_string() << MY_DUMP_END; LogErr(strText); return; })
#define CHECK_TRACE2(x, n) MACRO_WITH_FORCED_SEMICOLON(if (!(x)) { stacktrace::call_stack st; juce::String strText; strText << "CHECK_TRACE2(" << #x << "," << #n << "=" << n << ") FAILED!" << MY_DUMP_BEGIN << st.to_string() << MY_DUMP_END; LogErr(strText); return; })
#define CHECK_RETURN_TRACE(x, ret) MACRO_WITH_FORCED_SEMICOLON(if (!(x)) { stacktrace::call_stack st; juce::String strText; strText << "CHECK_RETURN_TRACE(" << #x <<"," << #ret << ") FAILED!"<< MY_DUMP_BEGIN << st.to_string() << MY_DUMP_END; LogErr(strText); return ret; })
#define CHECK_RETURN_TRACE2(x, n, ret) MACRO_WITH_FORCED_SEMICOLON(if (!(x)) { stacktrace::call_stack st; juce::String strText; strText << "CHECK_RETURN_TRACE2(" << #x << "," << #n << "=" << n <<"," << #ret << ") FAILED!"<< MY_DUMP_BEGIN << st.to_string() << MY_DUMP_END; LogErr(strText); return ret; })
#define IF_NOT(x) if (!(x) ? (LogErr(juce::String() << "IF_NOT(" << #x << ") FAILED!" ),1) : 0)
#define IF_NOT2(x, n) if (!(x) ? (LogErr(juce::String() << "IF_NOT2(" << #x << "," << #n << "=" << n << ") FAILED!" ), 1) : 0)

#define MAP_RELEASE_ALL(mapDel, TypeIter)						\
for (TypeIter it = mapDel.begin(); it != mapDel.end(); ++it)	\
{																	\
	SAFE_RELEASE(it->second);									\
}

#define MAP_DELETE_ALL(mapDel, TypeIter)						\
for (TypeIter it = mapDel.begin(); it != mapDel.end(); ++it)	\
{																	\
	SAFE_DELETE(it->second);									\
}

#define MAP_FIND_IMPL(mapFind, ObjFind, TypeIter)			\
																\
	TypeIter it = mapFind.find(ObjFind);					\
	if (it == mapFind.end())									\
	{															\
		return NULL;											\
	}															\
																\
	return it->second											

typedef juce::String SQLBUF;

#define TEXTBUF_SIZE	1024
typedef char TEXT_BUF[TEXTBUF_SIZE];

#define MSGBUF_SIZE	102400		//100KB

#define  DEBUG_TRY	try {
#define DEBUG_CATCH	} catch(const std::exception& e) { stacktrace::call_stack st; juce::String strText; strText << "Exception Catched on " << e.what() << " !" << MY_DUMP_BEGIN << st.to_string() << MY_DUMP_END; LogErr(strText); } catch(...) { stacktrace::call_stack st; juce::String strText; strText << __FILE__ << "[" << __LINE__ << "]: crashed! " << MY_DUMP_BEGIN << st.to_string() << MY_DUMP_END; LogErr(strText); }

#endif	//end of define _BASEDEFINE_H_