#include "CharField.h"
#include "VarcharField.h"
#include "FieldsCreator.h"
#include "../../Utils/Logger.h"
#include "../../Parser/Expression/Operations.h"
using namespace std;

namespace Columns {
    
Parser::FieldType_t CharField::GetType() const 
{
    return Parser::FIELD_TYPE_CHAR;
}

string CharField::ToString() const 
{
    return data;
}

FieldPtr CharField::Clone() const 
{
    return FieldsCreator::CreateCharField(data);
}

string CharField::GetData() const 
{
    return data;
}

void CharField::SetData(const string& data) 
{
    this->data = data;
}

bool CharField::Compare(Parser::operator_type_t op, const Field* other) const
{
    string right;
    if (other->GetType() == Parser::FIELD_TYPE_CHAR) {
        right = dynamic_cast<const CharField*>(other)->GetData();
    } else if (other->GetType() == Parser::FIELD_TYPE_VARCHAR) {
        right = dynamic_cast<const VarcharField*>(other)->GetData();
    } else {
        LOG_ERROR("Unsupported other's field type"); 
        return false;
    }

    switch (op)
    {
    case Parser::OPERATOR_EQ:   return data ==  right;
    case Parser::OPERATOR_GEQ:  return data >=  right;
    case Parser::OPERATOR_GT:   return data >   right;
    case Parser::OPERATOR_LEQ:  return data <=  right;
    case Parser::OPERATOR_LT:   return data <   right;   
    }
    LOG_ERROR("Unsupported operator type %s", Parser::Operations::ToString(op).c_str());
}

bool CharField::Query(Parser::operator_type_t op) const
{
    switch (op)
    {
    case Parser::OPERATOR_ISNULL:   return false;
    case Parser::OPERATOR_NOTNULL:  return true;   
    }
    LOG_ERROR("Unsupported operator type %s", Parser::Operations::ToString(op).c_str());
}

FieldPtr CharField::Op(Parser::operator_type_t op, const Field* other) const
{
    LOG_ERROR("Unsupported operator type %s", Parser::Operations::ToString(op).c_str());
    return NULL;    
}

FieldPtr CharField::Op(Parser::operator_type_t op) const
{
    LOG_ERROR("Unsupported operator type %s", Parser::Operations::ToString(op).c_str());
    return NULL;
}

void CharField::UpdateWithOp(Parser::operator_type_t op, const Field* other)
{
    LOG_ERROR("Unsupported operator type %s", Parser::Operations::ToString(op).c_str());    
}

void CharField::UpdateWithOp(Parser::operator_type_t op)
{
    LOG_ERROR("Unsupported operator type %s", Parser::Operations::ToString(op).c_str());
}

}