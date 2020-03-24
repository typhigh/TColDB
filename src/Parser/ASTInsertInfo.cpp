#include "ASTInsertInfo.h"
#include "../Utils/StringUtils.h"
using namespace std;

namespace Parser {

string ASTInsertInfo::ToString() const 
{
    return "ASTInsertInfo";
}

Plan::PlanPtr ASTInsertInfo::MakePlan() const 
{
    return Plan::PlanPtr();
}

bool ASTInsertInfo::IsWriteSQL() const 
{
    return true;
}

vector<string> ASTInsertInfo::GetTablesRef() const
{
    return vector<string> {Utils::CopyStringFromCString(table)};
}
}