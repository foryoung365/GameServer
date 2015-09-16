##############################################################
# Describe: 初始提交
# Author: Fu Yan
##############################################################
DROP TABLE IF EXISTS `gs_config`;
CREATE TABLE `gs_config` (
	`id` INT(4) UNSIGNED NOT NULL AUTO_INCREMENT,				#序列号
	`type` INT(4) UNSIGNED NOT NULL DEFAULT 0,				#类型
	`data1` INT(4) UNSIGNED NOT NULL DEFAULT 0,				#自定义数据1
	`data2` INT(4) UNSIGNED NOT NULL DEFAULT 0,				#自定义数据2
	`data3` INT(4) UNSIGNED NOT NULL DEFAULT 0,				#自定义数据3
	`data4` INT(4) UNSIGNED NOT NULL DEFAULT 0,				#自定义数据4
	`data5` INT(4) UNSIGNED NOT NULL DEFAULT 0,				#自定义数据5
	`str` CHAR(255) NOT NULL DEFAULT '',						#字符串
	`desc`	CHAR(32) NOT NULL DEFAULT '',						#配置项描述
    PRIMARY KEY (`id`)
) ENGINE=MyISAM;

DROP TABLE IF EXISTS `gs_role_type`;
CREATE TABLE `gs_role_type`  (
	`id` INT(4) UNSIGNED NOT NULL AUTO_INCREMENT,				#序列号
	`name` CHAR(16) NOT NULL DEFAULT '',						#名字
	`gender` TINYINT NOT NULL DEFAULT 0,						#性别
	`profession` INT(4) UNSIGNED NOT NULL DEFAULT 0,			#职业
	`base_level` INT(4) UNSIGNED NOT NULL DEFAULT 0,			#基础等级
	`max_level` INT(4) UNSIGNED NOT NULL DEFAULT 0,			#最大等级
	`length` FLOAT NOT NULL DEFAULT 0,						#长度
	`width` FLOAT NOT NULL DEFAULT 0,							#宽度
	`height` FLOAT NOT NULL DEFAULT 0,							#高度
	`base_life` INT(4) UNSIGNED NOT NULL DEFAULT 0,			#基础生命值
	`base_mana` INT(4) UNSIGNED NOT NULL DEFAULT 0,			#基础法力值
	`base_speed` FLOAT NOT NULL DEFAULT 0,					#基础移动速度
    PRIMARY KEY (`id`)
) ENGINE=MyISAM;

