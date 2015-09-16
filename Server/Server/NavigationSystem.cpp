////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:2015/08/06
// Describe:
////////////////////////////////////////////////////////////////////////
#include "NavigationSystem.h"

juce_ImplementSingleton_SingleThreaded(CNavigationSystem);

CNavigationSystem::CNavigationSystem()
{
}


CNavigationSystem::~CNavigationSystem()
{
	CNavigationSystem::clearSingletonInstance();
}
