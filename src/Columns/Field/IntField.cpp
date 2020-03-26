#include "IntField.h"
using namespace std;

namespace Columns {
bool IntField::IsType(Parser::FieldType type) const
{
    return type.IsType(Parser::FIELD_TYPE_INT);
} 

string IntField::ToString() const 
{
    return to_string(data);
}

int IntField::GetData() const 
{
    return data;
}

void IntField::SetData(int data)
{
    this->data = data;
}

}