#include "CommandWrap.h"
using namespace std;

namespace Common {

string CommandWrap::GetContent() const 
{
    return data->GetContent();
}
    
void CommandWrap::SetResult(const string& result) 
{
    return data->SetResult(result);
}

string CommandWrap::GetResult() {
    return data->GetResult();
}

Parser::IAST* CommandWrap::GetParserResult() 
{
    return parserResult;
}

void CommandWrap::SetParserResult(Parser::IAST* parserResult)
{
    this->parserResult = parserResult;
}

}