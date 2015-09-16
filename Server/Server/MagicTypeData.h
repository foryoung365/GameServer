////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author: 	Fu Yan
// Created: 	2015-08-17
// Describe: 	Specailized SQL structure of table gs_magic_type, 
//				generate by genSsqls.py, !!!DO NOT EDIT!!!
////////////////////////////////////////////////////////////////////////
#ifndef _MAGIC_TYPE_DATA_H_
#define _MAGIC_TYPE_DATA_H_

#include <mysql++.h>
#include <ssqls.h>

using namespace mysqlpp;

struct CMagicTypeData; 
    
        enum CMagicTypeData_enum { 
        MAGICTYPEDATA_ID,
    MAGICTYPEDATA_NAME,
    MAGICTYPEDATA_SORT,
    MAGICTYPEDATA_BEGIN_DELAY_MS,
    MAGICTYPEDATA_END_DELAY_MS,
    MAGICTYPEDATA_COOL_DOWN_MS,
    MAGICTYPEDATA_COST_TYPE1,
    MAGICTYPEDATA_COST_VALUE1,
    MAGICTYPEDATA_COST_TYPE2,
    MAGICTYPEDATA_COST_VALUE2,
    MAGICTYPEDATA_RANGE_DISTANCE,
    MAGICTYPEDATA_TARGET_TYPE,
    MAGICTYPEDATA_RANGE_TYPE,
    MAGICTYPEDATA_RANGE_X,
    MAGICTYPEDATA_RANGE_Y,
    MAGICTYPEDATA_DAMAGE_ID,
    MAGICTYPEDATA_ATKER_DISTANCE,
    MAGICTYPEDATA_ATKER_DURATION,
    MAGICTYPEDATA_VICTIM_DISTANCE,
    MAGICTYPEDATA_VICTIM_DURATION,
    MAGICTYPEDATA_STATUS_ID,
    MAGICTYPEDATA_STATUS_RATE,
        MAGICTYPEDATA_NULL 
        }; 
    
        template <class Manip>
        class CMagicTypeData_value_list { 
        public: 
        const CMagicTypeData* obj;
        const char* delim;
        Manip manip;
        public: 
        CMagicTypeData_value_list (const CMagicTypeData* o, const char* d, Manip m) :
        obj(o), delim(d), manip(m) { } 
        };
    
        template <class Manip>
        class CMagicTypeData_field_list {
        public: 
        const CMagicTypeData* obj; 
        const char* delim;
        Manip manip;
        public: 
        CMagicTypeData_field_list (const CMagicTypeData* o, const char* d, Manip m) :
        obj(o), delim(d), manip(m) { } 
        };
    
        template <class Manip>
        class CMagicTypeData_equal_list { 
        public: 
        const CMagicTypeData* obj;
        const char* delim;
        const char* comp;
        Manip manip;
        public: 
        CMagicTypeData_equal_list (const CMagicTypeData* o, const char* d, const char* c, Manip m) :
        obj(o), delim(d), comp(c), manip(m) { }
        };
    
        template <class Manip>
        class CMagicTypeData_cus_value_list {
        public:
        const CMagicTypeData* obj;
        std::vector<bool> *include;
        bool del_vector;
        const char* delim;
        Manip manip;
        public: 
        ~CMagicTypeData_cus_value_list () {if (del_vector) delete include;} 
        CMagicTypeData_cus_value_list (const CMagicTypeData* o, const char* d, Manip m, bool i1, bool i2, bool i3, bool i4, bool i5, bool i6, bool i7, bool i8, bool i9, bool i10, bool i11, bool i12, bool i13, bool i14, bool i15, bool i16, bool i17, bool i18, bool i19, bool i20, bool i21, bool i22);
        CMagicTypeData_cus_value_list (const CMagicTypeData* o, const char* d, Manip m, CMagicTypeData_enum i1, CMagicTypeData_enum i2, CMagicTypeData_enum i3, CMagicTypeData_enum i4, CMagicTypeData_enum i5, CMagicTypeData_enum i6, CMagicTypeData_enum i7, CMagicTypeData_enum i8, CMagicTypeData_enum i9, CMagicTypeData_enum i10, CMagicTypeData_enum i11, CMagicTypeData_enum i12, CMagicTypeData_enum i13, CMagicTypeData_enum i14, CMagicTypeData_enum i15, CMagicTypeData_enum i16, CMagicTypeData_enum i17, CMagicTypeData_enum i18, CMagicTypeData_enum i19, CMagicTypeData_enum i20, CMagicTypeData_enum i21, CMagicTypeData_enum i22); 
        CMagicTypeData_cus_value_list (const CMagicTypeData* o, const char* d, Manip m ,std::vector<bool>* i) :
        obj(o), include(i), del_vector(false), delim(d), manip(m) { }
        };
    
        template <class Manip>
        class CMagicTypeData_cus_field_list { 
        public:
        const CMagicTypeData* obj; 
        std::vector<bool> *include; 
        bool del_vector; 
        const char* delim;
        Manip manip;
        public: 
        ~CMagicTypeData_cus_field_list () {if (del_vector) delete include;} 
        CMagicTypeData_cus_field_list (const CMagicTypeData* o, const char* d, Manip m, bool i1, bool i2, bool i3, bool i4, bool i5, bool i6, bool i7, bool i8, bool i9, bool i10, bool i11, bool i12, bool i13, bool i14, bool i15, bool i16, bool i17, bool i18, bool i19, bool i20, bool i21, bool i22); 
        CMagicTypeData_cus_field_list (const CMagicTypeData* o, const char* d, Manip m, CMagicTypeData_enum i1, CMagicTypeData_enum i2, CMagicTypeData_enum i3, CMagicTypeData_enum i4, CMagicTypeData_enum i5, CMagicTypeData_enum i6, CMagicTypeData_enum i7, CMagicTypeData_enum i8, CMagicTypeData_enum i9, CMagicTypeData_enum i10, CMagicTypeData_enum i11, CMagicTypeData_enum i12, CMagicTypeData_enum i13, CMagicTypeData_enum i14, CMagicTypeData_enum i15, CMagicTypeData_enum i16, CMagicTypeData_enum i17, CMagicTypeData_enum i18, CMagicTypeData_enum i19, CMagicTypeData_enum i20, CMagicTypeData_enum i21, CMagicTypeData_enum i22); 
        CMagicTypeData_cus_field_list (const CMagicTypeData* o, const char* d, Manip m, std::vector<bool> *i) :
        obj(o), include(i), del_vector(false), delim(d), manip(m) { }
        };
    
        template <class Manip>
        class CMagicTypeData_cus_equal_list {
        public:
        const CMagicTypeData* obj;
        std::vector<bool> *include;
        bool del_vector;
        const char* delim;
        const char* comp;
        Manip manip;
        public:
        ~CMagicTypeData_cus_equal_list () {if (del_vector) delete include;}
        CMagicTypeData_cus_equal_list (const CMagicTypeData* o, const char* d, const char* c, Manip m, bool i1, bool i2, bool i3, bool i4, bool i5, bool i6, bool i7, bool i8, bool i9, bool i10, bool i11, bool i12, bool i13, bool i14, bool i15, bool i16, bool i17, bool i18, bool i19, bool i20, bool i21, bool i22); 
        CMagicTypeData_cus_equal_list (const CMagicTypeData* o, const char* d, const char* c, Manip m, CMagicTypeData_enum i1, CMagicTypeData_enum i2, CMagicTypeData_enum i3, CMagicTypeData_enum i4, CMagicTypeData_enum i5, CMagicTypeData_enum i6, CMagicTypeData_enum i7, CMagicTypeData_enum i8, CMagicTypeData_enum i9, CMagicTypeData_enum i10, CMagicTypeData_enum i11, CMagicTypeData_enum i12, CMagicTypeData_enum i13, CMagicTypeData_enum i14, CMagicTypeData_enum i15, CMagicTypeData_enum i16, CMagicTypeData_enum i17, CMagicTypeData_enum i18, CMagicTypeData_enum i19, CMagicTypeData_enum i20, CMagicTypeData_enum i21, CMagicTypeData_enum i22); 
        CMagicTypeData_cus_equal_list (const CMagicTypeData* o, const char* d, const char* c, Manip m, std::vector<bool> *i) :
        obj(o), include(i), del_vector(false), delim(d), comp(c), manip(m) { }
        };
    
        template <mysqlpp::sql_dummy_type dummy> int sql_compare_CMagicTypeData(const CMagicTypeData&, const CMagicTypeData&);
    
        struct CMagicTypeData {
        sql_bigint_unsigned id;
    sql_char name;
    sql_int_unsigned sort;
    sql_int_unsigned begin_delay_ms;
    sql_int_unsigned end_delay_ms;
    sql_int_unsigned cool_down_ms;
    sql_int_unsigned cost_type1;
    sql_int_unsigned cost_value1;
    sql_int_unsigned cost_type2;
    sql_int_unsigned cost_value2;
    sql_float range_distance;
    sql_int_unsigned target_type;
    sql_int_unsigned range_type;
    sql_float range_x;
    sql_float range_y;
    sql_int_unsigned damage_id;
    sql_int_unsigned atker_distance;
    sql_int_unsigned atker_duration;
    sql_int_unsigned victim_distance;
    sql_int_unsigned victim_duration;
    sql_int_unsigned status_id;
    sql_int_unsigned status_rate; 
        CMagicTypeData() : table_override_(0) { }
        CMagicTypeData(const mysqlpp::Row& row);
        void set(const mysqlpp::Row &row);
        CMagicTypeData(const sql_bigint_unsigned &p1, const sql_char &p2, const sql_int_unsigned &p3, const sql_int_unsigned &p4, const sql_int_unsigned &p5, const sql_int_unsigned &p6, const sql_int_unsigned &p7, const sql_int_unsigned &p8, const sql_int_unsigned &p9, const sql_int_unsigned &p10, const sql_float &p11, const sql_int_unsigned &p12, const sql_int_unsigned &p13, const sql_float &p14, const sql_float &p15, const sql_int_unsigned &p16, const sql_int_unsigned &p17, const sql_int_unsigned &p18, const sql_int_unsigned &p19, const sql_int_unsigned &p20, const sql_int_unsigned &p21, const sql_int_unsigned &p22) : id (p1), name (p2), sort (p3), begin_delay_ms (p4), end_delay_ms (p5), cool_down_ms (p6), cost_type1 (p7), cost_value1 (p8), cost_type2 (p9), cost_value2 (p10), range_distance (p11), target_type (p12), range_type (p13), range_x (p14), range_y (p15), damage_id (p16), atker_distance (p17), atker_duration (p18), victim_distance (p19), victim_duration (p20), status_id (p21), status_rate (p22), table_override_(0) {}
void set(const sql_bigint_unsigned &p1, const sql_char &p2, const sql_int_unsigned &p3, const sql_int_unsigned &p4, const sql_int_unsigned &p5, const sql_int_unsigned &p6, const sql_int_unsigned &p7, const sql_int_unsigned &p8, const sql_int_unsigned &p9, const sql_int_unsigned &p10, const sql_float &p11, const sql_int_unsigned &p12, const sql_int_unsigned &p13, const sql_float &p14, const sql_float &p15, const sql_int_unsigned &p16, const sql_int_unsigned &p17, const sql_int_unsigned &p18, const sql_int_unsigned &p19, const sql_int_unsigned &p20, const sql_int_unsigned &p21, const sql_int_unsigned &p22) {
table_override_ = 0;
    id = p1;\
    name = p2;\
    sort = p3;\
    begin_delay_ms = p4;\
    end_delay_ms = p5;\
    cool_down_ms = p6;\
    cost_type1 = p7;\
    cost_value1 = p8;\
    cost_type2 = p9;\
    cost_value2 = p10;\
    range_distance = p11;\
    target_type = p12;\
    range_type = p13;\
    range_x = p14;\
    range_y = p15;\
    damage_id = p16;\
    atker_distance = p17;\
    atker_duration = p18;\
    victim_distance = p19;\
    victim_duration = p20;\
    status_id = p21;\
    status_rate = p22;\

}
bool operator == (const CMagicTypeData &other) const 
 {return sql_compare_CMagicTypeData<mysqlpp::sql_dummy>(*this,other) == 0;} 
 bool operator != (const CMagicTypeData &other) const 
 {return sql_compare_CMagicTypeData<mysqlpp::sql_dummy>(*this,other) != 0;} 
 bool operator > (const CMagicTypeData &other) const 
 {return sql_compare_CMagicTypeData<mysqlpp::sql_dummy>(*this,other) >  0;} 
 bool operator < (const CMagicTypeData &other) const 
 {return sql_compare_CMagicTypeData<mysqlpp::sql_dummy>(*this,other) <  0;} 
 bool operator >= (const CMagicTypeData &other) const 
 {return sql_compare_CMagicTypeData<mysqlpp::sql_dummy>(*this,other) >= 0;} 
 bool operator <= (const CMagicTypeData &other) const 
 {return sql_compare_CMagicTypeData<mysqlpp::sql_dummy>(*this,other) <= 0;} 
 int cmp (const CMagicTypeData &other) const 
 {return sql_compare_CMagicTypeData<mysqlpp::sql_dummy>(*this,other);} 
 int compare (const CMagicTypeData &other) const 
 {return sql_compare_CMagicTypeData<mysqlpp::sql_dummy>(*this,other);}

        void set(const sql_bigint_unsigned p1) { \
        table_override_ = 0;

        id = p1;


        } \
        CMagicTypeData(const sql_bigint_unsigned p1) : id(p1), table_override_(0) {}
        static const char* names[];
        static void table(const char* t) { table_ = t; }
        const char* table() const
                { return table_override_ ? table_override_ : CMagicTypeData::table_; }
        void instance_table(const char* t) { table_override_ = t; }
    
        CMagicTypeData_value_list<mysqlpp::quote_type0> value_list() const {
            return value_list(",", mysqlpp::quote);}
        CMagicTypeData_value_list<mysqlpp::quote_type0> value_list(const char* d) const {
            return value_list(d, mysqlpp::quote);}
        template <class Manip>
        CMagicTypeData_value_list<Manip> value_list(const char* d, Manip m) const;
    
        CMagicTypeData_field_list<mysqlpp::do_nothing_type0> field_list() const {
            return field_list(",", mysqlpp::do_nothing);}
        CMagicTypeData_field_list<mysqlpp::do_nothing_type0> field_list(const char* d) const {
            return field_list(d, mysqlpp::do_nothing);}
        template <class Manip>
        CMagicTypeData_field_list<Manip> field_list(const char* d, Manip m) const;
    
        CMagicTypeData_equal_list<mysqlpp::quote_type0> equal_list(const char* d = ",",
                const char* c = " = ") const
                { return equal_list(d, c, mysqlpp::quote); }
        template <class Manip>
        CMagicTypeData_equal_list<Manip> equal_list(const char* d, const char* c, Manip m) const;
    
        /* cus_data */
    
        CMagicTypeData_cus_value_list<mysqlpp::quote_type0> value_list(bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false, bool i9 = false, bool i10 = false, bool i11 = false, bool i12 = false, bool i13 = false, bool i14 = false, bool i15 = false, bool i16 = false, bool i17 = false, bool i18 = false, bool i19 = false, bool i20 = false, bool i21 = false, bool i22 = false) const
                { return value_list(",", mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15, i16, i17, i18, i19, i20, i21, i22); }
        CMagicTypeData_cus_value_list<mysqlpp::quote_type0> value_list(CMagicTypeData_enum i1, CMagicTypeData_enum i2 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i3 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i4 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i5 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i6 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i7 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i8 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i9 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i10 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i11 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i12 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i13 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i14 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i15 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i16 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i17 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i18 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i19 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i20 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i21 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i22 = MAGICTYPEDATA_NULL) const
                { return value_list(",", mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15, i16, i17, i18, i19, i20, i21, i22); }
        CMagicTypeData_cus_value_list<mysqlpp::quote_type0> value_list(std::vector<bool> *i) const
                { return value_list(",", mysqlpp::quote, i); }
        CMagicTypeData_cus_value_list<mysqlpp::quote_type0> value_list(mysqlpp::sql_cmp_type sc) const
                { return value_list(",", mysqlpp::quote, sc); }
    
        CMagicTypeData_cus_value_list<mysqlpp::quote_type0> value_list(const char* d, bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false, bool i9 = false, bool i10 = false, bool i11 = false, bool i12 = false, bool i13 = false, bool i14 = false, bool i15 = false, bool i16 = false, bool i17 = false, bool i18 = false, bool i19 = false, bool i20 = false, bool i21 = false, bool i22 = false) const
                { return value_list(d, mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15, i16, i17, i18, i19, i20, i21, i22); }
        CMagicTypeData_cus_value_list<mysqlpp::quote_type0> value_list(const char* d, CMagicTypeData_enum i1, CMagicTypeData_enum i2 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i3 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i4 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i5 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i6 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i7 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i8 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i9 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i10 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i11 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i12 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i13 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i14 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i15 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i16 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i17 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i18 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i19 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i20 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i21 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i22 = MAGICTYPEDATA_NULL) const
                { return value_list(d, mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15, i16, i17, i18, i19, i20, i21, i22); }
        CMagicTypeData_cus_value_list<mysqlpp::quote_type0> value_list(const char* d,
                std::vector<bool> *i) const
                { return value_list(d, mysqlpp::quote, i); }
        CMagicTypeData_cus_value_list<mysqlpp::quote_type0> value_list(const char* d,
                mysqlpp::sql_cmp_type sc) const
                { return value_list(d, mysqlpp::quote, sc); }
    
        template <class Manip>
        CMagicTypeData_cus_value_list<Manip> value_list(const char* d, Manip m,
                bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false, bool i9 = false, bool i10 = false, bool i11 = false, bool i12 = false, bool i13 = false, bool i14 = false, bool i15 = false, bool i16 = false, bool i17 = false, bool i18 = false, bool i19 = false, bool i20 = false, bool i21 = false, bool i22 = false) const;
        template <class Manip>
        CMagicTypeData_cus_value_list<Manip> value_list(const char* d, Manip m,
                CMagicTypeData_enum i1, CMagicTypeData_enum i2 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i3 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i4 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i5 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i6 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i7 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i8 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i9 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i10 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i11 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i12 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i13 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i14 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i15 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i16 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i17 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i18 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i19 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i20 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i21 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i22 = MAGICTYPEDATA_NULL) const;
        template <class Manip>
        CMagicTypeData_cus_value_list<Manip> value_list(const char* d, Manip m,
                std::vector<bool>* i) const;
        template <class Manip>
        CMagicTypeData_cus_value_list<Manip> value_list(const char* d, Manip m, 
                mysqlpp::sql_cmp_type sc) const;
        /* cus field */
    
        CMagicTypeData_cus_field_list<mysqlpp::do_nothing_type0> field_list(bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false, bool i9 = false, bool i10 = false, bool i11 = false, bool i12 = false, bool i13 = false, bool i14 = false, bool i15 = false, bool i16 = false, bool i17 = false, bool i18 = false, bool i19 = false, bool i20 = false, bool i21 = false, bool i22 = false) const 
                { return field_list(",", mysqlpp::do_nothing, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15, i16, i17, i18, i19, i20, i21, i22); }
        CMagicTypeData_cus_field_list<mysqlpp::do_nothing_type0> field_list(CMagicTypeData_enum i1, CMagicTypeData_enum i2 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i3 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i4 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i5 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i6 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i7 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i8 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i9 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i10 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i11 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i12 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i13 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i14 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i15 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i16 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i17 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i18 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i19 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i20 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i21 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i22 = MAGICTYPEDATA_NULL) const
                { return field_list(",", mysqlpp::do_nothing, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15, i16, i17, i18, i19, i20, i21, i22); }
        CMagicTypeData_cus_field_list<mysqlpp::do_nothing_type0> field_list(std::vector<bool> *i) const
                { return field_list(",", mysqlpp::do_nothing, i); }
        CMagicTypeData_cus_field_list<mysqlpp::do_nothing_type0> field_list(mysqlpp::sql_cmp_type sc) const
                { return field_list(",", mysqlpp::do_nothing, sc); }
    
        CMagicTypeData_cus_field_list<mysqlpp::do_nothing_type0> field_list(const char* d,
                bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false, bool i9 = false, bool i10 = false, bool i11 = false, bool i12 = false, bool i13 = false, bool i14 = false, bool i15 = false, bool i16 = false, bool i17 = false, bool i18 = false, bool i19 = false, bool i20 = false, bool i21 = false, bool i22 = false) const
                { return field_list(d, mysqlpp::do_nothing, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15, i16, i17, i18, i19, i20, i21, i22); }
        CMagicTypeData_cus_field_list<mysqlpp::do_nothing_type0> field_list(const char* d,
                CMagicTypeData_enum i1, CMagicTypeData_enum i2 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i3 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i4 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i5 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i6 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i7 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i8 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i9 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i10 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i11 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i12 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i13 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i14 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i15 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i16 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i17 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i18 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i19 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i20 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i21 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i22 = MAGICTYPEDATA_NULL) const
                { return field_list(d, mysqlpp::do_nothing, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15, i16, i17, i18, i19, i20, i21, i22); }
        CMagicTypeData_cus_field_list<mysqlpp::do_nothing_type0> field_list(const char* d,
                std::vector<bool>* i) const
                { return field_list(d, mysqlpp::do_nothing, i); }
        CMagicTypeData_cus_field_list<mysqlpp::do_nothing_type0> field_list(const char* d,
                mysqlpp::sql_cmp_type sc) const
                { return field_list(d, mysqlpp::do_nothing, sc); }
    
        template <class Manip>
        CMagicTypeData_cus_field_list<Manip> field_list(const char* d, Manip m,
                bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false, bool i9 = false, bool i10 = false, bool i11 = false, bool i12 = false, bool i13 = false, bool i14 = false, bool i15 = false, bool i16 = false, bool i17 = false, bool i18 = false, bool i19 = false, bool i20 = false, bool i21 = false, bool i22 = false) const;
        template <class Manip>
        CMagicTypeData_cus_field_list<Manip> field_list(const char* d, Manip m,
                CMagicTypeData_enum i1, CMagicTypeData_enum i2 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i3 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i4 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i5 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i6 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i7 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i8 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i9 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i10 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i11 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i12 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i13 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i14 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i15 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i16 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i17 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i18 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i19 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i20 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i21 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i22 = MAGICTYPEDATA_NULL) const;
        template <class Manip>
        CMagicTypeData_cus_field_list<Manip> field_list(const char* d, Manip m,
                std::vector<bool> *i) const;
        template <class Manip>
        CMagicTypeData_cus_field_list<Manip> field_list(const char* d, Manip m,
                mysqlpp::sql_cmp_type sc) const;
    
        /* cus equal */
    
        CMagicTypeData_cus_equal_list<mysqlpp::quote_type0> equal_list(bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false, bool i9 = false, bool i10 = false, bool i11 = false, bool i12 = false, bool i13 = false, bool i14 = false, bool i15 = false, bool i16 = false, bool i17 = false, bool i18 = false, bool i19 = false, bool i20 = false, bool i21 = false, bool i22 = false) const
                { return equal_list(",", " = ", mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15, i16, i17, i18, i19, i20, i21, i22); }
        CMagicTypeData_cus_equal_list<mysqlpp::quote_type0> equal_list(CMagicTypeData_enum i1, CMagicTypeData_enum i2 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i3 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i4 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i5 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i6 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i7 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i8 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i9 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i10 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i11 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i12 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i13 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i14 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i15 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i16 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i17 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i18 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i19 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i20 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i21 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i22 = MAGICTYPEDATA_NULL) const
                { return equal_list(",", " = ", mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15, i16, i17, i18, i19, i20, i21, i22); }
        CMagicTypeData_cus_equal_list<mysqlpp::quote_type0> equal_list(std::vector<bool>* i) const
                { return equal_list(",", " = ", mysqlpp::quote, i); }
        CMagicTypeData_cus_equal_list<mysqlpp::quote_type0> equal_list(mysqlpp::sql_cmp_type sc) const
                { return equal_list(",", " = ", mysqlpp::quote, sc); }
    
        CMagicTypeData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d, bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false, bool i9 = false, bool i10 = false, bool i11 = false, bool i12 = false, bool i13 = false, bool i14 = false, bool i15 = false, bool i16 = false, bool i17 = false, bool i18 = false, bool i19 = false, bool i20 = false, bool i21 = false, bool i22 = false) const
                { return equal_list(d, " = ", mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15, i16, i17, i18, i19, i20, i21, i22); }
        CMagicTypeData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d, CMagicTypeData_enum i1, CMagicTypeData_enum i2 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i3 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i4 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i5 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i6 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i7 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i8 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i9 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i10 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i11 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i12 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i13 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i14 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i15 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i16 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i17 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i18 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i19 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i20 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i21 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i22 = MAGICTYPEDATA_NULL) const
                { return equal_list(d, " = ", mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15, i16, i17, i18, i19, i20, i21, i22); }
        CMagicTypeData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d,
                std::vector<bool> *i) const
                { return equal_list(d, " = ", mysqlpp::quote, i); }
        CMagicTypeData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d,
                mysqlpp::sql_cmp_type sc) const
                { return equal_list(d, " = ", mysqlpp::quote, sc); }
    
        CMagicTypeData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d, const char* c,
                bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false, bool i9 = false, bool i10 = false, bool i11 = false, bool i12 = false, bool i13 = false, bool i14 = false, bool i15 = false, bool i16 = false, bool i17 = false, bool i18 = false, bool i19 = false, bool i20 = false, bool i21 = false, bool i22 = false) const
                { return equal_list(d, c, mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15, i16, i17, i18, i19, i20, i21, i22); }
        CMagicTypeData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d, const char* c,
                CMagicTypeData_enum i1, CMagicTypeData_enum i2 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i3 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i4 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i5 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i6 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i7 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i8 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i9 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i10 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i11 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i12 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i13 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i14 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i15 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i16 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i17 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i18 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i19 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i20 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i21 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i22 = MAGICTYPEDATA_NULL) const
                { return equal_list(d, c, mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15, i16, i17, i18, i19, i20, i21, i22); }
        CMagicTypeData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d, const char* c,
                std::vector<bool> *i) const
                { return equal_list(d, c, mysqlpp::quote, i); }
        CMagicTypeData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d, const char* c,
                mysqlpp::sql_cmp_type sc) const
                { return equal_list(d, c, mysqlpp::quote, sc); }
    
        template <class Manip>
        CMagicTypeData_cus_equal_list<Manip> equal_list(const char* d, const char* c, Manip m, 
                            bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false, bool i9 = false, bool i10 = false, bool i11 = false, bool i12 = false, bool i13 = false, bool i14 = false, bool i15 = false, bool i16 = false, bool i17 = false, bool i18 = false, bool i19 = false, bool i20 = false, bool i21 = false, bool i22 = false) const;
        template <class Manip>
        CMagicTypeData_cus_equal_list<Manip> equal_list(const char* d, const char* c, Manip m, 
                            CMagicTypeData_enum i1, CMagicTypeData_enum i2 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i3 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i4 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i5 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i6 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i7 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i8 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i9 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i10 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i11 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i12 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i13 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i14 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i15 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i16 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i17 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i18 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i19 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i20 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i21 = MAGICTYPEDATA_NULL, CMagicTypeData_enum i22 = MAGICTYPEDATA_NULL) const;
        template <class Manip>
        CMagicTypeData_cus_equal_list<Manip> equal_list(const char* d, const char* c, Manip m, 
                            std::vector<bool> *i) const;
        template <class Manip>
        CMagicTypeData_cus_equal_list<Manip> equal_list(const char* d, const char* c, Manip m, 
                            mysqlpp::sql_cmp_type sc) const;
    
        private:
        static const char* table_;
        const char* table_override_;
        };
            
        template <class Manip>
        CMagicTypeData_cus_value_list<Manip>::CMagicTypeData_cus_value_list
                (const CMagicTypeData* o, const char* d, Manip m, bool i1, bool i2, bool i3, bool i4, bool i5, bool i6, bool i7, bool i8, bool i9, bool i10, bool i11, bool i12, bool i13, bool i14, bool i15, bool i16, bool i17, bool i18, bool i19, bool i20, bool i21, bool i22)
        {
            delim = d;
            manip = m;
            del_vector = true;
            obj = o;
            include = new std::vector<bool>(22, false);
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

        }
    
        template <class Manip>
        CMagicTypeData_cus_value_list<Manip>::CMagicTypeData_cus_value_list
                (const CMagicTypeData* o, const char* d, Manip m, CMagicTypeData_enum i1, CMagicTypeData_enum i2, CMagicTypeData_enum i3, CMagicTypeData_enum i4, CMagicTypeData_enum i5, CMagicTypeData_enum i6, CMagicTypeData_enum i7, CMagicTypeData_enum i8, CMagicTypeData_enum i9, CMagicTypeData_enum i10, CMagicTypeData_enum i11, CMagicTypeData_enum i12, CMagicTypeData_enum i13, CMagicTypeData_enum i14, CMagicTypeData_enum i15, CMagicTypeData_enum i16, CMagicTypeData_enum i17, CMagicTypeData_enum i18, CMagicTypeData_enum i19, CMagicTypeData_enum i20, CMagicTypeData_enum i21, CMagicTypeData_enum i22)
        {
            delim = d;
            manip = m;
            del_vector = true;
            obj = o;
            include = new std::vector<bool>(22, false);
        (*include)[i1]=true;
    if (i2 == MAGICTYPEDATA_NULL) return;
    (*include)[i2]=true;
    if (i3 == MAGICTYPEDATA_NULL) return;
    (*include)[i3]=true;
    if (i4 == MAGICTYPEDATA_NULL) return;
    (*include)[i4]=true;
    if (i5 == MAGICTYPEDATA_NULL) return;
    (*include)[i5]=true;
    if (i6 == MAGICTYPEDATA_NULL) return;
    (*include)[i6]=true;
    if (i7 == MAGICTYPEDATA_NULL) return;
    (*include)[i7]=true;
    if (i8 == MAGICTYPEDATA_NULL) return;
    (*include)[i8]=true;
    if (i9 == MAGICTYPEDATA_NULL) return;
    (*include)[i9]=true;
    if (i10 == MAGICTYPEDATA_NULL) return;
    (*include)[i10]=true;
    if (i11 == MAGICTYPEDATA_NULL) return;
    (*include)[i11]=true;
    if (i12 == MAGICTYPEDATA_NULL) return;
    (*include)[i12]=true;
    if (i13 == MAGICTYPEDATA_NULL) return;
    (*include)[i13]=true;
    if (i14 == MAGICTYPEDATA_NULL) return;
    (*include)[i14]=true;
    if (i15 == MAGICTYPEDATA_NULL) return;
    (*include)[i15]=true;
    if (i16 == MAGICTYPEDATA_NULL) return;
    (*include)[i16]=true;
    if (i17 == MAGICTYPEDATA_NULL) return;
    (*include)[i17]=true;
    if (i18 == MAGICTYPEDATA_NULL) return;
    (*include)[i18]=true;
    if (i19 == MAGICTYPEDATA_NULL) return;
    (*include)[i19]=true;
    if (i20 == MAGICTYPEDATA_NULL) return;
    (*include)[i20]=true;
    if (i21 == MAGICTYPEDATA_NULL) return;
    (*include)[i21]=true;
    if (i22 == MAGICTYPEDATA_NULL) return;
    (*include)[i22]=true;

        }
    
        template <class Manip>
        CMagicTypeData_cus_field_list<Manip>::CMagicTypeData_cus_field_list
                (const CMagicTypeData* o, const char* d, Manip m, bool i1, bool i2, bool i3, bool i4, bool i5, bool i6, bool i7, bool i8, bool i9, bool i10, bool i11, bool i12, bool i13, bool i14, bool i15, bool i16, bool i17, bool i18, bool i19, bool i20, bool i21, bool i22)
        {
            delim = d;
            manip = m;
            del_vector = true;
            obj = o;
            include = new std::vector<bool>(22, false);
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

        }
    
        template <class Manip>
        CMagicTypeData_cus_field_list<Manip>::CMagicTypeData_cus_field_list
                (const CMagicTypeData* o, const char* d, Manip m, CMagicTypeData_enum i1, CMagicTypeData_enum i2, CMagicTypeData_enum i3, CMagicTypeData_enum i4, CMagicTypeData_enum i5, CMagicTypeData_enum i6, CMagicTypeData_enum i7, CMagicTypeData_enum i8, CMagicTypeData_enum i9, CMagicTypeData_enum i10, CMagicTypeData_enum i11, CMagicTypeData_enum i12, CMagicTypeData_enum i13, CMagicTypeData_enum i14, CMagicTypeData_enum i15, CMagicTypeData_enum i16, CMagicTypeData_enum i17, CMagicTypeData_enum i18, CMagicTypeData_enum i19, CMagicTypeData_enum i20, CMagicTypeData_enum i21, CMagicTypeData_enum i22)
        {
            delim = d;
            manip = m;
            del_vector = true;
            obj = o;
            include = new std::vector<bool>(22, false);
        (*include)[i1]=true;
    if (i2 == MAGICTYPEDATA_NULL) return;
    (*include)[i2]=true;
    if (i3 == MAGICTYPEDATA_NULL) return;
    (*include)[i3]=true;
    if (i4 == MAGICTYPEDATA_NULL) return;
    (*include)[i4]=true;
    if (i5 == MAGICTYPEDATA_NULL) return;
    (*include)[i5]=true;
    if (i6 == MAGICTYPEDATA_NULL) return;
    (*include)[i6]=true;
    if (i7 == MAGICTYPEDATA_NULL) return;
    (*include)[i7]=true;
    if (i8 == MAGICTYPEDATA_NULL) return;
    (*include)[i8]=true;
    if (i9 == MAGICTYPEDATA_NULL) return;
    (*include)[i9]=true;
    if (i10 == MAGICTYPEDATA_NULL) return;
    (*include)[i10]=true;
    if (i11 == MAGICTYPEDATA_NULL) return;
    (*include)[i11]=true;
    if (i12 == MAGICTYPEDATA_NULL) return;
    (*include)[i12]=true;
    if (i13 == MAGICTYPEDATA_NULL) return;
    (*include)[i13]=true;
    if (i14 == MAGICTYPEDATA_NULL) return;
    (*include)[i14]=true;
    if (i15 == MAGICTYPEDATA_NULL) return;
    (*include)[i15]=true;
    if (i16 == MAGICTYPEDATA_NULL) return;
    (*include)[i16]=true;
    if (i17 == MAGICTYPEDATA_NULL) return;
    (*include)[i17]=true;
    if (i18 == MAGICTYPEDATA_NULL) return;
    (*include)[i18]=true;
    if (i19 == MAGICTYPEDATA_NULL) return;
    (*include)[i19]=true;
    if (i20 == MAGICTYPEDATA_NULL) return;
    (*include)[i20]=true;
    if (i21 == MAGICTYPEDATA_NULL) return;
    (*include)[i21]=true;
    if (i22 == MAGICTYPEDATA_NULL) return;
    (*include)[i22]=true;

        }
    
        template <class Manip>
        CMagicTypeData_cus_equal_list<Manip>::CMagicTypeData_cus_equal_list
                (const CMagicTypeData* o, const char* d, const char* c, Manip m, bool i1, bool i2, bool i3, bool i4, bool i5, bool i6, bool i7, bool i8, bool i9, bool i10, bool i11, bool i12, bool i13, bool i14, bool i15, bool i16, bool i17, bool i18, bool i19, bool i20, bool i21, bool i22)
        {
            delim = d;
            comp = c;
            manip = m;
            del_vector = true;
            obj = o;
            include = new std::vector<bool>(22, false);
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

        }
    
        template <class Manip>
        CMagicTypeData_cus_equal_list<Manip>::CMagicTypeData_cus_equal_list
                (const CMagicTypeData* o, const char* d, const char* c, Manip m, CMagicTypeData_enum i1, CMagicTypeData_enum i2, CMagicTypeData_enum i3, CMagicTypeData_enum i4, CMagicTypeData_enum i5, CMagicTypeData_enum i6, CMagicTypeData_enum i7, CMagicTypeData_enum i8, CMagicTypeData_enum i9, CMagicTypeData_enum i10, CMagicTypeData_enum i11, CMagicTypeData_enum i12, CMagicTypeData_enum i13, CMagicTypeData_enum i14, CMagicTypeData_enum i15, CMagicTypeData_enum i16, CMagicTypeData_enum i17, CMagicTypeData_enum i18, CMagicTypeData_enum i19, CMagicTypeData_enum i20, CMagicTypeData_enum i21, CMagicTypeData_enum i22)
        {
            delim = d;
            comp = c;
            manip = m;
            del_vector = true;
            obj = o;
            include = new std::vector<bool>(22, false);
        (*include)[i1]=true;
    if (i2 == MAGICTYPEDATA_NULL) return;
    (*include)[i2]=true;
    if (i3 == MAGICTYPEDATA_NULL) return;
    (*include)[i3]=true;
    if (i4 == MAGICTYPEDATA_NULL) return;
    (*include)[i4]=true;
    if (i5 == MAGICTYPEDATA_NULL) return;
    (*include)[i5]=true;
    if (i6 == MAGICTYPEDATA_NULL) return;
    (*include)[i6]=true;
    if (i7 == MAGICTYPEDATA_NULL) return;
    (*include)[i7]=true;
    if (i8 == MAGICTYPEDATA_NULL) return;
    (*include)[i8]=true;
    if (i9 == MAGICTYPEDATA_NULL) return;
    (*include)[i9]=true;
    if (i10 == MAGICTYPEDATA_NULL) return;
    (*include)[i10]=true;
    if (i11 == MAGICTYPEDATA_NULL) return;
    (*include)[i11]=true;
    if (i12 == MAGICTYPEDATA_NULL) return;
    (*include)[i12]=true;
    if (i13 == MAGICTYPEDATA_NULL) return;
    (*include)[i13]=true;
    if (i14 == MAGICTYPEDATA_NULL) return;
    (*include)[i14]=true;
    if (i15 == MAGICTYPEDATA_NULL) return;
    (*include)[i15]=true;
    if (i16 == MAGICTYPEDATA_NULL) return;
    (*include)[i16]=true;
    if (i17 == MAGICTYPEDATA_NULL) return;
    (*include)[i17]=true;
    if (i18 == MAGICTYPEDATA_NULL) return;
    (*include)[i18]=true;
    if (i19 == MAGICTYPEDATA_NULL) return;
    (*include)[i19]=true;
    if (i20 == MAGICTYPEDATA_NULL) return;
    (*include)[i20]=true;
    if (i21 == MAGICTYPEDATA_NULL) return;
    (*include)[i21]=true;
    if (i22 == MAGICTYPEDATA_NULL) return;
    (*include)[i22]=true;

        }
    
        template <class Manip>
        std::ostream& operator <<(std::ostream& s, const CMagicTypeData_value_list<Manip>& obj)
        {
        s << obj.manip << obj.obj->id << obj.delim;
    s << obj.manip << obj.obj->name << obj.delim;
    s << obj.manip << obj.obj->sort << obj.delim;
    s << obj.manip << obj.obj->begin_delay_ms << obj.delim;
    s << obj.manip << obj.obj->end_delay_ms << obj.delim;
    s << obj.manip << obj.obj->cool_down_ms << obj.delim;
    s << obj.manip << obj.obj->cost_type1 << obj.delim;
    s << obj.manip << obj.obj->cost_value1 << obj.delim;
    s << obj.manip << obj.obj->cost_type2 << obj.delim;
    s << obj.manip << obj.obj->cost_value2 << obj.delim;
    s << obj.manip << obj.obj->range_distance << obj.delim;
    s << obj.manip << obj.obj->target_type << obj.delim;
    s << obj.manip << obj.obj->range_type << obj.delim;
    s << obj.manip << obj.obj->range_x << obj.delim;
    s << obj.manip << obj.obj->range_y << obj.delim;
    s << obj.manip << obj.obj->damage_id << obj.delim;
    s << obj.manip << obj.obj->atker_distance << obj.delim;
    s << obj.manip << obj.obj->atker_duration << obj.delim;
    s << obj.manip << obj.obj->victim_distance << obj.delim;
    s << obj.manip << obj.obj->victim_duration << obj.delim;
    s << obj.manip << obj.obj->status_id << obj.delim;
    s << obj.manip << obj.obj->status_rate;
            return s;
        }
    
        template <class Manip>
        std::ostream& operator <<(std::ostream& s, const CMagicTypeData_field_list<Manip>& obj)
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
    s << obj.manip << '`' << obj.obj->names[21] << '`';
            return s;
        }
    
        template <class Manip>
        std::ostream& operator <<(std::ostream& s, const CMagicTypeData_equal_list<Manip>& obj)
        {
        s << '`' << obj.obj->names[0] << '`' << obj.comp << obj.manip << obj.obj->id << obj.delim;
    s << '`' << obj.obj->names[1] << '`' << obj.comp << obj.manip << obj.obj->name << obj.delim;
    s << '`' << obj.obj->names[2] << '`' << obj.comp << obj.manip << obj.obj->sort << obj.delim;
    s << '`' << obj.obj->names[3] << '`' << obj.comp << obj.manip << obj.obj->begin_delay_ms << obj.delim;
    s << '`' << obj.obj->names[4] << '`' << obj.comp << obj.manip << obj.obj->end_delay_ms << obj.delim;
    s << '`' << obj.obj->names[5] << '`' << obj.comp << obj.manip << obj.obj->cool_down_ms << obj.delim;
    s << '`' << obj.obj->names[6] << '`' << obj.comp << obj.manip << obj.obj->cost_type1 << obj.delim;
    s << '`' << obj.obj->names[7] << '`' << obj.comp << obj.manip << obj.obj->cost_value1 << obj.delim;
    s << '`' << obj.obj->names[8] << '`' << obj.comp << obj.manip << obj.obj->cost_type2 << obj.delim;
    s << '`' << obj.obj->names[9] << '`' << obj.comp << obj.manip << obj.obj->cost_value2 << obj.delim;
    s << '`' << obj.obj->names[10] << '`' << obj.comp << obj.manip << obj.obj->range_distance << obj.delim;
    s << '`' << obj.obj->names[11] << '`' << obj.comp << obj.manip << obj.obj->target_type << obj.delim;
    s << '`' << obj.obj->names[12] << '`' << obj.comp << obj.manip << obj.obj->range_type << obj.delim;
    s << '`' << obj.obj->names[13] << '`' << obj.comp << obj.manip << obj.obj->range_x << obj.delim;
    s << '`' << obj.obj->names[14] << '`' << obj.comp << obj.manip << obj.obj->range_y << obj.delim;
    s << '`' << obj.obj->names[15] << '`' << obj.comp << obj.manip << obj.obj->damage_id << obj.delim;
    s << '`' << obj.obj->names[16] << '`' << obj.comp << obj.manip << obj.obj->atker_distance << obj.delim;
    s << '`' << obj.obj->names[17] << '`' << obj.comp << obj.manip << obj.obj->atker_duration << obj.delim;
    s << '`' << obj.obj->names[18] << '`' << obj.comp << obj.manip << obj.obj->victim_distance << obj.delim;
    s << '`' << obj.obj->names[19] << '`' << obj.comp << obj.manip << obj.obj->victim_duration << obj.delim;
    s << '`' << obj.obj->names[20] << '`' << obj.comp << obj.manip << obj.obj->status_id << obj.delim;
    s << '`' << obj.obj->names[21] << '`' << obj.comp << obj.manip << obj.obj->status_rate;
            return s;
        }
    
        template <class Manip>
        std::ostream& operator <<(std::ostream& s, const CMagicTypeData_cus_value_list<Manip>& obj)
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
      s << obj.manip << obj.obj->sort;
      before = true; 
     } 
    if ((*obj.include)[3]) { 
      if (before) s << obj.delim;
      s << obj.manip << obj.obj->begin_delay_ms;
      before = true; 
     } 
    if ((*obj.include)[4]) { 
      if (before) s << obj.delim;
      s << obj.manip << obj.obj->end_delay_ms;
      before = true; 
     } 
    if ((*obj.include)[5]) { 
      if (before) s << obj.delim;
      s << obj.manip << obj.obj->cool_down_ms;
      before = true; 
     } 
    if ((*obj.include)[6]) { 
      if (before) s << obj.delim;
      s << obj.manip << obj.obj->cost_type1;
      before = true; 
     } 
    if ((*obj.include)[7]) { 
      if (before) s << obj.delim;
      s << obj.manip << obj.obj->cost_value1;
      before = true; 
     } 
    if ((*obj.include)[8]) { 
      if (before) s << obj.delim;
      s << obj.manip << obj.obj->cost_type2;
      before = true; 
     } 
    if ((*obj.include)[9]) { 
      if (before) s << obj.delim;
      s << obj.manip << obj.obj->cost_value2;
      before = true; 
     } 
    if ((*obj.include)[10]) { 
      if (before) s << obj.delim;
      s << obj.manip << obj.obj->range_distance;
      before = true; 
     } 
    if ((*obj.include)[11]) { 
      if (before) s << obj.delim;
      s << obj.manip << obj.obj->target_type;
      before = true; 
     } 
    if ((*obj.include)[12]) { 
      if (before) s << obj.delim;
      s << obj.manip << obj.obj->range_type;
      before = true; 
     } 
    if ((*obj.include)[13]) { 
      if (before) s << obj.delim;
      s << obj.manip << obj.obj->range_x;
      before = true; 
     } 
    if ((*obj.include)[14]) { 
      if (before) s << obj.delim;
      s << obj.manip << obj.obj->range_y;
      before = true; 
     } 
    if ((*obj.include)[15]) { 
      if (before) s << obj.delim;
      s << obj.manip << obj.obj->damage_id;
      before = true; 
     } 
    if ((*obj.include)[16]) { 
      if (before) s << obj.delim;
      s << obj.manip << obj.obj->atker_distance;
      before = true; 
     } 
    if ((*obj.include)[17]) { 
      if (before) s << obj.delim;
      s << obj.manip << obj.obj->atker_duration;
      before = true; 
     } 
    if ((*obj.include)[18]) { 
      if (before) s << obj.delim;
      s << obj.manip << obj.obj->victim_distance;
      before = true; 
     } 
    if ((*obj.include)[19]) { 
      if (before) s << obj.delim;
      s << obj.manip << obj.obj->victim_duration;
      before = true; 
     } 
    if ((*obj.include)[20]) { 
      if (before) s << obj.delim;
      s << obj.manip << obj.obj->status_id;
      before = true; 
     } 
    if ((*obj.include)[21]) { 
      if (before) s << obj.delim;
      s << obj.manip << obj.obj->status_rate;
     } 

            return s;
        }
    
        template <class Manip>
        std::ostream& operator <<(std::ostream& s, const CMagicTypeData_cus_field_list<Manip>& obj)
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
     } 

            return s;
        }
    
        template <class Manip>
        std::ostream& operator <<(std::ostream& s, const CMagicTypeData_cus_equal_list<Manip>& obj)
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
      s << '`' << obj.obj->names[2] << '`' << obj.comp         << obj.manip << obj.obj->sort;
      before = true; 
     } 
    if ((*obj.include)[3]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[3] << '`' << obj.comp         << obj.manip << obj.obj->begin_delay_ms;
      before = true; 
     } 
    if ((*obj.include)[4]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[4] << '`' << obj.comp         << obj.manip << obj.obj->end_delay_ms;
      before = true; 
     } 
    if ((*obj.include)[5]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[5] << '`' << obj.comp         << obj.manip << obj.obj->cool_down_ms;
      before = true; 
     } 
    if ((*obj.include)[6]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[6] << '`' << obj.comp         << obj.manip << obj.obj->cost_type1;
      before = true; 
     } 
    if ((*obj.include)[7]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[7] << '`' << obj.comp         << obj.manip << obj.obj->cost_value1;
      before = true; 
     } 
    if ((*obj.include)[8]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[8] << '`' << obj.comp         << obj.manip << obj.obj->cost_type2;
      before = true; 
     } 
    if ((*obj.include)[9]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[9] << '`' << obj.comp         << obj.manip << obj.obj->cost_value2;
      before = true; 
     } 
    if ((*obj.include)[10]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[10] << '`' << obj.comp         << obj.manip << obj.obj->range_distance;
      before = true; 
     } 
    if ((*obj.include)[11]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[11] << '`' << obj.comp         << obj.manip << obj.obj->target_type;
      before = true; 
     } 
    if ((*obj.include)[12]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[12] << '`' << obj.comp         << obj.manip << obj.obj->range_type;
      before = true; 
     } 
    if ((*obj.include)[13]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[13] << '`' << obj.comp         << obj.manip << obj.obj->range_x;
      before = true; 
     } 
    if ((*obj.include)[14]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[14] << '`' << obj.comp         << obj.manip << obj.obj->range_y;
      before = true; 
     } 
    if ((*obj.include)[15]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[15] << '`' << obj.comp         << obj.manip << obj.obj->damage_id;
      before = true; 
     } 
    if ((*obj.include)[16]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[16] << '`' << obj.comp         << obj.manip << obj.obj->atker_distance;
      before = true; 
     } 
    if ((*obj.include)[17]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[17] << '`' << obj.comp         << obj.manip << obj.obj->atker_duration;
      before = true; 
     } 
    if ((*obj.include)[18]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[18] << '`' << obj.comp         << obj.manip << obj.obj->victim_distance;
      before = true; 
     } 
    if ((*obj.include)[19]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[19] << '`' << obj.comp         << obj.manip << obj.obj->victim_duration;
      before = true; 
     } 
    if ((*obj.include)[20]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[20] << '`' << obj.comp         << obj.manip << obj.obj->status_id;
      before = true; 
     } 
    if ((*obj.include)[21]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[21] << '`' << obj.comp         << obj.manip << obj.obj->status_rate;
     } 

            return s;
        }
    
        template <class Manip>
        inline CMagicTypeData_value_list<Manip> CMagicTypeData::value_list(const char* d, Manip m) const
                { return CMagicTypeData_value_list<Manip> (this, d, m); } 
    
        template <class Manip>
        inline CMagicTypeData_field_list<Manip> CMagicTypeData::field_list(const char* d, Manip m) const
                { return CMagicTypeData_field_list<Manip> (this, d, m); } 
    
        template <class Manip>
        inline CMagicTypeData_equal_list<Manip> CMagicTypeData::equal_list(const char* d, const char* c, Manip m) const
                { return CMagicTypeData_equal_list<Manip> (this, d, c, m); } 
    
        template <class Manip>
        inline CMagicTypeData_cus_value_list<Manip> CMagicTypeData::value_list(const char* d, Manip m,
                bool i1, bool i2, bool i3, bool i4, bool i5, bool i6, bool i7, bool i8, bool i9, bool i10, bool i11, bool i12, bool i13, bool i14, bool i15, bool i16, bool i17, bool i18, bool i19, bool i20, bool i21, bool i22) const
                { return CMagicTypeData_cus_value_list<Manip> (this, d, m, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15, i16, i17, i18, i19, i20, i21, i22); }
    
        template <class Manip>
        inline CMagicTypeData_cus_field_list<Manip> CMagicTypeData::field_list(const char* d, Manip m,
                bool i1, bool i2, bool i3, bool i4, bool i5, bool i6, bool i7, bool i8, bool i9, bool i10, bool i11, bool i12, bool i13, bool i14, bool i15, bool i16, bool i17, bool i18, bool i19, bool i20, bool i21, bool i22) const
                { return CMagicTypeData_cus_field_list<Manip> (this, d, m, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15, i16, i17, i18, i19, i20, i21, i22); }
    
        template <class Manip>
        inline CMagicTypeData_cus_equal_list<Manip> CMagicTypeData::equal_list(const char* d, const char* c, Manip m,
                bool i1, bool i2, bool i3, bool i4, bool i5, bool i6, bool i7, bool i8, bool i9, bool i10, bool i11, bool i12, bool i13, bool i14, bool i15, bool i16, bool i17, bool i18, bool i19, bool i20, bool i21, bool i22) const
                { return CMagicTypeData_cus_equal_list<Manip> (this, d, c, m, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15, i16, i17, i18, i19, i20, i21, i22); } 
    
        template <class Manip>
        inline CMagicTypeData_cus_value_list<Manip> CMagicTypeData::value_list(const char* d, Manip m,
                CMagicTypeData_enum i1, CMagicTypeData_enum i2, CMagicTypeData_enum i3, CMagicTypeData_enum i4, CMagicTypeData_enum i5, CMagicTypeData_enum i6, CMagicTypeData_enum i7, CMagicTypeData_enum i8, CMagicTypeData_enum i9, CMagicTypeData_enum i10, CMagicTypeData_enum i11, CMagicTypeData_enum i12, CMagicTypeData_enum i13, CMagicTypeData_enum i14, CMagicTypeData_enum i15, CMagicTypeData_enum i16, CMagicTypeData_enum i17, CMagicTypeData_enum i18, CMagicTypeData_enum i19, CMagicTypeData_enum i20, CMagicTypeData_enum i21, CMagicTypeData_enum i22) const
                { return CMagicTypeData_cus_value_list<Manip> (this, d, m, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15, i16, i17, i18, i19, i20, i21, i22); } 
    
        template <class Manip>
        inline CMagicTypeData_cus_field_list<Manip> CMagicTypeData::field_list(const char* d, Manip m,
                CMagicTypeData_enum i1, CMagicTypeData_enum i2, CMagicTypeData_enum i3, CMagicTypeData_enum i4, CMagicTypeData_enum i5, CMagicTypeData_enum i6, CMagicTypeData_enum i7, CMagicTypeData_enum i8, CMagicTypeData_enum i9, CMagicTypeData_enum i10, CMagicTypeData_enum i11, CMagicTypeData_enum i12, CMagicTypeData_enum i13, CMagicTypeData_enum i14, CMagicTypeData_enum i15, CMagicTypeData_enum i16, CMagicTypeData_enum i17, CMagicTypeData_enum i18, CMagicTypeData_enum i19, CMagicTypeData_enum i20, CMagicTypeData_enum i21, CMagicTypeData_enum i22) const
                { return CMagicTypeData_cus_field_list<Manip> (this, d, m, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15, i16, i17, i18, i19, i20, i21, i22); } 
    
        template <class Manip>
        inline CMagicTypeData_cus_equal_list<Manip> CMagicTypeData::equal_list(const char* d, const char* c, Manip m, 
                CMagicTypeData_enum i1, CMagicTypeData_enum i2, CMagicTypeData_enum i3, CMagicTypeData_enum i4, CMagicTypeData_enum i5, CMagicTypeData_enum i6, CMagicTypeData_enum i7, CMagicTypeData_enum i8, CMagicTypeData_enum i9, CMagicTypeData_enum i10, CMagicTypeData_enum i11, CMagicTypeData_enum i12, CMagicTypeData_enum i13, CMagicTypeData_enum i14, CMagicTypeData_enum i15, CMagicTypeData_enum i16, CMagicTypeData_enum i17, CMagicTypeData_enum i18, CMagicTypeData_enum i19, CMagicTypeData_enum i20, CMagicTypeData_enum i21, CMagicTypeData_enum i22) const
                { return CMagicTypeData_cus_equal_list<Manip> (this, d, c, m, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, i13, i14, i15, i16, i17, i18, i19, i20, i21, i22); } 
    
        template <class Manip>
        inline CMagicTypeData_cus_value_list<Manip> CMagicTypeData::value_list(const char* d, Manip m,
                std::vector<bool> *i) const
                { return CMagicTypeData_cus_value_list<Manip> (this, d, m, i); }
    
        template <class Manip>
        inline CMagicTypeData_cus_field_list<Manip> CMagicTypeData::field_list(const char* d, Manip m,
                std::vector<bool> *i) const
                { return CMagicTypeData_cus_field_list<Manip> (this, d, m, i); }
    
        template <class Manip>
        inline CMagicTypeData_cus_equal_list<Manip> CMagicTypeData::equal_list(const char* d, const char* c, Manip m,
                std::vector<bool> *i) const
                { return CMagicTypeData_cus_equal_list<Manip> (this, d, c, m, i); }
    
        template <class Manip>
        inline CMagicTypeData_cus_value_list<Manip> 
        CMagicTypeData::value_list(const char* d, Manip m, mysqlpp::sql_cmp_type /*sc*/) const
                { return value_list(d, m, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true); }
    
        template <class Manip>
        inline CMagicTypeData_cus_field_list<Manip> 
        CMagicTypeData::field_list(const char* d, Manip m, mysqlpp::sql_cmp_type /*sc*/) const
                { return field_list(d, m, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true); }
    
        template <class Manip>
        inline CMagicTypeData_cus_equal_list<Manip> 
        CMagicTypeData::equal_list(const char* d, const char* c, Manip m, mysqlpp::sql_cmp_type /*sc*/) const
                { return equal_list(d, c, m, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true); }
    
        template <mysqlpp::sql_dummy_type dummy>
        void populate_CMagicTypeData(CMagicTypeData *s, const mysqlpp::Row &row)
        {
            mysqlpp::NoExceptions ignore_schema_mismatches(row);
        s->id = row["id"].conv(sql_bigint_unsigned());
    s->name = row["name"].conv(sql_char());
    s->sort = row["sort"].conv(sql_int_unsigned());
    s->begin_delay_ms = row["begin_delay_ms"].conv(sql_int_unsigned());
    s->end_delay_ms = row["end_delay_ms"].conv(sql_int_unsigned());
    s->cool_down_ms = row["cool_down_ms"].conv(sql_int_unsigned());
    s->cost_type1 = row["cost_type1"].conv(sql_int_unsigned());
    s->cost_value1 = row["cost_value1"].conv(sql_int_unsigned());
    s->cost_type2 = row["cost_type2"].conv(sql_int_unsigned());
    s->cost_value2 = row["cost_value2"].conv(sql_int_unsigned());
    s->range_distance = row["range_distance"].conv(sql_float());
    s->target_type = row["target_type"].conv(sql_int_unsigned());
    s->range_type = row["range_type"].conv(sql_int_unsigned());
    s->range_x = row["range_x"].conv(sql_float());
    s->range_y = row["range_y"].conv(sql_float());
    s->damage_id = row["damage_id"].conv(sql_int_unsigned());
    s->atker_distance = row["atker_distance"].conv(sql_int_unsigned());
    s->atker_duration = row["atker_duration"].conv(sql_int_unsigned());
    s->victim_distance = row["victim_distance"].conv(sql_int_unsigned());
    s->victim_duration = row["victim_duration"].conv(sql_int_unsigned());
    s->status_id = row["status_id"].conv(sql_int_unsigned());
    s->status_rate = row["status_rate"].conv(sql_int_unsigned());
        }
    
        inline CMagicTypeData::CMagicTypeData(const mysqlpp::Row& row) :
        table_override_(0)
                { populate_CMagicTypeData<mysqlpp::sql_dummy>(this, row); }
        inline void CMagicTypeData::set(const mysqlpp::Row& row)
        {
            table_override_ = 0;
            populate_CMagicTypeData<mysqlpp::sql_dummy>(this, row);
        }
    
        template <mysqlpp::sql_dummy_type dummy> 
 int sql_compare_CMagicTypeData(const CMagicTypeData &x, const CMagicTypeData &y) { 
     int cmp; \
    cmp = mysqlpp::sql_cmp(x.id, y.id ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.name, y.name ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.sort, y.sort ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.begin_delay_ms, y.begin_delay_ms ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.end_delay_ms, y.end_delay_ms ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.cool_down_ms, y.cool_down_ms ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.cost_type1, y.cost_type1 ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.cost_value1, y.cost_value1 ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.cost_type2, y.cost_type2 ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.cost_value2, y.cost_value2 ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.range_distance, y.range_distance ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.target_type, y.target_type ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.range_type, y.range_type ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.range_x, y.range_x ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.range_y, y.range_y ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.damage_id, y.damage_id ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.atker_distance, y.atker_distance ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.atker_duration, y.atker_duration ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.victim_distance, y.victim_distance ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.victim_duration, y.victim_duration ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.status_id, y.status_id ); \
    if (cmp) return cmp; \
    return mysqlpp::sql_cmp(x.status_rate, y.status_rate); 
 } 
 template <mysqlpp::sql_dummy_type dummy> 
 int compare (const CMagicTypeData &x, const CMagicTypeData &y) { 
     int cmp; \
    cmp = mysqlpp::sql_cmp(x.id, y.id ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.name, y.name ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.sort, y.sort ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.begin_delay_ms, y.begin_delay_ms ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.end_delay_ms, y.end_delay_ms ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.cool_down_ms, y.cool_down_ms ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.cost_type1, y.cost_type1 ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.cost_value1, y.cost_value1 ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.cost_type2, y.cost_type2 ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.cost_value2, y.cost_value2 ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.range_distance, y.range_distance ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.target_type, y.target_type ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.range_type, y.range_type ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.range_x, y.range_x ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.range_y, y.range_y ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.damage_id, y.damage_id ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.atker_distance, y.atker_distance ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.atker_duration, y.atker_duration ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.victim_distance, y.victim_distance ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.victim_duration, y.victim_duration ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.status_id, y.status_id ); \
    if (cmp) return cmp; \
    return mysqlpp::sql_cmp(x.status_rate, y.status_rate); 
 }

#endif	//end of define _MAGIC_TYPE_DATA_H_