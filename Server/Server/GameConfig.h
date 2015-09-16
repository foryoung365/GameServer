////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:2015/07/13
// Describe:游戏通用配置
////////////////////////////////////////////////////////////////////////
#ifndef _GAMECONFIG_H_
#define _GAMECONFIG_H_

#include "BaseDefine.h"
#include "GameObject.h"
#include "ConfigData.h"
#include "juce_core/juce_core.h"

enum GAME_CONFIG_TYPE
{
	GAME_CFGTYPE_NONE = 0,	//无效类型
	GAME_CFGTYPE_OPEN_TIME = 1000,	//开服时间，data1=YYMMDDHHMM
};

class CGameConfigSet
{
private:
	CGameConfigSet();
	~CGameConfigSet();
public:
	juce_DeclareSingleton_SingleThreaded(CGameConfigSet, true);
	void Release() { delete this; }
	bool Create();
	CConfigData* QueryConfigType(OBJID32 idType);
private:
	typedef std::map<OBJID32, CConfigData*> CONFIG_DATA_MAP;
	CONFIG_DATA_MAP m_mapConfig;
};

#endif	//end of define _GAMECONFIG_H_