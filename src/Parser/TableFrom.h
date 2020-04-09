#pragma once
#include "defs.h"
#include "IAST.h"
#include "../Plan/Plan.h"

namespace Parser {

class TableFrom
{
public:
	table_join_type_t join_type;
	char *table = nullptr;
	char *join_table = nullptr;
	char *alias = nullptr;
	ExprNode *cond = nullptr;

public:
	std::string GetTableRef() const;
};

}