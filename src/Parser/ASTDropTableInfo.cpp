#include "ASTDropTableInfo.h"
using namespace std;

namespace Parser {

string ASTDropTableInfo::ToString() const 
{
    return "ASTDropTableInfo";
}

bool ASTDropTableInfo::IsWriteSQL() const 
{
    return true;
}

vector<string> ASTDropTableInfo::GetTablesRef() const {
    std::string name = table;
    return std::vector<std::string>{name};    
}

}
