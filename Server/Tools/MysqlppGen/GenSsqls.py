# Generate Specialized SQL struct for mysql++ by @foryoung365
# foryoung365.github.io
import MySQLdb;
import ConfigParser;
import sys;
import re;
import datetime;
import os;

types = ["tinyint",
"tinyint_unsigned",
"smallint",
"smallint_unsigned",
"int",
"int_unsigned",
"mediumint",
"mediumint_unsigned",
"bigint",
"bigint_unsigned",
"float",
"double",
"decimal",
"enum",
"char",
"varchar",
"tinytext",
"text",
"mediumtext",
"longtext",
"bool",
"boolean",
"character_varying",
"fixed",
"float4",
"float8",
"int1",
"int2",
"int3",
"int4",
"int8",
"long_varchar",
"long",
"middleint",
"numeric",
"blob",
"tinyblob",
"mediumblob",
"longblob",
"long_varbinary",
"date",
"time",
"timestamp",
"datetime",
"set"];

def MakeMysqlppType(typename, unsigned, nullable):
    typename = "sql_" + typename;
    if unsigned == True:
        typename += "_unsigned";
    if nullable == True:
        typename += "_null";
    return typename;

def IsUnsigned(typename):
    if typename.find("unsigned") == -1:
        return False;
    return True;

def IsNullable(nullable):
    if nullable.upper().find("YES") == -1:
        return False;
    return True;

def IsPrimaryKey(key):
    if key.upper().find("PRI") == -1:
        return False;
    return True;

def LogExit(log):
    print(log+"\n");
    input("Press Enter to exit...");
    sys.exit(-1);
    
#load config file
parser = ConfigParser.ConfigParser();
if len(parser.read("config.ini")) == 0:
    LogExit("Error:Load config.ini failed!");
    
db_host = parser.get("Database", "DB_IP");
db_user = parser.get("Database", "DB_USER");
db_pwd = parser.get("Database", "DB_PWD");
db_port = parser.get("Database", "DB_PORT");
db_db = parser.get("Database", "DB_DB");
db_tableConfig = parser.get("Database", "DB_TABLE");

path = parser.get("Output", "PATH");

templatecpp = "";
tplcppfilename = parser.get("Template", "FILECPP");
try:
    tplcppfile = open(tplcppfilename, "r");
    templatecpp = tplcppfile.read();
finally:
    tplcppfile.close();
    
author = parser.get("FileInfo", "AUTHOR");
date = datetime.date.today();
templatecpp = re.sub("@author", author, templatecpp);
templatecpp = re.sub("@date", str(date), templatecpp);

cppfilename = path + "DbData.cpp";
cppinclude = "";
cppcontent = "";


db_tables = db_tableConfig.split(",");

