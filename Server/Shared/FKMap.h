////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:2015/07/17
// Describe:four key Map
////////////////////////////////////////////////////////////////////////
#ifndef _FKMAP_H_
#define _FKMAP_H_

#include <unordered_map>
#include <unordered_set>
#include "BaseDefine.h"

template <class K1, class K2, class K3, class K4, class T>
class CFKMap
{
public:
	typedef struct FKMapValueType_s
	{
		K1 k1;
		K2 k2;
		K3 k3;
		K4 k4;
		T* pObject;
	} FKMapValueType_t;
private:
	typedef std::unordered_map<K1, FKMapValueType_t*> K1MAP;
	typedef std::unordered_map<K2, FKMapValueType_t*> K2MAP;
	typedef std::unordered_map<K3, FKMapValueType_t*> K3MAP;
	typedef std::unordered_map<K4, FKMapValueType_t*> K4MAP;
	typedef std::unordered_set<FKMapValueType_t*> FKMAP_OBJECT_SET;
public:
	CFKMap() {}
	~CFKMap();
public:
	bool AddObject(K1 k1, K2 k2, K3 k3, K4 k4, T* pObject);
	bool DelObjectByKey1(K1 k1);
	bool DelObjectByKey2(K2 k2);
	bool DelObjectByKey3(K3 k3);
	bool DelObjectByKey4(K4 k4);
	T* GetObjectByKey1(K1 k1);
	T* GetObjectByKey2(K2 k2);
	T* GetObjectByKey3(K3 k3);
	T* GetObjectByKey4(K4 k4);

	typedef typename FKMAP_OBJECT_SET::iterator CIterator;

	CIterator Begin() { return m_setObjects.begin(); }
	CIterator End() { return m_setObjects.end(); }
private:
	FKMapValueType_t* GetValueTypeByKey1(K1 k1) { MAP_FIND_IMPL(m_mapK1, k1, K1MAP::iterator); }
	FKMapValueType_t* GetValueTypeByKey2(K2 k2) { MAP_FIND_IMPL(m_mapK2, k2, K2MAP::iterator); }
	FKMapValueType_t* GetValueTypeByKey3(K3 k3) { MAP_FIND_IMPL(m_mapK3, k3, K3MAP::iterator); }
	FKMapValueType_t* GetValueTypeByKey4(K4 k4) { MAP_FIND_IMPL(m_mapK4, k4, K4MAP::iterator); }
private:
	K1MAP m_mapK1;
	K2MAP m_mapK2;
	K3MAP m_mapK3;
	K4MAP m_mapK4;
	FKMAP_OBJECT_SET m_setObjects;

};

template <class K1, class K2, class K3, class K4, class T>
T* CFKMap<K1, K2, K3, K4, T>::GetObjectByKey4(K4 k4)
{
	FKMapValueType_t* pValueType = this->GetValueTypeByKey4(k4);
	if (pValueType == NULL)
	{
		return NULL;
	}

	return pValueType->pObject;
}

template <class K1, class K2, class K3, class K4, class T>
T* CFKMap<K1, K2, K3, K4, T>::GetObjectByKey3(K3 k3)
{
	FKMapValueType_t* pValueType = this->GetValueTypeByKey3(k3);
	if (pValueType == NULL)
	{
		return NULL;
	}

	return pValueType->pObject;
}

template <class K1, class K2, class K3, class K4, class T>
T* CFKMap<K1, K2, K3, K4, T>::GetObjectByKey2(K2 k2)
{
	FKMapValueType_t* pValueType = this->GetValueTypeByKey2(k2);
	if (pValueType == NULL)
	{
		return NULL;
	}

	return pValueType->pObject;
}

template <class K1, class K2, class K3, class K4, class T>
T* CFKMap<K1, K2, K3, K4, T>::GetObjectByKey1(K1 k1)
{
	FKMapValueType_t* pValueType = this->GetValueTypeByKey1(k1);
	if (pValueType == NULL)
	{
		return NULL;
	}

	return pValueType->pObject;
}

