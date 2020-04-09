#include "ASTExit.h"
using namespace std;

namespace Parser {

string ASTExit::ToString() const 
{
    return "ASTExit";
}

bool ASTExit::IsWriteSQL() const 
{
    return false;
}

vector<string> ASTExit::GetTablesRef() const 
{
    return vector<std::string>();
}

void ASTExit::Execute(Executor::ExecutorContextPtr context) const
{
    context->SubmitExit();
    context->SubmitResult("Exit");
    LOG_DEBUG("Yes oh");
}

}