DROP TABLE IF EXISTS `gs_scene`;
CREATE TABLE `gs_scene` (
  `id` INT(4) UNSIGNED NOT NULL DEFAULT 0,					#地图ID
  `name` CHAR(15) DEFAULT '未命名',								#地图名
  `mapdoc` INT(4) UNSIGNED NOT NULL DEFAULT 0,				#地图显示模型ID
  `type` BIGINT UNSIGNED NOT NULL DEFAULT 0,					#地图类型（按位掩码）
  `type2` BIGINT UNSIGNED NOT NULL DEFAULT 0,					#地图类型2（按位掩码）
  `sort` INT(4) UNSIGNED NOT NULL DEFAULT 0,					#地图种类
  `portal0_x` FLOAT NOT NULL DEFAULT 0,						#入口0的X坐标
  `portal0_y` FLOAT NOT NULL DEFAULT 0,						#入口0的Y坐标
  `portal0_z` FLOAT NOT NULL DEFAULT 0,						#入口0的Z坐标
  `reborn_map` INT(4) UNSIGNED  DEFAULT 0,						#复活地图ID
  `link_map` INT(4) UNSIGNED  NOT NULL DEFAULT 0,				#链接地图ID
  `link_x` FLOAT NOT NULL DEFAULT 0,							#链接地图的X坐标
  `link_y` FLOAT NOT NULL DEFAULT 0,							#链接地图的Y坐标
  `link_z` FLOAT NOT NULL DEFAULT 0,							#链接地图的Z坐标
  `flag` INT(4) UNSIGNED NOT NULL DEFAULT 0,					#标志位
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM;

DROP TABLE IF EXISTS `gs_user`;
CREATE TABLE `gs_user`  (
	`id` BIGINT UNSIGNED NOT NULL AUTO_INCREMENT,				#序列号
	`name` CHAR(16) NOT NULL DEFAULT '',						#名字
	`account_id` BIGINT UNSIGNED NOT NULL DEFAULT 0,			#账号ID
	`role_type` INT(4) UNSIGNED NOT NULL DEFAULT 0,			#角色类型
	`level` INT(4) UNSIGNED NOT NULL DEFAULT 0,				#等级
	`exp` BIGINT(4) UNSIGNED NOT NULL DEFAULT 0,				#经验值
	`length` FLOAT  NOT NULL DEFAULT 0,						#长度
	`width` FLOAT NOT NULL DEFAULT 0,							#宽度
	`height` FLOAT NOT NULL DEFAULT 0,							#高度
	`scene_id` INT(4) NOT NULL DEFAULT 0,						#地图ID
	`pos_x` FLOAT NOT NULL DEFAULT 0,							#x坐标
	`pos_y` FLOAT NOT NULL DEFAULT 0,							#y坐标
	`pos_z` FLOAT NOT NULL DEFAULT 0,							#z坐标
	`record_scene_id` INT(4) UNSIGNED NOT NULL DEFAULT 0,	#记录地图ID
	`record_x` FLOAT NOT NULL DEFAULT 0,						#记录x坐标
	`record_y` FLOAT NOT NULL DEFAULT 0,						#记录y坐标
	`record_z` FLOAT NOT NULL DEFAULT 0,						#记录z坐标
	`life` INT(4) UNSIGNED NOT NULL DEFAULT 0,				#生命值
	`mana` INT(4) UNSIGNED NOT NULL DEFAULT 0,				#法力值
    PRIMARY KEY (`id`),
	UNIQUE INDEX(`name`)
) ENGINE=MyISAM;

/* DROP TABLE IF EXISTS `gs_magic_type`;
CREATE TABLE `gs_magic_type`  (
	`id` BIGINT UNSIGNED NOT NULL,								#序列号
	`name` CHAR(16) NOT NULL DEFAULT '',						#名字
	`sort` INT(4) UNSIGNED NOT NULL DEFAULT 0,				#施法类型（瞬发，吟唱，引导，触发等）
	`begin_delay_ms` INT(4) UNSIGNED NOT NULL DEFAULT 0,		#前摇(毫秒)
	`end_delay_ms` INT(4) UNSIGNED NOT NULL DEFAULT 0,		#后摇(毫秒)
	`cool_down_ms` INT(4) UNSIGNED NOT NULL DEFAULT 0,		#冷却时间(毫秒)
	`hit_rate` INT(4) UNSIGNED NOT NULL DEFAULT 0,			#命中率
	`cost_type1` INT(4) UNSIGNED NOT NULL DEFAULT 0,			#技能消耗类型1(hp，hp百分比，mp，mp百分比等)
	`cost_value1` INT(4) UNSIGNED NOT NULL DEFAULT 0,		#技能消耗值1
	`cost_type2` INT(4) UNSIGNED NOT NULL DEFAULT 0,			#技能消耗类型2(hp，hp百分比，mp，mp百分比等)
	`cost_value2` INT(4) UNSIGNED NOT NULL DEFAULT 0,		#技能消耗值2
	`target_type` INT(4) UNSIGNED  NOT NULL DEFAULT 0,		#目标类型(对地，对角色，对自己，对玩家，对怪，对空等)
	`range_type` INT(4) UNSIGNED NOT NULL DEFAULT 0,			#范围类型(球形，线型，单体等)
	`range_data1` FLOAT NOT NULL DEFAULT 0,					#范围数值1
	`range_data2` FLOAT NOT NULL DEFAULT 0,					#范围数值2
	`damage_type1` INT(4) UNSIGNED NOT NULL DEFAULT 0,		#伤害类型1（物理，魔法，真实）
	`addition_type1` INT(4) UNSIGNED NOT NULL DEFAULT 0,		#伤害加成类型1(物理强度加成，魔法强度加成)
	`damage_attr1` INT(4) UNSIGNED NOT NULL DEFAULT 0,		#伤害的属性1(hp，hp百分比，mp，mp百分比等)
	`damage_value1` INT(4) UNSIGNED NOT NULL DEFAULT 0,		#伤害值1
	`damage_type2` INT(4) UNSIGNED NOT NULL DEFAULT 0,		#伤害类型2（物理，魔法，真实）
	`addition_type2` INT(4) UNSIGNED NOT NULL DEFAULT 0,		#伤害加成类型2(物理强度加成，魔法强度加成)
	`damage_attr2` INT(4) UNSIGNED NOT NULL DEFAULT 0,		#伤害的属性2(hp，hp百分比，mp，mp百分比等)
	`damage_value2` INT(4) UNSIGNED NOT NULL DEFAULT 0,		#伤害值2
	`atker_track` INT(4) UNSIGNED NOT NULL DEFAULT 0,		#施法者移动轨迹
	`victim_track` INT(4) UNSIGNED NOT NULL DEFAULT 0,		#受击者移动轨迹
	`status_id` INT(4) UNSIGNED NOT NULL DEFAULT 0,			#触发状态ID
	`status_rate` INT(4) UNSIGNED NOT NULL DEFAULT 0,		#触发状态的概率
	`next_magic_type` INT(4) UNSIGNED NOT NULL DEFAULT 0,	#触发技能ID
	`next_magic_rate` INT(4) UNSIGNED NOT NULL DEFAULT 0,	#触发技能的概率
    PRIMARY KEY (`id`)
) ENGINE=MyISAM;

DROP TABLE IF EXISTS `gs_status_type`;
CREATE TABLE `gs_status_type`  (
	`id` BIGINT UNSIGNED NOT NULL,								#序列号
	`name` CHAR(16) NOT NULL DEFAULT '',						#名字
	`status_type` INT(4) UNSIGNED NOT NULL DEFAULT 0,		#效果(晕眩，迷惑，沉默，禁锢等)
	`hit_rate`	INT(4) UNSIGNED NOT NULL DEFAULT 0,			#命中率
	`duration` INT(4) UNSIGNED NOT NULL DEFAULT 0,			#状态持续时间
	`hit_times` INT(4) UNSIGNED NOT NULL DEFAULT 0,			#触发次数
	`power_type` INT(4) UNSIGNED NOT NULL DEFAULT 0,			#产生的效果类型
	`power_value`	INT(4) UNSIGNED NOT NULL DEFAULT 0,		#产生的效果数值
	`power_add_type` INT(4) UNSIGNED NOT NULL DEFAULT 0,		#效果加成类型
	`power_add_value` INT(4) UNSIGNED NOT NULL DEFAULT 0,	#效果加成数值
	`next_status`	INT(4) UNSIGNED NOT NULL DEFAULT 0,		#触发的状态
	`next_status_rate` INT(4) UNSIGNED NOT NULL DEFAULT 0,	#状态触发概率
	`next_magic_type` INT(4) UNSIGNED NOT NULL DEFAULT 0,	#触发技能ID
	`next_magic_rate` INT(4) UNSIGNED NOT NULL DEFAULT 0,	#触发技能的概率
    PRIMARY KEY (`id`)
) ENGINE=MyISAM;

DROP TABLE IF EXISTS `gs_track_type`;
CREATE TABLE `gs_track_type`  (
	`id` BIGINT UNSIGNED NOT NULL,								#序列号
	`dir_type`	INT(4) UNSIGNED NOT NULL DEFAULT 0,			#方向类型（相对，绝对）
	`dir_x` FLOAT NOT NULL DEFAULT 0,							#方向X
	`dir_y` FLOAT NOT NULL DEFAULT 0,							#方向Y
	`dir_z` FLOAT NOT NULL DEFAULT 0,							#方向Z
	`speed` INT(4) UNSIGNED NOT NULL DEFAULT 0,				#移动速度
	`duration` INT(4) UNSIGNED NOT NULL DEFAULT 0,			#持续时间
	`next_track` INT(4) UNSIGNED NOT NULL DEFAULT 0,			#触发的轨迹
	`next_track_rate` INT(4) UNSIGNED NOT NULL DEFAULT 0,	#轨迹触发的概率
    PRIMARY KEY (`id`)
) ENGINE=MyISAM;

DROP TABLE IF EXISTS `gs_damage_type`;
CREATE TABLE `gs_damage_type`  (
	`id` BIGINT UNSIGNED NOT NULL,								#序列号
	`sort`	INT(4) UNSIGNED NOT NULL DEFAULT 0,				#伤害类型（物理，魔法，真实等）
	`power_add_type` INT(4) UNSIGNED NOT NULL DEFAULT 0,		#伤害加成类型
	`power_add_value` INT(4) UNSIGNED NOT NULL DEFAULT 0,	#伤害加成值
	`affect_attr` INT(4) UNSIGNED NOT NULL DEFAULT 0,		#影响的属性
	`power_value` INT(4) UNSIGNED NOT NULL DEFAULT 0,		#伤害值
	`next_damage` INT(4) UNSIGNED NOT NULL DEFAULT 0,		#触发的伤害ID
	`next_damage_rate` INT(4) UNSIGNED NOT NULL DEFAULT 0,	#触发伤害的概率
    PRIMARY KEY (`id`)
) ENGINE=MyISAM; */

DROP TABLE IF EXISTS `gs_magic_type`;
CREATE TABLE `gs_magic_type`  (
	`id` BIGINT UNSIGNED NOT NULL,								#序列号
	`name` CHAR(16) NOT NULL DEFAULT '',						#名字
	`role_type` INT(4) UNSIGNED NOT NULL DEFAULT 0,			#学习技能的角色类型
	`cast_type` INT(4) UNSIGNED NOT NULL DEFAULT 0,			#施法类型（吟唱,瞬发）
	`begin_delay_ms` INT(4) UNSIGNED NOT NULL DEFAULT 0,		#前摇(毫秒)
	`end_delay_ms` INT(4) UNSIGNED NOT NULL DEFAULT 0,		#后摇(毫秒)
	`cool_down_ms` INT(4) UNSIGNED NOT NULL DEFAULT 0,		#冷却时间(毫秒)
	`cost_type1` INT(4) UNSIGNED NOT NULL DEFAULT 0,			#技能消耗类型1(hp，hp百分比，mp，mp百分比等)
	`cost_value1` INT(4) UNSIGNED NOT NULL DEFAULT 0,		#技能消耗值1
	`cost_type2` INT(4) UNSIGNED NOT NULL DEFAULT 0,			#技能消耗类型2(hp，hp百分比，mp，mp百分比等)
	`cost_value2` INT(4) UNSIGNED NOT NULL DEFAULT 0,		#技能消耗值2
	`range_distance` FLOAT NOT NULL DEFAULT 0,				#技能距离
	`target_type` INT(4) UNSIGNED  NOT NULL DEFAULT 0,		#目标类型(对地，对角色，对自己，对玩家，对怪，对空等)
	`range_type` INT(4) UNSIGNED NOT NULL DEFAULT 0,			#范围类型(球形，线型，单体等)
	`range_x` FLOAT NOT NULL DEFAULT 0,						#范围x
	`range_y` FLOAT NOT NULL DEFAULT 0,						#范围y
	`damage_id` INT(4) UNSIGNED NOT NULL DEFAULT 0,			#伤害ID
	`atker_distance` INT(4) UNSIGNED NOT NULL DEFAULT 0,		#施法者移动距离
	`atker_duration` INT(4) UNSIGNED NOT NULL DEFAULT 0,		#施法者移动时间
	`victim_distance` INT(4) UNSIGNED NOT NULL DEFAULT 0,	#受击者移动距离
	`victim_duration` INT(4) UNSIGNED NOT NULL DEFAULT 0,	#受击者移动时间
	`status_id` INT(4) UNSIGNED NOT NULL DEFAULT 0,			#触发状态ID
	`status_rate` INT(4) UNSIGNED NOT NULL DEFAULT 0,		#触发状态的概率
    PRIMARY KEY (`id`)
) ENGINE=MyISAM;

DROP TABLE IF EXISTS `gs_magic`;
CREATE TABLE `gs_magic`  (
	`id` BIGINT UNSIGNED NOT NULL,								#序列号
	`owner_id` BIGINT UNSIGNED NOT NULL DEFAULT 0,			#拥有者ID
	`magic_type` BIGINT UNSIGNED NOT NULL DEFAULT 0,			#magic_type_id
	`exp` INT(4) UNSIGNED NOT NULL DEFAULT 0,					#熟练度
    PRIMARY KEY (`id`),
	INDEX (`owner_id`)
) ENGINE=MyISAM;

DROP TABLE IF EXISTS `gs_npc_magic`;
CREATE TABLE `gs_npc_magic`  (
	`id` BIGINT UNSIGNED NOT NULL,								#序列号
	`npc_type` BIGINT UNSIGNED NOT NULL DEFAULT 0,			#NPC类型ID
	`magic_type` BIGINT UNSIGNED NOT NULL DEFAULT 0,			#magic_type_id
	`cast_rule` INT(4) UNSIGNED NOT NULL DEFAULT 0,			#释放规则
	`cast_rule_data` INT(4) UNSIGNED NOT NULL DEFAULT 0,		#释放规则参数
    PRIMARY KEY (`id`),
	INDEX (`npc_type`)
) ENGINE=MyISAM;

DROP TABLE IF EXISTS `gs_status_type`;
CREATE TABLE `gs_status_type`  (
	`id` BIGINT UNSIGNED NOT NULL,								#序列号
	`name` CHAR(16) NOT NULL DEFAULT '',						#名字
	`status_type` INT(4) UNSIGNED NOT NULL DEFAULT 0,		#效果(晕眩，迷惑，沉默，禁锢等)
	`hit_rate`	INT(4) UNSIGNED NOT NULL DEFAULT 0,			#命中率
	`duration` INT(4) UNSIGNED NOT NULL DEFAULT 0,			#状态持续时间
	`hit_times` INT(4) UNSIGNED NOT NULL DEFAULT 0,			#触发次数
	`power_type` INT(4) UNSIGNED NOT NULL DEFAULT 0,			#产生的效果类型
	`power_value`	INT(4) UNSIGNED NOT NULL DEFAULT 0,		#产生的效果数值
    PRIMARY KEY (`id`)
) ENGINE=MyISAM;

