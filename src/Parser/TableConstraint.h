#pragma once
#include "defs.h"
#include "IAST.h"

namespace Parser {

class TableConstraint 
{
public:
	table_constraint_type_t type;
	ColumnRef *column_ref, *foreign_column_ref;
	ExprNode *check_cond;

public:
	TableConstraint() {}
	~TableConstraint();
} ;

}