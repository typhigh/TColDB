#include "ASTShowTableInfo.h"
using namespace std;

namespace Parser {
    
string ASTShowTableInfo::ToString() const {
    return "SetOutput";
}

bool ASTShowTableInfo::IsWriteSQL() const {
    return false;
}

std::vector<std::string> ASTShowTableInfo::GetTablesRef() const {
    std::string name = table;
    return std::vector<std::string>{name};
}

}