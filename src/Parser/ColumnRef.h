#pragma once
#include "defs.h"
#include <string>
namespace Parser {

class ColumnRef 
{
public:
	char *table;
	char *column;
	
	/// pos -1 means unknown pos
	/// First we use GetFieldName know the pos, and set it
	/// Then we can use pos to seek field
	int pos;
public:
	ColumnRef* Clone() const;
	std::string GetFieldName() const;
};
}