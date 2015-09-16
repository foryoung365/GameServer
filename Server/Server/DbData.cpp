////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author: 	Fu Yan
// Created: 	2015-08-17
// Describe: 	Specailized SQL structure's static member definition of all table, 
//				generate by genSsqls.py, !!!DO NOT EDIT!!!
////////////////////////////////////////////////////////////////////////
#include "ConfigData.h"
#include "RoleTypeData.h"
#include "SceneData.h"
#include "UserData.h"
#include "MagicTypeData.h"
#include "StatusTypeData.h"
#include "MagicData.h"


const char* CConfigData::names[] = {
        "id" ,
    "type" ,
    "data1" ,
    "data2" ,
    "data3" ,
    "data4" ,
    "data5" ,
    "str" ,
    "desc" 
};
const char* CConfigData::table_ = "gs_config";
const char* CRoleTypeData::names[] = {
        "id" ,
    "name" ,
    "gender" ,
    "profession" ,
    "base_level" ,
    "max_level" ,
    "length" ,
    "width" ,
    "height" ,
    "base_life" ,
    "base_mana" ,
    "base_speed" 
};
const char* CRoleTypeData::table_ = "gs_role_type";
const char* CSceneData::names[] = {
        "id" ,
    "name" ,
    "mapdoc" ,
    "type" ,
    "type2" ,
    "sort" ,
    "portal0_x" ,
    "portal0_y" ,
    "portal0_z" ,
    "reborn_map" ,
    "link_map" ,
    "link_x" ,
    "link_y" ,
    "link_z" ,
    "flag" 
};
const char* CSceneData::table_ = "gs_scene";
const char* CUserData::names[] = {
        "id" ,
    "name" ,
    "account_id" ,
    "role_type" ,
    "level" ,
    "exp" ,
    "length" ,
    "width" ,
    "height" ,
    "scene_id" ,
    "pos_x" ,
    "pos_y" ,
    "pos_z" ,
    "record_scene_id" ,
    "record_x" ,
    "record_y" ,
    "record_z" ,
    "life" ,
    "mana" 
};
const char* CUserData::table_ = "gs_user";
const char* CMagicTypeData::names[] = {
        "id" ,
    "name" ,
    "sort" ,
    "begin_delay_ms" ,
    "end_delay_ms" ,
    "cool_down_ms" ,
    "cost_type1" ,
    "cost_value1" ,
    "cost_type2" ,
    "cost_value2" ,
    "range_distance" ,
    "target_type" ,
    "range_type" ,
    "range_x" ,
    "range_y" ,
    "damage_id" ,
    "atker_distance" ,
    "atker_duration" ,
    "victim_distance" ,
    "victim_duration" ,
    "status_id" ,
    "status_rate" 
};
const char* CMagicTypeData::table_ = "gs_magic_type";
const char* CStatusTypeData::names[] = {
        "id" ,
    "name" ,
    "status_type" ,
    "hit_rate" ,
    "duration" ,
    "hit_times" ,
    "power_type" ,
    "power_value" 
};
const char* CStatusTypeData::table_ = "gs_status_type";
const char* CMagicData::names[] = {
        "id" ,
    "owner_id" ,
    "magic_type" ,
    "exp" 
};
const char* CMagicData::table_ = "gs_magic";

