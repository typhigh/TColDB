#include "SQLParser.h"
using namespace std;

namespace Parser {

char run_parser(const char* s, SQLParserResult* result);

bool SQLParser::Parse(const string& sql, SQLParserResult* result)
{
    result = nullptr;
    run_parser(sql.c_str(), result);
    return result != nullptr || result->GetErrorMsg() != nullptr;   
}

}