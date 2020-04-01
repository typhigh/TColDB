#include "SQLParser.h"
using namespace std;

char run_parser(const char *input, Parser::SQLParserResult* result);

namespace Parser {

bool SQLParser::Parse(const string& sql, SQLParserResult* result)
{
    /// Step 1 : lexer and program parse
    result = nullptr;
    run_parser(sql.c_str(), result);
    if (result == nullptr || result->GetErrorMsg() == nullptr) {
        return  false;
    }
     
    /// Step 2 :  
    return  SemanticCheck(result); 
}

bool SQLParser::SemanticCheck(const SQLParserResult* result) {
    return true;
}

}