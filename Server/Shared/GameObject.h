////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:	2015/06/16
// Describe:游戏内对象
////////////////////////////////////////////////////////////////////////
#ifndef _GAMEOBJECT_H_
#define _GAMEOBJECT_H_

#include <bitset>
#include "BaseDefine.h"

using std::bitset;

#define IPP_OF(x)	((void**)(&(x)))

#define OBJID_SERVER_ID_BITS		16
#define OBJID_REAL_ID_BITS		48
//对象ID，组成是高16位为服务器ID，低48位为真实ID
typedef OBJID64 OBJID;

enum OBJECT_TYPE
{
	OBJ_NONE					= 0,	//无效类型
	OBJ_USER					= 1,	//玩家
	OBJ_MONSTER				= 2,	//怪物
	OBJ_NPC						= 3,	//NPC
	OBJ_EUDEMON				= 4,	//幻兽
	OBJ_ITEM					= 5,	//物品
	OBJ_SYNDICATE				= 6,	//军团

	//!!!新的类型添加在本行之上
	OBJ_MAX,							//计数项，请勿直接使用
};

//对象类型
//支持定义复合类型，用于对象收集等时机使用
class CObjectType
{
public:
	//可以定义单个类型CObjectType(OBJ_USER)
	//也可以定义复合类型CObjectType(OBJ_USER, OBJ_MONSTER, OBJ_NONE)，因为是可变参数，最后一个参数必须以OBJ_NONE结束，在对象收集等场合很有用
	CObjectType(OBJECT_TYPE eType, OBJECT_TYPE eType1 = OBJ_NONE, ...);
	~CObjectType();
public:
	const OBJECT_TYPE GetType() const;
	bool IsType(const OBJECT_TYPE eType);
	bool IsContain(const OBJECT_TYPE eType);
	void AddType(const OBJECT_TYPE eType);
	bool operator==(const CObjectType& rOther);
	bool operator==(const OBJECT_TYPE eType);
	bool operator!=(const CObjectType& rOther);
	bool operator!=(const OBJECT_TYPE eType);
	CObjectType& operator=(const CObjectType& rOther);
	CObjectType& operator=(const OBJECT_TYPE eType);
private:
	bitset<OBJ_MAX> m_bsType;
};

//游戏中各种对象的基类
//跨服或者并服时，可能出现重复的对象，都要继承本类
//使用时，注意在创建对象时，指定对应的类型
class CGameObject
{
protected:
	CGameObject(OBJECT_TYPE eType);
	virtual ~CGameObject();
public:
	virtual void Release() { delete this; }

public:
	static OBJID16 GetServerID(OBJID idObject);
	static OBJID64 GetRealID(OBJID idObject);
	virtual OBJID GetID() = 0;
	OBJECT_TYPE GetType();
	virtual bool IsType(const CObjectType& eType);
	virtual bool QueryObject(OBJECT_TYPE eObjType, void** ppObj);
		
protected:
	CObjectType m_objType;
};

#endif	//end of define _GAMEOBJECT_H_