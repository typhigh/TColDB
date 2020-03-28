#include "ColumnRef.h"
#include "../Utils/StringUtils.h"
#include <cstring>

using namespace std;

namespace Parser {

ColumnRef* ColumnRef::Clone() const 
{
    ColumnRef* ret = new ColumnRef();
    ret->column = Utils::CopyCStringFromCString(column);
    ret->table = Utils::CopyCStringFromCString(table);
    return ret;
}

ColumnRef::~ColumnRef()
{
    delete column;
    delete table;
}

string ColumnRef::GetFieldName() const 
{
    string ret = Utils::CopyStringFromCString(column);
    if (table) {
        ret = Utils::CopyStringFromCString(table) + "." + ret;
    }
    return ret;
}

}