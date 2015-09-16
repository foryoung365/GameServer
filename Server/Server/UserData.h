////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author: 	Fu Yan
// Created: 	2015-08-17
// Describe: 	Specailized SQL structure of table gs_user, 
//				generate by genSsqls.py, !!!DO NOT EDIT!!!
////////////////////////////////////////////////////////////////////////
#ifndef _USER_DATA_H_
#define _USER_DATA_H_

#include <mysql++.h>
#include <ssqls.h>

using namespace mysqlpp;

struct CUserData; 
    
        enum CUserData_enum { 
        USERDATA_ID,
    USERDATA_NAME,
    USERDATA_ACCOUNT_ID,
    USERDATA_ROLE_TYPE,
    USERDATA_LEVEL,
    USERDATA_EXP,
    USERDATA_LENGTH,
    USERDATA_WIDTH,
    USERDATA_HEIGHT,
    USERDATA_SCENE_ID,
    USERDATA_POS_X,
    USERDATA_POS_Y,
    USERDATA_POS_Z,
    USERDATA_RECORD_SCENE_ID,
    USERDATA_RECORD_X,
    USERDATA_RECORD_Y,
    USERDATA_RECORD_Z,
    USERDATA_LIFE,
    USERDATA_MANA,
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
        CUserData_cus_value_list (const CUserData* o, const char* d, Manip m, bool i1, bool i2, bool i3, bool i4, bool i5, bool i6, bool i7, bool i8, bool i9, bool i10, bool i11, bool i12, bool i13, bool i14, bool i15, bool i16, bool i17, bool i18, bool i19);
        CUserData_cus_value_list (const CUserData* o, const char* d, Manip m, CUserData_enum i1, CUserData_enum i2, CUserData_enum i3, CUserData_enum i4, CUserData_enum i5, CUserData_enum i6, CUserData_enum i7, CUserData_enum i8, CUserData_enum i9, CUserData_enum i10, CUserData_enum i11, CUserData_enum i12, CUserData_enum i13, CUserData_enum i14, CUserData_enum i15, CUserData_enum i16, CUserData_enum i17, CUserData_enum i18, CUserData_enum i19); 
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
        CUserData_cus_field_list (const CUserData* o, const char* d, Manip m, bool i1, bool i2, bool i3, bool i4, bool i5, bool i6, bool i7, bool i8, bool i9, bool i10, bool i11, bool i12, bool i13, bool i14, bool i15, bool i16, bool i17, bool i18, bool i19); 
        CUserData_cus_field_list (const CUserData* o, const char* d, Manip m, CUserData_enum i1, CUserData_enum i2, CUserData_enum i3, CUserData_enum i4, CUserData_enum i5, CUserData_enum i6, CUserData_enum i7, CUserData_enum i8, CUserData_enum i9, CUserData_enum i10, CUserData_enum i11, CUserData_enum i12, CUserData_enum i13, CUserData_enum i14, CUserData_enum i15, CUserData_enum i16, CUserData_enum i17, CUserData_enum i18, CUserData_enum i19); 
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
        CUserData_cus_equal_list (const CUserData* o, const char* d, const char* c, Manip m, bool i1, bool i2, bool i3, bool i4, bool i5, bool i6, bool i7, bool i8, bool i9, bool i10, bool i11, bool i12, bool i13, bool i14, bool i15, bool i16, bool i17, bool i18, bool i19); 
        CUserData_cus_equal_list (const CUserData* o, const char* d, const char* c, Manip m, CUserData_enum i1, CUserData_enum i2, CUserData_enum i3, CUserData_enum i4, CUserData_enum i5, CUserData_enum i6, CUserData_enum i7, CUserData_enum i8, CUserData_enum i9, CUserData_enum i10, CUserData_enum i11, CUserData_enum i12, CUserData_enum i13, CUserData_enum i14, CUserData_enum i15, CUserData_enum i16, CUserData_enum i17, CUserData_enum i18, CUserData_enum i19); 
        CUserData_cus_equal_list (const CUserData* o, const char* d, const char* c, Manip m, std::vector<bool> *i) :
        obj(o), include(i), del_vector(false), delim(d), comp(c), manip(m) { }
        };
    
        template <mysqlpp::sql_dummy_type dummy> int sql_compare_CUserData(const CUserData&, const CUserData&);
    
        struct CUserData {
        sql_bigint_unsigned id;
    sql_char name;
    sql_bigint_unsigned account_id;
    sql_int_unsigned role_type;
    sql_int_unsigned level;
    sql_bigint_unsigned exp;
    sql_float length;
    sql_float width;
    sql_float height;
    sql_int scene_id;
    sql_float pos_x;
    sql_float pos_y;
    sql_float pos_z;
    sql_int_unsigned record_scene_id;
    sql_float record_x;
    sql_float record_y;
    sql_float record_z;
    sql_int_unsigned life;
    sql_int_unsigned mana; 
        CUserData() : table_override_(0) { }
        CUserData(const mysqlpp::Row& row);
        void set(const mysqlpp::Row &row);
        CUserData(const sql_bigint_unsigned &p1, const sql_char &p2, const sql_bigint_unsigned &p3, const sql_int_unsigned &p4, const sql_int_unsigned &p5, const sql_bigint_unsigned &p6, const sql_float &p7, const sql_float &p8, const sql_float &p9, const sql_int &p10, const sql_float &p11, const sql_float &p12, const sql_float &p13, const sql_int_unsigned &p14, const sql_float &p15, const sql_float &p16, const sql_float &p17, const sql_int_unsigned &p18, const sql_int_unsigned &p19) : id (p1), name (p2), account_id (p3), role_type (p4), level (p5), exp (p6), length (p7), width (p8), height (p9), scene_id (p10), pos_x (p11), pos_y (p12), pos_z (p13), record_scene_id (p14), record_x (p15), record_y (p16), record_z (p17), life (p18), mana (p19), table_override_(0) {}
void set(const sql_bigint_unsigned &p1, const sql_char &p2, const sql_bigint_unsigned &p3, const sql_int_unsigned &p4, const sql_int_unsigned &p5, const sql_bigint_unsigned &p6, const sql_float &p7, const sql_float &p8, const sql_float &p9, const sql_int &p10, const sql_float &p11, const sql_float &p12, const sql_float &p13, const sql_int_unsigned &p14, const sql_float &p15, const sql_float &p16, const sql_float &p17, const sql_int_unsigned &p18, const sql_int_unsigned &p19) {
table_override_ = 0;
    id = p1;\
    name = p2;\
    account_id = p3;\
    role_type = p4;\
    level = p5;\
    exp = p6;\
    length = p7;\
    width = p8;\
    height = p9;\
    scene_id = p10;\
    pos_x = p11;\
    pos_y = p12;\
    pos_z = p13;\
    record_scene_id = p14;\
    record_x = p15;\
    record_y = p16;\
    record_z = p17;\
    life = p18;\
    mana = p19;\

}
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

        void set(const sql_bigint_unsigned p1) { \
        table_override_ = 0;

        id = p1;


        } \
        CUserData(const sql_bigint_unsigned p1) : id(p1), table_override_(0) {}
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
    
        CUserData_cus_value_list<mysqlpp::quote_type0> value_list(bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false, bool i9 = false, bool i10 = false, bool i11 = false, bool i12 = false, bool i13 = false, bool i14 = false, bool i15 = false, bool i16 = false, bool i17 = false, bool i18 = false, bool i19 = false) const
                { return value_list(",", mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15, i16, i17, i18, i19); }
        CUserData_cus_value_list<mysqlpp::quote_type0> value_list(CUserData_enum i1, CUserData_enum i2 = USERDATA_NULL, CUserData_enum i3 = USERDATA_NULL, CUserData_enum i4 = USERDATA_NULL, CUserData_enum i5 = USERDATA_NULL, CUserData_enum i6 = USERDATA_NULL, CUserData_enum i7 = USERDATA_NULL, CUserData_enum i8 = USERDATA_NULL, CUserData_enum i9 = USERDATA_NULL, CUserData_enum i10 = USERDATA_NULL, CUserData_enum i11 = USERDATA_NULL, CUserData_enum i12 = USERDATA_NULL, CUserData_enum i13 = USERDATA_NULL, CUserData_enum i14 = USERDATA_NULL, CUserData_enum i15 = USERDATA_NULL, CUserData_enum i16 = USERDATA_NULL, CUserData_enum i17 = USERDATA_NULL, CUserData_enum i18 = USERDATA_NULL, CUserData_enum i19 = USERDATA_NULL) const
                { return value_list(",", mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15, i16, i17, i18, i19); }
        CUserData_cus_value_list<mysqlpp::quote_type0> value_list(std::vector<bool> *i) const
                { return value_list(",", mysqlpp::quote, i); }
        CUserData_cus_value_list<mysqlpp::quote_type0> value_list(mysqlpp::sql_cmp_type sc) const
                { return value_list(",", mysqlpp::quote, sc); }
    
        CUserData_cus_value_list<mysqlpp::quote_type0> value_list(const char* d, bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false, bool i9 = false, bool i10 = false, bool i11 = false, bool i12 = false, bool i13 = false, bool i14 = false, bool i15 = false, bool i16 = false, bool i17 = false, bool i18 = false, bool i19 = false) const
                { return value_list(d, mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15, i16, i17, i18, i19); }
        CUserData_cus_value_list<mysqlpp::quote_type0> value_list(const char* d, CUserData_enum i1, CUserData_enum i2 = USERDATA_NULL, CUserData_enum i3 = USERDATA_NULL, CUserData_enum i4 = USERDATA_NULL, CUserData_enum i5 = USERDATA_NULL, CUserData_enum i6 = USERDATA_NULL, CUserData_enum i7 = USERDATA_NULL, CUserData_enum i8 = USERDATA_NULL, CUserData_enum i9 = USERDATA_NULL, CUserData_enum i10 = USERDATA_NULL, CUserData_enum i11 = USERDATA_NULL, CUserData_enum i12 = USERDATA_NULL, CUserData_enum i13 = USERDATA_NULL, CUserData_enum i14 = USERDATA_NULL, CUserData_enum i15 = USERDATA_NULL, CUserData_enum i16 = USERDATA_NULL, CUserData_enum i17 = USERDATA_NULL, CUserData_enum i18 = USERDATA_NULL, CUserData_enum i19 = USERDATA_NULL) const
                { return value_list(d, mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15, i16, i17, i18, i19); }
        CUserData_cus_value_list<mysqlpp::quote_type0> value_list(const char* d,
                std::vector<bool> *i) const
                { return value_list(d, mysqlpp::quote, i); }
        CUserData_cus_value_list<mysqlpp::quote_type0> value_list(const char* d,
                mysqlpp::sql_cmp_type sc) const
                { return value_list(d, mysqlpp::quote, sc); }
    
        template <class Manip>
        CUserData_cus_value_list<Manip> value_list(const char* d, Manip m,
                bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false, bool i9 = false, bool i10 = false, bool i11 = false, bool i12 = false, bool i13 = false, bool i14 = false, bool i15 = false, bool i16 = false, bool i17 = false, bool i18 = false, bool i19 = false) const;
        template <class Manip>
        CUserData_cus_value_list<Manip> value_list(const char* d, Manip m,
                CUserData_enum i1, CUserData_enum i2 = USERDATA_NULL, CUserData_enum i3 = USERDATA_NULL, CUserData_enum i4 = USERDATA_NULL, CUserData_enum i5 = USERDATA_NULL, CUserData_enum i6 = USERDATA_NULL, CUserData_enum i7 = USERDATA_NULL, CUserData_enum i8 = USERDATA_NULL, CUserData_enum i9 = USERDATA_NULL, CUserData_enum i10 = USERDATA_NULL, CUserData_enum i11 = USERDATA_NULL, CUserData_enum i12 = USERDATA_NULL, CUserData_enum i13 = USERDATA_NULL, CUserData_enum i14 = USERDATA_NULL, CUserData_enum i15 = USERDATA_NULL, CUserData_enum i16 = USERDATA_NULL, CUserData_enum i17 = USERDATA_NULL, CUserData_enum i18 = USERDATA_NULL, CUserData_enum i19 = USERDATA_NULL) const;
        template <class Manip>
        CUserData_cus_value_list<Manip> value_list(const char* d, Manip m,
                std::vector<bool>* i) const;
        template <class Manip>
        CUserData_cus_value_list<Manip> value_list(const char* d, Manip m, 
                mysqlpp::sql_cmp_type sc) const;
        /* cus field */
    
        CUserData_cus_field_list<mysqlpp::do_nothing_type0> field_list(bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false, bool i9 = false, bool i10 = false, bool i11 = false, bool i12 = false, bool i13 = false, bool i14 = false, bool i15 = false, bool i16 = false, bool i17 = false, bool i18 = false, bool i19 = false) const 
                { return field_list(",", mysqlpp::do_nothing, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15, i16, i17, i18, i19); }
        CUserData_cus_field_list<mysqlpp::do_nothing_type0> field_list(CUserData_enum i1, CUserData_enum i2 = USERDATA_NULL, CUserData_enum i3 = USERDATA_NULL, CUserData_enum i4 = USERDATA_NULL, CUserData_enum i5 = USERDATA_NULL, CUserData_enum i6 = USERDATA_NULL, CUserData_enum i7 = USERDATA_NULL, CUserData_enum i8 = USERDATA_NULL, CUserData_enum i9 = USERDATA_NULL, CUserData_enum i10 = USERDATA_NULL, CUserData_enum i11 = USERDATA_NULL, CUserData_enum i12 = USERDATA_NULL, CUserData_enum i13 = USERDATA_NULL, CUserData_enum i14 = USERDATA_NULL, CUserData_enum i15 = USERDATA_NULL, CUserData_enum i16 = USERDATA_NULL, CUserData_enum i17 = USERDATA_NULL, CUserData_enum i18 = USERDATA_NULL, CUserData_enum i19 = USERDATA_NULL) const
                { return field_list(",", mysqlpp::do_nothing, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15, i16, i17, i18, i19); }
        CUserData_cus_field_list<mysqlpp::do_nothing_type0> field_list(std::vector<bool> *i) const
                { return field_list(",", mysqlpp::do_nothing, i); }
        CUserData_cus_field_list<mysqlpp::do_nothing_type0> field_list(mysqlpp::sql_cmp_type sc) const
                { return field_list(",", mysqlpp::do_nothing, sc); }
    
        CUserData_cus_field_list<mysqlpp::do_nothing_type0> field_list(const char* d,
                bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false, bool i9 = false, bool i10 = false, bool i11 = false, bool i12 = false, bool i13 = false, bool i14 = false, bool i15 = false, bool i16 = false, bool i17 = false, bool i18 = false, bool i19 = false) const
                { return field_list(d, mysqlpp::do_nothing, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15, i16, i17, i18, i19); }
        CUserData_cus_field_list<mysqlpp::do_nothing_type0> field_list(const char* d,
                CUserData_enum i1, CUserData_enum i2 = USERDATA_NULL, CUserData_enum i3 = USERDATA_NULL, CUserData_enum i4 = USERDATA_NULL, CUserData_enum i5 = USERDATA_NULL, CUserData_enum i6 = USERDATA_NULL, CUserData_enum i7 = USERDATA_NULL, CUserData_enum i8 = USERDATA_NULL, CUserData_enum i9 = USERDATA_NULL, CUserData_enum i10 = USERDATA_NULL, CUserData_enum i11 = USERDATA_NULL, CUserData_enum i12 = USERDATA_NULL, CUserData_enum i13 = USERDATA_NULL, CUserData_enum i14 = USERDATA_NULL, CUserData_enum i15 = USERDATA_NULL, CUserData_enum i16 = USERDATA_NULL, CUserData_enum i17 = USERDATA_NULL, CUserData_enum i18 = USERDATA_NULL, CUserData_enum i19 = USERDATA_NULL) const
                { return field_list(d, mysqlpp::do_nothing, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15, i16, i17, i18, i19); }
        CUserData_cus_field_list<mysqlpp::do_nothing_type0> field_list(const char* d,
                std::vector<bool>* i) const
                { return field_list(d, mysqlpp::do_nothing, i); }
        CUserData_cus_field_list<mysqlpp::do_nothing_type0> field_list(const char* d,
                mysqlpp::sql_cmp_type sc) const
                { return field_list(d, mysqlpp::do_nothing, sc); }
    
        template <class Manip>
        CUserData_cus_field_list<Manip> field_list(const char* d, Manip m,
                bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false, bool i9 = false, bool i10 = false, bool i11 = false, bool i12 = false, bool i13 = false, bool i14 = false, bool i15 = false, bool i16 = false, bool i17 = false, bool i18 = false, bool i19 = false) const;
        template <class Manip>
        CUserData_cus_field_list<Manip> field_list(const char* d, Manip m,
                CUserData_enum i1, CUserData_enum i2 = USERDATA_NULL, CUserData_enum i3 = USERDATA_NULL, CUserData_enum i4 = USERDATA_NULL, CUserData_enum i5 = USERDATA_NULL, CUserData_enum i6 = USERDATA_NULL, CUserData_enum i7 = USERDATA_NULL, CUserData_enum i8 = USERDATA_NULL, CUserData_enum i9 = USERDATA_NULL, CUserData_enum i10 = USERDATA_NULL, CUserData_enum i11 = USERDATA_NULL, CUserData_enum i12 = USERDATA_NULL, CUserData_enum i13 = USERDATA_NULL, CUserData_enum i14 = USERDATA_NULL, CUserData_enum i15 = USERDATA_NULL, CUserData_enum i16 = USERDATA_NULL, CUserData_enum i17 = USERDATA_NULL, CUserData_enum i18 = USERDATA_NULL, CUserData_enum i19 = USERDATA_NULL) const;
        template <class Manip>
        CUserData_cus_field_list<Manip> field_list(const char* d, Manip m,
                std::vector<bool> *i) const;
        template <class Manip>
        CUserData_cus_field_list<Manip> field_list(const char* d, Manip m,
                mysqlpp::sql_cmp_type sc) const;
    
        /* cus equal */
    
        CUserData_cus_equal_list<mysqlpp::quote_type0> equal_list(bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false, bool i9 = false, bool i10 = false, bool i11 = false, bool i12 = false, bool i13 = false, bool i14 = false, bool i15 = false, bool i16 = false, bool i17 = false, bool i18 = false, bool i19 = false) const
                { return equal_list(",", " = ", mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15, i16, i17, i18, i19); }
        CUserData_cus_equal_list<mysqlpp::quote_type0> equal_list(CUserData_enum i1, CUserData_enum i2 = USERDATA_NULL, CUserData_enum i3 = USERDATA_NULL, CUserData_enum i4 = USERDATA_NULL, CUserData_enum i5 = USERDATA_NULL, CUserData_enum i6 = USERDATA_NULL, CUserData_enum i7 = USERDATA_NULL, CUserData_enum i8 = USERDATA_NULL, CUserData_enum i9 = USERDATA_NULL, CUserData_enum i10 = USERDATA_NULL, CUserData_enum i11 = USERDATA_NULL, CUserData_enum i12 = USERDATA_NULL, CUserData_enum i13 = USERDATA_NULL, CUserData_enum i14 = USERDATA_NULL, CUserData_enum i15 = USERDATA_NULL, CUserData_enum i16 = USERDATA_NULL, CUserData_enum i17 = USERDATA_NULL, CUserData_enum i18 = USERDATA_NULL, CUserData_enum i19 = USERDATA_NULL) const
                { return equal_list(",", " = ", mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15, i16, i17, i18, i19); }
        CUserData_cus_equal_list<mysqlpp::quote_type0> equal_list(std::vector<bool>* i) const
                { return equal_list(",", " = ", mysqlpp::quote, i); }
        CUserData_cus_equal_list<mysqlpp::quote_type0> equal_list(mysqlpp::sql_cmp_type sc) const
                { return equal_list(",", " = ", mysqlpp::quote, sc); }
    
        CUserData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d, bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false, bool i9 = false, bool i10 = false, bool i11 = false, bool i12 = false, bool i13 = false, bool i14 = false, bool i15 = false, bool i16 = false, bool i17 = false, bool i18 = false, bool i19 = false) const
                { return equal_list(d, " = ", mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15, i16, i17, i18, i19); }
        CUserData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d, CUserData_enum i1, CUserData_enum i2 = USERDATA_NULL, CUserData_enum i3 = USERDATA_NULL, CUserData_enum i4 = USERDATA_NULL, CUserData_enum i5 = USERDATA_NULL, CUserData_enum i6 = USERDATA_NULL, CUserData_enum i7 = USERDATA_NULL, CUserData_enum i8 = USERDATA_NULL, CUserData_enum i9 = USERDATA_NULL, CUserData_enum i10 = USERDATA_NULL, CUserData_enum i11 = USERDATA_NULL, CUserData_enum i12 = USERDATA_NULL, CUserData_enum i13 = USERDATA_NULL, CUserData_enum i14 = USERDATA_NULL, CUserData_enum i15 = USERDATA_NULL, CUserData_enum i16 = USERDATA_NULL, CUserData_enum i17 = USERDATA_NULL, CUserData_enum i18 = USERDATA_NULL, CUserData_enum i19 = USERDATA_NULL) const
                { return equal_list(d, " = ", mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15, i16, i17, i18, i19); }
        CUserData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d,
                std::vector<bool> *i) const
                { return equal_list(d, " = ", mysqlpp::quote, i); }
        CUserData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d,
                mysqlpp::sql_cmp_type sc) const
                { return equal_list(d, " = ", mysqlpp::quote, sc); }
    
        CUserData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d, const char* c,
                bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false, bool i9 = false, bool i10 = false, bool i11 = false, bool i12 = false, bool i13 = false, bool i14 = false, bool i15 = false, bool i16 = false, bool i17 = false, bool i18 = false, bool i19 = false) const
                { return equal_list(d, c, mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15, i16, i17, i18, i19); }
        CUserData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d, const char* c,
                CUserData_enum i1, CUserData_enum i2 = USERDATA_NULL, CUserData_enum i3 = USERDATA_NULL, CUserData_enum i4 = USERDATA_NULL, CUserData_enum i5 = USERDATA_NULL, CUserData_enum i6 = USERDATA_NULL, CUserData_enum i7 = USERDATA_NULL, CUserData_enum i8 = USERDATA_NULL, CUserData_enum i9 = USERDATA_NULL, CUserData_enum i10 = USERDATA_NULL, CUserData_enum i11 = USERDATA_NULL, CUserData_enum i12 = USERDATA_NULL, CUserData_enum i13 = USERDATA_NULL, CUserData_enum i14 = USERDATA_NULL, CUserData_enum i15 = USERDATA_NULL, CUserData_enum i16 = USERDATA_NULL, CUserData_enum i17 = USERDATA_NULL, CUserData_enum i18 = USERDATA_NULL, CUserData_enum i19 = USERDATA_NULL) const
                { return equal_list(d, c, mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15, i16, i17, i18, i19); }
        CUserData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d, const char* c,
                std::vector<bool> *i) const
                { return equal_list(d, c, mysqlpp::quote, i); }
        CUserData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d, const char* c,
                mysqlpp::sql_cmp_type sc) const
                { return equal_list(d, c, mysqlpp::quote, sc); }
    
        template <class Manip>
        CUserData_cus_equal_list<Manip> equal_list(const char* d, const char* c, Manip m, 
                            bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false, bool i9 = false, bool i10 = false, bool i11 = false, bool i12 = false, bool i13 = false, bool i14 = false, bool i15 = false, bool i16 = false, bool i17 = false, bool i18 = false, bool i19 = false) const;
        template <class Manip>
        CUserData_cus_equal_list<Manip> equal_list(const char* d, const char* c, Manip m, 
                            CUserData_enum i1, CUserData_enum i2 = USERDATA_NULL, CUserData_enum i3 = USERDATA_NULL, CUserData_enum i4 = USERDATA_NULL, CUserData_enum i5 = USERDATA_NULL, CUserData_enum i6 = USERDATA_NULL, CUserData_enum i7 = USERDATA_NULL, CUserData_enum i8 = USERDATA_NULL, CUserData_enum i9 = USERDATA_NULL, CUserData_enum i10 = USERDATA_NULL, CUserData_enum i11 = USERDATA_NULL, CUserData_enum i12 = USERDATA_NULL, CUserData_enum i13 = USERDATA_NULL, CUserData_enum i14 = USERDATA_NULL, CUserData_enum i15 = USERDATA_NULL, CUserData_enum i16 = USERDATA_NULL, CUserData_enum i17 = USERDATA_NULL, CUserData_enum i18 = USERDATA_NULL, CUserData_enum i19 = USERDATA_NULL) const;
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
            
        template <class Manip>
        CUserData_cus_value_list<Manip>::CUserData_cus_value_list
                (const CUserData* o, const char* d, Manip m, bool i1, bool i2, bool i3, bool i4, bool i5, bool i6, bool i7, bool i8, bool i9, bool i10, bool i11, bool i12, bool i13, bool i14, bool i15, bool i16, bool i17, bool i18, bool i19)
        {
            delim = d;
            manip = m;
            del_vector = true;
            obj = o;
            include = new std::vector<bool>(19, false);
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

        }
    
        template <class Manip>
        CUserData_cus_value_list<Manip>::CUserData_cus_value_list
                (const CUserData* o, const char* d, Manip m, CUserData_enum i1, CUserData_enum i2, CUserData_enum i3, CUserData_enum i4, CUserData_enum i5, CUserData_enum i6, CUserData_enum i7, CUserData_enum i8, CUserData_enum i9, CUserData_enum i10, CUserData_enum i11, CUserData_enum i12, CUserData_enum i13, CUserData_enum i14, CUserData_enum i15, CUserData_enum i16, CUserData_enum i17, CUserData_enum i18, CUserData_enum i19)
        {
            delim = d;
            manip = m;
            del_vector = true;
            obj = o;
            include = new std::vector<bool>(19, false);
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

        }
    
        template <class Manip>
        CUserData_cus_field_list<Manip>::CUserData_cus_field_list
                (const CUserData* o, const char* d, Manip m, bool i1, bool i2, bool i3, bool i4, bool i5, bool i6, bool i7, bool i8, bool i9, bool i10, bool i11, bool i12, bool i13, bool i14, bool i15, bool i16, bool i17, bool i18, bool i19)
        {
            delim = d;
            manip = m;
            del_vector = true;
            obj = o;
            include = new std::vector<bool>(19, false);
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

        }
    
        template <class Manip>
        CUserData_cus_field_list<Manip>::CUserData_cus_field_list
                (const CUserData* o, const char* d, Manip m, CUserData_enum i1, CUserData_enum i2, CUserData_enum i3, CUserData_enum i4, CUserData_enum i5, CUserData_enum i6, CUserData_enum i7, CUserData_enum i8, CUserData_enum i9, CUserData_enum i10, CUserData_enum i11, CUserData_enum i12, CUserData_enum i13, CUserData_enum i14, CUserData_enum i15, CUserData_enum i16, CUserData_enum i17, CUserData_enum i18, CUserData_enum i19)
        {
            delim = d;
            manip = m;
            del_vector = true;
            obj = o;
            include = new std::vector<bool>(19, false);
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

        }
    
        template <class Manip>
        CUserData_cus_equal_list<Manip>::CUserData_cus_equal_list
                (const CUserData* o, const char* d, const char* c, Manip m, bool i1, bool i2, bool i3, bool i4, bool i5, bool i6, bool i7, bool i8, bool i9, bool i10, bool i11, bool i12, bool i13, bool i14, bool i15, bool i16, bool i17, bool i18, bool i19)
        {
            delim = d;
            comp = c;
            manip = m;
            del_vector = true;
            obj = o;
            include = new std::vector<bool>(19, false);
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

        }
    
        template <class Manip>
        CUserData_cus_equal_list<Manip>::CUserData_cus_equal_list
                (const CUserData* o, const char* d, const char* c, Manip m, CUserData_enum i1, CUserData_enum i2, CUserData_enum i3, CUserData_enum i4, CUserData_enum i5, CUserData_enum i6, CUserData_enum i7, CUserData_enum i8, CUserData_enum i9, CUserData_enum i10, CUserData_enum i11, CUserData_enum i12, CUserData_enum i13, CUserData_enum i14, CUserData_enum i15, CUserData_enum i16, CUserData_enum i17, CUserData_enum i18, CUserData_enum i19)
        {
            delim = d;
            comp = c;
            manip = m;
            del_vector = true;
            obj = o;
            include = new std::vector<bool>(19, false);
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

        }
    
        template <class Manip>
        std::ostream& operator <<(std::ostream& s, const CUserData_value_list<Manip>& obj)
        {
        s << obj.manip << obj.obj->id << obj.delim;
    s << obj.manip << obj.obj->name << obj.delim;
    s << obj.manip << obj.obj->account_id << obj.delim;
    s << obj.manip << obj.obj->role_type << obj.delim;
    s << obj.manip << obj.obj->level << obj.delim;
    s << obj.manip << obj.obj->exp << obj.delim;
    s << obj.manip << obj.obj->length << obj.delim;
    s << obj.manip << obj.obj->width << obj.delim;
    s << obj.manip << obj.obj->height << obj.delim;
    s << obj.manip << obj.obj->scene_id << obj.delim;
    s << obj.manip << obj.obj->pos_x << obj.delim;
    s << obj.manip << obj.obj->pos_y << obj.delim;
    s << obj.manip << obj.obj->pos_z << obj.delim;
    s << obj.manip << obj.obj->record_scene_id << obj.delim;
    s << obj.manip << obj.obj->record_x << obj.delim;
    s << obj.manip << obj.obj->record_y << obj.delim;
    s << obj.manip << obj.obj->record_z << obj.delim;
    s << obj.manip << obj.obj->life << obj.delim;
    s << obj.manip << obj.obj->mana;
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
    s << obj.manip << '`' << obj.obj->names[18] << '`';
            return s;
        }
    
        template <class Manip>
        std::ostream& operator <<(std::ostream& s, const CUserData_equal_list<Manip>& obj)
        {
        s << '`' << obj.obj->names[0] << '`' << obj.comp << obj.manip << obj.obj->id << obj.delim;
    s << '`' << obj.obj->names[1] << '`' << obj.comp << obj.manip << obj.obj->name << obj.delim;
    s << '`' << obj.obj->names[2] << '`' << obj.comp << obj.manip << obj.obj->account_id << obj.delim;
    s << '`' << obj.obj->names[3] << '`' << obj.comp << obj.manip << obj.obj->role_type << obj.delim;
    s << '`' << obj.obj->names[4] << '`' << obj.comp << obj.manip << obj.obj->level << obj.delim;
    s << '`' << obj.obj->names[5] << '`' << obj.comp << obj.manip << obj.obj->exp << obj.delim;
    s << '`' << obj.obj->names[6] << '`' << obj.comp << obj.manip << obj.obj->length << obj.delim;
    s << '`' << obj.obj->names[7] << '`' << obj.comp << obj.manip << obj.obj->width << obj.delim;
    s << '`' << obj.obj->names[8] << '`' << obj.comp << obj.manip << obj.obj->height << obj.delim;
    s << '`' << obj.obj->names[9] << '`' << obj.comp << obj.manip << obj.obj->scene_id << obj.delim;
    s << '`' << obj.obj->names[10] << '`' << obj.comp << obj.manip << obj.obj->pos_x << obj.delim;
    s << '`' << obj.obj->names[11] << '`' << obj.comp << obj.manip << obj.obj->pos_y << obj.delim;
    s << '`' << obj.obj->names[12] << '`' << obj.comp << obj.manip << obj.obj->pos_z << obj.delim;
    s << '`' << obj.obj->names[13] << '`' << obj.comp << obj.manip << obj.obj->record_scene_id << obj.delim;
    s << '`' << obj.obj->names[14] << '`' << obj.comp << obj.manip << obj.obj->record_x << obj.delim;
    s << '`' << obj.obj->names[15] << '`' << obj.comp << obj.manip << obj.obj->record_y << obj.delim;
    s << '`' << obj.obj->names[16] << '`' << obj.comp << obj.manip << obj.obj->record_z << obj.delim;
    s << '`' << obj.obj->names[17] << '`' << obj.comp << obj.manip << obj.obj->life << obj.delim;
    s << '`' << obj.obj->names[18] << '`' << obj.comp << obj.manip << obj.obj->mana;
            return s;
        }
    
        template <class Manip>
        std::ostream& operator <<(std::ostream& s, const CUserData_cus_value_list<Manip>& obj)
        {
            bool before = false;
        if ((*obj.include)[0]) { 
      s << obj.manip << obj.obj->id;
      before = true; 
     } 
    if ((*obj.include)[1]) { 
      if (before) s << obj.delim;
      s << obj.manip << obj.obj->name;
      before = true; 
     } 
    if ((*obj.include)[2]) { 
      if (before) s << obj.delim;
      s << obj.manip << obj.obj->account_id;
      before = true; 
     } 
    if ((*obj.include)[3]) { 
      if (before) s << obj.delim;
      s << obj.manip << obj.obj->role_type;
      before = true; 
     } 
    if ((*obj.include)[4]) { 
      if (before) s << obj.delim;
      s << obj.manip << obj.obj->level;
      before = true; 
     } 
    if ((*obj.include)[5]) { 
      if (before) s << obj.delim;
      s << obj.manip << obj.obj->exp;
      before = true; 
     } 
    if ((*obj.include)[6]) { 
      if (before) s << obj.delim;
      s << obj.manip << obj.obj->length;
      before = true; 
     } 
    if ((*obj.include)[7]) { 
      if (before) s << obj.delim;
      s << obj.manip << obj.obj->width;
      before = true; 
     } 
    if ((*obj.include)[8]) { 
      if (before) s << obj.delim;
      s << obj.manip << obj.obj->height;
      before = true; 
     } 
    if ((*obj.include)[9]) { 
      if (before) s << obj.delim;
      s << obj.manip << obj.obj->scene_id;
      before = true; 
     } 
    if ((*obj.include)[10]) { 
      if (before) s << obj.delim;
      s << obj.manip << obj.obj->pos_x;
      before = true; 
     } 
    if ((*obj.include)[11]) { 
      if (before) s << obj.delim;
      s << obj.manip << obj.obj->pos_y;
      before = true; 
     } 
    if ((*obj.include)[12]) { 
      if (before) s << obj.delim;
      s << obj.manip << obj.obj->pos_z;
      before = true; 
     } 
    if ((*obj.include)[13]) { 
      if (before) s << obj.delim;
      s << obj.manip << obj.obj->record_scene_id;
      before = true; 
     } 
    if ((*obj.include)[14]) { 
      if (before) s << obj.delim;
      s << obj.manip << obj.obj->record_x;
      before = true; 
     } 
    if ((*obj.include)[15]) { 
      if (before) s << obj.delim;
      s << obj.manip << obj.obj->record_y;
      before = true; 
     } 
    if ((*obj.include)[16]) { 
      if (before) s << obj.delim;
      s << obj.manip << obj.obj->record_z;
      before = true; 
     } 
    if ((*obj.include)[17]) { 
      if (before) s << obj.delim;
      s << obj.manip << obj.obj->life;
      before = true; 
     } 
    if ((*obj.include)[18]) { 
      if (before) s << obj.delim;
      s << obj.manip << obj.obj->mana;
     } 

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
     } 

            return s;
        }
    
        template <class Manip>
        std::ostream& operator <<(std::ostream& s, const CUserData_cus_equal_list<Manip>& obj)
        {
            bool before = false;
        if ((*obj.include)[0]) { 
      s << '`' << obj.obj->names[0] << '`' << obj.comp         << obj.manip << obj.obj->id;
      before = true; 
     } 
    if ((*obj.include)[1]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[1] << '`' << obj.comp         << obj.manip << obj.obj->name;
      before = true; 
     } 
    if ((*obj.include)[2]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[2] << '`' << obj.comp         << obj.manip << obj.obj->account_id;
      before = true; 
     } 
    if ((*obj.include)[3]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[3] << '`' << obj.comp         << obj.manip << obj.obj->role_type;
      before = true; 
     } 
    if ((*obj.include)[4]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[4] << '`' << obj.comp         << obj.manip << obj.obj->level;
      before = true; 
     } 
    if ((*obj.include)[5]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[5] << '`' << obj.comp         << obj.manip << obj.obj->exp;
      before = true; 
     } 
    if ((*obj.include)[6]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[6] << '`' << obj.comp         << obj.manip << obj.obj->length;
      before = true; 
     } 
    if ((*obj.include)[7]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[7] << '`' << obj.comp         << obj.manip << obj.obj->width;
      before = true; 
     } 
    if ((*obj.include)[8]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[8] << '`' << obj.comp         << obj.manip << obj.obj->height;
      before = true; 
     } 
    if ((*obj.include)[9]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[9] << '`' << obj.comp         << obj.manip << obj.obj->scene_id;
      before = true; 
     } 
    if ((*obj.include)[10]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[10] << '`' << obj.comp         << obj.manip << obj.obj->pos_x;
      before = true; 
     } 
    if ((*obj.include)[11]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[11] << '`' << obj.comp         << obj.manip << obj.obj->pos_y;
      before = true; 
     } 
    if ((*obj.include)[12]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[12] << '`' << obj.comp         << obj.manip << obj.obj->pos_z;
      before = true; 
     } 
    if ((*obj.include)[13]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[13] << '`' << obj.comp         << obj.manip << obj.obj->record_scene_id;
      before = true; 
     } 
    if ((*obj.include)[14]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[14] << '`' << obj.comp         << obj.manip << obj.obj->record_x;
      before = true; 
     } 
    if ((*obj.include)[15]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[15] << '`' << obj.comp         << obj.manip << obj.obj->record_y;
      before = true; 
     } 
    if ((*obj.include)[16]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[16] << '`' << obj.comp         << obj.manip << obj.obj->record_z;
      before = true; 
     } 
    if ((*obj.include)[17]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[17] << '`' << obj.comp         << obj.manip << obj.obj->life;
      before = true; 
     } 
    if ((*obj.include)[18]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[18] << '`' << obj.comp         << obj.manip << obj.obj->mana;
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
                bool i1, bool i2, bool i3, bool i4, bool i5, bool i6, bool i7, bool i8, bool i9, bool i10, bool i11, bool i12, bool i13, bool i14, bool i15, bool i16, bool i17, bool i18, bool i19) const
                { return CUserData_cus_value_list<Manip> (this, d, m, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15, i16, i17, i18, i19); }
    
        template <class Manip>
        inline CUserData_cus_field_list<Manip> CUserData::field_list(const char* d, Manip m,
                bool i1, bool i2, bool i3, bool i4, bool i5, bool i6, bool i7, bool i8, bool i9, bool i10, bool i11, bool i12, bool i13, bool i14, bool i15, bool i16, bool i17, bool i18, bool i19) const
                { return CUserData_cus_field_list<Manip> (this, d, m, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15, i16, i17, i18, i19); }
    
        template <class Manip>
        inline CUserData_cus_equal_list<Manip> CUserData::equal_list(const char* d, const char* c, Manip m,
                bool i1, bool i2, bool i3, bool i4, bool i5, bool i6, bool i7, bool i8, bool i9, bool i10, bool i11, bool i12, bool i13, bool i14, bool i15, bool i16, bool i17, bool i18, bool i19) const
                { return CUserData_cus_equal_list<Manip> (this, d, c, m, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15, i16, i17, i18, i19); } 
    
        template <class Manip>
        inline CUserData_cus_value_list<Manip> CUserData::value_list(const char* d, Manip m,
                CUserData_enum i1, CUserData_enum i2, CUserData_enum i3, CUserData_enum i4, CUserData_enum i5, CUserData_enum i6, CUserData_enum i7, CUserData_enum i8, CUserData_enum i9, CUserData_enum i10, CUserData_enum i11, CUserData_enum i12, CUserData_enum i13, CUserData_enum i14, CUserData_enum i15, CUserData_enum i16, CUserData_enum i17, CUserData_enum i18, CUserData_enum i19) const
                { return CUserData_cus_value_list<Manip> (this, d, m, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15, i16, i17, i18, i19); } 
    
        template <class Manip>
        inline CUserData_cus_field_list<Manip> CUserData::field_list(const char* d, Manip m,
                CUserData_enum i1, CUserData_enum i2, CUserData_enum i3, CUserData_enum i4, CUserData_enum i5, CUserData_enum i6, CUserData_enum i7, CUserData_enum i8, CUserData_enum i9, CUserData_enum i10, CUserData_enum i11, CUserData_enum i12, CUserData_enum i13, CUserData_enum i14, CUserData_enum i15, CUserData_enum i16, CUserData_enum i17, CUserData_enum i18, CUserData_enum i19) const
                { return CUserData_cus_field_list<Manip> (this, d, m, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15, i16, i17, i18, i19); } 
    
        template <class Manip>
        inline CUserData_cus_equal_list<Manip> CUserData::equal_list(const char* d, const char* c, Manip m, 
                CUserData_enum i1, CUserData_enum i2, CUserData_enum i3, CUserData_enum i4, CUserData_enum i5, CUserData_enum i6, CUserData_enum i7, CUserData_enum i8, CUserData_enum i9, CUserData_enum i10, CUserData_enum i11, CUserData_enum i12, CUserData_enum i13, CUserData_enum i14, CUserData_enum i15, CUserData_enum i16, CUserData_enum i17, CUserData_enum i18, CUserData_enum i19) const
                { return CUserData_cus_equal_list<Manip> (this, d, c, m, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15, i16, i17, i18, i19); } 
    
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
                { return value_list(d, m, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true); }
    
        template <class Manip>
        inline CUserData_cus_field_list<Manip> 
        CUserData::field_list(const char* d, Manip m, mysqlpp::sql_cmp_type /*sc*/) const
                { return field_list(d, m, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true); }
    
        template <class Manip>
        inline CUserData_cus_equal_list<Manip> 
        CUserData::equal_list(const char* d, const char* c, Manip m, mysqlpp::sql_cmp_type /*sc*/) const
                { return equal_list(d, c, m, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true); }
    
        template <mysqlpp::sql_dummy_type dummy>
        void populate_CUserData(CUserData *s, const mysqlpp::Row &row)
        {
            mysqlpp::NoExceptions ignore_schema_mismatches(row);
        s->id = row["id"].conv(sql_bigint_unsigned());
    s->name = row["name"].conv(sql_char());
    s->account_id = row["account_id"].conv(sql_bigint_unsigned());
    s->role_type = row["role_type"].conv(sql_int_unsigned());
    s->level = row["level"].conv(sql_int_unsigned());
    s->exp = row["exp"].conv(sql_bigint_unsigned());
    s->length = row["length"].conv(sql_float());
    s->width = row["width"].conv(sql_float());
    s->height = row["height"].conv(sql_float());
    s->scene_id = row["scene_id"].conv(sql_int());
    s->pos_x = row["pos_x"].conv(sql_float());
    s->pos_y = row["pos_y"].conv(sql_float());
    s->pos_z = row["pos_z"].conv(sql_float());
    s->record_scene_id = row["record_scene_id"].conv(sql_int_unsigned());
    s->record_x = row["record_x"].conv(sql_float());
    s->record_y = row["record_y"].conv(sql_float());
    s->record_z = row["record_z"].conv(sql_float());
    s->life = row["life"].conv(sql_int_unsigned());
    s->mana = row["mana"].conv(sql_int_unsigned());
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
    cmp = mysqlpp::sql_cmp(x.id, y.id ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.name, y.name ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.account_id, y.account_id ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.role_type, y.role_type ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.level, y.level ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.exp, y.exp ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.length, y.length ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.width, y.width ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.height, y.height ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.scene_id, y.scene_id ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.pos_x, y.pos_x ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.pos_y, y.pos_y ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.pos_z, y.pos_z ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.record_scene_id, y.record_scene_id ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.record_x, y.record_x ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.record_y, y.record_y ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.record_z, y.record_z ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.life, y.life ); \
    if (cmp) return cmp; \
    return mysqlpp::sql_cmp(x.mana, y.mana); 
 } 
 template <mysqlpp::sql_dummy_type dummy> 
 int compare (const CUserData &x, const CUserData &y) { 
     int cmp; \
    cmp = mysqlpp::sql_cmp(x.id, y.id ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.name, y.name ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.account_id, y.account_id ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.role_type, y.role_type ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.level, y.level ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.exp, y.exp ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.length, y.length ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.width, y.width ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.height, y.height ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.scene_id, y.scene_id ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.pos_x, y.pos_x ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.pos_y, y.pos_y ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.pos_z, y.pos_z ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.record_scene_id, y.record_scene_id ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.record_x, y.record_x ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.record_y, y.record_y ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.record_z, y.record_z ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.life, y.life ); \
    if (cmp) return cmp; \
    return mysqlpp::sql_cmp(x.mana, y.mana); 
 }

#endif	//end of define _USER_DATA_H_