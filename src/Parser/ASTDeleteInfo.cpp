#include "ASTDeleteInfo.h"
#include "../Utils/StringUtils.h"
using namespace std;
namespace Parser {

string ASTDeleteInfo::ToString() const 
{
    return "ASTDeleteInfo";
}

Plan::PlanPtr ASTDeleteInfo::MakePlan() const 
{
    return Plan::PlanPtr();
}

bool ASTDeleteInfo::IsWriteSQL() const
{
    return true;
}

vector<string> ASTDeleteInfo::GetTablesRef() const
{
    return vector<string> {Utils::CopyStringFromCString(table)};
}

}