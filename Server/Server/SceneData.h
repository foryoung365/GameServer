////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author: 	Fu Yan
// Created: 	2015-08-17
// Describe: 	Specailized SQL structure of table gs_scene, 
//				generate by genSsqls.py, !!!DO NOT EDIT!!!
////////////////////////////////////////////////////////////////////////
#ifndef _SCENE_DATA_H_
#define _SCENE_DATA_H_

#include <mysql++.h>
#include <ssqls.h>

using namespace mysqlpp;

struct CSceneData; 
    
        enum CSceneData_enum { 
        SCENEDATA_ID,
    SCENEDATA_NAME,
    SCENEDATA_MAPDOC,
    SCENEDATA_TYPE,
    SCENEDATA_TYPE2,
    SCENEDATA_SORT,
    SCENEDATA_PORTAL0_X,
    SCENEDATA_PORTAL0_Y,
    SCENEDATA_PORTAL0_Z,
    SCENEDATA_REBORN_MAP,
    SCENEDATA_LINK_MAP,
    SCENEDATA_LINK_X,
    SCENEDATA_LINK_Y,
    SCENEDATA_LINK_Z,
    SCENEDATA_FLAG,
        SCENEDATA_NULL 
        }; 
    
        template <class Manip>
        class CSceneData_value_list { 
        public: 
        const CSceneData* obj;
        const char* delim;
        Manip manip;
        public: 
        CSceneData_value_list (const CSceneData* o, const char* d, Manip m) :
        obj(o), delim(d), manip(m) { } 
        };
    
        template <class Manip>
        class CSceneData_field_list {
        public: 
        const CSceneData* obj; 
        const char* delim;
        Manip manip;
        public: 
        CSceneData_field_list (const CSceneData* o, const char* d, Manip m) :
        obj(o), delim(d), manip(m) { } 
        };
    
        template <class Manip>
        class CSceneData_equal_list { 
        public: 
        const CSceneData* obj;
        const char* delim;
        const char* comp;
        Manip manip;
        public: 
        CSceneData_equal_list (const CSceneData* o, const char* d, const char* c, Manip m) :
        obj(o), delim(d), comp(c), manip(m) { }
        };
    
        template <class Manip>
        class CSceneData_cus_value_list {
        public:
        const CSceneData* obj;
        std::vector<bool> *include;
        bool del_vector;
        const char* delim;
        Manip manip;
        public: 
        ~CSceneData_cus_value_list () {if (del_vector) delete include;} 
        CSceneData_cus_value_list (const CSceneData* o, const char* d, Manip m, bool i1, bool i2, bool i3, bool i4, bool i5, bool i6, bool i7, bool i8, bool i9, bool i10, bool i11, bool i12, bool i13, bool i14, bool i15);
        CSceneData_cus_value_list (const CSceneData* o, const char* d, Manip m, CSceneData_enum i1, CSceneData_enum i2, CSceneData_enum i3, CSceneData_enum i4, CSceneData_enum i5, CSceneData_enum i6, CSceneData_enum i7, CSceneData_enum i8, CSceneData_enum i9, CSceneData_enum i10, CSceneData_enum i11, CSceneData_enum i12, CSceneData_enum i13, CSceneData_enum i14, CSceneData_enum i15); 
        CSceneData_cus_value_list (const CSceneData* o, const char* d, Manip m ,std::vector<bool>* i) :
        obj(o), include(i), del_vector(false), delim(d), manip(m) { }
        };
    
        template <class Manip>
        class CSceneData_cus_field_list { 
        public:
        const CSceneData* obj; 
        std::vector<bool> *include; 
        bool del_vector; 
        const char* delim;
        Manip manip;
        public: 
        ~CSceneData_cus_field_list () {if (del_vector) delete include;} 
        CSceneData_cus_field_list (const CSceneData* o, const char* d, Manip m, bool i1, bool i2, bool i3, bool i4, bool i5, bool i6, bool i7, bool i8, bool i9, bool i10, bool i11, bool i12, bool i13, bool i14, bool i15); 
        CSceneData_cus_field_list (const CSceneData* o, const char* d, Manip m, CSceneData_enum i1, CSceneData_enum i2, CSceneData_enum i3, CSceneData_enum i4, CSceneData_enum i5, CSceneData_enum i6, CSceneData_enum i7, CSceneData_enum i8, CSceneData_enum i9, CSceneData_enum i10, CSceneData_enum i11, CSceneData_enum i12, CSceneData_enum i13, CSceneData_enum i14, CSceneData_enum i15); 
        CSceneData_cus_field_list (const CSceneData* o, const char* d, Manip m, std::vector<bool> *i) :
        obj(o), include(i), del_vector(false), delim(d), manip(m) { }
        };
    
        template <class Manip>
        class CSceneData_cus_equal_list {
        public:
        const CSceneData* obj;
        std::vector<bool> *include;
        bool del_vector;
        const char* delim;
        const char* comp;
        Manip manip;
        public:
        ~CSceneData_cus_equal_list () {if (del_vector) delete include;}
        CSceneData_cus_equal_list (const CSceneData* o, const char* d, const char* c, Manip m, bool i1, bool i2, bool i3, bool i4, bool i5, bool i6, bool i7, bool i8, bool i9, bool i10, bool i11, bool i12, bool i13, bool i14, bool i15); 
        CSceneData_cus_equal_list (const CSceneData* o, const char* d, const char* c, Manip m, CSceneData_enum i1, CSceneData_enum i2, CSceneData_enum i3, CSceneData_enum i4, CSceneData_enum i5, CSceneData_enum i6, CSceneData_enum i7, CSceneData_enum i8, CSceneData_enum i9, CSceneData_enum i10, CSceneData_enum i11, CSceneData_enum i12, CSceneData_enum i13, CSceneData_enum i14, CSceneData_enum i15); 
        CSceneData_cus_equal_list (const CSceneData* o, const char* d, const char* c, Manip m, std::vector<bool> *i) :
        obj(o), include(i), del_vector(false), delim(d), comp(c), manip(m) { }
        };
    
        template <mysqlpp::sql_dummy_type dummy> int sql_compare_CSceneData(const CSceneData&, const CSceneData&);
    
        struct CSceneData {
        sql_int_unsigned id;
    sql_char_null name;
    sql_int_unsigned mapdoc;
    sql_bigint_unsigned type;
    sql_bigint_unsigned type2;
    sql_int_unsigned sort;
    sql_float portal0_x;
    sql_float portal0_y;
    sql_float portal0_z;
    sql_int_unsigned_null reborn_map;
    sql_int_unsigned link_map;
    sql_float link_x;
    sql_float link_y;
    sql_float link_z;
    sql_int_unsigned flag; 
        CSceneData() : table_override_(0) { }
        CSceneData(const mysqlpp::Row& row);
        void set(const mysqlpp::Row &row);
        CSceneData(const sql_int_unsigned &p1, const sql_char_null &p2, const sql_int_unsigned &p3, const sql_bigint_unsigned &p4, const sql_bigint_unsigned &p5, const sql_int_unsigned &p6, const sql_float &p7, const sql_float &p8, const sql_float &p9, const sql_int_unsigned_null &p10, const sql_int_unsigned &p11, const sql_float &p12, const sql_float &p13, const sql_float &p14, const sql_int_unsigned &p15) : id (p1), name (p2), mapdoc (p3), type (p4), type2 (p5), sort (p6), portal0_x (p7), portal0_y (p8), portal0_z (p9), reborn_map (p10), link_map (p11), link_x (p12), link_y (p13), link_z (p14), flag (p15), table_override_(0) {}
void set(const sql_int_unsigned &p1, const sql_char_null &p2, const sql_int_unsigned &p3, const sql_bigint_unsigned &p4, const sql_bigint_unsigned &p5, const sql_int_unsigned &p6, const sql_float &p7, const sql_float &p8, const sql_float &p9, const sql_int_unsigned_null &p10, const sql_int_unsigned &p11, const sql_float &p12, const sql_float &p13, const sql_float &p14, const sql_int_unsigned &p15) {
table_override_ = 0;
    id = p1;\
    name = p2;\
    mapdoc = p3;\
    type = p4;\
    type2 = p5;\
    sort = p6;\
    portal0_x = p7;\
    portal0_y = p8;\
    portal0_z = p9;\
    reborn_map = p10;\
    link_map = p11;\
    link_x = p12;\
    link_y = p13;\
    link_z = p14;\
    flag = p15;\

}
bool operator == (const CSceneData &other) const 
 {return sql_compare_CSceneData<mysqlpp::sql_dummy>(*this,other) == 0;} 
 bool operator != (const CSceneData &other) const 
 {return sql_compare_CSceneData<mysqlpp::sql_dummy>(*this,other) != 0;} 
 bool operator > (const CSceneData &other) const 
 {return sql_compare_CSceneData<mysqlpp::sql_dummy>(*this,other) >  0;} 
 bool operator < (const CSceneData &other) const 
 {return sql_compare_CSceneData<mysqlpp::sql_dummy>(*this,other) <  0;} 
 bool operator >= (const CSceneData &other) const 
 {return sql_compare_CSceneData<mysqlpp::sql_dummy>(*this,other) >= 0;} 
 bool operator <= (const CSceneData &other) const 
 {return sql_compare_CSceneData<mysqlpp::sql_dummy>(*this,other) <= 0;} 
 int cmp (const CSceneData &other) const 
 {return sql_compare_CSceneData<mysqlpp::sql_dummy>(*this,other);} 
 int compare (const CSceneData &other) const 
 {return sql_compare_CSceneData<mysqlpp::sql_dummy>(*this,other);}

        void set(const sql_int_unsigned p1) { \
        table_override_ = 0;

        id = p1;


        } \
        CSceneData(const sql_int_unsigned p1) : id(p1), table_override_(0) {}
        static const char* names[];
        static void table(const char* t) { table_ = t; }
        const char* table() const
                { return table_override_ ? table_override_ : CSceneData::table_; }
        void instance_table(const char* t) { table_override_ = t; }
    
        CSceneData_value_list<mysqlpp::quote_type0> value_list() const {
            return value_list(",", mysqlpp::quote);}
        CSceneData_value_list<mysqlpp::quote_type0> value_list(const char* d) const {
            return value_list(d, mysqlpp::quote);}
        template <class Manip>
        CSceneData_value_list<Manip> value_list(const char* d, Manip m) const;
    
        CSceneData_field_list<mysqlpp::do_nothing_type0> field_list() const {
            return field_list(",", mysqlpp::do_nothing);}
        CSceneData_field_list<mysqlpp::do_nothing_type0> field_list(const char* d) const {
            return field_list(d, mysqlpp::do_nothing);}
        template <class Manip>
        CSceneData_field_list<Manip> field_list(const char* d, Manip m) const;
    
        CSceneData_equal_list<mysqlpp::quote_type0> equal_list(const char* d = ",",
                const char* c = " = ") const
                { return equal_list(d, c, mysqlpp::quote); }
        template <class Manip>
        CSceneData_equal_list<Manip> equal_list(const char* d, const char* c, Manip m) const;
    
        /* cus_data */
    
        CSceneData_cus_value_list<mysqlpp::quote_type0> value_list(bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false, bool i9 = false, bool i10 = false, bool i11 = false, bool i12 = false, bool i13 = false, bool i14 = false, bool i15 = false) const
                { return value_list(",", mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15); }
        CSceneData_cus_value_list<mysqlpp::quote_type0> value_list(CSceneData_enum i1, CSceneData_enum i2 = SCENEDATA_NULL, CSceneData_enum i3 = SCENEDATA_NULL, CSceneData_enum i4 = SCENEDATA_NULL, CSceneData_enum i5 = SCENEDATA_NULL, CSceneData_enum i6 = SCENEDATA_NULL, CSceneData_enum i7 = SCENEDATA_NULL, CSceneData_enum i8 = SCENEDATA_NULL, CSceneData_enum i9 = SCENEDATA_NULL, CSceneData_enum i10 = SCENEDATA_NULL, CSceneData_enum i11 = SCENEDATA_NULL, CSceneData_enum i12 = SCENEDATA_NULL, CSceneData_enum i13 = SCENEDATA_NULL, CSceneData_enum i14 = SCENEDATA_NULL, CSceneData_enum i15 = SCENEDATA_NULL) const
                { return value_list(",", mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15); }
        CSceneData_cus_value_list<mysqlpp::quote_type0> value_list(std::vector<bool> *i) const
                { return value_list(",", mysqlpp::quote, i); }
        CSceneData_cus_value_list<mysqlpp::quote_type0> value_list(mysqlpp::sql_cmp_type sc) const
                { return value_list(",", mysqlpp::quote, sc); }
    
        CSceneData_cus_value_list<mysqlpp::quote_type0> value_list(const char* d, bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false, bool i9 = false, bool i10 = false, bool i11 = false, bool i12 = false, bool i13 = false, bool i14 = false, bool i15 = false) const
                { return value_list(d, mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15); }
        CSceneData_cus_value_list<mysqlpp::quote_type0> value_list(const char* d, CSceneData_enum i1, CSceneData_enum i2 = SCENEDATA_NULL, CSceneData_enum i3 = SCENEDATA_NULL, CSceneData_enum i4 = SCENEDATA_NULL, CSceneData_enum i5 = SCENEDATA_NULL, CSceneData_enum i6 = SCENEDATA_NULL, CSceneData_enum i7 = SCENEDATA_NULL, CSceneData_enum i8 = SCENEDATA_NULL, CSceneData_enum i9 = SCENEDATA_NULL, CSceneData_enum i10 = SCENEDATA_NULL, CSceneData_enum i11 = SCENEDATA_NULL, CSceneData_enum i12 = SCENEDATA_NULL, CSceneData_enum i13 = SCENEDATA_NULL, CSceneData_enum i14 = SCENEDATA_NULL, CSceneData_enum i15 = SCENEDATA_NULL) const
                { return value_list(d, mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15); }
        CSceneData_cus_value_list<mysqlpp::quote_type0> value_list(const char* d,
                std::vector<bool> *i) const
                { return value_list(d, mysqlpp::quote, i); }
        CSceneData_cus_value_list<mysqlpp::quote_type0> value_list(const char* d,
                mysqlpp::sql_cmp_type sc) const
                { return value_list(d, mysqlpp::quote, sc); }
    
        template <class Manip>
        CSceneData_cus_value_list<Manip> value_list(const char* d, Manip m,
                bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false, bool i9 = false, bool i10 = false, bool i11 = false, bool i12 = false, bool i13 = false, bool i14 = false, bool i15 = false) const;
        template <class Manip>
        CSceneData_cus_value_list<Manip> value_list(const char* d, Manip m,
                CSceneData_enum i1, CSceneData_enum i2 = SCENEDATA_NULL, CSceneData_enum i3 = SCENEDATA_NULL, CSceneData_enum i4 = SCENEDATA_NULL, CSceneData_enum i5 = SCENEDATA_NULL, CSceneData_enum i6 = SCENEDATA_NULL, CSceneData_enum i7 = SCENEDATA_NULL, CSceneData_enum i8 = SCENEDATA_NULL, CSceneData_enum i9 = SCENEDATA_NULL, CSceneData_enum i10 = SCENEDATA_NULL, CSceneData_enum i11 = SCENEDATA_NULL, CSceneData_enum i12 = SCENEDATA_NULL, CSceneData_enum i13 = SCENEDATA_NULL, CSceneData_enum i14 = SCENEDATA_NULL, CSceneData_enum i15 = SCENEDATA_NULL) const;
        template <class Manip>
        CSceneData_cus_value_list<Manip> value_list(const char* d, Manip m,
                std::vector<bool>* i) const;
        template <class Manip>
        CSceneData_cus_value_list<Manip> value_list(const char* d, Manip m, 
                mysqlpp::sql_cmp_type sc) const;
        /* cus field */
    
        CSceneData_cus_field_list<mysqlpp::do_nothing_type0> field_list(bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false, bool i9 = false, bool i10 = false, bool i11 = false, bool i12 = false, bool i13 = false, bool i14 = false, bool i15 = false) const 
                { return field_list(",", mysqlpp::do_nothing, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15); }
        CSceneData_cus_field_list<mysqlpp::do_nothing_type0> field_list(CSceneData_enum i1, CSceneData_enum i2 = SCENEDATA_NULL, CSceneData_enum i3 = SCENEDATA_NULL, CSceneData_enum i4 = SCENEDATA_NULL, CSceneData_enum i5 = SCENEDATA_NULL, CSceneData_enum i6 = SCENEDATA_NULL, CSceneData_enum i7 = SCENEDATA_NULL, CSceneData_enum i8 = SCENEDATA_NULL, CSceneData_enum i9 = SCENEDATA_NULL, CSceneData_enum i10 = SCENEDATA_NULL, CSceneData_enum i11 = SCENEDATA_NULL, CSceneData_enum i12 = SCENEDATA_NULL, CSceneData_enum i13 = SCENEDATA_NULL, CSceneData_enum i14 = SCENEDATA_NULL, CSceneData_enum i15 = SCENEDATA_NULL) const
                { return field_list(",", mysqlpp::do_nothing, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15); }
        CSceneData_cus_field_list<mysqlpp::do_nothing_type0> field_list(std::vector<bool> *i) const
                { return field_list(",", mysqlpp::do_nothing, i); }
        CSceneData_cus_field_list<mysqlpp::do_nothing_type0> field_list(mysqlpp::sql_cmp_type sc) const
                { return field_list(",", mysqlpp::do_nothing, sc); }
    
        CSceneData_cus_field_list<mysqlpp::do_nothing_type0> field_list(const char* d,
                bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false, bool i9 = false, bool i10 = false, bool i11 = false, bool i12 = false, bool i13 = false, bool i14 = false, bool i15 = false) const
                { return field_list(d, mysqlpp::do_nothing, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15); }
        CSceneData_cus_field_list<mysqlpp::do_nothing_type0> field_list(const char* d,
                CSceneData_enum i1, CSceneData_enum i2 = SCENEDATA_NULL, CSceneData_enum i3 = SCENEDATA_NULL, CSceneData_enum i4 = SCENEDATA_NULL, CSceneData_enum i5 = SCENEDATA_NULL, CSceneData_enum i6 = SCENEDATA_NULL, CSceneData_enum i7 = SCENEDATA_NULL, CSceneData_enum i8 = SCENEDATA_NULL, CSceneData_enum i9 = SCENEDATA_NULL, CSceneData_enum i10 = SCENEDATA_NULL, CSceneData_enum i11 = SCENEDATA_NULL, CSceneData_enum i12 = SCENEDATA_NULL, CSceneData_enum i13 = SCENEDATA_NULL, CSceneData_enum i14 = SCENEDATA_NULL, CSceneData_enum i15 = SCENEDATA_NULL) const
                { return field_list(d, mysqlpp::do_nothing, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15); }
        CSceneData_cus_field_list<mysqlpp::do_nothing_type0> field_list(const char* d,
                std::vector<bool>* i) const
                { return field_list(d, mysqlpp::do_nothing, i); }
        CSceneData_cus_field_list<mysqlpp::do_nothing_type0> field_list(const char* d,
                mysqlpp::sql_cmp_type sc) const
                { return field_list(d, mysqlpp::do_nothing, sc); }
    
        template <class Manip>
        CSceneData_cus_field_list<Manip> field_list(const char* d, Manip m,
                bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false, bool i9 = false, bool i10 = false, bool i11 = false, bool i12 = false, bool i13 = false, bool i14 = false, bool i15 = false) const;
        template <class Manip>
        CSceneData_cus_field_list<Manip> field_list(const char* d, Manip m,
                CSceneData_enum i1, CSceneData_enum i2 = SCENEDATA_NULL, CSceneData_enum i3 = SCENEDATA_NULL, CSceneData_enum i4 = SCENEDATA_NULL, CSceneData_enum i5 = SCENEDATA_NULL, CSceneData_enum i6 = SCENEDATA_NULL, CSceneData_enum i7 = SCENEDATA_NULL, CSceneData_enum i8 = SCENEDATA_NULL, CSceneData_enum i9 = SCENEDATA_NULL, CSceneData_enum i10 = SCENEDATA_NULL, CSceneData_enum i11 = SCENEDATA_NULL, CSceneData_enum i12 = SCENEDATA_NULL, CSceneData_enum i13 = SCENEDATA_NULL, CSceneData_enum i14 = SCENEDATA_NULL, CSceneData_enum i15 = SCENEDATA_NULL) const;
        template <class Manip>
        CSceneData_cus_field_list<Manip> field_list(const char* d, Manip m,
                std::vector<bool> *i) const;
        template <class Manip>
        CSceneData_cus_field_list<Manip> field_list(const char* d, Manip m,
                mysqlpp::sql_cmp_type sc) const;
    
        /* cus equal */
    
        CSceneData_cus_equal_list<mysqlpp::quote_type0> equal_list(bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false, bool i9 = false, bool i10 = false, bool i11 = false, bool i12 = false, bool i13 = false, bool i14 = false, bool i15 = false) const
                { return equal_list(",", " = ", mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15); }
        CSceneData_cus_equal_list<mysqlpp::quote_type0> equal_list(CSceneData_enum i1, CSceneData_enum i2 = SCENEDATA_NULL, CSceneData_enum i3 = SCENEDATA_NULL, CSceneData_enum i4 = SCENEDATA_NULL, CSceneData_enum i5 = SCENEDATA_NULL, CSceneData_enum i6 = SCENEDATA_NULL, CSceneData_enum i7 = SCENEDATA_NULL, CSceneData_enum i8 = SCENEDATA_NULL, CSceneData_enum i9 = SCENEDATA_NULL, CSceneData_enum i10 = SCENEDATA_NULL, CSceneData_enum i11 = SCENEDATA_NULL, CSceneData_enum i12 = SCENEDATA_NULL, CSceneData_enum i13 = SCENEDATA_NULL, CSceneData_enum i14 = SCENEDATA_NULL, CSceneData_enum i15 = SCENEDATA_NULL) const
                { return equal_list(",", " = ", mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15); }
        CSceneData_cus_equal_list<mysqlpp::quote_type0> equal_list(std::vector<bool>* i) const
                { return equal_list(",", " = ", mysqlpp::quote, i); }
        CSceneData_cus_equal_list<mysqlpp::quote_type0> equal_list(mysqlpp::sql_cmp_type sc) const
                { return equal_list(",", " = ", mysqlpp::quote, sc); }
    
        CSceneData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d, bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false, bool i9 = false, bool i10 = false, bool i11 = false, bool i12 = false, bool i13 = false, bool i14 = false, bool i15 = false) const
                { return equal_list(d, " = ", mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15); }
        CSceneData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d, CSceneData_enum i1, CSceneData_enum i2 = SCENEDATA_NULL, CSceneData_enum i3 = SCENEDATA_NULL, CSceneData_enum i4 = SCENEDATA_NULL, CSceneData_enum i5 = SCENEDATA_NULL, CSceneData_enum i6 = SCENEDATA_NULL, CSceneData_enum i7 = SCENEDATA_NULL, CSceneData_enum i8 = SCENEDATA_NULL, CSceneData_enum i9 = SCENEDATA_NULL, CSceneData_enum i10 = SCENEDATA_NULL, CSceneData_enum i11 = SCENEDATA_NULL, CSceneData_enum i12 = SCENEDATA_NULL, CSceneData_enum i13 = SCENEDATA_NULL, CSceneData_enum i14 = SCENEDATA_NULL, CSceneData_enum i15 = SCENEDATA_NULL) const
                { return equal_list(d, " = ", mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15); }
        CSceneData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d,
                std::vector<bool> *i) const
                { return equal_list(d, " = ", mysqlpp::quote, i); }
        CSceneData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d,
                mysqlpp::sql_cmp_type sc) const
                { return equal_list(d, " = ", mysqlpp::quote, sc); }
    
        CSceneData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d, const char* c,
                bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false, bool i9 = false, bool i10 = false, bool i11 = false, bool i12 = false, bool i13 = false, bool i14 = false, bool i15 = false) const
                { return equal_list(d, c, mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15); }
        CSceneData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d, const char* c,
                CSceneData_enum i1, CSceneData_enum i2 = SCENEDATA_NULL, CSceneData_enum i3 = SCENEDATA_NULL, CSceneData_enum i4 = SCENEDATA_NULL, CSceneData_enum i5 = SCENEDATA_NULL, CSceneData_enum i6 = SCENEDATA_NULL, CSceneData_enum i7 = SCENEDATA_NULL, CSceneData_enum i8 = SCENEDATA_NULL, CSceneData_enum i9 = SCENEDATA_NULL, CSceneData_enum i10 = SCENEDATA_NULL, CSceneData_enum i11 = SCENEDATA_NULL, CSceneData_enum i12 = SCENEDATA_NULL, CSceneData_enum i13 = SCENEDATA_NULL, CSceneData_enum i14 = SCENEDATA_NULL, CSceneData_enum i15 = SCENEDATA_NULL) const
                { return equal_list(d, c, mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15); }
        CSceneData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d, const char* c,
                std::vector<bool> *i) const
                { return equal_list(d, c, mysqlpp::quote, i); }
        CSceneData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d, const char* c,
                mysqlpp::sql_cmp_type sc) const
                { return equal_list(d, c, mysqlpp::quote, sc); }
    
        template <class Manip>
        CSceneData_cus_equal_list<Manip> equal_list(const char* d, const char* c, Manip m, 
                            bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false, bool i9 = false, bool i10 = false, bool i11 = false, bool i12 = false, bool i13 = false, bool i14 = false, bool i15 = false) const;
        template <class Manip>
        CSceneData_cus_equal_list<Manip> equal_list(const char* d, const char* c, Manip m, 
                            CSceneData_enum i1, CSceneData_enum i2 = SCENEDATA_NULL, CSceneData_enum i3 = SCENEDATA_NULL, CSceneData_enum i4 = SCENEDATA_NULL, CSceneData_enum i5 = SCENEDATA_NULL, CSceneData_enum i6 = SCENEDATA_NULL, CSceneData_enum i7 = SCENEDATA_NULL, CSceneData_enum i8 = SCENEDATA_NULL, CSceneData_enum i9 = SCENEDATA_NULL, CSceneData_enum i10 = SCENEDATA_NULL, CSceneData_enum i11 = SCENEDATA_NULL, CSceneData_enum i12 = SCENEDATA_NULL, CSceneData_enum i13 = SCENEDATA_NULL, CSceneData_enum i14 = SCENEDATA_NULL, CSceneData_enum i15 = SCENEDATA_NULL) const;
        template <class Manip>
        CSceneData_cus_equal_list<Manip> equal_list(const char* d, const char* c, Manip m, 
                            std::vector<bool> *i) const;
        template <class Manip>
        CSceneData_cus_equal_list<Manip> equal_list(const char* d, const char* c, Manip m, 
                            mysqlpp::sql_cmp_type sc) const;
    
        private:
        static const char* table_;
        const char* table_override_;
        };
            
        template <class Manip>
        CSceneData_cus_value_list<Manip>::CSceneData_cus_value_list
                (const CSceneData* o, const char* d, Manip m, bool i1, bool i2, bool i3, bool i4, bool i5, bool i6, bool i7, bool i8, bool i9, bool i10, bool i11, bool i12, bool i13, bool i14, bool i15)
        {
            delim = d;
            manip = m;
            del_vector = true;
            obj = o;
            include = new std::vector<bool>(15, false);
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

        }
    
        template <class Manip>
        CSceneData_cus_value_list<Manip>::CSceneData_cus_value_list
                (const CSceneData* o, const char* d, Manip m, CSceneData_enum i1, CSceneData_enum i2, CSceneData_enum i3, CSceneData_enum i4, CSceneData_enum i5, CSceneData_enum i6, CSceneData_enum i7, CSceneData_enum i8, CSceneData_enum i9, CSceneData_enum i10, CSceneData_enum i11, CSceneData_enum i12, CSceneData_enum i13, CSceneData_enum i14, CSceneData_enum i15)
        {
            delim = d;
            manip = m;
            del_vector = true;
            obj = o;
            include = new std::vector<bool>(15, false);
        (*include)[i1]=true;
    if (i2 == SCENEDATA_NULL) return;
    (*include)[i2]=true;
    if (i3 == SCENEDATA_NULL) return;
    (*include)[i3]=true;
    if (i4 == SCENEDATA_NULL) return;
    (*include)[i4]=true;
    if (i5 == SCENEDATA_NULL) return;
    (*include)[i5]=true;
    if (i6 == SCENEDATA_NULL) return;
    (*include)[i6]=true;
    if (i7 == SCENEDATA_NULL) return;
    (*include)[i7]=true;
    if (i8 == SCENEDATA_NULL) return;
    (*include)[i8]=true;
    if (i9 == SCENEDATA_NULL) return;
    (*include)[i9]=true;
    if (i10 == SCENEDATA_NULL) return;
    (*include)[i10]=true;
    if (i11 == SCENEDATA_NULL) return;
    (*include)[i11]=true;
    if (i12 == SCENEDATA_NULL) return;
    (*include)[i12]=true;
    if (i13 == SCENEDATA_NULL) return;
    (*include)[i13]=true;
    if (i14 == SCENEDATA_NULL) return;
    (*include)[i14]=true;
    if (i15 == SCENEDATA_NULL) return;
    (*include)[i15]=true;

        }
    
        template <class Manip>
        CSceneData_cus_field_list<Manip>::CSceneData_cus_field_list
                (const CSceneData* o, const char* d, Manip m, bool i1, bool i2, bool i3, bool i4, bool i5, bool i6, bool i7, bool i8, bool i9, bool i10, bool i11, bool i12, bool i13, bool i14, bool i15)
        {
            delim = d;
            manip = m;
            del_vector = true;
            obj = o;
            include = new std::vector<bool>(15, false);
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

        }
    
        template <class Manip>
        CSceneData_cus_field_list<Manip>::CSceneData_cus_field_list
                (const CSceneData* o, const char* d, Manip m, CSceneData_enum i1, CSceneData_enum i2, CSceneData_enum i3, CSceneData_enum i4, CSceneData_enum i5, CSceneData_enum i6, CSceneData_enum i7, CSceneData_enum i8, CSceneData_enum i9, CSceneData_enum i10, CSceneData_enum i11, CSceneData_enum i12, CSceneData_enum i13, CSceneData_enum i14, CSceneData_enum i15)
        {
            delim = d;
            manip = m;
            del_vector = true;
            obj = o;
            include = new std::vector<bool>(15, false);
        (*include)[i1]=true;
    if (i2 == SCENEDATA_NULL) return;
    (*include)[i2]=true;
    if (i3 == SCENEDATA_NULL) return;
    (*include)[i3]=true;
    if (i4 == SCENEDATA_NULL) return;
    (*include)[i4]=true;
    if (i5 == SCENEDATA_NULL) return;
    (*include)[i5]=true;
    if (i6 == SCENEDATA_NULL) return;
    (*include)[i6]=true;
    if (i7 == SCENEDATA_NULL) return;
    (*include)[i7]=true;
    if (i8 == SCENEDATA_NULL) return;
    (*include)[i8]=true;
    if (i9 == SCENEDATA_NULL) return;
    (*include)[i9]=true;
    if (i10 == SCENEDATA_NULL) return;
    (*include)[i10]=true;
    if (i11 == SCENEDATA_NULL) return;
    (*include)[i11]=true;
    if (i12 == SCENEDATA_NULL) return;
    (*include)[i12]=true;
    if (i13 == SCENEDATA_NULL) return;
    (*include)[i13]=true;
    if (i14 == SCENEDATA_NULL) return;
    (*include)[i14]=true;
    if (i15 == SCENEDATA_NULL) return;
    (*include)[i15]=true;

        }
    
        template <class Manip>
        CSceneData_cus_equal_list<Manip>::CSceneData_cus_equal_list
                (const CSceneData* o, const char* d, const char* c, Manip m, bool i1, bool i2, bool i3, bool i4, bool i5, bool i6, bool i7, bool i8, bool i9, bool i10, bool i11, bool i12, bool i13, bool i14, bool i15)
        {
            delim = d;
            comp = c;
            manip = m;
            del_vector = true;
            obj = o;
            include = new std::vector<bool>(15, false);
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

        }
    
        template <class Manip>
        CSceneData_cus_equal_list<Manip>::CSceneData_cus_equal_list
                (const CSceneData* o, const char* d, const char* c, Manip m, CSceneData_enum i1, CSceneData_enum i2, CSceneData_enum i3, CSceneData_enum i4, CSceneData_enum i5, CSceneData_enum i6, CSceneData_enum i7, CSceneData_enum i8, CSceneData_enum i9, CSceneData_enum i10, CSceneData_enum i11, CSceneData_enum i12, CSceneData_enum i13, CSceneData_enum i14, CSceneData_enum i15)
        {
            delim = d;
            comp = c;
            manip = m;
            del_vector = true;
            obj = o;
            include = new std::vector<bool>(15, false);
        (*include)[i1]=true;
    if (i2 == SCENEDATA_NULL) return;
    (*include)[i2]=true;
    if (i3 == SCENEDATA_NULL) return;
    (*include)[i3]=true;
    if (i4 == SCENEDATA_NULL) return;
    (*include)[i4]=true;
    if (i5 == SCENEDATA_NULL) return;
    (*include)[i5]=true;
    if (i6 == SCENEDATA_NULL) return;
    (*include)[i6]=true;
    if (i7 == SCENEDATA_NULL) return;
    (*include)[i7]=true;
    if (i8 == SCENEDATA_NULL) return;
    (*include)[i8]=true;
    if (i9 == SCENEDATA_NULL) return;
    (*include)[i9]=true;
    if (i10 == SCENEDATA_NULL) return;
    (*include)[i10]=true;
    if (i11 == SCENEDATA_NULL) return;
    (*include)[i11]=true;
    if (i12 == SCENEDATA_NULL) return;
    (*include)[i12]=true;
    if (i13 == SCENEDATA_NULL) return;
    (*include)[i13]=true;
    if (i14 == SCENEDATA_NULL) return;
    (*include)[i14]=true;
    if (i15 == SCENEDATA_NULL) return;
    (*include)[i15]=true;

        }
    
        template <class Manip>
        std::ostream& operator <<(std::ostream& s, const CSceneData_value_list<Manip>& obj)
        {
        s << obj.manip << obj.obj->id << obj.delim;
    s << obj.manip << obj.obj->name << obj.delim;
    s << obj.manip << obj.obj->mapdoc << obj.delim;
    s << obj.manip << obj.obj->type << obj.delim;
    s << obj.manip << obj.obj->type2 << obj.delim;
    s << obj.manip << obj.obj->sort << obj.delim;
    s << obj.manip << obj.obj->portal0_x << obj.delim;
    s << obj.manip << obj.obj->portal0_y << obj.delim;
    s << obj.manip << obj.obj->portal0_z << obj.delim;
    s << obj.manip << obj.obj->reborn_map << obj.delim;
    s << obj.manip << obj.obj->link_map << obj.delim;
    s << obj.manip << obj.obj->link_x << obj.delim;
    s << obj.manip << obj.obj->link_y << obj.delim;
    s << obj.manip << obj.obj->link_z << obj.delim;
    s << obj.manip << obj.obj->flag;
            return s;
        }
    
        template <class Manip>
        std::ostream& operator <<(std::ostream& s, const CSceneData_field_list<Manip>& obj)
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
    s << obj.manip << '`' << obj.obj->names[14] << '`';
            return s;
        }
    
        template <class Manip>
        std::ostream& operator <<(std::ostream& s, const CSceneData_equal_list<Manip>& obj)
        {
        s << '`' << obj.obj->names[0] << '`' << obj.comp << obj.manip << obj.obj->id << obj.delim;
    s << '`' << obj.obj->names[1] << '`' << obj.comp << obj.manip << obj.obj->name << obj.delim;
    s << '`' << obj.obj->names[2] << '`' << obj.comp << obj.manip << obj.obj->mapdoc << obj.delim;
    s << '`' << obj.obj->names[3] << '`' << obj.comp << obj.manip << obj.obj->type << obj.delim;
    s << '`' << obj.obj->names[4] << '`' << obj.comp << obj.manip << obj.obj->type2 << obj.delim;
    s << '`' << obj.obj->names[5] << '`' << obj.comp << obj.manip << obj.obj->sort << obj.delim;
    s << '`' << obj.obj->names[6] << '`' << obj.comp << obj.manip << obj.obj->portal0_x << obj.delim;
    s << '`' << obj.obj->names[7] << '`' << obj.comp << obj.manip << obj.obj->portal0_y << obj.delim;
    s << '`' << obj.obj->names[8] << '`' << obj.comp << obj.manip << obj.obj->portal0_z << obj.delim;
    s << '`' << obj.obj->names[9] << '`' << obj.comp << obj.manip << obj.obj->reborn_map << obj.delim;
    s << '`' << obj.obj->names[10] << '`' << obj.comp << obj.manip << obj.obj->link_map << obj.delim;
    s << '`' << obj.obj->names[11] << '`' << obj.comp << obj.manip << obj.obj->link_x << obj.delim;
    s << '`' << obj.obj->names[12] << '`' << obj.comp << obj.manip << obj.obj->link_y << obj.delim;
    s << '`' << obj.obj->names[13] << '`' << obj.comp << obj.manip << obj.obj->link_z << obj.delim;
    s << '`' << obj.obj->names[14] << '`' << obj.comp << obj.manip << obj.obj->flag;
            return s;
        }
    
        template <class Manip>
        std::ostream& operator <<(std::ostream& s, const CSceneData_cus_value_list<Manip>& obj)
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
      s << obj.manip << obj.obj->mapdoc;
      before = true; 
     } 
    if ((*obj.include)[3]) { 
      if (before) s << obj.delim;
      s << obj.manip << obj.obj->type;
      before = true; 
     } 
    if ((*obj.include)[4]) { 
      if (before) s << obj.delim;
      s << obj.manip << obj.obj->type2;
      before = true; 
     } 
    if ((*obj.include)[5]) { 
      if (before) s << obj.delim;
      s << obj.manip << obj.obj->sort;
      before = true; 
     } 
    if ((*obj.include)[6]) { 
      if (before) s << obj.delim;
      s << obj.manip << obj.obj->portal0_x;
      before = true; 
     } 
    if ((*obj.include)[7]) { 
      if (before) s << obj.delim;
      s << obj.manip << obj.obj->portal0_y;
      before = true; 
     } 
    if ((*obj.include)[8]) { 
      if (before) s << obj.delim;
      s << obj.manip << obj.obj->portal0_z;
      before = true; 
     } 
    if ((*obj.include)[9]) { 
      if (before) s << obj.delim;
      s << obj.manip << obj.obj->reborn_map;
      before = true; 
     } 
    if ((*obj.include)[10]) { 
      if (before) s << obj.delim;
      s << obj.manip << obj.obj->link_map;
      before = true; 
     } 
    if ((*obj.include)[11]) { 
      if (before) s << obj.delim;
      s << obj.manip << obj.obj->link_x;
      before = true; 
     } 
    if ((*obj.include)[12]) { 
      if (before) s << obj.delim;
      s << obj.manip << obj.obj->link_y;
      before = true; 
     } 
    if ((*obj.include)[13]) { 
      if (before) s << obj.delim;
      s << obj.manip << obj.obj->link_z;
      before = true; 
     } 
    if ((*obj.include)[14]) { 
      if (before) s << obj.delim;
      s << obj.manip << obj.obj->flag;
     } 

            return s;
        }
    
        template <class Manip>
        std::ostream& operator <<(std::ostream& s, const CSceneData_cus_field_list<Manip>& obj)
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
     } 

            return s;
        }
    
        template <class Manip>
        std::ostream& operator <<(std::ostream& s, const CSceneData_cus_equal_list<Manip>& obj)
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
      s << '`' << obj.obj->names[2] << '`' << obj.comp         << obj.manip << obj.obj->mapdoc;
      before = true; 
     } 
    if ((*obj.include)[3]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[3] << '`' << obj.comp         << obj.manip << obj.obj->type;
      before = true; 
     } 
    if ((*obj.include)[4]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[4] << '`' << obj.comp         << obj.manip << obj.obj->type2;
      before = true; 
     } 
    if ((*obj.include)[5]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[5] << '`' << obj.comp         << obj.manip << obj.obj->sort;
      before = true; 
     } 
    if ((*obj.include)[6]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[6] << '`' << obj.comp         << obj.manip << obj.obj->portal0_x;
      before = true; 
     } 
    if ((*obj.include)[7]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[7] << '`' << obj.comp         << obj.manip << obj.obj->portal0_y;
      before = true; 
     } 
    if ((*obj.include)[8]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[8] << '`' << obj.comp         << obj.manip << obj.obj->portal0_z;
      before = true; 
     } 
    if ((*obj.include)[9]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[9] << '`' << obj.comp         << obj.manip << obj.obj->reborn_map;
      before = true; 
     } 
    if ((*obj.include)[10]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[10] << '`' << obj.comp         << obj.manip << obj.obj->link_map;
      before = true; 
     } 
    if ((*obj.include)[11]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[11] << '`' << obj.comp         << obj.manip << obj.obj->link_x;
      before = true; 
     } 
    if ((*obj.include)[12]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[12] << '`' << obj.comp         << obj.manip << obj.obj->link_y;
      before = true; 
     } 
    if ((*obj.include)[13]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[13] << '`' << obj.comp         << obj.manip << obj.obj->link_z;
      before = true; 
     } 
    if ((*obj.include)[14]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[14] << '`' << obj.comp         << obj.manip << obj.obj->flag;
     } 

            return s;
        }
    
        template <class Manip>
        inline CSceneData_value_list<Manip> CSceneData::value_list(const char* d, Manip m) const
                { return CSceneData_value_list<Manip> (this, d, m); } 
    
        template <class Manip>
        inline CSceneData_field_list<Manip> CSceneData::field_list(const char* d, Manip m) const
                { return CSceneData_field_list<Manip> (this, d, m); } 
    
        template <class Manip>
        inline CSceneData_equal_list<Manip> CSceneData::equal_list(const char* d, const char* c, Manip m) const
                { return CSceneData_equal_list<Manip> (this, d, c, m); } 
    
        template <class Manip>
        inline CSceneData_cus_value_list<Manip> CSceneData::value_list(const char* d, Manip m,
                bool i1, bool i2, bool i3, bool i4, bool i5, bool i6, bool i7, bool i8, bool i9, bool i10, bool i11, bool i12, bool i13, bool i14, bool i15) const
                { return CSceneData_cus_value_list<Manip> (this, d, m, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15); }
    
        template <class Manip>
        inline CSceneData_cus_field_list<Manip> CSceneData::field_list(const char* d, Manip m,
                bool i1, bool i2, bool i3, bool i4, bool i5, bool i6, bool i7, bool i8, bool i9, bool i10, bool i11, bool i12, bool i13, bool i14, bool i15) const
                { return CSceneData_cus_field_list<Manip> (this, d, m, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15); }
    
        template <class Manip>
        inline CSceneData_cus_equal_list<Manip> CSceneData::equal_list(const char* d, const char* c, Manip m,
                bool i1, bool i2, bool i3, bool i4, bool i5, bool i6, bool i7, bool i8, bool i9, bool i10, bool i11, bool i12, bool i13, bool i14, bool i15) const
                { return CSceneData_cus_equal_list<Manip> (this, d, c, m, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15); } 
    
        template <class Manip>
        inline CSceneData_cus_value_list<Manip> CSceneData::value_list(const char* d, Manip m,
                CSceneData_enum i1, CSceneData_enum i2, CSceneData_enum i3, CSceneData_enum i4, CSceneData_enum i5, CSceneData_enum i6, CSceneData_enum i7, CSceneData_enum i8, CSceneData_enum i9, CSceneData_enum i10, CSceneData_enum i11, CSceneData_enum i12, CSceneData_enum i13, CSceneData_enum i14, CSceneData_enum i15) const
                { return CSceneData_cus_value_list<Manip> (this, d, m, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15); } 
    
        template <class Manip>
        inline CSceneData_cus_field_list<Manip> CSceneData::field_list(const char* d, Manip m,
                CSceneData_enum i1, CSceneData_enum i2, CSceneData_enum i3, CSceneData_enum i4, CSceneData_enum i5, CSceneData_enum i6, CSceneData_enum i7, CSceneData_enum i8, CSceneData_enum i9, CSceneData_enum i10, CSceneData_enum i11, CSceneData_enum i12, CSceneData_enum i13, CSceneData_enum i14, CSceneData_enum i15) const
                { return CSceneData_cus_field_list<Manip> (this, d, m, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15); } 
    
        template <class Manip>
        inline CSceneData_cus_equal_list<Manip> CSceneData::equal_list(const char* d, const char* c, Manip m, 
                CSceneData_enum i1, CSceneData_enum i2, CSceneData_enum i3, CSceneData_enum i4, CSceneData_enum i5, CSceneData_enum i6, CSceneData_enum i7, CSceneData_enum i8, CSceneData_enum i9, CSceneData_enum i10, CSceneData_enum i11, CSceneData_enum i12, CSceneData_enum i13, CSceneData_enum i14, CSceneData_enum i15) const
                { return CSceneData_cus_equal_list<Manip> (this, d, c, m, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15); } 
    
        template <class Manip>
        inline CSceneData_cus_value_list<Manip> CSceneData::value_list(const char* d, Manip m,
                std::vector<bool> *i) const
                { return CSceneData_cus_value_list<Manip> (this, d, m, i); }
    
        template <class Manip>
        inline CSceneData_cus_field_list<Manip> CSceneData::field_list(const char* d, Manip m,
                std::vector<bool> *i) const
                { return CSceneData_cus_field_list<Manip> (this, d, m, i); }
    
        template <class Manip>
        inline CSceneData_cus_equal_list<Manip> CSceneData::equal_list(const char* d, const char* c, Manip m,
                std::vector<bool> *i) const
                { return CSceneData_cus_equal_list<Manip> (this, d, c, m, i); }
    
        template <class Manip>
        inline CSceneData_cus_value_list<Manip> 
        CSceneData::value_list(const char* d, Manip m, mysqlpp::sql_cmp_type /*sc*/) const
                { return value_list(d, m, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true); }
    
        template <class Manip>
        inline CSceneData_cus_field_list<Manip> 
        CSceneData::field_list(const char* d, Manip m, mysqlpp::sql_cmp_type /*sc*/) const
                { return field_list(d, m, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true); }
    
        template <class Manip>
        inline CSceneData_cus_equal_list<Manip> 
        CSceneData::equal_list(const char* d, const char* c, Manip m, mysqlpp::sql_cmp_type /*sc*/) const
                { return equal_list(d, c, m, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true); }
    
        template <mysqlpp::sql_dummy_type dummy>
        void populate_CSceneData(CSceneData *s, const mysqlpp::Row &row)
        {
            mysqlpp::NoExceptions ignore_schema_mismatches(row);
        s->id = row["id"].conv(sql_int_unsigned());
    s->name = row["name"].conv(sql_char_null());
    s->mapdoc = row["mapdoc"].conv(sql_int_unsigned());
    s->type = row["type"].conv(sql_bigint_unsigned());
    s->type2 = row["type2"].conv(sql_bigint_unsigned());
    s->sort = row["sort"].conv(sql_int_unsigned());
    s->portal0_x = row["portal0_x"].conv(sql_float());
    s->portal0_y = row["portal0_y"].conv(sql_float());
    s->portal0_z = row["portal0_z"].conv(sql_float());
    s->reborn_map = row["reborn_map"].conv(sql_int_unsigned_null());
    s->link_map = row["link_map"].conv(sql_int_unsigned());
    s->link_x = row["link_x"].conv(sql_float());
    s->link_y = row["link_y"].conv(sql_float());
    s->link_z = row["link_z"].conv(sql_float());
    s->flag = row["flag"].conv(sql_int_unsigned());
        }
    
        inline CSceneData::CSceneData(const mysqlpp::Row& row) :
        table_override_(0)
                { populate_CSceneData<mysqlpp::sql_dummy>(this, row); }
        inline void CSceneData::set(const mysqlpp::Row& row)
        {
            table_override_ = 0;
            populate_CSceneData<mysqlpp::sql_dummy>(this, row);
        }
    
        template <mysqlpp::sql_dummy_type dummy> 
 int sql_compare_CSceneData(const CSceneData &x, const CSceneData &y) { 
     int cmp; \
    cmp = mysqlpp::sql_cmp(x.id, y.id ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.name, y.name ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.mapdoc, y.mapdoc ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.type, y.type ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.type2, y.type2 ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.sort, y.sort ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.portal0_x, y.portal0_x ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.portal0_y, y.portal0_y ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.portal0_z, y.portal0_z ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.reborn_map, y.reborn_map ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.link_map, y.link_map ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.link_x, y.link_x ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.link_y, y.link_y ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.link_z, y.link_z ); \
    if (cmp) return cmp; \
    return mysqlpp::sql_cmp(x.flag, y.flag); 
 } 
 template <mysqlpp::sql_dummy_type dummy> 
 int compare (const CSceneData &x, const CSceneData &y) { 
     int cmp; \
    cmp = mysqlpp::sql_cmp(x.id, y.id ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.name, y.name ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.mapdoc, y.mapdoc ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.type, y.type ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.type2, y.type2 ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.sort, y.sort ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.portal0_x, y.portal0_x ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.portal0_y, y.portal0_y ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.portal0_z, y.portal0_z ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.reborn_map, y.reborn_map ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.link_map, y.link_map ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.link_x, y.link_x ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.link_y, y.link_y ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.link_z, y.link_z ); \
    if (cmp) return cmp; \
    return mysqlpp::sql_cmp(x.flag, y.flag); 
 }

#endif	//end of define _SCENE_DATA_H_