for db_table in db_tables:
    fields = [];
    fieldtypes = [];
    fieldnulls = [];
    key = "";
    try:
        conn = MySQLdb.Connect(host=db_host, user=db_user, passwd=db_pwd, port=int(db_port));
        conn.select_db(db_db);
        cur = conn.cursor();
                    
        sql = "DESCRIBE " + db_table;
        
        numrows = cur.execute(sql);
        if numrows <= 0:
            LogExit("ExecuteSQL ", sql, " failed!");
            
        resset = cur.fetchall();
        for res in resset:
            fields.append(res[0]);
            fieldtype = res[1].lower();
            bunsigned = IsUnsigned(fieldtype);
            bnullable = IsNullable(res[2]);
            key = IsPrimaryKey(res[3]);
            if fieldtype.find(" ") != -1:
                fieldtype = fieldtype[0:fieldtype.find(" ")];
            if fieldtype.find("(") != -1:
                fieldtype = fieldtype[0:fieldtype.find("(")];
            fieldtype = MakeMysqlppType(fieldtype, bunsigned, bnullable);
            fieldtypes.append(fieldtype);
    finally:
        cur.close();
        conn.close();
        
    print "Connect to Database OK, begin generating...";
    
    tblnameidx = db_table.find("_");
    realtblname = db_table;
    if tblnameidx != -1:
        realtblname = db_table[tblnameidx+1:];
    
    
    
    tplfilename = parser.get("Template", "FILEH");
    
    template = "";
    try:
        tplfile = open(tplfilename, "r");
        template = tplfile.read();
    finally:
        tplfile.close();
        
    template = re.sub("@author", author, template);
    template = re.sub("@date", str(date), template);
    template = re.sub("@tblname_upper", realtblname.upper(), template);
    template = re.sub("@tblname", db_table, template);
    
    parm0 = "";
    parm1 = "";
    
    for j in range(1, numrows+1):
        parm0 +=  "T%d, C%d"%(j,j);
        if j != numrows:
            parm0 += ", ";
        parm1 += "C%d" %j;
        if j != numrows:
            parm1 += ", ";
    
    compr = "";
    parm2 = "";
    define = "";
    if (numrows != 1):
        compr = "    int cmp; \\\n";
    compp = "";
    myset = "";
    for j in range(1, numrows+1):
        if j != numrows :
            compr += "    cmp = mysqlpp::sql_cmp(x." + fields[j-1] + ", y." + fields[j-1] +" ); \\\n";
            compr += "    if (cmp) return cmp; \\\n";
        if j == numrows:
            compr += "    return mysqlpp::sql_cmp(x." + fields[j-1] + ", y." + fields[j-1] + ");";
        parm2 += "const " + fieldtypes[j-1] + " &p" + str(j);
        if j != numrows:
            parm2 += ", ";
        define += "" + fields[j-1] + " (p" + str(j) + ")";   
        if j != numrows:
            define += ", ";
        myset += "    %s = p%d;\\\n" % (fields[j-1], j);
        compp += "true";
        if j != numrows:
            compp += ", ";
            
    tblwords = realtblname.split("_");
    realtblname = "";
    for word in tblwords:
        realtblname += word.capitalize();
    dataname = "C" + realtblname + "Data";
    
    
    sql_compare_define = re.sub("@dataname", dataname, "bool operator == (const @dataname &other) const \n {return sql_compare_@dataname<mysqlpp::sql_dummy>(*this,other) == 0;} \n bool operator != (const @dataname &other) const \n {return sql_compare_@dataname<mysqlpp::sql_dummy>(*this,other) != 0;} \n bool operator > (const @dataname &other) const \n {return sql_compare_@dataname<mysqlpp::sql_dummy>(*this,other) >  0;} \n bool operator < (const @dataname &other) const \n {return sql_compare_@dataname<mysqlpp::sql_dummy>(*this,other) <  0;} \n bool operator >= (const @dataname &other) const \n {return sql_compare_@dataname<mysqlpp::sql_dummy>(*this,other) >= 0;} \n bool operator <= (const @dataname &other) const \n {return sql_compare_@dataname<mysqlpp::sql_dummy>(*this,other) <= 0;} \n int cmp (const @dataname &other) const \n {return sql_compare_@dataname<mysqlpp::sql_dummy>(*this,other);} \n int compare (const @dataname &other) const \n {return sql_compare_@dataname<mysqlpp::sql_dummy>(*this,other);}\n");
    
    sql_compare_define1 = "%s(%s) : %s, table_override_(0) {}\nvoid set(%s) {\ntable_override_ = 0;\n%s\n}\n@sql_compare_define" % (dataname, parm2, define, parm2, myset)
    sql_compare_define1 = re.sub("@sql_compare_define", sql_compare_define, sql_compare_define1);
    
    sql_construct_define1 = "void set(%s) {\ntable_override_ = 0;\n%s\n}\n%s(%s) : %s, table_override_(0) {}\n" % (parm2, myset, dataname, parm2, define)
    
    myparm0 = "";
    myparm1 = "";
    myset0 = "";
    end = 1;
    for j in range(1, end+1):
        myparm0 += "const %s p%d" %(fieldtypes[j-1], j)
        if j !=1:
            myparm0 += " = 0";
        if j != end:
            myparm0 += ", ";
        myparm1 += "%s(p%d)"%(fields[j-1], j);
        if j != end:
            myparm1 += ", ";
        myset0 += "    %s = p%d;\n"  %(fields[j-1], j)   
        
    sql_construct_def_my = """void set(%s) { \\
        table_override_ = 0;\n
    %s\n
        } \\
        %s(%s) : %s, table_override_(0) {}""" %(myparm0, myset0, dataname, myparm0, myparm1);
    
    sql_compare_type_def1 = "return @WHAT_list(d, m, %s)" %(compp);
    
    
    sql_compare_type_defe1 = "return @WHAT_list(d, c, m, %s)" %(compp);
    
    sql_COMPARE__1 = "template <mysqlpp::sql_dummy_type dummy> \n int sql_compare_@dataname(const @dataname &x, const @dataname &y) { \n %s \n } \n template <mysqlpp::sql_dummy_type dummy> \n int compare (const @dataname &x, const @dataname &y) { \n %s \n }" %(compr, compr)
    sql_COMPARE__1 = re.sub("@dataname", dataname, sql_COMPARE__1);
    
    
    create_bool = "";
    create_list = "";
    cus_equal_list = "";
    cus_field_list = "";
    cusparms1 = "";
    cusparms11 = "";
    cusparms2 = "";
    cusparms22 = "";
    cusparmsv = "";
    defs = "";
    enums = "";
    equal_list = "";
    field_list = "";
    names = "";
    parmc = "";
    parmC = "";
    parm_complete = "";
    parm_simple = "";
    parm_simple2c = "";
    parm_simple2c_b = "";
    parm_simple_b = "";
    popul = "";
    value_list = "";
    value_list_cus = "";
    
    for j in range(1, numrows+1):
        parm_complete += "%s, %s, \"%s\"" % (fieldtypes[j-1], fields[j-1], fields[j-1]);
        if j != numrows:
            parm_complete += ", ";
        parm_simple += "%s, %s" % (fieldtypes[j-1], fields[j-1]);
        if j != numrows:
            parm_simple += ", ";
        parm_simple2c += "%s, %s, \"%s\"" %(fieldtypes[j-1], fields[j-1], fields[j-1]);
        if j != numrows:
            parm_simple2c += ", ";
        parm_simple_b += "%s, %s" % (fieldtypes[j-1], fields[j-1]);
        if j != numrows:
            parm_simple_b += ", ";
        parm_simple2c_b += "%s, %s" % (fieldtypes[j-1], fields[j-1]);
        if j != numrows:
            parm_simple2c_b += ", ";
        defs += "    %s %s;" %(fieldtypes[j-1], fields[j-1]);
        if j != numrows:
            defs += "\n";
        popul += "    s->%s = row[\"%s\"].conv(%s());" %(fields[j-1], fields[j-1], fieldtypes[j-1]);
        if j != numrows:
            popul += "\n";
        names += "    \"%s\" " %(fields[j-1]);
        if j != numrows:
            names += ",\n";
        enums += "    %s_%s" %(dataname[1:].upper(), fields[j-1].upper());
        if j != numrows:
            enums +=",\n";
            
        field_list += "    s << obj.manip << '`' << obj.obj->names[%d] << '`'" %(j-1);
        if j != numrows:
            field_list += " << obj.delim;\n";
        value_list += "    s << obj.manip << obj.obj->%s" %(fields[j-1]);
        if j != numrows:
            value_list += " << obj.delim;\n";
        create_bool += "    if (i%d) (*include)[%d]=true;\n" %(j, j-1);
        
        if j != 1:
            create_list += "    if (i%d == %s_NULL) return;\n" %(j, dataname[1:].upper())
        create_list += "    (*include)[i%d]=true;\n" %(j);
        
        value_list_cus +="    if ((*obj.include)[%d]) { \n" %(j-1);
        if j != 1:
            value_list_cus += "      if (before) s << obj.delim;\n";
        value_list_cus += "      s << obj.manip << obj.obj->%s;\n" %(fields[j-1]);
        if j != numrows:
            value_list_cus += "      before = true; \n";
        value_list_cus += "     } \n";
        
        cus_field_list += "    if ((*obj.include)[%d]) { \n" %(j-1);
        if j != 1:
            cus_field_list += "      if (before) s << obj.delim;\n";
        cus_field_list += "      s << obj.manip << '`' << obj.obj->names[%d] << '`';\n" %(j-1)
        if j != numrows:
            cus_field_list += "      before = true; \n";
        cus_field_list += "     } \n";
        
        cus_equal_list += "    if ((*obj.include)[%d]) { \n" %(j-1)
        if j != 1:
            cus_equal_list += "      if (before) s << obj.delim;\n";
        cus_equal_list += "      s << '`' << obj.obj->names[%d] << '`' << obj.comp" %(j-1)
        cus_equal_list += "         << obj.manip << obj.obj->%s;\n"%(fields[j-1])
        if j != numrows:
            cus_equal_list += "      before = true; \n";
        cus_equal_list += "     } \n";
        
        equal_list += "    s << '`' << obj.obj->names[%d] << '`' << obj.comp" %(j-1)
        equal_list += " << obj.manip << obj.obj->%s" %(fields[j-1])
        if j != numrows:
            equal_list += " << obj.delim;\n";
            
        if j == 1:
            cusparms1 += "bool i%d" %(j);
        if j != 1:
            cusparms1 += "bool i%d = false" %(j)
        if j != numrows:
            cusparms1 += ", ";
        
        cusparms11 += "bool i%d" %(j)
        if j != numrows:
            cusparms11 += ", ";
        
        if j == 1:
            cusparms2 += "%s_enum i%d" %(dataname, j)
        if j != 1:
            cusparms2 += "%s_enum i%d = %s_NULL" %(dataname, j, dataname[1:].upper());
        if j != numrows:
            cusparms2 += ", ";
        
        cusparms22 += "%s_enum i%d" %(dataname, j);
        if j != numrows:
            cusparms22 += ", ";
        
        cusparmsv += "i%d" %(j);
        if j != numrows:
            cusparmsv += ", ";
            
        parmC += "T%d, I%d"%(j, j);
        if j != numrows:
            parmC += ", ";
            
        parmc += "I%d" %(j);
        if j != numrows:
            parmc += ", ";
        
    createcomplete = """struct @dataname; 
    
        enum @dataname_enum { 
    $enums,
        @Udataname_NULL 
        }; 
    
        template <class Manip>
        class @dataname_value_list { 
        public: 
        const @dataname* obj;
        const char* delim;
        Manip manip;
        public: 
        @dataname_value_list (const @dataname* o, const char* d, Manip m) :
        obj(o), delim(d), manip(m) { } 
        };
    
        template <class Manip>
        class @dataname_field_list {
        public: 
        const @dataname* obj; 
        const char* delim;
        Manip manip;
        public: 
        @dataname_field_list (const @dataname* o, const char* d, Manip m) :
        obj(o), delim(d), manip(m) { } 
        };
    
        template <class Manip>
        class @dataname_equal_list { 
        public: 
        const @dataname* obj;
        const char* delim;
        const char* comp;
        Manip manip;
        public: 
        @dataname_equal_list (const @dataname* o, const char* d, const char* c, Manip m) :
        obj(o), delim(d), comp(c), manip(m) { }
        };
    
        template <class Manip>
        class @dataname_cus_value_list {
        public:
        const @dataname* obj;
        std::vector<bool> *include;
        bool del_vector;
        const char* delim;
        Manip manip;
        public: 
        ~@dataname_cus_value_list () {if (del_vector) delete include;} 
        @dataname_cus_value_list (const @dataname* o, const char* d, Manip m, $cusparms11);
        @dataname_cus_value_list (const @dataname* o, const char* d, Manip m, $cusparms22); 
        @dataname_cus_value_list (const @dataname* o, const char* d, Manip m ,std::vector<bool>* i) :
        obj(o), include(i), del_vector(false), delim(d), manip(m) { }
        };
    
        template <class Manip>
        class @dataname_cus_field_list { 
        public:
        const @dataname* obj; 
        std::vector<bool> *include; 
        bool del_vector; 
        const char* delim;
        Manip manip;
        public: 
        ~@dataname_cus_field_list () {if (del_vector) delete include;} 
        @dataname_cus_field_list (const @dataname* o, const char* d, Manip m, $cusparms11); 
        @dataname_cus_field_list (const @dataname* o, const char* d, Manip m, $cusparms22); 
        @dataname_cus_field_list (const @dataname* o, const char* d, Manip m, std::vector<bool> *i) :
        obj(o), include(i), del_vector(false), delim(d), manip(m) { }
        };
    
        template <class Manip>
        class @dataname_cus_equal_list {
        public:
        const @dataname* obj;
        std::vector<bool> *include;
        bool del_vector;
        const char* delim;
        const char* comp;
        Manip manip;
        public:
        ~@dataname_cus_equal_list () {if (del_vector) delete include;}
        @dataname_cus_equal_list (const @dataname* o, const char* d, const char* c, Manip m, $cusparms11); 
        @dataname_cus_equal_list (const @dataname* o, const char* d, const char* c, Manip m, $cusparms22); 
        @dataname_cus_equal_list (const @dataname* o, const char* d, const char* c, Manip m, std::vector<bool> *i) :
        obj(o), include(i), del_vector(false), delim(d), comp(c), manip(m) { }
        };
    
        template <mysqlpp::sql_dummy_type dummy> int sql_compare_@dataname(const @dataname&, const @dataname&);
    
        struct @dataname {
    $defs 
        @dataname() : table_override_(0) { }
        @dataname(const mysqlpp::Row& row);
        void set(const mysqlpp::Row &row);
        @sql_compare_define_1
        @sql_construct_define_1
        static const char* names[];
        static void table(const char* t) { table_ = t; }
        const char* table() const
                { return table_override_ ? table_override_ : @dataname::table_; }
        void instance_table(const char* t) { table_override_ = t; }
    
        @dataname_value_list<mysqlpp::quote_type0> value_list() const {
            return value_list(",", mysqlpp::quote);}
        @dataname_value_list<mysqlpp::quote_type0> value_list(const char* d) const {
            return value_list(d, mysqlpp::quote);}
        template <class Manip>
        @dataname_value_list<Manip> value_list(const char* d, Manip m) const;
    
        @dataname_field_list<mysqlpp::do_nothing_type0> field_list() const {
            return field_list(",", mysqlpp::do_nothing);}
        @dataname_field_list<mysqlpp::do_nothing_type0> field_list(const char* d) const {
            return field_list(d, mysqlpp::do_nothing);}
        template <class Manip>
        @dataname_field_list<Manip> field_list(const char* d, Manip m) const;
    
        @dataname_equal_list<mysqlpp::quote_type0> equal_list(const char* d = ",",
                const char* c = " = ") const
                { return equal_list(d, c, mysqlpp::quote); }
        template <class Manip>
        @dataname_equal_list<Manip> equal_list(const char* d, const char* c, Manip m) const;
    
        /* cus_data */
    
        @dataname_cus_value_list<mysqlpp::quote_type0> value_list($cusparms1) const
                { return value_list(",", mysqlpp::quote, $cusparmsv); }
        @dataname_cus_value_list<mysqlpp::quote_type0> value_list($cusparms2) const
                { return value_list(",", mysqlpp::quote, $cusparmsv); }
        @dataname_cus_value_list<mysqlpp::quote_type0> value_list(std::vector<bool> *i) const
                { return value_list(",", mysqlpp::quote, i); }
        @dataname_cus_value_list<mysqlpp::quote_type0> value_list(mysqlpp::sql_cmp_type sc) const
                { return value_list(",", mysqlpp::quote, sc); }
    
        @dataname_cus_value_list<mysqlpp::quote_type0> value_list(const char* d, $cusparms1) const
                { return value_list(d, mysqlpp::quote, $cusparmsv); }
        @dataname_cus_value_list<mysqlpp::quote_type0> value_list(const char* d, $cusparms2) const
                { return value_list(d, mysqlpp::quote, $cusparmsv); }
        @dataname_cus_value_list<mysqlpp::quote_type0> value_list(const char* d,
                std::vector<bool> *i) const
                { return value_list(d, mysqlpp::quote, i); }
        @dataname_cus_value_list<mysqlpp::quote_type0> value_list(const char* d,
                mysqlpp::sql_cmp_type sc) const
                { return value_list(d, mysqlpp::quote, sc); }
    
        template <class Manip>
        @dataname_cus_value_list<Manip> value_list(const char* d, Manip m,
                $cusparms1) const;
        template <class Manip>
        @dataname_cus_value_list<Manip> value_list(const char* d, Manip m,
                $cusparms2) const;
        template <class Manip>
        @dataname_cus_value_list<Manip> value_list(const char* d, Manip m,
                std::vector<bool>* i) const;
        template <class Manip>
        @dataname_cus_value_list<Manip> value_list(const char* d, Manip m, 
                mysqlpp::sql_cmp_type sc) const;
        /* cus field */
    
        @dataname_cus_field_list<mysqlpp::do_nothing_type0> field_list($cusparms1) const 
                { return field_list(",", mysqlpp::do_nothing, $cusparmsv); }
        @dataname_cus_field_list<mysqlpp::do_nothing_type0> field_list($cusparms2) const
                { return field_list(",", mysqlpp::do_nothing, $cusparmsv); }
        @dataname_cus_field_list<mysqlpp::do_nothing_type0> field_list(std::vector<bool> *i) const
                { return field_list(",", mysqlpp::do_nothing, i); }
        @dataname_cus_field_list<mysqlpp::do_nothing_type0> field_list(mysqlpp::sql_cmp_type sc) const
                { return field_list(",", mysqlpp::do_nothing, sc); }
    
        @dataname_cus_field_list<mysqlpp::do_nothing_type0> field_list(const char* d,
                $cusparms1) const
                { return field_list(d, mysqlpp::do_nothing, $cusparmsv); }
        @dataname_cus_field_list<mysqlpp::do_nothing_type0> field_list(const char* d,
                $cusparms2) const
                { return field_list(d, mysqlpp::do_nothing, $cusparmsv); }
        @dataname_cus_field_list<mysqlpp::do_nothing_type0> field_list(const char* d,
                std::vector<bool>* i) const
                { return field_list(d, mysqlpp::do_nothing, i); }
        @dataname_cus_field_list<mysqlpp::do_nothing_type0> field_list(const char* d,
                mysqlpp::sql_cmp_type sc) const
                { return field_list(d, mysqlpp::do_nothing, sc); }
    
        template <class Manip>
        @dataname_cus_field_list<Manip> field_list(const char* d, Manip m,
                $cusparms1) const;
        template <class Manip>
        @dataname_cus_field_list<Manip> field_list(const char* d, Manip m,
                $cusparms2) const;
        template <class Manip>
        @dataname_cus_field_list<Manip> field_list(const char* d, Manip m,
                std::vector<bool> *i) const;
        template <class Manip>
        @dataname_cus_field_list<Manip> field_list(const char* d, Manip m,
                mysqlpp::sql_cmp_type sc) const;
    
        /* cus equal */
    
        @dataname_cus_equal_list<mysqlpp::quote_type0> equal_list($cusparms1) const
                { return equal_list(",", " = ", mysqlpp::quote, $cusparmsv); }
        @dataname_cus_equal_list<mysqlpp::quote_type0> equal_list($cusparms2) const
                { return equal_list(",", " = ", mysqlpp::quote, $cusparmsv); }
        @dataname_cus_equal_list<mysqlpp::quote_type0> equal_list(std::vector<bool>* i) const
                { return equal_list(",", " = ", mysqlpp::quote, i); }
        @dataname_cus_equal_list<mysqlpp::quote_type0> equal_list(mysqlpp::sql_cmp_type sc) const
                { return equal_list(",", " = ", mysqlpp::quote, sc); }
    
        @dataname_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d, $cusparms1) const
                { return equal_list(d, " = ", mysqlpp::quote, $cusparmsv); }
        @dataname_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d, $cusparms2) const
                { return equal_list(d, " = ", mysqlpp::quote, $cusparmsv); }
        @dataname_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d,
                std::vector<bool> *i) const
                { return equal_list(d, " = ", mysqlpp::quote, i); }
        @dataname_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d,
                mysqlpp::sql_cmp_type sc) const
                { return equal_list(d, " = ", mysqlpp::quote, sc); }
    
        @dataname_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d, const char* c,
                $cusparms1) const
                { return equal_list(d, c, mysqlpp::quote, $cusparmsv); }
        @dataname_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d, const char* c,
                $cusparms2) const
                { return equal_list(d, c, mysqlpp::quote, $cusparmsv); }
        @dataname_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d, const char* c,
                std::vector<bool> *i) const
                { return equal_list(d, c, mysqlpp::quote, i); }
        @dataname_cus_equal_list<mysqlpp::quote_type0> equal_list(const char* d, const char* c,
                mysqlpp::sql_cmp_type sc) const
                { return equal_list(d, c, mysqlpp::quote, sc); }
    
        template <class Manip>
        @dataname_cus_equal_list<Manip> equal_list(const char* d, const char* c, Manip m, 
                            $cusparms1) const;
        template <class Manip>
        @dataname_cus_equal_list<Manip> equal_list(const char* d, const char* c, Manip m, 
                            $cusparms2) const;
        template <class Manip>
        @dataname_cus_equal_list<Manip> equal_list(const char* d, const char* c, Manip m, 
                            std::vector<bool> *i) const;
        template <class Manip>
        @dataname_cus_equal_list<Manip> equal_list(const char* d, const char* c, Manip m, 
                            mysqlpp::sql_cmp_type sc) const;
    
        private:
        static const char* table_;
        const char* table_override_;
        };
            
        template <class Manip>
        @dataname_cus_value_list<Manip>::@dataname_cus_value_list
                (const @dataname* o, const char* d, Manip m, $cusparms11)
        {
            delim = d;
            manip = m;
            del_vector = true;
            obj = o;
            include = new std::vector<bool>($i, false);
    $create_bool
        }
    
        template <class Manip>
        @dataname_cus_value_list<Manip>::@dataname_cus_value_list
                (const @dataname* o, const char* d, Manip m, $cusparms22)
        {
            delim = d;
            manip = m;
            del_vector = true;
            obj = o;
            include = new std::vector<bool>($i, false);
    $create_list
        }
    
        template <class Manip>
        @dataname_cus_field_list<Manip>::@dataname_cus_field_list
                (const @dataname* o, const char* d, Manip m, $cusparms11)
        {
            delim = d;
            manip = m;
            del_vector = true;
            obj = o;
            include = new std::vector<bool>($i, false);
    $create_bool
        }
    
        template <class Manip>
        @dataname_cus_field_list<Manip>::@dataname_cus_field_list
                (const @dataname* o, const char* d, Manip m, $cusparms22)
        {
            delim = d;
            manip = m;
            del_vector = true;
            obj = o;
            include = new std::vector<bool>($i, false);
    $create_list
        }
    
        template <class Manip>
        @dataname_cus_equal_list<Manip>::@dataname_cus_equal_list
                (const @dataname* o, const char* d, const char* c, Manip m, $cusparms11)
        {
            delim = d;
            comp = c;
            manip = m;
            del_vector = true;
            obj = o;
            include = new std::vector<bool>($i, false);
    $create_bool
        }
    
        template <class Manip>
        @dataname_cus_equal_list<Manip>::@dataname_cus_equal_list
                (const @dataname* o, const char* d, const char* c, Manip m, $cusparms22)
        {
            delim = d;
            comp = c;
            manip = m;
            del_vector = true;
            obj = o;
            include = new std::vector<bool>($i, false);
    $create_list
        }
    
        template <class Manip>
        std::ostream& operator <<(std::ostream& s, const @dataname_value_list<Manip>& obj)
        {
    $value_list;
            return s;
        }
    
        template <class Manip>
        std::ostream& operator <<(std::ostream& s, const @dataname_field_list<Manip>& obj)
        {
    $field_list;
            return s;
        }
    
        template <class Manip>
        std::ostream& operator <<(std::ostream& s, const @dataname_equal_list<Manip>& obj)
        {
    $equal_list;
            return s;
        }
    
        template <class Manip>
        std::ostream& operator <<(std::ostream& s, const @dataname_cus_value_list<Manip>& obj)
        {
            bool before = false;
    $value_list_cus
            return s;
        }
    
        template <class Manip>
        std::ostream& operator <<(std::ostream& s, const @dataname_cus_field_list<Manip>& obj)
        {
            bool before = false;
    $cus_field_list
            return s;
        }
    
        template <class Manip>
        std::ostream& operator <<(std::ostream& s, const @dataname_cus_equal_list<Manip>& obj)
        {
            bool before = false;
    $cus_equal_list
            return s;
        }
    
        template <class Manip>
        inline @dataname_value_list<Manip> @dataname::value_list(const char* d, Manip m) const
                { return @dataname_value_list<Manip> (this, d, m); } 
    
        template <class Manip>
        inline @dataname_field_list<Manip> @dataname::field_list(const char* d, Manip m) const
                { return @dataname_field_list<Manip> (this, d, m); } 
    
        template <class Manip>
        inline @dataname_equal_list<Manip> @dataname::equal_list(const char* d, const char* c, Manip m) const
                { return @dataname_equal_list<Manip> (this, d, c, m); } 
    
        template <class Manip>
        inline @dataname_cus_value_list<Manip> @dataname::value_list(const char* d, Manip m,
                $cusparms11) const
                { return @dataname_cus_value_list<Manip> (this, d, m, $cusparmsv); }
    
        template <class Manip>
        inline @dataname_cus_field_list<Manip> @dataname::field_list(const char* d, Manip m,
                $cusparms11) const
                { return @dataname_cus_field_list<Manip> (this, d, m, $cusparmsv); }
    
        template <class Manip>
        inline @dataname_cus_equal_list<Manip> @dataname::equal_list(const char* d, const char* c, Manip m,
                $cusparms11) const
                { return @dataname_cus_equal_list<Manip> (this, d, c, m, $cusparmsv); } 
    
        template <class Manip>
        inline @dataname_cus_value_list<Manip> @dataname::value_list(const char* d, Manip m,
                $cusparms22) const
                { return @dataname_cus_value_list<Manip> (this, d, m, $cusparmsv); } 
    
        template <class Manip>
        inline @dataname_cus_field_list<Manip> @dataname::field_list(const char* d, Manip m,
                $cusparms22) const
                { return @dataname_cus_field_list<Manip> (this, d, m, $cusparmsv); } 
    
        template <class Manip>
        inline @dataname_cus_equal_list<Manip> @dataname::equal_list(const char* d, const char* c, Manip m, 
                $cusparms22) const
                { return @dataname_cus_equal_list<Manip> (this, d, c, m, $cusparmsv); } 
    
        template <class Manip>
        inline @dataname_cus_value_list<Manip> @dataname::value_list(const char* d, Manip m,
                std::vector<bool> *i) const
                { return @dataname_cus_value_list<Manip> (this, d, m, i); }
    
        template <class Manip>
        inline @dataname_cus_field_list<Manip> @dataname::field_list(const char* d, Manip m,
                std::vector<bool> *i) const
                { return @dataname_cus_field_list<Manip> (this, d, m, i); }
    
        template <class Manip>
        inline @dataname_cus_equal_list<Manip> @dataname::equal_list(const char* d, const char* c, Manip m,
                std::vector<bool> *i) const
                { return @dataname_cus_equal_list<Manip> (this, d, c, m, i); }
    
        template <class Manip>
        inline @dataname_cus_value_list<Manip> 
        @dataname::value_list(const char* d, Manip m, mysqlpp::sql_cmp_type /*sc*/) const
                { @value; }
    
        template <class Manip>
        inline @dataname_cus_field_list<Manip> 
        @dataname::field_list(const char* d, Manip m, mysqlpp::sql_cmp_type /*sc*/) const
                { @field; }
    
        template <class Manip>
        inline @dataname_cus_equal_list<Manip> 
        @dataname::equal_list(const char* d, const char* c, Manip m, mysqlpp::sql_cmp_type /*sc*/) const
                { @equal; }
    
        template <mysqlpp::sql_dummy_type dummy>
        void populate_@dataname(@dataname *s, const mysqlpp::Row &row)
        {
            mysqlpp::NoExceptions ignore_schema_mismatches(row);
    $popul
        }
    
        inline @dataname::@dataname(const mysqlpp::Row& row) :
        table_override_(0)
                { populate_@dataname<mysqlpp::sql_dummy>(this, row); }
        inline void @dataname::set(const mysqlpp::Row& row)
        {
            table_override_ = 0;
            populate_@dataname<mysqlpp::sql_dummy>(this, row);
        }
    
        @sql_COMPARE__1"""
    
    createcomplete = re.sub("@sql_compare_define_1", sql_compare_define1, createcomplete);
    createcomplete = re.sub("@sql_construct_define_1", sql_construct_def_my, createcomplete);
    createcomplete = re.sub("@sql_COMPARE__1", sql_COMPARE__1, createcomplete);
    
    createcomplete = re.sub("@db_table", db_table, createcomplete);
    createcomplete = re.sub("@Udataname", dataname[1:].upper(), createcomplete);
    createcomplete = re.sub("@dataname", dataname, createcomplete);
    createcomplete = re.sub("\$i", str(numrows), createcomplete);
    createcomplete = re.sub("\$create_bool", create_bool, createcomplete);
    createcomplete = re.sub("\$create_list", create_list, createcomplete);
    createcomplete = re.sub("\$cus_equal_list", cus_equal_list, createcomplete);
    createcomplete = re.sub("\$cus_field_list", cus_field_list, createcomplete);
    createcomplete = re.sub("\$cusparms11", cusparms11, createcomplete);
    createcomplete = re.sub("\$cusparms1", cusparms1, createcomplete);
    createcomplete = re.sub("\$cusparms22", cusparms22, createcomplete);
    createcomplete = re.sub("\$cusparms2", cusparms2, createcomplete);
    createcomplete = re.sub("\$cusparmsv", cusparmsv, createcomplete);
    createcomplete = re.sub("\$defs", defs, createcomplete);
    createcomplete = re.sub("\$enums", enums, createcomplete);
    createcomplete = re.sub("\$equal_list", equal_list, createcomplete);
    createcomplete = re.sub("\$field_list", field_list, createcomplete);
    createcomplete = re.sub("\$names", names, createcomplete);
    createcomplete = re.sub("\$parmc", parmc, createcomplete);
    createcomplete = re.sub("\$parmC", parmC, createcomplete);
    createcomplete = re.sub("\$parm_complete", parm_complete, createcomplete);
    createcomplete = re.sub("\$parm_simple2c_b", parm_simple2c_b, createcomplete);
    createcomplete = re.sub("\$parm_simple_b", parm_simple_b, createcomplete);
    createcomplete = re.sub("\$parm_simple2c", parm_simple2c, createcomplete);
    createcomplete = re.sub("\$parm_simple", parm_simple, createcomplete);
    createcomplete = re.sub("\$popul", popul, createcomplete);
    createcomplete = re.sub("\$value_list_cus", value_list_cus, createcomplete);
    createcomplete = re.sub("\$value_list", value_list, createcomplete);
    
    sql_compare_type_def1_value = re.sub("@WHAT", "value", sql_compare_type_def1);
    createcomplete = re.sub("@value", sql_compare_type_def1_value, createcomplete);
    sql_compare_type_def1_value = re.sub("@WHAT", "field", sql_compare_type_def1);
    createcomplete = re.sub("@field", sql_compare_type_def1_value, createcomplete);
    sql_compare_type_defe1_value = re.sub("@WHAT", "equal", sql_compare_type_defe1);
    createcomplete = re.sub("@equal", sql_compare_type_defe1_value, createcomplete);
    
    staticimpl = """const char* @dataname::names[] = {
    $names
};
const char* @dataname::table_ = "@db_table";\n""";
    staticimpl = re.sub("@dataname", dataname, staticimpl);
    staticimpl = re.sub("\$names", names, staticimpl);
    staticimpl = re.sub("@db_table", db_table, staticimpl);
    
    cppcontent += staticimpl;
    
    template = re.sub("@content", createcomplete, template);
        
    filename = path + dataname[1:] + ".h";
    cppinclude += "#include \"" + dataname[1:] + ".h\"\n";
    
    try:
        outfile = open(filename, "w");
        outfile.write(template);
    finally:
        outfile.close();
        
    print "Gen %s Successfully." %filename;
    
templatecpp = re.sub("@include", cppinclude, templatecpp);
templatecpp = re.sub("@content", cppcontent, templatecpp);
try:
    cppoutfile = open(cppfilename, "w");
    cppoutfile.write(templatecpp);
finally:
    cppoutfile.close();
    
print "Gen %s Successfully." %cppfilename;