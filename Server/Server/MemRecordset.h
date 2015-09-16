////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:2015/07/14
// Describe:内存玩家数据集，DBKernel异步加载的玩家数据集会保存在本类中
// 当玩家登录完成后或者数据超时时清除
////////////////////////////////////////////////////////////////////////
#ifndef _MEMRECORDSET_H_
#define _MEMRECORDSET_H_

#include <map>
#include "BaseDefine.h"
#include "GameDatabase.h"
#include "DbTableDef.h"
#include "TimeFormatter.h"
#include "Timer.h"

class CMemRecordset
{
private:
	CMemRecordset();
	~CMemRecordset();
public:
	bool Create();
	juce_DeclareSingleton_SingleThreaded(CMemRecordset, true);
	void AddRecordsetMap(OBJID idUser, OBJID64 idRecordsetMap);
	CGameRecordset* QueryRecordset(OBJID idUser, DB_LOAD_DATA_TYPE eType);
	void ReleaseRecordset(OBJID idUser);
	void OnTimer();
private:
	LOADED_USER_DATA_MAP* QueryRecordsetMap(OBJID idUser);
private:
	typedef std::map<OBJID, LOADED_USER_DATA_MAP*> RECORDSET_MAP;
	RECORDSET_MAP m_mapRecordsets;
	typedef std::map<OBJID, time_t> USER_TIME_MAP;
	USER_TIME_MAP m_mapUserTime;
	CTimer m_tTimer;
};

#endif	//end of define _MEMRECORDSET_H_