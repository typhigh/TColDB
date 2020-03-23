#pragma once
#include "defs.h"
#include <string>
namespace Parser {

class ColumnRef 
{
public:
	char *table;
	char *column;

public:
	ColumnRef* Clone() const;
	std::string GetFieldName() const;
};
}