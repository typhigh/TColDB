#include "DateField.h"
using namespace std;

namespace Columns {
bool DateField::IsType(Parser::FieldType type) const
{
    return type.IsType(Parser::FIELD_TYPE_DATE);
}

string DateField::ToString() const
{
    return this->data;
}

string DateField::GetData() const 
{
    return data;
}

void DateField::SetData(const string& data) 
{
    this->data = data;
}
}