#pragma once
#include "defs.h"

namespace Parser {

class 

FieldDef 
{
public:	
	char *name = nullptr;
	FieldType_t type;
	int width;
	int flags;
	ExprNode *default_value = nullptr;

public:
	FieldDef() {}
	~FieldDef();
};

using FieldDefPtr = std::shared_ptr<FieldDef>;
}