#pragma once
#include "defs.h"
#include "FieldType.h"

namespace Parser {

class FieldDef 
{
public:	
	char *name;
	FieldType type;
	int width;
	int flags;
	ExprNode *default_value;
};

using FieldDefPtr = std::shared_ptr<FieldDef>;
}