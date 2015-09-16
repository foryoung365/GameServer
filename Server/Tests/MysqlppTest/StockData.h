////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author: 	Fu Yan
// Created: 	2015-07-07
// Describe: 	Specailized SQL structure of table @tblname, 
//				generate by genSsqls.py, !!!DO NOT EDIT!!!
////////////////////////////////////////////////////////////////////////
#ifndef _STOCK_DATA_H_
#define _STOCK_DATA_H_

#include <mysql++.h>
#include <ssqls.h>

using namespace mysqlpp;

struct CStockData; 

    enum CStockData_enum { 
    STOCKDATA_ITEM,
    STOCKDATA_NUM,
    STOCKDATA_WEIGHT,
    STOCKDATA_PRICE,
    STOCKDATA_SDATE,
    STOCKDATA_DESCRIPTION,
    STOCKDATA_NULL 
    }; 

    template <class Manip>
    class CStockData_value_list { 
    public: 
    const CStockData* obj;
    const char* delim;
    Manip manip;
    public: 
    CStockData_value_list (const CStockData* o, const char* d, Manip m) :
    obj(o), delim(d), manip(m) { } 
    };

    template <class Manip>
    class CStockData_field_list {
    public: 
    const CStockData* obj; 
    const char* delim;
    Manip manip;
    public: 
    CStockData_field_list (const CStockData* o, const char* d, Manip m) :
    obj(o), delim(d), manip(m) { } 
    };

    template <class Manip>
    class CStockData_equal_list { 
    public: 
    const CStockData* obj;
    const char* delim;
    const char* comp;
    Manip manip;
    public: 
    CStockData_equal_list (const CStockData* o, const char* d, const char* c, Manip m) :
    obj(o), delim(d), comp(c), manip(m) { }
    };

    template <class Manip>
    class CStockData_cus_value_list {
    public:
    const CStockData* obj;
    std::vector<bool> *include;
    bool del_vector;
    const char* delim;
    Manip manip;
    public: 
    ~CStockData_cus_value_list () {if (del_vector) delete include;} 
    CStockData_cus_value_list (const CStockData* o, const char* d, Manip m, bool i1, bool i2, bool i3, bool i4, bool i5, bool i6);
    CStockData_cus_value_list (const CStockData* o, const char* d, Manip m, CStockData_enum i1, CStockData_enum i2, CStockData_enum i3, CStockData_enum i4, CStockData_enum i5, CStockData_enum i6); 
    CStockData_cus_value_list (const CStockData* o, const char* d, Manip m ,std::vector<bool>* i) :
    obj(o), include(i), del_vector(false), delim(d), manip(m) { }
    };

    template <class Manip>
    class CStockData_cus_field_list { 
    public:
    const CStockData* obj; 
    std::vector<bool> *include; 
    bool del_vector; 
    const char* delim;
    Manip manip;
    public: 
    ~CStockData_cus_field_list () {if (del_vector) delete include;} 
    CStockData_cus_field_list (const CStockData* o, const char* d, Manip m, bool i1, bool i2, bool i3, bool i4, bool i5, bool i6); 
    CStockData_cus_field_list (const CStockData* o, const char* d, Manip m, CStockData_enum i1, CStockData_enum i2, CStockData_enum i3, CStockData_enum i4, CStockData_enum i5, CStockData_enum i6); 
    CStockData_cus_field_list (const CStockData* o, const char* d, Manip m, std::vector<bool> *i) :
    obj(o), include(i), del_vector(false), delim(d), manip(m) { }
    };

    template <class Manip>
    class CStockData_cus_equal_list {
    public:
    const CStockData* obj;
    std::vector<bool> *include;
    bool del_vector;
    const char* delim;
    const char* comp;
    Manip manip;
    public:
    ~CStockData_cus_equal_list () {if (del_vector) delete include;}
    CStockData_cus_equal_list (const CStockData* o, const char* d, const char* c, Manip m, bool i1, bool i2, bool i3, bool i4, bool i5, bool i6); 
    CStockData_cus_equal_list (const CStockData* o, const char* d, const char* c, Manip m, CStockData_enum i1, CStockData_enum i2, CStockData_enum i3, CStockData_enum i4, CStockData_enum i5, CStockData_enum i6); 
    CStockData_cus_equal_list (const CStockData* o, const char* d, const char* c, Manip m, std::vector<bool> *i) :
    obj(o), include(i), del_vector(false), delim(d), comp(c), manip(m) { }
    };

    template <mysqlpp::sql_dummy_type dummy> int sql_compare_CStockData(const CStockData&, const CStockData&);

    struct CStockData {
    sql_char item;
    sql_bigint num;
    sql_double weight;
    sql_decimal_null price;
    sql_date sdate;
    sql_mediumtext_null description; 
    CStockData() : table_override_(0) { }
    CStockData(const mysqlpp::Row& row);
    void set(const mysqlpp::Row &row);
    CStockData(const sql_char &p1, const sql_bigint &p2, const sql_double &p3, const sql_decimal_null &p4, const sql_date &p5, const sql_mediumtext_null &p6) : item (p1), num (p2), weight (p3), price (p4), sdate (p5), description (p6), table_override_(0) {}
void set(const sql_char &p1, const sql_bigint &p2, const sql_double &p3, const sql_decimal_null &p4, const sql_date &p5, const sql_mediumtext_null &p6) {
table_override_ = 0;
    item = p1;\
    num = p2;\
    weight = p3;\
    price = p4;\
    sdate = p5;\
    description = p6;\

}
bool operator == (const CStockData &other) const 
 {return sql_compare_CStockData<mysqlpp::sql_dummy>(*this,other) == 0;} 
 bool operator != (const CStockData &other) const 
 {return sql_compare_CStockData<mysqlpp::sql_dummy>(*this,other) != 0;} 
 bool operator > (const CStockData &other) const 
 {return sql_compare_CStockData<mysqlpp::sql_dummy>(*this,other) >  0;} 
 bool operator < (const CStockData &other) const 
 {return sql_compare_CStockData<mysqlpp::sql_dummy>(*this,other) <  0;} 
 bool operator >= (const CStockData &other) const 
 {return sql_compare_CStockData<mysqlpp::sql_dummy>(*this,other) >= 0;} 
 bool operator <= (const CStockData &other) const 
 {return sql_compare_CStockData<mysqlpp::sql_dummy>(*this,other) <= 0;} 
 int cmp (const CStockData &other) const 
 {return sql_compare_CStockData<mysqlpp::sql_dummy>(*this,other);} 
 int compare (const CStockData &other) const 
 {return sql_compare_CStockData<mysqlpp::sql_dummy>(*this,other);}

    void set(const sql_char p1) { \
    table_override_ = 0;

    item = p1;


    } \
    CStockData(const sql_char p1) : item(p1), table_override_(0) {}
    static const char* names[];
    static void table(const char* t) { table_ = t; }
    const char* table() const
            { return table_override_ ? table_override_ : CStockData::table_; }
    void instance_table(const char* t) { table_override_ = t; }

    CStockData_value_list<mysqlpp::quote_type0> value_list() const {
        return value_list(",", mysqlpp::quote);}
    CStockData_value_list<mysqlpp::quote_type0> value_list(const char* d) const {
        return value_list(d, mysqlpp::quote);}
    template <class Manip>
    CStockData_value_list<Manip> value_list(const char* d, Manip m) const;

    CStockData_field_list<mysqlpp::do_nothing_type0> field_list() const {
        return field_list(",", mysqlpp::do_nothing);}
    CStockData_field_list<mysqlpp::do_nothing_type0> field_list(const char* d) const {
        return field_list(d, mysqlpp::do_nothing);}
    template <class Manip>
    CStockData_field_list<Manip> field_list(const char* d, Manip m) const;

    CStockData_equal_list<mysqlpp::quote_type0> equal_list(const char* d = ",",
            const char* c = " = ") const
            { return equal_list(d, c, mysqlpp::quote); }
    template <class Manip>
    CStockData_equal_list<Manip> equal_list(const char* d, const char* c, Manip m) const;

    /* cus_data */

    CStockData_cus_value_list<mysqlpp::quote_type0> value_list(bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false) const
            { return value_list(",", mysqlpp::quote, i1, i2, i3, i4, i5, i6); }
    CStockData_cus_value_list<mysqlpp::quote_type0> value_list(CStockData_enum i1, CStockData_enum i2 = STOCKDATA_NULL, CStockData_enum i3 = STOCKDATA_NULL, CStockData_enum i4 = STOCKDATA_NULL, CStockData_enum i5 = STOCKDATA_NULL, CStockData_enum i6 = STOCKDATA_NULL) const
            { return value_list(",", mysqlpp::quote, i1, i2, i3, i4, i5, i6); }
    CStockData_cus_value_list<mysqlpp::quote_type0> value_list(std::vector<bool> *i) const
            { return value_list(",", mysqlpp::quote, i); }
    CStockData_cus_value_list<mysqlpp::quote_type0> value_list(mysqlpp::sql_cmp_type sc) const
            { return value_list(",", mysqlpp::quote, sc); }

    CStockData_cus_value_list<mysqlpp::quote_type0> value_list(const char* d, bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false) const
            { return value_list(d, mysqlpp::quote, i1, i2, i3, i4, i5, i6); }
    CStockData_cus_value_list<mysqlpp::quote_type0> value_list(const char* d, CStockData_enum i1, CStockData_enum i2 = STOCKDATA_NULL, CStockData_enum i3 = STOCKDATA_NULL, CStockData_enum i4 = STOCKDATA_NULL, CStockData_enum i5 = STOCKDATA_NULL, CStockData_enum i6 = STOCKDATA_NULL) const
            { return value_list(d, mysqlpp::quote, i1, i2, i3, i4, i5, i6); }
    CStockData_cus_value_list<mysqlpp::quote_type0> value_list(const char* d,
            std::vector<bool> *i) const
            { return value_list(d, mysqlpp::quote, i); }
    CStockData_cus_value_list<mysqlpp::quote_type0> value_list(const char* d,
            mysqlpp::sql_cmp_type sc) const
            { return value_list(d, mysqlpp::quote, sc); }

    template <class Manip>
    CStockData_cus_value_list<Manip> value_list(const char* d, Manip m,
            bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false) const;
    template <class Manip>
    CStockData_cus_value_list<Manip> value_list(const char* d, Manip m,
            CStockData_enum i1, CStockData_enum i2 = STOCKDATA_NULL, CStockData_enum i3 = STOCKDATA_NULL, CStockData_enum i4 = STOCKDATA_NULL, CStockData_enum i5 = STOCKDATA_NULL, CStockData_enum i6 = STOCKDATA_NULL) const;
    template <class Manip>
    CStockData_cus_value_list<Manip> value_list(const char* d, Manip m,
            std::vector<bool>* i) const;
    template <class Manip>
    CStockData_cus_value_list<Manip> value_list(const char* d, Manip m, 
            mysqlpp::sql_cmp_type sc) const;
    /* cus field */

    CStockData_cus_field_list<mysqlpp::do_nothing_type0> field_list(bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false) const 
            { return field_list(",", mysqlpp::do_nothing, i1, i2, i3, i4, i5, i6); }
    CStockData_cus_field_list<mysqlpp::do_nothing_type0> field_list(CStockData_enum i1, CStockData_enum i2 = STOCKDATA_NULL, CStockData_enum i3 = STOCKDATA_NULL, CStockData_enum i4 = STOCKDATA_NULL, CStockData_enum i5 = STOCKDATA_NULL, CStockData_enum i6 = STOCKDATA_NULL) const
            { return field_list(",", mysqlpp::do_nothing, i1, i2, i3, i4, i5, i6); }
    CStockData_cus_field_list<mysqlpp::do_nothing_type0> field_list(std::vector<bool> *i) const
            { return field_list(",", mysqlpp::do_nothing, i); }
    CStockData_cus_field_list<mysqlpp::do_nothing_type0> field_list(mysqlpp::sql_cmp_type sc) const
            { return field_list(",", mysqlpp::do_nothing, sc); }

    CStockData_cus_field_list<mysqlpp::do_nothing_type0> field_list(const char* d,
            bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false) const
            { return field_list(d, mysqlpp::do_nothing, i1, i2, i3, i4, i5, i6); }
    CStockData_cus_field_list<mysqlpp::do_nothing_type0> field_list(const char* d,
            CStockData_enum i1, CStockData_enum i2 = STOCKDATA_NULL, CStockData_enum i3 = STOCKDATA_NULL, CStockData_enum i4 = STOCKDATA_NULL, CStockData_enum i5 = STOCKDATA_NULL, CStockData_enum i6 = STOCKDATA_NULL) const
            { return field_list(d, mysqlpp::do_nothing, i1, i2, i3, i4, i5, i6); }
    CStockData_cus_field_list<mysqlpp::do_nothing_type0> field_list(const char* d,
            std::vector<bool>* i) const
            { return field_list(d, mysqlpp::do_nothing, i); }
    CStockData_cus_field_list<mysqlpp::do_nothing_type0> field_list(const char* d,
            mysqlpp::sql_cmp_type sc) const
            { return field_list(d, mysqlpp::do_nothing, sc); }

    template <class Manip>
    CStockData_cus_field_list<Manip> field_list(const char* d, Manip m,
            bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false) const;
    template <class Manip>
    CStockData_cus_field_list<Manip> field_list(const char* d, Manip m,
            CStockData_enum i1, CStockData_enum i2 = STOCKDATA_NULL, CStockData_enum i3 = STOCKDATA_NULL, CStockData_enum i4 = STOCKDATA_NULL, CStockData_enum i5 = STOCKDATA_NULL, CStockData_enum i6 = STOCKDATA_NULL) const;
    template <class Manip>
    CStockData_cus_field_list<Manip> field_list(const char* d, Manip m,
            std::vector<bool> *i) const;
    template <class Manip>
    CStockData_cus_field_list<Manip> field_list(const char* d, Manip m,
            mysqlpp::sql_cmp_type sc) const;

    /* cus equal */

    CStockData_cus_equal_list<mysqlpp::quote_type0> equal_list(bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false) const
            { return equal_list(",", " = ", mysqlpp::quote, i1, i2, i3, i4, i5, i6); }
    CStockData_cus_equal_list<mysqlpp::quote_type0> equal_list(CStockData_enum i1, CStockData_enum i2 = STOCKDATA_NULL, CStockData_enum i3 = STOCKDATA_NULL, CStockData_enum i4 = STOCKDATA_NULL, CStockData_enum i5 = STOCKDATA_NULL, CStockData_enum i6 = STOCKDATA_NULL) const
            { return equal_list(",", " = ", mysqlpp::quote, i1, i2, i3, i4, i5, i6); }
    CStockData_cus_equal_list<mysqlpp::quote_type0> equal_list(std::vector<bool>* i) const
            { return equal_list(",", " = ", mysqlpp::quote, i); }
    CStockData_cus_equal_list<mysqlpp::quote_type0> equal_list(mysqlpp::sql_cmp_type sc) const
            { return equal_list(",", " = ", mysqlpp::quote, sc); }

    CStockData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d, bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false) const
            { return equal_list(d, " = ", mysqlpp::quote, i1, i2, i3, i4, i5, i6); }
    CStockData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d, CStockData_enum i1, CStockData_enum i2 = STOCKDATA_NULL, CStockData_enum i3 = STOCKDATA_NULL, CStockData_enum i4 = STOCKDATA_NULL, CStockData_enum i5 = STOCKDATA_NULL, CStockData_enum i6 = STOCKDATA_NULL) const
            { return equal_list(d, " = ", mysqlpp::quote, i1, i2, i3, i4, i5, i6); }
    CStockData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d,
            std::vector<bool> *i) const
            { return equal_list(d, " = ", mysqlpp::quote, i); }
    CStockData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d,
            mysqlpp::sql_cmp_type sc) const
            { return equal_list(d, " = ", mysqlpp::quote, sc); }

    CStockData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d, const char* c,
            bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false) const
            { return equal_list(d, c, mysqlpp::quote, i1, i2, i3, i4, i5, i6); }
    CStockData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d, const char* c,
            CStockData_enum i1, CStockData_enum i2 = STOCKDATA_NULL, CStockData_enum i3 = STOCKDATA_NULL, CStockData_enum i4 = STOCKDATA_NULL, CStockData_enum i5 = STOCKDATA_NULL, CStockData_enum i6 = STOCKDATA_NULL) const
            { return equal_list(d, c, mysqlpp::quote, i1, i2, i3, i4, i5, i6); }
    CStockData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d, const char* c,
            std::vector<bool> *i) const
            { return equal_list(d, c, mysqlpp::quote, i); }
    CStockData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d, const char* c,
            mysqlpp::sql_cmp_type sc) const
            { return equal_list(d, c, mysqlpp::quote, sc); }

    template <class Manip>
    CStockData_cus_equal_list<Manip> equal_list(const char* d, const char* c, Manip m, 
                        bool i1, bool i2 = false, bool i3 = false, bool i4 = false, bool i5 = false, bool i6 = false) const;
    template <class Manip>
    CStockData_cus_equal_list<Manip> equal_list(const char* d, const char* c, Manip m, 
                        CStockData_enum i1, CStockData_enum i2 = STOCKDATA_NULL, CStockData_enum i3 = STOCKDATA_NULL, CStockData_enum i4 = STOCKDATA_NULL, CStockData_enum i5 = STOCKDATA_NULL, CStockData_enum i6 = STOCKDATA_NULL) const;
    template <class Manip>
    CStockData_cus_equal_list<Manip> equal_list(const char* d, const char* c, Manip m, 
                        std::vector<bool> *i) const;
    template <class Manip>
    CStockData_cus_equal_list<Manip> equal_list(const char* d, const char* c, Manip m, 
                        mysqlpp::sql_cmp_type sc) const;

    private:
    static const char* table_;
    const char* table_override_;
    };
    MYSQLPP_SSQLS_CONDITIONAL_STATICS(
        const char* CStockData::names[] = {
                "item" ,
    "num" ,
    "weight" ,
    "price" ,
    "sdate" ,
    "description" 
        };
        const char* CStockData::table_ = "stock";
    )

    template <class Manip>
    CStockData_cus_value_list<Manip>::CStockData_cus_value_list
            (const CStockData* o, const char* d, Manip m, bool i1, bool i2, bool i3, bool i4, bool i5, bool i6)
    {
        delim = d;
        manip = m;
        del_vector = true;
        obj = o;
        include = new std::vector<bool>(6, false);
    if (i1) (*include)[0]=true;
    if (i2) (*include)[1]=true;
    if (i3) (*include)[2]=true;
    if (i4) (*include)[3]=true;
    if (i5) (*include)[4]=true;
    if (i6) (*include)[5]=true;

    }

    template <class Manip>
    CStockData_cus_value_list<Manip>::CStockData_cus_value_list
            (const CStockData* o, const char* d, Manip m, CStockData_enum i1, CStockData_enum i2, CStockData_enum i3, CStockData_enum i4, CStockData_enum i5, CStockData_enum i6)
    {
        delim = d;
        manip = m;
        del_vector = true;
        obj = o;
        include = new std::vector<bool>(6, false);
    (*include)[i1]=true;
    if (i2 == STOCKDATA_NULL) return;
    (*include)[i2]=true;
    if (i3 == STOCKDATA_NULL) return;
    (*include)[i3]=true;
    if (i4 == STOCKDATA_NULL) return;
    (*include)[i4]=true;
    if (i5 == STOCKDATA_NULL) return;
    (*include)[i5]=true;
    if (i6 == STOCKDATA_NULL) return;
    (*include)[i6]=true;

    }

    template <class Manip>
    CStockData_cus_field_list<Manip>::CStockData_cus_field_list
            (const CStockData* o, const char* d, Manip m, bool i1, bool i2, bool i3, bool i4, bool i5, bool i6)
    {
        delim = d;
        manip = m;
        del_vector = true;
        obj = o;
        include = new std::vector<bool>(6, false);
    if (i1) (*include)[0]=true;
    if (i2) (*include)[1]=true;
    if (i3) (*include)[2]=true;
    if (i4) (*include)[3]=true;
    if (i5) (*include)[4]=true;
    if (i6) (*include)[5]=true;

    }

    template <class Manip>
    CStockData_cus_field_list<Manip>::CStockData_cus_field_list
            (const CStockData* o, const char* d, Manip m, CStockData_enum i1, CStockData_enum i2, CStockData_enum i3, CStockData_enum i4, CStockData_enum i5, CStockData_enum i6)
    {
        delim = d;
        manip = m;
        del_vector = true;
        obj = o;
        include = new std::vector<bool>(6, false);
    (*include)[i1]=true;
    if (i2 == STOCKDATA_NULL) return;
    (*include)[i2]=true;
    if (i3 == STOCKDATA_NULL) return;
    (*include)[i3]=true;
    if (i4 == STOCKDATA_NULL) return;
    (*include)[i4]=true;
    if (i5 == STOCKDATA_NULL) return;
    (*include)[i5]=true;
    if (i6 == STOCKDATA_NULL) return;
    (*include)[i6]=true;

    }

    template <class Manip>
    CStockData_cus_equal_list<Manip>::CStockData_cus_equal_list
            (const CStockData* o, const char* d, const char* c, Manip m, bool i1, bool i2, bool i3, bool i4, bool i5, bool i6)
    {
        delim = d;
        comp = c;
        manip = m;
        del_vector = true;
        obj = o;
        include = new std::vector<bool>(6, false);
    if (i1) (*include)[0]=true;
    if (i2) (*include)[1]=true;
    if (i3) (*include)[2]=true;
    if (i4) (*include)[3]=true;
    if (i5) (*include)[4]=true;
    if (i6) (*include)[5]=true;

    }

    template <class Manip>
    CStockData_cus_equal_list<Manip>::CStockData_cus_equal_list
            (const CStockData* o, const char* d, const char* c, Manip m, CStockData_enum i1, CStockData_enum i2, CStockData_enum i3, CStockData_enum i4, CStockData_enum i5, CStockData_enum i6)
    {
        delim = d;
        comp = c;
        manip = m;
        del_vector = true;
        obj = o;
        include = new std::vector<bool>(6, false);
    (*include)[i1]=true;
    if (i2 == STOCKDATA_NULL) return;
    (*include)[i2]=true;
    if (i3 == STOCKDATA_NULL) return;
    (*include)[i3]=true;
    if (i4 == STOCKDATA_NULL) return;
    (*include)[i4]=true;
    if (i5 == STOCKDATA_NULL) return;
    (*include)[i5]=true;
    if (i6 == STOCKDATA_NULL) return;
    (*include)[i6]=true;

    }

    template <class Manip>
    std::ostream& operator <<(std::ostream& s, const CStockData_value_list<Manip>& obj)
    {
    s << obj.manip << obj.obj->item << obj.delim;
    s << obj.manip << obj.obj->num << obj.delim;
    s << obj.manip << obj.obj->weight << obj.delim;
    s << obj.manip << obj.obj->price << obj.delim;
    s << obj.manip << obj.obj->sdate << obj.delim;
    s << obj.manip << obj.obj->description;
        return s;
    }

    template <class Manip>
    std::ostream& operator <<(std::ostream& s, const CStockData_field_list<Manip>& obj)
    {
    s << obj.manip << '`' << obj.obj->names[0] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[1] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[2] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[3] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[4] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[5] << '`';
        return s;
    }

    template <class Manip>
    std::ostream& operator <<(std::ostream& s, const CStockData_equal_list<Manip>& obj)
    {
    s << '`' << obj.obj->names[0] << '`' << obj.comp << obj.manip << obj.obj->item << obj.delim;
    s << '`' << obj.obj->names[1] << '`' << obj.comp << obj.manip << obj.obj->num << obj.delim;
    s << '`' << obj.obj->names[2] << '`' << obj.comp << obj.manip << obj.obj->weight << obj.delim;
    s << '`' << obj.obj->names[3] << '`' << obj.comp << obj.manip << obj.obj->price << obj.delim;
    s << '`' << obj.obj->names[4] << '`' << obj.comp << obj.manip << obj.obj->sdate << obj.delim;
    s << '`' << obj.obj->names[5] << '`' << obj.comp << obj.manip << obj.obj->description;
        return s;
    }

    template <class Manip>
    std::ostream& operator <<(std::ostream& s, const CStockData_cus_value_list<Manip>& obj)
    {
        bool before = false;
    s << obj.manip << obj.obj->item << obj.delim;
    s << obj.manip << obj.obj->num << obj.delim;
    s << obj.manip << obj.obj->weight << obj.delim;
    s << obj.manip << obj.obj->price << obj.delim;
    s << obj.manip << obj.obj->sdate << obj.delim;
    s << obj.manip << obj.obj->description_cus
        return s;
    }

    template <class Manip>
    std::ostream& operator <<(std::ostream& s, const CStockData_cus_field_list<Manip>& obj)
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
     } 

        return s;
    }

    template <class Manip>
    std::ostream& operator <<(std::ostream& s, const CStockData_cus_equal_list<Manip>& obj)
    {
        bool before = false;
    if ((*obj.include)[0]) { 
      s << '`' << obj.obj->names[0] << '`' << obj.comp         << obj.manip << obj.obj->item;
      before = true; 
     } 
    if ((*obj.include)[1]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[1] << '`' << obj.comp         << obj.manip << obj.obj->num;
      before = true; 
     } 
    if ((*obj.include)[2]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[2] << '`' << obj.comp         << obj.manip << obj.obj->weight;
      before = true; 
     } 
    if ((*obj.include)[3]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[3] << '`' << obj.comp         << obj.manip << obj.obj->price;
      before = true; 
     } 
    if ((*obj.include)[4]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[4] << '`' << obj.comp         << obj.manip << obj.obj->sdate;
      before = true; 
     } 
    if ((*obj.include)[5]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[5] << '`' << obj.comp         << obj.manip << obj.obj->description;
     } 

        return s;
    }

    template <class Manip>
    inline CStockData_value_list<Manip> CStockData::value_list(const char* d, Manip m) const
            { return CStockData_value_list<Manip> (this, d, m); } 

    template <class Manip>
    inline CStockData_field_list<Manip> CStockData::field_list(const char* d, Manip m) const
            { return CStockData_field_list<Manip> (this, d, m); } 

    template <class Manip>
    inline CStockData_equal_list<Manip> CStockData::equal_list(const char* d, const char* c, Manip m) const
            { return CStockData_equal_list<Manip> (this, d, c, m); } 

    template <class Manip>
    inline CStockData_cus_value_list<Manip> CStockData::value_list(const char* d, Manip m,
            bool i1, bool i2, bool i3, bool i4, bool i5, bool i6) const
            { return CStockData_cus_value_list<Manip> (this, d, m, i1, i2, i3, i4, i5, i6); }

    template <class Manip>
    inline CStockData_cus_field_list<Manip> CStockData::field_list(const char* d, Manip m,
            bool i1, bool i2, bool i3, bool i4, bool i5, bool i6) const
            { return CStockData_cus_field_list<Manip> (this, d, m, i1, i2, i3, i4, i5, i6); }

    template <class Manip>
    inline CStockData_cus_equal_list<Manip> CStockData::equal_list(const char* d, const char* c, Manip m,
            bool i1, bool i2, bool i3, bool i4, bool i5, bool i6) const
            { return CStockData_cus_equal_list<Manip> (this, d, c, m, i1, i2, i3, i4, i5, i6); } 

    template <class Manip>
    inline CStockData_cus_value_list<Manip> CStockData::value_list(const char* d, Manip m,
            CStockData_enum i1, CStockData_enum i2, CStockData_enum i3, CStockData_enum i4, CStockData_enum i5, CStockData_enum i6) const
            { return CStockData_cus_value_list<Manip> (this, d, m, i1, i2, i3, i4, i5, i6); } 

    template <class Manip>
    inline CStockData_cus_field_list<Manip> CStockData::field_list(const char* d, Manip m,
            CStockData_enum i1, CStockData_enum i2, CStockData_enum i3, CStockData_enum i4, CStockData_enum i5, CStockData_enum i6) const
            { return CStockData_cus_field_list<Manip> (this, d, m, i1, i2, i3, i4, i5, i6); } 

    template <class Manip>
    inline CStockData_cus_equal_list<Manip> CStockData::equal_list(const char* d, const char* c, Manip m, 
            CStockData_enum i1, CStockData_enum i2, CStockData_enum i3, CStockData_enum i4, CStockData_enum i5, CStockData_enum i6) const
            { return CStockData_cus_equal_list<Manip> (this, d, c, m, i1, i2, i3, i4, i5, i6); } 

    template <class Manip>
    inline CStockData_cus_value_list<Manip> CStockData::value_list(const char* d, Manip m,
            std::vector<bool> *i) const
            { return CStockData_cus_value_list<Manip> (this, d, m, i); }

    template <class Manip>
    inline CStockData_cus_field_list<Manip> CStockData::field_list(const char* d, Manip m,
            std::vector<bool> *i) const
            { return CStockData_cus_field_list<Manip> (this, d, m, i); }

    template <class Manip>
    inline CStockData_cus_equal_list<Manip> CStockData::equal_list(const char* d, const char* c, Manip m,
            std::vector<bool> *i) const
            { return CStockData_cus_equal_list<Manip> (this, d, c, m, i); }

    template <class Manip>
    inline CStockData_cus_value_list<Manip> 
    CStockData::value_list(const char* d, Manip m, mysqlpp::sql_cmp_type /*sc*/) const
            { return value_list(d, m, true, true, true, true, true, true); }

    template <class Manip>
    inline CStockData_cus_field_list<Manip> 
    CStockData::field_list(const char* d, Manip m, mysqlpp::sql_cmp_type /*sc*/) const
            { return field_list(d, m, true, true, true, true, true, true); }

    template <class Manip>
    inline CStockData_cus_equal_list<Manip> 
    CStockData::equal_list(const char* d, const char* c, Manip m, mysqlpp::sql_cmp_type /*sc*/) const
            { return equal_list(d, c, m, true, true, true, true, true, true); }

    template <mysqlpp::sql_dummy_type dummy>
    void populate_CStockData(CStockData *s, const mysqlpp::Row &row)
    {
        mysqlpp::NoExceptions ignore_schema_mismatches(row);
    s->item = row["item"].conv(sql_char());
    s->num = row["num"].conv(sql_bigint());
    s->weight = row["weight"].conv(sql_double());
    s->price = row["price"].conv(sql_decimal_null());
    s->sdate = row["sdate"].conv(sql_date());
    s->description = row["description"].conv(sql_mediumtext_null());
    }

    inline CStockData::CStockData(const mysqlpp::Row& row) :
    table_override_(0)
            { populate_CStockData<mysqlpp::sql_dummy>(this, row); }
    inline void CStockData::set(const mysqlpp::Row& row)
    {
        table_override_ = 0;
        populate_CStockData<mysqlpp::sql_dummy>(this, row);
    }

    template <mysqlpp::sql_dummy_type dummy> 
 int sql_compare_CStockData(const CStockData &x, const CStockData &y) { 
     int cmp; \
    cmp = mysqlpp::sql_cmp(x.item, y.item ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.num, y.num ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.weight, y.weight ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.price, y.price ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.sdate, y.sdate ); \
    if (cmp) return cmp; \
    return mysqlpp::sql_cmp(x.description, y.description); 
 } 
 template <mysqlpp::sql_dummy_type dummy> 
 int compare (const CStockData &x, const CStockData &y) { 
     int cmp; \
    cmp = mysqlpp::sql_cmp(x.item, y.item ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.num, y.num ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.weight, y.weight ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.price, y.price ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.sdate, y.sdate ); \
    if (cmp) return cmp; \
    return mysqlpp::sql_cmp(x.description, y.description); 
 }

#endif	//end of define _STOCK_DATA_H_