#ifndef __TRIVIALDB_PARSER_DEF__
#define __TRIVIALDB_PARSER_DEF__
#include "../Common/Common.h"

#include <cstdint>
#include <cstdlib>

namespace Parser {
enum field_type_t{
	FIELD_TYPE_INT,
	FIELD_TYPE_FLOAT,
	FIELD_TYPE_CHAR,
	FIELD_TYPE_DATE,
	FIELD_TYPE_VARCHAR
};

enum field_flag_t{
	FIELD_FLAG_NOTNULL = 1,
	FIELD_FLAG_UNIQUE  = 2,
	FIELD_FLAG_PRIMARY = 4
};

enum table_constraint_type_t{
	TABLE_CONSTRAINT_PRIMARY_KEY,
	TABLE_CONSTRAINT_FOREIGN_KEY,
	TABLE_CONSTRAINT_UNIQUE,
	TABLE_CONSTRAINT_CHECK
};

enum table_join_type_t{
	TABLE_JOIN_NONE,
} ;

#define OPERATOR_UNARY 0x80
enum operator_type_t {
	OPERATOR_NONE = 0,
	/* arithematic */
	OPERATOR_ADD,
	OPERATOR_MINUS,
	OPERATOR_DIV,
	OPERATOR_MUL,
	/* logical */
	OPERATOR_AND,
	OPERATOR_OR,
	/* compare */
	OPERATOR_EQ,
	OPERATOR_GEQ,
	OPERATOR_LEQ,
	OPERATOR_NEQ,
	OPERATOR_GT,
	OPERATOR_LT,
	OPERATOR_IN,
	OPERATOR_LIKE,
	/* unary */
	OPERATOR_NEGATE = OPERATOR_UNARY,
	OPERATOR_ISNULL,
	OPERATOR_NOTNULL,
	OPERATOR_NOT,
	/* aggregate */
	OPERATOR_SUM,
	OPERATOR_AVG,
	OPERATOR_MIN,
	OPERATOR_MAX,
	OPERATOR_COUNT,
} ;

enum term_type_t {
	TERM_NONE = 0,
	TERM_COLUMN_REF,
	TERM_INT,
	TERM_STRING,
	TERM_DATE,
	TERM_FLOAT,
	TERM_BOOL,
	TERM_LITERAL_LIST,
	TERM_NULL
} ;

class ASTFieldItem;
class ASTLinkedList;
class ASTColumnRef;
class ASTTableDef;
class ASTInsertInfo;
class ASTExprNode;
class ASTTableConstraint;
class ASTDeleteInfo;
class ASTUpdateInfo;
class ASTSelectInfo;
class ASTTableJoinInfo;

// Old classes(useless)

class ASTFieldItem {
public:	
	char *name;
	int type, width, flags;
	ASTFieldItem *next;
	ASTExprNode *default_value;
};
 

class ASTLinkedList {
public:
	void *data;
	ASTLinkedList *next;
};

class ASTColumnRef {
public:
	char *table;
	char *column;
};

class ASTTableDef {
public:
	char *name;
	ASTFieldItem *fields;
	ASTLinkedList *constraints;
} ;

class ASTInsertInfo {
public:
	char *table;
	ASTLinkedList *columns, *values;
} ;

class ASTExprNode {
public:
	union {
		int    val_i;
		float  val_f;
		char   val_b;
		char  *val_s;
		ASTColumnRef  *column_ref;
		ASTExprNode   *left;
		ASTLinkedList *literal_list;
	};
	ASTExprNode *right;
	operator_type_t op;
	term_type_t term_type;
};

class ASTTableConstraint {
public:
	int type;
	ASTColumnRef *column_ref, *foreign_column_ref;
	ASTExprNode *check_cond;
} ;

class ASTDeleteInfo {
public:
	char *table;
	ASTExprNode *where;
} ;

class ASTUpdateInfo {
public:
	char *table;
	ASTColumnRef *column_ref;
	ASTExprNode *where, *value;
};

class ASTSelectInfo {
public:
	ASTLinkedList *tables, *exprs;
	ASTExprNode *where;
};

class ASTTableJoinInfo {
public:
	table_join_type_t join_type;
	char *table, *join_table, *alias;
	ASTExprNode *cond;
};

}
#endif
