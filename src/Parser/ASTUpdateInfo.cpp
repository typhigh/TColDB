#include "ASTUpdateInfo.h"
#include "../Utils/StringUtils.h"
using namespace std;

namespace Parser {

string ASTUpdateInfo::ToString() const 
{
    return "ASTUpdateInfo";
}

Plan::PlanPtr ASTUpdateInfo::MakePlan() const 
{
    /*TODO*/
    return Plan::PlanPtr();
}

bool ASTUpdateInfo::IsWriteSQL() const
{
    return true;
}

vector<string> ASTUpdateInfo::GetTablesRef() const
{
    return vector<string> {Utils::CopyStringFromCString(table)};
}

}