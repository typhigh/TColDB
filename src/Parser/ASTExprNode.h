#pragma once
#include "defs.h"
#include "IAST.h"
namespace Parser {

class ASTExprNode : public IAST {
public:
	union {
		int    val_i;
		float  val_f;
		char   val_b;
		char  *val_s;
		ColumnRef  	*column_ref;
		ASTExprNode   	*left;
		ASTExprNodeList *literal_list;
	};
	ASTExprNode *right;
	operator_type_t op;
	TermType_t term_type;

public:
    virtual std::string ToString() const override;
};

}