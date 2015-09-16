##############################################################
# Describe: 初始提交
# Author: Fu Yan
##############################################################
INSERT INTO `gs_config`(`type`, `data1`,`desc`) VALUES(1000, 1507141330, '开服时间');
INSERT INTO `gs_role_type`(`name`, `profession`, `base_level`, `max_level`, `length`, `width`, `height`, `base_life`, `base_mana`, `base_speed`) VALUES('战士男', 1000, 1, 300, 40, 30, 200, 500, 200, 120);
INSERT INTO `gs_scene`(`id`, `name`, `mapdoc`, `portal0_x`, `portal0_y`, `portal0_z`, `reborn_map`, `flag`) VALUES(1000, '主城', 1000, 100, 100, 100, 1000, 0);