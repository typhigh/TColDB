#include "DoubleField.h"
#include "../../Parser/Expression/Operations.h"
#include "FieldsCreator.h"

using namespace std;

namespace Columns {
Parser::FieldType_t DoubleField::GetType() const
{
    return Parser::FIELD_TYPE_FLOAT;
}

string DoubleField::ToString() const 
{
    return to_string(data);
}

FieldPtr DoubleField::Clone() const 
{
    return FieldsCreator::CreateDoubleField(data);
}

DoubleField::ValT DoubleField::GetData() const 
{
    return data;
}

void DoubleField::SetData(DoubleField::ValT data) 
{
    this->data = data;
}

bool DoubleField::Compare(Parser::operator_type_t op, const Field* other) const 
{
    ValT right = dynamic_cast<const DoubleField*>(other)->GetData();
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

bool DoubleField::Query(Parser::operator_type_t op) const
{   
    switch (op)
    {
    case Parser::OPERATOR_ISNULL:   return false;
    case Parser::OPERATOR_NOTNULL:  return true;   
    }
    LOG_ERROR("Unsupported operator type %s", Parser::Operations::ToString(op).c_str());
    return false;
}
    
FieldPtr DoubleField::Op(Parser::operator_type_t op, const Field* other) const
{
    ValT right = dynamic_cast<const DoubleField*>(other)->GetData();
    ValT result;
    switch (op)
    {
    case Parser::OPERATOR_ADD: 
        result = data + right;
        break;
    case Parser::OPERATOR_DIV:
        result = data / right;
        break;
    case Parser::OPERATOR_MINUS:
        result = data - right;
        break;
    case Parser::OPERATOR_MUL:
        result = data * right;
        break;
    default:
        LOG_ERROR("Unsupported operator type %s", Parser::Operations::ToString(op).c_str());
        return nullptr;
    }
    DoubleFieldPtr ret = move(FieldsCreator::CreateDoubleField());
    ret->SetData(result);
    return ret;
}

FieldPtr DoubleField::Op(Parser::operator_type_t op) const
{
    ValT result;
    switch (op)
    {
    case Parser::OPERATOR_NEGATE:
        result = -data;
        break;
    default:
        LOG_ERROR("Unsupported operator type %s", Parser::Operations::ToString(op).c_str());
        return nullptr;
    }
    DoubleFieldPtr ret = move(FieldsCreator::CreateDoubleField());
    ret->SetData(result);
    return ret;
}

void DoubleField::UpdateWithOp(Parser::operator_type_t op, const Field* other)
{
    ValT right = dynamic_cast<const DoubleField*>(other)->GetData();
    ValT result;
    switch (op)
    {
    case Parser::OPERATOR_ADD: 
        result = data + right;
        break;
    case Parser::OPERATOR_DIV:
        result = data / right;
        break;
    case Parser::OPERATOR_MINUS:
        result = data - right;
        break;
    case Parser::OPERATOR_MUL:
        result = data * right;
        break;
    default:
        LOG_ERROR("Unsupported operator type %s", Parser::Operations::ToString(op).c_str());
        return;
    }
    SetData(result);
}

void DoubleField::UpdateWithOp(Parser::operator_type_t op)
{
    ValT result;
    switch (op)
    {
    case Parser::OPERATOR_NEGATE:
        result = -data;
        break;
    default:
        LOG_ERROR("Unsupported operator type %s", Parser::Operations::ToString(op).c_str());
    }
    SetData(result);
}

}