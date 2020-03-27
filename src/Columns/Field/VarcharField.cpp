#include "VarcharField.h"
#include "FieldsCreator.h"
#include "../../Parser/Expression/Operations.h"
using namespace std;

namespace Columns {
Parser::FieldType_t VarcharField::GetType() const
{
    return Parser::FIELD_TYPE_VARCHAR;
}

string VarcharField::ToString() const 
{
    return data;
}

FieldPtr VarcharField::Clone() const 
{
    return FieldsCreator::CreateVarcharField(data);
}

string VarcharField::GetData() const 
{
    return data;
}

void VarcharField::SetData(const string& data) 
{
    this->data = data;
}


bool VarcharField::Compare(Parser::operator_type_t op, const Field* other) const
{
    string right;
    if (other->GetType() == Parser::FIELD_TYPE_CHAR) {
        right = dynamic_cast<const VarcharField*>(other)->GetData();
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

bool VarcharField::Query(Parser::operator_type_t op) const
{
    switch (op)
    {
    case Parser::OPERATOR_ISNULL:   return false;
    case Parser::OPERATOR_NOTNULL:  return true;   
    }
    LOG_ERROR("Unsupported operator type %s", Parser::Operations::ToString(op).c_str());
}

FieldPtr VarcharField::Op(Parser::operator_type_t op, const Field* other) const
{
    LOG_ERROR("Unsupported operator type %s", Parser::Operations::ToString(op).c_str());
    return NULL;    
}

FieldPtr VarcharField::Op(Parser::operator_type_t op) const
{
    LOG_ERROR("Unsupported operator type %s", Parser::Operations::ToString(op).c_str());
    return NULL;
}

void VarcharField::UpdateWithOp(Parser::operator_type_t op, const Field* other)
{
    LOG_ERROR("Unsupported operator type %s", Parser::Operations::ToString(op).c_str());    
}

void VarcharField::UpdateWithOp(Parser::operator_type_t op)
{
    LOG_ERROR("Unsupported operator type %s", Parser::Operations::ToString(op).c_str());
}

}