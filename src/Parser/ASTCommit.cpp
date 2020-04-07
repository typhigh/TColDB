#include "ASTCommit.h"
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
    return {};
}

void ASTCommit::Execute(Executor::ExecutorContextPtr context) const
{
    context->SubmitCommit();    
    context->SubmitResult("Exit done");
}

}