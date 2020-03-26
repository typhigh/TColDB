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

string CharField::GetData() const 
{
    return data;
}

void CharField::SetData(const string& data) 
{
    this->data = data;
}

}