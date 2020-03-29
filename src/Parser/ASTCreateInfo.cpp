#include "ASTCreateInfo.h"
#include "../Utils/StringUtils.h"
using namespace std;

namespace Parser {

string ASTCreateInfo::ToString() const 
{
    return "ASTCreateInfo";
}

bool ASTCreateInfo::IsWriteSQL() const
{
    return true;
}

vector<string> ASTCreateInfo::GetTablesRef() const
{
    return vector<string> {Utils::CopyStringFromCString(name)};
}

}