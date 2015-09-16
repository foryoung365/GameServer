////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:	2015/06/29
// Describe:
////////////////////////////////////////////////////////////////////////
#ifndef _KERNELDEF_H_
#define _KERNELDEF_H_

#include <string>

enum THREAD_INDEX
{
	THREAD_INDEX_MAIN,					//主线程
 	THREAD_INDEX_SERVER_SOCKET,			//客户端连接的服务器SOCKET线程
	THREAD_INDEX_AS_SOCKET,				//账服连接SOCKET线程
	THREAD_INDEX_LOGIN,					//登录预处理线程（相当于原来的WORLD_KERNEL）
	THREAD_INDEX_DATABASE,				//数据库线程（登录数据的异步加载）
 	THREAD_INDEX_GAME,					//游戏服务线程（处理游戏业务逻辑）

	//------新的线程添加在此之上-----------
	THREAD_INDEX_MAX,					//计数项，不可直接使用
};

extern const std::string g_stThreadInfos[THREAD_INDEX_MAX];

#endif	//end of define _KERNELDEF_H_