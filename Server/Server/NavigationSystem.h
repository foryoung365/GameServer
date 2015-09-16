////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:2015/08/06
// Describe:导航网格寻路系统
////////////////////////////////////////////////////////////////////////
#ifndef _NAVIGATIONSYSTEM_H_
#define _NAVIGATIONSYSTEM_H_

#include "BaseDefine.h"
#include "ozcollide/vec3f.h"

using namespace ozcollide;

class CNavigationSystem
{
public:
	juce_DeclareSingleton_SingleThreaded(CNavigationSystem, true);
	CNavigationSystem();
	~CNavigationSystem();
public:
	bool Create();
	
private:

};

#endif	//end of define _NAVIGATIONSYSTEM_H_
