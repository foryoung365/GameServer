////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author: 	Fu Yan
// Created: 	2015-08-17
// Describe: 	Specailized SQL structure of table gs_role_type, 
//				generate by genSsqls.py, !!!DO NOT EDIT!!!
////////////////////////////////////////////////////////////////////////
#ifndef _ROLE_TYPE_DATA_H_
#define _ROLE_TYPE_DATA_H_

#include <mysql++.h>
#include <ssqls.h>

using namespace mysqlpp;

struct CRoleTypeData; 
    
        enum CRoleTypeData_enum { 
        ROLETYPEDATA_ID,
    ROLETYPEDATA_NAME,
    ROLETYPEDATA_GENDER,
    ROLETYPEDATA_PROFESSION,
    ROLETYPEDATA_BASE_LEVEL,
    ROLETYPEDATA_MAX_LEVEL,
    ROLETYPEDATA_LENGTH,
    ROLETYPEDATA_WIDTH,
    ROLETYPEDATA_HEIGHT,
    ROLETYPEDATA_BASE_LIFE,
    ROLETYPEDATA_BASE_MANA,
    ROLETYPEDATA_BASE_SPEED,
        ROLETYPEDATA_NULL 
        }; 
    
        template <class Manip>
        class CRoleTypeData_value_list { 
        public: 
        const CRoleTypeData* obj;
        const char* delim;
        Manip manip;
        public: 
        CRoleTypeData_value_list (const CRoleTypeData* o, const char* d, Manip m) :
        obj(o), delim(d), manip(m) { } 
        };
    
        template <class Manip>
        class CRoleTypeData_field_list {
        public: 
        const CRoleTypeData* obj; 
        const char* delim;
        Manip manip;
        public: 
        CRoleTypeData_field_list (const CRoleTypeData* o, const char* d, Manip m) :
        obj(o), delim(d), manip(m) { } 
        };
    
        template <class Manip>
        class CRoleTypeData_equal_list { 
        public: 
        const CRoleTypeData* obj;
        const char* delim;
        const char* comp;
        Manip manip;
        public: 
        CRoleTypeData_equal_list (const CRoleTypeData* o, const char* d, const char* c, Manip m) :
        obj(o), delim(d), comp(c), manip(m) { }
        };
    
        template <class Manip>
        class CRoleTypeData_cus_value_list {
        public:
        const CRoleTypeData* obj;
        std::vector<bool> *include;
        bool del_vector;
        const char* delim;
        Manip manip;
        public: 
        ~CRoleTypeData_cus_value_list () {if (del_vector) delete include;} 
        CRoleTypeData_cus_value_list (const CRoleTypeData* o, const char* d, Manip m, bool i1, bool i2, bool i3, bool i4, bool i5, bool i6, bool i7, bool i8, bool i9, bool i10, bool i11, bool i12);
        CRoleTypeData_cus_value_list (const CRoleTypeData* o, const char* d, Manip m, CRoleTypeData_enum i1, CRoleTypeData_enum i2, CRoleTypeData_enum i3, CRoleTypeData_enum i4, CRoleTypeData_enum i5, CRoleTypeData_enum i6, CRoleTypeData_enum i7, CRoleTypeData_enum i8, CRoleTypeData_enum i9, CRoleTypeData_enum i10, CRoleTypeData_enum i11, CRoleTypeData_enum i12); 
        CRoleTypeData_cus_value_list (const CRoleTypeData* o, const char* d, Manip m ,std::vector<bool>* i) :
        obj(o), include(i), del_vector(false), delim(d), manip(m) { }
        };
    
        template <class Manip>
        class CRoleTypeData_cus_field_list { 
        public:
        const CRoleTypeData* obj; 
        std::vector<bool> *include; 
        bool del_vector; 
        const char* delim;
        Manip manip;
        public: 
        ~CRoleTypeData_cus_field_list () {if (del_vector) delete include;} 
        CRoleTypeData_cus_field_list (const CRoleTypeData* o, const char* d, Manip m, bool i1, bool i2, bool i3, bool i4, bool i5, bool i6, bool i7, bool i8, bool i9, bool i10, bool i11, bool i12); 
        CRoleTypeData_cus_field_list (const CRoleTypeData* o, const char* d, Manip m, CRoleTypeData_enum i1, CRoleTypeData_enum i2, CRoleTypeData_enum i3, CRoleTypeData_enum i4, CRoleTypeData_enum i5, CRoleTypeData_enum i6, CRoleTypeData_enum i7, CRoleTypeData_enum i8, CRoleTypeData_enum i9, CRoleTypeData_enum i10, CRoleTypeData_enum i11, CRoleTypeData_enum i12); 
        CRoleTypeData_cus_field_list (const CRoleTypeData* o, const char* d, Manip m, std::vector<bool> *i) :
        obj(o), include(i), del_vector(false), delim(d), manip(m) { }
        };
    
        template <class Manip>
        class CRoleTypeData_cus_equal_list {
        public:
        const CRoleTypeData* obj;
        std::vector<bool> *include;
        bool del_vector;
        const char* delim;
        const char* comp;
        Manip manip;
        public:
        ~CRoleTypeData_cus_equal_list () {if (del_vector) delete include;}
        CRoleTypeData_cus_equal_list (const CRoleTypeData* o, const char* d, const char* c, Manip m, bool i1, bool i2, bool i3, bool i4, bool i5, bool i6, bool i7, bool i8, bool i9, bool i10, bool i11, bool i12); 
        CRoleTypeData_cus_equal_list (const CRoleTypeData* o, const char* d, const char* c, Manip m, CRoleTypeData_enum i1, CRoleTypeData_enum i2, CRoleTypeData_enum i3, CRoleTypeData_enum i4, CRoleTypeData_enum i5, CRoleTypeData_enum i6, CRoleTypeData_enum i7, CRoleTypeData_enum i8, CRoleTypeData_enum i9, CRoleTypeData_enum i10, CRoleTypeData_enum i11, CRoleTypeData_enum i12); 
        CRoleTypeData_cus_equal_list (const CRoleTypeData* o, const char* d, const char* c, Manip m, std::vector<bool> *i) :
        obj(o), include(i), del_vector(false), delim(d), comp(c), manip(m) { }
        };
    
        template <mysqlpp::sql_dummy_type dummy> int sql_compare_CRoleTypeData(const CRoleTypeData&, const CRoleTypeData&);
    
        struct CRoleTypeData {
        sql_int_unsigned id;
    sql_char name;
    sql_tinyint gender;
    sql_int_unsigned profession;
    sql_int_unsigned base_level;
    sql_int_unsigned max_level;
    sql_float length;
    sql_float width;
    sql_float height;
    sql_int_unsigned base_life;
    sql_int_unsigned base_mana;
    sql_float base_speed; 
        CRoleTypeData() : table_override_(0) { }
        CRoleTypeData(const mysqlpp::Row& row);
        void set(const mysqlpp::Row &row);
        CRoleTypeData(const sql_int_unsigned &p1, const sql_char &p2, const sql_tinyint &p3, const sql_int_unsigned &p4, const sql_int_unsigned &p5, const sql_int_unsigned &p6, const sql_float &p7, const sql_float &p8, const sql_float &p9, const sql_int_unsigned &p10, const sql_int_unsigned &p11, const sql_float &p12) : id (p1), name (p2), gender (p3), profession (p4), base_level (p5), max_level (p6), length (p7), width (p8), height (p9), base_life (p10), base_mana (p11), base_speed (p12), table_override_(0) {}
void set(const sql_int_unsigned &p1, const sql_char &p2, const sql_tinyint &p3, const sql_int_unsigned &p4, const sql_int_unsigned &p5, const sql_int_unsigned &p6, const sql_float &p7, const sql_float &p8, const sql_float &p9, const sql_int_unsigned &p10, const sql_int_unsigned &p11, const sql_float &p12) {
table_override_ = 0;
    id = p1;\
    name = p2;\
    gender = p3;\
    profession = p4;\
    base_level = p5;\
    max_level = p6;\
    length = p7;\
    width = p8;\
    height = p9;\
    base_life = p10;\
    base_mana = p11;\
    base_speed = p12;\

}
bool operator == (const CRoleTypeData &other) const 
 {return sql_compare_CRoleTypeData<mysqlpp::sql_dummy>(*this,other) == 0;} 
 bool operator != (const CRoleTypeData &other) const 
 {return sql_compare_CRoleTypeData<mysqlpp::sql_dummy>(*this,other) != 0;} 
 bool operator > (const CRoleTypeData &other) const 
 {return sql_compare_CRoleTypeData<mysqlpp::sql_dummy>(*this,other) >  0;} 
 bool operator < (const CRoleTypeData &other) const 
 {return sql_compare_CRoleTypeData<mysqlpp::sql_dummy>(*this,other) <  0;} 
 bool operator >= (const CRoleTypeData &other) const 
 {return sql_compare_CRoleTypeData<mysqlpp::sql_dummy>(*this,other) >= 0;} 
 bool operator <= (const CRoleTypeData &other) const 
 {return sql_compare_CRoleTypeData<mysqlpp::sql_dummy>(*this,other) <= 0;} 
 int cmp (const CRoleTypeData &other) const 
 {return sql_compare_CRoleTypeData<mysqlpp::sql_dummy>(*this,other);} 
 int compare (const CRoleTypeData &other) const 
 {return sql_compare_CRoleTypeData<mysqlpp::sql_dummy>(*this,other);}

        void set(const sql_int_unsigned p1) { \
        table_override_ = 0;

        id = p1;


        } \
        CRoleTypeData(const sql_int_unsigned p1) : id(p1), table_override_(0) {}
        static const char* names[];
        static void table(const char* t) { table_ = t; }
        const char* table() const
                { return table_override_ ? table_override_ : CRoleTypeData::table_; }
        void instance_table(const char* t) { table_override_ = t; }
    
        CRoleTypeData_value_list<mysqlpp::quote_type0> value_list() const {
            return value_list(",", mysqlpp::quote);}
        CRoleTypeData_value_list<mysqlpp::quote_type0> value_list(const char* d) const {
            return value_list(d, mysqlpp::quote);}
        template <class Manip>
        CRoleTypeData_value_list<Manip> value_list(const char* d, Manip m) const;
    
        CRoleTypeData_field_list<mysqlpp::do_nothing_type0> field_list() const {
            return field_list(",", mysqlpp::do_nothing);}
        CRoleTypeData_field_list<mysqlpp::do_nothing_type0> field_list(const char* d) const {
            return field_list(d, mysqlpp::do_nothing);}
        template <class Manip>
        CRoleTypeData_field_list<Manip> field_list(const char* d, Manip m) const;
    
        CRoleTypeData_equal_list<mysqlpp::quote_type0> equal_list(const char* d = ",",
                const char* c = " = ") const
                { return equal_list(d, c, mysqlpp::quote); }
        template <class Manip>
        CRoleTypeData_equal_list<Manip> equal_list(const char* d, const char* c, Manip m) const;
    
        /* cus_data */
    
        CRoleTypeData_cus_value_list<mysqlpp::quote_type0> value_list(bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false, bool i9 = false, bool i10 = false, bool i11 = false, bool i12 = false) const
                { return value_list(",", mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12); }
        CRoleTypeData_cus_value_list<mysqlpp::quote_type0> value_list(CRoleTypeData_enum i1, CRoleTypeData_enum i2 = ROLETYPEDATA_NULL, CRoleTypeData_enum i3 = ROLETYPEDATA_NULL, CRoleTypeData_enum i4 = ROLETYPEDATA_NULL, CRoleTypeData_enum i5 = ROLETYPEDATA_NULL, CRoleTypeData_enum i6 = ROLETYPEDATA_NULL, CRoleTypeData_enum i7 = ROLETYPEDATA_NULL, CRoleTypeData_enum i8 = ROLETYPEDATA_NULL, CRoleTypeData_enum i9 = ROLETYPEDATA_NULL, CRoleTypeData_enum i10 = ROLETYPEDATA_NULL, CRoleTypeData_enum i11 = ROLETYPEDATA_NULL, CRoleTypeData_enum i12 = ROLETYPEDATA_NULL) const
                { return value_list(",", mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12); }
        CRoleTypeData_cus_value_list<mysqlpp::quote_type0> value_list(std::vector<bool> *i) const
                { return value_list(",", mysqlpp::quote, i); }
        CRoleTypeData_cus_value_list<mysqlpp::quote_type0> value_list(mysqlpp::sql_cmp_type sc) const
                { return value_list(",", mysqlpp::quote, sc); }
    
        CRoleTypeData_cus_value_list<mysqlpp::quote_type0> value_list(const char* d, bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false, bool i9 = false, bool i10 = false, bool i11 = false, bool i12 = false) const
                { return value_list(d, mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12); }
        CRoleTypeData_cus_value_list<mysqlpp::quote_type0> value_list(const char* d, CRoleTypeData_enum i1, CRoleTypeData_enum i2 = ROLETYPEDATA_NULL, CRoleTypeData_enum i3 = ROLETYPEDATA_NULL, CRoleTypeData_enum i4 = ROLETYPEDATA_NULL, CRoleTypeData_enum i5 = ROLETYPEDATA_NULL, CRoleTypeData_enum i6 = ROLETYPEDATA_NULL, CRoleTypeData_enum i7 = ROLETYPEDATA_NULL, CRoleTypeData_enum i8 = ROLETYPEDATA_NULL, CRoleTypeData_enum i9 = ROLETYPEDATA_NULL, CRoleTypeData_enum i10 = ROLETYPEDATA_NULL, CRoleTypeData_enum i11 = ROLETYPEDATA_NULL, CRoleTypeData_enum i12 = ROLETYPEDATA_NULL) const
                { return value_list(d, mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12); }
        CRoleTypeData_cus_value_list<mysqlpp::quote_type0> value_list(const char* d,
                std::vector<bool> *i) const
                { return value_list(d, mysqlpp::quote, i); }
        CRoleTypeData_cus_value_list<mysqlpp::quote_type0> value_list(const char* d,
                mysqlpp::sql_cmp_type sc) const
                { return value_list(d, mysqlpp::quote, sc); }
    
        template <class Manip>
        CRoleTypeData_cus_value_list<Manip> value_list(const char* d, Manip m,
                bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false, bool i9 = false, bool i10 = false, bool i11 = false, bool i12 = false) const;
        template <class Manip>
        CRoleTypeData_cus_value_list<Manip> value_list(const char* d, Manip m,
                CRoleTypeData_enum i1, CRoleTypeData_enum i2 = ROLETYPEDATA_NULL, CRoleTypeData_enum i3 = ROLETYPEDATA_NULL, CRoleTypeData_enum i4 = ROLETYPEDATA_NULL, CRoleTypeData_enum i5 = ROLETYPEDATA_NULL, CRoleTypeData_enum i6 = ROLETYPEDATA_NULL, CRoleTypeData_enum i7 = ROLETYPEDATA_NULL, CRoleTypeData_enum i8 = ROLETYPEDATA_NULL, CRoleTypeData_enum i9 = ROLETYPEDATA_NULL, CRoleTypeData_enum i10 = ROLETYPEDATA_NULL, CRoleTypeData_enum i11 = ROLETYPEDATA_NULL, CRoleTypeData_enum i12 = ROLETYPEDATA_NULL) const;
        template <class Manip>
        CRoleTypeData_cus_value_list<Manip> value_list(const char* d, Manip m,
                std::vector<bool>* i) const;
        template <class Manip>
        CRoleTypeData_cus_value_list<Manip> value_list(const char* d, Manip m, 
                mysqlpp::sql_cmp_type sc) const;
        /* cus field */
    
        CRoleTypeData_cus_field_list<mysqlpp::do_nothing_type0> field_list(bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false, bool i9 = false, bool i10 = false, bool i11 = false, bool i12 = false) const 
                { return field_list(",", mysqlpp::do_nothing, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12); }
        CRoleTypeData_cus_field_list<mysqlpp::do_nothing_type0> field_list(CRoleTypeData_enum i1, CRoleTypeData_enum i2 = ROLETYPEDATA_NULL, CRoleTypeData_enum i3 = ROLETYPEDATA_NULL, CRoleTypeData_enum i4 = ROLETYPEDATA_NULL, CRoleTypeData_enum i5 = ROLETYPEDATA_NULL, CRoleTypeData_enum i6 = ROLETYPEDATA_NULL, CRoleTypeData_enum i7 = ROLETYPEDATA_NULL, CRoleTypeData_enum i8 = ROLETYPEDATA_NULL, CRoleTypeData_enum i9 = ROLETYPEDATA_NULL, CRoleTypeData_enum i10 = ROLETYPEDATA_NULL, CRoleTypeData_enum i11 = ROLETYPEDATA_NULL, CRoleTypeData_enum i12 = ROLETYPEDATA_NULL) const
                { return field_list(",", mysqlpp::do_nothing, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12); }
        CRoleTypeData_cus_field_list<mysqlpp::do_nothing_type0> field_list(std::vector<bool> *i) const
                { return field_list(",", mysqlpp::do_nothing, i); }
        CRoleTypeData_cus_field_list<mysqlpp::do_nothing_type0> field_list(mysqlpp::sql_cmp_type sc) const
                { return field_list(",", mysqlpp::do_nothing, sc); }
    
        CRoleTypeData_cus_field_list<mysqlpp::do_nothing_type0> field_list(const char* d,
                bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false, bool i9 = false, bool i10 = false, bool i11 = false, bool i12 = false) const
                { return field_list(d, mysqlpp::do_nothing, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12); }
        CRoleTypeData_cus_field_list<mysqlpp::do_nothing_type0> field_list(const char* d,
                CRoleTypeData_enum i1, CRoleTypeData_enum i2 = ROLETYPEDATA_NULL, CRoleTypeData_enum i3 = ROLETYPEDATA_NULL, CRoleTypeData_enum i4 = ROLETYPEDATA_NULL, CRoleTypeData_enum i5 = ROLETYPEDATA_NULL, CRoleTypeData_enum i6 = ROLETYPEDATA_NULL, CRoleTypeData_enum i7 = ROLETYPEDATA_NULL, CRoleTypeData_enum i8 = ROLETYPEDATA_NULL, CRoleTypeData_enum i9 = ROLETYPEDATA_NULL, CRoleTypeData_enum i10 = ROLETYPEDATA_NULL, CRoleTypeData_enum i11 = ROLETYPEDATA_NULL, CRoleTypeData_enum i12 = ROLETYPEDATA_NULL) const
                { return field_list(d, mysqlpp::do_nothing, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12); }
        CRoleTypeData_cus_field_list<mysqlpp::do_nothing_type0> field_list(const char* d,
                std::vector<bool>* i) const
                { return field_list(d, mysqlpp::do_nothing, i); }
        CRoleTypeData_cus_field_list<mysqlpp::do_nothing_type0> field_list(const char* d,
                mysqlpp::sql_cmp_type sc) const
                { return field_list(d, mysqlpp::do_nothing, sc); }
    
        template <class Manip>
        CRoleTypeData_cus_field_list<Manip> field_list(const char* d, Manip m,
                bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false, bool i9 = false, bool i10 = false, bool i11 = false, bool i12 = false) const;
        template <class Manip>
        CRoleTypeData_cus_field_list<Manip> field_list(const char* d, Manip m,
                CRoleTypeData_enum i1, CRoleTypeData_enum i2 = ROLETYPEDATA_NULL, CRoleTypeData_enum i3 = ROLETYPEDATA_NULL, CRoleTypeData_enum i4 = ROLETYPEDATA_NULL, CRoleTypeData_enum i5 = ROLETYPEDATA_NULL, CRoleTypeData_enum i6 = ROLETYPEDATA_NULL, CRoleTypeData_enum i7 = ROLETYPEDATA_NULL, CRoleTypeData_enum i8 = ROLETYPEDATA_NULL, CRoleTypeData_enum i9 = ROLETYPEDATA_NULL, CRoleTypeData_enum i10 = ROLETYPEDATA_NULL, CRoleTypeData_enum i11 = ROLETYPEDATA_NULL, CRoleTypeData_enum i12 = ROLETYPEDATA_NULL) const;
        template <class Manip>
        CRoleTypeData_cus_field_list<Manip> field_list(const char* d, Manip m,
                std::vector<bool> *i) const;
        template <class Manip>
        CRoleTypeData_cus_field_list<Manip> field_list(const char* d, Manip m,
                mysqlpp::sql_cmp_type sc) const;
    
        /* cus equal */
    
        CRoleTypeData_cus_equal_list<mysqlpp::quote_type0> equal_list(bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false, bool i9 = false, bool i10 = false, bool i11 = false, bool i12 = false) const
                { return equal_list(",", " = ", mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12); }
        CRoleTypeData_cus_equal_list<mysqlpp::quote_type0> equal_list(CRoleTypeData_enum i1, CRoleTypeData_enum i2 = ROLETYPEDATA_NULL, CRoleTypeData_enum i3 = ROLETYPEDATA_NULL, CRoleTypeData_enum i4 = ROLETYPEDATA_NULL, CRoleTypeData_enum i5 = ROLETYPEDATA_NULL, CRoleTypeData_enum i6 = ROLETYPEDATA_NULL, CRoleTypeData_enum i7 = ROLETYPEDATA_NULL, CRoleTypeData_enum i8 = ROLETYPEDATA_NULL, CRoleTypeData_enum i9 = ROLETYPEDATA_NULL, CRoleTypeData_enum i10 = ROLETYPEDATA_NULL, CRoleTypeData_enum i11 = ROLETYPEDATA_NULL, CRoleTypeData_enum i12 = ROLETYPEDATA_NULL) const
                { return equal_list(",", " = ", mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12); }
        CRoleTypeData_cus_equal_list<mysqlpp::quote_type0> equal_list(std::vector<bool>* i) const
                { return equal_list(",", " = ", mysqlpp::quote, i); }
        CRoleTypeData_cus_equal_list<mysqlpp::quote_type0> equal_list(mysqlpp::sql_cmp_type sc) const
                { return equal_list(",", " = ", mysqlpp::quote, sc); }
    
        CRoleTypeData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d, bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false, bool i9 = false, bool i10 = false, bool i11 = false, bool i12 = false) const
                { return equal_list(d, " = ", mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12); }
        CRoleTypeData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d, CRoleTypeData_enum i1, CRoleTypeData_enum i2 = ROLETYPEDATA_NULL, CRoleTypeData_enum i3 = ROLETYPEDATA_NULL, CRoleTypeData_enum i4 = ROLETYPEDATA_NULL, CRoleTypeData_enum i5 = ROLETYPEDATA_NULL, CRoleTypeData_enum i6 = ROLETYPEDATA_NULL, CRoleTypeData_enum i7 = ROLETYPEDATA_NULL, CRoleTypeData_enum i8 = ROLETYPEDATA_NULL, CRoleTypeData_enum i9 = ROLETYPEDATA_NULL, CRoleTypeData_enum i10 = ROLETYPEDATA_NULL, CRoleTypeData_enum i11 = ROLETYPEDATA_NULL, CRoleTypeData_enum i12 = ROLETYPEDATA_NULL) const
                { return equal_list(d, " = ", mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12); }
        CRoleTypeData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d,
                std::vector<bool> *i) const
                { return equal_list(d, " = ", mysqlpp::quote, i); }
        CRoleTypeData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d,
                mysqlpp::sql_cmp_type sc) const
                { return equal_list(d, " = ", mysqlpp::quote, sc); }
    
        CRoleTypeData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d, const char* c,
                bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false, bool i9 = false, bool i10 = false, bool i11 = false, bool i12 = false) const
                { return equal_list(d, c, mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12); }
        CRoleTypeData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d, const char* c,
                CRoleTypeData_enum i1, CRoleTypeData_enum i2 = ROLETYPEDATA_NULL, CRoleTypeData_enum i3 = ROLETYPEDATA_NULL, CRoleTypeData_enum i4 = ROLETYPEDATA_NULL, CRoleTypeData_enum i5 = ROLETYPEDATA_NULL, CRoleTypeData_enum i6 = ROLETYPEDATA_NULL, CRoleTypeData_enum i7 = ROLETYPEDATA_NULL, CRoleTypeData_enum i8 = ROLETYPEDATA_NULL, CRoleTypeData_enum i9 = ROLETYPEDATA_NULL, CRoleTypeData_enum i10 = ROLETYPEDATA_NULL, CRoleTypeData_enum i11 = ROLETYPEDATA_NULL, CRoleTypeData_enum i12 = ROLETYPEDATA_NULL) const
                { return equal_list(d, c, mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12); }
        CRoleTypeData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d, const char* c,
                std::vector<bool> *i) const
                { return equal_list(d, c, mysqlpp::quote, i); }
        CRoleTypeData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d, const char* c,
                mysqlpp::sql_cmp_type sc) const
                { return equal_list(d, c, mysqlpp::quote, sc); }
    
        template <class Manip>
        CRoleTypeData_cus_equal_list<Manip> equal_list(const char* d, const char* c, Manip m, 
                            bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false, bool i9 = false, bool i10 = false, bool i11 = false, bool i12 = false) const;
        template <class Manip>
        CRoleTypeData_cus_equal_list<Manip> equal_list(const char* d, const char* c, Manip m, 
                            CRoleTypeData_enum i1, CRoleTypeData_enum i2 = ROLETYPEDATA_NULL, CRoleTypeData_enum i3 = ROLETYPEDATA_NULL, CRoleTypeData_enum i4 = ROLETYPEDATA_NULL, CRoleTypeData_enum i5 = ROLETYPEDATA_NULL, CRoleTypeData_enum i6 = ROLETYPEDATA_NULL, CRoleTypeData_enum i7 = ROLETYPEDATA_NULL, CRoleTypeData_enum i8 = ROLETYPEDATA_NULL, CRoleTypeData_enum i9 = ROLETYPEDATA_NULL, CRoleTypeData_enum i10 = ROLETYPEDATA_NULL, CRoleTypeData_enum i11 = ROLETYPEDATA_NULL, CRoleTypeData_enum i12 = ROLETYPEDATA_NULL) const;
        template <class Manip>
        CRoleTypeData_cus_equal_list<Manip> equal_list(const char* d, const char* c, Manip m, 
                            std::vector<bool> *i) const;
        template <class Manip>
        CRoleTypeData_cus_equal_list<Manip> equal_list(const char* d, const char* c, Manip m, 
                            mysqlpp::sql_cmp_type sc) const;
    
        private:
        static const char* table_;
        const char* table_override_;
        };
            
        template <class Manip>
        CRoleTypeData_cus_value_list<Manip>::CRoleTypeData_cus_value_list
                (const CRoleTypeData* o, const char* d, Manip m, bool i1, bool i2, bool i3, bool i4, bool i5, bool i6, bool i7, bool i8, bool i9, bool i10, bool i11, bool i12)
        {
            delim = d;
            manip = m;
            del_vector = true;
            obj = o;
            include = new std::vector<bool>(12, false);
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

        }
    
        template <class Manip>
        CRoleTypeData_cus_value_list<Manip>::CRoleTypeData_cus_value_list
                (const CRoleTypeData* o, const char* d, Manip m, CRoleTypeData_enum i1, CRoleTypeData_enum i2, CRoleTypeData_enum i3, CRoleTypeData_enum i4, CRoleTypeData_enum i5, CRoleTypeData_enum i6, CRoleTypeData_enum i7, CRoleTypeData_enum i8, CRoleTypeData_enum i9, CRoleTypeData_enum i10, CRoleTypeData_enum i11, CRoleTypeData_enum i12)
        {
            delim = d;
            manip = m;
            del_vector = true;
            obj = o;
            include = new std::vector<bool>(12, false);
        (*include)[i1]=true;
    if (i2 == ROLETYPEDATA_NULL) return;
    (*include)[i2]=true;
    if (i3 == ROLETYPEDATA_NULL) return;
    (*include)[i3]=true;
    if (i4 == ROLETYPEDATA_NULL) return;
    (*include)[i4]=true;
    if (i5 == ROLETYPEDATA_NULL) return;
    (*include)[i5]=true;
    if (i6 == ROLETYPEDATA_NULL) return;
    (*include)[i6]=true;
    if (i7 == ROLETYPEDATA_NULL) return;
    (*include)[i7]=true;
    if (i8 == ROLETYPEDATA_NULL) return;
    (*include)[i8]=true;
    if (i9 == ROLETYPEDATA_NULL) return;
    (*include)[i9]=true;
    if (i10 == ROLETYPEDATA_NULL) return;
    (*include)[i10]=true;
    if (i11 == ROLETYPEDATA_NULL) return;
    (*include)[i11]=true;
    if (i12 == ROLETYPEDATA_NULL) return;
    (*include)[i12]=true;

        }
    
        template <class Manip>
        CRoleTypeData_cus_field_list<Manip>::CRoleTypeData_cus_field_list
                (const CRoleTypeData* o, const char* d, Manip m, bool i1, bool i2, bool i3, bool i4, bool i5, bool i6, bool i7, bool i8, bool i9, bool i10, bool i11, bool i12)
        {
            delim = d;
            manip = m;
            del_vector = true;
            obj = o;
            include = new std::vector<bool>(12, false);
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

        }
    
        template <class Manip>
        CRoleTypeData_cus_field_list<Manip>::CRoleTypeData_cus_field_list
                (const CRoleTypeData* o, const char* d, Manip m, CRoleTypeData_enum i1, CRoleTypeData_enum i2, CRoleTypeData_enum i3, CRoleTypeData_enum i4, CRoleTypeData_enum i5, CRoleTypeData_enum i6, CRoleTypeData_enum i7, CRoleTypeData_enum i8, CRoleTypeData_enum i9, CRoleTypeData_enum i10, CRoleTypeData_enum i11, CRoleTypeData_enum i12)
        {
            delim = d;
            manip = m;
            del_vector = true;
            obj = o;
            include = new std::vector<bool>(12, false);
        (*include)[i1]=true;
    if (i2 == ROLETYPEDATA_NULL) return;
    (*include)[i2]=true;
    if (i3 == ROLETYPEDATA_NULL) return;
    (*include)[i3]=true;
    if (i4 == ROLETYPEDATA_NULL) return;
    (*include)[i4]=true;
    if (i5 == ROLETYPEDATA_NULL) return;
    (*include)[i5]=true;
    if (i6 == ROLETYPEDATA_NULL) return;
    (*include)[i6]=true;
    if (i7 == ROLETYPEDATA_NULL) return;
    (*include)[i7]=true;
    if (i8 == ROLETYPEDATA_NULL) return;
    (*include)[i8]=true;
    if (i9 == ROLETYPEDATA_NULL) return;
    (*include)[i9]=true;
    if (i10 == ROLETYPEDATA_NULL) return;
    (*include)[i10]=true;
    if (i11 == ROLETYPEDATA_NULL) return;
    (*include)[i11]=true;
    if (i12 == ROLETYPEDATA_NULL) return;
    (*include)[i12]=true;

        }
    
        template <class Manip>
        CRoleTypeData_cus_equal_list<Manip>::CRoleTypeData_cus_equal_list
                (const CRoleTypeData* o, const char* d, const char* c, Manip m, bool i1, bool i2, bool i3, bool i4, bool i5, bool i6, bool i7, bool i8, bool i9, bool i10, bool i11, bool i12)
        {
            delim = d;
            comp = c;
            manip = m;
            del_vector = true;
            obj = o;
            include = new std::vector<bool>(12, false);
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

        }
    
        template <class Manip>
        CRoleTypeData_cus_equal_list<Manip>::CRoleTypeData_cus_equal_list
                (const CRoleTypeData* o, const char* d, const char* c, Manip m, CRoleTypeData_enum i1, CRoleTypeData_enum i2, CRoleTypeData_enum i3, CRoleTypeData_enum i4, CRoleTypeData_enum i5, CRoleTypeData_enum i6, CRoleTypeData_enum i7, CRoleTypeData_enum i8, CRoleTypeData_enum i9, CRoleTypeData_enum i10, CRoleTypeData_enum i11, CRoleTypeData_enum i12)
        {
            delim = d;
            comp = c;
            manip = m;
            del_vector = true;
            obj = o;
            include = new std::vector<bool>(12, false);
        (*include)[i1]=true;
    if (i2 == ROLETYPEDATA_NULL) return;
    (*include)[i2]=true;
    if (i3 == ROLETYPEDATA_NULL) return;
    (*include)[i3]=true;
    if (i4 == ROLETYPEDATA_NULL) return;
    (*include)[i4]=true;
    if (i5 == ROLETYPEDATA_NULL) return;
    (*include)[i5]=true;
    if (i6 == ROLETYPEDATA_NULL) return;
    (*include)[i6]=true;
    if (i7 == ROLETYPEDATA_NULL) return;
    (*include)[i7]=true;
    if (i8 == ROLETYPEDATA_NULL) return;
    (*include)[i8]=true;
    if (i9 == ROLETYPEDATA_NULL) return;
    (*include)[i9]=true;
    if (i10 == ROLETYPEDATA_NULL) return;
    (*include)[i10]=true;
    if (i11 == ROLETYPEDATA_NULL) return;
    (*include)[i11]=true;
    if (i12 == ROLETYPEDATA_NULL) return;
    (*include)[i12]=true;

        }
    
        template <class Manip>
        std::ostream& operator <<(std::ostream& s, const CRoleTypeData_value_list<Manip>& obj)
        {
        s << obj.manip << obj.obj->id << obj.delim;
    s << obj.manip << obj.obj->name << obj.delim;
    s << obj.manip << obj.obj->gender << obj.delim;
    s << obj.manip << obj.obj->profession << obj.delim;
    s << obj.manip << obj.obj->base_level << obj.delim;
    s << obj.manip << obj.obj->max_level << obj.delim;
    s << obj.manip << obj.obj->length << obj.delim;
    s << obj.manip << obj.obj->width << obj.delim;
    s << obj.manip << obj.obj->height << obj.delim;
    s << obj.manip << obj.obj->base_life << obj.delim;
    s << obj.manip << obj.obj->base_mana << obj.delim;
    s << obj.manip << obj.obj->base_speed;
            return s;
        }
    
        template <class Manip>
        std::ostream& operator <<(std::ostream& s, const CRoleTypeData_field_list<Manip>& obj)
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
    s << obj.manip << '`' << obj.obj->names[11] << '`';
            return s;
        }
    
        template <class Manip>
        std::ostream& operator <<(std::ostream& s, const CRoleTypeData_equal_list<Manip>& obj)
        {
        s << '`' << obj.obj->names[0] << '`' << obj.comp << obj.manip << obj.obj->id << obj.delim;
    s << '`' << obj.obj->names[1] << '`' << obj.comp << obj.manip << obj.obj->name << obj.delim;
    s << '`' << obj.obj->names[2] << '`' << obj.comp << obj.manip << obj.obj->gender << obj.delim;
    s << '`' << obj.obj->names[3] << '`' << obj.comp << obj.manip << obj.obj->profession << obj.delim;
    s << '`' << obj.obj->names[4] << '`' << obj.comp << obj.manip << obj.obj->base_level << obj.delim;
    s << '`' << obj.obj->names[5] << '`' << obj.comp << obj.manip << obj.obj->max_level << obj.delim;
    s << '`' << obj.obj->names[6] << '`' << obj.comp << obj.manip << obj.obj->length << obj.delim;
    s << '`' << obj.obj->names[7] << '`' << obj.comp << obj.manip << obj.obj->width << obj.delim;
    s << '`' << obj.obj->names[8] << '`' << obj.comp << obj.manip << obj.obj->height << obj.delim;
    s << '`' << obj.obj->names[9] << '`' << obj.comp << obj.manip << obj.obj->base_life << obj.delim;
    s << '`' << obj.obj->names[10] << '`' << obj.comp << obj.manip << obj.obj->base_mana << obj.delim;
    s << '`' << obj.obj->names[11] << '`' << obj.comp << obj.manip << obj.obj->base_speed;
            return s;
        }
    
        template <class Manip>
        std::ostream& operator <<(std::ostream& s, const CRoleTypeData_cus_value_list<Manip>& obj)
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
      s << obj.manip << obj.obj->gender;
      before = true; 
     } 
    if ((*obj.include)[3]) { 
      if (before) s << obj.delim;
      s << obj.manip << obj.obj->profession;
      before = true; 
     } 
    if ((*obj.include)[4]) { 
      if (before) s << obj.delim;
      s << obj.manip << obj.obj->base_level;
      before = true; 
     } 
    if ((*obj.include)[5]) { 
      if (before) s << obj.delim;
      s << obj.manip << obj.obj->max_level;
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
      s << obj.manip << obj.obj->base_life;
      before = true; 
     } 
    if ((*obj.include)[10]) { 
      if (before) s << obj.delim;
      s << obj.manip << obj.obj->base_mana;
      before = true; 
     } 
    if ((*obj.include)[11]) { 
      if (before) s << obj.delim;
      s << obj.manip << obj.obj->base_speed;
     } 

            return s;
        }
    
        template <class Manip>
        std::ostream& operator <<(std::ostream& s, const CRoleTypeData_cus_field_list<Manip>& obj)
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
     } 

            return s;
        }
    
        template <class Manip>
        std::ostream& operator <<(std::ostream& s, const CRoleTypeData_cus_equal_list<Manip>& obj)
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
      s << '`' << obj.obj->names[2] << '`' << obj.comp         << obj.manip << obj.obj->gender;
      before = true; 
     } 
    if ((*obj.include)[3]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[3] << '`' << obj.comp         << obj.manip << obj.obj->profession;
      before = true; 
     } 
    if ((*obj.include)[4]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[4] << '`' << obj.comp         << obj.manip << obj.obj->base_level;
      before = true; 
     } 
    if ((*obj.include)[5]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[5] << '`' << obj.comp         << obj.manip << obj.obj->max_level;
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
      s << '`' << obj.obj->names[9] << '`' << obj.comp         << obj.manip << obj.obj->base_life;
      before = true; 
     } 
    if ((*obj.include)[10]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[10] << '`' << obj.comp         << obj.manip << obj.obj->base_mana;
      before = true; 
     } 
    if ((*obj.include)[11]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[11] << '`' << obj.comp         << obj.manip << obj.obj->base_speed;
     } 

            return s;
        }
    
        template <class Manip>
        inline CRoleTypeData_value_list<Manip> CRoleTypeData::value_list(const char* d, Manip m) const
                { return CRoleTypeData_value_list<Manip> (this, d, m); } 
    
        template <class Manip>
        inline CRoleTypeData_field_list<Manip> CRoleTypeData::field_list(const char* d, Manip m) const
                { return CRoleTypeData_field_list<Manip> (this, d, m); } 
    
        template <class Manip>
        inline CRoleTypeData_equal_list<Manip> CRoleTypeData::equal_list(const char* d, const char* c, Manip m) const
                { return CRoleTypeData_equal_list<Manip> (this, d, c, m); } 
    
        template <class Manip>
        inline CRoleTypeData_cus_value_list<Manip> CRoleTypeData::value_list(const char* d, Manip m,
                bool i1, bool i2, bool i3, bool i4, bool i5, bool i6, bool i7, bool i8, bool i9, bool i10, bool i11, bool i12) const
                { return CRoleTypeData_cus_value_list<Manip> (this, d, m, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12); }
    
        template <class Manip>
        inline CRoleTypeData_cus_field_list<Manip> CRoleTypeData::field_list(const char* d, Manip m,
                bool i1, bool i2, bool i3, bool i4, bool i5, bool i6, bool i7, bool i8, bool i9, bool i10, bool i11, bool i12) const
                { return CRoleTypeData_cus_field_list<Manip> (this, d, m, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12); }
    
        template <class Manip>
        inline CRoleTypeData_cus_equal_list<Manip> CRoleTypeData::equal_list(const char* d, const char* c, Manip m,
                bool i1, bool i2, bool i3, bool i4, bool i5, bool i6, bool i7, bool i8, bool i9, bool i10, bool i11, bool i12) const
                { return CRoleTypeData_cus_equal_list<Manip> (this, d, c, m, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12); } 
    
        template <class Manip>
        inline CRoleTypeData_cus_value_list<Manip> CRoleTypeData::value_list(const char* d, Manip m,
                CRoleTypeData_enum i1, CRoleTypeData_enum i2, CRoleTypeData_enum i3, CRoleTypeData_enum i4, CRoleTypeData_enum i5, CRoleTypeData_enum i6, CRoleTypeData_enum i7, CRoleTypeData_enum i8, CRoleTypeData_enum i9, CRoleTypeData_enum i10, CRoleTypeData_enum i11, CRoleTypeData_enum i12) const
                { return CRoleTypeData_cus_value_list<Manip> (this, d, m, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12); } 
    
        template <class Manip>
        inline CRoleTypeData_cus_field_list<Manip> CRoleTypeData::field_list(const char* d, Manip m,
                CRoleTypeData_enum i1, CRoleTypeData_enum i2, CRoleTypeData_enum i3, CRoleTypeData_enum i4, CRoleTypeData_enum i5, CRoleTypeData_enum i6, CRoleTypeData_enum i7, CRoleTypeData_enum i8, CRoleTypeData_enum i9, CRoleTypeData_enum i10, CRoleTypeData_enum i11, CRoleTypeData_enum i12) const
                { return CRoleTypeData_cus_field_list<Manip> (this, d, m, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12); } 
    
        template <class Manip>
        inline CRoleTypeData_cus_equal_list<Manip> CRoleTypeData::equal_list(const char* d, const char* c, Manip m, 
                CRoleTypeData_enum i1, CRoleTypeData_enum i2, CRoleTypeData_enum i3, CRoleTypeData_enum i4, CRoleTypeData_enum i5, CRoleTypeData_enum i6, CRoleTypeData_enum i7, CRoleTypeData_enum i8, CRoleTypeData_enum i9, CRoleTypeData_enum i10, CRoleTypeData_enum i11, CRoleTypeData_enum i12) const
                { return CRoleTypeData_cus_equal_list<Manip> (this, d, c, m, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12); } 
    
        template <class Manip>
        inline CRoleTypeData_cus_value_list<Manip> CRoleTypeData::value_list(const char* d, Manip m,
                std::vector<bool> *i) const
                { return CRoleTypeData_cus_value_list<Manip> (this, d, m, i); }
    
        template <class Manip>
        inline CRoleTypeData_cus_field_list<Manip> CRoleTypeData::field_list(const char* d, Manip m,
                std::vector<bool> *i) const
                { return CRoleTypeData_cus_field_list<Manip> (this, d, m, i); }
    
        template <class Manip>
        inline CRoleTypeData_cus_equal_list<Manip> CRoleTypeData::equal_list(const char* d, const char* c, Manip m,
                std::vector<bool> *i) const
                { return CRoleTypeData_cus_equal_list<Manip> (this, d, c, m, i); }
    
        template <class Manip>
        inline CRoleTypeData_cus_value_list<Manip> 
        CRoleTypeData::value_list(const char* d, Manip m, mysqlpp::sql_cmp_type /*sc*/) const
                { return value_list(d, m, true, true, true, true, true, true, true, true, true, true, true, true); }
    
        template <class Manip>
        inline CRoleTypeData_cus_field_list<Manip> 
        CRoleTypeData::field_list(const char* d, Manip m, mysqlpp::sql_cmp_type /*sc*/) const
                { return field_list(d, m, true, true, true, true, true, true, true, true, true, true, true, true); }
    
        template <class Manip>
        inline CRoleTypeData_cus_equal_list<Manip> 
        CRoleTypeData::equal_list(const char* d, const char* c, Manip m, mysqlpp::sql_cmp_type /*sc*/) const
                { return equal_list(d, c, m, true, true, true, true, true, true, true, true, true, true, true, true); }
    
        template <mysqlpp::sql_dummy_type dummy>
        void populate_CRoleTypeData(CRoleTypeData *s, const mysqlpp::Row &row)
        {
            mysqlpp::NoExceptions ignore_schema_mismatches(row);
        s->id = row["id"].conv(sql_int_unsigned());
    s->name = row["name"].conv(sql_char());
    s->gender = row["gender"].conv(sql_tinyint());
    s->profession = row["profession"].conv(sql_int_unsigned());
    s->base_level = row["base_level"].conv(sql_int_unsigned());
    s->max_level = row["max_level"].conv(sql_int_unsigned());
    s->length = row["length"].conv(sql_float());
    s->width = row["width"].conv(sql_float());
    s->height = row["height"].conv(sql_float());
    s->base_life = row["base_life"].conv(sql_int_unsigned());
    s->base_mana = row["base_mana"].conv(sql_int_unsigned());
    s->base_speed = row["base_speed"].conv(sql_float());
        }
    
        inline CRoleTypeData::CRoleTypeData(const mysqlpp::Row& row) :
        table_override_(0)
                { populate_CRoleTypeData<mysqlpp::sql_dummy>(this, row); }
        inline void CRoleTypeData::set(const mysqlpp::Row& row)
        {
            table_override_ = 0;
            populate_CRoleTypeData<mysqlpp::sql_dummy>(this, row);
        }
    
        template <mysqlpp::sql_dummy_type dummy> 
 int sql_compare_CRoleTypeData(const CRoleTypeData &x, const CRoleTypeData &y) { 
     int cmp; \
    cmp = mysqlpp::sql_cmp(x.id, y.id ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.name, y.name ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.gender, y.gender ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.profession, y.profession ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.base_level, y.base_level ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.max_level, y.max_level ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.length, y.length ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.width, y.width ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.height, y.height ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.base_life, y.base_life ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.base_mana, y.base_mana ); \
    if (cmp) return cmp; \
    return mysqlpp::sql_cmp(x.base_speed, y.base_speed); 
 } 
 template <mysqlpp::sql_dummy_type dummy> 
 int compare (const CRoleTypeData &x, const CRoleTypeData &y) { 
     int cmp; \
    cmp = mysqlpp::sql_cmp(x.id, y.id ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.name, y.name ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.gender, y.gender ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.profession, y.profession ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.base_level, y.base_level ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.max_level, y.max_level ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.length, y.length ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.width, y.width ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.height, y.height ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.base_life, y.base_life ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.base_mana, y.base_mana ); \
    if (cmp) return cmp; \
    return mysqlpp::sql_cmp(x.base_speed, y.base_speed); 
 }

#endif	//end of define _ROLE_TYPE_DATA_H_