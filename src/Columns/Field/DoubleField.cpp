#include "DoubleField.h"
using namespace std;

namespace Columns {
bool DoubleField::IsType(Parser::FieldType type) const
{
    return type.IsType(Parser::FIELD_TYPE_FLOAT);
} 

string DoubleField::ToString() const 
{
    return to_string(data);
}

DoubleField::ValT DoubleField::GetData() const 
{
    return data;
}

}