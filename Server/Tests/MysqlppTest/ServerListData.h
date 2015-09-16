////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author: 	Fu Yan
// Created: 	2015-07-07
// Describe: 	Specailized SQL structure of table @tblname, 
//				generate by genSsqls.py, !!!DO NOT EDIT!!!
////////////////////////////////////////////////////////////////////////
#ifndef _SERVER_LIST_DATA_H_
#define _SERVER_LIST_DATA_H_

#include <mysql++.h>
#include <ssqls.h>

using namespace mysqlpp;

struct CServerListData; 

    enum CServerListData_enum { 
    SERVERLISTDATA_ID,
    SERVERLISTDATA_SECTION_ID,
    SERVERLISTDATA_NAME,
    SERVERLISTDATA_REAL_NAME,
    SERVERLISTDATA_DOMAIN_NAME,
    SERVERLISTDATA_SERVER_INDEX,
    SERVERLISTDATA_MASK,
    SERVERLISTDATA_SUBSECTION,
    SERVERLISTDATA_ORDER_TIME,
    SERVERLISTDATA_FLAG,
    SERVERLISTDATA_NULL 
    }; 

    template <class Manip>
    class CServerListData_value_list { 
    public: 
    const CServerListData* obj;
    const char* delim;
    Manip manip;
    public: 
    CServerListData_value_list (const CServerListData* o, const char* d, Manip m) :
    obj(o), delim(d), manip(m) { } 
    };

    template <class Manip>
    class CServerListData_field_list {
    public: 
    const CServerListData* obj; 
    const char* delim;
    Manip manip;
    public: 
    CServerListData_field_list (const CServerListData* o, const char* d, Manip m) :
    obj(o), delim(d), manip(m) { } 
    };

    template <class Manip>
    class CServerListData_equal_list { 
    public: 
    const CServerListData* obj;
    const char* delim;
    const char* comp;
    Manip manip;
    public: 
    CServerListData_equal_list (const CServerListData* o, const char* d, const char* c, Manip m) :
    obj(o), delim(d), comp(c), manip(m) { }
    };

    template <class Manip>
    class CServerListData_cus_value_list {
    public:
    const CServerListData* obj;
    std::vector<bool> *include;
    bool del_vector;
    const char* delim;
    Manip manip;
    public: 
    ~CServerListData_cus_value_list () {if (del_vector) delete include;} 
    CServerListData_cus_value_list (const CServerListData* o, const char* d, Manip m, bool i1, bool i2, bool i3, bool i4, bool i5, bool i6, bool i7, bool i8, bool i9, bool i10);
    CServerListData_cus_value_list (const CServerListData* o, const char* d, Manip m, CServerListData_enum i1, CServerListData_enum i2, CServerListData_enum i3, CServerListData_enum i4, CServerListData_enum i5, CServerListData_enum i6, CServerListData_enum i7, CServerListData_enum i8, CServerListData_enum i9, CServerListData_enum i10); 
    CServerListData_cus_value_list (const CServerListData* o, const char* d, Manip m ,std::vector<bool>* i) :
    obj(o), include(i), del_vector(false), delim(d), manip(m) { }
    };

    template <class Manip>
    class CServerListData_cus_field_list { 
    public:
    const CServerListData* obj; 
    std::vector<bool> *include; 
    bool del_vector; 
    const char* delim;
    Manip manip;
    public: 
    ~CServerListData_cus_field_list () {if (del_vector) delete include;} 
    CServerListData_cus_field_list (const CServerListData* o, const char* d, Manip m, bool i1, bool i2, bool i3, bool i4, bool i5, bool i6, bool i7, bool i8, bool i9, bool i10); 
    CServerListData_cus_field_list (const CServerListData* o, const char* d, Manip m, CServerListData_enum i1, CServerListData_enum i2, CServerListData_enum i3, CServerListData_enum i4, CServerListData_enum i5, CServerListData_enum i6, CServerListData_enum i7, CServerListData_enum i8, CServerListData_enum i9, CServerListData_enum i10); 
    CServerListData_cus_field_list (const CServerListData* o, const char* d, Manip m, std::vector<bool> *i) :
    obj(o), include(i), del_vector(false), delim(d), manip(m) { }
    };

    template <class Manip>
    class CServerListData_cus_equal_list {
    public:
    const CServerListData* obj;
    std::vector<bool> *include;
    bool del_vector;
    const char* delim;
    const char* comp;
    Manip manip;
    public:
    ~CServerListData_cus_equal_list () {if (del_vector) delete include;}
    CServerListData_cus_equal_list (const CServerListData* o, const char* d, const char* c, Manip m, bool i1, bool i2, bool i3, bool i4, bool i5, bool i6, bool i7, bool i8, bool i9, bool i10); 
    CServerListData_cus_equal_list (const CServerListData* o, const char* d, const char* c, Manip m, CServerListData_enum i1, CServerListData_enum i2, CServerListData_enum i3, CServerListData_enum i4, CServerListData_enum i5, CServerListData_enum i6, CServerListData_enum i7, CServerListData_enum i8, CServerListData_enum i9, CServerListData_enum i10); 
    CServerListData_cus_equal_list (const CServerListData* o, const char* d, const char* c, Manip m, std::vector<bool> *i) :
    obj(o), include(i), del_vector(false), delim(d), comp(c), manip(m) { }
    };

    template <mysqlpp::sql_dummy_type dummy> int sql_compare_CServerListData(const CServerListData&, const CServerListData&);

    struct CServerListData {
    sql_int_unsigned id;
    sql_int_unsigned section_id;
    sql_varchar name;
    sql_varchar real_name;
    sql_varchar domain_name;
    sql_int_unsigned server_index;
    sql_int_unsigned mask;
    sql_int_unsigned subsection;
    sql_int_unsigned order_time;
    sql_int_unsigned flag; 
    CServerListData() : table_override_(0) { }
    CServerListData(const mysqlpp::Row& row);
    void set(const mysqlpp::Row &row);
    CServerListData(const sql_int_unsigned &p1, const sql_int_unsigned &p2, const sql_varchar &p3, const sql_varchar &p4, const sql_varchar &p5, const sql_int_unsigned &p6, const sql_int_unsigned &p7, const sql_int_unsigned &p8, const sql_int_unsigned &p9, const sql_int_unsigned &p10) : id (p1), section_id (p2), name (p3), real_name (p4), domain_name (p5), server_index (p6), mask (p7), subsection (p8), order_time (p9), flag (p10), table_override_(0) {}
void set(const sql_int_unsigned &p1, const sql_int_unsigned &p2, const sql_varchar &p3, const sql_varchar &p4, const sql_varchar &p5, const sql_int_unsigned &p6, const sql_int_unsigned &p7, const sql_int_unsigned &p8, const sql_int_unsigned &p9, const sql_int_unsigned &p10) {
table_override_ = 0;
    id = p1;\
    section_id = p2;\
    name = p3;\
    real_name = p4;\
    domain_name = p5;\
    server_index = p6;\
    mask = p7;\
    subsection = p8;\
    order_time = p9;\
    flag = p10;\

}
bool operator == (const CServerListData &other) const 
 {return sql_compare_CServerListData<mysqlpp::sql_dummy>(*this,other) == 0;} 
 bool operator != (const CServerListData &other) const 
 {return sql_compare_CServerListData<mysqlpp::sql_dummy>(*this,other) != 0;} 
 bool operator > (const CServerListData &other) const 
 {return sql_compare_CServerListData<mysqlpp::sql_dummy>(*this,other) >  0;} 
 bool operator < (const CServerListData &other) const 
 {return sql_compare_CServerListData<mysqlpp::sql_dummy>(*this,other) <  0;} 
 bool operator >= (const CServerListData &other) const 
 {return sql_compare_CServerListData<mysqlpp::sql_dummy>(*this,other) >= 0;} 
 bool operator <= (const CServerListData &other) const 
 {return sql_compare_CServerListData<mysqlpp::sql_dummy>(*this,other) <= 0;} 
 int cmp (const CServerListData &other) const 
 {return sql_compare_CServerListData<mysqlpp::sql_dummy>(*this,other);} 
 int compare (const CServerListData &other) const 
 {return sql_compare_CServerListData<mysqlpp::sql_dummy>(*this,other);}

    void set(const sql_int_unsigned p1) { \
    table_override_ = 0;

    id = p1;


    } \
    CServerListData(const sql_int_unsigned p1) : id(p1), table_override_(0) {}
    static const char* names[];
    static void table(const char* t) { table_ = t; }
    const char* table() const
            { return table_override_ ? table_override_ : CServerListData::table_; }
    void instance_table(const char* t) { table_override_ = t; }

    CServerListData_value_list<mysqlpp::quote_type0> value_list() const {
        return value_list(",", mysqlpp::quote);}
    CServerListData_value_list<mysqlpp::quote_type0> value_list(const char* d) const {
        return value_list(d, mysqlpp::quote);}
    template <class Manip>
    CServerListData_value_list<Manip> value_list(const char* d, Manip m) const;

    CServerListData_field_list<mysqlpp::do_nothing_type0> field_list() const {
        return field_list(",", mysqlpp::do_nothing);}
    CServerListData_field_list<mysqlpp::do_nothing_type0> field_list(const char* d) const {
        return field_list(d, mysqlpp::do_nothing);}
    template <class Manip>
    CServerListData_field_list<Manip> field_list(const char* d, Manip m) const;

    CServerListData_equal_list<mysqlpp::quote_type0> equal_list(const char* d = ",",
            const char* c = " = ") const
            { return equal_list(d, c, mysqlpp::quote); }
    template <class Manip>
    CServerListData_equal_list<Manip> equal_list(const char* d, const char* c, Manip m) const;

    /* cus_data */

    CServerListData_cus_value_list<mysqlpp::quote_type0> value_list(bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false, bool i9 = false, bool i10 = false) const
            { return value_list(",", mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10); }
    CServerListData_cus_value_list<mysqlpp::quote_type0> value_list(CServerListData_enum i1, CServerListData_enum i2 = SERVERLISTDATA_NULL, CServerListData_enum i3 = SERVERLISTDATA_NULL, CServerListData_enum i4 = SERVERLISTDATA_NULL, CServerListData_enum i5 = SERVERLISTDATA_NULL, CServerListData_enum i6 = SERVERLISTDATA_NULL, CServerListData_enum i7 = SERVERLISTDATA_NULL, CServerListData_enum i8 = SERVERLISTDATA_NULL, CServerListData_enum i9 = SERVERLISTDATA_NULL, CServerListData_enum i10 = SERVERLISTDATA_NULL) const
            { return value_list(",", mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10); }
    CServerListData_cus_value_list<mysqlpp::quote_type0> value_list(std::vector<bool> *i) const
            { return value_list(",", mysqlpp::quote, i); }
    CServerListData_cus_value_list<mysqlpp::quote_type0> value_list(mysqlpp::sql_cmp_type sc) const
            { return value_list(",", mysqlpp::quote, sc); }

    CServerListData_cus_value_list<mysqlpp::quote_type0> value_list(const char* d, bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false, bool i9 = false, bool i10 = false) const
            { return value_list(d, mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10); }
    CServerListData_cus_value_list<mysqlpp::quote_type0> value_list(const char* d, CServerListData_enum i1, CServerListData_enum i2 = SERVERLISTDATA_NULL, CServerListData_enum i3 = SERVERLISTDATA_NULL, CServerListData_enum i4 = SERVERLISTDATA_NULL, CServerListData_enum i5 = SERVERLISTDATA_NULL, CServerListData_enum i6 = SERVERLISTDATA_NULL, CServerListData_enum i7 = SERVERLISTDATA_NULL, CServerListData_enum i8 = SERVERLISTDATA_NULL, CServerListData_enum i9 = SERVERLISTDATA_NULL, CServerListData_enum i10 = SERVERLISTDATA_NULL) const
            { return value_list(d, mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10); }
    CServerListData_cus_value_list<mysqlpp::quote_type0> value_list(const char* d,
            std::vector<bool> *i) const
            { return value_list(d, mysqlpp::quote, i); }
    CServerListData_cus_value_list<mysqlpp::quote_type0> value_list(const char* d,
            mysqlpp::sql_cmp_type sc) const
            { return value_list(d, mysqlpp::quote, sc); }

    template <class Manip>
    CServerListData_cus_value_list<Manip> value_list(const char* d, Manip m,
            bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false, bool i9 = false, bool i10 = false) const;
    template <class Manip>
    CServerListData_cus_value_list<Manip> value_list(const char* d, Manip m,
            CServerListData_enum i1, CServerListData_enum i2 = SERVERLISTDATA_NULL, CServerListData_enum i3 = SERVERLISTDATA_NULL, CServerListData_enum i4 = SERVERLISTDATA_NULL, CServerListData_enum i5 = SERVERLISTDATA_NULL, CServerListData_enum i6 = SERVERLISTDATA_NULL, CServerListData_enum i7 = SERVERLISTDATA_NULL, CServerListData_enum i8 = SERVERLISTDATA_NULL, CServerListData_enum i9 = SERVERLISTDATA_NULL, CServerListData_enum i10 = SERVERLISTDATA_NULL) const;
    template <class Manip>
    CServerListData_cus_value_list<Manip> value_list(const char* d, Manip m,
            std::vector<bool>* i) const;
    template <class Manip>
    CServerListData_cus_value_list<Manip> value_list(const char* d, Manip m, 
            mysqlpp::sql_cmp_type sc) const;
    /* cus field */

    CServerListData_cus_field_list<mysqlpp::do_nothing_type0> field_list(bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false, bool i9 = false, bool i10 = false) const 
            { return field_list(",", mysqlpp::do_nothing, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10); }
    CServerListData_cus_field_list<mysqlpp::do_nothing_type0> field_list(CServerListData_enum i1, CServerListData_enum i2 = SERVERLISTDATA_NULL, CServerListData_enum i3 = SERVERLISTDATA_NULL, CServerListData_enum i4 = SERVERLISTDATA_NULL, CServerListData_enum i5 = SERVERLISTDATA_NULL, CServerListData_enum i6 = SERVERLISTDATA_NULL, CServerListData_enum i7 = SERVERLISTDATA_NULL, CServerListData_enum i8 = SERVERLISTDATA_NULL, CServerListData_enum i9 = SERVERLISTDATA_NULL, CServerListData_enum i10 = SERVERLISTDATA_NULL) const
            { return field_list(",", mysqlpp::do_nothing, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10); }
    CServerListData_cus_field_list<mysqlpp::do_nothing_type0> field_list(std::vector<bool> *i) const
            { return field_list(",", mysqlpp::do_nothing, i); }
    CServerListData_cus_field_list<mysqlpp::do_nothing_type0> field_list(mysqlpp::sql_cmp_type sc) const
            { return field_list(",", mysqlpp::do_nothing, sc); }

    CServerListData_cus_field_list<mysqlpp::do_nothing_type0> field_list(const char* d,
            bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false, bool i9 = false, bool i10 = false) const
            { return field_list(d, mysqlpp::do_nothing, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10); }
    CServerListData_cus_field_list<mysqlpp::do_nothing_type0> field_list(const char* d,
            CServerListData_enum i1, CServerListData_enum i2 = SERVERLISTDATA_NULL, CServerListData_enum i3 = SERVERLISTDATA_NULL, CServerListData_enum i4 = SERVERLISTDATA_NULL, CServerListData_enum i5 = SERVERLISTDATA_NULL, CServerListData_enum i6 = SERVERLISTDATA_NULL, CServerListData_enum i7 = SERVERLISTDATA_NULL, CServerListData_enum i8 = SERVERLISTDATA_NULL, CServerListData_enum i9 = SERVERLISTDATA_NULL, CServerListData_enum i10 = SERVERLISTDATA_NULL) const
            { return field_list(d, mysqlpp::do_nothing, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10); }
    CServerListData_cus_field_list<mysqlpp::do_nothing_type0> field_list(const char* d,
            std::vector<bool>* i) const
            { return field_list(d, mysqlpp::do_nothing, i); }
    CServerListData_cus_field_list<mysqlpp::do_nothing_type0> field_list(const char* d,
            mysqlpp::sql_cmp_type sc) const
            { return field_list(d, mysqlpp::do_nothing, sc); }

    template <class Manip>
    CServerListData_cus_field_list<Manip> field_list(const char* d, Manip m,
            bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false, bool i9 = false, bool i10 = false) const;
    template <class Manip>
    CServerListData_cus_field_list<Manip> field_list(const char* d, Manip m,
            CServerListData_enum i1, CServerListData_enum i2 = SERVERLISTDATA_NULL, CServerListData_enum i3 = SERVERLISTDATA_NULL, CServerListData_enum i4 = SERVERLISTDATA_NULL, CServerListData_enum i5 = SERVERLISTDATA_NULL, CServerListData_enum i6 = SERVERLISTDATA_NULL, CServerListData_enum i7 = SERVERLISTDATA_NULL, CServerListData_enum i8 = SERVERLISTDATA_NULL, CServerListData_enum i9 = SERVERLISTDATA_NULL, CServerListData_enum i10 = SERVERLISTDATA_NULL) const;
    template <class Manip>
    CServerListData_cus_field_list<Manip> field_list(const char* d, Manip m,
            std::vector<bool> *i) const;
    template <class Manip>
    CServerListData_cus_field_list<Manip> field_list(const char* d, Manip m,
            mysqlpp::sql_cmp_type sc) const;

    /* cus equal */

    CServerListData_cus_equal_list<mysqlpp::quote_type0> equal_list(bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false, bool i9 = false, bool i10 = false) const
            { return equal_list(",", " = ", mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10); }
    CServerListData_cus_equal_list<mysqlpp::quote_type0> equal_list(CServerListData_enum i1, CServerListData_enum i2 = SERVERLISTDATA_NULL, CServerListData_enum i3 = SERVERLISTDATA_NULL, CServerListData_enum i4 = SERVERLISTDATA_NULL, CServerListData_enum i5 = SERVERLISTDATA_NULL, CServerListData_enum i6 = SERVERLISTDATA_NULL, CServerListData_enum i7 = SERVERLISTDATA_NULL, CServerListData_enum i8 = SERVERLISTDATA_NULL, CServerListData_enum i9 = SERVERLISTDATA_NULL, CServerListData_enum i10 = SERVERLISTDATA_NULL) const
            { return equal_list(",", " = ", mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10); }
    CServerListData_cus_equal_list<mysqlpp::quote_type0> equal_list(std::vector<bool>* i) const
            { return equal_list(",", " = ", mysqlpp::quote, i); }
    CServerListData_cus_equal_list<mysqlpp::quote_type0> equal_list(mysqlpp::sql_cmp_type sc) const
            { return equal_list(",", " = ", mysqlpp::quote, sc); }

    CServerListData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d, bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false, bool i9 = false, bool i10 = false) const
            { return equal_list(d, " = ", mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10); }
    CServerListData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d, CServerListData_enum i1, CServerListData_enum i2 = SERVERLISTDATA_NULL, CServerListData_enum i3 = SERVERLISTDATA_NULL, CServerListData_enum i4 = SERVERLISTDATA_NULL, CServerListData_enum i5 = SERVERLISTDATA_NULL, CServerListData_enum i6 = SERVERLISTDATA_NULL, CServerListData_enum i7 = SERVERLISTDATA_NULL, CServerListData_enum i8 = SERVERLISTDATA_NULL, CServerListData_enum i9 = SERVERLISTDATA_NULL, CServerListData_enum i10 = SERVERLISTDATA_NULL) const
            { return equal_list(d, " = ", mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10); }
    CServerListData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d,
            std::vector<bool> *i) const
            { return equal_list(d, " = ", mysqlpp::quote, i); }
    CServerListData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d,
            mysqlpp::sql_cmp_type sc) const
            { return equal_list(d, " = ", mysqlpp::quote, sc); }

    CServerListData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d, const char* c,
            bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false, bool i9 = false, bool i10 = false) const
            { return equal_list(d, c, mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10); }
    CServerListData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d, const char* c,
            CServerListData_enum i1, CServerListData_enum i2 = SERVERLISTDATA_NULL, CServerListData_enum i3 = SERVERLISTDATA_NULL, CServerListData_enum i4 = SERVERLISTDATA_NULL, CServerListData_enum i5 = SERVERLISTDATA_NULL, CServerListData_enum i6 = SERVERLISTDATA_NULL, CServerListData_enum i7 = SERVERLISTDATA_NULL, CServerListData_enum i8 = SERVERLISTDATA_NULL, CServerListData_enum i9 = SERVERLISTDATA_NULL, CServerListData_enum i10 = SERVERLISTDATA_NULL) const
            { return equal_list(d, c, mysqlpp::quote, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10); }
    CServerListData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d, const char* c,
            std::vector<bool> *i) const
            { return equal_list(d, c, mysqlpp::quote, i); }
    CServerListData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d, const char* c,
            mysqlpp::sql_cmp_type sc) const
            { return equal_list(d, c, mysqlpp::quote, sc); }

    template <class Manip>
    CServerListData_cus_equal_list<Manip> equal_list(const char* d, const char* c, Manip m, 
                        bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false, bool i7 = false, bool i8 = false, bool i9 = false, bool i10 = false) const;
    template <class Manip>
    CServerListData_cus_equal_list<Manip> equal_list(const char* d, const char* c, Manip m, 
                        CServerListData_enum i1, CServerListData_enum i2 = SERVERLISTDATA_NULL, CServerListData_enum i3 = SERVERLISTDATA_NULL, CServerListData_enum i4 = SERVERLISTDATA_NULL, CServerListData_enum i5 = SERVERLISTDATA_NULL, CServerListData_enum i6 = SERVERLISTDATA_NULL, CServerListData_enum i7 = SERVERLISTDATA_NULL, CServerListData_enum i8 = SERVERLISTDATA_NULL, CServerListData_enum i9 = SERVERLISTDATA_NULL, CServerListData_enum i10 = SERVERLISTDATA_NULL) const;
    template <class Manip>
    CServerListData_cus_equal_list<Manip> equal_list(const char* d, const char* c, Manip m, 
                        std::vector<bool> *i) const;
    template <class Manip>
    CServerListData_cus_equal_list<Manip> equal_list(const char* d, const char* c, Manip m, 
                        mysqlpp::sql_cmp_type sc) const;

    private:
    static const char* table_;
    const char* table_override_;
    };
    MYSQLPP_SSQLS_CONDITIONAL_STATICS(
        const char* CServerListData::names[] = {
                "id" ,
    "section_id" ,
    "name" ,
    "real_name" ,
    "domain_name" ,
    "server_index" ,
    "mask" ,
    "subsection" ,
    "order_time" ,
    "flag" 
        };
        const char* CServerListData::table_ = "cq_server_list";
    )

    template <class Manip>
    CServerListData_cus_value_list<Manip>::CServerListData_cus_value_list
            (const CServerListData* o, const char* d, Manip m, bool i1, bool i2, bool i3, bool i4, bool i5, bool i6, bool i7, bool i8, bool i9, bool i10)
    {
        delim = d;
        manip = m;
        del_vector = true;
        obj = o;
        include = new std::vector<bool>(10, false);
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

    }

    template <class Manip>
    CServerListData_cus_value_list<Manip>::CServerListData_cus_value_list
            (const CServerListData* o, const char* d, Manip m, CServerListData_enum i1, CServerListData_enum i2, CServerListData_enum i3, CServerListData_enum i4, CServerListData_enum i5, CServerListData_enum i6, CServerListData_enum i7, CServerListData_enum i8, CServerListData_enum i9, CServerListData_enum i10)
    {
        delim = d;
        manip = m;
        del_vector = true;
        obj = o;
        include = new std::vector<bool>(10, false);
    (*include)[i1]=true;
    if (i2 == SERVERLISTDATA_NULL) return;
    (*include)[i2]=true;
    if (i3 == SERVERLISTDATA_NULL) return;
    (*include)[i3]=true;
    if (i4 == SERVERLISTDATA_NULL) return;
    (*include)[i4]=true;
    if (i5 == SERVERLISTDATA_NULL) return;
    (*include)[i5]=true;
    if (i6 == SERVERLISTDATA_NULL) return;
    (*include)[i6]=true;
    if (i7 == SERVERLISTDATA_NULL) return;
    (*include)[i7]=true;
    if (i8 == SERVERLISTDATA_NULL) return;
    (*include)[i8]=true;
    if (i9 == SERVERLISTDATA_NULL) return;
    (*include)[i9]=true;
    if (i10 == SERVERLISTDATA_NULL) return;
    (*include)[i10]=true;

    }

    template <class Manip>
    CServerListData_cus_field_list<Manip>::CServerListData_cus_field_list
            (const CServerListData* o, const char* d, Manip m, bool i1, bool i2, bool i3, bool i4, bool i5, bool i6, bool i7, bool i8, bool i9, bool i10)
    {
        delim = d;
        manip = m;
        del_vector = true;
        obj = o;
        include = new std::vector<bool>(10, false);
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

    }

    template <class Manip>
    CServerListData_cus_field_list<Manip>::CServerListData_cus_field_list
            (const CServerListData* o, const char* d, Manip m, CServerListData_enum i1, CServerListData_enum i2, CServerListData_enum i3, CServerListData_enum i4, CServerListData_enum i5, CServerListData_enum i6, CServerListData_enum i7, CServerListData_enum i8, CServerListData_enum i9, CServerListData_enum i10)
    {
        delim = d;
        manip = m;
        del_vector = true;
        obj = o;
        include = new std::vector<bool>(10, false);
    (*include)[i1]=true;
    if (i2 == SERVERLISTDATA_NULL) return;
    (*include)[i2]=true;
    if (i3 == SERVERLISTDATA_NULL) return;
    (*include)[i3]=true;
    if (i4 == SERVERLISTDATA_NULL) return;
    (*include)[i4]=true;
    if (i5 == SERVERLISTDATA_NULL) return;
    (*include)[i5]=true;
    if (i6 == SERVERLISTDATA_NULL) return;
    (*include)[i6]=true;
    if (i7 == SERVERLISTDATA_NULL) return;
    (*include)[i7]=true;
    if (i8 == SERVERLISTDATA_NULL) return;
    (*include)[i8]=true;
    if (i9 == SERVERLISTDATA_NULL) return;
    (*include)[i9]=true;
    if (i10 == SERVERLISTDATA_NULL) return;
    (*include)[i10]=true;

    }

    template <class Manip>
    CServerListData_cus_equal_list<Manip>::CServerListData_cus_equal_list
            (const CServerListData* o, const char* d, const char* c, Manip m, bool i1, bool i2, bool i3, bool i4, bool i5, bool i6, bool i7, bool i8, bool i9, bool i10)
    {
        delim = d;
        comp = c;
        manip = m;
        del_vector = true;
        obj = o;
        include = new std::vector<bool>(10, false);
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

    }

    template <class Manip>
    CServerListData_cus_equal_list<Manip>::CServerListData_cus_equal_list
            (const CServerListData* o, const char* d, const char* c, Manip m, CServerListData_enum i1, CServerListData_enum i2, CServerListData_enum i3, CServerListData_enum i4, CServerListData_enum i5, CServerListData_enum i6, CServerListData_enum i7, CServerListData_enum i8, CServerListData_enum i9, CServerListData_enum i10)
    {
        delim = d;
        comp = c;
        manip = m;
        del_vector = true;
        obj = o;
        include = new std::vector<bool>(10, false);
    (*include)[i1]=true;
    if (i2 == SERVERLISTDATA_NULL) return;
    (*include)[i2]=true;
    if (i3 == SERVERLISTDATA_NULL) return;
    (*include)[i3]=true;
    if (i4 == SERVERLISTDATA_NULL) return;
    (*include)[i4]=true;
    if (i5 == SERVERLISTDATA_NULL) return;
    (*include)[i5]=true;
    if (i6 == SERVERLISTDATA_NULL) return;
    (*include)[i6]=true;
    if (i7 == SERVERLISTDATA_NULL) return;
    (*include)[i7]=true;
    if (i8 == SERVERLISTDATA_NULL) return;
    (*include)[i8]=true;
    if (i9 == SERVERLISTDATA_NULL) return;
    (*include)[i9]=true;
    if (i10 == SERVERLISTDATA_NULL) return;
    (*include)[i10]=true;

    }

    template <class Manip>
    std::ostream& operator <<(std::ostream& s, const CServerListData_value_list<Manip>& obj)
    {
    s << obj.manip << obj.obj->id << obj.delim;
    s << obj.manip << obj.obj->section_id << obj.delim;
    s << obj.manip << obj.obj->name << obj.delim;
    s << obj.manip << obj.obj->real_name << obj.delim;
    s << obj.manip << obj.obj->domain_name << obj.delim;
    s << obj.manip << obj.obj->server_index << obj.delim;
    s << obj.manip << obj.obj->mask << obj.delim;
    s << obj.manip << obj.obj->subsection << obj.delim;
    s << obj.manip << obj.obj->order_time << obj.delim;
    s << obj.manip << obj.obj->flag;
        return s;
    }

    template <class Manip>
    std::ostream& operator <<(std::ostream& s, const CServerListData_field_list<Manip>& obj)
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
    s << obj.manip << '`' << obj.obj->names[9] << '`';
        return s;
    }

    template <class Manip>
    std::ostream& operator <<(std::ostream& s, const CServerListData_equal_list<Manip>& obj)
    {
    s << '`' << obj.obj->names[0] << '`' << obj.comp << obj.manip << obj.obj->id << obj.delim;
    s << '`' << obj.obj->names[1] << '`' << obj.comp << obj.manip << obj.obj->section_id << obj.delim;
    s << '`' << obj.obj->names[2] << '`' << obj.comp << obj.manip << obj.obj->name << obj.delim;
    s << '`' << obj.obj->names[3] << '`' << obj.comp << obj.manip << obj.obj->real_name << obj.delim;
    s << '`' << obj.obj->names[4] << '`' << obj.comp << obj.manip << obj.obj->domain_name << obj.delim;
    s << '`' << obj.obj->names[5] << '`' << obj.comp << obj.manip << obj.obj->server_index << obj.delim;
    s << '`' << obj.obj->names[6] << '`' << obj.comp << obj.manip << obj.obj->mask << obj.delim;
    s << '`' << obj.obj->names[7] << '`' << obj.comp << obj.manip << obj.obj->subsection << obj.delim;
    s << '`' << obj.obj->names[8] << '`' << obj.comp << obj.manip << obj.obj->order_time << obj.delim;
    s << '`' << obj.obj->names[9] << '`' << obj.comp << obj.manip << obj.obj->flag;
        return s;
    }

    template <class Manip>
    std::ostream& operator <<(std::ostream& s, const CServerListData_cus_value_list<Manip>& obj)
    {
        bool before = false;
    s << obj.manip << obj.obj->id << obj.delim;
    s << obj.manip << obj.obj->section_id << obj.delim;
    s << obj.manip << obj.obj->name << obj.delim;
    s << obj.manip << obj.obj->real_name << obj.delim;
    s << obj.manip << obj.obj->domain_name << obj.delim;
    s << obj.manip << obj.obj->server_index << obj.delim;
    s << obj.manip << obj.obj->mask << obj.delim;
    s << obj.manip << obj.obj->subsection << obj.delim;
    s << obj.manip << obj.obj->order_time << obj.delim;
    s << obj.manip << obj.obj->flag_cus
        return s;
    }

    template <class Manip>
    std::ostream& operator <<(std::ostream& s, const CServerListData_cus_field_list<Manip>& obj)
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
     } 

        return s;
    }

    template <class Manip>
    std::ostream& operator <<(std::ostream& s, const CServerListData_cus_equal_list<Manip>& obj)
    {
        bool before = false;
    if ((*obj.include)[0]) { 
      s << '`' << obj.obj->names[0] << '`' << obj.comp         << obj.manip << obj.obj->id;
      before = true; 
     } 
    if ((*obj.include)[1]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[1] << '`' << obj.comp         << obj.manip << obj.obj->section_id;
      before = true; 
     } 
    if ((*obj.include)[2]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[2] << '`' << obj.comp         << obj.manip << obj.obj->name;
      before = true; 
     } 
    if ((*obj.include)[3]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[3] << '`' << obj.comp         << obj.manip << obj.obj->real_name;
      before = true; 
     } 
    if ((*obj.include)[4]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[4] << '`' << obj.comp         << obj.manip << obj.obj->domain_name;
      before = true; 
     } 
    if ((*obj.include)[5]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[5] << '`' << obj.comp         << obj.manip << obj.obj->server_index;
      before = true; 
     } 
    if ((*obj.include)[6]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[6] << '`' << obj.comp         << obj.manip << obj.obj->mask;
      before = true; 
     } 
    if ((*obj.include)[7]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[7] << '`' << obj.comp         << obj.manip << obj.obj->subsection;
      before = true; 
     } 
    if ((*obj.include)[8]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[8] << '`' << obj.comp         << obj.manip << obj.obj->order_time;
      before = true; 
     } 
    if ((*obj.include)[9]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[9] << '`' << obj.comp         << obj.manip << obj.obj->flag;
     } 

        return s;
    }

    template <class Manip>
    inline CServerListData_value_list<Manip> CServerListData::value_list(const char* d, Manip m) const
            { return CServerListData_value_list<Manip> (this, d, m); } 

    template <class Manip>
    inline CServerListData_field_list<Manip> CServerListData::field_list(const char* d, Manip m) const
            { return CServerListData_field_list<Manip> (this, d, m); } 

    template <class Manip>
    inline CServerListData_equal_list<Manip> CServerListData::equal_list(const char* d, const char* c, Manip m) const
            { return CServerListData_equal_list<Manip> (this, d, c, m); } 

    template <class Manip>
    inline CServerListData_cus_value_list<Manip> CServerListData::value_list(const char* d, Manip m,
            bool i1, bool i2, bool i3, bool i4, bool i5, bool i6, bool i7, bool i8, bool i9, bool i10) const
            { return CServerListData_cus_value_list<Manip> (this, d, m, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10); }

    template <class Manip>
    inline CServerListData_cus_field_list<Manip> CServerListData::field_list(const char* d, Manip m,
            bool i1, bool i2, bool i3, bool i4, bool i5, bool i6, bool i7, bool i8, bool i9, bool i10) const
            { return CServerListData_cus_field_list<Manip> (this, d, m, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10); }

    template <class Manip>
    inline CServerListData_cus_equal_list<Manip> CServerListData::equal_list(const char* d, const char* c, Manip m,
            bool i1, bool i2, bool i3, bool i4, bool i5, bool i6, bool i7, bool i8, bool i9, bool i10) const
            { return CServerListData_cus_equal_list<Manip> (this, d, c, m, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10); } 

    template <class Manip>
    inline CServerListData_cus_value_list<Manip> CServerListData::value_list(const char* d, Manip m,
            CServerListData_enum i1, CServerListData_enum i2, CServerListData_enum i3, CServerListData_enum i4, CServerListData_enum i5, CServerListData_enum i6, CServerListData_enum i7, CServerListData_enum i8, CServerListData_enum i9, CServerListData_enum i10) const
            { return CServerListData_cus_value_list<Manip> (this, d, m, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10); } 

    template <class Manip>
    inline CServerListData_cus_field_list<Manip> CServerListData::field_list(const char* d, Manip m,
            CServerListData_enum i1, CServerListData_enum i2, CServerListData_enum i3, CServerListData_enum i4, CServerListData_enum i5, CServerListData_enum i6, CServerListData_enum i7, CServerListData_enum i8, CServerListData_enum i9, CServerListData_enum i10) const
            { return CServerListData_cus_field_list<Manip> (this, d, m, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10); } 

    template <class Manip>
    inline CServerListData_cus_equal_list<Manip> CServerListData::equal_list(const char* d, const char* c, Manip m, 
            CServerListData_enum i1, CServerListData_enum i2, CServerListData_enum i3, CServerListData_enum i4, CServerListData_enum i5, CServerListData_enum i6, CServerListData_enum i7, CServerListData_enum i8, CServerListData_enum i9, CServerListData_enum i10) const
            { return CServerListData_cus_equal_list<Manip> (this, d, c, m, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10); } 

    template <class Manip>
    inline CServerListData_cus_value_list<Manip> CServerListData::value_list(const char* d, Manip m,
            std::vector<bool> *i) const
            { return CServerListData_cus_value_list<Manip> (this, d, m, i); }

    template <class Manip>
    inline CServerListData_cus_field_list<Manip> CServerListData::field_list(const char* d, Manip m,
            std::vector<bool> *i) const
            { return CServerListData_cus_field_list<Manip> (this, d, m, i); }

    template <class Manip>
    inline CServerListData_cus_equal_list<Manip> CServerListData::equal_list(const char* d, const char* c, Manip m,
            std::vector<bool> *i) const
            { return CServerListData_cus_equal_list<Manip> (this, d, c, m, i); }

    template <class Manip>
    inline CServerListData_cus_value_list<Manip> 
    CServerListData::value_list(const char* d, Manip m, mysqlpp::sql_cmp_type /*sc*/) const
            { return value_list(d, m, true, true, true, true, true, true, true, true, true, true); }

    template <class Manip>
    inline CServerListData_cus_field_list<Manip> 
    CServerListData::field_list(const char* d, Manip m, mysqlpp::sql_cmp_type /*sc*/) const
            { return field_list(d, m, true, true, true, true, true, true, true, true, true, true); }

    template <class Manip>
    inline CServerListData_cus_equal_list<Manip> 
    CServerListData::equal_list(const char* d, const char* c, Manip m, mysqlpp::sql_cmp_type /*sc*/) const
            { return equal_list(d, c, m, true, true, true, true, true, true, true, true, true, true); }

    template <mysqlpp::sql_dummy_type dummy>
    void populate_CServerListData(CServerListData *s, const mysqlpp::Row &row)
    {
        mysqlpp::NoExceptions ignore_schema_mismatches(row);
    s->id = row["id"].conv(sql_int_unsigned());
    s->section_id = row["section_id"].conv(sql_int_unsigned());
    s->name = row["name"].conv(sql_varchar());
    s->real_name = row["real_name"].conv(sql_varchar());
    s->domain_name = row["domain_name"].conv(sql_varchar());
    s->server_index = row["server_index"].conv(sql_int_unsigned());
    s->mask = row["mask"].conv(sql_int_unsigned());
    s->subsection = row["subsection"].conv(sql_int_unsigned());
    s->order_time = row["order_time"].conv(sql_int_unsigned());
    s->flag = row["flag"].conv(sql_int_unsigned());
    }

    inline CServerListData::CServerListData(const mysqlpp::Row& row) :
    table_override_(0)
            { populate_CServerListData<mysqlpp::sql_dummy>(this, row); }
    inline void CServerListData::set(const mysqlpp::Row& row)
    {
        table_override_ = 0;
        populate_CServerListData<mysqlpp::sql_dummy>(this, row);
    }

    template <mysqlpp::sql_dummy_type dummy> 
 int sql_compare_CServerListData(const CServerListData &x, const CServerListData &y) { 
     int cmp; \
    cmp = mysqlpp::sql_cmp(x.id, y.id ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.section_id, y.section_id ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.name, y.name ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.real_name, y.real_name ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.domain_name, y.domain_name ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.server_index, y.server_index ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.mask, y.mask ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.subsection, y.subsection ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.order_time, y.order_time ); \
    if (cmp) return cmp; \
    return mysqlpp::sql_cmp(x.flag, y.flag); 
 } 
 template <mysqlpp::sql_dummy_type dummy> 
 int compare (const CServerListData &x, const CServerListData &y) { 
     int cmp; \
    cmp = mysqlpp::sql_cmp(x.id, y.id ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.section_id, y.section_id ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.name, y.name ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.real_name, y.real_name ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.domain_name, y.domain_name ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.server_index, y.server_index ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.mask, y.mask ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.subsection, y.subsection ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.order_time, y.order_time ); \
    if (cmp) return cmp; \
    return mysqlpp::sql_cmp(x.flag, y.flag); 
 }

#endif	//end of define _SERVER_LIST_DATA_H_