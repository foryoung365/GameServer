////////////////////////////////////////////////////////////////////////
// Copyright(c) 1999-2015, All Rights Reserved
// Author: 	Fu Yan
// Created: 	2015-08-17
// Describe: 	Specailized SQL structure of table gs_magic, 
//				generate by genSsqls.py, !!!DO NOT EDIT!!!
////////////////////////////////////////////////////////////////////////
#ifndef _MAGIC_DATA_H_
#define _MAGIC_DATA_H_

#include <mysql++.h>
#include <ssqls.h>

using namespace mysqlpp;

struct CMagicData; 
    
        enum CMagicData_enum { 
        MAGICDATA_ID,
    MAGICDATA_OWNER_ID,
    MAGICDATA_MAGIC_TYPE,
    MAGICDATA_EXP,
        MAGICDATA_NULL 
        }; 
    
        template <class Manip>
        class CMagicData_value_list { 
        public: 
        const CMagicData* obj;
        const char* delim;
        Manip manip;
        public: 
        CMagicData_value_list (const CMagicData* o, const char* d, Manip m) :
        obj(o), delim(d), manip(m) { } 
        };
    
        template <class Manip>
        class CMagicData_field_list {
        public: 
        const CMagicData* obj; 
        const char* delim;
        Manip manip;
        public: 
        CMagicData_field_list (const CMagicData* o, const char* d, Manip m) :
        obj(o), delim(d), manip(m) { } 
        };
    
        template <class Manip>
        class CMagicData_equal_list { 
        public: 
        const CMagicData* obj;
        const char* delim;
        const char* comp;
        Manip manip;
        public: 
        CMagicData_equal_list (const CMagicData* o, const char* d, const char* c, Manip m) :
        obj(o), delim(d), comp(c), manip(m) { }
        };
    
        template <class Manip>
        class CMagicData_cus_value_list {
        public:
        const CMagicData* obj;
        std::vector<bool> *include;
        bool del_vector;
        const char* delim;
        Manip manip;
        public: 
        ~CMagicData_cus_value_list () {if (del_vector) delete include;} 
        CMagicData_cus_value_list (const CMagicData* o, const char* d, Manip m, bool i1, bool i2, bool i3, bool i4);
        CMagicData_cus_value_list (const CMagicData* o, const char* d, Manip m, CMagicData_enum i1, CMagicData_enum i2, CMagicData_enum i3, CMagicData_enum i4); 
        CMagicData_cus_value_list (const CMagicData* o, const char* d, Manip m ,std::vector<bool>* i) :
        obj(o), include(i), del_vector(false), delim(d), manip(m) { }
        };
    
        template <class Manip>
        class CMagicData_cus_field_list { 
        public:
        const CMagicData* obj; 
        std::vector<bool> *include; 
        bool del_vector; 
        const char* delim;
        Manip manip;
        public: 
        ~CMagicData_cus_field_list () {if (del_vector) delete include;} 
        CMagicData_cus_field_list (const CMagicData* o, const char* d, Manip m, bool i1, bool i2, bool i3, bool i4); 
        CMagicData_cus_field_list (const CMagicData* o, const char* d, Manip m, CMagicData_enum i1, CMagicData_enum i2, CMagicData_enum i3, CMagicData_enum i4); 
        CMagicData_cus_field_list (const CMagicData* o, const char* d, Manip m, std::vector<bool> *i) :
        obj(o), include(i), del_vector(false), delim(d), manip(m) { }
        };
    
        template <class Manip>
        class CMagicData_cus_equal_list {
        public:
        const CMagicData* obj;
        std::vector<bool> *include;
        bool del_vector;
        const char* delim;
        const char* comp;
        Manip manip;
        public:
        ~CMagicData_cus_equal_list () {if (del_vector) delete include;}
        CMagicData_cus_equal_list (const CMagicData* o, const char* d, const char* c, Manip m, bool i1, bool i2, bool i3, bool i4); 
        CMagicData_cus_equal_list (const CMagicData* o, const char* d, const char* c, Manip m, CMagicData_enum i1, CMagicData_enum i2, CMagicData_enum i3, CMagicData_enum i4); 
        CMagicData_cus_equal_list (const CMagicData* o, const char* d, const char* c, Manip m, std::vector<bool> *i) :
        obj(o), include(i), del_vector(false), delim(d), comp(c), manip(m) { }
        };
    
        template <mysqlpp::sql_dummy_type dummy> int sql_compare_CMagicData(const CMagicData&, const CMagicData&);
    
        struct CMagicData {
        sql_bigint_unsigned id;
    sql_bigint_unsigned owner_id;
    sql_bigint_unsigned magic_type;
    sql_int_unsigned exp; 
        CMagicData() : table_override_(0) { }
        CMagicData(const mysqlpp::Row& row);
        void set(const mysqlpp::Row &row);
        CMagicData(const sql_bigint_unsigned &p1, const sql_bigint_unsigned &p2, const sql_bigint_unsigned &p3, const sql_int_unsigned &p4) : id (p1), owner_id (p2), magic_type (p3), exp (p4), table_override_(0) {}
void set(const sql_bigint_unsigned &p1, const sql_bigint_unsigned &p2, const sql_bigint_unsigned &p3, const sql_int_unsigned &p4) {
table_override_ = 0;
    id = p1;\
    owner_id = p2;\
    magic_type = p3;\
    exp = p4;\

}
bool operator == (const CMagicData &other) const 
 {return sql_compare_CMagicData<mysqlpp::sql_dummy>(*this,other) == 0;} 
 bool operator != (const CMagicData &other) const 
 {return sql_compare_CMagicData<mysqlpp::sql_dummy>(*this,other) != 0;} 
 bool operator > (const CMagicData &other) const 
 {return sql_compare_CMagicData<mysqlpp::sql_dummy>(*this,other) >  0;} 
 bool operator < (const CMagicData &other) const 
 {return sql_compare_CMagicData<mysqlpp::sql_dummy>(*this,other) <  0;} 
 bool operator >= (const CMagicData &other) const 
 {return sql_compare_CMagicData<mysqlpp::sql_dummy>(*this,other) >= 0;} 
 bool operator <= (const CMagicData &other) const 
 {return sql_compare_CMagicData<mysqlpp::sql_dummy>(*this,other) <= 0;} 
 int cmp (const CMagicData &other) const 
 {return sql_compare_CMagicData<mysqlpp::sql_dummy>(*this,other);} 
 int compare (const CMagicData &other) const 
 {return sql_compare_CMagicData<mysqlpp::sql_dummy>(*this,other);}

        void set(const sql_bigint_unsigned p1) { \
        table_override_ = 0;

        id = p1;


        } \
        CMagicData(const sql_bigint_unsigned p1) : id(p1), table_override_(0) {}
        static const char* names[];
        static void table(const char* t) { table_ = t; }
        const char* table() const
                { return table_override_ ? table_override_ : CMagicData::table_; }
        void instance_table(const char* t) { table_override_ = t; }
    
        CMagicData_value_list<mysqlpp::quote_type0> value_list() const {
            return value_list(",", mysqlpp::quote);}
        CMagicData_value_list<mysqlpp::quote_type0> value_list(const char* d) const {
            return value_list(d, mysqlpp::quote);}
        template <class Manip>
        CMagicData_value_list<Manip> value_list(const char* d, Manip m) const;
    
        CMagicData_field_list<mysqlpp::do_nothing_type0> field_list() const {
            return field_list(",", mysqlpp::do_nothing);}
        CMagicData_field_list<mysqlpp::do_nothing_type0> field_list(const char* d) const {
            return field_list(d, mysqlpp::do_nothing);}
        template <class Manip>
        CMagicData_field_list<Manip> field_list(const char* d, Manip m) const;
    
        CMagicData_equal_list<mysqlpp::quote_type0> equal_list(const char* d = ",",
                const char* c = " = ") const
                { return equal_list(d, c, mysqlpp::quote); }
        template <class Manip>
        CMagicData_equal_list<Manip> equal_list(const char* d, const char* c, Manip m) const;
    
        /* cus_data */
    
        CMagicData_cus_value_list<mysqlpp::quote_type0> value_list(bool i1, bool i2 = false, bool i3 = false, bool i4 = false) const
                { return value_list(",", mysqlpp::quote, i1, i2, i3, i4); }
        CMagicData_cus_value_list<mysqlpp::quote_type0> value_list(CMagicData_enum i1, CMagicData_enum i2 = MAGICDATA_NULL, CMagicData_enum i3 = MAGICDATA_NULL, CMagicData_enum i4 = MAGICDATA_NULL) const
                { return value_list(",", mysqlpp::quote, i1, i2, i3, i4); }
        CMagicData_cus_value_list<mysqlpp::quote_type0> value_list(std::vector<bool> *i) const
                { return value_list(",", mysqlpp::quote, i); }
        CMagicData_cus_value_list<mysqlpp::quote_type0> value_list(mysqlpp::sql_cmp_type sc) const
                { return value_list(",", mysqlpp::quote, sc); }
    
        CMagicData_cus_value_list<mysqlpp::quote_type0> value_list(const char* d, bool i1, bool i2 = false, bool i3 = false, bool i4 = false) const
                { return value_list(d, mysqlpp::quote, i1, i2, i3, i4); }
        CMagicData_cus_value_list<mysqlpp::quote_type0> value_list(const char* d, CMagicData_enum i1, CMagicData_enum i2 = MAGICDATA_NULL, CMagicData_enum i3 = MAGICDATA_NULL, CMagicData_enum i4 = MAGICDATA_NULL) const
                { return value_list(d, mysqlpp::quote, i1, i2, i3, i4); }
        CMagicData_cus_value_list<mysqlpp::quote_type0> value_list(const char* d,
                std::vector<bool> *i) const
                { return value_list(d, mysqlpp::quote, i); }
        CMagicData_cus_value_list<mysqlpp::quote_type0> value_list(const char* d,
                mysqlpp::sql_cmp_type sc) const
                { return value_list(d, mysqlpp::quote, sc); }
    
        template <class Manip>
        CMagicData_cus_value_list<Manip> value_list(const char* d, Manip m,
                bool i1, bool i2 = false, bool i3 = false, bool i4 = false) const;
        template <class Manip>
        CMagicData_cus_value_list<Manip> value_list(const char* d, Manip m,
                CMagicData_enum i1, CMagicData_enum i2 = MAGICDATA_NULL, CMagicData_enum i3 = MAGICDATA_NULL, CMagicData_enum i4 = MAGICDATA_NULL) const;
        template <class Manip>
        CMagicData_cus_value_list<Manip> value_list(const char* d, Manip m,
                std::vector<bool>* i) const;
        template <class Manip>
        CMagicData_cus_value_list<Manip> value_list(const char* d, Manip m, 
                mysqlpp::sql_cmp_type sc) const;
        /* cus field */
    
        CMagicData_cus_field_list<mysqlpp::do_nothing_type0> field_list(bool i1, bool i2 = false, bool i3 = false, bool i4 = false) const 
                { return field_list(",", mysqlpp::do_nothing, i1, i2, i3, i4); }
        CMagicData_cus_field_list<mysqlpp::do_nothing_type0> field_list(CMagicData_enum i1, CMagicData_enum i2 = MAGICDATA_NULL, CMagicData_enum i3 = MAGICDATA_NULL, CMagicData_enum i4 = MAGICDATA_NULL) const
                { return field_list(",", mysqlpp::do_nothing, i1, i2, i3, i4); }
        CMagicData_cus_field_list<mysqlpp::do_nothing_type0> field_list(std::vector<bool> *i) const
                { return field_list(",", mysqlpp::do_nothing, i); }
        CMagicData_cus_field_list<mysqlpp::do_nothing_type0> field_list(mysqlpp::sql_cmp_type sc) const
                { return field_list(",", mysqlpp::do_nothing, sc); }
    
        CMagicData_cus_field_list<mysqlpp::do_nothing_type0> field_list(const char* d,
                bool i1, bool i2 = false, bool i3 = false, bool i4 = false) const
                { return field_list(d, mysqlpp::do_nothing, i1, i2, i3, i4); }
        CMagicData_cus_field_list<mysqlpp::do_nothing_type0> field_list(const char* d,
                CMagicData_enum i1, CMagicData_enum i2 = MAGICDATA_NULL, CMagicData_enum i3 = MAGICDATA_NULL, CMagicData_enum i4 = MAGICDATA_NULL) const
                { return field_list(d, mysqlpp::do_nothing, i1, i2, i3, i4); }
        CMagicData_cus_field_list<mysqlpp::do_nothing_type0> field_list(const char* d,
                std::vector<bool>* i) const
                { return field_list(d, mysqlpp::do_nothing, i); }
        CMagicData_cus_field_list<mysqlpp::do_nothing_type0> field_list(const char* d,
                mysqlpp::sql_cmp_type sc) const
                { return field_list(d, mysqlpp::do_nothing, sc); }
    
        template <class Manip>
        CMagicData_cus_field_list<Manip> field_list(const char* d, Manip m,
                bool i1, bool i2 = false, bool i3 = false, bool i4 = false) const;
        template <class Manip>
        CMagicData_cus_field_list<Manip> field_list(const char* d, Manip m,
                CMagicData_enum i1, CMagicData_enum i2 = MAGICDATA_NULL, CMagicData_enum i3 = MAGICDATA_NULL, CMagicData_enum i4 = MAGICDATA_NULL) const;
        template <class Manip>
        CMagicData_cus_field_list<Manip> field_list(const char* d, Manip m,
                std::vector<bool> *i) const;
        template <class Manip>
        CMagicData_cus_field_list<Manip> field_list(const char* d, Manip m,
                mysqlpp::sql_cmp_type sc) const;
    
        /* cus equal */
    
        CMagicData_cus_equal_list<mysqlpp::quote_type0> equal_list(bool i1, bool i2 = false, bool i3 = false, bool i4 = false) const
                { return equal_list(",", " = ", mysqlpp::quote, i1, i2, i3, i4); }
        CMagicData_cus_equal_list<mysqlpp::quote_type0> equal_list(CMagicData_enum i1, CMagicData_enum i2 = MAGICDATA_NULL, CMagicData_enum i3 = MAGICDATA_NULL, CMagicData_enum i4 = MAGICDATA_NULL) const
                { return equal_list(",", " = ", mysqlpp::quote, i1, i2, i3, i4); }
        CMagicData_cus_equal_list<mysqlpp::quote_type0> equal_list(std::vector<bool>* i) const
                { return equal_list(",", " = ", mysqlpp::quote, i); }
        CMagicData_cus_equal_list<mysqlpp::quote_type0> equal_list(mysqlpp::sql_cmp_type sc) const
                { return equal_list(",", " = ", mysqlpp::quote, sc); }
    
        CMagicData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d, bool i1, bool i2 = false, bool i3 = false, bool i4 = false) const
                { return equal_list(d, " = ", mysqlpp::quote, i1, i2, i3, i4); }
        CMagicData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d, CMagicData_enum i1, CMagicData_enum i2 = MAGICDATA_NULL, CMagicData_enum i3 = MAGICDATA_NULL, CMagicData_enum i4 = MAGICDATA_NULL) const
                { return equal_list(d, " = ", mysqlpp::quote, i1, i2, i3, i4); }
        CMagicData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d,
                std::vector<bool> *i) const
                { return equal_list(d, " = ", mysqlpp::quote, i); }
        CMagicData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d,
                mysqlpp::sql_cmp_type sc) const
                { return equal_list(d, " = ", mysqlpp::quote, sc); }
    
        CMagicData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d, const char* c,
                bool i1, bool i2 = false, bool i3 = false, bool i4 = false) const
                { return equal_list(d, c, mysqlpp::quote, i1, i2, i3, i4); }
        CMagicData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d, const char* c,
                CMagicData_enum i1, CMagicData_enum i2 = MAGICDATA_NULL, CMagicData_enum i3 = MAGICDATA_NULL, CMagicData_enum i4 = MAGICDATA_NULL) const
                { return equal_list(d, c, mysqlpp::quote, i1, i2, i3, i4); }
        CMagicData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d, const char* c,
                std::vector<bool> *i) const
                { return equal_list(d, c, mysqlpp::quote, i); }
        CMagicData_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d, const char* c,
                mysqlpp::sql_cmp_type sc) const
                { return equal_list(d, c, mysqlpp::quote, sc); }
    
        template <class Manip>
        CMagicData_cus_equal_list<Manip> equal_list(const char* d, const char* c, Manip m, 
                            bool i1, bool i2 = false, bool i3 = false, bool i4 = false) const;
        template <class Manip>
        CMagicData_cus_equal_list<Manip> equal_list(const char* d, const char* c, Manip m, 
                            CMagicData_enum i1, CMagicData_enum i2 = MAGICDATA_NULL, CMagicData_enum i3 = MAGICDATA_NULL, CMagicData_enum i4 = MAGICDATA_NULL) const;
        template <class Manip>
        CMagicData_cus_equal_list<Manip> equal_list(const char* d, const char* c, Manip m, 
                            std::vector<bool> *i) const;
        template <class Manip>
        CMagicData_cus_equal_list<Manip> equal_list(const char* d, const char* c, Manip m, 
                            mysqlpp::sql_cmp_type sc) const;
    
        private:
        static const char* table_;
        const char* table_override_;
        };
            
        template <class Manip>
        CMagicData_cus_value_list<Manip>::CMagicData_cus_value_list
                (const CMagicData* o, const char* d, Manip m, bool i1, bool i2, bool i3, bool i4)
        {
            delim = d;
            manip = m;
            del_vector = true;
            obj = o;
            include = new std::vector<bool>(4, false);
        if (i1) (*include)[0]=true;
    if (i2) (*include)[1]=true;
    if (i3) (*include)[2]=true;
    if (i4) (*include)[3]=true;

        }
    
        template <class Manip>
        CMagicData_cus_value_list<Manip>::CMagicData_cus_value_list
                (const CMagicData* o, const char* d, Manip m, CMagicData_enum i1, CMagicData_enum i2, CMagicData_enum i3, CMagicData_enum i4)
        {
            delim = d;
            manip = m;
            del_vector = true;
            obj = o;
            include = new std::vector<bool>(4, false);
        (*include)[i1]=true;
    if (i2 == MAGICDATA_NULL) return;
    (*include)[i2]=true;
    if (i3 == MAGICDATA_NULL) return;
    (*include)[i3]=true;
    if (i4 == MAGICDATA_NULL) return;
    (*include)[i4]=true;

        }
    
        template <class Manip>
        CMagicData_cus_field_list<Manip>::CMagicData_cus_field_list
                (const CMagicData* o, const char* d, Manip m, bool i1, bool i2, bool i3, bool i4)
        {
            delim = d;
            manip = m;
            del_vector = true;
            obj = o;
            include = new std::vector<bool>(4, false);
        if (i1) (*include)[0]=true;
    if (i2) (*include)[1]=true;
    if (i3) (*include)[2]=true;
    if (i4) (*include)[3]=true;

        }
    
        template <class Manip>
        CMagicData_cus_field_list<Manip>::CMagicData_cus_field_list
                (const CMagicData* o, const char* d, Manip m, CMagicData_enum i1, CMagicData_enum i2, CMagicData_enum i3, CMagicData_enum i4)
        {
            delim = d;
            manip = m;
            del_vector = true;
            obj = o;
            include = new std::vector<bool>(4, false);
        (*include)[i1]=true;
    if (i2 == MAGICDATA_NULL) return;
    (*include)[i2]=true;
    if (i3 == MAGICDATA_NULL) return;
    (*include)[i3]=true;
    if (i4 == MAGICDATA_NULL) return;
    (*include)[i4]=true;

        }
    
        template <class Manip>
        CMagicData_cus_equal_list<Manip>::CMagicData_cus_equal_list
                (const CMagicData* o, const char* d, const char* c, Manip m, bool i1, bool i2, bool i3, bool i4)
        {
            delim = d;
            comp = c;
            manip = m;
            del_vector = true;
            obj = o;
            include = new std::vector<bool>(4, false);
        if (i1) (*include)[0]=true;
    if (i2) (*include)[1]=true;
    if (i3) (*include)[2]=true;
    if (i4) (*include)[3]=true;

        }
    
        template <class Manip>
        CMagicData_cus_equal_list<Manip>::CMagicData_cus_equal_list
                (const CMagicData* o, const char* d, const char* c, Manip m, CMagicData_enum i1, CMagicData_enum i2, CMagicData_enum i3, CMagicData_enum i4)
        {
            delim = d;
            comp = c;
            manip = m;
            del_vector = true;
            obj = o;
            include = new std::vector<bool>(4, false);
        (*include)[i1]=true;
    if (i2 == MAGICDATA_NULL) return;
    (*include)[i2]=true;
    if (i3 == MAGICDATA_NULL) return;
    (*include)[i3]=true;
    if (i4 == MAGICDATA_NULL) return;
    (*include)[i4]=true;

        }
    
        template <class Manip>
        std::ostream& operator <<(std::ostream& s, const CMagicData_value_list<Manip>& obj)
        {
        s << obj.manip << obj.obj->id << obj.delim;
    s << obj.manip << obj.obj->owner_id << obj.delim;
    s << obj.manip << obj.obj->magic_type << obj.delim;
    s << obj.manip << obj.obj->exp;
            return s;
        }
    
        template <class Manip>
        std::ostream& operator <<(std::ostream& s, const CMagicData_field_list<Manip>& obj)
        {
        s << obj.manip << '`' << obj.obj->names[0] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[1] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[2] << '`' << obj.delim;
    s << obj.manip << '`' << obj.obj->names[3] << '`';
            return s;
        }
    
        template <class Manip>
        std::ostream& operator <<(std::ostream& s, const CMagicData_equal_list<Manip>& obj)
        {
        s << '`' << obj.obj->names[0] << '`' << obj.comp << obj.manip << obj.obj->id << obj.delim;
    s << '`' << obj.obj->names[1] << '`' << obj.comp << obj.manip << obj.obj->owner_id << obj.delim;
    s << '`' << obj.obj->names[2] << '`' << obj.comp << obj.manip << obj.obj->magic_type << obj.delim;
    s << '`' << obj.obj->names[3] << '`' << obj.comp << obj.manip << obj.obj->exp;
            return s;
        }
    
        template <class Manip>
        std::ostream& operator <<(std::ostream& s, const CMagicData_cus_value_list<Manip>& obj)
        {
            bool before = false;
        if ((*obj.include)[0]) { 
      s << obj.manip << obj.obj->id;
      before = true; 
     } 
    if ((*obj.include)[1]) { 
      if (before) s << obj.delim;
      s << obj.manip << obj.obj->owner_id;
      before = true; 
     } 
    if ((*obj.include)[2]) { 
      if (before) s << obj.delim;
      s << obj.manip << obj.obj->magic_type;
      before = true; 
     } 
    if ((*obj.include)[3]) { 
      if (before) s << obj.delim;
      s << obj.manip << obj.obj->exp;
     } 

            return s;
        }
    
        template <class Manip>
        std::ostream& operator <<(std::ostream& s, const CMagicData_cus_field_list<Manip>& obj)
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
     } 

            return s;
        }
    
        template <class Manip>
        std::ostream& operator <<(std::ostream& s, const CMagicData_cus_equal_list<Manip>& obj)
        {
            bool before = false;
        if ((*obj.include)[0]) { 
      s << '`' << obj.obj->names[0] << '`' << obj.comp         << obj.manip << obj.obj->id;
      before = true; 
     } 
    if ((*obj.include)[1]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[1] << '`' << obj.comp         << obj.manip << obj.obj->owner_id;
      before = true; 
     } 
    if ((*obj.include)[2]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[2] << '`' << obj.comp         << obj.manip << obj.obj->magic_type;
      before = true; 
     } 
    if ((*obj.include)[3]) { 
      if (before) s << obj.delim;
      s << '`' << obj.obj->names[3] << '`' << obj.comp         << obj.manip << obj.obj->exp;
     } 

            return s;
        }
    
        template <class Manip>
        inline CMagicData_value_list<Manip> CMagicData::value_list(const char* d, Manip m) const
                { return CMagicData_value_list<Manip> (this, d, m); } 
    
        template <class Manip>
        inline CMagicData_field_list<Manip> CMagicData::field_list(const char* d, Manip m) const
                { return CMagicData_field_list<Manip> (this, d, m); } 
    
        template <class Manip>
        inline CMagicData_equal_list<Manip> CMagicData::equal_list(const char* d, const char* c, Manip m) const
                { return CMagicData_equal_list<Manip> (this, d, c, m); } 
    
        template <class Manip>
        inline CMagicData_cus_value_list<Manip> CMagicData::value_list(const char* d, Manip m,
                bool i1, bool i2, bool i3, bool i4) const
                { return CMagicData_cus_value_list<Manip> (this, d, m, i1, i2, i3, i4); }
    
        template <class Manip>
        inline CMagicData_cus_field_list<Manip> CMagicData::field_list(const char* d, Manip m,
                bool i1, bool i2, bool i3, bool i4) const
                { return CMagicData_cus_field_list<Manip> (this, d, m, i1, i2, i3, i4); }
    
        template <class Manip>
        inline CMagicData_cus_equal_list<Manip> CMagicData::equal_list(const char* d, const char* c, Manip m,
                bool i1, bool i2, bool i3, bool i4) const
                { return CMagicData_cus_equal_list<Manip> (this, d, c, m, i1, i2, i3, i4); } 
    
        template <class Manip>
        inline CMagicData_cus_value_list<Manip> CMagicData::value_list(const char* d, Manip m,
                CMagicData_enum i1, CMagicData_enum i2, CMagicData_enum i3, CMagicData_enum i4) const
                { return CMagicData_cus_value_list<Manip> (this, d, m, i1, i2, i3, i4); } 
    
        template <class Manip>
        inline CMagicData_cus_field_list<Manip> CMagicData::field_list(const char* d, Manip m,
                CMagicData_enum i1, CMagicData_enum i2, CMagicData_enum i3, CMagicData_enum i4) const
                { return CMagicData_cus_field_list<Manip> (this, d, m, i1, i2, i3, i4); } 
    
        template <class Manip>
        inline CMagicData_cus_equal_list<Manip> CMagicData::equal_list(const char* d, const char* c, Manip m, 
                CMagicData_enum i1, CMagicData_enum i2, CMagicData_enum i3, CMagicData_enum i4) const
                { return CMagicData_cus_equal_list<Manip> (this, d, c, m, i1, i2, i3, i4); } 
    
        template <class Manip>
        inline CMagicData_cus_value_list<Manip> CMagicData::value_list(const char* d, Manip m,
                std::vector<bool> *i) const
                { return CMagicData_cus_value_list<Manip> (this, d, m, i); }
    
        template <class Manip>
        inline CMagicData_cus_field_list<Manip> CMagicData::field_list(const char* d, Manip m,
                std::vector<bool> *i) const
                { return CMagicData_cus_field_list<Manip> (this, d, m, i); }
    
        template <class Manip>
        inline CMagicData_cus_equal_list<Manip> CMagicData::equal_list(const char* d, const char* c, Manip m,
                std::vector<bool> *i) const
                { return CMagicData_cus_equal_list<Manip> (this, d, c, m, i); }
    
        template <class Manip>
        inline CMagicData_cus_value_list<Manip> 
        CMagicData::value_list(const char* d, Manip m, mysqlpp::sql_cmp_type /*sc*/) const
                { return value_list(d, m, true, true, true, true); }
    
        template <class Manip>
        inline CMagicData_cus_field_list<Manip> 
        CMagicData::field_list(const char* d, Manip m, mysqlpp::sql_cmp_type /*sc*/) const
                { return field_list(d, m, true, true, true, true); }
    
        template <class Manip>
        inline CMagicData_cus_equal_list<Manip> 
        CMagicData::equal_list(const char* d, const char* c, Manip m, mysqlpp::sql_cmp_type /*sc*/) const
                { return equal_list(d, c, m, true, true, true, true); }
    
        template <mysqlpp::sql_dummy_type dummy>
        void populate_CMagicData(CMagicData *s, const mysqlpp::Row &row)
        {
            mysqlpp::NoExceptions ignore_schema_mismatches(row);
        s->id = row["id"].conv(sql_bigint_unsigned());
    s->owner_id = row["owner_id"].conv(sql_bigint_unsigned());
    s->magic_type = row["magic_type"].conv(sql_bigint_unsigned());
    s->exp = row["exp"].conv(sql_int_unsigned());
        }
    
        inline CMagicData::CMagicData(const mysqlpp::Row& row) :
        table_override_(0)
                { populate_CMagicData<mysqlpp::sql_dummy>(this, row); }
        inline void CMagicData::set(const mysqlpp::Row& row)
        {
            table_override_ = 0;
            populate_CMagicData<mysqlpp::sql_dummy>(this, row);
        }
    
        template <mysqlpp::sql_dummy_type dummy> 
 int sql_compare_CMagicData(const CMagicData &x, const CMagicData &y) { 
     int cmp; \
    cmp = mysqlpp::sql_cmp(x.id, y.id ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.owner_id, y.owner_id ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.magic_type, y.magic_type ); \
    if (cmp) return cmp; \
    return mysqlpp::sql_cmp(x.exp, y.exp); 
 } 
 template <mysqlpp::sql_dummy_type dummy> 
 int compare (const CMagicData &x, const CMagicData &y) { 
     int cmp; \
    cmp = mysqlpp::sql_cmp(x.id, y.id ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.owner_id, y.owner_id ); \
    if (cmp) return cmp; \
    cmp = mysqlpp::sql_cmp(x.magic_type, y.magic_type ); \
    if (cmp) return cmp; \
    return mysqlpp::sql_cmp(x.exp, y.exp); 
 }

#endif	//end of define _MAGIC_DATA_H_