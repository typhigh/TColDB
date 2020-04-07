#include "CommandWrap.h"
#include <sstream>
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

ClientID CommandWrap::GetClientID() const 
{
    return data->GetclientID();
}

string CommandWrap::ToString() const 
{
    stringstream out;
    out << "Content : \n" + GetContent() + "\n"
        << "ClientID : " + to_string(GetClientID()) + "\n";
    if (parserResult != nullptr) {
        out << parserResult->ToString();
    }
    return out.str();
}

}