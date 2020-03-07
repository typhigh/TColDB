#pragma once
#include "defs.h"
#include "IAST.h"

namespace Parser {

class ASTTableConstraint : public IAST {
public:
	int type;
	ColumnRef *column_ref, *foreign_column_ref;
	ASTExprNode *check_cond;

public:
    virtual std::string ToString() const override;
} ;

}