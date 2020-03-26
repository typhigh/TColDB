#include "VarcharField.h"
using namespace std;

namespace Columns {
bool VarcharField::IsType(Parser::FieldType type) const
{
    return type.IsType(Parser::FIELD_TYPE_VARCHAR);
} 

string VarcharField::ToString() const 
{
    return data;
}

string VarcharField::GetData() const 
{
    return data;
}

void VarcharField::SetData(const string& data) 
{
    this->data = data;
}

}