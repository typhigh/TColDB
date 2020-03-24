#include "ASTTableDef.h"
#include "../Utils/StringUtils.h"
using namespace std;

namespace Parser {

string ASTTableDef::ToString() const 
{
    return "ASTTableDef";
}

Plan::PlanPtr ASTTableDef::MakePlan() const 
{
    return Plan::PlanPtr();
}

bool ASTTableDef::IsWriteSQL() const
{
    return true;
}

vector<string> ASTTableDef::GetTablesRef() const
{
    return vector<string> {Utils::CopyStringFromCString(name)};
}

}