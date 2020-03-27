#include "IntField.h"
#include "FieldsCreator.h"
#include "../../Parser/Expression/Operations.h"
using namespace std;

namespace Columns {
Parser::FieldType_t IntField::GetType() const
{
    return Parser::FIELD_TYPE_INT;
}

FieldPtr IntField::Clone() const 
{
    return FieldsCreator::CreateIntField(data);
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

bool IntField::Compare(Parser::operator_type_t op, const Field* other) const 
{
    int right = dynamic_cast<const IntField*>(other)->GetData();
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

bool IntField::Query(Parser::operator_type_t op) const
{   
    switch (op)
    {
    case Parser::OPERATOR_ISNULL:   return false;
    case Parser::OPERATOR_NOTNULL:  return true;   
    }
    LOG_ERROR("Unsupported operator type %s", Parser::Operations::ToString(op).c_str());
    return false;
}
    
FieldPtr IntField::Op(Parser::operator_type_t op, const Field* other) const
{
    int right = dynamic_cast<const IntField*>(other)->GetData();
    int result;
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
    IntFieldPtr ret = move(FieldsCreator::CreateIntField());
    ret->SetData(result);
    return ret;
}

FieldPtr IntField::Op(Parser::operator_type_t op) const
{
    int result;
    switch (op)
    {
    case Parser::OPERATOR_NEGATE:
        result = -data;
        break;
    default:
        LOG_ERROR("Unsupported operator type %s", Parser::Operations::ToString(op).c_str());
        return nullptr;
    }
    IntFieldPtr ret = move(FieldsCreator::CreateIntField());
    ret->SetData(result);
    return ret;
}

void IntField::UpdateWithOp(Parser::operator_type_t op, const Field* other)
{
    int right = dynamic_cast<const IntField*>(other)->GetData();
    int result;
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

void IntField::UpdateWithOp(Parser::operator_type_t op)
{
    int result;
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