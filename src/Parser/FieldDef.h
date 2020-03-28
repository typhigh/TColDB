#pragma once
#include "defs.h"

namespace Parser {

class FieldDef 
{
public:	
	char *name;
	FieldType_t type;
	int width;
	int flags;
	ExprNode *default_value;
};

using FieldDefPtr = std::shared_ptr<FieldDef>;
}