#pragma once
#include "defs.h"
#include "IAST.h"

namespace Parser {

class ASTTableJoinInfo : public IAST{
public:
	table_join_type_t join_type;
	char *table, *join_table, *alias;
	ASTExprNode *cond;

public:
    virtual std::string ToString() const override;
};

}