#include "ASTCreateInfo.h"
#include "../Utils/StringUtils.h"
using namespace std;

namespace Parser {

string ASTCreateInfo::ToString() const 
{
    return "ASTCreateInfo";
}

Plan::PlanPtr ASTCreateInfo::MakePlan() const 
{
    return Plan::PlanPtr();
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