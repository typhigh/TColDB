#include "ASTCommit.h"
#include "../Utils/StringUtils.h"
using namespace std;

namespace Parser {

string ASTCommit::ToString() const 
{
    return "ASTCommit";
}

bool ASTCommit::IsWriteSQL() const 
{
    return true;
}

vector<string> ASTCommit::GetTablesRef() const 
{
    return {Utils::CopyStringFromCString(table)};
}

void ASTCommit::Execute(Executor::ExecutorContextPtr context) const
{
    context->SubmitCommit();
    context->SubmitResult("done");
}

}