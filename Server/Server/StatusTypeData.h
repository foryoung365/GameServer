////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author: 	Fu Yan
// Created: 	2015-08-17
// Describe: 	Specailized SQL structure of table gs_status_type, 
//				generate by genSsqls.py, !!!DO NOT EDIT!!!
////////////////////////////////////////////////////////////////////////
#ifndef _STATUS_TYPE_DATA_H_
#define _STATUS_TYPE_DATA_H_

#include <mysql++.h>
#include <ssqls.h>

using namespace mysqlpp;

struct CStatusTypeData; 
    
        enum CStatusTypeData_enum { 
        STATUSTYPEDATA_ID,
    STATUSTYPEDATA_NAME,
    STATUSTYPEDATA_STATUS_TYPE,
    STATUSTYPEDATA_HIT_RATE,
    STATUSTYPEDATA_DURATION,
    STATUSTYPEDATA_HIT_TIMES,
    STATUSTYPEDATA_POWER_TYPE,
    STATUSTYPEDATA_POWER_VALUE,
        STATUSTYPEDATA_NULL 
        }; 
    
        template <class Manip>
        class CStatusTypeData_value_list { 
        public: 
        const CStatusTypeData* obj;
        const char* delim;
        Manip manip;
        public: 
        CStatusTypeData_value_list (const CStatusTypeData* o, const char* d, Manip m) :
        obj(o), delim(d), manip(m) { } 
        };
    
        template <class Manip>
        class CStatusTypeData_field_list {
        public: 
        const CStatusTypeData* obj; 
        const char* delim;
        Manip manip;
        public: 
        CStatusTypeData_field_list (const CStatusTypeData* o, const char* d, Manip m) :
        obj(o), delim(d), manip(m) { } 
        };
    
        template <class Manip>
        class CStatusTypeData_equal_list { 
        public: 
        const CStatusTypeData* obj;
        const char* delim;
        const char* comp;
        Manip manip;
        public: 
        CStatusTypeData_equal_list (const CStatusTypeData* o, const char* d, const char* c, Manip m) :
        obj(o), delim(d), comp(c), manip(m) { }
        };
    
        template <class Manip>
        class CStatusTypeData_cus_value_list {
        public:
        const CStatusTypeData* obj;
        std::vector<bool> *include;
        bool del_vector;
        const char* delim;
        Manip manip;
        public: 
        ~CStatusTypeData_cus_value_list () {if (del_vector) delete include;} 
        CStatusTypeData_cus_value_list (const CStatusTypeData* o, const char* d, Manip m, bool i1, bool i2, bool i3, bool i4, bool i5, bool i6, bool i7, bool i8);
        CStatusTypeData_cus_value_list (const CStatusTypeData* o, const char* d, Manip m, CStatusTypeData_enum i1, CStatusTypeData_enum i2, CStatusTypeData_enum i3, CStatusTypeData_enum i4, CStatusTypeData_enum i5, CStatusTypeData_enum i6, CStatusTypeData_enum i7, CStatusTypeData_enum i8); 
        CStatusTypeData_cus_value_list (const CStatusTypeData* o, const char* d, Manip m ,std::vector<bool>* i) :
        obj(o), include(i), del_vector(false), delim(d), manip(m) { }
        };
    
        template <class Manip>
        class CStatusTypeData_cus_field_list { 
        public:
        const CStatusTypeData* obj; 
        std::vector<bool> *include; 
        bool del_vector; 
        const char* delim;
        Manip manip;
        public: 
        ~CStatusTypeData_cus_field_list () {if (del_vector) delete include;} 
        CStatusTypeData_cus_field_list (const CStatusTypeData* o, const char* d, Manip m, bool i1, bool i2, bool i3, bool i4, bool i5, bool i6, bool i7, bool i8); 
        CStatusTypeData_cus_field_list (const CStatusTypeData* o, const char* d, Manip m, CStatusTypeData_enum i1, CStatusTypeData_enum i2, CStatusTypeData_enum i3, CStatusTypeData_enum i4, CStatusTypeData_enum i5, CStatusTypeData_enum i6, CStatusTypeData_enum i7, CStatusTypeData_enum i8); 
        CStatusTypeData_cus_field_list (const CStatusTypeData* o, const char* d, Manip m, std::vector<bool> *i) :
        obj(o), include(i), del_vector(false), delim(d), manip(m) { }
        };
    
        template <class Manip>
        class CStatusTypeData_cus_equal_list {
        public:
        const CStatusTypeData* obj;
        std::vector<bool> *include;
        bool del_vector;
        const char* delim;
        const char* comp;
        Manip manip;
        public:
        ~CStatusTypeData_cus_equal_list () {if (del_vector) delete include;}
        CStatusTypeData_cus_equal_list (const CStatusTypeData* o, const char* d, const char* c, Manip m, bool i1, bool i2, bool i3, bool i4, bool i5, bool i6, bool i7, bool i8); 
        CStatusTypeData_cus_equal_list (const CStatusTypeData* o, const char* d, const char* c, Manip m, CStatusTypeData_enum i1, CStatusTypeData_enum i2, CStatusTypeData_enum i3, CStatusTypeData_enum i4, CStatusTypeData_enum i5, CStatusTypeData_enum i6, CStatusTypeData_enum i7, CStatusTypeData_enum i8); 
        CStatusTypeData_cus_equal_list (const CStatusTypeData* o, const char* d, const char* c, Manip m, std::vector<bool> *i) :
        obj(o), include(i), del_vector(false), delim(d), comp(c), manip(m) { }
        };
    
        template <mysqlpp::sql_dummy_type dummy> int sql_compare_CStatusTypeData(const CStatusTypeData&, const CStatusTypeData&);
    
        struct CStatusTypeData {
        sql_bigint_unsigned id;
    sql_char name;
    sql_int_unsigned status_type;
    sql_int_unsigned hit_rate;
    sql_int_unsigned duration;
    sql_int_unsigned hit_times;
    sql_int_unsigned power_type;
    sql_int_unsigned power_value; 
        CStatusTypeData() : table_override_(0) { }
        CStatusTypeData(const mysqlpp::Row& row);
        void set(const mysqlpp::Row &row);
        CStatusTypeData(const sql_bigint_unsigned &p1, const sql_char &p2, const sql_int_unsigned &p3, const sql_int_unsigned &p4, const sql_int_unsigned &p5, const sql_int_unsigned &p6, const sql_int_unsigned &p7, const sql_int_unsigned &p8) : id (p1), name (p2), status_type (p3), hit_rate (p4), duration (p5), hit_times (p6), power_type (p7), power_value (p8), table_override_(0) {}
void set(const sql_bigint_unsigned &p1, const sql_char &p2, const sql_int_unsigned &p3, const sql_int_unsigned &p4, const sql_int_unsigned &p5, const sql_int_unsigned &p6, const sql_int_unsigned &p7, const sql_int_unsigned &p8) {
table_override_ = 0;
    id = p1;\
    name = p2;\
    status_type = p3;\
    hit_rate = p4;\
    duration = p5;\
    hit_times = p6;\
    power_type = p7;\
    power_value = p8;\

}
bool operator == (const CStatusTypeData &other) const 
 {return sql_compare_CStatusTypeData<mysqlpp::sql_dummy>(*this,other) == 0;} 
 bool operator != (const CStatusTypeData &other) const 
 {return sql_compare_CStatusTypeData<mysqlpp::sql_dummy>(*this,other) != 0;} 
 bool operator > (const CStatusTypeData &other) const 
 {return sql_compare_CStatusTypeData<mysqlpp::sql_dummy>(*this,other) >  0;} 
 bool operator < (const CStatusTypeData &other) const 
 {return sql_compare_CStatusTypeData<mysqlpp::sql_dummy>(*this,other) <  0;} 
 bool operator >= (const CStatusTypeData &other) const 
 {return sql_compare_CStatusTypeData<mysqlpp::sql_dummy>(*this,other) >= 0;} 
 bool operator <= (const CStatusTypeData &other) const 
 {return sql_compare_CStatusTypeData<mysqlpp::sql_dummy>(*this,other) <= 0;} 
 int cmp (const CStatusTypeData &other) const 
 {return sql_compare_CStatusTypeData<mysqlpp::sql_dummy>(*this,other);} 
 int compare (const CStatusTypeData &other) const 
 {return sql_compare_CStatusTypeData<mysqlpp::sql_dummy>(*this,other);}

        void set(const sql_bigint_unsigned p1) { \
        table_override_ = 0;

        id = p1;


        } \
        CStatusTypeData(const sql_bigint_unsigned p1) : id(p1), table_override_(0) {}
        static const char* names[];
        static void table(const char* t) { table_ = t; }
        const char* table() const
                { return table_override_ ? table_override_ : CStatusTypeData::table_; }
        void instance_table(const char* t) { table_override_ = t; }
    
        CStatusTypeData_value_list<mysqlpp::quote_type0> value_list() const {
            return value_list(",", mysqlpp::quote);}
        CStatusTypeData_value_list<mysqlpp::quote_type0> value_list(const char* d) const {
            return value_list(d, mysqlpp::quote);}
        template <class Manip>
        CStatusTypeData_value_list<Manip> value_list(const char* d, Manip m) const;
    
        CStatusTypeData_field_list<mysqlpp::do_nothing_type0> field_list() const {
            return field_list(",", mysqlpp::do_nothing);}
        CStatusTypeData_field_list<mysqlpp::do_nothing_type0> field_list(const char* d) const {
            return field_list(d, mysqlpp::do_nothing);}
        template <class Manip>
        CStatusTypeData_field_list<Manip> field_list(const char* d, Manip m) const;
    
        CStatusTypeData_equal_list<mysqlpp::quote_type0> equal_list(const char* d = ",",
                const char* c = " = ") const
                { return equal_list(d, c, mysqlpp::quote); }
        template <class Manip>
        CStatusTypeData_equal_list<Manip> equal_list(const char* d, const char* c, Manip m) const;
    
        /* cus_data */
    
        CStatusTypeData_cus_value_list<mysqlpp::quote_type0> value_list(bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false) const
                { return value_list(",", mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8); }
        CStatusTypeData_cus_value_list<mysqlpp::quote_type0> value_list(CStatusTypeData_enum i1, CStatusTypeData_enum i2 = STATUSTYPEDATA_NULL, CStatusTypeData_enum i3 = STATUSTYPEDATA_NULL, CStatusTypeData_enum i4 = STATUSTYPEDATA_NULL, CStatusTypeData_enum i5 = STATUSTYPEDATA_NULL, CStatusTypeData_enum i6 = STATUSTYPEDATA_NULL, CStatusTypeData_enum i7 = STATUSTYPEDATA_NULL, CStatusTypeData_enum i8 = STATUSTYPEDATA_NULL) const
                { return value_list(",", mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8); }
        CStatusTypeData_cus_value_list<mysqlpp::quote_type0> value_list(std::vector<bool> *i) const
                { return value_list(",", mysqlpp::quote, i); }
        CStatusTypeData_cus_value_list<mysqlpp::quote_type0> value_list(mysqlpp::sql_cmp_type sc) const
                { return value_list(",", mysqlpp::quote, sc); }
    
        CStatusTypeData_cus_value_list<mysqlpp::quote_type0> value_list(const char* d, bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false) const
                { return value_list(d, mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8); }
        CStatusTypeData_cus_value_list<mysqlpp::quote_type0> value_list(const char* d, CStatusTypeData_enum i1, CStatusTypeData_enum i2 = STATUSTYPEDATA_NULL, CStatusTypeData_enum i3 = STATUSTYPEDATA_NULL, CStatusTypeData_enum i4 = STATUSTYPEDATA_NULL, CStatusTypeData_enum i5 = STATUSTYPEDATA_NULL, CStatusTypeData_enum i6 = STATUSTYPEDATA_NULL, CStatusTypeData_enum i7 = STATUSTYPEDATA_NULL, CStatusTypeData_enum i8 = STATUSTYPEDATA_NULL) const
                { return value_list(d, mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8); }
        CStatusTypeData_cus_value_list<mysqlpp::quote_type0> value_list(const char* d,
                std::vector<bool> *i) const
                { return value_list(d, mysqlpp::quote, i); }
        CStatusTypeData_cus_value_list<mysqlpp::quote_type0> value_list(const char* d,
                mysqlpp::sql_cmp_type sc) const
                { return value_list(d, mysqlpp::quote, sc); }
    
        template <class Manip>
        CStatusTypeData_cus_value_list<Manip> value_list(const char* d, Manip m,
                bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false) const;
        template <class Manip>
        CStatusTypeData_cus_value_list<Manip> value_list(const char* d, Manip m,
                CStatusTypeData_enum i1, CStatusTypeData_enum i2 = STATUSTYPEDATA_NULL, CStatusTypeData_enum i3 = STATUSTYPEDATA_NULL, CStatusTypeData_enum i4 = STATUSTYPEDATA_NULL, CStatusTypeData_enum i5 = STATUSTYPEDATA_NULL, CStatusTypeData_enum i6 = STATUSTYPEDATA_NULL, CStatusTypeData_enum i7 = STATUSTYPEDATA_NULL, CStatusTypeData_enum i8 = STATUSTYPEDATA_NULL) const;
        template <class Manip>
        CStatusTypeData_cus_value_list<Manip> value_list(const char* d, Manip m,
                std::vector<bool>* i) const;
        template <class Manip>
        CStatusTypeData_cus_value_list<Manip> value_list(const char* d, Manip m, 
                mysqlpp::sql_cmp_type sc) const;
        /* cus field */
    
        CStatusTypeData_cus_field_list<mysqlpp::do_nothing_type0> field_list(bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false) const 
                { return field_list(",", mysqlpp::do_nothing, i1, i2, i3, i4, i5, i6, i7, i8); }
        CStatusTypeData_cus_field_list<mysqlpp::do_nothing_type0> field_list(CStatusTypeData_enum i1, CStatusTypeData_enum i2 = STATUSTYPEDATA_NULL, CStatusTypeData_enum i3 = STATUSTYPEDATA_NULL, CStatusTypeData_enum i4 = STATUSTYPEDATA_NULL, CStatusTypeData_enum i5 = STATUSTYPEDATA_NULL, CStatusTypeData_enum i6 = STATUSTYPEDATA_NULL, CStatusTypeData_enum i7 = STATUSTYPEDATA_NULL, CStatusTypeData_enum i8 = STATUSTYPEDATA_NULL) const
                { return field_list(",", mysqlpp::do_nothing, i1, i2, i3, i4, i5, i6, i7, i8); }
        CStatusTypeData_cus_field_list<mysqlpp::do_nothing_type0> field_list(std::vector<bool> *i) const
                { return field_list(",", mysqlpp::do_nothing, i); }
        CStatusTypeData_cus_field_list<mysqlpp::do_nothing_type0> field_list(mysqlpp::sql_cmp_type sc) const
                { return field_list(",", mysqlpp::do_nothing, sc); }
    
        CStatusTypeData_cus_field_list<mysqlpp::do_nothing_type0> field_list(const char* d,
                bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false) const
                { return field_list(d, mysqlpp::do_nothing, i1, i2, i3, i4, i5, i6, i7, i8); }
        CStatusTypeData_cus_field_list<mysqlpp::do_nothing_type0> field_list(const char* d,
                CStatusTypeData_enum i1, CStatusTypeData_enum i2 = STATUSTYPEDATA_NULL, CStatusTypeData_enum i3 = STATUSTYPEDATA_NULL, CStatusTypeData_enum i4 = STATUSTYPEDATA_NULL, CStatusTypeData_enum i5 = STATUSTYPEDATA_NULL, CStatusTypeData_enum i6 = STATUSTYPEDATA_NULL, CStatusTypeData_enum i7 = STATUSTYPEDATA_NULL, CStatusTypeData_enum i8 = STATUSTYPEDATA_NULL) const
                { return field_list(d, mysqlpp::do_nothing, i1, i2, i3, i4, i5, i6, i7, i8); }
        CStatusTypeData_cus_field_list<mysqlpp::do_nothing_type0> field_list(const char* d,
                std::vector<bool>* i) const
                { return field_list(d, mysqlpp::do_nothing, i); }
        CStatusTypeData_cus_field_list<mysqlpp::do_nothing_type0> field_list(const char* d,
                mysqlpp::sql_cmp_type sc) const
                { return field_list(d, mysqlpp::do_nothing, sc); }
    
        template <class Manip>
        CStatusTypeData_cus_field_list<Manip> field_list(const char* d, Manip m,
                bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false) const;
        template <class Manip>
        CStatusTypeData_cus_field_list<Manip> field_list(const char* d, Manip m,
                CStatusTypeData_enum i1, CStatusTypeData_enum i2 = STATUSTYPEDATA_NULL, CStatusTypeData_enum i3 = STATUSTYPEDATA_NULL, CStatusTypeData_enum i4 = STATUSTYPEDATA_NULL, CStatusTypeData_enum i5 = STATUSTYPEDATA_NULL, CStatusTypeData_enum i6 = STATUSTYPEDATA_NULL, CStatusTypeData_enum i7 = STATUSTYPEDATA_NULL, CStatusTypeData_enum i8 = STATUSTYPEDATA_NULL) const;
        template <class Manip>
        CStatusTypeData_cus_field_list<Manip> field_list(const char* d, Manip m,
                std::vector<bool> *i) const;
        template <class Manip>
        CStatusTypeData_cus_field_list<Manip> field_list(const char* d, Manip m,
                mysqlpp::sql_cmp_type sc) const;
    
        /* cus equal */
    
        CStatusTypeData_cus_equal_list<mysqlpp::quote_type0> equal_list(bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false) const
                { return equal_list(",", " = ", mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8); }
        CStatusTypeData_cus_equal_list<mysqlpp::quote_type0> equal_list(CStatusTypeData_enum i1, CStatusTypeData_enum i2 = STATUSTYPEDATA_NULL, CStatusTypeData_enum i3 = STATUSTYPEDATA_NULL, CStatusTypeData_enum i4 = STATUSTYPEDATA_NULL, CStatusTypeData_enum i5 = STATUSTYPEDATA_NULL, CStatusTypeData_enum i6 = STATUSTYPEDATA_NULL, CStatusTypeData_enum i7 = STATUSTYPEDATA_NULL, CStatusTypeData_enum i8 = STATUSTYPEDATA_NULL) const
                { return equal_list(",", " = ", mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8); }
        CStatusTypeData_cus_equal_list<mysqlpp::quote_type0> equal_list(std::vector<bool>* i) const
                { return equal_list(",", " = ", mysqlpp::quote, i); }
        CStatusTypeData_cus_equal_list<mysqlpp::quote_type0> equal_list(mysqlpp::sql_cmp_type sc) const
                { return equal_list(",", " = ", mysqlpp::quote, sc); }
    
        CStatusTypeData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d, bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false) const
                { return equal_list(d, " = ", mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8); }
        CStatusTypeData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d, CStatusTypeData_enum i1, CStatusTypeData_enum i2 = STATUSTYPEDATA_NULL, CStatusTypeData_enum i3 = STATUSTYPEDATA_NULL, CStatusTypeData_enum i4 = STATUSTYPEDATA_NULL, CStatusTypeData_enum i5 = STATUSTYPEDATA_NULL, CStatusTypeData_enum i6 = STATUSTYPEDATA_NULL, CStatusTypeData_enum i7 = STATUSTYPEDATA_NULL, CStatusTypeData_enum i8 = STATUSTYPEDATA_NULL) const
                { return equal_list(d, " = ", mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8); }
        CStatusTypeData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d,
                std::vector<bool> *i) const
                { return equal_list(d, " = ", mysqlpp::quote, i); }
        CStatusTypeData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d,
                mysqlpp::sql_cmp_type sc) const
                { return equal_list(d, " = ", mysqlpp::quote, sc); }
    
        CStatusTypeData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d, const char* c,
                bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false) const
                { return equal_list(d, c, mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8); }
        CStatusTypeData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d, const char* c,
                CStatusTypeData_enum i1, CStatusTypeData_enum i2 = STATUSTYPEDATA_NULL, CStatusTypeData_enum i3 = STATUSTYPEDATA_NULL, CStatusTypeData_enum i4 = STATUSTYPEDATA_NULL, CStatusTypeData_enum i5 = STATUSTYPEDATA_NULL, CStatusTypeData_enum i6 = STATUSTYPEDATA_NULL, CStatusTypeData_enum i7 = STATUSTYPEDATA_NULL, CStatusTypeData_enum i8 = STATUSTYPEDATA_NULL) const
                { return equal_list(d, c, mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8); }
        CStatusTypeData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d, const char* c,
                std::vector<bool> *i) const
                { return equal_list(d, c, mysqlpp::quote, i); }
        CStatusTypeData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d, const char* c,
                mysqlpp::sql_cmp_type sc) const
                { return equal_list(d, c, mysqlpp::quote, sc); }
    
        template <class Manip>
        CStatusTypeData_cus_equal_list<Manip> equal_list(const char* d, const char* c, Manip m, 
                            bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false) const;
        template <class Manip>
        CStatusTypeData_cus_equal_list<Manip> equal_list(const char* d, const char* c, Manip m, 
                            CStatusTypeData_enum i1, CStatusTypeData_enum i2 = STATUSTYPEDATA_NULL, CStatusTypeData_enum i3 = STATUSTYPEDATA_NULL, CStatusTypeData_enum i4 = STATUSTYPEDATA_NULL, CStatusTypeData_enum i5 = STATUSTYPEDATA_NULL, CStatusTypeData_enum i6 = STATUSTYPEDATA_NULL, CStatusTypeData_enum i7 = STATUSTYPEDATA_NULL, CStatusTypeData_enum i8 = STATUSTYPEDATA_NULL) const;
        template <class Manip>
        CStatusTypeData_cus_equal_list<Manip> equal_list(const char* d, const char* c, Manip m, 
                            std::vector<bool> *i) const;
        template <class Manip>
        CStatusTypeData_cus_equal_list<Manip> equal_list(const char* d, const char* c, Manip m, 
                            mysqlpp::sql_cmp_type sc) const;
    
        private:
        static const char* table_;
        const char* table_override_;
        };
            
        template <class Manip>
        CStatusTypeData_cus_value_list<Manip>::CStatusTypeData_cus_value_list
                (const CStatusTypeData* o, const char* d, Manip m, bool i1, bool i2, bool i3, bool i4, bool i5, bool i6, bool i7, bool i8)
        {
            delim = d;
            manip = m;
            del_vector = true;
            obj = o;
            include = new std::vector<bool>(8, false);
        if (i1) (*include)[0]=true;
    if (i2) (*include)[1]=true;
    if (i3) (*include)[2]=true;
    if (i4) (*include)[3]=true;
    if (i5) (*include)[4]=true;
    if (i6) (*include)[5]=true;
    if (i7) (*include)[6]=true;
    if (i8) (*include)[7]=true;

        }
    
        template <class Manip>
        CStatusTypeData_cus_value_list<Manip>::CStatusTypeData_cus_value_list
                (const CStatusTypeData* o, const char* d, Manip m, CStatusTypeData_enum i1, CStatusTypeData_enum i2, CStatusTypeData_enum i3, CStatusTypeData_enum i4, CStatusTypeData_enum i5, CStatusTypeData_enum i6, CStatusTypeData_enum i7, CStatusTypeData_enum i8)
        {
            delim = d;
            manip = m;
            del_vector = true;
            obj = o;
            include = new std::vector<bool>(8, false);
        (*include)[i1]=true;
    if (i2 == STATUSTYPEDATA_NULL) return;
    (*include)[i2]=true;
    if (i3 == STATUSTYPEDATA_NULL) return;
    (*include)[i3]=true;
    if (i4 == STATUSTYPEDATA_NULL) return;
    (*include)[i4]=true;
    if (i5 == STATUSTYPEDATA_NULL) return;
    (*include)[i5]=true;
    if (i6 == STATUSTYPEDATA_NULL) return;
    (*include)[i6]=true;
    if (i7 == STATUSTYPEDATA_NULL) return;
    (*include)[i7]=true;
    if (i8 == STATUSTYPEDATA_NULL) return;
    (*include)[i8]=true;

        }
    
        template <class Manip>
        CStatusTypeData_cus_field_list<Manip>::CStatusTypeData_cus_field_list
                (const CStatusTypeData* o, const char* d, Manip m, bool i1, bool i2, bool i3, bool i4, bool i5, bool i6, bool i7, bool i8)
        {
            delim = d;
            manip = m;
            del_vector = true;
            obj = o;
            include = new std::vector<bool>(8, false);
        if (i1) (*include)[0]=true;
    if (i2) (*include)[1]=true;
    if (i3) (*include)[2]=true;
    if (i4) (*include)[3]=true;
    if (i5) (*include)[4]=true;
    if (i6) (*include)[5]=true;
    if (i7) (*include)[6]=true;
    if (i8) (*include)[7]=true;

        }
    
        template <class Manip>
        CStatusTypeData_cus_field_list<Manip>::CStatusTypeData_cus_field_list
                (const CStatusTypeData* o, const char* d, Manip m, CStatusTypeData_enum i1, CStatusTypeData_enum i2, CStatusTypeData_enum i3, CStatusTypeData_enum i4, CStatusTypeData_enum i5, CStatusTypeData_enum i6, CStatusTypeData_enum i7, CStatusTypeData_enum i8)
        {
            delim = d;
            manip = m;
            del_vector = true;
            obj = o;
            include = new std::vector<bool>(8, false);
        (*include)[i1]=true;
    if (i2 == STATUSTYPEDATA_NULL) return;
    (*include)[i2]=true;
    if (i3 == STATUSTYPEDATA_NULL) return;
    (*include)[i3]=true;
    if (i4 == STATUSTYPEDATA_NULL) return;
    (*include)[i4]=true;
    if (i5 == STATUSTYPEDATA_NULL) return;
    (*include)[i5]=true;
    if (i6 == STATUSTYPEDATA_NULL) return;
    (*include)[i6]=true;
    if (i7 == STATUSTYPEDATA_NULL) return;
    (*include)[i7]=true;
    if (i8 == STATUSTYPEDATA_NULL) return;
    (*include)[i8]=true;

        }
    
        template <class Manip>
        CStatusTypeData_cus_equal_list<Manip>::CStatusTypeData_cus_equal_list
                (const CStatusTypeData* o, const char* d, const char* c, Manip m, bool i1, bool i2, bool i3, bool i4, bool i5, bool i6, bool i7, bool i8)
        {
            delim = d;
            comp = c;
            manip = m;
            del_vector = true;
            obj = o;
            include = new std::vector<bool>(8, false);
        if (i1) (*include)[0]=true;
    if (i2) (*include)[1]=true;
    if (i3) (*include)[2]=true;
    if (i4) (*include)[3]=true;
    if (i5) (*include)[4]=true;
    if (i6) (*include)[5]=true;
    if (i7) (*include)[6]=true;
    if (i8) (*include)[7]=true;

        }
    
        template <class Manip>
        CStatusTypeData_cus_equal_list<Manip>::CStatusTypeData_cus_equal_list
                (const CStatusTypeData* o, const char* d, const char* c, Manip m, CStatusTypeData_enum i1, CStatusTypeData_enum i2, CStatusTypeData_enum i3, CStatusTypeData_enum i4, CStatusTypeData_enum i5, CStatusTypeData_enum i6, CStatusTypeData_enum i7, CStatusTypeData_enum i8)
        {
            delim = d;
            comp = c;
            manip = m;
            del_vector = true;
            obj = o;
            include = new std::vector<bool>(8, false);
        (*include)[i1]=true;
    if (i2 == STATUSTYPEDATA_NULL) return;
    (*include)[i2]=true;
    if (i3 == STATUSTYPEDATA_NULL) return;
    (*include)[i3]=true;
    if (i4 == STATUSTYPEDATA_NULL) return;
    (*include)[i4]=true;
    if (i5 == STATUSTYPEDATA_NULL) return;
    (*include)[i5]=true;
    if (i6 == STATUSTYPEDATA_NULL) return;
    (*include)[i6]=true;
    if (i7 == STATUSTYPEDATA_NULL) return;
    (*include)[i7]=true;
    if (i8 == STATUSTYPEDATA_NULL) return;
    (*include)[i8]=true;

        }
    
        template <class Manip>
        std::ostream& operator <<(std::ostream& s, const CStatusTypeData_value_list<Manip>& obj)
        {
        s << obj.manip << obj.obj->id << obj.delim;
    s << obj.manip << obj.obj->name << obj.delim;
    s << obj.manip << obj.obj->status_type << obj.delim;
    s << obj.manip << obj.obj->hit_rate << obj.delim;
    s << obj.manip << obj.obj->duration << obj.delim;
    s << obj.manip << obj.obj->hit_times << obj.delim;
    s << obj.manip << obj.obj->power_type << obj.delim;
    s << obj.manip << obj.obj->power_value;
            return s;
        }
    
        template <class Manip>
        std::ostream& operator <<(std::ostream& s, const CStatusTypeData_field_list<Manip>& obj)
        {
        s << obj.manip << '`' << obj.obj->names[0] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[1] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[2] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[3] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[4] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[5] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[6] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[7] << '`';
            return s;
        }
    
        template <class Manip>
        std::ostream& operator <<(std::ostream& s, const CStatusTypeData_equal_list<Manip>& obj)
        {
        s << '`' << obj.obj->names[0] << '`' << obj.comp << obj.manip << obj.obj->id << obj.delim;
    s << '`' << obj.obj->names[1] << '`' << obj.comp << obj.manip << obj.obj->name << obj.delim;
    s << '`' << obj.obj->names[2] << '`' << obj.comp << obj.manip << obj.obj->status_type << obj.delim;
    s << '`' << obj.obj->names[3] << '`' << obj.comp << obj.manip << obj.obj->hit_rate << obj.delim;
    s << '`' << obj.obj->names[4] << '`' << obj.comp << obj.manip << obj.obj->duration << obj.delim;
    s << '`' << obj.obj->names[5] << '`' << obj.comp << obj.manip << obj.obj->hit_times << obj.delim;
    s << '`' << obj.obj->names[6] << '`' << obj.comp << obj.manip << obj.obj->power_type << obj.delim;
    s << '`' << obj.obj->names[7] << '`' << obj.comp << obj.manip << obj.obj->power_value;
            return s;
        }
    
        template <class Manip>
        std::ostream& operator <<(std::ostream& s, const CStatusTypeData_cus_value_list<Manip>& obj)
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
      s << obj.manip << obj.obj->status_type;
      before = true; 
     } 
    if ((*obj.include)[3]) { 
      if (before) s << obj.delim;
      s << obj.manip << obj.obj->hit_rate;
      before = true; 
     } 
    if ((*obj.include)[4]) { 
      if (before) s << obj.delim;
      s << obj.manip << obj.obj->duration;
      before = true; 
     } 
    if ((*obj.include)[5]) { 
      if (before) s << obj.delim;
      s << obj.manip << obj.obj->hit_times;
      before = true; 
     } 
    if ((*obj.include)[6]) { 
      if (before) s << obj.delim;
      s << obj.manip << obj.obj->power_type;
      before = true; 
     } 
    if ((*obj.include)[7]) { 
      if (before) s << obj.delim;
      s << obj.manip << obj.obj->power_value;
     } 

            return s;
        }
    
        template <class Manip>
        std::ostream& operator <<(std::ostream& s, const CStatusTypeData_cus_field_list<Manip>& obj)
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
     } 

            return s;
        }
    
        template <class Manip>
        std::ostream& operator <<(std::ostream& s, const CStatusTypeData_cus_equal_list<Manip>& obj)
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
      s << '`' << obj.obj->names[2] << '`' << obj.comp         << obj.manip << obj.obj->status_type;
      before = true; 
     } 
    if ((*obj.include)[3]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[3] << '`' << obj.comp         << obj.manip << obj.obj->hit_rate;
      before = true; 
     } 
    if ((*obj.include)[4]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[4] << '`' << obj.comp         << obj.manip << obj.obj->duration;
      before = true; 
     } 
    if ((*obj.include)[5]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[5] << '`' << obj.comp         << obj.manip << obj.obj->hit_times;
      before = true; 
     } 
    if ((*obj.include)[6]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[6] << '`' << obj.comp         << obj.manip << obj.obj->power_type;
      before = true; 
     } 
    if ((*obj.include)[7]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[7] << '`' << obj.comp         << obj.manip << obj.obj->power_value;
     } 

            return s;
        }
    
        template <class Manip>
        inline CStatusTypeData_value_list<Manip> CStatusTypeData::value_list(const char* d, Manip m) const
                { return CStatusTypeData_value_list<Manip> (this, d, m); } 
    
        template <class Manip>
        inline CStatusTypeData_field_list<Manip> CStatusTypeData::field_list(const char* d, Manip m) const
                { return CStatusTypeData_field_list<Manip> (this, d, m); } 
    
        template <class Manip>
        inline CStatusTypeData_equal_list<Manip> CStatusTypeData::equal_list(const char* d, const char* c, Manip m) const
                { return CStatusTypeData_equal_list<Manip> (this, d, c, m); } 
    
        template <class Manip>
        inline CStatusTypeData_cus_value_list<Manip> CStatusTypeData::value_list(const char* d, Manip m,
                bool i1, bool i2, bool i3, bool i4, bool i5, bool i6, bool i7, bool i8) const
                { return CStatusTypeData_cus_value_list<Manip> (this, d, m, i1, i2, i3, i4, i5, i6, i7, i8); }
    
        template <class Manip>
        inline CStatusTypeData_cus_field_list<Manip> CStatusTypeData::field_list(const char* d, Manip m,
                bool i1, bool i2, bool i3, bool i4, bool i5, bool i6, bool i7, bool i8) const
                { return CStatusTypeData_cus_field_list<Manip> (this, d, m, i1, i2, i3, i4, i5, i6, i7, i8); }
    
        template <class Manip>
        inline CStatusTypeData_cus_equal_list<Manip> CStatusTypeData::equal_list(const char* d, const char* c, Manip m,
                bool i1, bool i2, bool i3, bool i4, bool i5, bool i6, bool i7, bool i8) const
                { return CStatusTypeData_cus_equal_list<Manip> (this, d, c, m, i1, i2, i3, i4, i5, i6, i7, i8); } 
    
        template <class Manip>
        inline CStatusTypeData_cus_value_list<Manip> CStatusTypeData::value_list(const char* d, Manip m,
                CStatusTypeData_enum i1, CStatusTypeData_enum i2, CStatusTypeData_enum i3, CStatusTypeData_enum i4, CStatusTypeData_enum i5, CStatusTypeData_enum i6, CStatusTypeData_enum i7, CStatusTypeData_enum i8) const
                { return CStatusTypeData_cus_value_list<Manip> (this, d, m, i1, i2, i3, i4, i5, i6, i7, i8); } 
    
        template <class Manip>
        inline CStatusTypeData_cus_field_list<Manip> CStatusTypeData::field_list(const char* d, Manip m,
                CStatusTypeData_enum i1, CStatusTypeData_enum i2, CStatusTypeData_enum i3, CStatusTypeData_enum i4, CStatusTypeData_enum i5, CStatusTypeData_enum i6, CStatusTypeData_enum i7, CStatusTypeData_enum i8) const
                { return CStatusTypeData_cus_field_list<Manip> (this, d, m, i1, i2, i3, i4, i5, i6, i7, i8); } 
    
        template <class Manip>
        inline CStatusTypeData_cus_equal_list<Manip> CStatusTypeData::equal_list(const char* d, const char* c, Manip m, 
                CStatusTypeData_enum i1, CStatusTypeData_enum i2, CStatusTypeData_enum i3, CStatusTypeData_enum i4, CStatusTypeData_enum i5, CStatusTypeData_enum i6, CStatusTypeData_enum i7, CStatusTypeData_enum i8) const
                { return CStatusTypeData_cus_equal_list<Manip> (this, d, c, m, i1, i2, i3, i4, i5, i6, i7, i8); } 
    
        template <class Manip>
        inline CStatusTypeData_cus_value_list<Manip> CStatusTypeData::value_list(const char* d, Manip m,
                std::vector<bool> *i) const
                { return CStatusTypeData_cus_value_list<Manip> (this, d, m, i); }
    
        template <class Manip>
        inline CStatusTypeData_cus_field_list<Manip> CStatusTypeData::field_list(const char* d, Manip m,
                std::vector<bool> *i) const
                { return CStatusTypeData_cus_field_list<Manip> (this, d, m, i); }
    
        template <class Manip>
        inline CStatusTypeData_cus_equal_list<Manip> CStatusTypeData::equal_list(const char* d, const char* c, Manip m,
                std::vector<bool> *i) const
                { return CStatusTypeData_cus_equal_list<Manip> (this, d, c, m, i); }
    
        template <class Manip>
        inline CStatusTypeData_cus_value_list<Manip> 
        CStatusTypeData::value_list(const char* d, Manip m, mysqlpp::sql_cmp_type /*sc*/) const
                { return value_list(d, m, true, true, true, true, true, true, true, true); }
    
        template <class Manip>
        inline CStatusTypeData_cus_field_list<Manip> 
        CStatusTypeData::field_list(const char* d, Manip m, mysqlpp::sql_cmp_type /*sc*/) const
                { return field_list(d, m, true, true, true, true, true, true, true, true); }
    
        template <class Manip>
        inline CStatusTypeData_cus_equal_list<Manip> 
        CStatusTypeData::equal_list(const char* d, const char* c, Manip m, mysqlpp::sql_cmp_type /*sc*/) const
                { return equal_list(d, c, m, true, true, true, true, true, true, true, true); }
    
        template <mysqlpp::sql_dummy_type dummy>
        void populate_CStatusTypeData(CStatusTypeData *s, const mysqlpp::Row &row)
        {
            mysqlpp::NoExceptions ignore_schema_mismatches(row);
        s->id = row["id"].conv(sql_bigint_unsigned());
    s->name = row["name"].conv(sql_char());
    s->status_type = row["status_type"].conv(sql_int_unsigned());
    s->hit_rate = row["hit_rate"].conv(sql_int_unsigned());
    s->duration = row["duration"].conv(sql_int_unsigned());
    s->hit_times = row["hit_times"].conv(sql_int_unsigned());
    s->power_type = row["power_type"].conv(sql_int_unsigned());
    s->power_value = row["power_value"].conv(sql_int_unsigned());
        }
    
        inline CStatusTypeData::CStatusTypeData(const mysqlpp::Row& row) :
        table_override_(0)
                { populate_CStatusTypeData<mysqlpp::sql_dummy>(this, row); }
        inline void CStatusTypeData::set(const mysqlpp::Row& row)
        {
            table_override_ = 0;
            populate_CStatusTypeData<mysqlpp::sql_dummy>(this, row);
        }
    
        template <mysqlpp::sql_dummy_type dummy> 
 int sql_compare_CStatusTypeData(const CStatusTypeData &x, const CStatusTypeData &y) { 
     int cmp; \
    cmp = mysqlpp::sql_cmp(x.id, y.id ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.name, y.name ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.status_type, y.status_type ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.hit_rate, y.hit_rate ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.duration, y.duration ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.hit_times, y.hit_times ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.power_type, y.power_type ); \
    if (cmp) return cmp; \
    return mysqlpp::sql_cmp(x.power_value, y.power_value); 
 } 
 template <mysqlpp::sql_dummy_type dummy> 
 int compare (const CStatusTypeData &x, const CStatusTypeData &y) { 
     int cmp; \
    cmp = mysqlpp::sql_cmp(x.id, y.id ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.name, y.name ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.status_type, y.status_type ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.hit_rate, y.hit_rate ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.duration, y.duration ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.hit_times, y.hit_times ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.power_type, y.power_type ); \
    if (cmp) return cmp; \
    return mysqlpp::sql_cmp(x.power_value, y.power_value); 
 }

#endif	//end of define _STATUS_TYPE_DATA_H_