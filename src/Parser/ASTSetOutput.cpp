#include "ASTSetOutput.h"
using namespace std;

namespace Parser {

string ASTSetOutput::ToString() const 
{
    return "ASTSetOutput";
}

bool ASTSetOutput::IsWriteSQL() const 
{
    return true;
}

vector<string> ASTSetOutput::GetTablesRef() const 
{
    return vector<string>();
}

void ASTSetOutput::Execute(Executor::ExecutorContextPtr context) const 
{
    /*TODO*/ 
}

}