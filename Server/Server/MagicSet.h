////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:2015/08/17
// Describe:角色技能集合
////////////////////////////////////////////////////////////////////////
#ifndef _MAGICSET_H_
#define _MAGICSET_H_

#include <map>
#include "BaseDefine.h"
#include "GameDatabase.h"
#include "MagicDef.h"
#include "Magic.h"

using juce::WeakReference;

class CRole;

class CMagicSet
{
private:
	CMagicSet();
	~CMagicSet();
public:
	static CMagicSet* CreateNew() { return new CMagicSet; }
	void Release() { delete this; }
	bool Create(CRole* pRole);
	//释放技能，模板方法，请勿直接将业务写在该函数内
	bool CastMagic(OBJID idMagic, CRole* pTargetRole, Point3f ptTargetPos);
	bool HasMagic(OBJID idMagic);
	CMagic* QueryMagic(OBJID idMagic);

private:
	CRole* m_pOwner;
	typedef std::map<OBJID, CMagic*> MAGIC_MAP;
	MAGIC_MAP m_mapMagics;
};

#endif	//end of define _MAGICSET_H_