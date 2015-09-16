////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:	2015/06/26
// Describe:≥°æ∞π‹¿Ì∆˜
////////////////////////////////////////////////////////////////////////
#ifndef _SCENEMGR_H_
#define _SCENEMGR_H_

#include <map>
#include "GameObject.h"
#include "SceneDef.h"
#include "juce_core/juce_core.h"

class CScene;

class CSceneMgr
{
private:
	CSceneMgr();
	~CSceneMgr();
public:
	bool Create();
	void Release() { delete this; }

	CScene* QueryScene(OBJID idScene);
public:
	juce_DeclareSingleton_SingleThreaded(CSceneMgr, true)
private:
	typedef std::map<OBJID, CScene*> SCENE_MAP;
	SCENE_MAP m_mapScenes;
};

#define SceneMgr CSceneMgr::getInstance

#endif	//end of define _SCENEMGR_H_