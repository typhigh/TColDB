#pragma once
#include "SQLParserResult.h"
#include <string>
namespace Parser {

class SQLParser
{
public:
    static bool Parse(const std::string& sql, SQLParserResult* result);
    
};

}