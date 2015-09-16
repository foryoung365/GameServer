////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author:	FU YAN
// Created:	2015/05/18
// Describe:场景相关常量定义
////////////////////////////////////////////////////////////////////////
#ifndef _SCENEDEF_H_
#define _SCENEDEF_H_

#include "ozcollide/vec3f.h"

using namespace ozcollide;

#define SCENE_SCREEN_SIZE				2048.0f			//一个屏幕所占的大小

#define SCENE_OCTREE_MAX_DEPTH			6				//八叉树最大层数

#define SCENE_OBJECT_CLIENT_MOVE_RANGE	200				//客户端移动每次4米

#define SCENE_MOVE_DISTANCE_TOLERANCE	200				//移动过程中允许存在的误差

#define SCENE_REGION_SIZE				Vec3f(SCENE_SCREEN_SIZE, SCENE_SCREEN_SIZE, SCENE_SCREEN_SIZE)

#endif	//end of define _SCENEDEF_H_