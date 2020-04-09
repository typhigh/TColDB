#pragma once
#include "defs.h"
#include "ColumnRef.h"
#include "../Columns/Field/Field.h"

namespace Parser {

class ExprNode  {
public:
	union 
	{
		int    val_i = 0;
		float  val_f;
		bool   val_b;
		char  *val_s;
		ColumnRef  	*column_ref;
		ExprNode   	*left;
		ExprNodeList *literal_list;
	};
	ExprNode *right = nullptr;
	operator_type_t op;
	TermType_t term_type;

public:
	/// For const optimize
	Columns::FieldPtr constVal;

public:
	ExprNode();
};

}