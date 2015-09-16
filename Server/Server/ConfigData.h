////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author: 	Fu Yan
// Created: 	2015-08-17
// Describe: 	Specailized SQL structure of table gs_config, 
//				generate by genSsqls.py, !!!DO NOT EDIT!!!
////////////////////////////////////////////////////////////////////////
#ifndef _CONFIG_DATA_H_
#define _CONFIG_DATA_H_

#include <mysql++.h>
#include <ssqls.h>

using namespace mysqlpp;

struct CConfigData; 
    
        enum CConfigData_enum { 
        CONFIGDATA_ID,
    CONFIGDATA_TYPE,
    CONFIGDATA_DATA1,
    CONFIGDATA_DATA2,
    CONFIGDATA_DATA3,
    CONFIGDATA_DATA4,
    CONFIGDATA_DATA5,
    CONFIGDATA_STR,
    CONFIGDATA_DESC,
        CONFIGDATA_NULL 
        }; 
    
        template <class Manip>
        class CConfigData_value_list { 
        public: 
        const CConfigData* obj;
        const char* delim;
        Manip manip;
        public: 
        CConfigData_value_list (const CConfigData* o, const char* d, Manip m) :
        obj(o), delim(d), manip(m) { } 
        };
    
        template <class Manip>
        class CConfigData_field_list {
        public: 
        const CConfigData* obj; 
        const char* delim;
        Manip manip;
        public: 
        CConfigData_field_list (const CConfigData* o, const char* d, Manip m) :
        obj(o), delim(d), manip(m) { } 
        };
    
        template <class Manip>
        class CConfigData_equal_list { 
        public: 
        const CConfigData* obj;
        const char* delim;
        const char* comp;
        Manip manip;
        public: 
        CConfigData_equal_list (const CConfigData* o, const char* d, const char* c, Manip m) :
        obj(o), delim(d), comp(c), manip(m) { }
        };
    
        template <class Manip>
        class CConfigData_cus_value_list {
        public:
        const CConfigData* obj;
        std::vector<bool> *include;
        bool del_vector;
        const char* delim;
        Manip manip;
        public: 
        ~CConfigData_cus_value_list () {if (del_vector) delete include;} 
        CConfigData_cus_value_list (const CConfigData* o, const char* d, Manip m, bool i1, bool i2, bool i3, bool i4, bool i5, bool i6, bool i7, bool i8, bool i9);
        CConfigData_cus_value_list (const CConfigData* o, const char* d, Manip m, CConfigData_enum i1, CConfigData_enum i2, CConfigData_enum i3, CConfigData_enum i4, CConfigData_enum i5, CConfigData_enum i6, CConfigData_enum i7, CConfigData_enum i8, CConfigData_enum i9); 
        CConfigData_cus_value_list (const CConfigData* o, const char* d, Manip m ,std::vector<bool>* i) :
        obj(o), include(i), del_vector(false), delim(d), manip(m) { }
        };
    
        template <class Manip>
        class CConfigData_cus_field_list { 
        public:
        const CConfigData* obj; 
        std::vector<bool> *include; 
        bool del_vector; 
        const char* delim;
        Manip manip;
        public: 
        ~CConfigData_cus_field_list () {if (del_vector) delete include;} 
        CConfigData_cus_field_list (const CConfigData* o, const char* d, Manip m, bool i1, bool i2, bool i3, bool i4, bool i5, bool i6, bool i7, bool i8, bool i9); 
        CConfigData_cus_field_list (const CConfigData* o, const char* d, Manip m, CConfigData_enum i1, CConfigData_enum i2, CConfigData_enum i3, CConfigData_enum i4, CConfigData_enum i5, CConfigData_enum i6, CConfigData_enum i7, CConfigData_enum i8, CConfigData_enum i9); 
        CConfigData_cus_field_list (const CConfigData* o, const char* d, Manip m, std::vector<bool> *i) :
        obj(o), include(i), del_vector(false), delim(d), manip(m) { }
        };
    
        template <class Manip>
        class CConfigData_cus_equal_list {
        public:
        const CConfigData* obj;
        std::vector<bool> *include;
        bool del_vector;
        const char* delim;
        const char* comp;
        Manip manip;
        public:
        ~CConfigData_cus_equal_list () {if (del_vector) delete include;}
        CConfigData_cus_equal_list (const CConfigData* o, const char* d, const char* c, Manip m, bool i1, bool i2, bool i3, bool i4, bool i5, bool i6, bool i7, bool i8, bool i9); 
        CConfigData_cus_equal_list (const CConfigData* o, const char* d, const char* c, Manip m, CConfigData_enum i1, CConfigData_enum i2, CConfigData_enum i3, CConfigData_enum i4, CConfigData_enum i5, CConfigData_enum i6, CConfigData_enum i7, CConfigData_enum i8, CConfigData_enum i9); 
        CConfigData_cus_equal_list (const CConfigData* o, const char* d, const char* c, Manip m, std::vector<bool> *i) :
        obj(o), include(i), del_vector(false), delim(d), comp(c), manip(m) { }
        };
    
        template <mysqlpp::sql_dummy_type dummy> int sql_compare_CConfigData(const CConfigData&, const CConfigData&);
    
        struct CConfigData {
        sql_int_unsigned id;
    sql_int_unsigned type;
    sql_int_unsigned data1;
    sql_int_unsigned data2;
    sql_int_unsigned data3;
    sql_int_unsigned data4;
    sql_int_unsigned data5;
    sql_char str;
    sql_char desc; 
        CConfigData() : table_override_(0) { }
        CConfigData(const mysqlpp::Row& row);
        void set(const mysqlpp::Row &row);
        CConfigData(const sql_int_unsigned &p1, const sql_int_unsigned &p2, const sql_int_unsigned &p3, const sql_int_unsigned &p4, const sql_int_unsigned &p5, const sql_int_unsigned &p6, const sql_int_unsigned &p7, const sql_char &p8, const sql_char &p9) : id (p1), type (p2), data1 (p3), data2 (p4), data3 (p5), data4 (p6), data5 (p7), str (p8), desc (p9), table_override_(0) {}
void set(const sql_int_unsigned &p1, const sql_int_unsigned &p2, const sql_int_unsigned &p3, const sql_int_unsigned &p4, const sql_int_unsigned &p5, const sql_int_unsigned &p6, const sql_int_unsigned &p7, const sql_char &p8, const sql_char &p9) {
table_override_ = 0;
    id = p1;\
    type = p2;\
    data1 = p3;\
    data2 = p4;\
    data3 = p5;\
    data4 = p6;\
    data5 = p7;\
    str = p8;\
    desc = p9;\

}
bool operator == (const CConfigData &other) const 
 {return sql_compare_CConfigData<mysqlpp::sql_dummy>(*this,other) == 0;} 
 bool operator != (const CConfigData &other) const 
 {return sql_compare_CConfigData<mysqlpp::sql_dummy>(*this,other) != 0;} 
 bool operator > (const CConfigData &other) const 
 {return sql_compare_CConfigData<mysqlpp::sql_dummy>(*this,other) >  0;} 
 bool operator < (const CConfigData &other) const 
 {return sql_compare_CConfigData<mysqlpp::sql_dummy>(*this,other) <  0;} 
 bool operator >= (const CConfigData &other) const 
 {return sql_compare_CConfigData<mysqlpp::sql_dummy>(*this,other) >= 0;} 
 bool operator <= (const CConfigData &other) const 
 {return sql_compare_CConfigData<mysqlpp::sql_dummy>(*this,other) <= 0;} 
 int cmp (const CConfigData &other) const 
 {return sql_compare_CConfigData<mysqlpp::sql_dummy>(*this,other);} 
 int compare (const CConfigData &other) const 
 {return sql_compare_CConfigData<mysqlpp::sql_dummy>(*this,other);}

        void set(const sql_int_unsigned p1) { \
        table_override_ = 0;

        id = p1;


        } \
        CConfigData(const sql_int_unsigned p1) : id(p1), table_override_(0) {}
        static const char* names[];
        static void table(const char* t) { table_ = t; }
        const char* table() const
                { return table_override_ ? table_override_ : CConfigData::table_; }
        void instance_table(const char* t) { table_override_ = t; }
    
        CConfigData_value_list<mysqlpp::quote_type0> value_list() const {
            return value_list(",", mysqlpp::quote);}
        CConfigData_value_list<mysqlpp::quote_type0> value_list(const char* d) const {
            return value_list(d, mysqlpp::quote);}
        template <class Manip>
        CConfigData_value_list<Manip> value_list(const char* d, Manip m) const;
    
        CConfigData_field_list<mysqlpp::do_nothing_type0> field_list() const {
            return field_list(",", mysqlpp::do_nothing);}
        CConfigData_field_list<mysqlpp::do_nothing_type0> field_list(const char* d) const {
            return field_list(d, mysqlpp::do_nothing);}
        template <class Manip>
        CConfigData_field_list<Manip> field_list(const char* d, Manip m) const;
    
        CConfigData_equal_list<mysqlpp::quote_type0> equal_list(const char* d = ",",
                const char* c = " = ") const
                { return equal_list(d, c, mysqlpp::quote); }
        template <class Manip>
        CConfigData_equal_list<Manip> equal_list(const char* d, const char* c, Manip m) const;
    
        /* cus_data */
    
        CConfigData_cus_value_list<mysqlpp::quote_type0> value_list(bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false, bool i9 = false) const
                { return value_list(",", mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8, i9); }
        CConfigData_cus_value_list<mysqlpp::quote_type0> value_list(CConfigData_enum i1, CConfigData_enum i2 = CONFIGDATA_NULL, CConfigData_enum i3 = CONFIGDATA_NULL, CConfigData_enum i4 = CONFIGDATA_NULL, CConfigData_enum i5 = CONFIGDATA_NULL, CConfigData_enum i6 = CONFIGDATA_NULL, CConfigData_enum i7 = CONFIGDATA_NULL, CConfigData_enum i8 = CONFIGDATA_NULL, CConfigData_enum i9 = CONFIGDATA_NULL) const
                { return value_list(",", mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8, i9); }
        CConfigData_cus_value_list<mysqlpp::quote_type0> value_list(std::vector<bool> *i) const
                { return value_list(",", mysqlpp::quote, i); }
        CConfigData_cus_value_list<mysqlpp::quote_type0> value_list(mysqlpp::sql_cmp_type sc) const
                { return value_list(",", mysqlpp::quote, sc); }
    
        CConfigData_cus_value_list<mysqlpp::quote_type0> value_list(const char* d, bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false, bool i9 = false) const
                { return value_list(d, mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8, i9); }
        CConfigData_cus_value_list<mysqlpp::quote_type0> value_list(const char* d, CConfigData_enum i1, CConfigData_enum i2 = CONFIGDATA_NULL, CConfigData_enum i3 = CONFIGDATA_NULL, CConfigData_enum i4 = CONFIGDATA_NULL, CConfigData_enum i5 = CONFIGDATA_NULL, CConfigData_enum i6 = CONFIGDATA_NULL, CConfigData_enum i7 = CONFIGDATA_NULL, CConfigData_enum i8 = CONFIGDATA_NULL, CConfigData_enum i9 = CONFIGDATA_NULL) const
                { return value_list(d, mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8, i9); }
        CConfigData_cus_value_list<mysqlpp::quote_type0> value_list(const char* d,
                std::vector<bool> *i) const
                { return value_list(d, mysqlpp::quote, i); }
        CConfigData_cus_value_list<mysqlpp::quote_type0> value_list(const char* d,
                mysqlpp::sql_cmp_type sc) const
                { return value_list(d, mysqlpp::quote, sc); }
    
        template <class Manip>
        CConfigData_cus_value_list<Manip> value_list(const char* d, Manip m,
                bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false, bool i9 = false) const;
        template <class Manip>
        CConfigData_cus_value_list<Manip> value_list(const char* d, Manip m,
                CConfigData_enum i1, CConfigData_enum i2 = CONFIGDATA_NULL, CConfigData_enum i3 = CONFIGDATA_NULL, CConfigData_enum i4 = CONFIGDATA_NULL, CConfigData_enum i5 = CONFIGDATA_NULL, CConfigData_enum i6 = CONFIGDATA_NULL, CConfigData_enum i7 = CONFIGDATA_NULL, CConfigData_enum i8 = CONFIGDATA_NULL, CConfigData_enum i9 = CONFIGDATA_NULL) const;
        template <class Manip>
        CConfigData_cus_value_list<Manip> value_list(const char* d, Manip m,
                std::vector<bool>* i) const;
        template <class Manip>
        CConfigData_cus_value_list<Manip> value_list(const char* d, Manip m, 
                mysqlpp::sql_cmp_type sc) const;
        /* cus field */
    
        CConfigData_cus_field_list<mysqlpp::do_nothing_type0> field_list(bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false, bool i9 = false) const 
                { return field_list(",", mysqlpp::do_nothing, i1, i2, i3, i4, i5, i6, i7, i8, i9); }
        CConfigData_cus_field_list<mysqlpp::do_nothing_type0> field_list(CConfigData_enum i1, CConfigData_enum i2 = CONFIGDATA_NULL, CConfigData_enum i3 = CONFIGDATA_NULL, CConfigData_enum i4 = CONFIGDATA_NULL, CConfigData_enum i5 = CONFIGDATA_NULL, CConfigData_enum i6 = CONFIGDATA_NULL, CConfigData_enum i7 = CONFIGDATA_NULL, CConfigData_enum i8 = CONFIGDATA_NULL, CConfigData_enum i9 = CONFIGDATA_NULL) const
                { return field_list(",", mysqlpp::do_nothing, i1, i2, i3, i4, i5, i6, i7, i8, i9); }
        CConfigData_cus_field_list<mysqlpp::do_nothing_type0> field_list(std::vector<bool> *i) const
                { return field_list(",", mysqlpp::do_nothing, i); }
        CConfigData_cus_field_list<mysqlpp::do_nothing_type0> field_list(mysqlpp::sql_cmp_type sc) const
                { return field_list(",", mysqlpp::do_nothing, sc); }
    
        CConfigData_cus_field_list<mysqlpp::do_nothing_type0> field_list(const char* d,
                bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false, bool i9 = false) const
                { return field_list(d, mysqlpp::do_nothing, i1, i2, i3, i4, i5, i6, i7, i8, i9); }
        CConfigData_cus_field_list<mysqlpp::do_nothing_type0> field_list(const char* d,
                CConfigData_enum i1, CConfigData_enum i2 = CONFIGDATA_NULL, CConfigData_enum i3 = CONFIGDATA_NULL, CConfigData_enum i4 = CONFIGDATA_NULL, CConfigData_enum i5 = CONFIGDATA_NULL, CConfigData_enum i6 = CONFIGDATA_NULL, CConfigData_enum i7 = CONFIGDATA_NULL, CConfigData_enum i8 = CONFIGDATA_NULL, CConfigData_enum i9 = CONFIGDATA_NULL) const
                { return field_list(d, mysqlpp::do_nothing, i1, i2, i3, i4, i5, i6, i7, i8, i9); }
        CConfigData_cus_field_list<mysqlpp::do_nothing_type0> field_list(const char* d,
                std::vector<bool>* i) const
                { return field_list(d, mysqlpp::do_nothing, i); }
        CConfigData_cus_field_list<mysqlpp::do_nothing_type0> field_list(const char* d,
                mysqlpp::sql_cmp_type sc) const
                { return field_list(d, mysqlpp::do_nothing, sc); }
    
        template <class Manip>
        CConfigData_cus_field_list<Manip> field_list(const char* d, Manip m,
                bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false, bool i9 = false) const;
        template <class Manip>
        CConfigData_cus_field_list<Manip> field_list(const char* d, Manip m,
                CConfigData_enum i1, CConfigData_enum i2 = CONFIGDATA_NULL, CConfigData_enum i3 = CONFIGDATA_NULL, CConfigData_enum i4 = CONFIGDATA_NULL, CConfigData_enum i5 = CONFIGDATA_NULL, CConfigData_enum i6 = CONFIGDATA_NULL, CConfigData_enum i7 = CONFIGDATA_NULL, CConfigData_enum i8 = CONFIGDATA_NULL, CConfigData_enum i9 = CONFIGDATA_NULL) const;
        template <class Manip>
        CConfigData_cus_field_list<Manip> field_list(const char* d, Manip m,
                std::vector<bool> *i) const;
        template <class Manip>
        CConfigData_cus_field_list<Manip> field_list(const char* d, Manip m,
                mysqlpp::sql_cmp_type sc) const;
    
        /* cus equal */
    
        CConfigData_cus_equal_list<mysqlpp::quote_type0> equal_list(bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false, bool i9 = false) const
                { return equal_list(",", " = ", mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8, i9); }
        CConfigData_cus_equal_list<mysqlpp::quote_type0> equal_list(CConfigData_enum i1, CConfigData_enum i2 = CONFIGDATA_NULL, CConfigData_enum i3 = CONFIGDATA_NULL, CConfigData_enum i4 = CONFIGDATA_NULL, CConfigData_enum i5 = CONFIGDATA_NULL, CConfigData_enum i6 = CONFIGDATA_NULL, CConfigData_enum i7 = CONFIGDATA_NULL, CConfigData_enum i8 = CONFIGDATA_NULL, CConfigData_enum i9 = CONFIGDATA_NULL) const
                { return equal_list(",", " = ", mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8, i9); }
        CConfigData_cus_equal_list<mysqlpp::quote_type0> equal_list(std::vector<bool>* i) const
                { return equal_list(",", " = ", mysqlpp::quote, i); }
        CConfigData_cus_equal_list<mysqlpp::quote_type0> equal_list(mysqlpp::sql_cmp_type sc) const
                { return equal_list(",", " = ", mysqlpp::quote, sc); }
    
        CConfigData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d, bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false, bool i9 = false) const
                { return equal_list(d, " = ", mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8, i9); }
        CConfigData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d, CConfigData_enum i1, CConfigData_enum i2 = CONFIGDATA_NULL, CConfigData_enum i3 = CONFIGDATA_NULL, CConfigData_enum i4 = CONFIGDATA_NULL, CConfigData_enum i5 = CONFIGDATA_NULL, CConfigData_enum i6 = CONFIGDATA_NULL, CConfigData_enum i7 = CONFIGDATA_NULL, CConfigData_enum i8 = CONFIGDATA_NULL, CConfigData_enum i9 = CONFIGDATA_NULL) const
                { return equal_list(d, " = ", mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8, i9); }
        CConfigData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d,
                std::vector<bool> *i) const
                { return equal_list(d, " = ", mysqlpp::quote, i); }
        CConfigData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d,
                mysqlpp::sql_cmp_type sc) const
                { return equal_list(d, " = ", mysqlpp::quote, sc); }
    
        CConfigData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d, const char* c,
                bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false, bool i9 = false) const
                { return equal_list(d, c, mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8, i9); }
        CConfigData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d, const char* c,
                CConfigData_enum i1, CConfigData_enum i2 = CONFIGDATA_NULL, CConfigData_enum i3 = CONFIGDATA_NULL, CConfigData_enum i4 = CONFIGDATA_NULL, CConfigData_enum i5 = CONFIGDATA_NULL, CConfigData_enum i6 = CONFIGDATA_NULL, CConfigData_enum i7 = CONFIGDATA_NULL, CConfigData_enum i8 = CONFIGDATA_NULL, CConfigData_enum i9 = CONFIGDATA_NULL) const
                { return equal_list(d, c, mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8, i9); }
        CConfigData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d, const char* c,
                std::vector<bool> *i) const
                { return equal_list(d, c, mysqlpp::quote, i); }
        CConfigData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d, const char* c,
                mysqlpp::sql_cmp_type sc) const
                { return equal_list(d, c, mysqlpp::quote, sc); }
    
        template <class Manip>
        CConfigData_cus_equal_list<Manip> equal_list(const char* d, const char* c, Manip m, 
                            bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false, bool i9 = false) const;
        template <class Manip>
        CConfigData_cus_equal_list<Manip> equal_list(const char* d, const char* c, Manip m, 
                            CConfigData_enum i1, CConfigData_enum i2 = CONFIGDATA_NULL, CConfigData_enum i3 = CONFIGDATA_NULL, CConfigData_enum i4 = CONFIGDATA_NULL, CConfigData_enum i5 = CONFIGDATA_NULL, CConfigData_enum i6 = CONFIGDATA_NULL, CConfigData_enum i7 = CONFIGDATA_NULL, CConfigData_enum i8 = CONFIGDATA_NULL, CConfigData_enum i9 = CONFIGDATA_NULL) const;
        template <class Manip>
        CConfigData_cus_equal_list<Manip> equal_list(const char* d, const char* c, Manip m, 
                            std::vector<bool> *i) const;
        template <class Manip>
        CConfigData_cus_equal_list<Manip> equal_list(const char* d, const char* c, Manip m, 
                            mysqlpp::sql_cmp_type sc) const;
    
        private:
        static const char* table_;
        const char* table_override_;
        };
            
        template <class Manip>
        CConfigData_cus_value_list<Manip>::CConfigData_cus_value_list
                (const CConfigData* o, const char* d, Manip m, bool i1, bool i2, bool i3, bool i4, bool i5, bool i6, bool i7, bool i8, bool i9)
        {
            delim = d;
            manip = m;
            del_vector = true;
            obj = o;
            include = new std::vector<bool>(9, false);
        if (i1) (*include)[0]=true;
    if (i2) (*include)[1]=true;
    if (i3) (*include)[2]=true;
    if (i4) (*include)[3]=true;
    if (i5) (*include)[4]=true;
    if (i6) (*include)[5]=true;
    if (i7) (*include)[6]=true;
    if (i8) (*include)[7]=true;
    if (i9) (*include)[8]=true;

        }
    
        template <class Manip>
        CConfigData_cus_value_list<Manip>::CConfigData_cus_value_list
                (const CConfigData* o, const char* d, Manip m, CConfigData_enum i1, CConfigData_enum i2, CConfigData_enum i3, CConfigData_enum i4, CConfigData_enum i5, CConfigData_enum i6, CConfigData_enum i7, CConfigData_enum i8, CConfigData_enum i9)
        {
            delim = d;
            manip = m;
            del_vector = true;
            obj = o;
            include = new std::vector<bool>(9, false);
        (*include)[i1]=true;
    if (i2 == CONFIGDATA_NULL) return;
    (*include)[i2]=true;
    if (i3 == CONFIGDATA_NULL) return;
    (*include)[i3]=true;
    if (i4 == CONFIGDATA_NULL) return;
    (*include)[i4]=true;
    if (i5 == CONFIGDATA_NULL) return;
    (*include)[i5]=true;
    if (i6 == CONFIGDATA_NULL) return;
    (*include)[i6]=true;
    if (i7 == CONFIGDATA_NULL) return;
    (*include)[i7]=true;
    if (i8 == CONFIGDATA_NULL) return;
    (*include)[i8]=true;
    if (i9 == CONFIGDATA_NULL) return;
    (*include)[i9]=true;

        }
    
        template <class Manip>
        CConfigData_cus_field_list<Manip>::CConfigData_cus_field_list
                (const CConfigData* o, const char* d, Manip m, bool i1, bool i2, bool i3, bool i4, bool i5, bool i6, bool i7, bool i8, bool i9)
        {
            delim = d;
            manip = m;
            del_vector = true;
            obj = o;
            include = new std::vector<bool>(9, false);
        if (i1) (*include)[0]=true;
    if (i2) (*include)[1]=true;
    if (i3) (*include)[2]=true;
    if (i4) (*include)[3]=true;
    if (i5) (*include)[4]=true;
    if (i6) (*include)[5]=true;
    if (i7) (*include)[6]=true;
    if (i8) (*include)[7]=true;
    if (i9) (*include)[8]=true;

        }
    
        template <class Manip>
        CConfigData_cus_field_list<Manip>::CConfigData_cus_field_list
                (const CConfigData* o, const char* d, Manip m, CConfigData_enum i1, CConfigData_enum i2, CConfigData_enum i3, CConfigData_enum i4, CConfigData_enum i5, CConfigData_enum i6, CConfigData_enum i7, CConfigData_enum i8, CConfigData_enum i9)
        {
            delim = d;
            manip = m;
            del_vector = true;
            obj = o;
            include = new std::vector<bool>(9, false);
        (*include)[i1]=true;
    if (i2 == CONFIGDATA_NULL) return;
    (*include)[i2]=true;
    if (i3 == CONFIGDATA_NULL) return;
    (*include)[i3]=true;
    if (i4 == CONFIGDATA_NULL) return;
    (*include)[i4]=true;
    if (i5 == CONFIGDATA_NULL) return;
    (*include)[i5]=true;
    if (i6 == CONFIGDATA_NULL) return;
    (*include)[i6]=true;
    if (i7 == CONFIGDATA_NULL) return;
    (*include)[i7]=true;
    if (i8 == CONFIGDATA_NULL) return;
    (*include)[i8]=true;
    if (i9 == CONFIGDATA_NULL) return;
    (*include)[i9]=true;

        }
    
        template <class Manip>
        CConfigData_cus_equal_list<Manip>::CConfigData_cus_equal_list
                (const CConfigData* o, const char* d, const char* c, Manip m, bool i1, bool i2, bool i3, bool i4, bool i5, bool i6, bool i7, bool i8, bool i9)
        {
            delim = d;
            comp = c;
            manip = m;
            del_vector = true;
            obj = o;
            include = new std::vector<bool>(9, false);
        if (i1) (*include)[0]=true;
    if (i2) (*include)[1]=true;
    if (i3) (*include)[2]=true;
    if (i4) (*include)[3]=true;
    if (i5) (*include)[4]=true;
    if (i6) (*include)[5]=true;
    if (i7) (*include)[6]=true;
    if (i8) (*include)[7]=true;
    if (i9) (*include)[8]=true;

        }
    
        template <class Manip>
        CConfigData_cus_equal_list<Manip>::CConfigData_cus_equal_list
                (const CConfigData* o, const char* d, const char* c, Manip m, CConfigData_enum i1, CConfigData_enum i2, CConfigData_enum i3, CConfigData_enum i4, CConfigData_enum i5, CConfigData_enum i6, CConfigData_enum i7, CConfigData_enum i8, CConfigData_enum i9)
        {
            delim = d;
            comp = c;
            manip = m;
            del_vector = true;
            obj = o;
            include = new std::vector<bool>(9, false);
        (*include)[i1]=true;
    if (i2 == CONFIGDATA_NULL) return;
    (*include)[i2]=true;
    if (i3 == CONFIGDATA_NULL) return;
    (*include)[i3]=true;
    if (i4 == CONFIGDATA_NULL) return;
    (*include)[i4]=true;
    if (i5 == CONFIGDATA_NULL) return;
    (*include)[i5]=true;
    if (i6 == CONFIGDATA_NULL) return;
    (*include)[i6]=true;
    if (i7 == CONFIGDATA_NULL) return;
    (*include)[i7]=true;
    if (i8 == CONFIGDATA_NULL) return;
    (*include)[i8]=true;
    if (i9 == CONFIGDATA_NULL) return;
    (*include)[i9]=true;

        }
    
        template <class Manip>
        std::ostream& operator <<(std::ostream& s, const CConfigData_value_list<Manip>& obj)
        {
        s << obj.manip << obj.obj->id << obj.delim;
    s << obj.manip << obj.obj->type << obj.delim;
    s << obj.manip << obj.obj->data1 << obj.delim;
    s << obj.manip << obj.obj->data2 << obj.delim;
    s << obj.manip << obj.obj->data3 << obj.delim;
    s << obj.manip << obj.obj->data4 << obj.delim;
    s << obj.manip << obj.obj->data5 << obj.delim;
    s << obj.manip << obj.obj->str << obj.delim;
    s << obj.manip << obj.obj->desc;
            return s;
        }
    
        template <class Manip>
        std::ostream& operator <<(std::ostream& s, const CConfigData_field_list<Manip>& obj)
        {
        s << obj.manip << '`' << obj.obj->names[0] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[1] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[2] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[3] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[4] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[5] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[6] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[7] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[8] << '`';
            return s;
        }
    
        template <class Manip>
        std::ostream& operator <<(std::ostream& s, const CConfigData_equal_list<Manip>& obj)
        {
        s << '`' << obj.obj->names[0] << '`' << obj.comp << obj.manip << obj.obj->id << obj.delim;
    s << '`' << obj.obj->names[1] << '`' << obj.comp << obj.manip << obj.obj->type << obj.delim;
    s << '`' << obj.obj->names[2] << '`' << obj.comp << obj.manip << obj.obj->data1 << obj.delim;
    s << '`' << obj.obj->names[3] << '`' << obj.comp << obj.manip << obj.obj->data2 << obj.delim;
    s << '`' << obj.obj->names[4] << '`' << obj.comp << obj.manip << obj.obj->data3 << obj.delim;
    s << '`' << obj.obj->names[5] << '`' << obj.comp << obj.manip << obj.obj->data4 << obj.delim;
    s << '`' << obj.obj->names[6] << '`' << obj.comp << obj.manip << obj.obj->data5 << obj.delim;
    s << '`' << obj.obj->names[7] << '`' << obj.comp << obj.manip << obj.obj->str << obj.delim;
    s << '`' << obj.obj->names[8] << '`' << obj.comp << obj.manip << obj.obj->desc;
            return s;
        }
    
        template <class Manip>
        std::ostream& operator <<(std::ostream& s, const CConfigData_cus_value_list<Manip>& obj)
        {
            bool before = false;
        if ((*obj.include)[0]) { 
      s << obj.manip << obj.obj->id;
      before = true; 
     } 
    if ((*obj.include)[1]) { 
      if (before) s << obj.delim;
      s << obj.manip << obj.obj->type;
      before = true; 
     } 
    if ((*obj.include)[2]) { 
      if (before) s << obj.delim;
      s << obj.manip << obj.obj->data1;
      before = true; 
     } 
    if ((*obj.include)[3]) { 
      if (before) s << obj.delim;
      s << obj.manip << obj.obj->data2;
      before = true; 
     } 
    if ((*obj.include)[4]) { 
      if (before) s << obj.delim;
      s << obj.manip << obj.obj->data3;
      before = true; 
     } 
    if ((*obj.include)[5]) { 
      if (before) s << obj.delim;
      s << obj.manip << obj.obj->data4;
      before = true; 
     } 
    if ((*obj.include)[6]) { 
      if (before) s << obj.delim;
      s << obj.manip << obj.obj->data5;
      before = true; 
     } 
    if ((*obj.include)[7]) { 
      if (before) s << obj.delim;
      s << obj.manip << obj.obj->str;
      before = true; 
     } 
    if ((*obj.include)[8]) { 
      if (before) s << obj.delim;
      s << obj.manip << obj.obj->desc;
     } 

            return s;
        }
    
        template <class Manip>
        std::ostream& operator <<(std::ostream& s, const CConfigData_cus_field_list<Manip>& obj)
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
     } 

            return s;
        }
    
        template <class Manip>
        std::ostream& operator <<(std::ostream& s, const CConfigData_cus_equal_list<Manip>& obj)
        {
            bool before = false;
        if ((*obj.include)[0]) { 
      s << '`' << obj.obj->names[0] << '`' << obj.comp         << obj.manip << obj.obj->id;
      before = true; 
     } 
    if ((*obj.include)[1]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[1] << '`' << obj.comp         << obj.manip << obj.obj->type;
      before = true; 
     } 
    if ((*obj.include)[2]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[2] << '`' << obj.comp         << obj.manip << obj.obj->data1;
      before = true; 
     } 
    if ((*obj.include)[3]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[3] << '`' << obj.comp         << obj.manip << obj.obj->data2;
      before = true; 
     } 
    if ((*obj.include)[4]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[4] << '`' << obj.comp         << obj.manip << obj.obj->data3;
      before = true; 
     } 
    if ((*obj.include)[5]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[5] << '`' << obj.comp         << obj.manip << obj.obj->data4;
      before = true; 
     } 
    if ((*obj.include)[6]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[6] << '`' << obj.comp         << obj.manip << obj.obj->data5;
      before = true; 
     } 
    if ((*obj.include)[7]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[7] << '`' << obj.comp         << obj.manip << obj.obj->str;
      before = true; 
     } 
    if ((*obj.include)[8]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[8] << '`' << obj.comp         << obj.manip << obj.obj->desc;
     } 

            return s;
        }
    
        template <class Manip>
        inline CConfigData_value_list<Manip> CConfigData::value_list(const char* d, Manip m) const
                { return CConfigData_value_list<Manip> (this, d, m); } 
    
        template <class Manip>
        inline CConfigData_field_list<Manip> CConfigData::field_list(const char* d, Manip m) const
                { return CConfigData_field_list<Manip> (this, d, m); } 
    
        template <class Manip>
        inline CConfigData_equal_list<Manip> CConfigData::equal_list(const char* d, const char* c, Manip m) const
                { return CConfigData_equal_list<Manip> (this, d, c, m); } 
    
        template <class Manip>
        inline CConfigData_cus_value_list<Manip> CConfigData::value_list(const char* d, Manip m,
                bool i1, bool i2, bool i3, bool i4, bool i5, bool i6, bool i7, bool i8, bool i9) const
                { return CConfigData_cus_value_list<Manip> (this, d, m, i1, i2, i3, i4, i5, i6, i7, i8, i9); }
    
        template <class Manip>
        inline CConfigData_cus_field_list<Manip> CConfigData::field_list(const char* d, Manip m,
                bool i1, bool i2, bool i3, bool i4, bool i5, bool i6, bool i7, bool i8, bool i9) const
                { return CConfigData_cus_field_list<Manip> (this, d, m, i1, i2, i3, i4, i5, i6, i7, i8, i9); }
    
        template <class Manip>
        inline CConfigData_cus_equal_list<Manip> CConfigData::equal_list(const char* d, const char* c, Manip m,
                bool i1, bool i2, bool i3, bool i4, bool i5, bool i6, bool i7, bool i8, bool i9) const
                { return CConfigData_cus_equal_list<Manip> (this, d, c, m, i1, i2, i3, i4, i5, i6, i7, i8, i9); } 
    
        template <class Manip>
        inline CConfigData_cus_value_list<Manip> CConfigData::value_list(const char* d, Manip m,
                CConfigData_enum i1, CConfigData_enum i2, CConfigData_enum i3, CConfigData_enum i4, CConfigData_enum i5, CConfigData_enum i6, CConfigData_enum i7, CConfigData_enum i8, CConfigData_enum i9) const
                { return CConfigData_cus_value_list<Manip> (this, d, m, i1, i2, i3, i4, i5, i6, i7, i8, i9); } 
    
        template <class Manip>
        inline CConfigData_cus_field_list<Manip> CConfigData::field_list(const char* d, Manip m,
                CConfigData_enum i1, CConfigData_enum i2, CConfigData_enum i3, CConfigData_enum i4, CConfigData_enum i5, CConfigData_enum i6, CConfigData_enum i7, CConfigData_enum i8, CConfigData_enum i9) const
                { return CConfigData_cus_field_list<Manip> (this, d, m, i1, i2, i3, i4, i5, i6, i7, i8, i9); } 
    
        template <class Manip>
        inline CConfigData_cus_equal_list<Manip> CConfigData::equal_list(const char* d, const char* c, Manip m, 
                CConfigData_enum i1, CConfigData_enum i2, CConfigData_enum i3, CConfigData_enum i4, CConfigData_enum i5, CConfigData_enum i6, CConfigData_enum i7, CConfigData_enum i8, CConfigData_enum i9) const
                { return CConfigData_cus_equal_list<Manip> (this, d, c, m, i1, i2, i3, i4, i5, i6, i7, i8, i9); } 
    
        template <class Manip>
        inline CConfigData_cus_value_list<Manip> CConfigData::value_list(const char* d, Manip m,
                std::vector<bool> *i) const
                { return CConfigData_cus_value_list<Manip> (this, d, m, i); }
    
        template <class Manip>
        inline CConfigData_cus_field_list<Manip> CConfigData::field_list(const char* d, Manip m,
                std::vector<bool> *i) const
                { return CConfigData_cus_field_list<Manip> (this, d, m, i); }
    
        template <class Manip>
        inline CConfigData_cus_equal_list<Manip> CConfigData::equal_list(const char* d, const char* c, Manip m,
                std::vector<bool> *i) const
                { return CConfigData_cus_equal_list<Manip> (this, d, c, m, i); }
    
        template <class Manip>
        inline CConfigData_cus_value_list<Manip> 
        CConfigData::value_list(const char* d, Manip m, mysqlpp::sql_cmp_type /*sc*/) const
                { return value_list(d, m, true, true, true, true, true, true, true, true, true); }
    
        template <class Manip>
        inline CConfigData_cus_field_list<Manip> 
        CConfigData::field_list(const char* d, Manip m, mysqlpp::sql_cmp_type /*sc*/) const
                { return field_list(d, m, true, true, true, true, true, true, true, true, true); }
    
        template <class Manip>
        inline CConfigData_cus_equal_list<Manip> 
        CConfigData::equal_list(const char* d, const char* c, Manip m, mysqlpp::sql_cmp_type /*sc*/) const
                { return equal_list(d, c, m, true, true, true, true, true, true, true, true, true); }
    
        template <mysqlpp::sql_dummy_type dummy>
        void populate_CConfigData(CConfigData *s, const mysqlpp::Row &row)
        {
            mysqlpp::NoExceptions ignore_schema_mismatches(row);
        s->id = row["id"].conv(sql_int_unsigned());
    s->type = row["type"].conv(sql_int_unsigned());
    s->data1 = row["data1"].conv(sql_int_unsigned());
    s->data2 = row["data2"].conv(sql_int_unsigned());
    s->data3 = row["data3"].conv(sql_int_unsigned());
    s->data4 = row["data4"].conv(sql_int_unsigned());
    s->data5 = row["data5"].conv(sql_int_unsigned());
    s->str = row["str"].conv(sql_char());
    s->desc = row["desc"].conv(sql_char());
        }
    
        inline CConfigData::CConfigData(const mysqlpp::Row& row) :
        table_override_(0)
                { populate_CConfigData<mysqlpp::sql_dummy>(this, row); }
        inline void CConfigData::set(const mysqlpp::Row& row)
        {
            table_override_ = 0;
            populate_CConfigData<mysqlpp::sql_dummy>(this, row);
        }
    
        template <mysqlpp::sql_dummy_type dummy> 
 int sql_compare_CConfigData(const CConfigData &x, const CConfigData &y) { 
     int cmp; \
    cmp = mysqlpp::sql_cmp(x.id, y.id ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.type, y.type ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.data1, y.data1 ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.data2, y.data2 ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.data3, y.data3 ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.data4, y.data4 ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.data5, y.data5 ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.str, y.str ); \
    if (cmp) return cmp; \
    return mysqlpp::sql_cmp(x.desc, y.desc); 
 } 
 template <mysqlpp::sql_dummy_type dummy> 
 int compare (const CConfigData &x, const CConfigData &y) { 
     int cmp; \
    cmp = mysqlpp::sql_cmp(x.id, y.id ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.type, y.type ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.data1, y.data1 ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.data2, y.data2 ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.data3, y.data3 ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.data4, y.data4 ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.data5, y.data5 ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.str, y.str ); \
    if (cmp) return cmp; \
    return mysqlpp::sql_cmp(x.desc, y.desc); 
 }

#endif	//end of define _CONFIG_DATA_H_