#pragma once
#include "defs.h"
#include "IAST.h"

namespace Parser {

class TableConstraint 
{
public:
	table_constraint_type_t type;
	ColumnRef *column_ref = nullptr;
	ColumnRef *foreign_column_ref = nullptr;
	ExprNode *check_cond = nullptr;

public:
	TableConstraint() {}
	~TableConstraint();
} ;

}