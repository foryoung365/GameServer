////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author: 	Fu Yan
// Created: 	2015-07-06
// Describe: 	Specailized SQL structure of table @tblname, 
//				generate by genSsqls.py, !!!DO NOT EDIT!!!
////////////////////////////////////////////////////////////////////////
#ifndef _USER_DATA_H_
#define _USER_DATA_H_

#include <mysql++.h>
#include <ssqls.h>

using namespace mysqlpp;

struct CUserData; 

    enum CUserData_enum { 
    USERDATA_NAME,
    USERDATA_MATE,
    USERDATA_LOOKFACE,
    USERDATA_HAIR,
    USERDATA_LENGTH,
    USERDATA_FAT,
    USERDATA_MONEY,
    USERDATA_MONEY_SAVED,
    USERDATA_TASK_DATA,
    USERDATA_LEVEL,
    USERDATA_EXP,
    USERDATA_POWER,
    USERDATA_CONSTITUTION,
    USERDATA_DEXTERITY,
    USERDATA_SPEED,
    USERDATA_HEALTH,
    USERDATA_SOUL,
    USERDATA_ADDITIONAL_POINT,
    USERDATA_AUTO_ALLOT,
    USERDATA_LIFE,
    USERDATA_MANA,
    USERDATA_PROFESSION,
    USERDATA_POTENTIAL,
    USERDATA_PK,
    USERDATA_NOBILITY,
    USERDATA_MEDAL,
    USERDATA_MEDAL_SELECT,
    USERDATA_METEMPSYCHOSIS,
    USERDATA_SYNDICATE_ID,
    USERDATA_RECORDMAP_ID,
    USERDATA_RECORDX,
    USERDATA_RECORDY,
    USERDATA_ACCOUNT_ID,
    USERDATA_ID,
    USERDATA_LAST_LOGIN,
    USERDATA_ACCOUNT,
    USERDATA_PASSWORD,
    USERDATA_TASK_MASK,
    USERDATA_TIME_OF_LIFE,
    USERDATA_VIRTUE,
    USERDATA_HOME_ID,
    USERDATA_TITLE,
    USERDATA_TITLE_SELECT,
    USERDATA_TUTOR_EXP,
    USERDATA_TUTOR_LEVEL,
    USERDATA_MAXLIFE_PERCENT,
    USERDATA_MERCENARY_RANK,
    USERDATA_MERCENARY_EXP,
    USERDATA_NOBILITY_RANK,
    USERDATA_EXPLOIT,
    USERDATA_EUD_PACK_SIZE,
    USERDATA_DISABLEFLAG,
    USERDATA_REG_TIME,
    USERDATA_ACCU_ONLINE_TIME,
    USERDATA_ACCU_OFFLINE_TIME,
    USERDATA_LAST_LOGOUT,
    USERDATA_PROMPT_VER,
    USERDATA_FRIEND_SHARE,
    USERDATA_LOGIN_TIME,
    USERDATA_LOGIN_IP,
    USERDATA_SOUL_VALUE,
    USERDATA_BROOD_TIMES,
    USERDATA_EMONEY,
    USERDATA_CHK_SUM,
    USERDATA_ELOCK,
    USERDATA_EXPBALLUSAGE,
    USERDATA_EXPCRYSTALUSAGE,
    USERDATA_CHEAT_TIME,
    USERDATA_ONLINE_TIME,
    USERDATA_AUTO_EXERCISE,
    USERDATA_HUNG_LAST_LOGOUT,
    USERDATA_GOD_STATUS,
    USERDATA_BIG_PRIZE_FAILS,
    USERDATA_SMALL_PRIZE_FAILS,
    USERDATA_BONUS_POINTS,
    USERDATA_FLOWER,
    USERDATA_FLOWER_W,
    USERDATA_FLOWER_P,
    USERDATA_INCOME,
    USERDATA_ILLU_BUTTERFLY,
    USERDATA_ILLU_FISH,
    USERDATA_ILLU_SHELL,
    USERDATA_ILLU_HERBAL,
    USERDATA_ILLU_ORE,
    USERDATA_PASSWORD_ID,
    USERDATA_QUIZ_POINT,
    USERDATA_PROTECT_STATE,
    USERDATA_DONATION,
    USERDATA_WOOD,
    USERDATA_STONE,
    USERDATA_TODO_LIST_MASK1,
    USERDATA_TODO_LIST1,
    USERDATA_TODO_LIST_HEX1,
    USERDATA_COACH,
    USERDATA_COACH_TIME,
    USERDATA_COACH_DEED,
    USERDATA_COACH_DATE,
    USERDATA_EXTRA_HATCH_SIZE,
    USERDATA_SHADINESS_MONEY,
    USERDATA_SHADINESS_EMONEY,
    USERDATA_SOUL_VALUE_LEV,
    USERDATA_BUSINESS,
    USERDATA_EMONEY2,
    USERDATA_TYPE,
    USERDATA_GOD_STRENGTH,
    USERDATA_GOD_LEVEL,
    USERDATA_DEIFICATION,
    USERDATA_TMONEY,
    USERDATA_DEMON_LEVEL,
    USERDATA_DEMON_EXP,
    USERDATA_SOCIALCLASS,
    USERDATA_CREDIT_POINT,
    USERDATA_CREDIT_LIMIT,
    USERDATA_CREDIT_RETURN,
    USERDATA_EUDKERNEL_ID,
    USERDATA_REFINERY_TIME_END,
    USERDATA_PACK_ADD,
    USERDATA_BOUNDARY_LEV,
    USERDATA_BOUNDARY_EXP,
    USERDATA_OFFER_POINT,
    USERDATA_BATTLE_LEV,
    USERDATA_CHANNEL_ACCOUNT,
    USERDATA_RECHARGE_EMONEY,
    USERDATA_AUTO_BATTLE_TIME,
    USERDATA_FIRST_RECHARGE,
    USERDATA_SPECIAL_FLAG,
    USERDATA_VIP_LEV,
    USERDATA_GHOSTTOEXP_AMOUNT,
    USERDATA_VIGOR,
    USERDATA_FUNC_LIST,
    USERDATA_NULL 
    }; 

    template <class Manip>
    class CUserData_value_list { 
    public: 
    const CUserData* obj;
    const char* delim;
    Manip manip;
    public: 
    CUserData_value_list (const CUserData* o, const char* d, Manip m) :
    obj(o), delim(d), manip(m) { } 
    };

    template <class Manip>
    class CUserData_field_list {
    public: 
    const CUserData* obj; 
    const char* delim;
    Manip manip;
    public: 
    CUserData_field_list (const CUserData* o, const char* d, Manip m) :
    obj(o), delim(d), manip(m) { } 
    };

    template <class Manip>
    class CUserData_equal_list { 
    public: 
    const CUserData* obj;
    const char* delim;
    const char* comp;
    Manip manip;
    public: 
    CUserData_equal_list (const CUserData* o, const char* d, const char* c, Manip m) :
    obj(o), delim(d), comp(c), manip(m) { }
    };

    template <class Manip>
    class CUserData_cus_value_list {
    public:
    const CUserData* obj;
    std::vector<bool> *include;
    bool del_vector;
    const char* delim;
    Manip manip;
    public: 
    ~CUserData_cus_value_list () {if (del_vector) delete include;} 
    CUserData_cus_value_list (const CUserData* o, const char* d, Manip m, bool i1, bool i2, bool i3, bool i4, bool i5, bool i6, bool i7, bool i8, bool i9, bool i10, bool i11, bool i12, bool i13, bool i14, bool i15, bool i16, bool i17, bool i18, bool i19, bool i20, bool i21, bool i22, bool i23, bool i24, bool i25, bool i26, bool i27, bool i28, bool i29, bool i30, bool i31, bool i32, bool i33, bool i34, bool i35, bool i36, bool i37, bool i38, bool i39, bool i40, bool i41, bool i42, bool i43, bool i44, bool i45, bool i46, bool i47, bool i48, bool i49, bool i50, bool i51, bool i52, bool i53, bool i54, bool i55, bool i56, bool i57, bool i58, bool i59, bool i60, bool i61, bool i62, bool i63, bool i64, bool i65, bool i66, bool i67, bool i68, bool i69, bool i70, bool i71, bool i72, bool i73, bool i74, bool i75, bool i76, bool i77, bool i78, bool i79, bool i80, bool i81, bool i82, bool i83, bool i84, bool i85, bool i86, bool i87, bool i88, bool i89, bool i90, bool i91, bool i92, bool i93, bool i94, bool i95, bool i96, bool i97, bool i98, bool i99, bool i100, bool i101, bool i102, bool i103, bool i104, bool i105, bool i106, bool i107, bool i108, bool i109, bool i110, bool i111, bool i112, bool i113, bool i114, bool i115, bool i116, bool i117, bool i118, bool i119, bool i120, bool i121, bool i122, bool i123, bool i124, bool i125, bool i126, bool i127, bool i128, bool i129, bool i130);
    CUserData_cus_value_list (const CUserData* o, const char* d, Manip m, CUserData_enum i1, CUserData_enum i2, CUserData_enum i3, CUserData_enum i4, CUserData_enum i5, CUserData_enum i6, CUserData_enum i7, CUserData_enum i8, CUserData_enum i9, CUserData_enum i10, CUserData_enum i11, CUserData_enum i12, CUserData_enum i13, CUserData_enum i14, CUserData_enum i15, CUserData_enum i16, CUserData_enum i17, CUserData_enum i18, CUserData_enum i19, CUserData_enum i20, CUserData_enum i21, CUserData_enum i22, CUserData_enum i23, CUserData_enum i24, CUserData_enum i25, CUserData_enum i26, CUserData_enum i27, CUserData_enum i28, CUserData_enum i29, CUserData_enum i30, CUserData_enum i31, CUserData_enum i32, CUserData_enum i33, CUserData_enum i34, CUserData_enum i35, CUserData_enum i36, CUserData_enum i37, CUserData_enum i38, CUserData_enum i39, CUserData_enum i40, CUserData_enum i41, CUserData_enum i42, CUserData_enum i43, CUserData_enum i44, CUserData_enum i45, CUserData_enum i46, CUserData_enum i47, CUserData_enum i48, CUserData_enum i49, CUserData_enum i50, CUserData_enum i51, CUserData_enum i52, CUserData_enum i53, CUserData_enum i54, CUserData_enum i55, CUserData_enum i56, CUserData_enum i57, CUserData_enum i58, CUserData_enum i59, CUserData_enum i60, CUserData_enum i61, CUserData_enum i62, CUserData_enum i63, CUserData_enum i64, CUserData_enum i65, CUserData_enum i66, CUserData_enum i67, CUserData_enum i68, CUserData_enum i69, CUserData_enum i70, CUserData_enum i71, CUserData_enum i72, CUserData_enum i73, CUserData_enum i74, CUserData_enum i75, CUserData_enum i76, CUserData_enum i77, CUserData_enum i78, CUserData_enum i79, CUserData_enum i80, CUserData_enum i81, CUserData_enum i82, CUserData_enum i83, CUserData_enum i84, CUserData_enum i85, CUserData_enum i86, CUserData_enum i87, CUserData_enum i88, CUserData_enum i89, CUserData_enum i90, CUserData_enum i91, CUserData_enum i92, CUserData_enum i93, CUserData_enum i94, CUserData_enum i95, CUserData_enum i96, CUserData_enum i97, CUserData_enum i98, CUserData_enum i99, CUserData_enum i100, CUserData_enum i101, CUserData_enum i102, CUserData_enum i103, CUserData_enum i104, CUserData_enum i105, CUserData_enum i106, CUserData_enum i107, CUserData_enum i108, CUserData_enum i109, CUserData_enum i110, CUserData_enum i111, CUserData_enum i112, CUserData_enum i113, CUserData_enum i114, CUserData_enum i115, CUserData_enum i116, CUserData_enum i117, CUserData_enum i118, CUserData_enum i119, CUserData_enum i120, CUserData_enum i121, CUserData_enum i122, CUserData_enum i123, CUserData_enum i124, CUserData_enum i125, CUserData_enum i126, CUserData_enum i127, CUserData_enum i128, CUserData_enum i129, CUserData_enum i130); 
    CUserData_cus_value_list (const CUserData* o, const char* d, Manip m ,std::vector<bool>* i) :
    obj(o), include(i), del_vector(false), delim(d), manip(m) { }
    };

    template <class Manip>
    class CUserData_cus_field_list { 
    public:
    const CUserData* obj; 
    std::vector<bool> *include; 
    bool del_vector; 
    const char* delim;
    Manip manip;
    public: 
    ~CUserData_cus_field_list () {if (del_vector) delete include;} 
    CUserData_cus_field_list (const CUserData* o, const char* d, Manip m, bool i1, bool i2, bool i3, bool i4, bool i5, bool i6, bool i7, bool i8, bool i9, bool i10, bool i11, bool i12, bool i13, bool i14, bool i15, bool i16, bool i17, bool i18, bool i19, bool i20, bool i21, bool i22, bool i23, bool i24, bool i25, bool i26, bool i27, bool i28, bool i29, bool i30, bool i31, bool i32, bool i33, bool i34, bool i35, bool i36, bool i37, bool i38, bool i39, bool i40, bool i41, bool i42, bool i43, bool i44, bool i45, bool i46, bool i47, bool i48, bool i49, bool i50, bool i51, bool i52, bool i53, bool i54, bool i55, bool i56, bool i57, bool i58, bool i59, bool i60, bool i61, bool i62, bool i63, bool i64, bool i65, bool i66, bool i67, bool i68, bool i69, bool i70, bool i71, bool i72, bool i73, bool i74, bool i75, bool i76, bool i77, bool i78, bool i79, bool i80, bool i81, bool i82, bool i83, bool i84, bool i85, bool i86, bool i87, bool i88, bool i89, bool i90, bool i91, bool i92, bool i93, bool i94, bool i95, bool i96, bool i97, bool i98, bool i99, bool i100, bool i101, bool i102, bool i103, bool i104, bool i105, bool i106, bool i107, bool i108, bool i109, bool i110, bool i111, bool i112, bool i113, bool i114, bool i115, bool i116, bool i117, bool i118, bool i119, bool i120, bool i121, bool i122, bool i123, bool i124, bool i125, bool i126, bool i127, bool i128, bool i129, bool i130); 
    CUserData_cus_field_list (const CUserData* o, const char* d, Manip m, CUserData_enum i1, CUserData_enum i2, CUserData_enum i3, CUserData_enum i4, CUserData_enum i5, CUserData_enum i6, CUserData_enum i7, CUserData_enum i8, CUserData_enum i9, CUserData_enum i10, CUserData_enum i11, CUserData_enum i12, CUserData_enum i13, CUserData_enum i14, CUserData_enum i15, CUserData_enum i16, CUserData_enum i17, CUserData_enum i18, CUserData_enum i19, CUserData_enum i20, CUserData_enum i21, CUserData_enum i22, CUserData_enum i23, CUserData_enum i24, CUserData_enum i25, CUserData_enum i26, CUserData_enum i27, CUserData_enum i28, CUserData_enum i29, CUserData_enum i30, CUserData_enum i31, CUserData_enum i32, CUserData_enum i33, CUserData_enum i34, CUserData_enum i35, CUserData_enum i36, CUserData_enum i37, CUserData_enum i38, CUserData_enum i39, CUserData_enum i40, CUserData_enum i41, CUserData_enum i42, CUserData_enum i43, CUserData_enum i44, CUserData_enum i45, CUserData_enum i46, CUserData_enum i47, CUserData_enum i48, CUserData_enum i49, CUserData_enum i50, CUserData_enum i51, CUserData_enum i52, CUserData_enum i53, CUserData_enum i54, CUserData_enum i55, CUserData_enum i56, CUserData_enum i57, CUserData_enum i58, CUserData_enum i59, CUserData_enum i60, CUserData_enum i61, CUserData_enum i62, CUserData_enum i63, CUserData_enum i64, CUserData_enum i65, CUserData_enum i66, CUserData_enum i67, CUserData_enum i68, CUserData_enum i69, CUserData_enum i70, CUserData_enum i71, CUserData_enum i72, CUserData_enum i73, CUserData_enum i74, CUserData_enum i75, CUserData_enum i76, CUserData_enum i77, CUserData_enum i78, CUserData_enum i79, CUserData_enum i80, CUserData_enum i81, CUserData_enum i82, CUserData_enum i83, CUserData_enum i84, CUserData_enum i85, CUserData_enum i86, CUserData_enum i87, CUserData_enum i88, CUserData_enum i89, CUserData_enum i90, CUserData_enum i91, CUserData_enum i92, CUserData_enum i93, CUserData_enum i94, CUserData_enum i95, CUserData_enum i96, CUserData_enum i97, CUserData_enum i98, CUserData_enum i99, CUserData_enum i100, CUserData_enum i101, CUserData_enum i102, CUserData_enum i103, CUserData_enum i104, CUserData_enum i105, CUserData_enum i106, CUserData_enum i107, CUserData_enum i108, CUserData_enum i109, CUserData_enum i110, CUserData_enum i111, CUserData_enum i112, CUserData_enum i113, CUserData_enum i114, CUserData_enum i115, CUserData_enum i116, CUserData_enum i117, CUserData_enum i118, CUserData_enum i119, CUserData_enum i120, CUserData_enum i121, CUserData_enum i122, CUserData_enum i123, CUserData_enum i124, CUserData_enum i125, CUserData_enum i126, CUserData_enum i127, CUserData_enum i128, CUserData_enum i129, CUserData_enum i130); 
    CUserData_cus_field_list (const CUserData* o, const char* d, Manip m, std::vector<bool> *i) :
    obj(o), include(i), del_vector(false), delim(d), manip(m) { }
    };

    template <class Manip>
    class CUserData_cus_equal_list {
    public:
    const CUserData* obj;
    std::vector<bool> *include;
    bool del_vector;
    const char* delim;
    const char* comp;
    Manip manip;
    public:
    ~CUserData_cus_equal_list () {if (del_vector) delete include;}
    CUserData_cus_equal_list (const CUserData* o, const char* d, const char* c, Manip m, bool i1, bool i2, bool i3, bool i4, bool i5, bool i6, bool i7, bool i8, bool i9, bool i10, bool i11, bool i12, bool i13, bool i14, bool i15, bool i16, bool i17, bool i18, bool i19, bool i20, bool i21, bool i22, bool i23, bool i24, bool i25, bool i26, bool i27, bool i28, bool i29, bool i30, bool i31, bool i32, bool i33, bool i34, bool i35, bool i36, bool i37, bool i38, bool i39, bool i40, bool i41, bool i42, bool i43, bool i44, bool i45, bool i46, bool i47, bool i48, bool i49, bool i50, bool i51, bool i52, bool i53, bool i54, bool i55, bool i56, bool i57, bool i58, bool i59, bool i60, bool i61, bool i62, bool i63, bool i64, bool i65, bool i66, bool i67, bool i68, bool i69, bool i70, bool i71, bool i72, bool i73, bool i74, bool i75, bool i76, bool i77, bool i78, bool i79, bool i80, bool i81, bool i82, bool i83, bool i84, bool i85, bool i86, bool i87, bool i88, bool i89, bool i90, bool i91, bool i92, bool i93, bool i94, bool i95, bool i96, bool i97, bool i98, bool i99, bool i100, bool i101, bool i102, bool i103, bool i104, bool i105, bool i106, bool i107, bool i108, bool i109, bool i110, bool i111, bool i112, bool i113, bool i114, bool i115, bool i116, bool i117, bool i118, bool i119, bool i120, bool i121, bool i122, bool i123, bool i124, bool i125, bool i126, bool i127, bool i128, bool i129, bool i130); 
    CUserData_cus_equal_list (const CUserData* o, const char* d, const char* c, Manip m, CUserData_enum i1, CUserData_enum i2, CUserData_enum i3, CUserData_enum i4, CUserData_enum i5, CUserData_enum i6, CUserData_enum i7, CUserData_enum i8, CUserData_enum i9, CUserData_enum i10, CUserData_enum i11, CUserData_enum i12, CUserData_enum i13, CUserData_enum i14, CUserData_enum i15, CUserData_enum i16, CUserData_enum i17, CUserData_enum i18, CUserData_enum i19, CUserData_enum i20, CUserData_enum i21, CUserData_enum i22, CUserData_enum i23, CUserData_enum i24, CUserData_enum i25, CUserData_enum i26, CUserData_enum i27, CUserData_enum i28, CUserData_enum i29, CUserData_enum i30, CUserData_enum i31, CUserData_enum i32, CUserData_enum i33, CUserData_enum i34, CUserData_enum i35, CUserData_enum i36, CUserData_enum i37, CUserData_enum i38, CUserData_enum i39, CUserData_enum i40, CUserData_enum i41, CUserData_enum i42, CUserData_enum i43, CUserData_enum i44, CUserData_enum i45, CUserData_enum i46, CUserData_enum i47, CUserData_enum i48, CUserData_enum i49, CUserData_enum i50, CUserData_enum i51, CUserData_enum i52, CUserData_enum i53, CUserData_enum i54, CUserData_enum i55, CUserData_enum i56, CUserData_enum i57, CUserData_enum i58, CUserData_enum i59, CUserData_enum i60, CUserData_enum i61, CUserData_enum i62, CUserData_enum i63, CUserData_enum i64, CUserData_enum i65, CUserData_enum i66, CUserData_enum i67, CUserData_enum i68, CUserData_enum i69, CUserData_enum i70, CUserData_enum i71, CUserData_enum i72, CUserData_enum i73, CUserData_enum i74, CUserData_enum i75, CUserData_enum i76, CUserData_enum i77, CUserData_enum i78, CUserData_enum i79, CUserData_enum i80, CUserData_enum i81, CUserData_enum i82, CUserData_enum i83, CUserData_enum i84, CUserData_enum i85, CUserData_enum i86, CUserData_enum i87, CUserData_enum i88, CUserData_enum i89, CUserData_enum i90, CUserData_enum i91, CUserData_enum i92, CUserData_enum i93, CUserData_enum i94, CUserData_enum i95, CUserData_enum i96, CUserData_enum i97, CUserData_enum i98, CUserData_enum i99, CUserData_enum i100, CUserData_enum i101, CUserData_enum i102, CUserData_enum i103, CUserData_enum i104, CUserData_enum i105, CUserData_enum i106, CUserData_enum i107, CUserData_enum i108, CUserData_enum i109, CUserData_enum i110, CUserData_enum i111, CUserData_enum i112, CUserData_enum i113, CUserData_enum i114, CUserData_enum i115, CUserData_enum i116, CUserData_enum i117, CUserData_enum i118, CUserData_enum i119, CUserData_enum i120, CUserData_enum i121, CUserData_enum i122, CUserData_enum i123, CUserData_enum i124, CUserData_enum i125, CUserData_enum i126, CUserData_enum i127, CUserData_enum i128, CUserData_enum i129, CUserData_enum i130); 
    CUserData_cus_equal_list (const CUserData* o, const char* d, const char* c, Manip m, std::vector<bool> *i) :
    obj(o), include(i), del_vector(false), delim(d), comp(c), manip(m) { }
    };

    template <mysqlpp::sql_dummy_type dummy> int sql_compare_CUserData(const CUserData&, const CUserData&);

    struct CUserData {
    sql_varchar name;
    sql_varchar mate;
    sql_int_unsigned lookface;
    sql_smallint_unsigned hair;
    sql_tinyint length;
    sql_tinyint fat;
    sql_int_unsigned money;
    sql_bigint_unsigned money_saved;
    sql_int_unsigned task_data;
    sql_tinyint_unsigned level;
    sql_bigint exp;
    sql_smallint_unsigned power;
    sql_smallint_unsigned constitution;
    sql_smallint_unsigned dexterity;
    sql_smallint_unsigned Speed;
    sql_smallint_unsigned health;
    sql_smallint_unsigned soul;
    sql_smallint_unsigned additional_point;
    sql_tinyint_unsigned auto_allot;
    sql_int_unsigned life;
    sql_smallint_unsigned mana;
    sql_tinyint_unsigned profession;
    sql_int potential;
    sql_smallint pk;
    sql_tinyint_unsigned nobility;
    sql_varchar medal;
    sql_int_unsigned medal_select;
    sql_tinyint_unsigned metempsychosis;
    sql_int_unsigned syndicate_id;
    sql_int_unsigned recordmap_id;
    sql_smallint_unsigned recordx;
    sql_smallint_unsigned recordy;
    sql_int_unsigned account_id;
    sql_int_unsigned id;
    sql_int_unsigned last_login;
    sql_varchar account;
    sql_varchar password;
    sql_int_unsigned task_mask;
    sql_int_unsigned time_of_life;
    sql_int_unsigned virtue;
    sql_int_unsigned home_id;
    sql_varchar title;
    sql_tinyint_unsigned title_select;
    sql_int tutor_exp;
    sql_tinyint_unsigned tutor_level;
    sql_int_unsigned maxlife_percent;
    sql_tinyint_unsigned mercenary_rank;
    sql_smallint_unsigned mercenary_exp;
    sql_tinyint_unsigned nobility_rank;
    sql_int_unsigned exploit;
    sql_tinyint eud_pack_size;
    sql_int disableFlag;
    sql_int_unsigned reg_time;
    sql_tinyint_unsigned accu_online_time;
    sql_tinyint_unsigned accu_offline_time;
    sql_int_unsigned last_logout;
    sql_int_unsigned_null prompt_ver;
    sql_int_unsigned_null Friend_share;
    sql_int_unsigned_null Login_time;
    sql_int_unsigned_null Login_ip;
    sql_int_unsigned soul_value;
    sql_int_unsigned brood_times;
    sql_int_unsigned emoney;
    sql_int_unsigned chk_sum;
    sql_varchar elock;
    sql_int ExpBallUsage;
    sql_smallint_unsigned ExpCrystalUsage;
    sql_int_unsigned cheat_time;
    sql_tinyint online_time;
    sql_tinyint auto_exercise;
    sql_int_unsigned hung_last_logout;
    sql_int_unsigned god_status;
    sql_tinyint_unsigned big_prize_fails;
    sql_tinyint_unsigned small_prize_fails;
    sql_int_unsigned bonus_points;
    sql_int_unsigned_null flower;
    sql_int_unsigned flower_w;
    sql_int flower_p;
    sql_bigint income;
    sql_bigint_unsigned illu_ButterFly;
    sql_bigint_unsigned illu_Fish;
    sql_bigint_unsigned illu_Shell;
    sql_bigint_unsigned illu_Herbal;
    sql_bigint_unsigned illu_Ore;
    sql_int password_id;
    sql_int quiz_point;
    sql_tinyint_unsigned protect_state;
    sql_bigint donation;
    sql_int_unsigned wood;
    sql_int_unsigned stone;
    sql_int_unsigned todo_list_mask1;
    sql_bigint_unsigned todo_list1;
    sql_bigint_unsigned_null todo_list_hex1;
    sql_smallint_unsigned coach;
    sql_smallint_unsigned coach_time;
    sql_smallint_unsigned coach_deed;
    sql_smallint_unsigned coach_date;
    sql_tinyint_unsigned extra_hatch_size;
    sql_bigint_unsigned_null shadiness_money;
    sql_int_unsigned_null shadiness_emoney;
    sql_tinyint_unsigned soul_value_lev;
    sql_int_unsigned business;
    sql_int_unsigned emoney2;
    sql_tinyint_unsigned_null type;
    sql_bigint_unsigned_null god_strength;
    sql_tinyint_unsigned_null god_level;
    sql_tinyint_unsigned_null deification;
    sql_int_unsigned tmoney;
    sql_tinyint_unsigned_null demon_level;
    sql_bigint_unsigned_null demon_exp;
    sql_int_unsigned socialclass;
    sql_int_unsigned credit_point;
    sql_int_unsigned credit_limit;
    sql_smallint_unsigned credit_return;
    sql_int_unsigned eudkernel_id;
    sql_int_unsigned refinery_time_end;
    sql_tinyint_unsigned pack_add;
    sql_tinyint_unsigned boundary_lev;
    sql_int_unsigned boundary_exp;
    sql_int_unsigned offer_point;
    sql_int_unsigned battle_lev;
    sql_varchar channel_account;
    sql_int_unsigned recharge_emoney;
    sql_int_unsigned auto_battle_time;
    sql_int_unsigned first_recharge;
    sql_int_unsigned special_flag;
    sql_int_unsigned vip_lev;
    sql_int_unsigned ghosttoexp_amount;
    sql_int_unsigned vigor;
    sql_bigint_unsigned func_list; 
    CUserData() : table_override_(0) { }
    CUserData(const mysqlpp::Row& row);
    void set(const mysqlpp::Row &row);
    bool operator == (const CUserData &other) const 
 {return sql_compare_CUserData<mysqlpp::sql_dummy>(*this,other) == 0;} 
 bool operator != (const CUserData &other) const 
 {return sql_compare_CUserData<mysqlpp::sql_dummy>(*this,other) != 0;} 
 bool operator > (const CUserData &other) const 
 {return sql_compare_CUserData<mysqlpp::sql_dummy>(*this,other) >  0;} 
 bool operator < (const CUserData &other) const 
 {return sql_compare_CUserData<mysqlpp::sql_dummy>(*this,other) <  0;} 
 bool operator >= (const CUserData &other) const 
 {return sql_compare_CUserData<mysqlpp::sql_dummy>(*this,other) >= 0;} 
 bool operator <= (const CUserData &other) const 
 {return sql_compare_CUserData<mysqlpp::sql_dummy>(*this,other) <= 0;} 
 int cmp (const CUserData &other) const 
 {return sql_compare_CUserData<mysqlpp::sql_dummy>(*this,other);} 
 int compare (const CUserData &other) const 
 {return sql_compare_CUserData<mysqlpp::sql_dummy>(*this,other);}

    void set(const sql_varchar &p1, const sql_varchar &p2, const sql_int_unsigned &p3, const sql_smallint_unsigned &p4, const sql_tinyint &p5, const sql_tinyint &p6, const sql_int_unsigned &p7, const sql_bigint_unsigned &p8, const sql_int_unsigned &p9, const sql_tinyint_unsigned &p10, const sql_bigint &p11, const sql_smallint_unsigned &p12, const sql_smallint_unsigned &p13, const sql_smallint_unsigned &p14, const sql_smallint_unsigned &p15, const sql_smallint_unsigned &p16, const sql_smallint_unsigned &p17, const sql_smallint_unsigned &p18, const sql_tinyint_unsigned &p19, const sql_int_unsigned &p20, const sql_smallint_unsigned &p21, const sql_tinyint_unsigned &p22, const sql_int &p23, const sql_smallint &p24, const sql_tinyint_unsigned &p25, const sql_varchar &p26, const sql_int_unsigned &p27, const sql_tinyint_unsigned &p28, const sql_int_unsigned &p29, const sql_int_unsigned &p30, const sql_smallint_unsigned &p31, const sql_smallint_unsigned &p32, const sql_int_unsigned &p33, const sql_int_unsigned &p34, const sql_int_unsigned &p35, const sql_varchar &p36, const sql_varchar &p37, const sql_int_unsigned &p38, const sql_int_unsigned &p39, const sql_int_unsigned &p40, const sql_int_unsigned &p41, const sql_varchar &p42, const sql_tinyint_unsigned &p43, const sql_int &p44, const sql_tinyint_unsigned &p45, const sql_int_unsigned &p46, const sql_tinyint_unsigned &p47, const sql_smallint_unsigned &p48, const sql_tinyint_unsigned &p49, const sql_int_unsigned &p50, const sql_tinyint &p51, const sql_int &p52, const sql_int_unsigned &p53, const sql_tinyint_unsigned &p54, const sql_tinyint_unsigned &p55, const sql_int_unsigned &p56, const sql_int_unsigned_null &p57, const sql_int_unsigned_null &p58, const sql_int_unsigned_null &p59, const sql_int_unsigned_null &p60, const sql_int_unsigned &p61, const sql_int_unsigned &p62, const sql_int_unsigned &p63, const sql_int_unsigned &p64, const sql_varchar &p65, const sql_int &p66, const sql_smallint_unsigned &p67, const sql_int_unsigned &p68, const sql_tinyint &p69, const sql_tinyint &p70, const sql_int_unsigned &p71, const sql_int_unsigned &p72, const sql_tinyint_unsigned &p73, const sql_tinyint_unsigned &p74, const sql_int_unsigned &p75, const sql_int_unsigned_null &p76, const sql_int_unsigned &p77, const sql_int &p78, const sql_bigint &p79, const sql_bigint_unsigned &p80, const sql_bigint_unsigned &p81, const sql_bigint_unsigned &p82, const sql_bigint_unsigned &p83, const sql_bigint_unsigned &p84, const sql_int &p85, const sql_int &p86, const sql_tinyint_unsigned &p87, const sql_bigint &p88, const sql_int_unsigned &p89, const sql_int_unsigned &p90, const sql_int_unsigned &p91, const sql_bigint_unsigned &p92, const sql_bigint_unsigned_null &p93, const sql_smallint_unsigned &p94, const sql_smallint_unsigned &p95, const sql_smallint_unsigned &p96, const sql_smallint_unsigned &p97, const sql_tinyint_unsigned &p98, const sql_bigint_unsigned_null &p99, const sql_int_unsigned_null &p100, const sql_tinyint_unsigned &p101, const sql_int_unsigned &p102, const sql_int_unsigned &p103, const sql_tinyint_unsigned_null &p104, const sql_bigint_unsigned_null &p105, const sql_tinyint_unsigned_null &p106, const sql_tinyint_unsigned_null &p107, const sql_int_unsigned &p108, const sql_tinyint_unsigned_null &p109, const sql_bigint_unsigned_null &p110, const sql_int_unsigned &p111, const sql_int_unsigned &p112, const sql_int_unsigned &p113, const sql_smallint_unsigned &p114, const sql_int_unsigned &p115, const sql_int_unsigned &p116, const sql_tinyint_unsigned &p117, const sql_tinyint_unsigned &p118, const sql_int_unsigned &p119, const sql_int_unsigned &p120, const sql_int_unsigned &p121, const sql_varchar &p122, const sql_int_unsigned &p123, const sql_int_unsigned &p124, const sql_int_unsigned &p125, const sql_int_unsigned &p126, const sql_int_unsigned &p127, const sql_int_unsigned &p128, const sql_int_unsigned &p129, const sql_bigint_unsigned &p130) {
table_override_ = 0;
    name = p1;\
    mate = p2;\
    lookface = p3;\
    hair = p4;\
    length = p5;\
    fat = p6;\
    money = p7;\
    money_saved = p8;\
    task_data = p9;\
    level = p10;\
    exp = p11;\
    power = p12;\
    constitution = p13;\
    dexterity = p14;\
    Speed = p15;\
    health = p16;\
    soul = p17;\
    additional_point = p18;\
    auto_allot = p19;\
    life = p20;\
    mana = p21;\
    profession = p22;\
    potential = p23;\
    pk = p24;\
    nobility = p25;\
    medal = p26;\
    medal_select = p27;\
    metempsychosis = p28;\
    syndicate_id = p29;\
    recordmap_id = p30;\
    recordx = p31;\
    recordy = p32;\
    account_id = p33;\
    id = p34;\
    last_login = p35;\
    account = p36;\
    password = p37;\
    task_mask = p38;\
    time_of_life = p39;\
    virtue = p40;\
    home_id = p41;\
    title = p42;\
    title_select = p43;\
    tutor_exp = p44;\
    tutor_level = p45;\
    maxlife_percent = p46;\
    mercenary_rank = p47;\
    mercenary_exp = p48;\
    nobility_rank = p49;\
    exploit = p50;\
    eud_pack_size = p51;\
    disableFlag = p52;\
    reg_time = p53;\
    accu_online_time = p54;\
    accu_offline_time = p55;\
    last_logout = p56;\
    prompt_ver = p57;\
    Friend_share = p58;\
    Login_time = p59;\
    Login_ip = p60;\
    soul_value = p61;\
    brood_times = p62;\
    emoney = p63;\
    chk_sum = p64;\
    elock = p65;\
    ExpBallUsage = p66;\
    ExpCrystalUsage = p67;\
    cheat_time = p68;\
    online_time = p69;\
    auto_exercise = p70;\
    hung_last_logout = p71;\
    god_status = p72;\
    big_prize_fails = p73;\
    small_prize_fails = p74;\
    bonus_points = p75;\
    flower = p76;\
    flower_w = p77;\
    flower_p = p78;\
    income = p79;\
    illu_ButterFly = p80;\
    illu_Fish = p81;\
    illu_Shell = p82;\
    illu_Herbal = p83;\
    illu_Ore = p84;\
    password_id = p85;\
    quiz_point = p86;\
    protect_state = p87;\
    donation = p88;\
    wood = p89;\
    stone = p90;\
    todo_list_mask1 = p91;\
    todo_list1 = p92;\
    todo_list_hex1 = p93;\
    coach = p94;\
    coach_time = p95;\
    coach_deed = p96;\
    coach_date = p97;\
    extra_hatch_size = p98;\
    shadiness_money = p99;\
    shadiness_emoney = p100;\
    soul_value_lev = p101;\
    business = p102;\
    emoney2 = p103;\
    type = p104;\
    god_strength = p105;\
    god_level = p106;\
    deification = p107;\
    tmoney = p108;\
    demon_level = p109;\
    demon_exp = p110;\
    socialclass = p111;\
    credit_point = p112;\
    credit_limit = p113;\
    credit_return = p114;\
    eudkernel_id = p115;\
    refinery_time_end = p116;\
    pack_add = p117;\
    boundary_lev = p118;\
    boundary_exp = p119;\
    offer_point = p120;\
    battle_lev = p121;\
    channel_account = p122;\
    recharge_emoney = p123;\
    auto_battle_time = p124;\
    first_recharge = p125;\
    special_flag = p126;\
    vip_lev = p127;\
    ghosttoexp_amount = p128;\
    vigor = p129;\
    func_list = p130;\

}
CUserData(const sql_varchar &p1, const sql_varchar &p2, const sql_int_unsigned &p3, const sql_smallint_unsigned &p4, const sql_tinyint &p5, const sql_tinyint &p6, const sql_int_unsigned &p7, const sql_bigint_unsigned &p8, const sql_int_unsigned &p9, const sql_tinyint_unsigned &p10, const sql_bigint &p11, const sql_smallint_unsigned &p12, const sql_smallint_unsigned &p13, const sql_smallint_unsigned &p14, const sql_smallint_unsigned &p15, const sql_smallint_unsigned &p16, const sql_smallint_unsigned &p17, const sql_smallint_unsigned &p18, const sql_tinyint_unsigned &p19, const sql_int_unsigned &p20, const sql_smallint_unsigned &p21, const sql_tinyint_unsigned &p22, const sql_int &p23, const sql_smallint &p24, const sql_tinyint_unsigned &p25, const sql_varchar &p26, const sql_int_unsigned &p27, const sql_tinyint_unsigned &p28, const sql_int_unsigned &p29, const sql_int_unsigned &p30, const sql_smallint_unsigned &p31, const sql_smallint_unsigned &p32, const sql_int_unsigned &p33, const sql_int_unsigned &p34, const sql_int_unsigned &p35, const sql_varchar &p36, const sql_varchar &p37, const sql_int_unsigned &p38, const sql_int_unsigned &p39, const sql_int_unsigned &p40, const sql_int_unsigned &p41, const sql_varchar &p42, const sql_tinyint_unsigned &p43, const sql_int &p44, const sql_tinyint_unsigned &p45, const sql_int_unsigned &p46, const sql_tinyint_unsigned &p47, const sql_smallint_unsigned &p48, const sql_tinyint_unsigned &p49, const sql_int_unsigned &p50, const sql_tinyint &p51, const sql_int &p52, const sql_int_unsigned &p53, const sql_tinyint_unsigned &p54, const sql_tinyint_unsigned &p55, const sql_int_unsigned &p56, const sql_int_unsigned_null &p57, const sql_int_unsigned_null &p58, const sql_int_unsigned_null &p59, const sql_int_unsigned_null &p60, const sql_int_unsigned &p61, const sql_int_unsigned &p62, const sql_int_unsigned &p63, const sql_int_unsigned &p64, const sql_varchar &p65, const sql_int &p66, const sql_smallint_unsigned &p67, const sql_int_unsigned &p68, const sql_tinyint &p69, const sql_tinyint &p70, const sql_int_unsigned &p71, const sql_int_unsigned &p72, const sql_tinyint_unsigned &p73, const sql_tinyint_unsigned &p74, const sql_int_unsigned &p75, const sql_int_unsigned_null &p76, const sql_int_unsigned &p77, const sql_int &p78, const sql_bigint &p79, const sql_bigint_unsigned &p80, const sql_bigint_unsigned &p81, const sql_bigint_unsigned &p82, const sql_bigint_unsigned &p83, const sql_bigint_unsigned &p84, const sql_int &p85, const sql_int &p86, const sql_tinyint_unsigned &p87, const sql_bigint &p88, const sql_int_unsigned &p89, const sql_int_unsigned &p90, const sql_int_unsigned &p91, const sql_bigint_unsigned &p92, const sql_bigint_unsigned_null &p93, const sql_smallint_unsigned &p94, const sql_smallint_unsigned &p95, const sql_smallint_unsigned &p96, const sql_smallint_unsigned &p97, const sql_tinyint_unsigned &p98, const sql_bigint_unsigned_null &p99, const sql_int_unsigned_null &p100, const sql_tinyint_unsigned &p101, const sql_int_unsigned &p102, const sql_int_unsigned &p103, const sql_tinyint_unsigned_null &p104, const sql_bigint_unsigned_null &p105, const sql_tinyint_unsigned_null &p106, const sql_tinyint_unsigned_null &p107, const sql_int_unsigned &p108, const sql_tinyint_unsigned_null &p109, const sql_bigint_unsigned_null &p110, const sql_int_unsigned &p111, const sql_int_unsigned &p112, const sql_int_unsigned &p113, const sql_smallint_unsigned &p114, const sql_int_unsigned &p115, const sql_int_unsigned &p116, const sql_tinyint_unsigned &p117, const sql_tinyint_unsigned &p118, const sql_int_unsigned &p119, const sql_int_unsigned &p120, const sql_int_unsigned &p121, const sql_varchar &p122, const sql_int_unsigned &p123, const sql_int_unsigned &p124, const sql_int_unsigned &p125, const sql_int_unsigned &p126, const sql_int_unsigned &p127, const sql_int_unsigned &p128, const sql_int_unsigned &p129, const sql_bigint_unsigned &p130) : name (p1), mate (p2), lookface (p3), hair (p4), length (p5), fat (p6), money (p7), money_saved (p8), task_data (p9), level (p10), exp (p11), power (p12), constitution (p13), dexterity (p14), Speed (p15), health (p16), soul (p17), additional_point (p18), auto_allot (p19), life (p20), mana (p21), profession (p22), potential (p23), pk (p24), nobility (p25), medal (p26), medal_select (p27), metempsychosis (p28), syndicate_id (p29), recordmap_id (p30), recordx (p31), recordy (p32), account_id (p33), id (p34), last_login (p35), account (p36), password (p37), task_mask (p38), time_of_life (p39), virtue (p40), home_id (p41), title (p42), title_select (p43), tutor_exp (p44), tutor_level (p45), maxlife_percent (p46), mercenary_rank (p47), mercenary_exp (p48), nobility_rank (p49), exploit (p50), eud_pack_size (p51), disableFlag (p52), reg_time (p53), accu_online_time (p54), accu_offline_time (p55), last_logout (p56), prompt_ver (p57), Friend_share (p58), Login_time (p59), Login_ip (p60), soul_value (p61), brood_times (p62), emoney (p63), chk_sum (p64), elock (p65), ExpBallUsage (p66), ExpCrystalUsage (p67), cheat_time (p68), online_time (p69), auto_exercise (p70), hung_last_logout (p71), god_status (p72), big_prize_fails (p73), small_prize_fails (p74), bonus_points (p75), flower (p76), flower_w (p77), flower_p (p78), income (p79), illu_ButterFly (p80), illu_Fish (p81), illu_Shell (p82), illu_Herbal (p83), illu_Ore (p84), password_id (p85), quiz_point (p86), protect_state (p87), donation (p88), wood (p89), stone (p90), todo_list_mask1 (p91), todo_list1 (p92), todo_list_hex1 (p93), coach (p94), coach_time (p95), coach_deed (p96), coach_date (p97), extra_hatch_size (p98), shadiness_money (p99), shadiness_emoney (p100), soul_value_lev (p101), business (p102), emoney2 (p103), type (p104), god_strength (p105), god_level (p106), deification (p107), tmoney (p108), demon_level (p109), demon_exp (p110), socialclass (p111), credit_point (p112), credit_limit (p113), credit_return (p114), eudkernel_id (p115), refinery_time_end (p116), pack_add (p117), boundary_lev (p118), boundary_exp (p119), offer_point (p120), battle_lev (p121), channel_account (p122), recharge_emoney (p123), auto_battle_time (p124), first_recharge (p125), special_flag (p126), vip_lev (p127), ghosttoexp_amount (p128), vigor (p129), func_list (p130), table_override_(0) {}

    static const char* names[];
    static void table(const char* t) { table_ = t; }
    const char* table() const
            { return table_override_ ? table_override_ : CUserData::table_; }
    void instance_table(const char* t) { table_override_ = t; }

    CUserData_value_list<mysqlpp::quote_type0> value_list() const {
        return value_list(",", mysqlpp::quote);}
    CUserData_value_list<mysqlpp::quote_type0> value_list(const char* d) const {
        return value_list(d, mysqlpp::quote);}
    template <class Manip>
    CUserData_value_list<Manip> value_list(const char* d, Manip m) const;

    CUserData_field_list<mysqlpp::do_nothing_type0> field_list() const {
        return field_list(",", mysqlpp::do_nothing);}
    CUserData_field_list<mysqlpp::do_nothing_type0> field_list(const char* d) const {
        return field_list(d, mysqlpp::do_nothing);}
    template <class Manip>
    CUserData_field_list<Manip> field_list(const char* d, Manip m) const;

    CUserData_equal_list<mysqlpp::quote_type0> equal_list(const char* d = ",",
            const char* c = " = ") const
            { return equal_list(d, c, mysqlpp::quote); }
    template <class Manip>
    CUserData_equal_list<Manip> equal_list(const char* d, const char* c, Manip m) const;

    /* cus_data */

    CUserData_cus_value_list<mysqlpp::quote_type0> value_list(bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false, bool i9 = false, bool i10 = false, bool i11 = false, bool i12 = false, bool i13 = false, bool i14 = false, bool i15 = false, bool i16 = false, bool i17 = false, bool i18 = false, bool i19 = false, bool i20 = false, bool i21 = false, bool i22 = false, bool i23 = false, bool i24 = false, bool i25 = false, bool i26 = false, bool i27 = false, bool i28 = false, bool i29 = false, bool i30 = false, bool i31 = false, bool i32 = false, bool i33 = false, bool i34 = false, bool i35 = false, bool i36 = false, bool i37 = false, bool i38 = false, bool i39 = false, bool i40 = false, bool i41 = false, bool i42 = false, bool i43 = false, bool i44 = false, bool i45 = false, bool i46 = false, bool i47 = false, bool i48 = false, bool i49 = false, bool i50 = false, bool i51 = false, bool i52 = false, bool i53 = false, bool i54 = false, bool i55 = false, bool i56 = false, bool i57 = false, bool i58 = false, bool i59 = false, bool i60 = false, bool i61 = false, bool i62 = false, bool i63 = false, bool i64 = false, bool i65 = false, bool i66 = false, bool i67 = false, bool i68 = false, bool i69 = false, bool i70 = false, bool i71 = false, bool i72 = false, bool i73 = false, bool i74 = false, bool i75 = false, bool i76 = false, bool i77 = false, bool i78 = false, bool i79 = false, bool i80 = false, bool i81 = false, bool i82 = false, bool i83 = false, bool i84 = false, bool i85 = false, bool i86 = false, bool i87 = false, bool i88 = false, bool i89 = false, bool i90 = false, bool i91 = false, bool i92 = false, bool i93 = false, bool i94 = false, bool i95 = false, bool i96 = false, bool i97 = false, bool i98 = false, bool i99 = false, bool i100 = false, bool i101 = false, bool i102 = false, bool i103 = false, bool i104 = false, bool i105 = false, bool i106 = false, bool i107 = false, bool i108 = false, bool i109 = false, bool i110 = false, bool i111 = false, bool i112 = false, bool i113 = false, bool i114 = false, bool i115 = false, bool i116 = false, bool i117 = false, bool i118 = false, bool i119 = false, bool i120 = false, bool i121 = false, bool i122 = false, bool i123 = false, bool i124 = false, bool i125 = false, bool i126 = false, bool i127 = false, bool i128 = false, bool i129 = false, bool i130 = false) const
            { return value_list(",", mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15, i16, i17, i18, i19, i20, i21, i22, i23, i24, i25, i26, i27, i28, i29, i30, i31, i32, i33, i34, i35, i36, i37, i38, i39, i40, i41, i42, i43, i44, i45, i46, i47, i48, i49, i50, i51, i52, i53, i54, i55, i56, i57, i58, i59, i60, i61, i62, i63, i64, i65, i66, i67, i68, i69, i70, i71, i72, i73, i74, i75, i76, i77, i78, i79, i80, i81, i82, i83, i84, i85, i86, i87, i88, i89, i90, i91, i92, i93, i94, i95, i96, i97, i98, i99, i100, i101, i102, i103, i104, i105, i106, i107, i108, i109, i110, i111, i112, i113, i114, i115, i116, i117, i118, i119, i120, i121, i122, i123, i124, i125, i126, i127, i128, i129, i130); }
    CUserData_cus_value_list<mysqlpp::quote_type0> value_list(CUserData_enum i1, CUserData_enum i2 = USERDATA_NULL, CUserData_enum i3 = USERDATA_NULL, CUserData_enum i4 = USERDATA_NULL, CUserData_enum i5 = USERDATA_NULL, CUserData_enum i6 = USERDATA_NULL, CUserData_enum i7 = USERDATA_NULL, CUserData_enum i8 = USERDATA_NULL, CUserData_enum i9 = USERDATA_NULL, CUserData_enum i10 = USERDATA_NULL, CUserData_enum i11 = USERDATA_NULL, CUserData_enum i12 = USERDATA_NULL, CUserData_enum i13 = USERDATA_NULL, CUserData_enum i14 = USERDATA_NULL, CUserData_enum i15 = USERDATA_NULL, CUserData_enum i16 = USERDATA_NULL, CUserData_enum i17 = USERDATA_NULL, CUserData_enum i18 = USERDATA_NULL, CUserData_enum i19 = USERDATA_NULL, CUserData_enum i20 = USERDATA_NULL, CUserData_enum i21 = USERDATA_NULL, CUserData_enum i22 = USERDATA_NULL, CUserData_enum i23 = USERDATA_NULL, CUserData_enum i24 = USERDATA_NULL, CUserData_enum i25 = USERDATA_NULL, CUserData_enum i26 = USERDATA_NULL, CUserData_enum i27 = USERDATA_NULL, CUserData_enum i28 = USERDATA_NULL, CUserData_enum i29 = USERDATA_NULL, CUserData_enum i30 = USERDATA_NULL, CUserData_enum i31 = USERDATA_NULL, CUserData_enum i32 = USERDATA_NULL, CUserData_enum i33 = USERDATA_NULL, CUserData_enum i34 = USERDATA_NULL, CUserData_enum i35 = USERDATA_NULL, CUserData_enum i36 = USERDATA_NULL, CUserData_enum i37 = USERDATA_NULL, CUserData_enum i38 = USERDATA_NULL, CUserData_enum i39 = USERDATA_NULL, CUserData_enum i40 = USERDATA_NULL, CUserData_enum i41 = USERDATA_NULL, CUserData_enum i42 = USERDATA_NULL, CUserData_enum i43 = USERDATA_NULL, CUserData_enum i44 = USERDATA_NULL, CUserData_enum i45 = USERDATA_NULL, CUserData_enum i46 = USERDATA_NULL, CUserData_enum i47 = USERDATA_NULL, CUserData_enum i48 = USERDATA_NULL, CUserData_enum i49 = USERDATA_NULL, CUserData_enum i50 = USERDATA_NULL, CUserData_enum i51 = USERDATA_NULL, CUserData_enum i52 = USERDATA_NULL, CUserData_enum i53 = USERDATA_NULL, CUserData_enum i54 = USERDATA_NULL, CUserData_enum i55 = USERDATA_NULL, CUserData_enum i56 = USERDATA_NULL, CUserData_enum i57 = USERDATA_NULL, CUserData_enum i58 = USERDATA_NULL, CUserData_enum i59 = USERDATA_NULL, CUserData_enum i60 = USERDATA_NULL, CUserData_enum i61 = USERDATA_NULL, CUserData_enum i62 = USERDATA_NULL, CUserData_enum i63 = USERDATA_NULL, CUserData_enum i64 = USERDATA_NULL, CUserData_enum i65 = USERDATA_NULL, CUserData_enum i66 = USERDATA_NULL, CUserData_enum i67 = USERDATA_NULL, CUserData_enum i68 = USERDATA_NULL, CUserData_enum i69 = USERDATA_NULL, CUserData_enum i70 = USERDATA_NULL, CUserData_enum i71 = USERDATA_NULL, CUserData_enum i72 = USERDATA_NULL, CUserData_enum i73 = USERDATA_NULL, CUserData_enum i74 = USERDATA_NULL, CUserData_enum i75 = USERDATA_NULL, CUserData_enum i76 = USERDATA_NULL, CUserData_enum i77 = USERDATA_NULL, CUserData_enum i78 = USERDATA_NULL, CUserData_enum i79 = USERDATA_NULL, CUserData_enum i80 = USERDATA_NULL, CUserData_enum i81 = USERDATA_NULL, CUserData_enum i82 = USERDATA_NULL, CUserData_enum i83 = USERDATA_NULL, CUserData_enum i84 = USERDATA_NULL, CUserData_enum i85 = USERDATA_NULL, CUserData_enum i86 = USERDATA_NULL, CUserData_enum i87 = USERDATA_NULL, CUserData_enum i88 = USERDATA_NULL, CUserData_enum i89 = USERDATA_NULL, CUserData_enum i90 = USERDATA_NULL, CUserData_enum i91 = USERDATA_NULL, CUserData_enum i92 = USERDATA_NULL, CUserData_enum i93 = USERDATA_NULL, CUserData_enum i94 = USERDATA_NULL, CUserData_enum i95 = USERDATA_NULL, CUserData_enum i96 = USERDATA_NULL, CUserData_enum i97 = USERDATA_NULL, CUserData_enum i98 = USERDATA_NULL, CUserData_enum i99 = USERDATA_NULL, CUserData_enum i100 = USERDATA_NULL, CUserData_enum i101 = USERDATA_NULL, CUserData_enum i102 = USERDATA_NULL, CUserData_enum i103 = USERDATA_NULL, CUserData_enum i104 = USERDATA_NULL, CUserData_enum i105 = USERDATA_NULL, CUserData_enum i106 = USERDATA_NULL, CUserData_enum i107 = USERDATA_NULL, CUserData_enum i108 = USERDATA_NULL, CUserData_enum i109 = USERDATA_NULL, CUserData_enum i110 = USERDATA_NULL, CUserData_enum i111 = USERDATA_NULL, CUserData_enum i112 = USERDATA_NULL, CUserData_enum i113 = USERDATA_NULL, CUserData_enum i114 = USERDATA_NULL, CUserData_enum i115 = USERDATA_NULL, CUserData_enum i116 = USERDATA_NULL, CUserData_enum i117 = USERDATA_NULL, CUserData_enum i118 = USERDATA_NULL, CUserData_enum i119 = USERDATA_NULL, CUserData_enum i120 = USERDATA_NULL, CUserData_enum i121 = USERDATA_NULL, CUserData_enum i122 = USERDATA_NULL, CUserData_enum i123 = USERDATA_NULL, CUserData_enum i124 = USERDATA_NULL, CUserData_enum i125 = USERDATA_NULL, CUserData_enum i126 = USERDATA_NULL, CUserData_enum i127 = USERDATA_NULL, CUserData_enum i128 = USERDATA_NULL, CUserData_enum i129 = USERDATA_NULL, CUserData_enum i130 = USERDATA_NULL) const
            { return value_list(",", mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15, i16, i17, i18, i19, i20, i21, i22, i23, i24, i25, i26, i27, i28, i29, i30, i31, i32, i33, i34, i35, i36, i37, i38, i39, i40, i41, i42, i43, i44, i45, i46, i47, i48, i49, i50, i51, i52, i53, i54, i55, i56, i57, i58, i59, i60, i61, i62, i63, i64, i65, i66, i67, i68, i69, i70, i71, i72, i73, i74, i75, i76, i77, i78, i79, i80, i81, i82, i83, i84, i85, i86, i87, i88, i89, i90, i91, i92, i93, i94, i95, i96, i97, i98, i99, i100, i101, i102, i103, i104, i105, i106, i107, i108, i109, i110, i111, i112, i113, i114, i115, i116, i117, i118, i119, i120, i121, i122, i123, i124, i125, i126, i127, i128, i129, i130); }
    CUserData_cus_value_list<mysqlpp::quote_type0> value_list(std::vector<bool> *i) const
            { return value_list(",", mysqlpp::quote, i); }
    CUserData_cus_value_list<mysqlpp::quote_type0> value_list(mysqlpp::sql_cmp_type sc) const
            { return value_list(",", mysqlpp::quote, sc); }

    CUserData_cus_value_list<mysqlpp::quote_type0> value_list(const char* d, bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false, bool i9 = false, bool i10 = false, bool i11 = false, bool i12 = false, bool i13 = false, bool i14 = false, bool i15 = false, bool i16 = false, bool i17 = false, bool i18 = false, bool i19 = false, bool i20 = false, bool i21 = false, bool i22 = false, bool i23 = false, bool i24 = false, bool i25 = false, bool i26 = false, bool i27 = false, bool i28 = false, bool i29 = false, bool i30 = false, bool i31 = false, bool i32 = false, bool i33 = false, bool i34 = false, bool i35 = false, bool i36 = false, bool i37 = false, bool i38 = false, bool i39 = false, bool i40 = false, bool i41 = false, bool i42 = false, bool i43 = false, bool i44 = false, bool i45 = false, bool i46 = false, bool i47 = false, bool i48 = false, bool i49 = false, bool i50 = false, bool i51 = false, bool i52 = false, bool i53 = false, bool i54 = false, bool i55 = false, bool i56 = false, bool i57 = false, bool i58 = false, bool i59 = false, bool i60 = false, bool i61 = false, bool i62 = false, bool i63 = false, bool i64 = false, bool i65 = false, bool i66 = false, bool i67 = false, bool i68 = false, bool i69 = false, bool i70 = false, bool i71 = false, bool i72 = false, bool i73 = false, bool i74 = false, bool i75 = false, bool i76 = false, bool i77 = false, bool i78 = false, bool i79 = false, bool i80 = false, bool i81 = false, bool i82 = false, bool i83 = false, bool i84 = false, bool i85 = false, bool i86 = false, bool i87 = false, bool i88 = false, bool i89 = false, bool i90 = false, bool i91 = false, bool i92 = false, bool i93 = false, bool i94 = false, bool i95 = false, bool i96 = false, bool i97 = false, bool i98 = false, bool i99 = false, bool i100 = false, bool i101 = false, bool i102 = false, bool i103 = false, bool i104 = false, bool i105 = false, bool i106 = false, bool i107 = false, bool i108 = false, bool i109 = false, bool i110 = false, bool i111 = false, bool i112 = false, bool i113 = false, bool i114 = false, bool i115 = false, bool i116 = false, bool i117 = false, bool i118 = false, bool i119 = false, bool i120 = false, bool i121 = false, bool i122 = false, bool i123 = false, bool i124 = false, bool i125 = false, bool i126 = false, bool i127 = false, bool i128 = false, bool i129 = false, bool i130 = false) const
            { return value_list(d, mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15, i16, i17, i18, i19, i20, i21, i22, i23, i24, i25, i26, i27, i28, i29, i30, i31, i32, i33, i34, i35, i36, i37, i38, i39, i40, i41, i42, i43, i44, i45, i46, i47, i48, i49, i50, i51, i52, i53, i54, i55, i56, i57, i58, i59, i60, i61, i62, i63, i64, i65, i66, i67, i68, i69, i70, i71, i72, i73, i74, i75, i76, i77, i78, i79, i80, i81, i82, i83, i84, i85, i86, i87, i88, i89, i90, i91, i92, i93, i94, i95, i96, i97, i98, i99, i100, i101, i102, i103, i104, i105, i106, i107, i108, i109, i110, i111, i112, i113, i114, i115, i116, i117, i118, i119, i120, i121, i122, i123, i124, i125, i126, i127, i128, i129, i130); }
    CUserData_cus_value_list<mysqlpp::quote_type0> value_list(const char* d, CUserData_enum i1, CUserData_enum i2 = USERDATA_NULL, CUserData_enum i3 = USERDATA_NULL, CUserData_enum i4 = USERDATA_NULL, CUserData_enum i5 = USERDATA_NULL, CUserData_enum i6 = USERDATA_NULL, CUserData_enum i7 = USERDATA_NULL, CUserData_enum i8 = USERDATA_NULL, CUserData_enum i9 = USERDATA_NULL, CUserData_enum i10 = USERDATA_NULL, CUserData_enum i11 = USERDATA_NULL, CUserData_enum i12 = USERDATA_NULL, CUserData_enum i13 = USERDATA_NULL, CUserData_enum i14 = USERDATA_NULL, CUserData_enum i15 = USERDATA_NULL, CUserData_enum i16 = USERDATA_NULL, CUserData_enum i17 = USERDATA_NULL, CUserData_enum i18 = USERDATA_NULL, CUserData_enum i19 = USERDATA_NULL, CUserData_enum i20 = USERDATA_NULL, CUserData_enum i21 = USERDATA_NULL, CUserData_enum i22 = USERDATA_NULL, CUserData_enum i23 = USERDATA_NULL, CUserData_enum i24 = USERDATA_NULL, CUserData_enum i25 = USERDATA_NULL, CUserData_enum i26 = USERDATA_NULL, CUserData_enum i27 = USERDATA_NULL, CUserData_enum i28 = USERDATA_NULL, CUserData_enum i29 = USERDATA_NULL, CUserData_enum i30 = USERDATA_NULL, CUserData_enum i31 = USERDATA_NULL, CUserData_enum i32 = USERDATA_NULL, CUserData_enum i33 = USERDATA_NULL, CUserData_enum i34 = USERDATA_NULL, CUserData_enum i35 = USERDATA_NULL, CUserData_enum i36 = USERDATA_NULL, CUserData_enum i37 = USERDATA_NULL, CUserData_enum i38 = USERDATA_NULL, CUserData_enum i39 = USERDATA_NULL, CUserData_enum i40 = USERDATA_NULL, CUserData_enum i41 = USERDATA_NULL, CUserData_enum i42 = USERDATA_NULL, CUserData_enum i43 = USERDATA_NULL, CUserData_enum i44 = USERDATA_NULL, CUserData_enum i45 = USERDATA_NULL, CUserData_enum i46 = USERDATA_NULL, CUserData_enum i47 = USERDATA_NULL, CUserData_enum i48 = USERDATA_NULL, CUserData_enum i49 = USERDATA_NULL, CUserData_enum i50 = USERDATA_NULL, CUserData_enum i51 = USERDATA_NULL, CUserData_enum i52 = USERDATA_NULL, CUserData_enum i53 = USERDATA_NULL, CUserData_enum i54 = USERDATA_NULL, CUserData_enum i55 = USERDATA_NULL, CUserData_enum i56 = USERDATA_NULL, CUserData_enum i57 = USERDATA_NULL, CUserData_enum i58 = USERDATA_NULL, CUserData_enum i59 = USERDATA_NULL, CUserData_enum i60 = USERDATA_NULL, CUserData_enum i61 = USERDATA_NULL, CUserData_enum i62 = USERDATA_NULL, CUserData_enum i63 = USERDATA_NULL, CUserData_enum i64 = USERDATA_NULL, CUserData_enum i65 = USERDATA_NULL, CUserData_enum i66 = USERDATA_NULL, CUserData_enum i67 = USERDATA_NULL, CUserData_enum i68 = USERDATA_NULL, CUserData_enum i69 = USERDATA_NULL, CUserData_enum i70 = USERDATA_NULL, CUserData_enum i71 = USERDATA_NULL, CUserData_enum i72 = USERDATA_NULL, CUserData_enum i73 = USERDATA_NULL, CUserData_enum i74 = USERDATA_NULL, CUserData_enum i75 = USERDATA_NULL, CUserData_enum i76 = USERDATA_NULL, CUserData_enum i77 = USERDATA_NULL, CUserData_enum i78 = USERDATA_NULL, CUserData_enum i79 = USERDATA_NULL, CUserData_enum i80 = USERDATA_NULL, CUserData_enum i81 = USERDATA_NULL, CUserData_enum i82 = USERDATA_NULL, CUserData_enum i83 = USERDATA_NULL, CUserData_enum i84 = USERDATA_NULL, CUserData_enum i85 = USERDATA_NULL, CUserData_enum i86 = USERDATA_NULL, CUserData_enum i87 = USERDATA_NULL, CUserData_enum i88 = USERDATA_NULL, CUserData_enum i89 = USERDATA_NULL, CUserData_enum i90 = USERDATA_NULL, CUserData_enum i91 = USERDATA_NULL, CUserData_enum i92 = USERDATA_NULL, CUserData_enum i93 = USERDATA_NULL, CUserData_enum i94 = USERDATA_NULL, CUserData_enum i95 = USERDATA_NULL, CUserData_enum i96 = USERDATA_NULL, CUserData_enum i97 = USERDATA_NULL, CUserData_enum i98 = USERDATA_NULL, CUserData_enum i99 = USERDATA_NULL, CUserData_enum i100 = USERDATA_NULL, CUserData_enum i101 = USERDATA_NULL, CUserData_enum i102 = USERDATA_NULL, CUserData_enum i103 = USERDATA_NULL, CUserData_enum i104 = USERDATA_NULL, CUserData_enum i105 = USERDATA_NULL, CUserData_enum i106 = USERDATA_NULL, CUserData_enum i107 = USERDATA_NULL, CUserData_enum i108 = USERDATA_NULL, CUserData_enum i109 = USERDATA_NULL, CUserData_enum i110 = USERDATA_NULL, CUserData_enum i111 = USERDATA_NULL, CUserData_enum i112 = USERDATA_NULL, CUserData_enum i113 = USERDATA_NULL, CUserData_enum i114 = USERDATA_NULL, CUserData_enum i115 = USERDATA_NULL, CUserData_enum i116 = USERDATA_NULL, CUserData_enum i117 = USERDATA_NULL, CUserData_enum i118 = USERDATA_NULL, CUserData_enum i119 = USERDATA_NULL, CUserData_enum i120 = USERDATA_NULL, CUserData_enum i121 = USERDATA_NULL, CUserData_enum i122 = USERDATA_NULL, CUserData_enum i123 = USERDATA_NULL, CUserData_enum i124 = USERDATA_NULL, CUserData_enum i125 = USERDATA_NULL, CUserData_enum i126 = USERDATA_NULL, CUserData_enum i127 = USERDATA_NULL, CUserData_enum i128 = USERDATA_NULL, CUserData_enum i129 = USERDATA_NULL, CUserData_enum i130 = USERDATA_NULL) const
            { return value_list(d, mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15, i16, i17, i18, i19, i20, i21, i22, i23, i24, i25, i26, i27, i28, i29, i30, i31, i32, i33, i34, i35, i36, i37, i38, i39, i40, i41, i42, i43, i44, i45, i46, i47, i48, i49, i50, i51, i52, i53, i54, i55, i56, i57, i58, i59, i60, i61, i62, i63, i64, i65, i66, i67, i68, i69, i70, i71, i72, i73, i74, i75, i76, i77, i78, i79, i80, i81, i82, i83, i84, i85, i86, i87, i88, i89, i90, i91, i92, i93, i94, i95, i96, i97, i98, i99, i100, i101, i102, i103, i104, i105, i106, i107, i108, i109, i110, i111, i112, i113, i114, i115, i116, i117, i118, i119, i120, i121, i122, i123, i124, i125, i126, i127, i128, i129, i130); }
    CUserData_cus_value_list<mysqlpp::quote_type0> value_list(const char* d,
            std::vector<bool> *i) const
            { return value_list(d, mysqlpp::quote, i); }
    CUserData_cus_value_list<mysqlpp::quote_type0> value_list(const char* d,
            mysqlpp::sql_cmp_type sc) const
            { return value_list(d, mysqlpp::quote, sc); }

    template <class Manip>
    CUserData_cus_value_list<Manip> value_list(const char* d, Manip m,
            bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false, bool i9 = false, bool i10 = false, bool i11 = false, bool i12 = false, bool i13 = false, bool i14 = false, bool i15 = false, bool i16 = false, bool i17 = false, bool i18 = false, bool i19 = false, bool i20 = false, bool i21 = false, bool i22 = false, bool i23 = false, bool i24 = false, bool i25 = false, bool i26 = false, bool i27 = false, bool i28 = false, bool i29 = false, bool i30 = false, bool i31 = false, bool i32 = false, bool i33 = false, bool i34 = false, bool i35 = false, bool i36 = false, bool i37 = false, bool i38 = false, bool i39 = false, bool i40 = false, bool i41 = false, bool i42 = false, bool i43 = false, bool i44 = false, bool i45 = false, bool i46 = false, bool i47 = false, bool i48 = false, bool i49 = false, bool i50 = false, bool i51 = false, bool i52 = false, bool i53 = false, bool i54 = false, bool i55 = false, bool i56 = false, bool i57 = false, bool i58 = false, bool i59 = false, bool i60 = false, bool i61 = false, bool i62 = false, bool i63 = false, bool i64 = false, bool i65 = false, bool i66 = false, bool i67 = false, bool i68 = false, bool i69 = false, bool i70 = false, bool i71 = false, bool i72 = false, bool i73 = false, bool i74 = false, bool i75 = false, bool i76 = false, bool i77 = false, bool i78 = false, bool i79 = false, bool i80 = false, bool i81 = false, bool i82 = false, bool i83 = false, bool i84 = false, bool i85 = false, bool i86 = false, bool i87 = false, bool i88 = false, bool i89 = false, bool i90 = false, bool i91 = false, bool i92 = false, bool i93 = false, bool i94 = false, bool i95 = false, bool i96 = false, bool i97 = false, bool i98 = false, bool i99 = false, bool i100 = false, bool i101 = false, bool i102 = false, bool i103 = false, bool i104 = false, bool i105 = false, bool i106 = false, bool i107 = false, bool i108 = false, bool i109 = false, bool i110 = false, bool i111 = false, bool i112 = false, bool i113 = false, bool i114 = false, bool i115 = false, bool i116 = false, bool i117 = false, bool i118 = false, bool i119 = false, bool i120 = false, bool i121 = false, bool i122 = false, bool i123 = false, bool i124 = false, bool i125 = false, bool i126 = false, bool i127 = false, bool i128 = false, bool i129 = false, bool i130 = false) const;
    template <class Manip>
    CUserData_cus_value_list<Manip> value_list(const char* d, Manip m,
            CUserData_enum i1, CUserData_enum i2 = USERDATA_NULL, CUserData_enum i3 = USERDATA_NULL, CUserData_enum i4 = USERDATA_NULL, CUserData_enum i5 = USERDATA_NULL, CUserData_enum i6 = USERDATA_NULL, CUserData_enum i7 = USERDATA_NULL, CUserData_enum i8 = USERDATA_NULL, CUserData_enum i9 = USERDATA_NULL, CUserData_enum i10 = USERDATA_NULL, CUserData_enum i11 = USERDATA_NULL, CUserData_enum i12 = USERDATA_NULL, CUserData_enum i13 = USERDATA_NULL, CUserData_enum i14 = USERDATA_NULL, CUserData_enum i15 = USERDATA_NULL, CUserData_enum i16 = USERDATA_NULL, CUserData_enum i17 = USERDATA_NULL, CUserData_enum i18 = USERDATA_NULL, CUserData_enum i19 = USERDATA_NULL, CUserData_enum i20 = USERDATA_NULL, CUserData_enum i21 = USERDATA_NULL, CUserData_enum i22 = USERDATA_NULL, CUserData_enum i23 = USERDATA_NULL, CUserData_enum i24 = USERDATA_NULL, CUserData_enum i25 = USERDATA_NULL, CUserData_enum i26 = USERDATA_NULL, CUserData_enum i27 = USERDATA_NULL, CUserData_enum i28 = USERDATA_NULL, CUserData_enum i29 = USERDATA_NULL, CUserData_enum i30 = USERDATA_NULL, CUserData_enum i31 = USERDATA_NULL, CUserData_enum i32 = USERDATA_NULL, CUserData_enum i33 = USERDATA_NULL, CUserData_enum i34 = USERDATA_NULL, CUserData_enum i35 = USERDATA_NULL, CUserData_enum i36 = USERDATA_NULL, CUserData_enum i37 = USERDATA_NULL, CUserData_enum i38 = USERDATA_NULL, CUserData_enum i39 = USERDATA_NULL, CUserData_enum i40 = USERDATA_NULL, CUserData_enum i41 = USERDATA_NULL, CUserData_enum i42 = USERDATA_NULL, CUserData_enum i43 = USERDATA_NULL, CUserData_enum i44 = USERDATA_NULL, CUserData_enum i45 = USERDATA_NULL, CUserData_enum i46 = USERDATA_NULL, CUserData_enum i47 = USERDATA_NULL, CUserData_enum i48 = USERDATA_NULL, CUserData_enum i49 = USERDATA_NULL, CUserData_enum i50 = USERDATA_NULL, CUserData_enum i51 = USERDATA_NULL, CUserData_enum i52 = USERDATA_NULL, CUserData_enum i53 = USERDATA_NULL, CUserData_enum i54 = USERDATA_NULL, CUserData_enum i55 = USERDATA_NULL, CUserData_enum i56 = USERDATA_NULL, CUserData_enum i57 = USERDATA_NULL, CUserData_enum i58 = USERDATA_NULL, CUserData_enum i59 = USERDATA_NULL, CUserData_enum i60 = USERDATA_NULL, CUserData_enum i61 = USERDATA_NULL, CUserData_enum i62 = USERDATA_NULL, CUserData_enum i63 = USERDATA_NULL, CUserData_enum i64 = USERDATA_NULL, CUserData_enum i65 = USERDATA_NULL, CUserData_enum i66 = USERDATA_NULL, CUserData_enum i67 = USERDATA_NULL, CUserData_enum i68 = USERDATA_NULL, CUserData_enum i69 = USERDATA_NULL, CUserData_enum i70 = USERDATA_NULL, CUserData_enum i71 = USERDATA_NULL, CUserData_enum i72 = USERDATA_NULL, CUserData_enum i73 = USERDATA_NULL, CUserData_enum i74 = USERDATA_NULL, CUserData_enum i75 = USERDATA_NULL, CUserData_enum i76 = USERDATA_NULL, CUserData_enum i77 = USERDATA_NULL, CUserData_enum i78 = USERDATA_NULL, CUserData_enum i79 = USERDATA_NULL, CUserData_enum i80 = USERDATA_NULL, CUserData_enum i81 = USERDATA_NULL, CUserData_enum i82 = USERDATA_NULL, CUserData_enum i83 = USERDATA_NULL, CUserData_enum i84 = USERDATA_NULL, CUserData_enum i85 = USERDATA_NULL, CUserData_enum i86 = USERDATA_NULL, CUserData_enum i87 = USERDATA_NULL, CUserData_enum i88 = USERDATA_NULL, CUserData_enum i89 = USERDATA_NULL, CUserData_enum i90 = USERDATA_NULL, CUserData_enum i91 = USERDATA_NULL, CUserData_enum i92 = USERDATA_NULL, CUserData_enum i93 = USERDATA_NULL, CUserData_enum i94 = USERDATA_NULL, CUserData_enum i95 = USERDATA_NULL, CUserData_enum i96 = USERDATA_NULL, CUserData_enum i97 = USERDATA_NULL, CUserData_enum i98 = USERDATA_NULL, CUserData_enum i99 = USERDATA_NULL, CUserData_enum i100 = USERDATA_NULL, CUserData_enum i101 = USERDATA_NULL, CUserData_enum i102 = USERDATA_NULL, CUserData_enum i103 = USERDATA_NULL, CUserData_enum i104 = USERDATA_NULL, CUserData_enum i105 = USERDATA_NULL, CUserData_enum i106 = USERDATA_NULL, CUserData_enum i107 = USERDATA_NULL, CUserData_enum i108 = USERDATA_NULL, CUserData_enum i109 = USERDATA_NULL, CUserData_enum i110 = USERDATA_NULL, CUserData_enum i111 = USERDATA_NULL, CUserData_enum i112 = USERDATA_NULL, CUserData_enum i113 = USERDATA_NULL, CUserData_enum i114 = USERDATA_NULL, CUserData_enum i115 = USERDATA_NULL, CUserData_enum i116 = USERDATA_NULL, CUserData_enum i117 = USERDATA_NULL, CUserData_enum i118 = USERDATA_NULL, CUserData_enum i119 = USERDATA_NULL, CUserData_enum i120 = USERDATA_NULL, CUserData_enum i121 = USERDATA_NULL, CUserData_enum i122 = USERDATA_NULL, CUserData_enum i123 = USERDATA_NULL, CUserData_enum i124 = USERDATA_NULL, CUserData_enum i125 = USERDATA_NULL, CUserData_enum i126 = USERDATA_NULL, CUserData_enum i127 = USERDATA_NULL, CUserData_enum i128 = USERDATA_NULL, CUserData_enum i129 = USERDATA_NULL, CUserData_enum i130 = USERDATA_NULL) const;
    template <class Manip>
    CUserData_cus_value_list<Manip> value_list(const char* d, Manip m,
            std::vector<bool>* i) const;
    template <class Manip>
    CUserData_cus_value_list<Manip> value_list(const char* d, Manip m, 
            mysqlpp::sql_cmp_type sc) const;
    /* cus field */

    CUserData_cus_field_list<mysqlpp::do_nothing_type0> field_list(bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false, bool i9 = false, bool i10 = false, bool i11 = false, bool i12 = false, bool i13 = false, bool i14 = false, bool i15 = false, bool i16 = false, bool i17 = false, bool i18 = false, bool i19 = false, bool i20 = false, bool i21 = false, bool i22 = false, bool i23 = false, bool i24 = false, bool i25 = false, bool i26 = false, bool i27 = false, bool i28 = false, bool i29 = false, bool i30 = false, bool i31 = false, bool i32 = false, bool i33 = false, bool i34 = false, bool i35 = false, bool i36 = false, bool i37 = false, bool i38 = false, bool i39 = false, bool i40 = false, bool i41 = false, bool i42 = false, bool i43 = false, bool i44 = false, bool i45 = false, bool i46 = false, bool i47 = false, bool i48 = false, bool i49 = false, bool i50 = false, bool i51 = false, bool i52 = false, bool i53 = false, bool i54 = false, bool i55 = false, bool i56 = false, bool i57 = false, bool i58 = false, bool i59 = false, bool i60 = false, bool i61 = false, bool i62 = false, bool i63 = false, bool i64 = false, bool i65 = false, bool i66 = false, bool i67 = false, bool i68 = false, bool i69 = false, bool i70 = false, bool i71 = false, bool i72 = false, bool i73 = false, bool i74 = false, bool i75 = false, bool i76 = false, bool i77 = false, bool i78 = false, bool i79 = false, bool i80 = false, bool i81 = false, bool i82 = false, bool i83 = false, bool i84 = false, bool i85 = false, bool i86 = false, bool i87 = false, bool i88 = false, bool i89 = false, bool i90 = false, bool i91 = false, bool i92 = false, bool i93 = false, bool i94 = false, bool i95 = false, bool i96 = false, bool i97 = false, bool i98 = false, bool i99 = false, bool i100 = false, bool i101 = false, bool i102 = false, bool i103 = false, bool i104 = false, bool i105 = false, bool i106 = false, bool i107 = false, bool i108 = false, bool i109 = false, bool i110 = false, bool i111 = false, bool i112 = false, bool i113 = false, bool i114 = false, bool i115 = false, bool i116 = false, bool i117 = false, bool i118 = false, bool i119 = false, bool i120 = false, bool i121 = false, bool i122 = false, bool i123 = false, bool i124 = false, bool i125 = false, bool i126 = false, bool i127 = false, bool i128 = false, bool i129 = false, bool i130 = false) const 
            { return field_list(",", mysqlpp::do_nothing, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15, i16, i17, i18, i19, i20, i21, i22, i23, i24, i25, i26, i27, i28, i29, i30, i31, i32, i33, i34, i35, i36, i37, i38, i39, i40, i41, i42, i43, i44, i45, i46, i47, i48, i49, i50, i51, i52, i53, i54, i55, i56, i57, i58, i59, i60, i61, i62, i63, i64, i65, i66, i67, i68, i69, i70, i71, i72, i73, i74, i75, i76, i77, i78, i79, i80, i81, i82, i83, i84, i85, i86, i87, i88, i89, i90, i91, i92, i93, i94, i95, i96, i97, i98, i99, i100, i101, i102, i103, i104, i105, i106, i107, i108, i109, i110, i111, i112, i113, i114, i115, i116, i117, i118, i119, i120, i121, i122, i123, i124, i125, i126, i127, i128, i129, i130); }
    CUserData_cus_field_list<mysqlpp::do_nothing_type0> field_list(CUserData_enum i1, CUserData_enum i2 = USERDATA_NULL, CUserData_enum i3 = USERDATA_NULL, CUserData_enum i4 = USERDATA_NULL, CUserData_enum i5 = USERDATA_NULL, CUserData_enum i6 = USERDATA_NULL, CUserData_enum i7 = USERDATA_NULL, CUserData_enum i8 = USERDATA_NULL, CUserData_enum i9 = USERDATA_NULL, CUserData_enum i10 = USERDATA_NULL, CUserData_enum i11 = USERDATA_NULL, CUserData_enum i12 = USERDATA_NULL, CUserData_enum i13 = USERDATA_NULL, CUserData_enum i14 = USERDATA_NULL, CUserData_enum i15 = USERDATA_NULL, CUserData_enum i16 = USERDATA_NULL, CUserData_enum i17 = USERDATA_NULL, CUserData_enum i18 = USERDATA_NULL, CUserData_enum i19 = USERDATA_NULL, CUserData_enum i20 = USERDATA_NULL, CUserData_enum i21 = USERDATA_NULL, CUserData_enum i22 = USERDATA_NULL, CUserData_enum i23 = USERDATA_NULL, CUserData_enum i24 = USERDATA_NULL, CUserData_enum i25 = USERDATA_NULL, CUserData_enum i26 = USERDATA_NULL, CUserData_enum i27 = USERDATA_NULL, CUserData_enum i28 = USERDATA_NULL, CUserData_enum i29 = USERDATA_NULL, CUserData_enum i30 = USERDATA_NULL, CUserData_enum i31 = USERDATA_NULL, CUserData_enum i32 = USERDATA_NULL, CUserData_enum i33 = USERDATA_NULL, CUserData_enum i34 = USERDATA_NULL, CUserData_enum i35 = USERDATA_NULL, CUserData_enum i36 = USERDATA_NULL, CUserData_enum i37 = USERDATA_NULL, CUserData_enum i38 = USERDATA_NULL, CUserData_enum i39 = USERDATA_NULL, CUserData_enum i40 = USERDATA_NULL, CUserData_enum i41 = USERDATA_NULL, CUserData_enum i42 = USERDATA_NULL, CUserData_enum i43 = USERDATA_NULL, CUserData_enum i44 = USERDATA_NULL, CUserData_enum i45 = USERDATA_NULL, CUserData_enum i46 = USERDATA_NULL, CUserData_enum i47 = USERDATA_NULL, CUserData_enum i48 = USERDATA_NULL, CUserData_enum i49 = USERDATA_NULL, CUserData_enum i50 = USERDATA_NULL, CUserData_enum i51 = USERDATA_NULL, CUserData_enum i52 = USERDATA_NULL, CUserData_enum i53 = USERDATA_NULL, CUserData_enum i54 = USERDATA_NULL, CUserData_enum i55 = USERDATA_NULL, CUserData_enum i56 = USERDATA_NULL, CUserData_enum i57 = USERDATA_NULL, CUserData_enum i58 = USERDATA_NULL, CUserData_enum i59 = USERDATA_NULL, CUserData_enum i60 = USERDATA_NULL, CUserData_enum i61 = USERDATA_NULL, CUserData_enum i62 = USERDATA_NULL, CUserData_enum i63 = USERDATA_NULL, CUserData_enum i64 = USERDATA_NULL, CUserData_enum i65 = USERDATA_NULL, CUserData_enum i66 = USERDATA_NULL, CUserData_enum i67 = USERDATA_NULL, CUserData_enum i68 = USERDATA_NULL, CUserData_enum i69 = USERDATA_NULL, CUserData_enum i70 = USERDATA_NULL, CUserData_enum i71 = USERDATA_NULL, CUserData_enum i72 = USERDATA_NULL, CUserData_enum i73 = USERDATA_NULL, CUserData_enum i74 = USERDATA_NULL, CUserData_enum i75 = USERDATA_NULL, CUserData_enum i76 = USERDATA_NULL, CUserData_enum i77 = USERDATA_NULL, CUserData_enum i78 = USERDATA_NULL, CUserData_enum i79 = USERDATA_NULL, CUserData_enum i80 = USERDATA_NULL, CUserData_enum i81 = USERDATA_NULL, CUserData_enum i82 = USERDATA_NULL, CUserData_enum i83 = USERDATA_NULL, CUserData_enum i84 = USERDATA_NULL, CUserData_enum i85 = USERDATA_NULL, CUserData_enum i86 = USERDATA_NULL, CUserData_enum i87 = USERDATA_NULL, CUserData_enum i88 = USERDATA_NULL, CUserData_enum i89 = USERDATA_NULL, CUserData_enum i90 = USERDATA_NULL, CUserData_enum i91 = USERDATA_NULL, CUserData_enum i92 = USERDATA_NULL, CUserData_enum i93 = USERDATA_NULL, CUserData_enum i94 = USERDATA_NULL, CUserData_enum i95 = USERDATA_NULL, CUserData_enum i96 = USERDATA_NULL, CUserData_enum i97 = USERDATA_NULL, CUserData_enum i98 = USERDATA_NULL, CUserData_enum i99 = USERDATA_NULL, CUserData_enum i100 = USERDATA_NULL, CUserData_enum i101 = USERDATA_NULL, CUserData_enum i102 = USERDATA_NULL, CUserData_enum i103 = USERDATA_NULL, CUserData_enum i104 = USERDATA_NULL, CUserData_enum i105 = USERDATA_NULL, CUserData_enum i106 = USERDATA_NULL, CUserData_enum i107 = USERDATA_NULL, CUserData_enum i108 = USERDATA_NULL, CUserData_enum i109 = USERDATA_NULL, CUserData_enum i110 = USERDATA_NULL, CUserData_enum i111 = USERDATA_NULL, CUserData_enum i112 = USERDATA_NULL, CUserData_enum i113 = USERDATA_NULL, CUserData_enum i114 = USERDATA_NULL, CUserData_enum i115 = USERDATA_NULL, CUserData_enum i116 = USERDATA_NULL, CUserData_enum i117 = USERDATA_NULL, CUserData_enum i118 = USERDATA_NULL, CUserData_enum i119 = USERDATA_NULL, CUserData_enum i120 = USERDATA_NULL, CUserData_enum i121 = USERDATA_NULL, CUserData_enum i122 = USERDATA_NULL, CUserData_enum i123 = USERDATA_NULL, CUserData_enum i124 = USERDATA_NULL, CUserData_enum i125 = USERDATA_NULL, CUserData_enum i126 = USERDATA_NULL, CUserData_enum i127 = USERDATA_NULL, CUserData_enum i128 = USERDATA_NULL, CUserData_enum i129 = USERDATA_NULL, CUserData_enum i130 = USERDATA_NULL) const
            { return field_list(",", mysqlpp::do_nothing, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15, i16, i17, i18, i19, i20, i21, i22, i23, i24, i25, i26, i27, i28, i29, i30, i31, i32, i33, i34, i35, i36, i37, i38, i39, i40, i41, i42, i43, i44, i45, i46, i47, i48, i49, i50, i51, i52, i53, i54, i55, i56, i57, i58, i59, i60, i61, i62, i63, i64, i65, i66, i67, i68, i69, i70, i71, i72, i73, i74, i75, i76, i77, i78, i79, i80, i81, i82, i83, i84, i85, i86, i87, i88, i89, i90, i91, i92, i93, i94, i95, i96, i97, i98, i99, i100, i101, i102, i103, i104, i105, i106, i107, i108, i109, i110, i111, i112, i113, i114, i115, i116, i117, i118, i119, i120, i121, i122, i123, i124, i125, i126, i127, i128, i129, i130); }
    CUserData_cus_field_list<mysqlpp::do_nothing_type0> field_list(std::vector<bool> *i) const
            { return field_list(",", mysqlpp::do_nothing, i); }
    CUserData_cus_field_list<mysqlpp::do_nothing_type0> field_list(mysqlpp::sql_cmp_type sc) const
            { return field_list(",", mysqlpp::do_nothing, sc); }

    CUserData_cus_field_list<mysqlpp::do_nothing_type0> field_list(const char* d,
            bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false, bool i9 = false, bool i10 = false, bool i11 = false, bool i12 = false, bool i13 = false, bool i14 = false, bool i15 = false, bool i16 = false, bool i17 = false, bool i18 = false, bool i19 = false, bool i20 = false, bool i21 = false, bool i22 = false, bool i23 = false, bool i24 = false, bool i25 = false, bool i26 = false, bool i27 = false, bool i28 = false, bool i29 = false, bool i30 = false, bool i31 = false, bool i32 = false, bool i33 = false, bool i34 = false, bool i35 = false, bool i36 = false, bool i37 = false, bool i38 = false, bool i39 = false, bool i40 = false, bool i41 = false, bool i42 = false, bool i43 = false, bool i44 = false, bool i45 = false, bool i46 = false, bool i47 = false, bool i48 = false, bool i49 = false, bool i50 = false, bool i51 = false, bool i52 = false, bool i53 = false, bool i54 = false, bool i55 = false, bool i56 = false, bool i57 = false, bool i58 = false, bool i59 = false, bool i60 = false, bool i61 = false, bool i62 = false, bool i63 = false, bool i64 = false, bool i65 = false, bool i66 = false, bool i67 = false, bool i68 = false, bool i69 = false, bool i70 = false, bool i71 = false, bool i72 = false, bool i73 = false, bool i74 = false, bool i75 = false, bool i76 = false, bool i77 = false, bool i78 = false, bool i79 = false, bool i80 = false, bool i81 = false, bool i82 = false, bool i83 = false, bool i84 = false, bool i85 = false, bool i86 = false, bool i87 = false, bool i88 = false, bool i89 = false, bool i90 = false, bool i91 = false, bool i92 = false, bool i93 = false, bool i94 = false, bool i95 = false, bool i96 = false, bool i97 = false, bool i98 = false, bool i99 = false, bool i100 = false, bool i101 = false, bool i102 = false, bool i103 = false, bool i104 = false, bool i105 = false, bool i106 = false, bool i107 = false, bool i108 = false, bool i109 = false, bool i110 = false, bool i111 = false, bool i112 = false, bool i113 = false, bool i114 = false, bool i115 = false, bool i116 = false, bool i117 = false, bool i118 = false, bool i119 = false, bool i120 = false, bool i121 = false, bool i122 = false, bool i123 = false, bool i124 = false, bool i125 = false, bool i126 = false, bool i127 = false, bool i128 = false, bool i129 = false, bool i130 = false) const
            { return field_list(d, mysqlpp::do_nothing, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15, i16, i17, i18, i19, i20, i21, i22, i23, i24, i25, i26, i27, i28, i29, i30, i31, i32, i33, i34, i35, i36, i37, i38, i39, i40, i41, i42, i43, i44, i45, i46, i47, i48, i49, i50, i51, i52, i53, i54, i55, i56, i57, i58, i59, i60, i61, i62, i63, i64, i65, i66, i67, i68, i69, i70, i71, i72, i73, i74, i75, i76, i77, i78, i79, i80, i81, i82, i83, i84, i85, i86, i87, i88, i89, i90, i91, i92, i93, i94, i95, i96, i97, i98, i99, i100, i101, i102, i103, i104, i105, i106, i107, i108, i109, i110, i111, i112, i113, i114, i115, i116, i117, i118, i119, i120, i121, i122, i123, i124, i125, i126, i127, i128, i129, i130); }
    CUserData_cus_field_list<mysqlpp::do_nothing_type0> field_list(const char* d,
            CUserData_enum i1, CUserData_enum i2 = USERDATA_NULL, CUserData_enum i3 = USERDATA_NULL, CUserData_enum i4 = USERDATA_NULL, CUserData_enum i5 = USERDATA_NULL, CUserData_enum i6 = USERDATA_NULL, CUserData_enum i7 = USERDATA_NULL, CUserData_enum i8 = USERDATA_NULL, CUserData_enum i9 = USERDATA_NULL, CUserData_enum i10 = USERDATA_NULL, CUserData_enum i11 = USERDATA_NULL, CUserData_enum i12 = USERDATA_NULL, CUserData_enum i13 = USERDATA_NULL, CUserData_enum i14 = USERDATA_NULL, CUserData_enum i15 = USERDATA_NULL, CUserData_enum i16 = USERDATA_NULL, CUserData_enum i17 = USERDATA_NULL, CUserData_enum i18 = USERDATA_NULL, CUserData_enum i19 = USERDATA_NULL, CUserData_enum i20 = USERDATA_NULL, CUserData_enum i21 = USERDATA_NULL, CUserData_enum i22 = USERDATA_NULL, CUserData_enum i23 = USERDATA_NULL, CUserData_enum i24 = USERDATA_NULL, CUserData_enum i25 = USERDATA_NULL, CUserData_enum i26 = USERDATA_NULL, CUserData_enum i27 = USERDATA_NULL, CUserData_enum i28 = USERDATA_NULL, CUserData_enum i29 = USERDATA_NULL, CUserData_enum i30 = USERDATA_NULL, CUserData_enum i31 = USERDATA_NULL, CUserData_enum i32 = USERDATA_NULL, CUserData_enum i33 = USERDATA_NULL, CUserData_enum i34 = USERDATA_NULL, CUserData_enum i35 = USERDATA_NULL, CUserData_enum i36 = USERDATA_NULL, CUserData_enum i37 = USERDATA_NULL, CUserData_enum i38 = USERDATA_NULL, CUserData_enum i39 = USERDATA_NULL, CUserData_enum i40 = USERDATA_NULL, CUserData_enum i41 = USERDATA_NULL, CUserData_enum i42 = USERDATA_NULL, CUserData_enum i43 = USERDATA_NULL, CUserData_enum i44 = USERDATA_NULL, CUserData_enum i45 = USERDATA_NULL, CUserData_enum i46 = USERDATA_NULL, CUserData_enum i47 = USERDATA_NULL, CUserData_enum i48 = USERDATA_NULL, CUserData_enum i49 = USERDATA_NULL, CUserData_enum i50 = USERDATA_NULL, CUserData_enum i51 = USERDATA_NULL, CUserData_enum i52 = USERDATA_NULL, CUserData_enum i53 = USERDATA_NULL, CUserData_enum i54 = USERDATA_NULL, CUserData_enum i55 = USERDATA_NULL, CUserData_enum i56 = USERDATA_NULL, CUserData_enum i57 = USERDATA_NULL, CUserData_enum i58 = USERDATA_NULL, CUserData_enum i59 = USERDATA_NULL, CUserData_enum i60 = USERDATA_NULL, CUserData_enum i61 = USERDATA_NULL, CUserData_enum i62 = USERDATA_NULL, CUserData_enum i63 = USERDATA_NULL, CUserData_enum i64 = USERDATA_NULL, CUserData_enum i65 = USERDATA_NULL, CUserData_enum i66 = USERDATA_NULL, CUserData_enum i67 = USERDATA_NULL, CUserData_enum i68 = USERDATA_NULL, CUserData_enum i69 = USERDATA_NULL, CUserData_enum i70 = USERDATA_NULL, CUserData_enum i71 = USERDATA_NULL, CUserData_enum i72 = USERDATA_NULL, CUserData_enum i73 = USERDATA_NULL, CUserData_enum i74 = USERDATA_NULL, CUserData_enum i75 = USERDATA_NULL, CUserData_enum i76 = USERDATA_NULL, CUserData_enum i77 = USERDATA_NULL, CUserData_enum i78 = USERDATA_NULL, CUserData_enum i79 = USERDATA_NULL, CUserData_enum i80 = USERDATA_NULL, CUserData_enum i81 = USERDATA_NULL, CUserData_enum i82 = USERDATA_NULL, CUserData_enum i83 = USERDATA_NULL, CUserData_enum i84 = USERDATA_NULL, CUserData_enum i85 = USERDATA_NULL, CUserData_enum i86 = USERDATA_NULL, CUserData_enum i87 = USERDATA_NULL, CUserData_enum i88 = USERDATA_NULL, CUserData_enum i89 = USERDATA_NULL, CUserData_enum i90 = USERDATA_NULL, CUserData_enum i91 = USERDATA_NULL, CUserData_enum i92 = USERDATA_NULL, CUserData_enum i93 = USERDATA_NULL, CUserData_enum i94 = USERDATA_NULL, CUserData_enum i95 = USERDATA_NULL, CUserData_enum i96 = USERDATA_NULL, CUserData_enum i97 = USERDATA_NULL, CUserData_enum i98 = USERDATA_NULL, CUserData_enum i99 = USERDATA_NULL, CUserData_enum i100 = USERDATA_NULL, CUserData_enum i101 = USERDATA_NULL, CUserData_enum i102 = USERDATA_NULL, CUserData_enum i103 = USERDATA_NULL, CUserData_enum i104 = USERDATA_NULL, CUserData_enum i105 = USERDATA_NULL, CUserData_enum i106 = USERDATA_NULL, CUserData_enum i107 = USERDATA_NULL, CUserData_enum i108 = USERDATA_NULL, CUserData_enum i109 = USERDATA_NULL, CUserData_enum i110 = USERDATA_NULL, CUserData_enum i111 = USERDATA_NULL, CUserData_enum i112 = USERDATA_NULL, CUserData_enum i113 = USERDATA_NULL, CUserData_enum i114 = USERDATA_NULL, CUserData_enum i115 = USERDATA_NULL, CUserData_enum i116 = USERDATA_NULL, CUserData_enum i117 = USERDATA_NULL, CUserData_enum i118 = USERDATA_NULL, CUserData_enum i119 = USERDATA_NULL, CUserData_enum i120 = USERDATA_NULL, CUserData_enum i121 = USERDATA_NULL, CUserData_enum i122 = USERDATA_NULL, CUserData_enum i123 = USERDATA_NULL, CUserData_enum i124 = USERDATA_NULL, CUserData_enum i125 = USERDATA_NULL, CUserData_enum i126 = USERDATA_NULL, CUserData_enum i127 = USERDATA_NULL, CUserData_enum i128 = USERDATA_NULL, CUserData_enum i129 = USERDATA_NULL, CUserData_enum i130 = USERDATA_NULL) const
            { return field_list(d, mysqlpp::do_nothing, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15, i16, i17, i18, i19, i20, i21, i22, i23, i24, i25, i26, i27, i28, i29, i30, i31, i32, i33, i34, i35, i36, i37, i38, i39, i40, i41, i42, i43, i44, i45, i46, i47, i48, i49, i50, i51, i52, i53, i54, i55, i56, i57, i58, i59, i60, i61, i62, i63, i64, i65, i66, i67, i68, i69, i70, i71, i72, i73, i74, i75, i76, i77, i78, i79, i80, i81, i82, i83, i84, i85, i86, i87, i88, i89, i90, i91, i92, i93, i94, i95, i96, i97, i98, i99, i100, i101, i102, i103, i104, i105, i106, i107, i108, i109, i110, i111, i112, i113, i114, i115, i116, i117, i118, i119, i120, i121, i122, i123, i124, i125, i126, i127, i128, i129, i130); }
    CUserData_cus_field_list<mysqlpp::do_nothing_type0> field_list(const char* d,
            std::vector<bool>* i) const
            { return field_list(d, mysqlpp::do_nothing, i); }
    CUserData_cus_field_list<mysqlpp::do_nothing_type0> field_list(const char* d,
            mysqlpp::sql_cmp_type sc) const
            { return field_list(d, mysqlpp::do_nothing, sc); }

    template <class Manip>
    CUserData_cus_field_list<Manip> field_list(const char* d, Manip m,
            bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false, bool i9 = false, bool i10 = false, bool i11 = false, bool i12 = false, bool i13 = false, bool i14 = false, bool i15 = false, bool i16 = false, bool i17 = false, bool i18 = false, bool i19 = false, bool i20 = false, bool i21 = false, bool i22 = false, bool i23 = false, bool i24 = false, bool i25 = false, bool i26 = false, bool i27 = false, bool i28 = false, bool i29 = false, bool i30 = false, bool i31 = false, bool i32 = false, bool i33 = false, bool i34 = false, bool i35 = false, bool i36 = false, bool i37 = false, bool i38 = false, bool i39 = false, bool i40 = false, bool i41 = false, bool i42 = false, bool i43 = false, bool i44 = false, bool i45 = false, bool i46 = false, bool i47 = false, bool i48 = false, bool i49 = false, bool i50 = false, bool i51 = false, bool i52 = false, bool i53 = false, bool i54 = false, bool i55 = false, bool i56 = false, bool i57 = false, bool i58 = false, bool i59 = false, bool i60 = false, bool i61 = false, bool i62 = false, bool i63 = false, bool i64 = false, bool i65 = false, bool i66 = false, bool i67 = false, bool i68 = false, bool i69 = false, bool i70 = false, bool i71 = false, bool i72 = false, bool i73 = false, bool i74 = false, bool i75 = false, bool i76 = false, bool i77 = false, bool i78 = false, bool i79 = false, bool i80 = false, bool i81 = false, bool i82 = false, bool i83 = false, bool i84 = false, bool i85 = false, bool i86 = false, bool i87 = false, bool i88 = false, bool i89 = false, bool i90 = false, bool i91 = false, bool i92 = false, bool i93 = false, bool i94 = false, bool i95 = false, bool i96 = false, bool i97 = false, bool i98 = false, bool i99 = false, bool i100 = false, bool i101 = false, bool i102 = false, bool i103 = false, bool i104 = false, bool i105 = false, bool i106 = false, bool i107 = false, bool i108 = false, bool i109 = false, bool i110 = false, bool i111 = false, bool i112 = false, bool i113 = false, bool i114 = false, bool i115 = false, bool i116 = false, bool i117 = false, bool i118 = false, bool i119 = false, bool i120 = false, bool i121 = false, bool i122 = false, bool i123 = false, bool i124 = false, bool i125 = false, bool i126 = false, bool i127 = false, bool i128 = false, bool i129 = false, bool i130 = false) const;
    template <class Manip>
    CUserData_cus_field_list<Manip> field_list(const char* d, Manip m,
            CUserData_enum i1, CUserData_enum i2 = USERDATA_NULL, CUserData_enum i3 = USERDATA_NULL, CUserData_enum i4 = USERDATA_NULL, CUserData_enum i5 = USERDATA_NULL, CUserData_enum i6 = USERDATA_NULL, CUserData_enum i7 = USERDATA_NULL, CUserData_enum i8 = USERDATA_NULL, CUserData_enum i9 = USERDATA_NULL, CUserData_enum i10 = USERDATA_NULL, CUserData_enum i11 = USERDATA_NULL, CUserData_enum i12 = USERDATA_NULL, CUserData_enum i13 = USERDATA_NULL, CUserData_enum i14 = USERDATA_NULL, CUserData_enum i15 = USERDATA_NULL, CUserData_enum i16 = USERDATA_NULL, CUserData_enum i17 = USERDATA_NULL, CUserData_enum i18 = USERDATA_NULL, CUserData_enum i19 = USERDATA_NULL, CUserData_enum i20 = USERDATA_NULL, CUserData_enum i21 = USERDATA_NULL, CUserData_enum i22 = USERDATA_NULL, CUserData_enum i23 = USERDATA_NULL, CUserData_enum i24 = USERDATA_NULL, CUserData_enum i25 = USERDATA_NULL, CUserData_enum i26 = USERDATA_NULL, CUserData_enum i27 = USERDATA_NULL, CUserData_enum i28 = USERDATA_NULL, CUserData_enum i29 = USERDATA_NULL, CUserData_enum i30 = USERDATA_NULL, CUserData_enum i31 = USERDATA_NULL, CUserData_enum i32 = USERDATA_NULL, CUserData_enum i33 = USERDATA_NULL, CUserData_enum i34 = USERDATA_NULL, CUserData_enum i35 = USERDATA_NULL, CUserData_enum i36 = USERDATA_NULL, CUserData_enum i37 = USERDATA_NULL, CUserData_enum i38 = USERDATA_NULL, CUserData_enum i39 = USERDATA_NULL, CUserData_enum i40 = USERDATA_NULL, CUserData_enum i41 = USERDATA_NULL, CUserData_enum i42 = USERDATA_NULL, CUserData_enum i43 = USERDATA_NULL, CUserData_enum i44 = USERDATA_NULL, CUserData_enum i45 = USERDATA_NULL, CUserData_enum i46 = USERDATA_NULL, CUserData_enum i47 = USERDATA_NULL, CUserData_enum i48 = USERDATA_NULL, CUserData_enum i49 = USERDATA_NULL, CUserData_enum i50 = USERDATA_NULL, CUserData_enum i51 = USERDATA_NULL, CUserData_enum i52 = USERDATA_NULL, CUserData_enum i53 = USERDATA_NULL, CUserData_enum i54 = USERDATA_NULL, CUserData_enum i55 = USERDATA_NULL, CUserData_enum i56 = USERDATA_NULL, CUserData_enum i57 = USERDATA_NULL, CUserData_enum i58 = USERDATA_NULL, CUserData_enum i59 = USERDATA_NULL, CUserData_enum i60 = USERDATA_NULL, CUserData_enum i61 = USERDATA_NULL, CUserData_enum i62 = USERDATA_NULL, CUserData_enum i63 = USERDATA_NULL, CUserData_enum i64 = USERDATA_NULL, CUserData_enum i65 = USERDATA_NULL, CUserData_enum i66 = USERDATA_NULL, CUserData_enum i67 = USERDATA_NULL, CUserData_enum i68 = USERDATA_NULL, CUserData_enum i69 = USERDATA_NULL, CUserData_enum i70 = USERDATA_NULL, CUserData_enum i71 = USERDATA_NULL, CUserData_enum i72 = USERDATA_NULL, CUserData_enum i73 = USERDATA_NULL, CUserData_enum i74 = USERDATA_NULL, CUserData_enum i75 = USERDATA_NULL, CUserData_enum i76 = USERDATA_NULL, CUserData_enum i77 = USERDATA_NULL, CUserData_enum i78 = USERDATA_NULL, CUserData_enum i79 = USERDATA_NULL, CUserData_enum i80 = USERDATA_NULL, CUserData_enum i81 = USERDATA_NULL, CUserData_enum i82 = USERDATA_NULL, CUserData_enum i83 = USERDATA_NULL, CUserData_enum i84 = USERDATA_NULL, CUserData_enum i85 = USERDATA_NULL, CUserData_enum i86 = USERDATA_NULL, CUserData_enum i87 = USERDATA_NULL, CUserData_enum i88 = USERDATA_NULL, CUserData_enum i89 = USERDATA_NULL, CUserData_enum i90 = USERDATA_NULL, CUserData_enum i91 = USERDATA_NULL, CUserData_enum i92 = USERDATA_NULL, CUserData_enum i93 = USERDATA_NULL, CUserData_enum i94 = USERDATA_NULL, CUserData_enum i95 = USERDATA_NULL, CUserData_enum i96 = USERDATA_NULL, CUserData_enum i97 = USERDATA_NULL, CUserData_enum i98 = USERDATA_NULL, CUserData_enum i99 = USERDATA_NULL, CUserData_enum i100 = USERDATA_NULL, CUserData_enum i101 = USERDATA_NULL, CUserData_enum i102 = USERDATA_NULL, CUserData_enum i103 = USERDATA_NULL, CUserData_enum i104 = USERDATA_NULL, CUserData_enum i105 = USERDATA_NULL, CUserData_enum i106 = USERDATA_NULL, CUserData_enum i107 = USERDATA_NULL, CUserData_enum i108 = USERDATA_NULL, CUserData_enum i109 = USERDATA_NULL, CUserData_enum i110 = USERDATA_NULL, CUserData_enum i111 = USERDATA_NULL, CUserData_enum i112 = USERDATA_NULL, CUserData_enum i113 = USERDATA_NULL, CUserData_enum i114 = USERDATA_NULL, CUserData_enum i115 = USERDATA_NULL, CUserData_enum i116 = USERDATA_NULL, CUserData_enum i117 = USERDATA_NULL, CUserData_enum i118 = USERDATA_NULL, CUserData_enum i119 = USERDATA_NULL, CUserData_enum i120 = USERDATA_NULL, CUserData_enum i121 = USERDATA_NULL, CUserData_enum i122 = USERDATA_NULL, CUserData_enum i123 = USERDATA_NULL, CUserData_enum i124 = USERDATA_NULL, CUserData_enum i125 = USERDATA_NULL, CUserData_enum i126 = USERDATA_NULL, CUserData_enum i127 = USERDATA_NULL, CUserData_enum i128 = USERDATA_NULL, CUserData_enum i129 = USERDATA_NULL, CUserData_enum i130 = USERDATA_NULL) const;
    template <class Manip>
    CUserData_cus_field_list<Manip> field_list(const char* d, Manip m,
            std::vector<bool> *i) const;
    template <class Manip>
    CUserData_cus_field_list<Manip> field_list(const char* d, Manip m,
            mysqlpp::sql_cmp_type sc) const;

    /* cus equal */

    CUserData_cus_equal_list<mysqlpp::quote_type0> equal_list(bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false, bool i9 = false, bool i10 = false, bool i11 = false, bool i12 = false, bool i13 = false, bool i14 = false, bool i15 = false, bool i16 = false, bool i17 = false, bool i18 = false, bool i19 = false, bool i20 = false, bool i21 = false, bool i22 = false, bool i23 = false, bool i24 = false, bool i25 = false, bool i26 = false, bool i27 = false, bool i28 = false, bool i29 = false, bool i30 = false, bool i31 = false, bool i32 = false, bool i33 = false, bool i34 = false, bool i35 = false, bool i36 = false, bool i37 = false, bool i38 = false, bool i39 = false, bool i40 = false, bool i41 = false, bool i42 = false, bool i43 = false, bool i44 = false, bool i45 = false, bool i46 = false, bool i47 = false, bool i48 = false, bool i49 = false, bool i50 = false, bool i51 = false, bool i52 = false, bool i53 = false, bool i54 = false, bool i55 = false, bool i56 = false, bool i57 = false, bool i58 = false, bool i59 = false, bool i60 = false, bool i61 = false, bool i62 = false, bool i63 = false, bool i64 = false, bool i65 = false, bool i66 = false, bool i67 = false, bool i68 = false, bool i69 = false, bool i70 = false, bool i71 = false, bool i72 = false, bool i73 = false, bool i74 = false, bool i75 = false, bool i76 = false, bool i77 = false, bool i78 = false, bool i79 = false, bool i80 = false, bool i81 = false, bool i82 = false, bool i83 = false, bool i84 = false, bool i85 = false, bool i86 = false, bool i87 = false, bool i88 = false, bool i89 = false, bool i90 = false, bool i91 = false, bool i92 = false, bool i93 = false, bool i94 = false, bool i95 = false, bool i96 = false, bool i97 = false, bool i98 = false, bool i99 = false, bool i100 = false, bool i101 = false, bool i102 = false, bool i103 = false, bool i104 = false, bool i105 = false, bool i106 = false, bool i107 = false, bool i108 = false, bool i109 = false, bool i110 = false, bool i111 = false, bool i112 = false, bool i113 = false, bool i114 = false, bool i115 = false, bool i116 = false, bool i117 = false, bool i118 = false, bool i119 = false, bool i120 = false, bool i121 = false, bool i122 = false, bool i123 = false, bool i124 = false, bool i125 = false, bool i126 = false, bool i127 = false, bool i128 = false, bool i129 = false, bool i130 = false) const
            { return equal_list(",", " = ", mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15, i16, i17, i18, i19, i20, i21, i22, i23, i24, i25, i26, i27, i28, i29, i30, i31, i32, i33, i34, i35, i36, i37, i38, i39, i40, i41, i42, i43, i44, i45, i46, i47, i48, i49, i50, i51, i52, i53, i54, i55, i56, i57, i58, i59, i60, i61, i62, i63, i64, i65, i66, i67, i68, i69, i70, i71, i72, i73, i74, i75, i76, i77, i78, i79, i80, i81, i82, i83, i84, i85, i86, i87, i88, i89, i90, i91, i92, i93, i94, i95, i96, i97, i98, i99, i100, i101, i102, i103, i104, i105, i106, i107, i108, i109, i110, i111, i112, i113, i114, i115, i116, i117, i118, i119, i120, i121, i122, i123, i124, i125, i126, i127, i128, i129, i130); }
    CUserData_cus_equal_list<mysqlpp::quote_type0> equal_list(CUserData_enum i1, CUserData_enum i2 = USERDATA_NULL, CUserData_enum i3 = USERDATA_NULL, CUserData_enum i4 = USERDATA_NULL, CUserData_enum i5 = USERDATA_NULL, CUserData_enum i6 = USERDATA_NULL, CUserData_enum i7 = USERDATA_NULL, CUserData_enum i8 = USERDATA_NULL, CUserData_enum i9 = USERDATA_NULL, CUserData_enum i10 = USERDATA_NULL, CUserData_enum i11 = USERDATA_NULL, CUserData_enum i12 = USERDATA_NULL, CUserData_enum i13 = USERDATA_NULL, CUserData_enum i14 = USERDATA_NULL, CUserData_enum i15 = USERDATA_NULL, CUserData_enum i16 = USERDATA_NULL, CUserData_enum i17 = USERDATA_NULL, CUserData_enum i18 = USERDATA_NULL, CUserData_enum i19 = USERDATA_NULL, CUserData_enum i20 = USERDATA_NULL, CUserData_enum i21 = USERDATA_NULL, CUserData_enum i22 = USERDATA_NULL, CUserData_enum i23 = USERDATA_NULL, CUserData_enum i24 = USERDATA_NULL, CUserData_enum i25 = USERDATA_NULL, CUserData_enum i26 = USERDATA_NULL, CUserData_enum i27 = USERDATA_NULL, CUserData_enum i28 = USERDATA_NULL, CUserData_enum i29 = USERDATA_NULL, CUserData_enum i30 = USERDATA_NULL, CUserData_enum i31 = USERDATA_NULL, CUserData_enum i32 = USERDATA_NULL, CUserData_enum i33 = USERDATA_NULL, CUserData_enum i34 = USERDATA_NULL, CUserData_enum i35 = USERDATA_NULL, CUserData_enum i36 = USERDATA_NULL, CUserData_enum i37 = USERDATA_NULL, CUserData_enum i38 = USERDATA_NULL, CUserData_enum i39 = USERDATA_NULL, CUserData_enum i40 = USERDATA_NULL, CUserData_enum i41 = USERDATA_NULL, CUserData_enum i42 = USERDATA_NULL, CUserData_enum i43 = USERDATA_NULL, CUserData_enum i44 = USERDATA_NULL, CUserData_enum i45 = USERDATA_NULL, CUserData_enum i46 = USERDATA_NULL, CUserData_enum i47 = USERDATA_NULL, CUserData_enum i48 = USERDATA_NULL, CUserData_enum i49 = USERDATA_NULL, CUserData_enum i50 = USERDATA_NULL, CUserData_enum i51 = USERDATA_NULL, CUserData_enum i52 = USERDATA_NULL, CUserData_enum i53 = USERDATA_NULL, CUserData_enum i54 = USERDATA_NULL, CUserData_enum i55 = USERDATA_NULL, CUserData_enum i56 = USERDATA_NULL, CUserData_enum i57 = USERDATA_NULL, CUserData_enum i58 = USERDATA_NULL, CUserData_enum i59 = USERDATA_NULL, CUserData_enum i60 = USERDATA_NULL, CUserData_enum i61 = USERDATA_NULL, CUserData_enum i62 = USERDATA_NULL, CUserData_enum i63 = USERDATA_NULL, CUserData_enum i64 = USERDATA_NULL, CUserData_enum i65 = USERDATA_NULL, CUserData_enum i66 = USERDATA_NULL, CUserData_enum i67 = USERDATA_NULL, CUserData_enum i68 = USERDATA_NULL, CUserData_enum i69 = USERDATA_NULL, CUserData_enum i70 = USERDATA_NULL, CUserData_enum i71 = USERDATA_NULL, CUserData_enum i72 = USERDATA_NULL, CUserData_enum i73 = USERDATA_NULL, CUserData_enum i74 = USERDATA_NULL, CUserData_enum i75 = USERDATA_NULL, CUserData_enum i76 = USERDATA_NULL, CUserData_enum i77 = USERDATA_NULL, CUserData_enum i78 = USERDATA_NULL, CUserData_enum i79 = USERDATA_NULL, CUserData_enum i80 = USERDATA_NULL, CUserData_enum i81 = USERDATA_NULL, CUserData_enum i82 = USERDATA_NULL, CUserData_enum i83 = USERDATA_NULL, CUserData_enum i84 = USERDATA_NULL, CUserData_enum i85 = USERDATA_NULL, CUserData_enum i86 = USERDATA_NULL, CUserData_enum i87 = USERDATA_NULL, CUserData_enum i88 = USERDATA_NULL, CUserData_enum i89 = USERDATA_NULL, CUserData_enum i90 = USERDATA_NULL, CUserData_enum i91 = USERDATA_NULL, CUserData_enum i92 = USERDATA_NULL, CUserData_enum i93 = USERDATA_NULL, CUserData_enum i94 = USERDATA_NULL, CUserData_enum i95 = USERDATA_NULL, CUserData_enum i96 = USERDATA_NULL, CUserData_enum i97 = USERDATA_NULL, CUserData_enum i98 = USERDATA_NULL, CUserData_enum i99 = USERDATA_NULL, CUserData_enum i100 = USERDATA_NULL, CUserData_enum i101 = USERDATA_NULL, CUserData_enum i102 = USERDATA_NULL, CUserData_enum i103 = USERDATA_NULL, CUserData_enum i104 = USERDATA_NULL, CUserData_enum i105 = USERDATA_NULL, CUserData_enum i106 = USERDATA_NULL, CUserData_enum i107 = USERDATA_NULL, CUserData_enum i108 = USERDATA_NULL, CUserData_enum i109 = USERDATA_NULL, CUserData_enum i110 = USERDATA_NULL, CUserData_enum i111 = USERDATA_NULL, CUserData_enum i112 = USERDATA_NULL, CUserData_enum i113 = USERDATA_NULL, CUserData_enum i114 = USERDATA_NULL, CUserData_enum i115 = USERDATA_NULL, CUserData_enum i116 = USERDATA_NULL, CUserData_enum i117 = USERDATA_NULL, CUserData_enum i118 = USERDATA_NULL, CUserData_enum i119 = USERDATA_NULL, CUserData_enum i120 = USERDATA_NULL, CUserData_enum i121 = USERDATA_NULL, CUserData_enum i122 = USERDATA_NULL, CUserData_enum i123 = USERDATA_NULL, CUserData_enum i124 = USERDATA_NULL, CUserData_enum i125 = USERDATA_NULL, CUserData_enum i126 = USERDATA_NULL, CUserData_enum i127 = USERDATA_NULL, CUserData_enum i128 = USERDATA_NULL, CUserData_enum i129 = USERDATA_NULL, CUserData_enum i130 = USERDATA_NULL) const
            { return equal_list(",", " = ", mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15, i16, i17, i18, i19, i20, i21, i22, i23, i24, i25, i26, i27, i28, i29, i30, i31, i32, i33, i34, i35, i36, i37, i38, i39, i40, i41, i42, i43, i44, i45, i46, i47, i48, i49, i50, i51, i52, i53, i54, i55, i56, i57, i58, i59, i60, i61, i62, i63, i64, i65, i66, i67, i68, i69, i70, i71, i72, i73, i74, i75, i76, i77, i78, i79, i80, i81, i82, i83, i84, i85, i86, i87, i88, i89, i90, i91, i92, i93, i94, i95, i96, i97, i98, i99, i100, i101, i102, i103, i104, i105, i106, i107, i108, i109, i110, i111, i112, i113, i114, i115, i116, i117, i118, i119, i120, i121, i122, i123, i124, i125, i126, i127, i128, i129, i130); }
    CUserData_cus_equal_list<mysqlpp::quote_type0> equal_list(std::vector<bool>* i) const
            { return equal_list(",", " = ", mysqlpp::quote, i); }
    CUserData_cus_equal_list<mysqlpp::quote_type0> equal_list(mysqlpp::sql_cmp_type sc) const
            { return equal_list(",", " = ", mysqlpp::quote, sc); }

    CUserData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d, bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false, bool i9 = false, bool i10 = false, bool i11 = false, bool i12 = false, bool i13 = false, bool i14 = false, bool i15 = false, bool i16 = false, bool i17 = false, bool i18 = false, bool i19 = false, bool i20 = false, bool i21 = false, bool i22 = false, bool i23 = false, bool i24 = false, bool i25 = false, bool i26 = false, bool i27 = false, bool i28 = false, bool i29 = false, bool i30 = false, bool i31 = false, bool i32 = false, bool i33 = false, bool i34 = false, bool i35 = false, bool i36 = false, bool i37 = false, bool i38 = false, bool i39 = false, bool i40 = false, bool i41 = false, bool i42 = false, bool i43 = false, bool i44 = false, bool i45 = false, bool i46 = false, bool i47 = false, bool i48 = false, bool i49 = false, bool i50 = false, bool i51 = false, bool i52 = false, bool i53 = false, bool i54 = false, bool i55 = false, bool i56 = false, bool i57 = false, bool i58 = false, bool i59 = false, bool i60 = false, bool i61 = false, bool i62 = false, bool i63 = false, bool i64 = false, bool i65 = false, bool i66 = false, bool i67 = false, bool i68 = false, bool i69 = false, bool i70 = false, bool i71 = false, bool i72 = false, bool i73 = false, bool i74 = false, bool i75 = false, bool i76 = false, bool i77 = false, bool i78 = false, bool i79 = false, bool i80 = false, bool i81 = false, bool i82 = false, bool i83 = false, bool i84 = false, bool i85 = false, bool i86 = false, bool i87 = false, bool i88 = false, bool i89 = false, bool i90 = false, bool i91 = false, bool i92 = false, bool i93 = false, bool i94 = false, bool i95 = false, bool i96 = false, bool i97 = false, bool i98 = false, bool i99 = false, bool i100 = false, bool i101 = false, bool i102 = false, bool i103 = false, bool i104 = false, bool i105 = false, bool i106 = false, bool i107 = false, bool i108 = false, bool i109 = false, bool i110 = false, bool i111 = false, bool i112 = false, bool i113 = false, bool i114 = false, bool i115 = false, bool i116 = false, bool i117 = false, bool i118 = false, bool i119 = false, bool i120 = false, bool i121 = false, bool i122 = false, bool i123 = false, bool i124 = false, bool i125 = false, bool i126 = false, bool i127 = false, bool i128 = false, bool i129 = false, bool i130 = false) const
            { return equal_list(d, " = ", mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15, i16, i17, i18, i19, i20, i21, i22, i23, i24, i25, i26, i27, i28, i29, i30, i31, i32, i33, i34, i35, i36, i37, i38, i39, i40, i41, i42, i43, i44, i45, i46, i47, i48, i49, i50, i51, i52, i53, i54, i55, i56, i57, i58, i59, i60, i61, i62, i63, i64, i65, i66, i67, i68, i69, i70, i71, i72, i73, i74, i75, i76, i77, i78, i79, i80, i81, i82, i83, i84, i85, i86, i87, i88, i89, i90, i91, i92, i93, i94, i95, i96, i97, i98, i99, i100, i101, i102, i103, i104, i105, i106, i107, i108, i109, i110, i111, i112, i113, i114, i115, i116, i117, i118, i119, i120, i121, i122, i123, i124, i125, i126, i127, i128, i129, i130); }
    CUserData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d, CUserData_enum i1, CUserData_enum i2 = USERDATA_NULL, CUserData_enum i3 = USERDATA_NULL, CUserData_enum i4 = USERDATA_NULL, CUserData_enum i5 = USERDATA_NULL, CUserData_enum i6 = USERDATA_NULL, CUserData_enum i7 = USERDATA_NULL, CUserData_enum i8 = USERDATA_NULL, CUserData_enum i9 = USERDATA_NULL, CUserData_enum i10 = USERDATA_NULL, CUserData_enum i11 = USERDATA_NULL, CUserData_enum i12 = USERDATA_NULL, CUserData_enum i13 = USERDATA_NULL, CUserData_enum i14 = USERDATA_NULL, CUserData_enum i15 = USERDATA_NULL, CUserData_enum i16 = USERDATA_NULL, CUserData_enum i17 = USERDATA_NULL, CUserData_enum i18 = USERDATA_NULL, CUserData_enum i19 = USERDATA_NULL, CUserData_enum i20 = USERDATA_NULL, CUserData_enum i21 = USERDATA_NULL, CUserData_enum i22 = USERDATA_NULL, CUserData_enum i23 = USERDATA_NULL, CUserData_enum i24 = USERDATA_NULL, CUserData_enum i25 = USERDATA_NULL, CUserData_enum i26 = USERDATA_NULL, CUserData_enum i27 = USERDATA_NULL, CUserData_enum i28 = USERDATA_NULL, CUserData_enum i29 = USERDATA_NULL, CUserData_enum i30 = USERDATA_NULL, CUserData_enum i31 = USERDATA_NULL, CUserData_enum i32 = USERDATA_NULL, CUserData_enum i33 = USERDATA_NULL, CUserData_enum i34 = USERDATA_NULL, CUserData_enum i35 = USERDATA_NULL, CUserData_enum i36 = USERDATA_NULL, CUserData_enum i37 = USERDATA_NULL, CUserData_enum i38 = USERDATA_NULL, CUserData_enum i39 = USERDATA_NULL, CUserData_enum i40 = USERDATA_NULL, CUserData_enum i41 = USERDATA_NULL, CUserData_enum i42 = USERDATA_NULL, CUserData_enum i43 = USERDATA_NULL, CUserData_enum i44 = USERDATA_NULL, CUserData_enum i45 = USERDATA_NULL, CUserData_enum i46 = USERDATA_NULL, CUserData_enum i47 = USERDATA_NULL, CUserData_enum i48 = USERDATA_NULL, CUserData_enum i49 = USERDATA_NULL, CUserData_enum i50 = USERDATA_NULL, CUserData_enum i51 = USERDATA_NULL, CUserData_enum i52 = USERDATA_NULL, CUserData_enum i53 = USERDATA_NULL, CUserData_enum i54 = USERDATA_NULL, CUserData_enum i55 = USERDATA_NULL, CUserData_enum i56 = USERDATA_NULL, CUserData_enum i57 = USERDATA_NULL, CUserData_enum i58 = USERDATA_NULL, CUserData_enum i59 = USERDATA_NULL, CUserData_enum i60 = USERDATA_NULL, CUserData_enum i61 = USERDATA_NULL, CUserData_enum i62 = USERDATA_NULL, CUserData_enum i63 = USERDATA_NULL, CUserData_enum i64 = USERDATA_NULL, CUserData_enum i65 = USERDATA_NULL, CUserData_enum i66 = USERDATA_NULL, CUserData_enum i67 = USERDATA_NULL, CUserData_enum i68 = USERDATA_NULL, CUserData_enum i69 = USERDATA_NULL, CUserData_enum i70 = USERDATA_NULL, CUserData_enum i71 = USERDATA_NULL, CUserData_enum i72 = USERDATA_NULL, CUserData_enum i73 = USERDATA_NULL, CUserData_enum i74 = USERDATA_NULL, CUserData_enum i75 = USERDATA_NULL, CUserData_enum i76 = USERDATA_NULL, CUserData_enum i77 = USERDATA_NULL, CUserData_enum i78 = USERDATA_NULL, CUserData_enum i79 = USERDATA_NULL, CUserData_enum i80 = USERDATA_NULL, CUserData_enum i81 = USERDATA_NULL, CUserData_enum i82 = USERDATA_NULL, CUserData_enum i83 = USERDATA_NULL, CUserData_enum i84 = USERDATA_NULL, CUserData_enum i85 = USERDATA_NULL, CUserData_enum i86 = USERDATA_NULL, CUserData_enum i87 = USERDATA_NULL, CUserData_enum i88 = USERDATA_NULL, CUserData_enum i89 = USERDATA_NULL, CUserData_enum i90 = USERDATA_NULL, CUserData_enum i91 = USERDATA_NULL, CUserData_enum i92 = USERDATA_NULL, CUserData_enum i93 = USERDATA_NULL, CUserData_enum i94 = USERDATA_NULL, CUserData_enum i95 = USERDATA_NULL, CUserData_enum i96 = USERDATA_NULL, CUserData_enum i97 = USERDATA_NULL, CUserData_enum i98 = USERDATA_NULL, CUserData_enum i99 = USERDATA_NULL, CUserData_enum i100 = USERDATA_NULL, CUserData_enum i101 = USERDATA_NULL, CUserData_enum i102 = USERDATA_NULL, CUserData_enum i103 = USERDATA_NULL, CUserData_enum i104 = USERDATA_NULL, CUserData_enum i105 = USERDATA_NULL, CUserData_enum i106 = USERDATA_NULL, CUserData_enum i107 = USERDATA_NULL, CUserData_enum i108 = USERDATA_NULL, CUserData_enum i109 = USERDATA_NULL, CUserData_enum i110 = USERDATA_NULL, CUserData_enum i111 = USERDATA_NULL, CUserData_enum i112 = USERDATA_NULL, CUserData_enum i113 = USERDATA_NULL, CUserData_enum i114 = USERDATA_NULL, CUserData_enum i115 = USERDATA_NULL, CUserData_enum i116 = USERDATA_NULL, CUserData_enum i117 = USERDATA_NULL, CUserData_enum i118 = USERDATA_NULL, CUserData_enum i119 = USERDATA_NULL, CUserData_enum i120 = USERDATA_NULL, CUserData_enum i121 = USERDATA_NULL, CUserData_enum i122 = USERDATA_NULL, CUserData_enum i123 = USERDATA_NULL, CUserData_enum i124 = USERDATA_NULL, CUserData_enum i125 = USERDATA_NULL, CUserData_enum i126 = USERDATA_NULL, CUserData_enum i127 = USERDATA_NULL, CUserData_enum i128 = USERDATA_NULL, CUserData_enum i129 = USERDATA_NULL, CUserData_enum i130 = USERDATA_NULL) const
            { return equal_list(d, " = ", mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15, i16, i17, i18, i19, i20, i21, i22, i23, i24, i25, i26, i27, i28, i29, i30, i31, i32, i33, i34, i35, i36, i37, i38, i39, i40, i41, i42, i43, i44, i45, i46, i47, i48, i49, i50, i51, i52, i53, i54, i55, i56, i57, i58, i59, i60, i61, i62, i63, i64, i65, i66, i67, i68, i69, i70, i71, i72, i73, i74, i75, i76, i77, i78, i79, i80, i81, i82, i83, i84, i85, i86, i87, i88, i89, i90, i91, i92, i93, i94, i95, i96, i97, i98, i99, i100, i101, i102, i103, i104, i105, i106, i107, i108, i109, i110, i111, i112, i113, i114, i115, i116, i117, i118, i119, i120, i121, i122, i123, i124, i125, i126, i127, i128, i129, i130); }
    CUserData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d,
            std::vector<bool> *i) const
            { return equal_list(d, " = ", mysqlpp::quote, i); }
    CUserData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d,
            mysqlpp::sql_cmp_type sc) const
            { return equal_list(d, " = ", mysqlpp::quote, sc); }

    CUserData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d, const char* c,
            bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false, bool i9 = false, bool i10 = false, bool i11 = false, bool i12 = false, bool i13 = false, bool i14 = false, bool i15 = false, bool i16 = false, bool i17 = false, bool i18 = false, bool i19 = false, bool i20 = false, bool i21 = false, bool i22 = false, bool i23 = false, bool i24 = false, bool i25 = false, bool i26 = false, bool i27 = false, bool i28 = false, bool i29 = false, bool i30 = false, bool i31 = false, bool i32 = false, bool i33 = false, bool i34 = false, bool i35 = false, bool i36 = false, bool i37 = false, bool i38 = false, bool i39 = false, bool i40 = false, bool i41 = false, bool i42 = false, bool i43 = false, bool i44 = false, bool i45 = false, bool i46 = false, bool i47 = false, bool i48 = false, bool i49 = false, bool i50 = false, bool i51 = false, bool i52 = false, bool i53 = false, bool i54 = false, bool i55 = false, bool i56 = false, bool i57 = false, bool i58 = false, bool i59 = false, bool i60 = false, bool i61 = false, bool i62 = false, bool i63 = false, bool i64 = false, bool i65 = false, bool i66 = false, bool i67 = false, bool i68 = false, bool i69 = false, bool i70 = false, bool i71 = false, bool i72 = false, bool i73 = false, bool i74 = false, bool i75 = false, bool i76 = false, bool i77 = false, bool i78 = false, bool i79 = false, bool i80 = false, bool i81 = false, bool i82 = false, bool i83 = false, bool i84 = false, bool i85 = false, bool i86 = false, bool i87 = false, bool i88 = false, bool i89 = false, bool i90 = false, bool i91 = false, bool i92 = false, bool i93 = false, bool i94 = false, bool i95 = false, bool i96 = false, bool i97 = false, bool i98 = false, bool i99 = false, bool i100 = false, bool i101 = false, bool i102 = false, bool i103 = false, bool i104 = false, bool i105 = false, bool i106 = false, bool i107 = false, bool i108 = false, bool i109 = false, bool i110 = false, bool i111 = false, bool i112 = false, bool i113 = false, bool i114 = false, bool i115 = false, bool i116 = false, bool i117 = false, bool i118 = false, bool i119 = false, bool i120 = false, bool i121 = false, bool i122 = false, bool i123 = false, bool i124 = false, bool i125 = false, bool i126 = false, bool i127 = false, bool i128 = false, bool i129 = false, bool i130 = false) const
            { return equal_list(d, c, mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15, i16, i17, i18, i19, i20, i21, i22, i23, i24, i25, i26, i27, i28, i29, i30, i31, i32, i33, i34, i35, i36, i37, i38, i39, i40, i41, i42, i43, i44, i45, i46, i47, i48, i49, i50, i51, i52, i53, i54, i55, i56, i57, i58, i59, i60, i61, i62, i63, i64, i65, i66, i67, i68, i69, i70, i71, i72, i73, i74, i75, i76, i77, i78, i79, i80, i81, i82, i83, i84, i85, i86, i87, i88, i89, i90, i91, i92, i93, i94, i95, i96, i97, i98, i99, i100, i101, i102, i103, i104, i105, i106, i107, i108, i109, i110, i111, i112, i113, i114, i115, i116, i117, i118, i119, i120, i121, i122, i123, i124, i125, i126, i127, i128, i129, i130); }
    CUserData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d, const char* c,
            CUserData_enum i1, CUserData_enum i2 = USERDATA_NULL, CUserData_enum i3 = USERDATA_NULL, CUserData_enum i4 = USERDATA_NULL, CUserData_enum i5 = USERDATA_NULL, CUserData_enum i6 = USERDATA_NULL, CUserData_enum i7 = USERDATA_NULL, CUserData_enum i8 = USERDATA_NULL, CUserData_enum i9 = USERDATA_NULL, CUserData_enum i10 = USERDATA_NULL, CUserData_enum i11 = USERDATA_NULL, CUserData_enum i12 = USERDATA_NULL, CUserData_enum i13 = USERDATA_NULL, CUserData_enum i14 = USERDATA_NULL, CUserData_enum i15 = USERDATA_NULL, CUserData_enum i16 = USERDATA_NULL, CUserData_enum i17 = USERDATA_NULL, CUserData_enum i18 = USERDATA_NULL, CUserData_enum i19 = USERDATA_NULL, CUserData_enum i20 = USERDATA_NULL, CUserData_enum i21 = USERDATA_NULL, CUserData_enum i22 = USERDATA_NULL, CUserData_enum i23 = USERDATA_NULL, CUserData_enum i24 = USERDATA_NULL, CUserData_enum i25 = USERDATA_NULL, CUserData_enum i26 = USERDATA_NULL, CUserData_enum i27 = USERDATA_NULL, CUserData_enum i28 = USERDATA_NULL, CUserData_enum i29 = USERDATA_NULL, CUserData_enum i30 = USERDATA_NULL, CUserData_enum i31 = USERDATA_NULL, CUserData_enum i32 = USERDATA_NULL, CUserData_enum i33 = USERDATA_NULL, CUserData_enum i34 = USERDATA_NULL, CUserData_enum i35 = USERDATA_NULL, CUserData_enum i36 = USERDATA_NULL, CUserData_enum i37 = USERDATA_NULL, CUserData_enum i38 = USERDATA_NULL, CUserData_enum i39 = USERDATA_NULL, CUserData_enum i40 = USERDATA_NULL, CUserData_enum i41 = USERDATA_NULL, CUserData_enum i42 = USERDATA_NULL, CUserData_enum i43 = USERDATA_NULL, CUserData_enum i44 = USERDATA_NULL, CUserData_enum i45 = USERDATA_NULL, CUserData_enum i46 = USERDATA_NULL, CUserData_enum i47 = USERDATA_NULL, CUserData_enum i48 = USERDATA_NULL, CUserData_enum i49 = USERDATA_NULL, CUserData_enum i50 = USERDATA_NULL, CUserData_enum i51 = USERDATA_NULL, CUserData_enum i52 = USERDATA_NULL, CUserData_enum i53 = USERDATA_NULL, CUserData_enum i54 = USERDATA_NULL, CUserData_enum i55 = USERDATA_NULL, CUserData_enum i56 = USERDATA_NULL, CUserData_enum i57 = USERDATA_NULL, CUserData_enum i58 = USERDATA_NULL, CUserData_enum i59 = USERDATA_NULL, CUserData_enum i60 = USERDATA_NULL, CUserData_enum i61 = USERDATA_NULL, CUserData_enum i62 = USERDATA_NULL, CUserData_enum i63 = USERDATA_NULL, CUserData_enum i64 = USERDATA_NULL, CUserData_enum i65 = USERDATA_NULL, CUserData_enum i66 = USERDATA_NULL, CUserData_enum i67 = USERDATA_NULL, CUserData_enum i68 = USERDATA_NULL, CUserData_enum i69 = USERDATA_NULL, CUserData_enum i70 = USERDATA_NULL, CUserData_enum i71 = USERDATA_NULL, CUserData_enum i72 = USERDATA_NULL, CUserData_enum i73 = USERDATA_NULL, CUserData_enum i74 = USERDATA_NULL, CUserData_enum i75 = USERDATA_NULL, CUserData_enum i76 = USERDATA_NULL, CUserData_enum i77 = USERDATA_NULL, CUserData_enum i78 = USERDATA_NULL, CUserData_enum i79 = USERDATA_NULL, CUserData_enum i80 = USERDATA_NULL, CUserData_enum i81 = USERDATA_NULL, CUserData_enum i82 = USERDATA_NULL, CUserData_enum i83 = USERDATA_NULL, CUserData_enum i84 = USERDATA_NULL, CUserData_enum i85 = USERDATA_NULL, CUserData_enum i86 = USERDATA_NULL, CUserData_enum i87 = USERDATA_NULL, CUserData_enum i88 = USERDATA_NULL, CUserData_enum i89 = USERDATA_NULL, CUserData_enum i90 = USERDATA_NULL, CUserData_enum i91 = USERDATA_NULL, CUserData_enum i92 = USERDATA_NULL, CUserData_enum i93 = USERDATA_NULL, CUserData_enum i94 = USERDATA_NULL, CUserData_enum i95 = USERDATA_NULL, CUserData_enum i96 = USERDATA_NULL, CUserData_enum i97 = USERDATA_NULL, CUserData_enum i98 = USERDATA_NULL, CUserData_enum i99 = USERDATA_NULL, CUserData_enum i100 = USERDATA_NULL, CUserData_enum i101 = USERDATA_NULL, CUserData_enum i102 = USERDATA_NULL, CUserData_enum i103 = USERDATA_NULL, CUserData_enum i104 = USERDATA_NULL, CUserData_enum i105 = USERDATA_NULL, CUserData_enum i106 = USERDATA_NULL, CUserData_enum i107 = USERDATA_NULL, CUserData_enum i108 = USERDATA_NULL, CUserData_enum i109 = USERDATA_NULL, CUserData_enum i110 = USERDATA_NULL, CUserData_enum i111 = USERDATA_NULL, CUserData_enum i112 = USERDATA_NULL, CUserData_enum i113 = USERDATA_NULL, CUserData_enum i114 = USERDATA_NULL, CUserData_enum i115 = USERDATA_NULL, CUserData_enum i116 = USERDATA_NULL, CUserData_enum i117 = USERDATA_NULL, CUserData_enum i118 = USERDATA_NULL, CUserData_enum i119 = USERDATA_NULL, CUserData_enum i120 = USERDATA_NULL, CUserData_enum i121 = USERDATA_NULL, CUserData_enum i122 = USERDATA_NULL, CUserData_enum i123 = USERDATA_NULL, CUserData_enum i124 = USERDATA_NULL, CUserData_enum i125 = USERDATA_NULL, CUserData_enum i126 = USERDATA_NULL, CUserData_enum i127 = USERDATA_NULL, CUserData_enum i128 = USERDATA_NULL, CUserData_enum i129 = USERDATA_NULL, CUserData_enum i130 = USERDATA_NULL) const
            { return equal_list(d, c, mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15, i16, i17, i18, i19, i20, i21, i22, i23, i24, i25, i26, i27, i28, i29, i30, i31, i32, i33, i34, i35, i36, i37, i38, i39, i40, i41, i42, i43, i44, i45, i46, i47, i48, i49, i50, i51, i52, i53, i54, i55, i56, i57, i58, i59, i60, i61, i62, i63, i64, i65, i66, i67, i68, i69, i70, i71, i72, i73, i74, i75, i76, i77, i78, i79, i80, i81, i82, i83, i84, i85, i86, i87, i88, i89, i90, i91, i92, i93, i94, i95, i96, i97, i98, i99, i100, i101, i102, i103, i104, i105, i106, i107, i108, i109, i110, i111, i112, i113, i114, i115, i116, i117, i118, i119, i120, i121, i122, i123, i124, i125, i126, i127, i128, i129, i130); }
    CUserData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d, const char* c,
            std::vector<bool> *i) const
            { return equal_list(d, c, mysqlpp::quote, i); }
    CUserData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d, const char* c,
            mysqlpp::sql_cmp_type sc) const
            { return equal_list(d, c, mysqlpp::quote, sc); }

    template <class Manip>
    CUserData_cus_equal_list<Manip> equal_list(const char* d, const char* c, Manip m, 
                        bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false, bool i9 = false, bool i10 = false, bool i11 = false, bool i12 = false, bool i13 = false, bool i14 = false, bool i15 = false, bool i16 = false, bool i17 = false, bool i18 = false, bool i19 = false, bool i20 = false, bool i21 = false, bool i22 = false, bool i23 = false, bool i24 = false, bool i25 = false, bool i26 = false, bool i27 = false, bool i28 = false, bool i29 = false, bool i30 = false, bool i31 = false, bool i32 = false, bool i33 = false, bool i34 = false, bool i35 = false, bool i36 = false, bool i37 = false, bool i38 = false, bool i39 = false, bool i40 = false, bool i41 = false, bool i42 = false, bool i43 = false, bool i44 = false, bool i45 = false, bool i46 = false, bool i47 = false, bool i48 = false, bool i49 = false, bool i50 = false, bool i51 = false, bool i52 = false, bool i53 = false, bool i54 = false, bool i55 = false, bool i56 = false, bool i57 = false, bool i58 = false, bool i59 = false, bool i60 = false, bool i61 = false, bool i62 = false, bool i63 = false, bool i64 = false, bool i65 = false, bool i66 = false, bool i67 = false, bool i68 = false, bool i69 = false, bool i70 = false, bool i71 = false, bool i72 = false, bool i73 = false, bool i74 = false, bool i75 = false, bool i76 = false, bool i77 = false, bool i78 = false, bool i79 = false, bool i80 = false, bool i81 = false, bool i82 = false, bool i83 = false, bool i84 = false, bool i85 = false, bool i86 = false, bool i87 = false, bool i88 = false, bool i89 = false, bool i90 = false, bool i91 = false, bool i92 = false, bool i93 = false, bool i94 = false, bool i95 = false, bool i96 = false, bool i97 = false, bool i98 = false, bool i99 = false, bool i100 = false, bool i101 = false, bool i102 = false, bool i103 = false, bool i104 = false, bool i105 = false, bool i106 = false, bool i107 = false, bool i108 = false, bool i109 = false, bool i110 = false, bool i111 = false, bool i112 = false, bool i113 = false, bool i114 = false, bool i115 = false, bool i116 = false, bool i117 = false, bool i118 = false, bool i119 = false, bool i120 = false, bool i121 = false, bool i122 = false, bool i123 = false, bool i124 = false, bool i125 = false, bool i126 = false, bool i127 = false, bool i128 = false, bool i129 = false, bool i130 = false) const;
    template <class Manip>
    CUserData_cus_equal_list<Manip> equal_list(const char* d, const char* c, Manip m, 
                        CUserData_enum i1, CUserData_enum i2 = USERDATA_NULL, CUserData_enum i3 = USERDATA_NULL, CUserData_enum i4 = USERDATA_NULL, CUserData_enum i5 = USERDATA_NULL, CUserData_enum i6 = USERDATA_NULL, CUserData_enum i7 = USERDATA_NULL, CUserData_enum i8 = USERDATA_NULL, CUserData_enum i9 = USERDATA_NULL, CUserData_enum i10 = USERDATA_NULL, CUserData_enum i11 = USERDATA_NULL, CUserData_enum i12 = USERDATA_NULL, CUserData_enum i13 = USERDATA_NULL, CUserData_enum i14 = USERDATA_NULL, CUserData_enum i15 = USERDATA_NULL, CUserData_enum i16 = USERDATA_NULL, CUserData_enum i17 = USERDATA_NULL, CUserData_enum i18 = USERDATA_NULL, CUserData_enum i19 = USERDATA_NULL, CUserData_enum i20 = USERDATA_NULL, CUserData_enum i21 = USERDATA_NULL, CUserData_enum i22 = USERDATA_NULL, CUserData_enum i23 = USERDATA_NULL, CUserData_enum i24 = USERDATA_NULL, CUserData_enum i25 = USERDATA_NULL, CUserData_enum i26 = USERDATA_NULL, CUserData_enum i27 = USERDATA_NULL, CUserData_enum i28 = USERDATA_NULL, CUserData_enum i29 = USERDATA_NULL, CUserData_enum i30 = USERDATA_NULL, CUserData_enum i31 = USERDATA_NULL, CUserData_enum i32 = USERDATA_NULL, CUserData_enum i33 = USERDATA_NULL, CUserData_enum i34 = USERDATA_NULL, CUserData_enum i35 = USERDATA_NULL, CUserData_enum i36 = USERDATA_NULL, CUserData_enum i37 = USERDATA_NULL, CUserData_enum i38 = USERDATA_NULL, CUserData_enum i39 = USERDATA_NULL, CUserData_enum i40 = USERDATA_NULL, CUserData_enum i41 = USERDATA_NULL, CUserData_enum i42 = USERDATA_NULL, CUserData_enum i43 = USERDATA_NULL, CUserData_enum i44 = USERDATA_NULL, CUserData_enum i45 = USERDATA_NULL, CUserData_enum i46 = USERDATA_NULL, CUserData_enum i47 = USERDATA_NULL, CUserData_enum i48 = USERDATA_NULL, CUserData_enum i49 = USERDATA_NULL, CUserData_enum i50 = USERDATA_NULL, CUserData_enum i51 = USERDATA_NULL, CUserData_enum i52 = USERDATA_NULL, CUserData_enum i53 = USERDATA_NULL, CUserData_enum i54 = USERDATA_NULL, CUserData_enum i55 = USERDATA_NULL, CUserData_enum i56 = USERDATA_NULL, CUserData_enum i57 = USERDATA_NULL, CUserData_enum i58 = USERDATA_NULL, CUserData_enum i59 = USERDATA_NULL, CUserData_enum i60 = USERDATA_NULL, CUserData_enum i61 = USERDATA_NULL, CUserData_enum i62 = USERDATA_NULL, CUserData_enum i63 = USERDATA_NULL, CUserData_enum i64 = USERDATA_NULL, CUserData_enum i65 = USERDATA_NULL, CUserData_enum i66 = USERDATA_NULL, CUserData_enum i67 = USERDATA_NULL, CUserData_enum i68 = USERDATA_NULL, CUserData_enum i69 = USERDATA_NULL, CUserData_enum i70 = USERDATA_NULL, CUserData_enum i71 = USERDATA_NULL, CUserData_enum i72 = USERDATA_NULL, CUserData_enum i73 = USERDATA_NULL, CUserData_enum i74 = USERDATA_NULL, CUserData_enum i75 = USERDATA_NULL, CUserData_enum i76 = USERDATA_NULL, CUserData_enum i77 = USERDATA_NULL, CUserData_enum i78 = USERDATA_NULL, CUserData_enum i79 = USERDATA_NULL, CUserData_enum i80 = USERDATA_NULL, CUserData_enum i81 = USERDATA_NULL, CUserData_enum i82 = USERDATA_NULL, CUserData_enum i83 = USERDATA_NULL, CUserData_enum i84 = USERDATA_NULL, CUserData_enum i85 = USERDATA_NULL, CUserData_enum i86 = USERDATA_NULL, CUserData_enum i87 = USERDATA_NULL, CUserData_enum i88 = USERDATA_NULL, CUserData_enum i89 = USERDATA_NULL, CUserData_enum i90 = USERDATA_NULL, CUserData_enum i91 = USERDATA_NULL, CUserData_enum i92 = USERDATA_NULL, CUserData_enum i93 = USERDATA_NULL, CUserData_enum i94 = USERDATA_NULL, CUserData_enum i95 = USERDATA_NULL, CUserData_enum i96 = USERDATA_NULL, CUserData_enum i97 = USERDATA_NULL, CUserData_enum i98 = USERDATA_NULL, CUserData_enum i99 = USERDATA_NULL, CUserData_enum i100 = USERDATA_NULL, CUserData_enum i101 = USERDATA_NULL, CUserData_enum i102 = USERDATA_NULL, CUserData_enum i103 = USERDATA_NULL, CUserData_enum i104 = USERDATA_NULL, CUserData_enum i105 = USERDATA_NULL, CUserData_enum i106 = USERDATA_NULL, CUserData_enum i107 = USERDATA_NULL, CUserData_enum i108 = USERDATA_NULL, CUserData_enum i109 = USERDATA_NULL, CUserData_enum i110 = USERDATA_NULL, CUserData_enum i111 = USERDATA_NULL, CUserData_enum i112 = USERDATA_NULL, CUserData_enum i113 = USERDATA_NULL, CUserData_enum i114 = USERDATA_NULL, CUserData_enum i115 = USERDATA_NULL, CUserData_enum i116 = USERDATA_NULL, CUserData_enum i117 = USERDATA_NULL, CUserData_enum i118 = USERDATA_NULL, CUserData_enum i119 = USERDATA_NULL, CUserData_enum i120 = USERDATA_NULL, CUserData_enum i121 = USERDATA_NULL, CUserData_enum i122 = USERDATA_NULL, CUserData_enum i123 = USERDATA_NULL, CUserData_enum i124 = USERDATA_NULL, CUserData_enum i125 = USERDATA_NULL, CUserData_enum i126 = USERDATA_NULL, CUserData_enum i127 = USERDATA_NULL, CUserData_enum i128 = USERDATA_NULL, CUserData_enum i129 = USERDATA_NULL, CUserData_enum i130 = USERDATA_NULL) const;
    template <class Manip>
    CUserData_cus_equal_list<Manip> equal_list(const char* d, const char* c, Manip m, 
                        std::vector<bool> *i) const;
    template <class Manip>
    CUserData_cus_equal_list<Manip> equal_list(const char* d, const char* c, Manip m, 
                        mysqlpp::sql_cmp_type sc) const;

    private:
    static const char* table_;
    const char* table_override_;
    };
    MYSQLPP_SSQLS_CONDITIONAL_STATICS(
        const char* CUserData::names[] = {
                "name" ,
    "mate" ,
    "lookface" ,
    "hair" ,
    "length" ,
    "fat" ,
    "money" ,
    "money_saved" ,
    "task_data" ,
    "level" ,
    "exp" ,
    "power" ,
    "constitution" ,
    "dexterity" ,
    "Speed" ,
    "health" ,
    "soul" ,
    "additional_point" ,
    "auto_allot" ,
    "life" ,
    "mana" ,
    "profession" ,
    "potential" ,
    "pk" ,
    "nobility" ,
    "medal" ,
    "medal_select" ,
    "metempsychosis" ,
    "syndicate_id" ,
    "recordmap_id" ,
    "recordx" ,
    "recordy" ,
    "account_id" ,
    "id" ,
    "last_login" ,
    "account" ,
    "password" ,
    "task_mask" ,
    "time_of_life" ,
    "virtue" ,
    "home_id" ,
    "title" ,
    "title_select" ,
    "tutor_exp" ,
    "tutor_level" ,
    "maxlife_percent" ,
    "mercenary_rank" ,
    "mercenary_exp" ,
    "nobility_rank" ,
    "exploit" ,
    "eud_pack_size" ,
    "disableFlag" ,
    "reg_time" ,
    "accu_online_time" ,
    "accu_offline_time" ,
    "last_logout" ,
    "prompt_ver" ,
    "Friend_share" ,
    "Login_time" ,
    "Login_ip" ,
    "soul_value" ,
    "brood_times" ,
    "emoney" ,
    "chk_sum" ,
    "elock" ,
    "ExpBallUsage" ,
    "ExpCrystalUsage" ,
    "cheat_time" ,
    "online_time" ,
    "auto_exercise" ,
    "hung_last_logout" ,
    "god_status" ,
    "big_prize_fails" ,
    "small_prize_fails" ,
    "bonus_points" ,
    "flower" ,
    "flower_w" ,
    "flower_p" ,
    "income" ,
    "illu_ButterFly" ,
    "illu_Fish" ,
    "illu_Shell" ,
    "illu_Herbal" ,
    "illu_Ore" ,
    "password_id" ,
    "quiz_point" ,
    "protect_state" ,
    "donation" ,
    "wood" ,
    "stone" ,
    "todo_list_mask1" ,
    "todo_list1" ,
    "todo_list_hex1" ,
    "coach" ,
    "coach_time" ,
    "coach_deed" ,
    "coach_date" ,
    "extra_hatch_size" ,
    "shadiness_money" ,
    "shadiness_emoney" ,
    "soul_value_lev" ,
    "business" ,
    "emoney2" ,
    "type" ,
    "god_strength" ,
    "god_level" ,
    "deification" ,
    "tmoney" ,
    "demon_level" ,
    "demon_exp" ,
    "socialclass" ,
    "credit_point" ,
    "credit_limit" ,
    "credit_return" ,
    "eudkernel_id" ,
    "refinery_time_end" ,
    "pack_add" ,
    "boundary_lev" ,
    "boundary_exp" ,
    "offer_point" ,
    "battle_lev" ,
    "channel_account" ,
    "recharge_emoney" ,
    "auto_battle_time" ,
    "first_recharge" ,
    "special_flag" ,
    "vip_lev" ,
    "ghosttoexp_amount" ,
    "vigor" ,
    "func_list" 
        };
        const char* CUserData::table_ = "cq_user";
    )

    template <class Manip>
    CUserData_cus_value_list<Manip>::CUserData_cus_value_list
            (const CUserData* o, const char* d, Manip m, bool i1, bool i2, bool i3, bool i4, bool i5, bool i6, bool i7, bool i8, bool i9, bool i10, bool i11, bool i12, bool i13, bool i14, bool i15, bool i16, bool i17, bool i18, bool i19, bool i20, bool i21, bool i22, bool i23, bool i24, bool i25, bool i26, bool i27, bool i28, bool i29, bool i30, bool i31, bool i32, bool i33, bool i34, bool i35, bool i36, bool i37, bool i38, bool i39, bool i40, bool i41, bool i42, bool i43, bool i44, bool i45, bool i46, bool i47, bool i48, bool i49, bool i50, bool i51, bool i52, bool i53, bool i54, bool i55, bool i56, bool i57, bool i58, bool i59, bool i60, bool i61, bool i62, bool i63, bool i64, bool i65, bool i66, bool i67, bool i68, bool i69, bool i70, bool i71, bool i72, bool i73, bool i74, bool i75, bool i76, bool i77, bool i78, bool i79, bool i80, bool i81, bool i82, bool i83, bool i84, bool i85, bool i86, bool i87, bool i88, bool i89, bool i90, bool i91, bool i92, bool i93, bool i94, bool i95, bool i96, bool i97, bool i98, bool i99, bool i100, bool i101, bool i102, bool i103, bool i104, bool i105, bool i106, bool i107, bool i108, bool i109, bool i110, bool i111, bool i112, bool i113, bool i114, bool i115, bool i116, bool i117, bool i118, bool i119, bool i120, bool i121, bool i122, bool i123, bool i124, bool i125, bool i126, bool i127, bool i128, bool i129, bool i130)
    {
        delim = d;
        manip = m;
        del_vector = true;
        obj = o;
        include = new std::vector<bool>(130, false);
    if (i1) (*include)[0]=true;
    if (i2) (*include)[1]=true;
    if (i3) (*include)[2]=true;
    if (i4) (*include)[3]=true;
    if (i5) (*include)[4]=true;
    if (i6) (*include)[5]=true;
    if (i7) (*include)[6]=true;
    if (i8) (*include)[7]=true;
    if (i9) (*include)[8]=true;
    if (i10) (*include)[9]=true;
    if (i11) (*include)[10]=true;
    if (i12) (*include)[11]=true;
    if (i13) (*include)[12]=true;
    if (i14) (*include)[13]=true;
    if (i15) (*include)[14]=true;
    if (i16) (*include)[15]=true;
    if (i17) (*include)[16]=true;
    if (i18) (*include)[17]=true;
    if (i19) (*include)[18]=true;
    if (i20) (*include)[19]=true;
    if (i21) (*include)[20]=true;
    if (i22) (*include)[21]=true;
    if (i23) (*include)[22]=true;
    if (i24) (*include)[23]=true;
    if (i25) (*include)[24]=true;
    if (i26) (*include)[25]=true;
    if (i27) (*include)[26]=true;
    if (i28) (*include)[27]=true;
    if (i29) (*include)[28]=true;
    if (i30) (*include)[29]=true;
    if (i31) (*include)[30]=true;
    if (i32) (*include)[31]=true;
    if (i33) (*include)[32]=true;
    if (i34) (*include)[33]=true;
    if (i35) (*include)[34]=true;
    if (i36) (*include)[35]=true;
    if (i37) (*include)[36]=true;
    if (i38) (*include)[37]=true;
    if (i39) (*include)[38]=true;
    if (i40) (*include)[39]=true;
    if (i41) (*include)[40]=true;
    if (i42) (*include)[41]=true;
    if (i43) (*include)[42]=true;
    if (i44) (*include)[43]=true;
    if (i45) (*include)[44]=true;
    if (i46) (*include)[45]=true;
    if (i47) (*include)[46]=true;
    if (i48) (*include)[47]=true;
    if (i49) (*include)[48]=true;
    if (i50) (*include)[49]=true;
    if (i51) (*include)[50]=true;
    if (i52) (*include)[51]=true;
    if (i53) (*include)[52]=true;
    if (i54) (*include)[53]=true;
    if (i55) (*include)[54]=true;
    if (i56) (*include)[55]=true;
    if (i57) (*include)[56]=true;
    if (i58) (*include)[57]=true;
    if (i59) (*include)[58]=true;
    if (i60) (*include)[59]=true;
    if (i61) (*include)[60]=true;
    if (i62) (*include)[61]=true;
    if (i63) (*include)[62]=true;
    if (i64) (*include)[63]=true;
    if (i65) (*include)[64]=true;
    if (i66) (*include)[65]=true;
    if (i67) (*include)[66]=true;
    if (i68) (*include)[67]=true;
    if (i69) (*include)[68]=true;
    if (i70) (*include)[69]=true;
    if (i71) (*include)[70]=true;
    if (i72) (*include)[71]=true;
    if (i73) (*include)[72]=true;
    if (i74) (*include)[73]=true;
    if (i75) (*include)[74]=true;
    if (i76) (*include)[75]=true;
    if (i77) (*include)[76]=true;
    if (i78) (*include)[77]=true;
    if (i79) (*include)[78]=true;
    if (i80) (*include)[79]=true;
    if (i81) (*include)[80]=true;
    if (i82) (*include)[81]=true;
    if (i83) (*include)[82]=true;
    if (i84) (*include)[83]=true;
    if (i85) (*include)[84]=true;
    if (i86) (*include)[85]=true;
    if (i87) (*include)[86]=true;
    if (i88) (*include)[87]=true;
    if (i89) (*include)[88]=true;
    if (i90) (*include)[89]=true;
    if (i91) (*include)[90]=true;
    if (i92) (*include)[91]=true;
    if (i93) (*include)[92]=true;
    if (i94) (*include)[93]=true;
    if (i95) (*include)[94]=true;
    if (i96) (*include)[95]=true;
    if (i97) (*include)[96]=true;
    if (i98) (*include)[97]=true;
    if (i99) (*include)[98]=true;
    if (i100) (*include)[99]=true;
    if (i101) (*include)[100]=true;
    if (i102) (*include)[101]=true;
    if (i103) (*include)[102]=true;
    if (i104) (*include)[103]=true;
    if (i105) (*include)[104]=true;
    if (i106) (*include)[105]=true;
    if (i107) (*include)[106]=true;
    if (i108) (*include)[107]=true;
    if (i109) (*include)[108]=true;
    if (i110) (*include)[109]=true;
    if (i111) (*include)[110]=true;
    if (i112) (*include)[111]=true;
    if (i113) (*include)[112]=true;
    if (i114) (*include)[113]=true;
    if (i115) (*include)[114]=true;
    if (i116) (*include)[115]=true;
    if (i117) (*include)[116]=true;
    if (i118) (*include)[117]=true;
    if (i119) (*include)[118]=true;
    if (i120) (*include)[119]=true;
    if (i121) (*include)[120]=true;
    if (i122) (*include)[121]=true;
    if (i123) (*include)[122]=true;
    if (i124) (*include)[123]=true;
    if (i125) (*include)[124]=true;
    if (i126) (*include)[125]=true;
    if (i127) (*include)[126]=true;
    if (i128) (*include)[127]=true;
    if (i129) (*include)[128]=true;
    if (i130) (*include)[129]=true;

    }

    template <class Manip>
    CUserData_cus_value_list<Manip>::CUserData_cus_value_list
            (const CUserData* o, const char* d, Manip m, CUserData_enum i1, CUserData_enum i2, CUserData_enum i3, CUserData_enum i4, CUserData_enum i5, CUserData_enum i6, CUserData_enum i7, CUserData_enum i8, CUserData_enum i9, CUserData_enum i10, CUserData_enum i11, CUserData_enum i12, CUserData_enum i13, CUserData_enum i14, CUserData_enum i15, CUserData_enum i16, CUserData_enum i17, CUserData_enum i18, CUserData_enum i19, CUserData_enum i20, CUserData_enum i21, CUserData_enum i22, CUserData_enum i23, CUserData_enum i24, CUserData_enum i25, CUserData_enum i26, CUserData_enum i27, CUserData_enum i28, CUserData_enum i29, CUserData_enum i30, CUserData_enum i31, CUserData_enum i32, CUserData_enum i33, CUserData_enum i34, CUserData_enum i35, CUserData_enum i36, CUserData_enum i37, CUserData_enum i38, CUserData_enum i39, CUserData_enum i40, CUserData_enum i41, CUserData_enum i42, CUserData_enum i43, CUserData_enum i44, CUserData_enum i45, CUserData_enum i46, CUserData_enum i47, CUserData_enum i48, CUserData_enum i49, CUserData_enum i50, CUserData_enum i51, CUserData_enum i52, CUserData_enum i53, CUserData_enum i54, CUserData_enum i55, CUserData_enum i56, CUserData_enum i57, CUserData_enum i58, CUserData_enum i59, CUserData_enum i60, CUserData_enum i61, CUserData_enum i62, CUserData_enum i63, CUserData_enum i64, CUserData_enum i65, CUserData_enum i66, CUserData_enum i67, CUserData_enum i68, CUserData_enum i69, CUserData_enum i70, CUserData_enum i71, CUserData_enum i72, CUserData_enum i73, CUserData_enum i74, CUserData_enum i75, CUserData_enum i76, CUserData_enum i77, CUserData_enum i78, CUserData_enum i79, CUserData_enum i80, CUserData_enum i81, CUserData_enum i82, CUserData_enum i83, CUserData_enum i84, CUserData_enum i85, CUserData_enum i86, CUserData_enum i87, CUserData_enum i88, CUserData_enum i89, CUserData_enum i90, CUserData_enum i91, CUserData_enum i92, CUserData_enum i93, CUserData_enum i94, CUserData_enum i95, CUserData_enum i96, CUserData_enum i97, CUserData_enum i98, CUserData_enum i99, CUserData_enum i100, CUserData_enum i101, CUserData_enum i102, CUserData_enum i103, CUserData_enum i104, CUserData_enum i105, CUserData_enum i106, CUserData_enum i107, CUserData_enum i108, CUserData_enum i109, CUserData_enum i110, CUserData_enum i111, CUserData_enum i112, CUserData_enum i113, CUserData_enum i114, CUserData_enum i115, CUserData_enum i116, CUserData_enum i117, CUserData_enum i118, CUserData_enum i119, CUserData_enum i120, CUserData_enum i121, CUserData_enum i122, CUserData_enum i123, CUserData_enum i124, CUserData_enum i125, CUserData_enum i126, CUserData_enum i127, CUserData_enum i128, CUserData_enum i129, CUserData_enum i130)
    {
        delim = d;
        manip = m;
        del_vector = true;
        obj = o;
        include = new std::vector<bool>(130, false);
    (*include)[i1]=true;
    if (i2 == USERDATA_NULL) return;
    (*include)[i2]=true;
    if (i3 == USERDATA_NULL) return;
    (*include)[i3]=true;
    if (i4 == USERDATA_NULL) return;
    (*include)[i4]=true;
    if (i5 == USERDATA_NULL) return;
    (*include)[i5]=true;
    if (i6 == USERDATA_NULL) return;
    (*include)[i6]=true;
    if (i7 == USERDATA_NULL) return;
    (*include)[i7]=true;
    if (i8 == USERDATA_NULL) return;
    (*include)[i8]=true;
    if (i9 == USERDATA_NULL) return;
    (*include)[i9]=true;
    if (i10 == USERDATA_NULL) return;
    (*include)[i10]=true;
    if (i11 == USERDATA_NULL) return;
    (*include)[i11]=true;
    if (i12 == USERDATA_NULL) return;
    (*include)[i12]=true;
    if (i13 == USERDATA_NULL) return;
    (*include)[i13]=true;
    if (i14 == USERDATA_NULL) return;
    (*include)[i14]=true;
    if (i15 == USERDATA_NULL) return;
    (*include)[i15]=true;
    if (i16 == USERDATA_NULL) return;
    (*include)[i16]=true;
    if (i17 == USERDATA_NULL) return;
    (*include)[i17]=true;
    if (i18 == USERDATA_NULL) return;
    (*include)[i18]=true;
    if (i19 == USERDATA_NULL) return;
    (*include)[i19]=true;
    if (i20 == USERDATA_NULL) return;
    (*include)[i20]=true;
    if (i21 == USERDATA_NULL) return;
    (*include)[i21]=true;
    if (i22 == USERDATA_NULL) return;
    (*include)[i22]=true;
    if (i23 == USERDATA_NULL) return;
    (*include)[i23]=true;
    if (i24 == USERDATA_NULL) return;
    (*include)[i24]=true;
    if (i25 == USERDATA_NULL) return;
    (*include)[i25]=true;
    if (i26 == USERDATA_NULL) return;
    (*include)[i26]=true;
    if (i27 == USERDATA_NULL) return;
    (*include)[i27]=true;
    if (i28 == USERDATA_NULL) return;
    (*include)[i28]=true;
    if (i29 == USERDATA_NULL) return;
    (*include)[i29]=true;
    if (i30 == USERDATA_NULL) return;
    (*include)[i30]=true;
    if (i31 == USERDATA_NULL) return;
    (*include)[i31]=true;
    if (i32 == USERDATA_NULL) return;
    (*include)[i32]=true;
    if (i33 == USERDATA_NULL) return;
    (*include)[i33]=true;
    if (i34 == USERDATA_NULL) return;
    (*include)[i34]=true;
    if (i35 == USERDATA_NULL) return;
    (*include)[i35]=true;
    if (i36 == USERDATA_NULL) return;
    (*include)[i36]=true;
    if (i37 == USERDATA_NULL) return;
    (*include)[i37]=true;
    if (i38 == USERDATA_NULL) return;
    (*include)[i38]=true;
    if (i39 == USERDATA_NULL) return;
    (*include)[i39]=true;
    if (i40 == USERDATA_NULL) return;
    (*include)[i40]=true;
    if (i41 == USERDATA_NULL) return;
    (*include)[i41]=true;
    if (i42 == USERDATA_NULL) return;
    (*include)[i42]=true;
    if (i43 == USERDATA_NULL) return;
    (*include)[i43]=true;
    if (i44 == USERDATA_NULL) return;
    (*include)[i44]=true;
    if (i45 == USERDATA_NULL) return;
    (*include)[i45]=true;
    if (i46 == USERDATA_NULL) return;
    (*include)[i46]=true;
    if (i47 == USERDATA_NULL) return;
    (*include)[i47]=true;
    if (i48 == USERDATA_NULL) return;
    (*include)[i48]=true;
    if (i49 == USERDATA_NULL) return;
    (*include)[i49]=true;
    if (i50 == USERDATA_NULL) return;
    (*include)[i50]=true;
    if (i51 == USERDATA_NULL) return;
    (*include)[i51]=true;
    if (i52 == USERDATA_NULL) return;
    (*include)[i52]=true;
    if (i53 == USERDATA_NULL) return;
    (*include)[i53]=true;
    if (i54 == USERDATA_NULL) return;
    (*include)[i54]=true;
    if (i55 == USERDATA_NULL) return;
    (*include)[i55]=true;
    if (i56 == USERDATA_NULL) return;
    (*include)[i56]=true;
    if (i57 == USERDATA_NULL) return;
    (*include)[i57]=true;
    if (i58 == USERDATA_NULL) return;
    (*include)[i58]=true;
    if (i59 == USERDATA_NULL) return;
    (*include)[i59]=true;
    if (i60 == USERDATA_NULL) return;
    (*include)[i60]=true;
    if (i61 == USERDATA_NULL) return;
    (*include)[i61]=true;
    if (i62 == USERDATA_NULL) return;
    (*include)[i62]=true;
    if (i63 == USERDATA_NULL) return;
    (*include)[i63]=true;
    if (i64 == USERDATA_NULL) return;
    (*include)[i64]=true;
    if (i65 == USERDATA_NULL) return;
    (*include)[i65]=true;
    if (i66 == USERDATA_NULL) return;
    (*include)[i66]=true;
    if (i67 == USERDATA_NULL) return;
    (*include)[i67]=true;
    if (i68 == USERDATA_NULL) return;
    (*include)[i68]=true;
    if (i69 == USERDATA_NULL) return;
    (*include)[i69]=true;
    if (i70 == USERDATA_NULL) return;
    (*include)[i70]=true;
    if (i71 == USERDATA_NULL) return;
    (*include)[i71]=true;
    if (i72 == USERDATA_NULL) return;
    (*include)[i72]=true;
    if (i73 == USERDATA_NULL) return;
    (*include)[i73]=true;
    if (i74 == USERDATA_NULL) return;
    (*include)[i74]=true;
    if (i75 == USERDATA_NULL) return;
    (*include)[i75]=true;
    if (i76 == USERDATA_NULL) return;
    (*include)[i76]=true;
    if (i77 == USERDATA_NULL) return;
    (*include)[i77]=true;
    if (i78 == USERDATA_NULL) return;
    (*include)[i78]=true;
    if (i79 == USERDATA_NULL) return;
    (*include)[i79]=true;
    if (i80 == USERDATA_NULL) return;
    (*include)[i80]=true;
    if (i81 == USERDATA_NULL) return;
    (*include)[i81]=true;
    if (i82 == USERDATA_NULL) return;
    (*include)[i82]=true;
    if (i83 == USERDATA_NULL) return;
    (*include)[i83]=true;
    if (i84 == USERDATA_NULL) return;
    (*include)[i84]=true;
    if (i85 == USERDATA_NULL) return;
    (*include)[i85]=true;
    if (i86 == USERDATA_NULL) return;
    (*include)[i86]=true;
    if (i87 == USERDATA_NULL) return;
    (*include)[i87]=true;
    if (i88 == USERDATA_NULL) return;
    (*include)[i88]=true;
    if (i89 == USERDATA_NULL) return;
    (*include)[i89]=true;
    if (i90 == USERDATA_NULL) return;
    (*include)[i90]=true;
    if (i91 == USERDATA_NULL) return;
    (*include)[i91]=true;
    if (i92 == USERDATA_NULL) return;
    (*include)[i92]=true;
    if (i93 == USERDATA_NULL) return;
    (*include)[i93]=true;
    if (i94 == USERDATA_NULL) return;
    (*include)[i94]=true;
    if (i95 == USERDATA_NULL) return;
    (*include)[i95]=true;
    if (i96 == USERDATA_NULL) return;
    (*include)[i96]=true;
    if (i97 == USERDATA_NULL) return;
    (*include)[i97]=true;
    if (i98 == USERDATA_NULL) return;
    (*include)[i98]=true;
    if (i99 == USERDATA_NULL) return;
    (*include)[i99]=true;
    if (i100 == USERDATA_NULL) return;
    (*include)[i100]=true;
    if (i101 == USERDATA_NULL) return;
    (*include)[i101]=true;
    if (i102 == USERDATA_NULL) return;
    (*include)[i102]=true;
    if (i103 == USERDATA_NULL) return;
    (*include)[i103]=true;
    if (i104 == USERDATA_NULL) return;
    (*include)[i104]=true;
    if (i105 == USERDATA_NULL) return;
    (*include)[i105]=true;
    if (i106 == USERDATA_NULL) return;
    (*include)[i106]=true;
    if (i107 == USERDATA_NULL) return;
    (*include)[i107]=true;
    if (i108 == USERDATA_NULL) return;
    (*include)[i108]=true;
    if (i109 == USERDATA_NULL) return;
    (*include)[i109]=true;
    if (i110 == USERDATA_NULL) return;
    (*include)[i110]=true;
    if (i111 == USERDATA_NULL) return;
    (*include)[i111]=true;
    if (i112 == USERDATA_NULL) return;
    (*include)[i112]=true;
    if (i113 == USERDATA_NULL) return;
    (*include)[i113]=true;
    if (i114 == USERDATA_NULL) return;
    (*include)[i114]=true;
    if (i115 == USERDATA_NULL) return;
    (*include)[i115]=true;
    if (i116 == USERDATA_NULL) return;
    (*include)[i116]=true;
    if (i117 == USERDATA_NULL) return;
    (*include)[i117]=true;
    if (i118 == USERDATA_NULL) return;
    (*include)[i118]=true;
    if (i119 == USERDATA_NULL) return;
    (*include)[i119]=true;
    if (i120 == USERDATA_NULL) return;
    (*include)[i120]=true;
    if (i121 == USERDATA_NULL) return;
    (*include)[i121]=true;
    if (i122 == USERDATA_NULL) return;
    (*include)[i122]=true;
    if (i123 == USERDATA_NULL) return;
    (*include)[i123]=true;
    if (i124 == USERDATA_NULL) return;
    (*include)[i124]=true;
    if (i125 == USERDATA_NULL) return;
    (*include)[i125]=true;
    if (i126 == USERDATA_NULL) return;
    (*include)[i126]=true;
    if (i127 == USERDATA_NULL) return;
    (*include)[i127]=true;
    if (i128 == USERDATA_NULL) return;
    (*include)[i128]=true;
    if (i129 == USERDATA_NULL) return;
    (*include)[i129]=true;
    if (i130 == USERDATA_NULL) return;
    (*include)[i130]=true;

    }

    template <class Manip>
    CUserData_cus_field_list<Manip>::CUserData_cus_field_list
            (const CUserData* o, const char* d, Manip m, bool i1, bool i2, bool i3, bool i4, bool i5, bool i6, bool i7, bool i8, bool i9, bool i10, bool i11, bool i12, bool i13, bool i14, bool i15, bool i16, bool i17, bool i18, bool i19, bool i20, bool i21, bool i22, bool i23, bool i24, bool i25, bool i26, bool i27, bool i28, bool i29, bool i30, bool i31, bool i32, bool i33, bool i34, bool i35, bool i36, bool i37, bool i38, bool i39, bool i40, bool i41, bool i42, bool i43, bool i44, bool i45, bool i46, bool i47, bool i48, bool i49, bool i50, bool i51, bool i52, bool i53, bool i54, bool i55, bool i56, bool i57, bool i58, bool i59, bool i60, bool i61, bool i62, bool i63, bool i64, bool i65, bool i66, bool i67, bool i68, bool i69, bool i70, bool i71, bool i72, bool i73, bool i74, bool i75, bool i76, bool i77, bool i78, bool i79, bool i80, bool i81, bool i82, bool i83, bool i84, bool i85, bool i86, bool i87, bool i88, bool i89, bool i90, bool i91, bool i92, bool i93, bool i94, bool i95, bool i96, bool i97, bool i98, bool i99, bool i100, bool i101, bool i102, bool i103, bool i104, bool i105, bool i106, bool i107, bool i108, bool i109, bool i110, bool i111, bool i112, bool i113, bool i114, bool i115, bool i116, bool i117, bool i118, bool i119, bool i120, bool i121, bool i122, bool i123, bool i124, bool i125, bool i126, bool i127, bool i128, bool i129, bool i130)
    {
        delim = d;
        manip = m;
        del_vector = true;
        obj = o;
        include = new std::vector<bool>(130, false);
    if (i1) (*include)[0]=true;
    if (i2) (*include)[1]=true;
    if (i3) (*include)[2]=true;
    if (i4) (*include)[3]=true;
    if (i5) (*include)[4]=true;
    if (i6) (*include)[5]=true;
    if (i7) (*include)[6]=true;
    if (i8) (*include)[7]=true;
    if (i9) (*include)[8]=true;
    if (i10) (*include)[9]=true;
    if (i11) (*include)[10]=true;
    if (i12) (*include)[11]=true;
    if (i13) (*include)[12]=true;
    if (i14) (*include)[13]=true;
    if (i15) (*include)[14]=true;
    if (i16) (*include)[15]=true;
    if (i17) (*include)[16]=true;
    if (i18) (*include)[17]=true;
    if (i19) (*include)[18]=true;
    if (i20) (*include)[19]=true;
    if (i21) (*include)[20]=true;
    if (i22) (*include)[21]=true;
    if (i23) (*include)[22]=true;
    if (i24) (*include)[23]=true;
    if (i25) (*include)[24]=true;
    if (i26) (*include)[25]=true;
    if (i27) (*include)[26]=true;
    if (i28) (*include)[27]=true;
    if (i29) (*include)[28]=true;
    if (i30) (*include)[29]=true;
    if (i31) (*include)[30]=true;
    if (i32) (*include)[31]=true;
    if (i33) (*include)[32]=true;
    if (i34) (*include)[33]=true;
    if (i35) (*include)[34]=true;
    if (i36) (*include)[35]=true;
    if (i37) (*include)[36]=true;
    if (i38) (*include)[37]=true;
    if (i39) (*include)[38]=true;
    if (i40) (*include)[39]=true;
    if (i41) (*include)[40]=true;
    if (i42) (*include)[41]=true;
    if (i43) (*include)[42]=true;
    if (i44) (*include)[43]=true;
    if (i45) (*include)[44]=true;
    if (i46) (*include)[45]=true;
    if (i47) (*include)[46]=true;
    if (i48) (*include)[47]=true;
    if (i49) (*include)[48]=true;
    if (i50) (*include)[49]=true;
    if (i51) (*include)[50]=true;
    if (i52) (*include)[51]=true;
    if (i53) (*include)[52]=true;
    if (i54) (*include)[53]=true;
    if (i55) (*include)[54]=true;
    if (i56) (*include)[55]=true;
    if (i57) (*include)[56]=true;
    if (i58) (*include)[57]=true;
    if (i59) (*include)[58]=true;
    if (i60) (*include)[59]=true;
    if (i61) (*include)[60]=true;
    if (i62) (*include)[61]=true;
    if (i63) (*include)[62]=true;
    if (i64) (*include)[63]=true;
    if (i65) (*include)[64]=true;
    if (i66) (*include)[65]=true;
    if (i67) (*include)[66]=true;
    if (i68) (*include)[67]=true;
    if (i69) (*include)[68]=true;
    if (i70) (*include)[69]=true;
    if (i71) (*include)[70]=true;
    if (i72) (*include)[71]=true;
    if (i73) (*include)[72]=true;
    if (i74) (*include)[73]=true;
    if (i75) (*include)[74]=true;
    if (i76) (*include)[75]=true;
    if (i77) (*include)[76]=true;
    if (i78) (*include)[77]=true;
    if (i79) (*include)[78]=true;
    if (i80) (*include)[79]=true;
    if (i81) (*include)[80]=true;
    if (i82) (*include)[81]=true;
    if (i83) (*include)[82]=true;
    if (i84) (*include)[83]=true;
    if (i85) (*include)[84]=true;
    if (i86) (*include)[85]=true;
    if (i87) (*include)[86]=true;
    if (i88) (*include)[87]=true;
    if (i89) (*include)[88]=true;
    if (i90) (*include)[89]=true;
    if (i91) (*include)[90]=true;
    if (i92) (*include)[91]=true;
    if (i93) (*include)[92]=true;
    if (i94) (*include)[93]=true;
    if (i95) (*include)[94]=true;
    if (i96) (*include)[95]=true;
    if (i97) (*include)[96]=true;
    if (i98) (*include)[97]=true;
    if (i99) (*include)[98]=true;
    if (i100) (*include)[99]=true;
    if (i101) (*include)[100]=true;
    if (i102) (*include)[101]=true;
    if (i103) (*include)[102]=true;
    if (i104) (*include)[103]=true;
    if (i105) (*include)[104]=true;
    if (i106) (*include)[105]=true;
    if (i107) (*include)[106]=true;
    if (i108) (*include)[107]=true;
    if (i109) (*include)[108]=true;
    if (i110) (*include)[109]=true;
    if (i111) (*include)[110]=true;
    if (i112) (*include)[111]=true;
    if (i113) (*include)[112]=true;
    if (i114) (*include)[113]=true;
    if (i115) (*include)[114]=true;
    if (i116) (*include)[115]=true;
    if (i117) (*include)[116]=true;
    if (i118) (*include)[117]=true;
    if (i119) (*include)[118]=true;
    if (i120) (*include)[119]=true;
    if (i121) (*include)[120]=true;
    if (i122) (*include)[121]=true;
    if (i123) (*include)[122]=true;
    if (i124) (*include)[123]=true;
    if (i125) (*include)[124]=true;
    if (i126) (*include)[125]=true;
    if (i127) (*include)[126]=true;
    if (i128) (*include)[127]=true;
    if (i129) (*include)[128]=true;
    if (i130) (*include)[129]=true;

    }

    template <class Manip>
    CUserData_cus_field_list<Manip>::CUserData_cus_field_list
            (const CUserData* o, const char* d, Manip m, CUserData_enum i1, CUserData_enum i2, CUserData_enum i3, CUserData_enum i4, CUserData_enum i5, CUserData_enum i6, CUserData_enum i7, CUserData_enum i8, CUserData_enum i9, CUserData_enum i10, CUserData_enum i11, CUserData_enum i12, CUserData_enum i13, CUserData_enum i14, CUserData_enum i15, CUserData_enum i16, CUserData_enum i17, CUserData_enum i18, CUserData_enum i19, CUserData_enum i20, CUserData_enum i21, CUserData_enum i22, CUserData_enum i23, CUserData_enum i24, CUserData_enum i25, CUserData_enum i26, CUserData_enum i27, CUserData_enum i28, CUserData_enum i29, CUserData_enum i30, CUserData_enum i31, CUserData_enum i32, CUserData_enum i33, CUserData_enum i34, CUserData_enum i35, CUserData_enum i36, CUserData_enum i37, CUserData_enum i38, CUserData_enum i39, CUserData_enum i40, CUserData_enum i41, CUserData_enum i42, CUserData_enum i43, CUserData_enum i44, CUserData_enum i45, CUserData_enum i46, CUserData_enum i47, CUserData_enum i48, CUserData_enum i49, CUserData_enum i50, CUserData_enum i51, CUserData_enum i52, CUserData_enum i53, CUserData_enum i54, CUserData_enum i55, CUserData_enum i56, CUserData_enum i57, CUserData_enum i58, CUserData_enum i59, CUserData_enum i60, CUserData_enum i61, CUserData_enum i62, CUserData_enum i63, CUserData_enum i64, CUserData_enum i65, CUserData_enum i66, CUserData_enum i67, CUserData_enum i68, CUserData_enum i69, CUserData_enum i70, CUserData_enum i71, CUserData_enum i72, CUserData_enum i73, CUserData_enum i74, CUserData_enum i75, CUserData_enum i76, CUserData_enum i77, CUserData_enum i78, CUserData_enum i79, CUserData_enum i80, CUserData_enum i81, CUserData_enum i82, CUserData_enum i83, CUserData_enum i84, CUserData_enum i85, CUserData_enum i86, CUserData_enum i87, CUserData_enum i88, CUserData_enum i89, CUserData_enum i90, CUserData_enum i91, CUserData_enum i92, CUserData_enum i93, CUserData_enum i94, CUserData_enum i95, CUserData_enum i96, CUserData_enum i97, CUserData_enum i98, CUserData_enum i99, CUserData_enum i100, CUserData_enum i101, CUserData_enum i102, CUserData_enum i103, CUserData_enum i104, CUserData_enum i105, CUserData_enum i106, CUserData_enum i107, CUserData_enum i108, CUserData_enum i109, CUserData_enum i110, CUserData_enum i111, CUserData_enum i112, CUserData_enum i113, CUserData_enum i114, CUserData_enum i115, CUserData_enum i116, CUserData_enum i117, CUserData_enum i118, CUserData_enum i119, CUserData_enum i120, CUserData_enum i121, CUserData_enum i122, CUserData_enum i123, CUserData_enum i124, CUserData_enum i125, CUserData_enum i126, CUserData_enum i127, CUserData_enum i128, CUserData_enum i129, CUserData_enum i130)
    {
        delim = d;
        manip = m;
        del_vector = true;
        obj = o;
        include = new std::vector<bool>(130, false);
    (*include)[i1]=true;
    if (i2 == USERDATA_NULL) return;
    (*include)[i2]=true;
    if (i3 == USERDATA_NULL) return;
    (*include)[i3]=true;
    if (i4 == USERDATA_NULL) return;
    (*include)[i4]=true;
    if (i5 == USERDATA_NULL) return;
    (*include)[i5]=true;
    if (i6 == USERDATA_NULL) return;
    (*include)[i6]=true;
    if (i7 == USERDATA_NULL) return;
    (*include)[i7]=true;
    if (i8 == USERDATA_NULL) return;
    (*include)[i8]=true;
    if (i9 == USERDATA_NULL) return;
    (*include)[i9]=true;
    if (i10 == USERDATA_NULL) return;
    (*include)[i10]=true;
    if (i11 == USERDATA_NULL) return;
    (*include)[i11]=true;
    if (i12 == USERDATA_NULL) return;
    (*include)[i12]=true;
    if (i13 == USERDATA_NULL) return;
    (*include)[i13]=true;
    if (i14 == USERDATA_NULL) return;
    (*include)[i14]=true;
    if (i15 == USERDATA_NULL) return;
    (*include)[i15]=true;
    if (i16 == USERDATA_NULL) return;
    (*include)[i16]=true;
    if (i17 == USERDATA_NULL) return;
    (*include)[i17]=true;
    if (i18 == USERDATA_NULL) return;
    (*include)[i18]=true;
    if (i19 == USERDATA_NULL) return;
    (*include)[i19]=true;
    if (i20 == USERDATA_NULL) return;
    (*include)[i20]=true;
    if (i21 == USERDATA_NULL) return;
    (*include)[i21]=true;
    if (i22 == USERDATA_NULL) return;
    (*include)[i22]=true;
    if (i23 == USERDATA_NULL) return;
    (*include)[i23]=true;
    if (i24 == USERDATA_NULL) return;
    (*include)[i24]=true;
    if (i25 == USERDATA_NULL) return;
    (*include)[i25]=true;
    if (i26 == USERDATA_NULL) return;
    (*include)[i26]=true;
    if (i27 == USERDATA_NULL) return;
    (*include)[i27]=true;
    if (i28 == USERDATA_NULL) return;
    (*include)[i28]=true;
    if (i29 == USERDATA_NULL) return;
    (*include)[i29]=true;
    if (i30 == USERDATA_NULL) return;
    (*include)[i30]=true;
    if (i31 == USERDATA_NULL) return;
    (*include)[i31]=true;
    if (i32 == USERDATA_NULL) return;
    (*include)[i32]=true;
    if (i33 == USERDATA_NULL) return;
    (*include)[i33]=true;
    if (i34 == USERDATA_NULL) return;
    (*include)[i34]=true;
    if (i35 == USERDATA_NULL) return;
    (*include)[i35]=true;
    if (i36 == USERDATA_NULL) return;
    (*include)[i36]=true;
    if (i37 == USERDATA_NULL) return;
    (*include)[i37]=true;
    if (i38 == USERDATA_NULL) return;
    (*include)[i38]=true;
    if (i39 == USERDATA_NULL) return;
    (*include)[i39]=true;
    if (i40 == USERDATA_NULL) return;
    (*include)[i40]=true;
    if (i41 == USERDATA_NULL) return;
    (*include)[i41]=true;
    if (i42 == USERDATA_NULL) return;
    (*include)[i42]=true;
    if (i43 == USERDATA_NULL) return;
    (*include)[i43]=true;
    if (i44 == USERDATA_NULL) return;
    (*include)[i44]=true;
    if (i45 == USERDATA_NULL) return;
    (*include)[i45]=true;
    if (i46 == USERDATA_NULL) return;
    (*include)[i46]=true;
    if (i47 == USERDATA_NULL) return;
    (*include)[i47]=true;
    if (i48 == USERDATA_NULL) return;
    (*include)[i48]=true;
    if (i49 == USERDATA_NULL) return;
    (*include)[i49]=true;
    if (i50 == USERDATA_NULL) return;
    (*include)[i50]=true;
    if (i51 == USERDATA_NULL) return;
    (*include)[i51]=true;
    if (i52 == USERDATA_NULL) return;
    (*include)[i52]=true;
    if (i53 == USERDATA_NULL) return;
    (*include)[i53]=true;
    if (i54 == USERDATA_NULL) return;
    (*include)[i54]=true;
    if (i55 == USERDATA_NULL) return;
    (*include)[i55]=true;
    if (i56 == USERDATA_NULL) return;
    (*include)[i56]=true;
    if (i57 == USERDATA_NULL) return;
    (*include)[i57]=true;
    if (i58 == USERDATA_NULL) return;
    (*include)[i58]=true;
    if (i59 == USERDATA_NULL) return;
    (*include)[i59]=true;
    if (i60 == USERDATA_NULL) return;
    (*include)[i60]=true;
    if (i61 == USERDATA_NULL) return;
    (*include)[i61]=true;
    if (i62 == USERDATA_NULL) return;
    (*include)[i62]=true;
    if (i63 == USERDATA_NULL) return;
    (*include)[i63]=true;
    if (i64 == USERDATA_NULL) return;
    (*include)[i64]=true;
    if (i65 == USERDATA_NULL) return;
    (*include)[i65]=true;
    if (i66 == USERDATA_NULL) return;
    (*include)[i66]=true;
    if (i67 == USERDATA_NULL) return;
    (*include)[i67]=true;
    if (i68 == USERDATA_NULL) return;
    (*include)[i68]=true;
    if (i69 == USERDATA_NULL) return;
    (*include)[i69]=true;
    if (i70 == USERDATA_NULL) return;
    (*include)[i70]=true;
    if (i71 == USERDATA_NULL) return;
    (*include)[i71]=true;
    if (i72 == USERDATA_NULL) return;
    (*include)[i72]=true;
    if (i73 == USERDATA_NULL) return;
    (*include)[i73]=true;
    if (i74 == USERDATA_NULL) return;
    (*include)[i74]=true;
    if (i75 == USERDATA_NULL) return;
    (*include)[i75]=true;
    if (i76 == USERDATA_NULL) return;
    (*include)[i76]=true;
    if (i77 == USERDATA_NULL) return;
    (*include)[i77]=true;
    if (i78 == USERDATA_NULL) return;
    (*include)[i78]=true;
    if (i79 == USERDATA_NULL) return;
    (*include)[i79]=true;
    if (i80 == USERDATA_NULL) return;
    (*include)[i80]=true;
    if (i81 == USERDATA_NULL) return;
    (*include)[i81]=true;
    if (i82 == USERDATA_NULL) return;
    (*include)[i82]=true;
    if (i83 == USERDATA_NULL) return;
    (*include)[i83]=true;
    if (i84 == USERDATA_NULL) return;
    (*include)[i84]=true;
    if (i85 == USERDATA_NULL) return;
    (*include)[i85]=true;
    if (i86 == USERDATA_NULL) return;
    (*include)[i86]=true;
    if (i87 == USERDATA_NULL) return;
    (*include)[i87]=true;
    if (i88 == USERDATA_NULL) return;
    (*include)[i88]=true;
    if (i89 == USERDATA_NULL) return;
    (*include)[i89]=true;
    if (i90 == USERDATA_NULL) return;
    (*include)[i90]=true;
    if (i91 == USERDATA_NULL) return;
    (*include)[i91]=true;
    if (i92 == USERDATA_NULL) return;
    (*include)[i92]=true;
    if (i93 == USERDATA_NULL) return;
    (*include)[i93]=true;
    if (i94 == USERDATA_NULL) return;
    (*include)[i94]=true;
    if (i95 == USERDATA_NULL) return;
    (*include)[i95]=true;
    if (i96 == USERDATA_NULL) return;
    (*include)[i96]=true;
    if (i97 == USERDATA_NULL) return;
    (*include)[i97]=true;
    if (i98 == USERDATA_NULL) return;
    (*include)[i98]=true;
    if (i99 == USERDATA_NULL) return;
    (*include)[i99]=true;
    if (i100 == USERDATA_NULL) return;
    (*include)[i100]=true;
    if (i101 == USERDATA_NULL) return;
    (*include)[i101]=true;
    if (i102 == USERDATA_NULL) return;
    (*include)[i102]=true;
    if (i103 == USERDATA_NULL) return;
    (*include)[i103]=true;
    if (i104 == USERDATA_NULL) return;
    (*include)[i104]=true;
    if (i105 == USERDATA_NULL) return;
    (*include)[i105]=true;
    if (i106 == USERDATA_NULL) return;
    (*include)[i106]=true;
    if (i107 == USERDATA_NULL) return;
    (*include)[i107]=true;
    if (i108 == USERDATA_NULL) return;
    (*include)[i108]=true;
    if (i109 == USERDATA_NULL) return;
    (*include)[i109]=true;
    if (i110 == USERDATA_NULL) return;
    (*include)[i110]=true;
    if (i111 == USERDATA_NULL) return;
    (*include)[i111]=true;
    if (i112 == USERDATA_NULL) return;
    (*include)[i112]=true;
    if (i113 == USERDATA_NULL) return;
    (*include)[i113]=true;
    if (i114 == USERDATA_NULL) return;
    (*include)[i114]=true;
    if (i115 == USERDATA_NULL) return;
    (*include)[i115]=true;
    if (i116 == USERDATA_NULL) return;
    (*include)[i116]=true;
    if (i117 == USERDATA_NULL) return;
    (*include)[i117]=true;
    if (i118 == USERDATA_NULL) return;
    (*include)[i118]=true;
    if (i119 == USERDATA_NULL) return;
    (*include)[i119]=true;
    if (i120 == USERDATA_NULL) return;
    (*include)[i120]=true;
    if (i121 == USERDATA_NULL) return;
    (*include)[i121]=true;
    if (i122 == USERDATA_NULL) return;
    (*include)[i122]=true;
    if (i123 == USERDATA_NULL) return;
    (*include)[i123]=true;
    if (i124 == USERDATA_NULL) return;
    (*include)[i124]=true;
    if (i125 == USERDATA_NULL) return;
    (*include)[i125]=true;
    if (i126 == USERDATA_NULL) return;
    (*include)[i126]=true;
    if (i127 == USERDATA_NULL) return;
    (*include)[i127]=true;
    if (i128 == USERDATA_NULL) return;
    (*include)[i128]=true;
    if (i129 == USERDATA_NULL) return;
    (*include)[i129]=true;
    if (i130 == USERDATA_NULL) return;
    (*include)[i130]=true;

    }

    template <class Manip>
    CUserData_cus_equal_list<Manip>::CUserData_cus_equal_list
            (const CUserData* o, const char* d, const char* c, Manip m, bool i1, bool i2, bool i3, bool i4, bool i5, bool i6, bool i7, bool i8, bool i9, bool i10, bool i11, bool i12, bool i13, bool i14, bool i15, bool i16, bool i17, bool i18, bool i19, bool i20, bool i21, bool i22, bool i23, bool i24, bool i25, bool i26, bool i27, bool i28, bool i29, bool i30, bool i31, bool i32, bool i33, bool i34, bool i35, bool i36, bool i37, bool i38, bool i39, bool i40, bool i41, bool i42, bool i43, bool i44, bool i45, bool i46, bool i47, bool i48, bool i49, bool i50, bool i51, bool i52, bool i53, bool i54, bool i55, bool i56, bool i57, bool i58, bool i59, bool i60, bool i61, bool i62, bool i63, bool i64, bool i65, bool i66, bool i67, bool i68, bool i69, bool i70, bool i71, bool i72, bool i73, bool i74, bool i75, bool i76, bool i77, bool i78, bool i79, bool i80, bool i81, bool i82, bool i83, bool i84, bool i85, bool i86, bool i87, bool i88, bool i89, bool i90, bool i91, bool i92, bool i93, bool i94, bool i95, bool i96, bool i97, bool i98, bool i99, bool i100, bool i101, bool i102, bool i103, bool i104, bool i105, bool i106, bool i107, bool i108, bool i109, bool i110, bool i111, bool i112, bool i113, bool i114, bool i115, bool i116, bool i117, bool i118, bool i119, bool i120, bool i121, bool i122, bool i123, bool i124, bool i125, bool i126, bool i127, bool i128, bool i129, bool i130)
    {
        delim = d;
        comp = c;
        manip = m;
        del_vector = true;
        obj = o;
        include = new std::vector<bool>(130, false);
    if (i1) (*include)[0]=true;
    if (i2) (*include)[1]=true;
    if (i3) (*include)[2]=true;
    if (i4) (*include)[3]=true;
    if (i5) (*include)[4]=true;
    if (i6) (*include)[5]=true;
    if (i7) (*include)[6]=true;
    if (i8) (*include)[7]=true;
    if (i9) (*include)[8]=true;
    if (i10) (*include)[9]=true;
    if (i11) (*include)[10]=true;
    if (i12) (*include)[11]=true;
    if (i13) (*include)[12]=true;
    if (i14) (*include)[13]=true;
    if (i15) (*include)[14]=true;
    if (i16) (*include)[15]=true;
    if (i17) (*include)[16]=true;
    if (i18) (*include)[17]=true;
    if (i19) (*include)[18]=true;
    if (i20) (*include)[19]=true;
    if (i21) (*include)[20]=true;
    if (i22) (*include)[21]=true;
    if (i23) (*include)[22]=true;
    if (i24) (*include)[23]=true;
    if (i25) (*include)[24]=true;
    if (i26) (*include)[25]=true;
    if (i27) (*include)[26]=true;
    if (i28) (*include)[27]=true;
    if (i29) (*include)[28]=true;
    if (i30) (*include)[29]=true;
    if (i31) (*include)[30]=true;
    if (i32) (*include)[31]=true;
    if (i33) (*include)[32]=true;
    if (i34) (*include)[33]=true;
    if (i35) (*include)[34]=true;
    if (i36) (*include)[35]=true;
    if (i37) (*include)[36]=true;
    if (i38) (*include)[37]=true;
    if (i39) (*include)[38]=true;
    if (i40) (*include)[39]=true;
    if (i41) (*include)[40]=true;
    if (i42) (*include)[41]=true;
    if (i43) (*include)[42]=true;
    if (i44) (*include)[43]=true;
    if (i45) (*include)[44]=true;
    if (i46) (*include)[45]=true;
    if (i47) (*include)[46]=true;
    if (i48) (*include)[47]=true;
    if (i49) (*include)[48]=true;
    if (i50) (*include)[49]=true;
    if (i51) (*include)[50]=true;
    if (i52) (*include)[51]=true;
    if (i53) (*include)[52]=true;
    if (i54) (*include)[53]=true;
    if (i55) (*include)[54]=true;
    if (i56) (*include)[55]=true;
    if (i57) (*include)[56]=true;
    if (i58) (*include)[57]=true;
    if (i59) (*include)[58]=true;
    if (i60) (*include)[59]=true;
    if (i61) (*include)[60]=true;
    if (i62) (*include)[61]=true;
    if (i63) (*include)[62]=true;
    if (i64) (*include)[63]=true;
    if (i65) (*include)[64]=true;
    if (i66) (*include)[65]=true;
    if (i67) (*include)[66]=true;
    if (i68) (*include)[67]=true;
    if (i69) (*include)[68]=true;
    if (i70) (*include)[69]=true;
    if (i71) (*include)[70]=true;
    if (i72) (*include)[71]=true;
    if (i73) (*include)[72]=true;
    if (i74) (*include)[73]=true;
    if (i75) (*include)[74]=true;
    if (i76) (*include)[75]=true;
    if (i77) (*include)[76]=true;
    if (i78) (*include)[77]=true;
    if (i79) (*include)[78]=true;
    if (i80) (*include)[79]=true;
    if (i81) (*include)[80]=true;
    if (i82) (*include)[81]=true;
    if (i83) (*include)[82]=true;
    if (i84) (*include)[83]=true;
    if (i85) (*include)[84]=true;
    if (i86) (*include)[85]=true;
    if (i87) (*include)[86]=true;
    if (i88) (*include)[87]=true;
    if (i89) (*include)[88]=true;
    if (i90) (*include)[89]=true;
    if (i91) (*include)[90]=true;
    if (i92) (*include)[91]=true;
    if (i93) (*include)[92]=true;
    if (i94) (*include)[93]=true;
    if (i95) (*include)[94]=true;
    if (i96) (*include)[95]=true;
    if (i97) (*include)[96]=true;
    if (i98) (*include)[97]=true;
    if (i99) (*include)[98]=true;
    if (i100) (*include)[99]=true;
    if (i101) (*include)[100]=true;
    if (i102) (*include)[101]=true;
    if (i103) (*include)[102]=true;
    if (i104) (*include)[103]=true;
    if (i105) (*include)[104]=true;
    if (i106) (*include)[105]=true;
    if (i107) (*include)[106]=true;
    if (i108) (*include)[107]=true;
    if (i109) (*include)[108]=true;
    if (i110) (*include)[109]=true;
    if (i111) (*include)[110]=true;
    if (i112) (*include)[111]=true;
    if (i113) (*include)[112]=true;
    if (i114) (*include)[113]=true;
    if (i115) (*include)[114]=true;
    if (i116) (*include)[115]=true;
    if (i117) (*include)[116]=true;
    if (i118) (*include)[117]=true;
    if (i119) (*include)[118]=true;
    if (i120) (*include)[119]=true;
    if (i121) (*include)[120]=true;
    if (i122) (*include)[121]=true;
    if (i123) (*include)[122]=true;
    if (i124) (*include)[123]=true;
    if (i125) (*include)[124]=true;
    if (i126) (*include)[125]=true;
    if (i127) (*include)[126]=true;
    if (i128) (*include)[127]=true;
    if (i129) (*include)[128]=true;
    if (i130) (*include)[129]=true;

    }

    template <class Manip>
    CUserData_cus_equal_list<Manip>::CUserData_cus_equal_list
            (const CUserData* o, const char* d, const char* c, Manip m, CUserData_enum i1, CUserData_enum i2, CUserData_enum i3, CUserData_enum i4, CUserData_enum i5, CUserData_enum i6, CUserData_enum i7, CUserData_enum i8, CUserData_enum i9, CUserData_enum i10, CUserData_enum i11, CUserData_enum i12, CUserData_enum i13, CUserData_enum i14, CUserData_enum i15, CUserData_enum i16, CUserData_enum i17, CUserData_enum i18, CUserData_enum i19, CUserData_enum i20, CUserData_enum i21, CUserData_enum i22, CUserData_enum i23, CUserData_enum i24, CUserData_enum i25, CUserData_enum i26, CUserData_enum i27, CUserData_enum i28, CUserData_enum i29, CUserData_enum i30, CUserData_enum i31, CUserData_enum i32, CUserData_enum i33, CUserData_enum i34, CUserData_enum i35, CUserData_enum i36, CUserData_enum i37, CUserData_enum i38, CUserData_enum i39, CUserData_enum i40, CUserData_enum i41, CUserData_enum i42, CUserData_enum i43, CUserData_enum i44, CUserData_enum i45, CUserData_enum i46, CUserData_enum i47, CUserData_enum i48, CUserData_enum i49, CUserData_enum i50, CUserData_enum i51, CUserData_enum i52, CUserData_enum i53, CUserData_enum i54, CUserData_enum i55, CUserData_enum i56, CUserData_enum i57, CUserData_enum i58, CUserData_enum i59, CUserData_enum i60, CUserData_enum i61, CUserData_enum i62, CUserData_enum i63, CUserData_enum i64, CUserData_enum i65, CUserData_enum i66, CUserData_enum i67, CUserData_enum i68, CUserData_enum i69, CUserData_enum i70, CUserData_enum i71, CUserData_enum i72, CUserData_enum i73, CUserData_enum i74, CUserData_enum i75, CUserData_enum i76, CUserData_enum i77, CUserData_enum i78, CUserData_enum i79, CUserData_enum i80, CUserData_enum i81, CUserData_enum i82, CUserData_enum i83, CUserData_enum i84, CUserData_enum i85, CUserData_enum i86, CUserData_enum i87, CUserData_enum i88, CUserData_enum i89, CUserData_enum i90, CUserData_enum i91, CUserData_enum i92, CUserData_enum i93, CUserData_enum i94, CUserData_enum i95, CUserData_enum i96, CUserData_enum i97, CUserData_enum i98, CUserData_enum i99, CUserData_enum i100, CUserData_enum i101, CUserData_enum i102, CUserData_enum i103, CUserData_enum i104, CUserData_enum i105, CUserData_enum i106, CUserData_enum i107, CUserData_enum i108, CUserData_enum i109, CUserData_enum i110, CUserData_enum i111, CUserData_enum i112, CUserData_enum i113, CUserData_enum i114, CUserData_enum i115, CUserData_enum i116, CUserData_enum i117, CUserData_enum i118, CUserData_enum i119, CUserData_enum i120, CUserData_enum i121, CUserData_enum i122, CUserData_enum i123, CUserData_enum i124, CUserData_enum i125, CUserData_enum i126, CUserData_enum i127, CUserData_enum i128, CUserData_enum i129, CUserData_enum i130)
    {
        delim = d;
        comp = c;
        manip = m;
        del_vector = true;
        obj = o;
        include = new std::vector<bool>(130, false);
    (*include)[i1]=true;
    if (i2 == USERDATA_NULL) return;
    (*include)[i2]=true;
    if (i3 == USERDATA_NULL) return;
    (*include)[i3]=true;
    if (i4 == USERDATA_NULL) return;
    (*include)[i4]=true;
    if (i5 == USERDATA_NULL) return;
    (*include)[i5]=true;
    if (i6 == USERDATA_NULL) return;
    (*include)[i6]=true;
    if (i7 == USERDATA_NULL) return;
    (*include)[i7]=true;
    if (i8 == USERDATA_NULL) return;
    (*include)[i8]=true;
    if (i9 == USERDATA_NULL) return;
    (*include)[i9]=true;
    if (i10 == USERDATA_NULL) return;
    (*include)[i10]=true;
    if (i11 == USERDATA_NULL) return;
    (*include)[i11]=true;
    if (i12 == USERDATA_NULL) return;
    (*include)[i12]=true;
    if (i13 == USERDATA_NULL) return;
    (*include)[i13]=true;
    if (i14 == USERDATA_NULL) return;
    (*include)[i14]=true;
    if (i15 == USERDATA_NULL) return;
    (*include)[i15]=true;
    if (i16 == USERDATA_NULL) return;
    (*include)[i16]=true;
    if (i17 == USERDATA_NULL) return;
    (*include)[i17]=true;
    if (i18 == USERDATA_NULL) return;
    (*include)[i18]=true;
    if (i19 == USERDATA_NULL) return;
    (*include)[i19]=true;
    if (i20 == USERDATA_NULL) return;
    (*include)[i20]=true;
    if (i21 == USERDATA_NULL) return;
    (*include)[i21]=true;
    if (i22 == USERDATA_NULL) return;
    (*include)[i22]=true;
    if (i23 == USERDATA_NULL) return;
    (*include)[i23]=true;
    if (i24 == USERDATA_NULL) return;
    (*include)[i24]=true;
    if (i25 == USERDATA_NULL) return;
    (*include)[i25]=true;
    if (i26 == USERDATA_NULL) return;
    (*include)[i26]=true;
    if (i27 == USERDATA_NULL) return;
    (*include)[i27]=true;
    if (i28 == USERDATA_NULL) return;
    (*include)[i28]=true;
    if (i29 == USERDATA_NULL) return;
    (*include)[i29]=true;
    if (i30 == USERDATA_NULL) return;
    (*include)[i30]=true;
    if (i31 == USERDATA_NULL) return;
    (*include)[i31]=true;
    if (i32 == USERDATA_NULL) return;
    (*include)[i32]=true;
    if (i33 == USERDATA_NULL) return;
    (*include)[i33]=true;
    if (i34 == USERDATA_NULL) return;
    (*include)[i34]=true;
    if (i35 == USERDATA_NULL) return;
    (*include)[i35]=true;
    if (i36 == USERDATA_NULL) return;
    (*include)[i36]=true;
    if (i37 == USERDATA_NULL) return;
    (*include)[i37]=true;
    if (i38 == USERDATA_NULL) return;
    (*include)[i38]=true;
    if (i39 == USERDATA_NULL) return;
    (*include)[i39]=true;
    if (i40 == USERDATA_NULL) return;
    (*include)[i40]=true;
    if (i41 == USERDATA_NULL) return;
    (*include)[i41]=true;
    if (i42 == USERDATA_NULL) return;
    (*include)[i42]=true;
    if (i43 == USERDATA_NULL) return;
    (*include)[i43]=true;
    if (i44 == USERDATA_NULL) return;
    (*include)[i44]=true;
    if (i45 == USERDATA_NULL) return;
    (*include)[i45]=true;
    if (i46 == USERDATA_NULL) return;
    (*include)[i46]=true;
    if (i47 == USERDATA_NULL) return;
    (*include)[i47]=true;
    if (i48 == USERDATA_NULL) return;
    (*include)[i48]=true;
    if (i49 == USERDATA_NULL) return;
    (*include)[i49]=true;
    if (i50 == USERDATA_NULL) return;
    (*include)[i50]=true;
    if (i51 == USERDATA_NULL) return;
    (*include)[i51]=true;
    if (i52 == USERDATA_NULL) return;
    (*include)[i52]=true;
    if (i53 == USERDATA_NULL) return;
    (*include)[i53]=true;
    if (i54 == USERDATA_NULL) return;
    (*include)[i54]=true;
    if (i55 == USERDATA_NULL) return;
    (*include)[i55]=true;
    if (i56 == USERDATA_NULL) return;
    (*include)[i56]=true;
    if (i57 == USERDATA_NULL) return;
    (*include)[i57]=true;
    if (i58 == USERDATA_NULL) return;
    (*include)[i58]=true;
    if (i59 == USERDATA_NULL) return;
    (*include)[i59]=true;
    if (i60 == USERDATA_NULL) return;
    (*include)[i60]=true;
    if (i61 == USERDATA_NULL) return;
    (*include)[i61]=true;
    if (i62 == USERDATA_NULL) return;
    (*include)[i62]=true;
    if (i63 == USERDATA_NULL) return;
    (*include)[i63]=true;
    if (i64 == USERDATA_NULL) return;
    (*include)[i64]=true;
    if (i65 == USERDATA_NULL) return;
    (*include)[i65]=true;
    if (i66 == USERDATA_NULL) return;
    (*include)[i66]=true;
    if (i67 == USERDATA_NULL) return;
    (*include)[i67]=true;
    if (i68 == USERDATA_NULL) return;
    (*include)[i68]=true;
    if (i69 == USERDATA_NULL) return;
    (*include)[i69]=true;
    if (i70 == USERDATA_NULL) return;
    (*include)[i70]=true;
    if (i71 == USERDATA_NULL) return;
    (*include)[i71]=true;
    if (i72 == USERDATA_NULL) return;
    (*include)[i72]=true;
    if (i73 == USERDATA_NULL) return;
    (*include)[i73]=true;
    if (i74 == USERDATA_NULL) return;
    (*include)[i74]=true;
    if (i75 == USERDATA_NULL) return;
    (*include)[i75]=true;
    if (i76 == USERDATA_NULL) return;
    (*include)[i76]=true;
    if (i77 == USERDATA_NULL) return;
    (*include)[i77]=true;
    if (i78 == USERDATA_NULL) return;
    (*include)[i78]=true;
    if (i79 == USERDATA_NULL) return;
    (*include)[i79]=true;
    if (i80 == USERDATA_NULL) return;
    (*include)[i80]=true;
    if (i81 == USERDATA_NULL) return;
    (*include)[i81]=true;
    if (i82 == USERDATA_NULL) return;
    (*include)[i82]=true;
    if (i83 == USERDATA_NULL) return;
    (*include)[i83]=true;
    if (i84 == USERDATA_NULL) return;
    (*include)[i84]=true;
    if (i85 == USERDATA_NULL) return;
    (*include)[i85]=true;
    if (i86 == USERDATA_NULL) return;
    (*include)[i86]=true;
    if (i87 == USERDATA_NULL) return;
    (*include)[i87]=true;
    if (i88 == USERDATA_NULL) return;
    (*include)[i88]=true;
    if (i89 == USERDATA_NULL) return;
    (*include)[i89]=true;
    if (i90 == USERDATA_NULL) return;
    (*include)[i90]=true;
    if (i91 == USERDATA_NULL) return;
    (*include)[i91]=true;
    if (i92 == USERDATA_NULL) return;
    (*include)[i92]=true;
    if (i93 == USERDATA_NULL) return;
    (*include)[i93]=true;
    if (i94 == USERDATA_NULL) return;
    (*include)[i94]=true;
    if (i95 == USERDATA_NULL) return;
    (*include)[i95]=true;
    if (i96 == USERDATA_NULL) return;
    (*include)[i96]=true;
    if (i97 == USERDATA_NULL) return;
    (*include)[i97]=true;
    if (i98 == USERDATA_NULL) return;
    (*include)[i98]=true;
    if (i99 == USERDATA_NULL) return;
    (*include)[i99]=true;
    if (i100 == USERDATA_NULL) return;
    (*include)[i100]=true;
    if (i101 == USERDATA_NULL) return;
    (*include)[i101]=true;
    if (i102 == USERDATA_NULL) return;
    (*include)[i102]=true;
    if (i103 == USERDATA_NULL) return;
    (*include)[i103]=true;
    if (i104 == USERDATA_NULL) return;
    (*include)[i104]=true;
    if (i105 == USERDATA_NULL) return;
    (*include)[i105]=true;
    if (i106 == USERDATA_NULL) return;
    (*include)[i106]=true;
    if (i107 == USERDATA_NULL) return;
    (*include)[i107]=true;
    if (i108 == USERDATA_NULL) return;
    (*include)[i108]=true;
    if (i109 == USERDATA_NULL) return;
    (*include)[i109]=true;
    if (i110 == USERDATA_NULL) return;
    (*include)[i110]=true;
    if (i111 == USERDATA_NULL) return;
    (*include)[i111]=true;
    if (i112 == USERDATA_NULL) return;
    (*include)[i112]=true;
    if (i113 == USERDATA_NULL) return;
    (*include)[i113]=true;
    if (i114 == USERDATA_NULL) return;
    (*include)[i114]=true;
    if (i115 == USERDATA_NULL) return;
    (*include)[i115]=true;
    if (i116 == USERDATA_NULL) return;
    (*include)[i116]=true;
    if (i117 == USERDATA_NULL) return;
    (*include)[i117]=true;
    if (i118 == USERDATA_NULL) return;
    (*include)[i118]=true;
    if (i119 == USERDATA_NULL) return;
    (*include)[i119]=true;
    if (i120 == USERDATA_NULL) return;
    (*include)[i120]=true;
    if (i121 == USERDATA_NULL) return;
    (*include)[i121]=true;
    if (i122 == USERDATA_NULL) return;
    (*include)[i122]=true;
    if (i123 == USERDATA_NULL) return;
    (*include)[i123]=true;
    if (i124 == USERDATA_NULL) return;
    (*include)[i124]=true;
    if (i125 == USERDATA_NULL) return;
    (*include)[i125]=true;
    if (i126 == USERDATA_NULL) return;
    (*include)[i126]=true;
    if (i127 == USERDATA_NULL) return;
    (*include)[i127]=true;
    if (i128 == USERDATA_NULL) return;
    (*include)[i128]=true;
    if (i129 == USERDATA_NULL) return;
    (*include)[i129]=true;
    if (i130 == USERDATA_NULL) return;
    (*include)[i130]=true;

    }

    template <class Manip>
    std::ostream& operator <<(std::ostream& s, const CUserData_value_list<Manip>& obj)
    {
    s << obj.manip << obj.obj->name << obj.delim;
    s << obj.manip << obj.obj->mate << obj.delim;
    s << obj.manip << obj.obj->lookface << obj.delim;
    s << obj.manip << obj.obj->hair << obj.delim;
    s << obj.manip << obj.obj->length << obj.delim;
    s << obj.manip << obj.obj->fat << obj.delim;
    s << obj.manip << obj.obj->money << obj.delim;
    s << obj.manip << obj.obj->money_saved << obj.delim;
    s << obj.manip << obj.obj->task_data << obj.delim;
    s << obj.manip << obj.obj->level << obj.delim;
    s << obj.manip << obj.obj->exp << obj.delim;
    s << obj.manip << obj.obj->power << obj.delim;
    s << obj.manip << obj.obj->constitution << obj.delim;
    s << obj.manip << obj.obj->dexterity << obj.delim;
    s << obj.manip << obj.obj->Speed << obj.delim;
    s << obj.manip << obj.obj->health << obj.delim;
    s << obj.manip << obj.obj->soul << obj.delim;
    s << obj.manip << obj.obj->additional_point << obj.delim;
    s << obj.manip << obj.obj->auto_allot << obj.delim;
    s << obj.manip << obj.obj->life << obj.delim;
    s << obj.manip << obj.obj->mana << obj.delim;
    s << obj.manip << obj.obj->profession << obj.delim;
    s << obj.manip << obj.obj->potential << obj.delim;
    s << obj.manip << obj.obj->pk << obj.delim;
    s << obj.manip << obj.obj->nobility << obj.delim;
    s << obj.manip << obj.obj->medal << obj.delim;
    s << obj.manip << obj.obj->medal_select << obj.delim;
    s << obj.manip << obj.obj->metempsychosis << obj.delim;
    s << obj.manip << obj.obj->syndicate_id << obj.delim;
    s << obj.manip << obj.obj->recordmap_id << obj.delim;
    s << obj.manip << obj.obj->recordx << obj.delim;
    s << obj.manip << obj.obj->recordy << obj.delim;
    s << obj.manip << obj.obj->account_id << obj.delim;
    s << obj.manip << obj.obj->id << obj.delim;
    s << obj.manip << obj.obj->last_login << obj.delim;
    s << obj.manip << obj.obj->account << obj.delim;
    s << obj.manip << obj.obj->password << obj.delim;
    s << obj.manip << obj.obj->task_mask << obj.delim;
    s << obj.manip << obj.obj->time_of_life << obj.delim;
    s << obj.manip << obj.obj->virtue << obj.delim;
    s << obj.manip << obj.obj->home_id << obj.delim;
    s << obj.manip << obj.obj->title << obj.delim;
    s << obj.manip << obj.obj->title_select << obj.delim;
    s << obj.manip << obj.obj->tutor_exp << obj.delim;
    s << obj.manip << obj.obj->tutor_level << obj.delim;
    s << obj.manip << obj.obj->maxlife_percent << obj.delim;
    s << obj.manip << obj.obj->mercenary_rank << obj.delim;
    s << obj.manip << obj.obj->mercenary_exp << obj.delim;
    s << obj.manip << obj.obj->nobility_rank << obj.delim;
    s << obj.manip << obj.obj->exploit << obj.delim;
    s << obj.manip << obj.obj->eud_pack_size << obj.delim;
    s << obj.manip << obj.obj->disableFlag << obj.delim;
    s << obj.manip << obj.obj->reg_time << obj.delim;
    s << obj.manip << obj.obj->accu_online_time << obj.delim;
    s << obj.manip << obj.obj->accu_offline_time << obj.delim;
    s << obj.manip << obj.obj->last_logout << obj.delim;
    s << obj.manip << obj.obj->prompt_ver << obj.delim;
    s << obj.manip << obj.obj->Friend_share << obj.delim;
    s << obj.manip << obj.obj->Login_time << obj.delim;
    s << obj.manip << obj.obj->Login_ip << obj.delim;
    s << obj.manip << obj.obj->soul_value << obj.delim;
    s << obj.manip << obj.obj->brood_times << obj.delim;
    s << obj.manip << obj.obj->emoney << obj.delim;
    s << obj.manip << obj.obj->chk_sum << obj.delim;
    s << obj.manip << obj.obj->elock << obj.delim;
    s << obj.manip << obj.obj->ExpBallUsage << obj.delim;
    s << obj.manip << obj.obj->ExpCrystalUsage << obj.delim;
    s << obj.manip << obj.obj->cheat_time << obj.delim;
    s << obj.manip << obj.obj->online_time << obj.delim;
    s << obj.manip << obj.obj->auto_exercise << obj.delim;
    s << obj.manip << obj.obj->hung_last_logout << obj.delim;
    s << obj.manip << obj.obj->god_status << obj.delim;
    s << obj.manip << obj.obj->big_prize_fails << obj.delim;
    s << obj.manip << obj.obj->small_prize_fails << obj.delim;
    s << obj.manip << obj.obj->bonus_points << obj.delim;
    s << obj.manip << obj.obj->flower << obj.delim;
    s << obj.manip << obj.obj->flower_w << obj.delim;
    s << obj.manip << obj.obj->flower_p << obj.delim;
    s << obj.manip << obj.obj->income << obj.delim;
    s << obj.manip << obj.obj->illu_ButterFly << obj.delim;
    s << obj.manip << obj.obj->illu_Fish << obj.delim;
    s << obj.manip << obj.obj->illu_Shell << obj.delim;
    s << obj.manip << obj.obj->illu_Herbal << obj.delim;
    s << obj.manip << obj.obj->illu_Ore << obj.delim;
    s << obj.manip << obj.obj->password_id << obj.delim;
    s << obj.manip << obj.obj->quiz_point << obj.delim;
    s << obj.manip << obj.obj->protect_state << obj.delim;
    s << obj.manip << obj.obj->donation << obj.delim;
    s << obj.manip << obj.obj->wood << obj.delim;
    s << obj.manip << obj.obj->stone << obj.delim;
    s << obj.manip << obj.obj->todo_list_mask1 << obj.delim;
    s << obj.manip << obj.obj->todo_list1 << obj.delim;
    s << obj.manip << obj.obj->todo_list_hex1 << obj.delim;
    s << obj.manip << obj.obj->coach << obj.delim;
    s << obj.manip << obj.obj->coach_time << obj.delim;
    s << obj.manip << obj.obj->coach_deed << obj.delim;
    s << obj.manip << obj.obj->coach_date << obj.delim;
    s << obj.manip << obj.obj->extra_hatch_size << obj.delim;
    s << obj.manip << obj.obj->shadiness_money << obj.delim;
    s << obj.manip << obj.obj->shadiness_emoney << obj.delim;
    s << obj.manip << obj.obj->soul_value_lev << obj.delim;
    s << obj.manip << obj.obj->business << obj.delim;
    s << obj.manip << obj.obj->emoney2 << obj.delim;
    s << obj.manip << obj.obj->type << obj.delim;
    s << obj.manip << obj.obj->god_strength << obj.delim;
    s << obj.manip << obj.obj->god_level << obj.delim;
    s << obj.manip << obj.obj->deification << obj.delim;
    s << obj.manip << obj.obj->tmoney << obj.delim;
    s << obj.manip << obj.obj->demon_level << obj.delim;
    s << obj.manip << obj.obj->demon_exp << obj.delim;
    s << obj.manip << obj.obj->socialclass << obj.delim;
    s << obj.manip << obj.obj->credit_point << obj.delim;
    s << obj.manip << obj.obj->credit_limit << obj.delim;
    s << obj.manip << obj.obj->credit_return << obj.delim;
    s << obj.manip << obj.obj->eudkernel_id << obj.delim;
    s << obj.manip << obj.obj->refinery_time_end << obj.delim;
    s << obj.manip << obj.obj->pack_add << obj.delim;
    s << obj.manip << obj.obj->boundary_lev << obj.delim;
    s << obj.manip << obj.obj->boundary_exp << obj.delim;
    s << obj.manip << obj.obj->offer_point << obj.delim;
    s << obj.manip << obj.obj->battle_lev << obj.delim;
    s << obj.manip << obj.obj->channel_account << obj.delim;
    s << obj.manip << obj.obj->recharge_emoney << obj.delim;
    s << obj.manip << obj.obj->auto_battle_time << obj.delim;
    s << obj.manip << obj.obj->first_recharge << obj.delim;
    s << obj.manip << obj.obj->special_flag << obj.delim;
    s << obj.manip << obj.obj->vip_lev << obj.delim;
    s << obj.manip << obj.obj->ghosttoexp_amount << obj.delim;
    s << obj.manip << obj.obj->vigor << obj.delim;
    s << obj.manip << obj.obj->func_list;
        return s;
    }

    template <class Manip>
    std::ostream& operator <<(std::ostream& s, const CUserData_field_list<Manip>& obj)
    {
    s << obj.manip << '`' << obj.obj->names[0] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[1] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[2] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[3] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[4] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[5] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[6] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[7] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[8] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[9] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[10] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[11] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[12] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[13] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[14] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[15] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[16] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[17] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[18] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[19] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[20] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[21] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[22] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[23] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[24] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[25] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[26] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[27] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[28] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[29] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[30] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[31] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[32] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[33] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[34] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[35] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[36] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[37] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[38] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[39] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[40] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[41] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[42] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[43] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[44] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[45] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[46] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[47] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[48] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[49] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[50] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[51] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[52] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[53] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[54] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[55] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[56] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[57] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[58] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[59] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[60] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[61] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[62] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[63] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[64] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[65] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[66] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[67] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[68] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[69] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[70] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[71] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[72] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[73] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[74] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[75] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[76] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[77] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[78] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[79] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[80] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[81] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[82] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[83] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[84] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[85] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[86] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[87] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[88] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[89] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[90] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[91] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[92] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[93] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[94] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[95] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[96] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[97] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[98] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[99] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[100] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[101] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[102] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[103] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[104] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[105] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[106] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[107] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[108] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[109] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[110] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[111] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[112] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[113] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[114] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[115] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[116] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[117] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[118] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[119] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[120] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[121] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[122] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[123] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[124] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[125] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[126] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[127] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[128] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[129] << '`';
        return s;
    }

    template <class Manip>
    std::ostream& operator <<(std::ostream& s, const CUserData_equal_list<Manip>& obj)
    {
    s << '`' << obj.obj->names[0] << '`' << obj.comp << obj.manip << obj.obj->name << obj.delim;
    s << '`' << obj.obj->names[1] << '`' << obj.comp << obj.manip << obj.obj->mate << obj.delim;
    s << '`' << obj.obj->names[2] << '`' << obj.comp << obj.manip << obj.obj->lookface << obj.delim;
    s << '`' << obj.obj->names[3] << '`' << obj.comp << obj.manip << obj.obj->hair << obj.delim;
    s << '`' << obj.obj->names[4] << '`' << obj.comp << obj.manip << obj.obj->length << obj.delim;
    s << '`' << obj.obj->names[5] << '`' << obj.comp << obj.manip << obj.obj->fat << obj.delim;
    s << '`' << obj.obj->names[6] << '`' << obj.comp << obj.manip << obj.obj->money << obj.delim;
    s << '`' << obj.obj->names[7] << '`' << obj.comp << obj.manip << obj.obj->money_saved << obj.delim;
    s << '`' << obj.obj->names[8] << '`' << obj.comp << obj.manip << obj.obj->task_data << obj.delim;
    s << '`' << obj.obj->names[9] << '`' << obj.comp << obj.manip << obj.obj->level << obj.delim;
    s << '`' << obj.obj->names[10] << '`' << obj.comp << obj.manip << obj.obj->exp << obj.delim;
    s << '`' << obj.obj->names[11] << '`' << obj.comp << obj.manip << obj.obj->power << obj.delim;
    s << '`' << obj.obj->names[12] << '`' << obj.comp << obj.manip << obj.obj->constitution << obj.delim;
    s << '`' << obj.obj->names[13] << '`' << obj.comp << obj.manip << obj.obj->dexterity << obj.delim;
    s << '`' << obj.obj->names[14] << '`' << obj.comp << obj.manip << obj.obj->Speed << obj.delim;
    s << '`' << obj.obj->names[15] << '`' << obj.comp << obj.manip << obj.obj->health << obj.delim;
    s << '`' << obj.obj->names[16] << '`' << obj.comp << obj.manip << obj.obj->soul << obj.delim;
    s << '`' << obj.obj->names[17] << '`' << obj.comp << obj.manip << obj.obj->additional_point << obj.delim;
    s << '`' << obj.obj->names[18] << '`' << obj.comp << obj.manip << obj.obj->auto_allot << obj.delim;
    s << '`' << obj.obj->names[19] << '`' << obj.comp << obj.manip << obj.obj->life << obj.delim;
    s << '`' << obj.obj->names[20] << '`' << obj.comp << obj.manip << obj.obj->mana << obj.delim;
    s << '`' << obj.obj->names[21] << '`' << obj.comp << obj.manip << obj.obj->profession << obj.delim;
    s << '`' << obj.obj->names[22] << '`' << obj.comp << obj.manip << obj.obj->potential << obj.delim;
    s << '`' << obj.obj->names[23] << '`' << obj.comp << obj.manip << obj.obj->pk << obj.delim;
    s << '`' << obj.obj->names[24] << '`' << obj.comp << obj.manip << obj.obj->nobility << obj.delim;
    s << '`' << obj.obj->names[25] << '`' << obj.comp << obj.manip << obj.obj->medal << obj.delim;
    s << '`' << obj.obj->names[26] << '`' << obj.comp << obj.manip << obj.obj->medal_select << obj.delim;
    s << '`' << obj.obj->names[27] << '`' << obj.comp << obj.manip << obj.obj->metempsychosis << obj.delim;
    s << '`' << obj.obj->names[28] << '`' << obj.comp << obj.manip << obj.obj->syndicate_id << obj.delim;
    s << '`' << obj.obj->names[29] << '`' << obj.comp << obj.manip << obj.obj->recordmap_id << obj.delim;
    s << '`' << obj.obj->names[30] << '`' << obj.comp << obj.manip << obj.obj->recordx << obj.delim;
    s << '`' << obj.obj->names[31] << '`' << obj.comp << obj.manip << obj.obj->recordy << obj.delim;
    s << '`' << obj.obj->names[32] << '`' << obj.comp << obj.manip << obj.obj->account_id << obj.delim;
    s << '`' << obj.obj->names[33] << '`' << obj.comp << obj.manip << obj.obj->id << obj.delim;
    s << '`' << obj.obj->names[34] << '`' << obj.comp << obj.manip << obj.obj->last_login << obj.delim;
    s << '`' << obj.obj->names[35] << '`' << obj.comp << obj.manip << obj.obj->account << obj.delim;
    s << '`' << obj.obj->names[36] << '`' << obj.comp << obj.manip << obj.obj->password << obj.delim;
    s << '`' << obj.obj->names[37] << '`' << obj.comp << obj.manip << obj.obj->task_mask << obj.delim;
    s << '`' << obj.obj->names[38] << '`' << obj.comp << obj.manip << obj.obj->time_of_life << obj.delim;
    s << '`' << obj.obj->names[39] << '`' << obj.comp << obj.manip << obj.obj->virtue << obj.delim;
    s << '`' << obj.obj->names[40] << '`' << obj.comp << obj.manip << obj.obj->home_id << obj.delim;
    s << '`' << obj.obj->names[41] << '`' << obj.comp << obj.manip << obj.obj->title << obj.delim;
    s << '`' << obj.obj->names[42] << '`' << obj.comp << obj.manip << obj.obj->title_select << obj.delim;
    s << '`' << obj.obj->names[43] << '`' << obj.comp << obj.manip << obj.obj->tutor_exp << obj.delim;
    s << '`' << obj.obj->names[44] << '`' << obj.comp << obj.manip << obj.obj->tutor_level << obj.delim;
    s << '`' << obj.obj->names[45] << '`' << obj.comp << obj.manip << obj.obj->maxlife_percent << obj.delim;
    s << '`' << obj.obj->names[46] << '`' << obj.comp << obj.manip << obj.obj->mercenary_rank << obj.delim;
    s << '`' << obj.obj->names[47] << '`' << obj.comp << obj.manip << obj.obj->mercenary_exp << obj.delim;
    s << '`' << obj.obj->names[48] << '`' << obj.comp << obj.manip << obj.obj->nobility_rank << obj.delim;
    s << '`' << obj.obj->names[49] << '`' << obj.comp << obj.manip << obj.obj->exploit << obj.delim;
    s << '`' << obj.obj->names[50] << '`' << obj.comp << obj.manip << obj.obj->eud_pack_size << obj.delim;
    s << '`' << obj.obj->names[51] << '`' << obj.comp << obj.manip << obj.obj->disableFlag << obj.delim;
    s << '`' << obj.obj->names[52] << '`' << obj.comp << obj.manip << obj.obj->reg_time << obj.delim;
    s << '`' << obj.obj->names[53] << '`' << obj.comp << obj.manip << obj.obj->accu_online_time << obj.delim;
    s << '`' << obj.obj->names[54] << '`' << obj.comp << obj.manip << obj.obj->accu_offline_time << obj.delim;
    s << '`' << obj.obj->names[55] << '`' << obj.comp << obj.manip << obj.obj->last_logout << obj.delim;
    s << '`' << obj.obj->names[56] << '`' << obj.comp << obj.manip << obj.obj->prompt_ver << obj.delim;
    s << '`' << obj.obj->names[57] << '`' << obj.comp << obj.manip << obj.obj->Friend_share << obj.delim;
    s << '`' << obj.obj->names[58] << '`' << obj.comp << obj.manip << obj.obj->Login_time << obj.delim;
    s << '`' << obj.obj->names[59] << '`' << obj.comp << obj.manip << obj.obj->Login_ip << obj.delim;
    s << '`' << obj.obj->names[60] << '`' << obj.comp << obj.manip << obj.obj->soul_value << obj.delim;
    s << '`' << obj.obj->names[61] << '`' << obj.comp << obj.manip << obj.obj->brood_times << obj.delim;
    s << '`' << obj.obj->names[62] << '`' << obj.comp << obj.manip << obj.obj->emoney << obj.delim;
    s << '`' << obj.obj->names[63] << '`' << obj.comp << obj.manip << obj.obj->chk_sum << obj.delim;
    s << '`' << obj.obj->names[64] << '`' << obj.comp << obj.manip << obj.obj->elock << obj.delim;
    s << '`' << obj.obj->names[65] << '`' << obj.comp << obj.manip << obj.obj->ExpBallUsage << obj.delim;
    s << '`' << obj.obj->names[66] << '`' << obj.comp << obj.manip << obj.obj->ExpCrystalUsage << obj.delim;
    s << '`' << obj.obj->names[67] << '`' << obj.comp << obj.manip << obj.obj->cheat_time << obj.delim;
    s << '`' << obj.obj->names[68] << '`' << obj.comp << obj.manip << obj.obj->online_time << obj.delim;
    s << '`' << obj.obj->names[69] << '`' << obj.comp << obj.manip << obj.obj->auto_exercise << obj.delim;
    s << '`' << obj.obj->names[70] << '`' << obj.comp << obj.manip << obj.obj->hung_last_logout << obj.delim;
    s << '`' << obj.obj->names[71] << '`' << obj.comp << obj.manip << obj.obj->god_status << obj.delim;
    s << '`' << obj.obj->names[72] << '`' << obj.comp << obj.manip << obj.obj->big_prize_fails << obj.delim;
    s << '`' << obj.obj->names[73] << '`' << obj.comp << obj.manip << obj.obj->small_prize_fails << obj.delim;
    s << '`' << obj.obj->names[74] << '`' << obj.comp << obj.manip << obj.obj->bonus_points << obj.delim;
    s << '`' << obj.obj->names[75] << '`' << obj.comp << obj.manip << obj.obj->flower << obj.delim;
    s << '`' << obj.obj->names[76] << '`' << obj.comp << obj.manip << obj.obj->flower_w << obj.delim;
    s << '`' << obj.obj->names[77] << '`' << obj.comp << obj.manip << obj.obj->flower_p << obj.delim;
    s << '`' << obj.obj->names[78] << '`' << obj.comp << obj.manip << obj.obj->income << obj.delim;
    s << '`' << obj.obj->names[79] << '`' << obj.comp << obj.manip << obj.obj->illu_ButterFly << obj.delim;
    s << '`' << obj.obj->names[80] << '`' << obj.comp << obj.manip << obj.obj->illu_Fish << obj.delim;
    s << '`' << obj.obj->names[81] << '`' << obj.comp << obj.manip << obj.obj->illu_Shell << obj.delim;
    s << '`' << obj.obj->names[82] << '`' << obj.comp << obj.manip << obj.obj->illu_Herbal << obj.delim;
    s << '`' << obj.obj->names[83] << '`' << obj.comp << obj.manip << obj.obj->illu_Ore << obj.delim;
    s << '`' << obj.obj->names[84] << '`' << obj.comp << obj.manip << obj.obj->password_id << obj.delim;
    s << '`' << obj.obj->names[85] << '`' << obj.comp << obj.manip << obj.obj->quiz_point << obj.delim;
    s << '`' << obj.obj->names[86] << '`' << obj.comp << obj.manip << obj.obj->protect_state << obj.delim;
    s << '`' << obj.obj->names[87] << '`' << obj.comp << obj.manip << obj.obj->donation << obj.delim;
    s << '`' << obj.obj->names[88] << '`' << obj.comp << obj.manip << obj.obj->wood << obj.delim;
    s << '`' << obj.obj->names[89] << '`' << obj.comp << obj.manip << obj.obj->stone << obj.delim;
    s << '`' << obj.obj->names[90] << '`' << obj.comp << obj.manip << obj.obj->todo_list_mask1 << obj.delim;
    s << '`' << obj.obj->names[91] << '`' << obj.comp << obj.manip << obj.obj->todo_list1 << obj.delim;
    s << '`' << obj.obj->names[92] << '`' << obj.comp << obj.manip << obj.obj->todo_list_hex1 << obj.delim;
    s << '`' << obj.obj->names[93] << '`' << obj.comp << obj.manip << obj.obj->coach << obj.delim;
    s << '`' << obj.obj->names[94] << '`' << obj.comp << obj.manip << obj.obj->coach_time << obj.delim;
    s << '`' << obj.obj->names[95] << '`' << obj.comp << obj.manip << obj.obj->coach_deed << obj.delim;
    s << '`' << obj.obj->names[96] << '`' << obj.comp << obj.manip << obj.obj->coach_date << obj.delim;
    s << '`' << obj.obj->names[97] << '`' << obj.comp << obj.manip << obj.obj->extra_hatch_size << obj.delim;
    s << '`' << obj.obj->names[98] << '`' << obj.comp << obj.manip << obj.obj->shadiness_money << obj.delim;
    s << '`' << obj.obj->names[99] << '`' << obj.comp << obj.manip << obj.obj->shadiness_emoney << obj.delim;
    s << '`' << obj.obj->names[100] << '`' << obj.comp << obj.manip << obj.obj->soul_value_lev << obj.delim;
    s << '`' << obj.obj->names[101] << '`' << obj.comp << obj.manip << obj.obj->business << obj.delim;
    s << '`' << obj.obj->names[102] << '`' << obj.comp << obj.manip << obj.obj->emoney2 << obj.delim;
    s << '`' << obj.obj->names[103] << '`' << obj.comp << obj.manip << obj.obj->type << obj.delim;
    s << '`' << obj.obj->names[104] << '`' << obj.comp << obj.manip << obj.obj->god_strength << obj.delim;
    s << '`' << obj.obj->names[105] << '`' << obj.comp << obj.manip << obj.obj->god_level << obj.delim;
    s << '`' << obj.obj->names[106] << '`' << obj.comp << obj.manip << obj.obj->deification << obj.delim;
    s << '`' << obj.obj->names[107] << '`' << obj.comp << obj.manip << obj.obj->tmoney << obj.delim;
    s << '`' << obj.obj->names[108] << '`' << obj.comp << obj.manip << obj.obj->demon_level << obj.delim;
    s << '`' << obj.obj->names[109] << '`' << obj.comp << obj.manip << obj.obj->demon_exp << obj.delim;
    s << '`' << obj.obj->names[110] << '`' << obj.comp << obj.manip << obj.obj->socialclass << obj.delim;
    s << '`' << obj.obj->names[111] << '`' << obj.comp << obj.manip << obj.obj->credit_point << obj.delim;
    s << '`' << obj.obj->names[112] << '`' << obj.comp << obj.manip << obj.obj->credit_limit << obj.delim;
    s << '`' << obj.obj->names[113] << '`' << obj.comp << obj.manip << obj.obj->credit_return << obj.delim;
    s << '`' << obj.obj->names[114] << '`' << obj.comp << obj.manip << obj.obj->eudkernel_id << obj.delim;
    s << '`' << obj.obj->names[115] << '`' << obj.comp << obj.manip << obj.obj->refinery_time_end << obj.delim;
    s << '`' << obj.obj->names[116] << '`' << obj.comp << obj.manip << obj.obj->pack_add << obj.delim;
    s << '`' << obj.obj->names[117] << '`' << obj.comp << obj.manip << obj.obj->boundary_lev << obj.delim;
    s << '`' << obj.obj->names[118] << '`' << obj.comp << obj.manip << obj.obj->boundary_exp << obj.delim;
    s << '`' << obj.obj->names[119] << '`' << obj.comp << obj.manip << obj.obj->offer_point << obj.delim;
    s << '`' << obj.obj->names[120] << '`' << obj.comp << obj.manip << obj.obj->battle_lev << obj.delim;
    s << '`' << obj.obj->names[121] << '`' << obj.comp << obj.manip << obj.obj->channel_account << obj.delim;
    s << '`' << obj.obj->names[122] << '`' << obj.comp << obj.manip << obj.obj->recharge_emoney << obj.delim;
    s << '`' << obj.obj->names[123] << '`' << obj.comp << obj.manip << obj.obj->auto_battle_time << obj.delim;
    s << '`' << obj.obj->names[124] << '`' << obj.comp << obj.manip << obj.obj->first_recharge << obj.delim;
    s << '`' << obj.obj->names[125] << '`' << obj.comp << obj.manip << obj.obj->special_flag << obj.delim;
    s << '`' << obj.obj->names[126] << '`' << obj.comp << obj.manip << obj.obj->vip_lev << obj.delim;
    s << '`' << obj.obj->names[127] << '`' << obj.comp << obj.manip << obj.obj->ghosttoexp_amount << obj.delim;
    s << '`' << obj.obj->names[128] << '`' << obj.comp << obj.manip << obj.obj->vigor << obj.delim;
    s << '`' << obj.obj->names[129] << '`' << obj.comp << obj.manip << obj.obj->func_list;
        return s;
    }

    template <class Manip>
    std::ostream& operator <<(std::ostream& s, const CUserData_cus_value_list<Manip>& obj)
    {
        bool before = false;
    s << obj.manip << obj.obj->name << obj.delim;
    s << obj.manip << obj.obj->mate << obj.delim;
    s << obj.manip << obj.obj->lookface << obj.delim;
    s << obj.manip << obj.obj->hair << obj.delim;
    s << obj.manip << obj.obj->length << obj.delim;
    s << obj.manip << obj.obj->fat << obj.delim;
    s << obj.manip << obj.obj->money << obj.delim;
    s << obj.manip << obj.obj->money_saved << obj.delim;
    s << obj.manip << obj.obj->task_data << obj.delim;
    s << obj.manip << obj.obj->level << obj.delim;
    s << obj.manip << obj.obj->exp << obj.delim;
    s << obj.manip << obj.obj->power << obj.delim;
    s << obj.manip << obj.obj->constitution << obj.delim;
    s << obj.manip << obj.obj->dexterity << obj.delim;
    s << obj.manip << obj.obj->Speed << obj.delim;
    s << obj.manip << obj.obj->health << obj.delim;
    s << obj.manip << obj.obj->soul << obj.delim;
    s << obj.manip << obj.obj->additional_point << obj.delim;
    s << obj.manip << obj.obj->auto_allot << obj.delim;
    s << obj.manip << obj.obj->life << obj.delim;
    s << obj.manip << obj.obj->mana << obj.delim;
    s << obj.manip << obj.obj->profession << obj.delim;
    s << obj.manip << obj.obj->potential << obj.delim;
    s << obj.manip << obj.obj->pk << obj.delim;
    s << obj.manip << obj.obj->nobility << obj.delim;
    s << obj.manip << obj.obj->medal << obj.delim;
    s << obj.manip << obj.obj->medal_select << obj.delim;
    s << obj.manip << obj.obj->metempsychosis << obj.delim;
    s << obj.manip << obj.obj->syndicate_id << obj.delim;
    s << obj.manip << obj.obj->recordmap_id << obj.delim;
    s << obj.manip << obj.obj->recordx << obj.delim;
    s << obj.manip << obj.obj->recordy << obj.delim;
    s << obj.manip << obj.obj->account_id << obj.delim;
    s << obj.manip << obj.obj->id << obj.delim;
    s << obj.manip << obj.obj->last_login << obj.delim;
    s << obj.manip << obj.obj->account << obj.delim;
    s << obj.manip << obj.obj->password << obj.delim;
    s << obj.manip << obj.obj->task_mask << obj.delim;
    s << obj.manip << obj.obj->time_of_life << obj.delim;
    s << obj.manip << obj.obj->virtue << obj.delim;
    s << obj.manip << obj.obj->home_id << obj.delim;
    s << obj.manip << obj.obj->title << obj.delim;
    s << obj.manip << obj.obj->title_select << obj.delim;
    s << obj.manip << obj.obj->tutor_exp << obj.delim;
    s << obj.manip << obj.obj->tutor_level << obj.delim;
    s << obj.manip << obj.obj->maxlife_percent << obj.delim;
    s << obj.manip << obj.obj->mercenary_rank << obj.delim;
    s << obj.manip << obj.obj->mercenary_exp << obj.delim;
    s << obj.manip << obj.obj->nobility_rank << obj.delim;
    s << obj.manip << obj.obj->exploit << obj.delim;
    s << obj.manip << obj.obj->eud_pack_size << obj.delim;
    s << obj.manip << obj.obj->disableFlag << obj.delim;
    s << obj.manip << obj.obj->reg_time << obj.delim;
    s << obj.manip << obj.obj->accu_online_time << obj.delim;
    s << obj.manip << obj.obj->accu_offline_time << obj.delim;
    s << obj.manip << obj.obj->last_logout << obj.delim;
    s << obj.manip << obj.obj->prompt_ver << obj.delim;
    s << obj.manip << obj.obj->Friend_share << obj.delim;
    s << obj.manip << obj.obj->Login_time << obj.delim;
    s << obj.manip << obj.obj->Login_ip << obj.delim;
    s << obj.manip << obj.obj->soul_value << obj.delim;
    s << obj.manip << obj.obj->brood_times << obj.delim;
    s << obj.manip << obj.obj->emoney << obj.delim;
    s << obj.manip << obj.obj->chk_sum << obj.delim;
    s << obj.manip << obj.obj->elock << obj.delim;
    s << obj.manip << obj.obj->ExpBallUsage << obj.delim;
    s << obj.manip << obj.obj->ExpCrystalUsage << obj.delim;
    s << obj.manip << obj.obj->cheat_time << obj.delim;
    s << obj.manip << obj.obj->online_time << obj.delim;
    s << obj.manip << obj.obj->auto_exercise << obj.delim;
    s << obj.manip << obj.obj->hung_last_logout << obj.delim;
    s << obj.manip << obj.obj->god_status << obj.delim;
    s << obj.manip << obj.obj->big_prize_fails << obj.delim;
    s << obj.manip << obj.obj->small_prize_fails << obj.delim;
    s << obj.manip << obj.obj->bonus_points << obj.delim;
    s << obj.manip << obj.obj->flower << obj.delim;
    s << obj.manip << obj.obj->flower_w << obj.delim;
    s << obj.manip << obj.obj->flower_p << obj.delim;
    s << obj.manip << obj.obj->income << obj.delim;
    s << obj.manip << obj.obj->illu_ButterFly << obj.delim;
    s << obj.manip << obj.obj->illu_Fish << obj.delim;
    s << obj.manip << obj.obj->illu_Shell << obj.delim;
    s << obj.manip << obj.obj->illu_Herbal << obj.delim;
    s << obj.manip << obj.obj->illu_Ore << obj.delim;
    s << obj.manip << obj.obj->password_id << obj.delim;
    s << obj.manip << obj.obj->quiz_point << obj.delim;
    s << obj.manip << obj.obj->protect_state << obj.delim;
    s << obj.manip << obj.obj->donation << obj.delim;
    s << obj.manip << obj.obj->wood << obj.delim;
    s << obj.manip << obj.obj->stone << obj.delim;
    s << obj.manip << obj.obj->todo_list_mask1 << obj.delim;
    s << obj.manip << obj.obj->todo_list1 << obj.delim;
    s << obj.manip << obj.obj->todo_list_hex1 << obj.delim;
    s << obj.manip << obj.obj->coach << obj.delim;
    s << obj.manip << obj.obj->coach_time << obj.delim;
    s << obj.manip << obj.obj->coach_deed << obj.delim;
    s << obj.manip << obj.obj->coach_date << obj.delim;
    s << obj.manip << obj.obj->extra_hatch_size << obj.delim;
    s << obj.manip << obj.obj->shadiness_money << obj.delim;
    s << obj.manip << obj.obj->shadiness_emoney << obj.delim;
    s << obj.manip << obj.obj->soul_value_lev << obj.delim;
    s << obj.manip << obj.obj->business << obj.delim;
    s << obj.manip << obj.obj->emoney2 << obj.delim;
    s << obj.manip << obj.obj->type << obj.delim;
    s << obj.manip << obj.obj->god_strength << obj.delim;
    s << obj.manip << obj.obj->god_level << obj.delim;
    s << obj.manip << obj.obj->deification << obj.delim;
    s << obj.manip << obj.obj->tmoney << obj.delim;
    s << obj.manip << obj.obj->demon_level << obj.delim;
    s << obj.manip << obj.obj->demon_exp << obj.delim;
    s << obj.manip << obj.obj->socialclass << obj.delim;
    s << obj.manip << obj.obj->credit_point << obj.delim;
    s << obj.manip << obj.obj->credit_limit << obj.delim;
    s << obj.manip << obj.obj->credit_return << obj.delim;
    s << obj.manip << obj.obj->eudkernel_id << obj.delim;
    s << obj.manip << obj.obj->refinery_time_end << obj.delim;
    s << obj.manip << obj.obj->pack_add << obj.delim;
    s << obj.manip << obj.obj->boundary_lev << obj.delim;
    s << obj.manip << obj.obj->boundary_exp << obj.delim;
    s << obj.manip << obj.obj->offer_point << obj.delim;
    s << obj.manip << obj.obj->battle_lev << obj.delim;
    s << obj.manip << obj.obj->channel_account << obj.delim;
    s << obj.manip << obj.obj->recharge_emoney << obj.delim;
    s << obj.manip << obj.obj->auto_battle_time << obj.delim;
    s << obj.manip << obj.obj->first_recharge << obj.delim;
    s << obj.manip << obj.obj->special_flag << obj.delim;
    s << obj.manip << obj.obj->vip_lev << obj.delim;
    s << obj.manip << obj.obj->ghosttoexp_amount << obj.delim;
    s << obj.manip << obj.obj->vigor << obj.delim;
    s << obj.manip << obj.obj->func_list_cus
        return s;
    }

    template <class Manip>
    std::ostream& operator <<(std::ostream& s, const CUserData_cus_field_list<Manip>& obj)
    {
        bool before = false;
    if ((*obj.include)[0]) { 
      s << obj.manip << '`' << obj.obj->names[0] << '`';
      before = true; 
     } 
    if ((*obj.include)[1]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[1] << '`';
      before = true; 
     } 
    if ((*obj.include)[2]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[2] << '`';
      before = true; 
     } 
    if ((*obj.include)[3]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[3] << '`';
      before = true; 
     } 
    if ((*obj.include)[4]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[4] << '`';
      before = true; 
     } 
    if ((*obj.include)[5]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[5] << '`';
      before = true; 
     } 
    if ((*obj.include)[6]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[6] << '`';
      before = true; 
     } 
    if ((*obj.include)[7]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[7] << '`';
      before = true; 
     } 
    if ((*obj.include)[8]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[8] << '`';
      before = true; 
     } 
    if ((*obj.include)[9]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[9] << '`';
      before = true; 
     } 
    if ((*obj.include)[10]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[10] << '`';
      before = true; 
     } 
    if ((*obj.include)[11]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[11] << '`';
      before = true; 
     } 
    if ((*obj.include)[12]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[12] << '`';
      before = true; 
     } 
    if ((*obj.include)[13]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[13] << '`';
      before = true; 
     } 
    if ((*obj.include)[14]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[14] << '`';
      before = true; 
     } 
    if ((*obj.include)[15]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[15] << '`';
      before = true; 
     } 
    if ((*obj.include)[16]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[16] << '`';
      before = true; 
     } 
    if ((*obj.include)[17]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[17] << '`';
      before = true; 
     } 
    if ((*obj.include)[18]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[18] << '`';
      before = true; 
     } 
    if ((*obj.include)[19]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[19] << '`';
      before = true; 
     } 
    if ((*obj.include)[20]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[20] << '`';
      before = true; 
     } 
    if ((*obj.include)[21]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[21] << '`';
      before = true; 
     } 
    if ((*obj.include)[22]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[22] << '`';
      before = true; 
     } 
    if ((*obj.include)[23]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[23] << '`';
      before = true; 
     } 
    if ((*obj.include)[24]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[24] << '`';
      before = true; 
     } 
    if ((*obj.include)[25]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[25] << '`';
      before = true; 
     } 
    if ((*obj.include)[26]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[26] << '`';
      before = true; 
     } 
    if ((*obj.include)[27]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[27] << '`';
      before = true; 
     } 
    if ((*obj.include)[28]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[28] << '`';
      before = true; 
     } 
    if ((*obj.include)[29]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[29] << '`';
      before = true; 
     } 
    if ((*obj.include)[30]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[30] << '`';
      before = true; 
     } 
    if ((*obj.include)[31]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[31] << '`';
      before = true; 
     } 
    if ((*obj.include)[32]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[32] << '`';
      before = true; 
     } 
    if ((*obj.include)[33]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[33] << '`';
      before = true; 
     } 
    if ((*obj.include)[34]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[34] << '`';
      before = true; 
     } 
    if ((*obj.include)[35]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[35] << '`';
      before = true; 
     } 
    if ((*obj.include)[36]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[36] << '`';
      before = true; 
     } 
    if ((*obj.include)[37]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[37] << '`';
      before = true; 
     } 
    if ((*obj.include)[38]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[38] << '`';
      before = true; 
     } 
    if ((*obj.include)[39]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[39] << '`';
      before = true; 
     } 
    if ((*obj.include)[40]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[40] << '`';
      before = true; 
     } 
    if ((*obj.include)[41]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[41] << '`';
      before = true; 
     } 
    if ((*obj.include)[42]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[42] << '`';
      before = true; 
     } 
    if ((*obj.include)[43]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[43] << '`';
      before = true; 
     } 
    if ((*obj.include)[44]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[44] << '`';
      before = true; 
     } 
    if ((*obj.include)[45]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[45] << '`';
      before = true; 
     } 
    if ((*obj.include)[46]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[46] << '`';
      before = true; 
     } 
    if ((*obj.include)[47]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[47] << '`';
      before = true; 
     } 
    if ((*obj.include)[48]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[48] << '`';
      before = true; 
     } 
    if ((*obj.include)[49]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[49] << '`';
      before = true; 
     } 
    if ((*obj.include)[50]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[50] << '`';
      before = true; 
     } 
    if ((*obj.include)[51]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[51] << '`';
      before = true; 
     } 
    if ((*obj.include)[52]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[52] << '`';
      before = true; 
     } 
    if ((*obj.include)[53]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[53] << '`';
      before = true; 
     } 
    if ((*obj.include)[54]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[54] << '`';
      before = true; 
     } 
    if ((*obj.include)[55]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[55] << '`';
      before = true; 
     } 
    if ((*obj.include)[56]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[56] << '`';
      before = true; 
     } 
    if ((*obj.include)[57]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[57] << '`';
      before = true; 
     } 
    if ((*obj.include)[58]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[58] << '`';
      before = true; 
     } 
    if ((*obj.include)[59]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[59] << '`';
      before = true; 
     } 
    if ((*obj.include)[60]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[60] << '`';
      before = true; 
     } 
    if ((*obj.include)[61]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[61] << '`';
      before = true; 
     } 
    if ((*obj.include)[62]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[62] << '`';
      before = true; 
     } 
    if ((*obj.include)[63]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[63] << '`';
      before = true; 
     } 
    if ((*obj.include)[64]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[64] << '`';
      before = true; 
     } 
    if ((*obj.include)[65]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[65] << '`';
      before = true; 
     } 
    if ((*obj.include)[66]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[66] << '`';
      before = true; 
     } 
    if ((*obj.include)[67]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[67] << '`';
      before = true; 
     } 
    if ((*obj.include)[68]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[68] << '`';
      before = true; 
     } 
    if ((*obj.include)[69]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[69] << '`';
      before = true; 
     } 
    if ((*obj.include)[70]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[70] << '`';
      before = true; 
     } 
    if ((*obj.include)[71]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[71] << '`';
      before = true; 
     } 
    if ((*obj.include)[72]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[72] << '`';
      before = true; 
     } 
    if ((*obj.include)[73]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[73] << '`';
      before = true; 
     } 
    if ((*obj.include)[74]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[74] << '`';
      before = true; 
     } 
    if ((*obj.include)[75]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[75] << '`';
      before = true; 
     } 
    if ((*obj.include)[76]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[76] << '`';
      before = true; 
     } 
    if ((*obj.include)[77]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[77] << '`';
      before = true; 
     } 
    if ((*obj.include)[78]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[78] << '`';
      before = true; 
     } 
    if ((*obj.include)[79]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[79] << '`';
      before = true; 
     } 
    if ((*obj.include)[80]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[80] << '`';
      before = true; 
     } 
    if ((*obj.include)[81]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[81] << '`';
      before = true; 
     } 
    if ((*obj.include)[82]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[82] << '`';
      before = true; 
     } 
    if ((*obj.include)[83]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[83] << '`';
      before = true; 
     } 
    if ((*obj.include)[84]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[84] << '`';
      before = true; 
     } 
    if ((*obj.include)[85]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[85] << '`';
      before = true; 
     } 
    if ((*obj.include)[86]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[86] << '`';
      before = true; 
     } 
    if ((*obj.include)[87]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[87] << '`';
      before = true; 
     } 
    if ((*obj.include)[88]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[88] << '`';
      before = true; 
     } 
    if ((*obj.include)[89]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[89] << '`';
      before = true; 
     } 
    if ((*obj.include)[90]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[90] << '`';
      before = true; 
     } 
    if ((*obj.include)[91]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[91] << '`';
      before = true; 
     } 
    if ((*obj.include)[92]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[92] << '`';
      before = true; 
     } 
    if ((*obj.include)[93]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[93] << '`';
      before = true; 
     } 
    if ((*obj.include)[94]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[94] << '`';
      before = true; 
     } 
    if ((*obj.include)[95]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[95] << '`';
      before = true; 
     } 
    if ((*obj.include)[96]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[96] << '`';
      before = true; 
     } 
    if ((*obj.include)[97]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[97] << '`';
      before = true; 
     } 
    if ((*obj.include)[98]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[98] << '`';
      before = true; 
     } 
    if ((*obj.include)[99]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[99] << '`';
      before = true; 
     } 
    if ((*obj.include)[100]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[100] << '`';
      before = true; 
     } 
    if ((*obj.include)[101]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[101] << '`';
      before = true; 
     } 
    if ((*obj.include)[102]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[102] << '`';
      before = true; 
     } 
    if ((*obj.include)[103]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[103] << '`';
      before = true; 
     } 
    if ((*obj.include)[104]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[104] << '`';
      before = true; 
     } 
    if ((*obj.include)[105]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[105] << '`';
      before = true; 
     } 
    if ((*obj.include)[106]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[106] << '`';
      before = true; 
     } 
    if ((*obj.include)[107]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[107] << '`';
      before = true; 
     } 
    if ((*obj.include)[108]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[108] << '`';
      before = true; 
     } 
    if ((*obj.include)[109]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[109] << '`';
      before = true; 
     } 
    if ((*obj.include)[110]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[110] << '`';
      before = true; 
     } 
    if ((*obj.include)[111]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[111] << '`';
      before = true; 
     } 
    if ((*obj.include)[112]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[112] << '`';
      before = true; 
     } 
    if ((*obj.include)[113]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[113] << '`';
      before = true; 
     } 
    if ((*obj.include)[114]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[114] << '`';
      before = true; 
     } 
    if ((*obj.include)[115]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[115] << '`';
      before = true; 
     } 
    if ((*obj.include)[116]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[116] << '`';
      before = true; 
     } 
    if ((*obj.include)[117]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[117] << '`';
      before = true; 
     } 
    if ((*obj.include)[118]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[118] << '`';
      before = true; 
     } 
    if ((*obj.include)[119]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[119] << '`';
      before = true; 
     } 
    if ((*obj.include)[120]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[120] << '`';
      before = true; 
     } 
    if ((*obj.include)[121]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[121] << '`';
      before = true; 
     } 
    if ((*obj.include)[122]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[122] << '`';
      before = true; 
     } 
    if ((*obj.include)[123]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[123] << '`';
      before = true; 
     } 
    if ((*obj.include)[124]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[124] << '`';
      before = true; 
     } 
    if ((*obj.include)[125]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[125] << '`';
      before = true; 
     } 
    if ((*obj.include)[126]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[126] << '`';
      before = true; 
     } 
    if ((*obj.include)[127]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[127] << '`';
      before = true; 
     } 
    if ((*obj.include)[128]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[128] << '`';
      before = true; 
     } 
    if ((*obj.include)[129]) { 
      if (before) s << obj.delim;
      s << obj.manip << '`' << obj.obj->names[129] << '`';
     } 

        return s;
    }

    template <class Manip>
    std::ostream& operator <<(std::ostream& s, const CUserData_cus_equal_list<Manip>& obj)
    {
        bool before = false;
    if ((*obj.include)[0]) { 
      s << '`' << obj.obj->names[0] << '`' << obj.comp         << obj.manip << obj.obj->name;
      before = true; 
     } 
    if ((*obj.include)[1]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[1] << '`' << obj.comp         << obj.manip << obj.obj->mate;
      before = true; 
     } 
    if ((*obj.include)[2]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[2] << '`' << obj.comp         << obj.manip << obj.obj->lookface;
      before = true; 
     } 
    if ((*obj.include)[3]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[3] << '`' << obj.comp         << obj.manip << obj.obj->hair;
      before = true; 
     } 
    if ((*obj.include)[4]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[4] << '`' << obj.comp         << obj.manip << obj.obj->length;
      before = true; 
     } 
    if ((*obj.include)[5]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[5] << '`' << obj.comp         << obj.manip << obj.obj->fat;
      before = true; 
     } 
    if ((*obj.include)[6]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[6] << '`' << obj.comp         << obj.manip << obj.obj->money;
      before = true; 
     } 
    if ((*obj.include)[7]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[7] << '`' << obj.comp         << obj.manip << obj.obj->money_saved;
      before = true; 
     } 
    if ((*obj.include)[8]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[8] << '`' << obj.comp         << obj.manip << obj.obj->task_data;
      before = true; 
     } 
    if ((*obj.include)[9]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[9] << '`' << obj.comp         << obj.manip << obj.obj->level;
      before = true; 
     } 
    if ((*obj.include)[10]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[10] << '`' << obj.comp         << obj.manip << obj.obj->exp;
      before = true; 
     } 
    if ((*obj.include)[11]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[11] << '`' << obj.comp         << obj.manip << obj.obj->power;
      before = true; 
     } 
    if ((*obj.include)[12]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[12] << '`' << obj.comp         << obj.manip << obj.obj->constitution;
      before = true; 
     } 
    if ((*obj.include)[13]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[13] << '`' << obj.comp         << obj.manip << obj.obj->dexterity;
      before = true; 
     } 
    if ((*obj.include)[14]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[14] << '`' << obj.comp         << obj.manip << obj.obj->Speed;
      before = true; 
     } 
    if ((*obj.include)[15]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[15] << '`' << obj.comp         << obj.manip << obj.obj->health;
      before = true; 
     } 
    if ((*obj.include)[16]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[16] << '`' << obj.comp         << obj.manip << obj.obj->soul;
      before = true; 
     } 
    if ((*obj.include)[17]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[17] << '`' << obj.comp         << obj.manip << obj.obj->additional_point;
      before = true; 
     } 
    if ((*obj.include)[18]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[18] << '`' << obj.comp         << obj.manip << obj.obj->auto_allot;
      before = true; 
     } 
    if ((*obj.include)[19]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[19] << '`' << obj.comp         << obj.manip << obj.obj->life;
      before = true; 
     } 
    if ((*obj.include)[20]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[20] << '`' << obj.comp         << obj.manip << obj.obj->mana;
      before = true; 
     } 
    if ((*obj.include)[21]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[21] << '`' << obj.comp         << obj.manip << obj.obj->profession;
      before = true; 
     } 
    if ((*obj.include)[22]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[22] << '`' << obj.comp         << obj.manip << obj.obj->potential;
      before = true; 
     } 
    if ((*obj.include)[23]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[23] << '`' << obj.comp         << obj.manip << obj.obj->pk;
      before = true; 
     } 
    if ((*obj.include)[24]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[24] << '`' << obj.comp         << obj.manip << obj.obj->nobility;
      before = true; 
     } 
    if ((*obj.include)[25]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[25] << '`' << obj.comp         << obj.manip << obj.obj->medal;
      before = true; 
     } 
    if ((*obj.include)[26]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[26] << '`' << obj.comp         << obj.manip << obj.obj->medal_select;
      before = true; 
     } 
    if ((*obj.include)[27]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[27] << '`' << obj.comp         << obj.manip << obj.obj->metempsychosis;
      before = true; 
     } 
    if ((*obj.include)[28]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[28] << '`' << obj.comp         << obj.manip << obj.obj->syndicate_id;
      before = true; 
     } 
    if ((*obj.include)[29]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[29] << '`' << obj.comp         << obj.manip << obj.obj->recordmap_id;
      before = true; 
     } 
    if ((*obj.include)[30]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[30] << '`' << obj.comp         << obj.manip << obj.obj->recordx;
      before = true; 
     } 
    if ((*obj.include)[31]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[31] << '`' << obj.comp         << obj.manip << obj.obj->recordy;
      before = true; 
     } 
    if ((*obj.include)[32]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[32] << '`' << obj.comp         << obj.manip << obj.obj->account_id;
      before = true; 
     } 
    if ((*obj.include)[33]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[33] << '`' << obj.comp         << obj.manip << obj.obj->id;
      before = true; 
     } 
    if ((*obj.include)[34]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[34] << '`' << obj.comp         << obj.manip << obj.obj->last_login;
      before = true; 
     } 
    if ((*obj.include)[35]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[35] << '`' << obj.comp         << obj.manip << obj.obj->account;
      before = true; 
     } 
    if ((*obj.include)[36]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[36] << '`' << obj.comp         << obj.manip << obj.obj->password;
      before = true; 
     } 
    if ((*obj.include)[37]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[37] << '`' << obj.comp         << obj.manip << obj.obj->task_mask;
      before = true; 
     } 
    if ((*obj.include)[38]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[38] << '`' << obj.comp         << obj.manip << obj.obj->time_of_life;
      before = true; 
     } 
    if ((*obj.include)[39]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[39] << '`' << obj.comp         << obj.manip << obj.obj->virtue;
      before = true; 
     } 
    if ((*obj.include)[40]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[40] << '`' << obj.comp         << obj.manip << obj.obj->home_id;
      before = true; 
     } 
    if ((*obj.include)[41]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[41] << '`' << obj.comp         << obj.manip << obj.obj->title;
      before = true; 
     } 
    if ((*obj.include)[42]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[42] << '`' << obj.comp         << obj.manip << obj.obj->title_select;
      before = true; 
     } 
    if ((*obj.include)[43]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[43] << '`' << obj.comp         << obj.manip << obj.obj->tutor_exp;
      before = true; 
     } 
    if ((*obj.include)[44]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[44] << '`' << obj.comp         << obj.manip << obj.obj->tutor_level;
      before = true; 
     } 
    if ((*obj.include)[45]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[45] << '`' << obj.comp         << obj.manip << obj.obj->maxlife_percent;
      before = true; 
     } 
    if ((*obj.include)[46]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[46] << '`' << obj.comp         << obj.manip << obj.obj->mercenary_rank;
      before = true; 
     } 
    if ((*obj.include)[47]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[47] << '`' << obj.comp         << obj.manip << obj.obj->mercenary_exp;
      before = true; 
     } 
    if ((*obj.include)[48]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[48] << '`' << obj.comp         << obj.manip << obj.obj->nobility_rank;
      before = true; 
     } 
    if ((*obj.include)[49]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[49] << '`' << obj.comp         << obj.manip << obj.obj->exploit;
      before = true; 
     } 
    if ((*obj.include)[50]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[50] << '`' << obj.comp         << obj.manip << obj.obj->eud_pack_size;
      before = true; 
     } 
    if ((*obj.include)[51]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[51] << '`' << obj.comp         << obj.manip << obj.obj->disableFlag;
      before = true; 
     } 
    if ((*obj.include)[52]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[52] << '`' << obj.comp         << obj.manip << obj.obj->reg_time;
      before = true; 
     } 
    if ((*obj.include)[53]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[53] << '`' << obj.comp         << obj.manip << obj.obj->accu_online_time;
      before = true; 
     } 
    if ((*obj.include)[54]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[54] << '`' << obj.comp         << obj.manip << obj.obj->accu_offline_time;
      before = true; 
     } 
    if ((*obj.include)[55]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[55] << '`' << obj.comp         << obj.manip << obj.obj->last_logout;
      before = true; 
     } 
    if ((*obj.include)[56]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[56] << '`' << obj.comp         << obj.manip << obj.obj->prompt_ver;
      before = true; 
     } 
    if ((*obj.include)[57]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[57] << '`' << obj.comp         << obj.manip << obj.obj->Friend_share;
      before = true; 
     } 
    if ((*obj.include)[58]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[58] << '`' << obj.comp         << obj.manip << obj.obj->Login_time;
      before = true; 
     } 
    if ((*obj.include)[59]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[59] << '`' << obj.comp         << obj.manip << obj.obj->Login_ip;
      before = true; 
     } 
    if ((*obj.include)[60]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[60] << '`' << obj.comp         << obj.manip << obj.obj->soul_value;
      before = true; 
     } 
    if ((*obj.include)[61]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[61] << '`' << obj.comp         << obj.manip << obj.obj->brood_times;
      before = true; 
     } 
    if ((*obj.include)[62]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[62] << '`' << obj.comp         << obj.manip << obj.obj->emoney;
      before = true; 
     } 
    if ((*obj.include)[63]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[63] << '`' << obj.comp         << obj.manip << obj.obj->chk_sum;
      before = true; 
     } 
    if ((*obj.include)[64]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[64] << '`' << obj.comp         << obj.manip << obj.obj->elock;
      before = true; 
     } 
    if ((*obj.include)[65]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[65] << '`' << obj.comp         << obj.manip << obj.obj->ExpBallUsage;
      before = true; 
     } 
    if ((*obj.include)[66]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[66] << '`' << obj.comp         << obj.manip << obj.obj->ExpCrystalUsage;
      before = true; 
     } 
    if ((*obj.include)[67]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[67] << '`' << obj.comp         << obj.manip << obj.obj->cheat_time;
      before = true; 
     } 
    if ((*obj.include)[68]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[68] << '`' << obj.comp         << obj.manip << obj.obj->online_time;
      before = true; 
     } 
    if ((*obj.include)[69]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[69] << '`' << obj.comp         << obj.manip << obj.obj->auto_exercise;
      before = true; 
     } 
    if ((*obj.include)[70]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[70] << '`' << obj.comp         << obj.manip << obj.obj->hung_last_logout;
      before = true; 
     } 
    if ((*obj.include)[71]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[71] << '`' << obj.comp         << obj.manip << obj.obj->god_status;
      before = true; 
     } 
    if ((*obj.include)[72]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[72] << '`' << obj.comp         << obj.manip << obj.obj->big_prize_fails;
      before = true; 
     } 
    if ((*obj.include)[73]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[73] << '`' << obj.comp         << obj.manip << obj.obj->small_prize_fails;
      before = true; 
     } 
    if ((*obj.include)[74]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[74] << '`' << obj.comp         << obj.manip << obj.obj->bonus_points;
      before = true; 
     } 
    if ((*obj.include)[75]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[75] << '`' << obj.comp         << obj.manip << obj.obj->flower;
      before = true; 
     } 
    if ((*obj.include)[76]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[76] << '`' << obj.comp         << obj.manip << obj.obj->flower_w;
      before = true; 
     } 
    if ((*obj.include)[77]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[77] << '`' << obj.comp         << obj.manip << obj.obj->flower_p;
      before = true; 
     } 
    if ((*obj.include)[78]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[78] << '`' << obj.comp         << obj.manip << obj.obj->income;
      before = true; 
     } 
    if ((*obj.include)[79]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[79] << '`' << obj.comp         << obj.manip << obj.obj->illu_ButterFly;
      before = true; 
     } 
    if ((*obj.include)[80]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[80] << '`' << obj.comp         << obj.manip << obj.obj->illu_Fish;
      before = true; 
     } 
    if ((*obj.include)[81]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[81] << '`' << obj.comp         << obj.manip << obj.obj->illu_Shell;
      before = true; 
     } 
    if ((*obj.include)[82]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[82] << '`' << obj.comp         << obj.manip << obj.obj->illu_Herbal;
      before = true; 
     } 
    if ((*obj.include)[83]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[83] << '`' << obj.comp         << obj.manip << obj.obj->illu_Ore;
      before = true; 
     } 
    if ((*obj.include)[84]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[84] << '`' << obj.comp         << obj.manip << obj.obj->password_id;
      before = true; 
     } 
    if ((*obj.include)[85]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[85] << '`' << obj.comp         << obj.manip << obj.obj->quiz_point;
      before = true; 
     } 
    if ((*obj.include)[86]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[86] << '`' << obj.comp         << obj.manip << obj.obj->protect_state;
      before = true; 
     } 
    if ((*obj.include)[87]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[87] << '`' << obj.comp         << obj.manip << obj.obj->donation;
      before = true; 
     } 
    if ((*obj.include)[88]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[88] << '`' << obj.comp         << obj.manip << obj.obj->wood;
      before = true; 
     } 
    if ((*obj.include)[89]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[89] << '`' << obj.comp         << obj.manip << obj.obj->stone;
      before = true; 
     } 
    if ((*obj.include)[90]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[90] << '`' << obj.comp         << obj.manip << obj.obj->todo_list_mask1;
      before = true; 
     } 
    if ((*obj.include)[91]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[91] << '`' << obj.comp         << obj.manip << obj.obj->todo_list1;
      before = true; 
     } 
    if ((*obj.include)[92]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[92] << '`' << obj.comp         << obj.manip << obj.obj->todo_list_hex1;
      before = true; 
     } 
    if ((*obj.include)[93]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[93] << '`' << obj.comp         << obj.manip << obj.obj->coach;
      before = true; 
     } 
    if ((*obj.include)[94]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[94] << '`' << obj.comp         << obj.manip << obj.obj->coach_time;
      before = true; 
     } 
    if ((*obj.include)[95]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[95] << '`' << obj.comp         << obj.manip << obj.obj->coach_deed;
      before = true; 
     } 
    if ((*obj.include)[96]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[96] << '`' << obj.comp         << obj.manip << obj.obj->coach_date;
      before = true; 
     } 
    if ((*obj.include)[97]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[97] << '`' << obj.comp         << obj.manip << obj.obj->extra_hatch_size;
      before = true; 
     } 
    if ((*obj.include)[98]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[98] << '`' << obj.comp         << obj.manip << obj.obj->shadiness_money;
      before = true; 
     } 
    if ((*obj.include)[99]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[99] << '`' << obj.comp         << obj.manip << obj.obj->shadiness_emoney;
      before = true; 
     } 
    if ((*obj.include)[100]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[100] << '`' << obj.comp         << obj.manip << obj.obj->soul_value_lev;
      before = true; 
     } 
    if ((*obj.include)[101]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[101] << '`' << obj.comp         << obj.manip << obj.obj->business;
      before = true; 
     } 
    if ((*obj.include)[102]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[102] << '`' << obj.comp         << obj.manip << obj.obj->emoney2;
      before = true; 
     } 
    if ((*obj.include)[103]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[103] << '`' << obj.comp         << obj.manip << obj.obj->type;
      before = true; 
     } 
    if ((*obj.include)[104]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[104] << '`' << obj.comp         << obj.manip << obj.obj->god_strength;
      before = true; 
     } 
    if ((*obj.include)[105]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[105] << '`' << obj.comp         << obj.manip << obj.obj->god_level;
      before = true; 
     } 
    if ((*obj.include)[106]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[106] << '`' << obj.comp         << obj.manip << obj.obj->deification;
      before = true; 
     } 
    if ((*obj.include)[107]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[107] << '`' << obj.comp         << obj.manip << obj.obj->tmoney;
      before = true; 
     } 
    if ((*obj.include)[108]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[108] << '`' << obj.comp         << obj.manip << obj.obj->demon_level;
      before = true; 
     } 
    if ((*obj.include)[109]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[109] << '`' << obj.comp         << obj.manip << obj.obj->demon_exp;
      before = true; 
     } 
    if ((*obj.include)[110]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[110] << '`' << obj.comp         << obj.manip << obj.obj->socialclass;
      before = true; 
     } 
    if ((*obj.include)[111]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[111] << '`' << obj.comp         << obj.manip << obj.obj->credit_point;
      before = true; 
     } 
    if ((*obj.include)[112]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[112] << '`' << obj.comp         << obj.manip << obj.obj->credit_limit;
      before = true; 
     } 
    if ((*obj.include)[113]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[113] << '`' << obj.comp         << obj.manip << obj.obj->credit_return;
      before = true; 
     } 
    if ((*obj.include)[114]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[114] << '`' << obj.comp         << obj.manip << obj.obj->eudkernel_id;
      before = true; 
     } 
    if ((*obj.include)[115]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[115] << '`' << obj.comp         << obj.manip << obj.obj->refinery_time_end;
      before = true; 
     } 
    if ((*obj.include)[116]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[116] << '`' << obj.comp         << obj.manip << obj.obj->pack_add;
      before = true; 
     } 
    if ((*obj.include)[117]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[117] << '`' << obj.comp         << obj.manip << obj.obj->boundary_lev;
      before = true; 
     } 
    if ((*obj.include)[118]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[118] << '`' << obj.comp         << obj.manip << obj.obj->boundary_exp;
      before = true; 
     } 
    if ((*obj.include)[119]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[119] << '`' << obj.comp         << obj.manip << obj.obj->offer_point;
      before = true; 
     } 
    if ((*obj.include)[120]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[120] << '`' << obj.comp         << obj.manip << obj.obj->battle_lev;
      before = true; 
     } 
    if ((*obj.include)[121]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[121] << '`' << obj.comp         << obj.manip << obj.obj->channel_account;
      before = true; 
     } 
    if ((*obj.include)[122]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[122] << '`' << obj.comp         << obj.manip << obj.obj->recharge_emoney;
      before = true; 
     } 
    if ((*obj.include)[123]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[123] << '`' << obj.comp         << obj.manip << obj.obj->auto_battle_time;
      before = true; 
     } 
    if ((*obj.include)[124]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[124] << '`' << obj.comp         << obj.manip << obj.obj->first_recharge;
      before = true; 
     } 
    if ((*obj.include)[125]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[125] << '`' << obj.comp         << obj.manip << obj.obj->special_flag;
      before = true; 
     } 
    if ((*obj.include)[126]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[126] << '`' << obj.comp         << obj.manip << obj.obj->vip_lev;
      before = true; 
     } 
    if ((*obj.include)[127]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[127] << '`' << obj.comp         << obj.manip << obj.obj->ghosttoexp_amount;
      before = true; 
     } 
    if ((*obj.include)[128]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[128] << '`' << obj.comp         << obj.manip << obj.obj->vigor;
      before = true; 
     } 
    if ((*obj.include)[129]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[129] << '`' << obj.comp         << obj.manip << obj.obj->func_list;
     } 

        return s;
    }

    template <class Manip>
    inline CUserData_value_list<Manip> CUserData::value_list(const char* d, Manip m) const
            { return CUserData_value_list<Manip> (this, d, m); } 

    template <class Manip>
    inline CUserData_field_list<Manip> CUserData::field_list(const char* d, Manip m) const
            { return CUserData_field_list<Manip> (this, d, m); } 

    template <class Manip>
    inline CUserData_equal_list<Manip> CUserData::equal_list(const char* d, const char* c, Manip m) const
            { return CUserData_equal_list<Manip> (this, d, c, m); } 

    template <class Manip>
    inline CUserData_cus_value_list<Manip> CUserData::value_list(const char* d, Manip m,
            bool i1, bool i2, bool i3, bool i4, bool i5, bool i6, bool i7, bool i8, bool i9, bool i10, bool i11, bool i12, bool i13, bool i14, bool i15, bool i16, bool i17, bool i18, bool i19, bool i20, bool i21, bool i22, bool i23, bool i24, bool i25, bool i26, bool i27, bool i28, bool i29, bool i30, bool i31, bool i32, bool i33, bool i34, bool i35, bool i36, bool i37, bool i38, bool i39, bool i40, bool i41, bool i42, bool i43, bool i44, bool i45, bool i46, bool i47, bool i48, bool i49, bool i50, bool i51, bool i52, bool i53, bool i54, bool i55, bool i56, bool i57, bool i58, bool i59, bool i60, bool i61, bool i62, bool i63, bool i64, bool i65, bool i66, bool i67, bool i68, bool i69, bool i70, bool i71, bool i72, bool i73, bool i74, bool i75, bool i76, bool i77, bool i78, bool i79, bool i80, bool i81, bool i82, bool i83, bool i84, bool i85, bool i86, bool i87, bool i88, bool i89, bool i90, bool i91, bool i92, bool i93, bool i94, bool i95, bool i96, bool i97, bool i98, bool i99, bool i100, bool i101, bool i102, bool i103, bool i104, bool i105, bool i106, bool i107, bool i108, bool i109, bool i110, bool i111, bool i112, bool i113, bool i114, bool i115, bool i116, bool i117, bool i118, bool i119, bool i120, bool i121, bool i122, bool i123, bool i124, bool i125, bool i126, bool i127, bool i128, bool i129, bool i130) const
            { return CUserData_cus_value_list<Manip> (this, d, m, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15, i16, i17, i18, i19, i20, i21, i22, i23, i24, i25, i26, i27, i28, i29, i30, i31, i32, i33, i34, i35, i36, i37, i38, i39, i40, i41, i42, i43, i44, i45, i46, i47, i48, i49, i50, i51, i52, i53, i54, i55, i56, i57, i58, i59, i60, i61, i62, i63, i64, i65, i66, i67, i68, i69, i70, i71, i72, i73, i74, i75, i76, i77, i78, i79, i80, i81, i82, i83, i84, i85, i86, i87, i88, i89, i90, i91, i92, i93, i94, i95, i96, i97, i98, i99, i100, i101, i102, i103, i104, i105, i106, i107, i108, i109, i110, i111, i112, i113, i114, i115, i116, i117, i118, i119, i120, i121, i122, i123, i124, i125, i126, i127, i128, i129, i130); }

    template <class Manip>
    inline CUserData_cus_field_list<Manip> CUserData::field_list(const char* d, Manip m,
            bool i1, bool i2, bool i3, bool i4, bool i5, bool i6, bool i7, bool i8, bool i9, bool i10, bool i11, bool i12, bool i13, bool i14, bool i15, bool i16, bool i17, bool i18, bool i19, bool i20, bool i21, bool i22, bool i23, bool i24, bool i25, bool i26, bool i27, bool i28, bool i29, bool i30, bool i31, bool i32, bool i33, bool i34, bool i35, bool i36, bool i37, bool i38, bool i39, bool i40, bool i41, bool i42, bool i43, bool i44, bool i45, bool i46, bool i47, bool i48, bool i49, bool i50, bool i51, bool i52, bool i53, bool i54, bool i55, bool i56, bool i57, bool i58, bool i59, bool i60, bool i61, bool i62, bool i63, bool i64, bool i65, bool i66, bool i67, bool i68, bool i69, bool i70, bool i71, bool i72, bool i73, bool i74, bool i75, bool i76, bool i77, bool i78, bool i79, bool i80, bool i81, bool i82, bool i83, bool i84, bool i85, bool i86, bool i87, bool i88, bool i89, bool i90, bool i91, bool i92, bool i93, bool i94, bool i95, bool i96, bool i97, bool i98, bool i99, bool i100, bool i101, bool i102, bool i103, bool i104, bool i105, bool i106, bool i107, bool i108, bool i109, bool i110, bool i111, bool i112, bool i113, bool i114, bool i115, bool i116, bool i117, bool i118, bool i119, bool i120, bool i121, bool i122, bool i123, bool i124, bool i125, bool i126, bool i127, bool i128, bool i129, bool i130) const
            { return CUserData_cus_field_list<Manip> (this, d, m, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15, i16, i17, i18, i19, i20, i21, i22, i23, i24, i25, i26, i27, i28, i29, i30, i31, i32, i33, i34, i35, i36, i37, i38, i39, i40, i41, i42, i43, i44, i45, i46, i47, i48, i49, i50, i51, i52, i53, i54, i55, i56, i57, i58, i59, i60, i61, i62, i63, i64, i65, i66, i67, i68, i69, i70, i71, i72, i73, i74, i75, i76, i77, i78, i79, i80, i81, i82, i83, i84, i85, i86, i87, i88, i89, i90, i91, i92, i93, i94, i95, i96, i97, i98, i99, i100, i101, i102, i103, i104, i105, i106, i107, i108, i109, i110, i111, i112, i113, i114, i115, i116, i117, i118, i119, i120, i121, i122, i123, i124, i125, i126, i127, i128, i129, i130); }

    template <class Manip>
    inline CUserData_cus_equal_list<Manip> CUserData::equal_list(const char* d, const char* c, Manip m,
            bool i1, bool i2, bool i3, bool i4, bool i5, bool i6, bool i7, bool i8, bool i9, bool i10, bool i11, bool i12, bool i13, bool i14, bool i15, bool i16, bool i17, bool i18, bool i19, bool i20, bool i21, bool i22, bool i23, bool i24, bool i25, bool i26, bool i27, bool i28, bool i29, bool i30, bool i31, bool i32, bool i33, bool i34, bool i35, bool i36, bool i37, bool i38, bool i39, bool i40, bool i41, bool i42, bool i43, bool i44, bool i45, bool i46, bool i47, bool i48, bool i49, bool i50, bool i51, bool i52, bool i53, bool i54, bool i55, bool i56, bool i57, bool i58, bool i59, bool i60, bool i61, bool i62, bool i63, bool i64, bool i65, bool i66, bool i67, bool i68, bool i69, bool i70, bool i71, bool i72, bool i73, bool i74, bool i75, bool i76, bool i77, bool i78, bool i79, bool i80, bool i81, bool i82, bool i83, bool i84, bool i85, bool i86, bool i87, bool i88, bool i89, bool i90, bool i91, bool i92, bool i93, bool i94, bool i95, bool i96, bool i97, bool i98, bool i99, bool i100, bool i101, bool i102, bool i103, bool i104, bool i105, bool i106, bool i107, bool i108, bool i109, bool i110, bool i111, bool i112, bool i113, bool i114, bool i115, bool i116, bool i117, bool i118, bool i119, bool i120, bool i121, bool i122, bool i123, bool i124, bool i125, bool i126, bool i127, bool i128, bool i129, bool i130) const
            { return CUserData_cus_equal_list<Manip> (this, d, c, m, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15, i16, i17, i18, i19, i20, i21, i22, i23, i24, i25, i26, i27, i28, i29, i30, i31, i32, i33, i34, i35, i36, i37, i38, i39, i40, i41, i42, i43, i44, i45, i46, i47, i48, i49, i50, i51, i52, i53, i54, i55, i56, i57, i58, i59, i60, i61, i62, i63, i64, i65, i66, i67, i68, i69, i70, i71, i72, i73, i74, i75, i76, i77, i78, i79, i80, i81, i82, i83, i84, i85, i86, i87, i88, i89, i90, i91, i92, i93, i94, i95, i96, i97, i98, i99, i100, i101, i102, i103, i104, i105, i106, i107, i108, i109, i110, i111, i112, i113, i114, i115, i116, i117, i118, i119, i120, i121, i122, i123, i124, i125, i126, i127, i128, i129, i130); } 

    template <class Manip>
    inline CUserData_cus_value_list<Manip> CUserData::value_list(const char* d, Manip m,
            CUserData_enum i1, CUserData_enum i2, CUserData_enum i3, CUserData_enum i4, CUserData_enum i5, CUserData_enum i6, CUserData_enum i7, CUserData_enum i8, CUserData_enum i9, CUserData_enum i10, CUserData_enum i11, CUserData_enum i12, CUserData_enum i13, CUserData_enum i14, CUserData_enum i15, CUserData_enum i16, CUserData_enum i17, CUserData_enum i18, CUserData_enum i19, CUserData_enum i20, CUserData_enum i21, CUserData_enum i22, CUserData_enum i23, CUserData_enum i24, CUserData_enum i25, CUserData_enum i26, CUserData_enum i27, CUserData_enum i28, CUserData_enum i29, CUserData_enum i30, CUserData_enum i31, CUserData_enum i32, CUserData_enum i33, CUserData_enum i34, CUserData_enum i35, CUserData_enum i36, CUserData_enum i37, CUserData_enum i38, CUserData_enum i39, CUserData_enum i40, CUserData_enum i41, CUserData_enum i42, CUserData_enum i43, CUserData_enum i44, CUserData_enum i45, CUserData_enum i46, CUserData_enum i47, CUserData_enum i48, CUserData_enum i49, CUserData_enum i50, CUserData_enum i51, CUserData_enum i52, CUserData_enum i53, CUserData_enum i54, CUserData_enum i55, CUserData_enum i56, CUserData_enum i57, CUserData_enum i58, CUserData_enum i59, CUserData_enum i60, CUserData_enum i61, CUserData_enum i62, CUserData_enum i63, CUserData_enum i64, CUserData_enum i65, CUserData_enum i66, CUserData_enum i67, CUserData_enum i68, CUserData_enum i69, CUserData_enum i70, CUserData_enum i71, CUserData_enum i72, CUserData_enum i73, CUserData_enum i74, CUserData_enum i75, CUserData_enum i76, CUserData_enum i77, CUserData_enum i78, CUserData_enum i79, CUserData_enum i80, CUserData_enum i81, CUserData_enum i82, CUserData_enum i83, CUserData_enum i84, CUserData_enum i85, CUserData_enum i86, CUserData_enum i87, CUserData_enum i88, CUserData_enum i89, CUserData_enum i90, CUserData_enum i91, CUserData_enum i92, CUserData_enum i93, CUserData_enum i94, CUserData_enum i95, CUserData_enum i96, CUserData_enum i97, CUserData_enum i98, CUserData_enum i99, CUserData_enum i100, CUserData_enum i101, CUserData_enum i102, CUserData_enum i103, CUserData_enum i104, CUserData_enum i105, CUserData_enum i106, CUserData_enum i107, CUserData_enum i108, CUserData_enum i109, CUserData_enum i110, CUserData_enum i111, CUserData_enum i112, CUserData_enum i113, CUserData_enum i114, CUserData_enum i115, CUserData_enum i116, CUserData_enum i117, CUserData_enum i118, CUserData_enum i119, CUserData_enum i120, CUserData_enum i121, CUserData_enum i122, CUserData_enum i123, CUserData_enum i124, CUserData_enum i125, CUserData_enum i126, CUserData_enum i127, CUserData_enum i128, CUserData_enum i129, CUserData_enum i130) const
            { return CUserData_cus_value_list<Manip> (this, d, m, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15, i16, i17, i18, i19, i20, i21, i22, i23, i24, i25, i26, i27, i28, i29, i30, i31, i32, i33, i34, i35, i36, i37, i38, i39, i40, i41, i42, i43, i44, i45, i46, i47, i48, i49, i50, i51, i52, i53, i54, i55, i56, i57, i58, i59, i60, i61, i62, i63, i64, i65, i66, i67, i68, i69, i70, i71, i72, i73, i74, i75, i76, i77, i78, i79, i80, i81, i82, i83, i84, i85, i86, i87, i88, i89, i90, i91, i92, i93, i94, i95, i96, i97, i98, i99, i100, i101, i102, i103, i104, i105, i106, i107, i108, i109, i110, i111, i112, i113, i114, i115, i116, i117, i118, i119, i120, i121, i122, i123, i124, i125, i126, i127, i128, i129, i130); } 

    template <class Manip>
    inline CUserData_cus_field_list<Manip> CUserData::field_list(const char* d, Manip m,
            CUserData_enum i1, CUserData_enum i2, CUserData_enum i3, CUserData_enum i4, CUserData_enum i5, CUserData_enum i6, CUserData_enum i7, CUserData_enum i8, CUserData_enum i9, CUserData_enum i10, CUserData_enum i11, CUserData_enum i12, CUserData_enum i13, CUserData_enum i14, CUserData_enum i15, CUserData_enum i16, CUserData_enum i17, CUserData_enum i18, CUserData_enum i19, CUserData_enum i20, CUserData_enum i21, CUserData_enum i22, CUserData_enum i23, CUserData_enum i24, CUserData_enum i25, CUserData_enum i26, CUserData_enum i27, CUserData_enum i28, CUserData_enum i29, CUserData_enum i30, CUserData_enum i31, CUserData_enum i32, CUserData_enum i33, CUserData_enum i34, CUserData_enum i35, CUserData_enum i36, CUserData_enum i37, CUserData_enum i38, CUserData_enum i39, CUserData_enum i40, CUserData_enum i41, CUserData_enum i42, CUserData_enum i43, CUserData_enum i44, CUserData_enum i45, CUserData_enum i46, CUserData_enum i47, CUserData_enum i48, CUserData_enum i49, CUserData_enum i50, CUserData_enum i51, CUserData_enum i52, CUserData_enum i53, CUserData_enum i54, CUserData_enum i55, CUserData_enum i56, CUserData_enum i57, CUserData_enum i58, CUserData_enum i59, CUserData_enum i60, CUserData_enum i61, CUserData_enum i62, CUserData_enum i63, CUserData_enum i64, CUserData_enum i65, CUserData_enum i66, CUserData_enum i67, CUserData_enum i68, CUserData_enum i69, CUserData_enum i70, CUserData_enum i71, CUserData_enum i72, CUserData_enum i73, CUserData_enum i74, CUserData_enum i75, CUserData_enum i76, CUserData_enum i77, CUserData_enum i78, CUserData_enum i79, CUserData_enum i80, CUserData_enum i81, CUserData_enum i82, CUserData_enum i83, CUserData_enum i84, CUserData_enum i85, CUserData_enum i86, CUserData_enum i87, CUserData_enum i88, CUserData_enum i89, CUserData_enum i90, CUserData_enum i91, CUserData_enum i92, CUserData_enum i93, CUserData_enum i94, CUserData_enum i95, CUserData_enum i96, CUserData_enum i97, CUserData_enum i98, CUserData_enum i99, CUserData_enum i100, CUserData_enum i101, CUserData_enum i102, CUserData_enum i103, CUserData_enum i104, CUserData_enum i105, CUserData_enum i106, CUserData_enum i107, CUserData_enum i108, CUserData_enum i109, CUserData_enum i110, CUserData_enum i111, CUserData_enum i112, CUserData_enum i113, CUserData_enum i114, CUserData_enum i115, CUserData_enum i116, CUserData_enum i117, CUserData_enum i118, CUserData_enum i119, CUserData_enum i120, CUserData_enum i121, CUserData_enum i122, CUserData_enum i123, CUserData_enum i124, CUserData_enum i125, CUserData_enum i126, CUserData_enum i127, CUserData_enum i128, CUserData_enum i129, CUserData_enum i130) const
            { return CUserData_cus_field_list<Manip> (this, d, m, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15, i16, i17, i18, i19, i20, i21, i22, i23, i24, i25, i26, i27, i28, i29, i30, i31, i32, i33, i34, i35, i36, i37, i38, i39, i40, i41, i42, i43, i44, i45, i46, i47, i48, i49, i50, i51, i52, i53, i54, i55, i56, i57, i58, i59, i60, i61, i62, i63, i64, i65, i66, i67, i68, i69, i70, i71, i72, i73, i74, i75, i76, i77, i78, i79, i80, i81, i82, i83, i84, i85, i86, i87, i88, i89, i90, i91, i92, i93, i94, i95, i96, i97, i98, i99, i100, i101, i102, i103, i104, i105, i106, i107, i108, i109, i110, i111, i112, i113, i114, i115, i116, i117, i118, i119, i120, i121, i122, i123, i124, i125, i126, i127, i128, i129, i130); } 

    template <class Manip>
    inline CUserData_cus_equal_list<Manip> CUserData::equal_list(const char* d, const char* c, Manip m, 
            CUserData_enum i1, CUserData_enum i2, CUserData_enum i3, CUserData_enum i4, CUserData_enum i5, CUserData_enum i6, CUserData_enum i7, CUserData_enum i8, CUserData_enum i9, CUserData_enum i10, CUserData_enum i11, CUserData_enum i12, CUserData_enum i13, CUserData_enum i14, CUserData_enum i15, CUserData_enum i16, CUserData_enum i17, CUserData_enum i18, CUserData_enum i19, CUserData_enum i20, CUserData_enum i21, CUserData_enum i22, CUserData_enum i23, CUserData_enum i24, CUserData_enum i25, CUserData_enum i26, CUserData_enum i27, CUserData_enum i28, CUserData_enum i29, CUserData_enum i30, CUserData_enum i31, CUserData_enum i32, CUserData_enum i33, CUserData_enum i34, CUserData_enum i35, CUserData_enum i36, CUserData_enum i37, CUserData_enum i38, CUserData_enum i39, CUserData_enum i40, CUserData_enum i41, CUserData_enum i42, CUserData_enum i43, CUserData_enum i44, CUserData_enum i45, CUserData_enum i46, CUserData_enum i47, CUserData_enum i48, CUserData_enum i49, CUserData_enum i50, CUserData_enum i51, CUserData_enum i52, CUserData_enum i53, CUserData_enum i54, CUserData_enum i55, CUserData_enum i56, CUserData_enum i57, CUserData_enum i58, CUserData_enum i59, CUserData_enum i60, CUserData_enum i61, CUserData_enum i62, CUserData_enum i63, CUserData_enum i64, CUserData_enum i65, CUserData_enum i66, CUserData_enum i67, CUserData_enum i68, CUserData_enum i69, CUserData_enum i70, CUserData_enum i71, CUserData_enum i72, CUserData_enum i73, CUserData_enum i74, CUserData_enum i75, CUserData_enum i76, CUserData_enum i77, CUserData_enum i78, CUserData_enum i79, CUserData_enum i80, CUserData_enum i81, CUserData_enum i82, CUserData_enum i83, CUserData_enum i84, CUserData_enum i85, CUserData_enum i86, CUserData_enum i87, CUserData_enum i88, CUserData_enum i89, CUserData_enum i90, CUserData_enum i91, CUserData_enum i92, CUserData_enum i93, CUserData_enum i94, CUserData_enum i95, CUserData_enum i96, CUserData_enum i97, CUserData_enum i98, CUserData_enum i99, CUserData_enum i100, CUserData_enum i101, CUserData_enum i102, CUserData_enum i103, CUserData_enum i104, CUserData_enum i105, CUserData_enum i106, CUserData_enum i107, CUserData_enum i108, CUserData_enum i109, CUserData_enum i110, CUserData_enum i111, CUserData_enum i112, CUserData_enum i113, CUserData_enum i114, CUserData_enum i115, CUserData_enum i116, CUserData_enum i117, CUserData_enum i118, CUserData_enum i119, CUserData_enum i120, CUserData_enum i121, CUserData_enum i122, CUserData_enum i123, CUserData_enum i124, CUserData_enum i125, CUserData_enum i126, CUserData_enum i127, CUserData_enum i128, CUserData_enum i129, CUserData_enum i130) const
            { return CUserData_cus_equal_list<Manip> (this, d, c, m, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15, i16, i17, i18, i19, i20, i21, i22, i23, i24, i25, i26, i27, i28, i29, i30, i31, i32, i33, i34, i35, i36, i37, i38, i39, i40, i41, i42, i43, i44, i45, i46, i47, i48, i49, i50, i51, i52, i53, i54, i55, i56, i57, i58, i59, i60, i61, i62, i63, i64, i65, i66, i67, i68, i69, i70, i71, i72, i73, i74, i75, i76, i77, i78, i79, i80, i81, i82, i83, i84, i85, i86, i87, i88, i89, i90, i91, i92, i93, i94, i95, i96, i97, i98, i99, i100, i101, i102, i103, i104, i105, i106, i107, i108, i109, i110, i111, i112, i113, i114, i115, i116, i117, i118, i119, i120, i121, i122, i123, i124, i125, i126, i127, i128, i129, i130); } 

    template <class Manip>
    inline CUserData_cus_value_list<Manip> CUserData::value_list(const char* d, Manip m,
            std::vector<bool> *i) const
            { return CUserData_cus_value_list<Manip> (this, d, m, i); }

    template <class Manip>
    inline CUserData_cus_field_list<Manip> CUserData::field_list(const char* d, Manip m,
            std::vector<bool> *i) const
            { return CUserData_cus_field_list<Manip> (this, d, m, i); }

    template <class Manip>
    inline CUserData_cus_equal_list<Manip> CUserData::equal_list(const char* d, const char* c, Manip m,
            std::vector<bool> *i) const
            { return CUserData_cus_equal_list<Manip> (this, d, c, m, i); }

    template <class Manip>
    inline CUserData_cus_value_list<Manip> 
    CUserData::value_list(const char* d, Manip m, mysqlpp::sql_cmp_type /*sc*/) const
            { return value_list(d, m, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true); }

    template <class Manip>
    inline CUserData_cus_field_list<Manip> 
    CUserData::field_list(const char* d, Manip m, mysqlpp::sql_cmp_type /*sc*/) const
            { return field_list(d, m, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true); }

    template <class Manip>
    inline CUserData_cus_equal_list<Manip> 
    CUserData::equal_list(const char* d, const char* c, Manip m, mysqlpp::sql_cmp_type /*sc*/) const
            { return equal_list(d, c, m, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true); }

    template <mysqlpp::sql_dummy_type dummy>
    void populate_CUserData(CUserData *s, const mysqlpp::Row &row)
    {
        mysqlpp::NoExceptions ignore_schema_mismatches(row);
    s->name = row["name"].conv(sql_varchar());
    s->mate = row["mate"].conv(sql_varchar());
    s->lookface = row["lookface"].conv(sql_int_unsigned());
    s->hair = row["hair"].conv(sql_smallint_unsigned());
    s->length = row["length"].conv(sql_tinyint());
    s->fat = row["fat"].conv(sql_tinyint());
    s->money = row["money"].conv(sql_int_unsigned());
    s->money_saved = row["money_saved"].conv(sql_bigint_unsigned());
    s->task_data = row["task_data"].conv(sql_int_unsigned());
    s->level = row["level"].conv(sql_tinyint_unsigned());
    s->exp = row["exp"].conv(sql_bigint());
    s->power = row["power"].conv(sql_smallint_unsigned());
    s->constitution = row["constitution"].conv(sql_smallint_unsigned());
    s->dexterity = row["dexterity"].conv(sql_smallint_unsigned());
    s->Speed = row["Speed"].conv(sql_smallint_unsigned());
    s->health = row["health"].conv(sql_smallint_unsigned());
    s->soul = row["soul"].conv(sql_smallint_unsigned());
    s->additional_point = row["additional_point"].conv(sql_smallint_unsigned());
    s->auto_allot = row["auto_allot"].conv(sql_tinyint_unsigned());
    s->life = row["life"].conv(sql_int_unsigned());
    s->mana = row["mana"].conv(sql_smallint_unsigned());
    s->profession = row["profession"].conv(sql_tinyint_unsigned());
    s->potential = row["potential"].conv(sql_int());
    s->pk = row["pk"].conv(sql_smallint());
    s->nobility = row["nobility"].conv(sql_tinyint_unsigned());
    s->medal = row["medal"].conv(sql_varchar());
    s->medal_select = row["medal_select"].conv(sql_int_unsigned());
    s->metempsychosis = row["metempsychosis"].conv(sql_tinyint_unsigned());
    s->syndicate_id = row["syndicate_id"].conv(sql_int_unsigned());
    s->recordmap_id = row["recordmap_id"].conv(sql_int_unsigned());
    s->recordx = row["recordx"].conv(sql_smallint_unsigned());
    s->recordy = row["recordy"].conv(sql_smallint_unsigned());
    s->account_id = row["account_id"].conv(sql_int_unsigned());
    s->id = row["id"].conv(sql_int_unsigned());
    s->last_login = row["last_login"].conv(sql_int_unsigned());
    s->account = row["account"].conv(sql_varchar());
    s->password = row["password"].conv(sql_varchar());
    s->task_mask = row["task_mask"].conv(sql_int_unsigned());
    s->time_of_life = row["time_of_life"].conv(sql_int_unsigned());
    s->virtue = row["virtue"].conv(sql_int_unsigned());
    s->home_id = row["home_id"].conv(sql_int_unsigned());
    s->title = row["title"].conv(sql_varchar());
    s->title_select = row["title_select"].conv(sql_tinyint_unsigned());
    s->tutor_exp = row["tutor_exp"].conv(sql_int());
    s->tutor_level = row["tutor_level"].conv(sql_tinyint_unsigned());
    s->maxlife_percent = row["maxlife_percent"].conv(sql_int_unsigned());
    s->mercenary_rank = row["mercenary_rank"].conv(sql_tinyint_unsigned());
    s->mercenary_exp = row["mercenary_exp"].conv(sql_smallint_unsigned());
    s->nobility_rank = row["nobility_rank"].conv(sql_tinyint_unsigned());
    s->exploit = row["exploit"].conv(sql_int_unsigned());
    s->eud_pack_size = row["eud_pack_size"].conv(sql_tinyint());
    s->disableFlag = row["disableFlag"].conv(sql_int());
    s->reg_time = row["reg_time"].conv(sql_int_unsigned());
    s->accu_online_time = row["accu_online_time"].conv(sql_tinyint_unsigned());
    s->accu_offline_time = row["accu_offline_time"].conv(sql_tinyint_unsigned());
    s->last_logout = row["last_logout"].conv(sql_int_unsigned());
    s->prompt_ver = row["prompt_ver"].conv(sql_int_unsigned_null());
    s->Friend_share = row["Friend_share"].conv(sql_int_unsigned_null());
    s->Login_time = row["Login_time"].conv(sql_int_unsigned_null());
    s->Login_ip = row["Login_ip"].conv(sql_int_unsigned_null());
    s->soul_value = row["soul_value"].conv(sql_int_unsigned());
    s->brood_times = row["brood_times"].conv(sql_int_unsigned());
    s->emoney = row["emoney"].conv(sql_int_unsigned());
    s->chk_sum = row["chk_sum"].conv(sql_int_unsigned());
    s->elock = row["elock"].conv(sql_varchar());
    s->ExpBallUsage = row["ExpBallUsage"].conv(sql_int());
    s->ExpCrystalUsage = row["ExpCrystalUsage"].conv(sql_smallint_unsigned());
    s->cheat_time = row["cheat_time"].conv(sql_int_unsigned());
    s->online_time = row["online_time"].conv(sql_tinyint());
    s->auto_exercise = row["auto_exercise"].conv(sql_tinyint());
    s->hung_last_logout = row["hung_last_logout"].conv(sql_int_unsigned());
    s->god_status = row["god_status"].conv(sql_int_unsigned());
    s->big_prize_fails = row["big_prize_fails"].conv(sql_tinyint_unsigned());
    s->small_prize_fails = row["small_prize_fails"].conv(sql_tinyint_unsigned());
    s->bonus_points = row["bonus_points"].conv(sql_int_unsigned());
    s->flower = row["flower"].conv(sql_int_unsigned_null());
    s->flower_w = row["flower_w"].conv(sql_int_unsigned());
    s->flower_p = row["flower_p"].conv(sql_int());
    s->income = row["income"].conv(sql_bigint());
    s->illu_ButterFly = row["illu_ButterFly"].conv(sql_bigint_unsigned());
    s->illu_Fish = row["illu_Fish"].conv(sql_bigint_unsigned());
    s->illu_Shell = row["illu_Shell"].conv(sql_bigint_unsigned());
    s->illu_Herbal = row["illu_Herbal"].conv(sql_bigint_unsigned());
    s->illu_Ore = row["illu_Ore"].conv(sql_bigint_unsigned());
    s->password_id = row["password_id"].conv(sql_int());
    s->quiz_point = row["quiz_point"].conv(sql_int());
    s->protect_state = row["protect_state"].conv(sql_tinyint_unsigned());
    s->donation = row["donation"].conv(sql_bigint());
    s->wood = row["wood"].conv(sql_int_unsigned());
    s->stone = row["stone"].conv(sql_int_unsigned());
    s->todo_list_mask1 = row["todo_list_mask1"].conv(sql_int_unsigned());
    s->todo_list1 = row["todo_list1"].conv(sql_bigint_unsigned());
    s->todo_list_hex1 = row["todo_list_hex1"].conv(sql_bigint_unsigned_null());
    s->coach = row["coach"].conv(sql_smallint_unsigned());
    s->coach_time = row["coach_time"].conv(sql_smallint_unsigned());
    s->coach_deed = row["coach_deed"].conv(sql_smallint_unsigned());
    s->coach_date = row["coach_date"].conv(sql_smallint_unsigned());
    s->extra_hatch_size = row["extra_hatch_size"].conv(sql_tinyint_unsigned());
    s->shadiness_money = row["shadiness_money"].conv(sql_bigint_unsigned_null());
    s->shadiness_emoney = row["shadiness_emoney"].conv(sql_int_unsigned_null());
    s->soul_value_lev = row["soul_value_lev"].conv(sql_tinyint_unsigned());
    s->business = row["business"].conv(sql_int_unsigned());
    s->emoney2 = row["emoney2"].conv(sql_int_unsigned());
    s->type = row["type"].conv(sql_tinyint_unsigned_null());
    s->god_strength = row["god_strength"].conv(sql_bigint_unsigned_null());
    s->god_level = row["god_level"].conv(sql_tinyint_unsigned_null());
    s->deification = row["deification"].conv(sql_tinyint_unsigned_null());
    s->tmoney = row["tmoney"].conv(sql_int_unsigned());
    s->demon_level = row["demon_level"].conv(sql_tinyint_unsigned_null());
    s->demon_exp = row["demon_exp"].conv(sql_bigint_unsigned_null());
    s->socialclass = row["socialclass"].conv(sql_int_unsigned());
    s->credit_point = row["credit_point"].conv(sql_int_unsigned());
    s->credit_limit = row["credit_limit"].conv(sql_int_unsigned());
    s->credit_return = row["credit_return"].conv(sql_smallint_unsigned());
    s->eudkernel_id = row["eudkernel_id"].conv(sql_int_unsigned());
    s->refinery_time_end = row["refinery_time_end"].conv(sql_int_unsigned());
    s->pack_add = row["pack_add"].conv(sql_tinyint_unsigned());
    s->boundary_lev = row["boundary_lev"].conv(sql_tinyint_unsigned());
    s->boundary_exp = row["boundary_exp"].conv(sql_int_unsigned());
    s->offer_point = row["offer_point"].conv(sql_int_unsigned());
    s->battle_lev = row["battle_lev"].conv(sql_int_unsigned());
    s->channel_account = row["channel_account"].conv(sql_varchar());
    s->recharge_emoney = row["recharge_emoney"].conv(sql_int_unsigned());
    s->auto_battle_time = row["auto_battle_time"].conv(sql_int_unsigned());
    s->first_recharge = row["first_recharge"].conv(sql_int_unsigned());
    s->special_flag = row["special_flag"].conv(sql_int_unsigned());
    s->vip_lev = row["vip_lev"].conv(sql_int_unsigned());
    s->ghosttoexp_amount = row["ghosttoexp_amount"].conv(sql_int_unsigned());
    s->vigor = row["vigor"].conv(sql_int_unsigned());
    s->func_list = row["func_list"].conv(sql_bigint_unsigned());
    }

    inline CUserData::CUserData(const mysqlpp::Row& row) :
    table_override_(0)
            { populate_CUserData<mysqlpp::sql_dummy>(this, row); }
    inline void CUserData::set(const mysqlpp::Row& row)
    {
        table_override_ = 0;
        populate_CUserData<mysqlpp::sql_dummy>(this, row);
    }

    template <mysqlpp::sql_dummy_type dummy> 
 int sql_compare_CUserData(const CUserData &x, const CUserData &y) { 
     int cmp; \
    cmp = mysqlpp::sql_cmp(x.name, y.name ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.mate, y.mate ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.lookface, y.lookface ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.hair, y.hair ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.length, y.length ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.fat, y.fat ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.money, y.money ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.money_saved, y.money_saved ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.task_data, y.task_data ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.level, y.level ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.exp, y.exp ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.power, y.power ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.constitution, y.constitution ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.dexterity, y.dexterity ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.Speed, y.Speed ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.health, y.health ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.soul, y.soul ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.additional_point, y.additional_point ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.auto_allot, y.auto_allot ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.life, y.life ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.mana, y.mana ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.profession, y.profession ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.potential, y.potential ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.pk, y.pk ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.nobility, y.nobility ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.medal, y.medal ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.medal_select, y.medal_select ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.metempsychosis, y.metempsychosis ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.syndicate_id, y.syndicate_id ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.recordmap_id, y.recordmap_id ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.recordx, y.recordx ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.recordy, y.recordy ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.account_id, y.account_id ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.id, y.id ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.last_login, y.last_login ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.account, y.account ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.password, y.password ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.task_mask, y.task_mask ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.time_of_life, y.time_of_life ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.virtue, y.virtue ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.home_id, y.home_id ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.title, y.title ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.title_select, y.title_select ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.tutor_exp, y.tutor_exp ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.tutor_level, y.tutor_level ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.maxlife_percent, y.maxlife_percent ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.mercenary_rank, y.mercenary_rank ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.mercenary_exp, y.mercenary_exp ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.nobility_rank, y.nobility_rank ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.exploit, y.exploit ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.eud_pack_size, y.eud_pack_size ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.disableFlag, y.disableFlag ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.reg_time, y.reg_time ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.accu_online_time, y.accu_online_time ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.accu_offline_time, y.accu_offline_time ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.last_logout, y.last_logout ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.prompt_ver, y.prompt_ver ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.Friend_share, y.Friend_share ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.Login_time, y.Login_time ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.Login_ip, y.Login_ip ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.soul_value, y.soul_value ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.brood_times, y.brood_times ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.emoney, y.emoney ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.chk_sum, y.chk_sum ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.elock, y.elock ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.ExpBallUsage, y.ExpBallUsage ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.ExpCrystalUsage, y.ExpCrystalUsage ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.cheat_time, y.cheat_time ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.online_time, y.online_time ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.auto_exercise, y.auto_exercise ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.hung_last_logout, y.hung_last_logout ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.god_status, y.god_status ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.big_prize_fails, y.big_prize_fails ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.small_prize_fails, y.small_prize_fails ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.bonus_points, y.bonus_points ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.flower, y.flower ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.flower_w, y.flower_w ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.flower_p, y.flower_p ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.income, y.income ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.illu_ButterFly, y.illu_ButterFly ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.illu_Fish, y.illu_Fish ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.illu_Shell, y.illu_Shell ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.illu_Herbal, y.illu_Herbal ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.illu_Ore, y.illu_Ore ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.password_id, y.password_id ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.quiz_point, y.quiz_point ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.protect_state, y.protect_state ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.donation, y.donation ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.wood, y.wood ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.stone, y.stone ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.todo_list_mask1, y.todo_list_mask1 ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.todo_list1, y.todo_list1 ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.todo_list_hex1, y.todo_list_hex1 ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.coach, y.coach ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.coach_time, y.coach_time ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.coach_deed, y.coach_deed ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.coach_date, y.coach_date ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.extra_hatch_size, y.extra_hatch_size ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.shadiness_money, y.shadiness_money ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.shadiness_emoney, y.shadiness_emoney ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.soul_value_lev, y.soul_value_lev ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.business, y.business ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.emoney2, y.emoney2 ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.type, y.type ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.god_strength, y.god_strength ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.god_level, y.god_level ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.deification, y.deification ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.tmoney, y.tmoney ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.demon_level, y.demon_level ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.demon_exp, y.demon_exp ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.socialclass, y.socialclass ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.credit_point, y.credit_point ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.credit_limit, y.credit_limit ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.credit_return, y.credit_return ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.eudkernel_id, y.eudkernel_id ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.refinery_time_end, y.refinery_time_end ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.pack_add, y.pack_add ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.boundary_lev, y.boundary_lev ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.boundary_exp, y.boundary_exp ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.offer_point, y.offer_point ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.battle_lev, y.battle_lev ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.channel_account, y.channel_account ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.recharge_emoney, y.recharge_emoney ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.auto_battle_time, y.auto_battle_time ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.first_recharge, y.first_recharge ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.special_flag, y.special_flag ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.vip_lev, y.vip_lev ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.ghosttoexp_amount, y.ghosttoexp_amount ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.vigor, y.vigor ); \
    if (cmp) return cmp; \
    return mysqlpp::sql_cmp(x.func_list, y.func_list); 
 } 
 template <mysqlpp::sql_dummy_type dummy> 
 int compare (const CUserData &x, const CUserData &y) { 
     int cmp; \
    cmp = mysqlpp::sql_cmp(x.name, y.name ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.mate, y.mate ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.lookface, y.lookface ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.hair, y.hair ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.length, y.length ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.fat, y.fat ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.money, y.money ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.money_saved, y.money_saved ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.task_data, y.task_data ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.level, y.level ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.exp, y.exp ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.power, y.power ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.constitution, y.constitution ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.dexterity, y.dexterity ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.Speed, y.Speed ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.health, y.health ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.soul, y.soul ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.additional_point, y.additional_point ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.auto_allot, y.auto_allot ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.life, y.life ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.mana, y.mana ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.profession, y.profession ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.potential, y.potential ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.pk, y.pk ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.nobility, y.nobility ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.medal, y.medal ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.medal_select, y.medal_select ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.metempsychosis, y.metempsychosis ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.syndicate_id, y.syndicate_id ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.recordmap_id, y.recordmap_id ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.recordx, y.recordx ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.recordy, y.recordy ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.account_id, y.account_id ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.id, y.id ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.last_login, y.last_login ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.account, y.account ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.password, y.password ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.task_mask, y.task_mask ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.time_of_life, y.time_of_life ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.virtue, y.virtue ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.home_id, y.home_id ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.title, y.title ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.title_select, y.title_select ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.tutor_exp, y.tutor_exp ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.tutor_level, y.tutor_level ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.maxlife_percent, y.maxlife_percent ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.mercenary_rank, y.mercenary_rank ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.mercenary_exp, y.mercenary_exp ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.nobility_rank, y.nobility_rank ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.exploit, y.exploit ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.eud_pack_size, y.eud_pack_size ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.disableFlag, y.disableFlag ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.reg_time, y.reg_time ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.accu_online_time, y.accu_online_time ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.accu_offline_time, y.accu_offline_time ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.last_logout, y.last_logout ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.prompt_ver, y.prompt_ver ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.Friend_share, y.Friend_share ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.Login_time, y.Login_time ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.Login_ip, y.Login_ip ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.soul_value, y.soul_value ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.brood_times, y.brood_times ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.emoney, y.emoney ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.chk_sum, y.chk_sum ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.elock, y.elock ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.ExpBallUsage, y.ExpBallUsage ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.ExpCrystalUsage, y.ExpCrystalUsage ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.cheat_time, y.cheat_time ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.online_time, y.online_time ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.auto_exercise, y.auto_exercise ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.hung_last_logout, y.hung_last_logout ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.god_status, y.god_status ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.big_prize_fails, y.big_prize_fails ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.small_prize_fails, y.small_prize_fails ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.bonus_points, y.bonus_points ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.flower, y.flower ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.flower_w, y.flower_w ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.flower_p, y.flower_p ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.income, y.income ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.illu_ButterFly, y.illu_ButterFly ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.illu_Fish, y.illu_Fish ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.illu_Shell, y.illu_Shell ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.illu_Herbal, y.illu_Herbal ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.illu_Ore, y.illu_Ore ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.password_id, y.password_id ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.quiz_point, y.quiz_point ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.protect_state, y.protect_state ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.donation, y.donation ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.wood, y.wood ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.stone, y.stone ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.todo_list_mask1, y.todo_list_mask1 ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.todo_list1, y.todo_list1 ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.todo_list_hex1, y.todo_list_hex1 ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.coach, y.coach ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.coach_time, y.coach_time ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.coach_deed, y.coach_deed ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.coach_date, y.coach_date ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.extra_hatch_size, y.extra_hatch_size ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.shadiness_money, y.shadiness_money ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.shadiness_emoney, y.shadiness_emoney ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.soul_value_lev, y.soul_value_lev ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.business, y.business ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.emoney2, y.emoney2 ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.type, y.type ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.god_strength, y.god_strength ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.god_level, y.god_level ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.deification, y.deification ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.tmoney, y.tmoney ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.demon_level, y.demon_level ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.demon_exp, y.demon_exp ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.socialclass, y.socialclass ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.credit_point, y.credit_point ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.credit_limit, y.credit_limit ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.credit_return, y.credit_return ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.eudkernel_id, y.eudkernel_id ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.refinery_time_end, y.refinery_time_end ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.pack_add, y.pack_add ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.boundary_lev, y.boundary_lev ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.boundary_exp, y.boundary_exp ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.offer_point, y.offer_point ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.battle_lev, y.battle_lev ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.channel_account, y.channel_account ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.recharge_emoney, y.recharge_emoney ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.auto_battle_time, y.auto_battle_time ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.first_recharge, y.first_recharge ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.special_flag, y.special_flag ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.vip_lev, y.vip_lev ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.ghosttoexp_amount, y.ghosttoexp_amount ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.vigor, y.vigor ); \
    if (cmp) return cmp; \
    return mysqlpp::sql_cmp(x.func_list, y.func_list); 
 }

#endif	//end of define _USER_DATA_H_