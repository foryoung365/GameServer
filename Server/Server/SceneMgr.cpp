////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:	2015/06/26
// Describe:
////////////////////////////////////////////////////////////////////////
#include "SceneMgr.h"
#include "BaseDefine.h"
#include "Scene.h"
#include "DbTableDef.h"
#include "GameKernel.h"

juce_ImplementSingleton_SingleThreaded(CSceneMgr)

CSceneMgr::CSceneMgr()
{

}

CSceneMgr::~CSceneMgr()
{
	MAP_RELEASE_ALL(m_mapScenes, SCENE_MAP::iterator);
	CSceneMgr::clearSingletonInstance();
}

bool CSceneMgr::Create()
{
	SQLBUF strSQL;
	strSQL << "SELECT * FROM " << TBL_SCENE;
	const CGameRecordset& rRes = CGameKernel::GetDatabase()->Select(strSQL);
	for (int i = 0; i < rRes.size(); ++i)
	{
		CScene* pScene = CScene::CreateNew();
		IF_NOT(pScene && pScene->Create(rRes.at(i)))
		{
			return false;
		}

		m_mapScenes.insert(std::make_pair(pScene->GetID(), pScene));
	}

	return true;
}

CScene* CSceneMgr::QueryScene(OBJID idScene)
{
	MAP_FIND_IMPL(m_mapScenes, idScene, SCENE_MAP::iterator);
}
