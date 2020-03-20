#pragma once
#include "SQLParserResult.h"
#include <string>
namespace Parser {

class SQLParserResult* sqlResult;

class SQLParser
{
public:
    static bool Parser(const std::string& sql, SQLParserResult* result);

};


}