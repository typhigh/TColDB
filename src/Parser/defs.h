#ifndef __TRIVIALDB_PARSER_DEF__
#define __TRIVIALDB_PARSER_DEF__
#include "../Common/Common.h"

#include <cstdint>
#include <cstdlib>
#include <string>
#include <vector>

namespace Parser {
enum FieldType_t
{
	FIELD_TYPE_INT,
	FIELD_TYPE_FLOAT,
	FIELD_TYPE_CHAR,
	FIELD_TYPE_DATE,
	FIELD_TYPE_VARCHAR
};
class FieldType;

enum field_flag_t
{
	FIELD_FLAG_NOTNULL = 1,
	FIELD_FLAG_UNIQUE  = 2,
	FIELD_FLAG_PRIMARY = 4
};

enum table_constraint_type_t
{
	TABLE_CONSTRAINT_PRIMARY_KEY,
	TABLE_CONSTRAINT_FOREIGN_KEY,
	TABLE_CONSTRAINT_UNIQUE,
	TABLE_CONSTRAINT_CHECK
};

enum table_join_type_t
{
	TABLE_JOIN_NONE,
} ;



#define OPERATOR_UNARY 0x80
enum operator_type_t 
{
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

enum TermType_t 
{
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

class TermType;
class IAST;
class FieldDef;
class ASTLinkedList;
class ColumnRef;
class ASTTableDef;
class ASTInsertInfo;
class ASTExprNode;
class ASTTableConstraint;
class ASTDeleteInfo;
class ASTUpdateInfo;
class ASTSelectInfo;
class ASTTableJoinInfo;

using IASTPtr = std::shared_ptr<IAST>;
using ColumnRefList = std::vector<ColumnRef*>;
using FieldDefList = std::vector<FieldDef*>;
using ASTTableJoinInfoList = std::vector<ASTTableJoinInfo*>;
using ASTExprNodeList = std::vector<ASTExprNode*>;
using ASTTableConstraintList = std::vector<ASTTableConstraint*>;

}
#endif



