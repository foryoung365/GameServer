////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:2015/08/17
// Describe:单件数据库数据类型Map
////////////////////////////////////////////////////////////////////////
#ifndef _SINGLETONDATAMAP_H_
#define _SINGLETONDATAMAP_H_

#include <map>
#include "BaseDefine.h"
#include "GameObject.h"
#include "GameDatabase.h"

//基本数据集，只能保存数据库Data
template<class T>
class CSingletonDataMap
{
private:
	CSingletonDataMap();
	~CSingletonDataMap();
public:
	typedef std::map<OBJID, T*> DATA_MAP;
	typedef typename DATA_MAP::iterator CIterator;
	juce_DeclareSingleton_SingleThreaded(CSingletonDataMap<T>, true);
	bool Create(CGameDatabase* pDb, SQLBUF strSQL);
	T* QueryData(OBJID idData);
	bool AddData(OBJID idData, T* pData);
	bool DelData(OBJID idData);
	CIterator Begin() { return m_mapDatas.begin(); }
	CIterator End() { return m_mapDatas.end(); }
private:
	DATA_MAP m_mapDatas;
};

template<class T>
CSingletonDataMap<T>::CSingletonDataMap()
{

}

template<class T>
CSingletonDataMap<T>::~CSingletonDataMap()
{
	MAP_DELETE_ALL(m_mapDatas, CIterator);
	this->clearSingletonInstance();
}

template<class T>
bool CSingletonDataMap<T>::Create(CGameDatabase* pDb, SQLBUF strSQL)
{
	CHECK_RETURN(pDb, false);
	CHECK_RETURN(strSQL.isEmpty(), false);

	const CGameRecordset& rRes = pDb->Select(strSQL);
	for (int i = 0; i < rRes.size(); ++i)
	{
		T* pData = new T(rRes.at(i));
		if (pData == NULL)
		{
			continue;
		}

		m_mapDatas[pData->id] = pData;
	}

	return true;
}

template<class T>
T* CSingletonDataMap<T>::QueryData(OBJID idData)
{
	CIterator it = m_mapDatas.find(idData);
	if (it == m_mapDatas.end())
	{
		return NULL;
	}

	return it->second;
}

template<class T>
bool CSingletonDataMap<T>::AddData(OBJID idData, T* pData)
{
	CHECK_RETURN(pData, false);

	m_mapDatas[idData] = pData;

	return true;
}

template<class T>
bool CSingletonDataMap<T>::DelData(OBJID idData)
{
	T* pData = this->QueryData(idData);
	if (pData == NULL)
	{
		return true;
	}

	SAFE_DELETE(pData);
	m_mapDatas.erase(idData);

	return true;
}

template<class T>
juce_ImplementSingleton_SingleThreaded(CSingletonDataMap<T>);

#endif	//end of define _SINGLETONDATAMAP_H_