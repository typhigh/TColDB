#pragma once
#include "defs.h"

namespace Parser {

class ColumnRef 
{
public:
	char *table;
	char *column;

public:
	ColumnRef* Clone() const;
};
}