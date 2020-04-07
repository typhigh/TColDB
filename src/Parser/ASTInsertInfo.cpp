#include "ASTInsertInfo.h"
#include "../Utils/StringUtils.h"
using namespace std;

namespace Parser {

string ASTInsertInfo::ToString() const 
{
    return "ASTInsertInfo";
}

bool ASTInsertInfo::IsWriteSQL() const 
{
    return true;
}

vector<string> ASTInsertInfo::GetTablesRef() const
{
    return vector<string> {Utils::CopyStringFromCString(table)};
}

void ASTInsertInfo::Execute(Executor::ExecutorContextPtr context) const 
{
    /*TODO*/
}

}