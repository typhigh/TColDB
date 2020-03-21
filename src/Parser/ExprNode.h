#pragma once
#include "defs.h"
#include "ColumnRef.h"
#include "IAST.h"
namespace Parser {

class ExprNode  {
public:
	union 
	{
		int    val_i;
		float  val_f;
		char   val_b;
		char  *val_s;
		ColumnRef  	*column_ref;
		ExprNode   	*left;
		ExprNodeList *literal_list;
	};
	ExprNode *right;
	operator_type_t op;
	TermType_t term_type;

public:
	ExprNode();
};

}