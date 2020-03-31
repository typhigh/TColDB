#include "ASTCreateInfo.h"
#include "../Utils/StringUtils.h"
using namespace std;

namespace Parser {

ASTCreateInfo::~ASTCreateInfo() 
{
    delete name;
    if (fields != nullptr) {
        for (FieldDef* ele : *fields) {
            delete ele;
        }
        delete fields;
    }

    if (constraints != nullptr) {
        for (TableConstraint* ele : *constraints) {
            delete ele;
        }
        delete constraints;
    }
}

string ASTCreateInfo::ToString() const 
{
    return "ASTCreateInfo";
}

bool ASTCreateInfo::IsWriteSQL() const
{
    return true;
}

vector<string> ASTCreateInfo::GetTablesRef() const
{
    return vector<string> {Utils::CopyStringFromCString(name)};
}

}