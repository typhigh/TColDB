#include "ColumnRef.h"
#include "../Utils/StringUtils.h"
#include <cstring>

using namespace std;

namespace Parser {

ColumnRef* ColumnRef::Clone() const 
{
    ColumnRef* ret = new ColumnRef();
    ret->column = Utils::CopyFromCString(column);
    ret->table = Utils::CopyFromCString(table);
    return ret;
}

}