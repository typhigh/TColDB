#include "TableFrom.h"
#include "../Utils/StringUtils.h"
using namespace std;

namespace Parser {

string TableFrom::GetTableRef() const 
{
    return Utils::CopyStringFromCString(table);
}
}