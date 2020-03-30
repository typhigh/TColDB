#include "ASTExit.h"
using namespace std;

namespace Parser {

string ASTExit::ToString() const 
{
    return "ASTExit";
}

bool ASTExit::IsWriteSQL() const 
{
    return true;
}

vector<string> ASTExit::GetTablesRef() const {
    return vector<std::string>();
}

}