template <class K1, class K2, class K3, class K4, class T>
bool CFKMap<K1, K2, K3, K4, T>::DelObjectByKey4(K4 k4)
{
	FKMapValueType_t* pValueType = this->GetValueTypeByKey4(k4);
	CHECK_RETURN(pValueType, true);

	m_mapK1.erase(pValueType->k1);
	m_mapK2.erase(pValueType->k2);
	m_mapK3.erase(pValueType->k3);
	m_mapK4.erase(pValueType->k4);

	m_setObjects.erase(pValueType);
	SAFE_DELETE(pValueType);

	return true;
}

template <class K1, class K2, class K3, class K4, class T>
bool CFKMap<K1, K2, K3, K4, T>::DelObjectByKey3(K3 k3)
{
	FKMapValueType_t* pValueType = this->GetValueTypeByKey3(k3);
	CHECK_RETURN(pValueType, true);

	m_mapK1.erase(pValueType->k1);
	m_mapK2.erase(pValueType->k2);
	m_mapK3.erase(pValueType->k3);
	m_mapK4.erase(pValueType->k4);

	m_setObjects.erase(pValueType);
	SAFE_DELETE(pValueType);

	return true;
}

template <class K1, class K2, class K3, class K4, class T>
bool CFKMap<K1, K2, K3, K4, T>::DelObjectByKey2(K2 k2)
{
	FKMapValueType_t* pValueType = this->GetValueTypeByKey2(k2);
	CHECK_RETURN(pValueType, true);

	m_mapK1.erase(pValueType->k1);
	m_mapK2.erase(pValueType->k2);
	m_mapK3.erase(pValueType->k3);
	m_mapK4.erase(pValueType->k4);

	m_setObjects.erase(pValueType);
	SAFE_DELETE(pValueType);

	return true;
}

template <class K1, class K2, class K3, class K4, class T>
bool CFKMap<K1, K2, K3, K4, T>::DelObjectByKey1(K1 k1)
{
	FKMapValueType_t* pValueType = this->GetValueTypeByKey1(k1);
	CHECK_RETURN(pValueType, true);

	m_mapK1.erase(pValueType->k1);
	m_mapK2.erase(pValueType->k2);
	m_mapK3.erase(pValueType->k3);
	m_mapK4.erase(pValueType->k4);

	m_setObjects.erase(pValueType);
	SAFE_DELETE(pValueType);

	return true;
}

template <class K1, class K2, class K3, class K4, class T>
bool CFKMap<K1, K2, K3, K4, T>::AddObject(K1 k1, K2 k2, K3 k3, K4 k4, T* pObject)
{
	CHECK_RETURN(pObject, false);

	FKMapValueType_t* pValueType = new FKMapValueType_t;
	CHECK_RETURN(pValueType, false);
	pValueType->k1 = k1;
	pValueType->k2 = k2;
	pValueType->k3 = k3;
	pValueType->k4 = k4;
	pValueType->pObject = pObject;
	m_mapK1.insert(std::make_pair(k1, pValueType));
	m_mapK2.insert(std::make_pair(k2, pValueType));
	m_mapK3.insert(std::make_pair(k3, pValueType));
	m_mapK4.insert(std::make_pair(k4, pValueType));

	m_setObjects.insert(pValueType);

	return true;
}

template <class K1, class K2, class K3, class K4, class T>
CFKMap<K1, K2, K3, K4, T>::~CFKMap()
{
	m_mapK1.clear();
	m_mapK2.clear();
	m_mapK3.clear();
	m_mapK4.clear();
	for (FKMAP_OBJECT_SET::iterator it = m_setObjects.begin(); it != m_setObjects.end(); ++it)
	{
		FKMapValueType_t* pValueType = *it;
		SAFE_DELETE(pValueType);
	}
	m_setObjects.clear();
}

#endif	//end of define _FKMAP_H_