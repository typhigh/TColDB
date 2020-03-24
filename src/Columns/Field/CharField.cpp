#include "CharField.h"
using namespace std;

namespace Columns {
bool CharField::IsType(Parser::FieldType type) const
{
    return type.IsType(Parser::FIELD_TYPE_CHAR);
} 

string CharField::ToString() const 
{
    return data;
}
}