#include "ASTDeleteInfo.h"
#include "../Utils/StringUtils.h"
#include "Expression/Expression.h"
using namespace std;
namespace Parser {

ASTDeleteInfo::~ASTDeleteInfo() 
{  
    delete table;
    Expression::Free(where);
}

string ASTDeleteInfo::ToString() const 
{
    return "ASTDeleteInfo";
}

Plan::PlanPtr ASTDeleteInfo::MakePlan(Plan::PlanContextPtr context) const 
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