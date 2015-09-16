////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:	2015/06/16
// Describe:
////////////////////////////////////////////////////////////////////////
#include "GameObject.h"

CObjectType::CObjectType(OBJECT_TYPE etype, OBJECT_TYPE eType1 /*= OBJ_NONE*/, ...)
{
	if (etype > OBJ_NONE && etype < OBJ_MAX)
	{
		m_bsType.set(etype);
	}

	UNUSED_PARM(eType1);

	va_list pArgs;
	va_start(pArgs, etype);

	OBJECT_TYPE etypeArg = OBJ_NONE;
	while ((etypeArg = va_arg(pArgs, OBJECT_TYPE)) != OBJ_NONE)
	{
		if (etypeArg == OBJ_NONE || etypeArg >= OBJ_MAX)
		{
			break;
		}
		m_bsType.set(etypeArg);
	}
}

CObjectType::~CObjectType()
{

}

const OBJECT_TYPE CObjectType::GetType() const
{
	if (m_bsType.count() != 1)
	{
		return OBJ_NONE;
	}

	for (int i = 0; i < m_bsType.size(); ++i)
	{
		if (m_bsType.test(i))
		{
			return OBJECT_TYPE(i);
		}
	}

	return OBJ_NONE;
}

bool CObjectType::IsType(OBJECT_TYPE eType)
{
	CHECK_RETURN(((eType > OBJ_NONE) && (eType < OBJ_MAX)), false);

	if (m_bsType.count() != 1)
	{
		return false;
	}

	return m_bsType.test(eType);
}

bool CObjectType::IsContain(OBJECT_TYPE eType)
{
	CHECK_RETURN(eType > OBJ_NONE && eType < OBJ_MAX, false);

	return m_bsType.test(eType);
}

bool CObjectType::operator==(const CObjectType& rOther)
{
	if (&rOther == this)
	{
		return true;
	}

	return rOther.m_bsType == this->m_bsType;
}

bool CObjectType::operator==(const OBJECT_TYPE eType)
{
	return this->IsType(eType);
}

CObjectType& CObjectType::operator=(const CObjectType& rOther)
{
	if (&rOther == this)
	{
		return *this;
	}

	this->m_bsType.reset();
	this->m_bsType = rOther.m_bsType;

	return *this;
}

CObjectType& CObjectType::operator=(const OBJECT_TYPE eType)
{
	m_bsType.reset();

	if (eType > OBJ_NONE && eType < OBJ_MAX)
	{
		m_bsType.set(eType);
	}

	return *this;
}

bool CObjectType::operator!=(const CObjectType& rOther)
{
	if (&rOther == this)
	{
		return false;
	}

	return rOther.m_bsType != this->m_bsType;
}

bool CObjectType::operator!=(const OBJECT_TYPE eType)
{
	return this->IsType(eType);
}

void CObjectType::AddType(const OBJECT_TYPE eType)
{
	m_bsType.set(eType);
}

CGameObject::CGameObject(OBJECT_TYPE eType) : m_objType(eType)
{

}

CGameObject::~CGameObject()
{

}

bool CGameObject::IsType(const CObjectType& eType)
{
	return (m_objType == eType);
}

OBJID16 CGameObject::GetServerID(OBJID idObject)
{
	return OBJID16(idObject >> OBJID_REAL_ID_BITS);
}


bool CGameObject::QueryObject(OBJECT_TYPE eObjType, void** ppObj)
{
	if (eObjType != this->GetType())
	{
		return false;
	}

	if (ppObj == NULL)
	{
		return false;
	}

	*ppObj = this;

	return true;
}

OBJID64 CGameObject::GetRealID(OBJID idObject)
{
	return ((idObject << OBJID_SERVER_ID_BITS) >> OBJID_SERVER_ID_BITS);
}

OBJECT_TYPE CGameObject::GetType()
{
	return m_objType.GetType();
}
