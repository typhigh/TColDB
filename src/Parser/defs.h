#pragma once
#include <cstdint>
#include <cstdlib>
#include <string>
#include <vector>
#include <memory>

namespace Parser {
enum FieldType_t
{
	FIELD_TYPE_INT,
	FIELD_TYPE_FLOAT,
	FIELD_TYPE_CHAR,
	FIELD_TYPE_DATE,
	FIELD_TYPE_VARCHAR,
	FIELD_TYPE_BOOL,
	FIELD_TYPE_NULL,
	FIELD_TYPE_LAZY
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
	OPERATOR_NEGATE,
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

class IAST;
class IASTNeedPlan;
class IASTNotNeedPlan;
class FieldDef;
class ColumnRef;
class ASTCommit;
class ASTCreateInfo;
class ASTDeleteInfo;
class ASTDropTableInfo;
class ASTExit;
class ASTInsertInfo;
class ASTSelectInfo;
class ASTSetOutput;
class ASTShowTableInfo;
class ASTUpdateInfo;
class ExprNode;
class TableConstraint;
class TableFrom;

using IASTPtr = std::shared_ptr<IAST>;
using IASTNeedPlanPtr = std::shared_ptr<IASTNeedPlan>;
using IASTNotNeedPlanPtr = std::shared_ptr<IASTNotNeedPlan>;
using ColumnRefList = std::vector<ColumnRef*>;
using FieldDefList = std::vector<FieldDef*>;
using TableFromList = std::vector<TableFrom*>;
using ExprNodeList = std::vector<ExprNode*>;
using TableConstraintList = std::vector<TableConstraint*>;

inline std::string ToString(FieldType_t type)
{
    switch (type)
    {
	case FIELD_TYPE_BOOL:		return "FIELD_BOOL";
    case FIELD_TYPE_INT:   		return "FIELD_INT";    
    case FIELD_TYPE_FLOAT: 		return "FIELD_FLOAT";
    case FIELD_TYPE_CHAR: 		return "FIELD_CHAR";
	case FIELD_TYPE_DATE:		return "FIELD_DATA";
    case FIELD_TYPE_VARCHAR:	return "FIELD_VARCHAR";
	case FIELD_TYPE_NULL:		return "FIELD_NULL";
	case FIELD_TYPE_LAZY:		return "FIELD_LAZY";
    default:					return "FIELD_UNKNOWN";
	}
}

inline std::string ToString(table_constraint_type_t type)
{
	switch (type) 
	{
	case TABLE_CONSTRAINT_CHECK: 		return "CHECK";
	case TABLE_CONSTRAINT_FOREIGN_KEY:	return "FOREIGN_KEY";
	case TABLE_CONSTRAINT_PRIMARY_KEY:	return "PRIMARY_KEY";
	case TABLE_CONSTRAINT_UNIQUE:		return "UNIQUE";
	default:							return "UNKNOWN";
	}
}

inline std::string ToString(operator_type_t op)
{
	switch (op) {
	case OPERATOR_SUM: 		return "OPERATOR_SUM";
	case OPERATOR_AVG:		return "OPERATOR_AVG";
	case OPERATOR_MIN:		return "OPERATOR_MIN";
	case OPERATOR_MAX:		return "OPERATOR_MAX";
	case OPERATOR_COUNT:	return "OPERATOR_COUNT";
	default:				return "UNKNOWN";
	}
}

}


