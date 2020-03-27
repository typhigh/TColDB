#include "BoolField.h"
#include "FieldsCreator.h"
#include "../../Parser/Expression/Operations.h"
#include "../../Utils/Logger.h"
using namespace std;

namespace Columns {

Parser::FieldType_t BoolField::GetType() const
{
    return Parser::FIELD_TYPE_BOOL;
} 

string BoolField::ToString() const 
{
    return to_string(data);
}

FieldPtr BoolField::Clone() const 
{
    return FieldsCreator::CreateBoolField(data);
}

bool BoolField::GetData() const 
{
    return data;
}

void BoolField::SetData(bool data) 
{
    this->data = data;
}

bool BoolField::Compare(Parser::operator_type_t op, const Field* other) const 
{
    bool result;
    bool left = data;
    bool right = dynamic_cast<const BoolField*>(other)->GetData();
    switch (op)
    {
    case Parser::OPERATOR_EQ:
        result = (left == right);
        break;
    case Parser::OPERATOR_NEQ:
        result = (left != right);
        break;
    default:
        LOG_ERROR("Unsupported operator type %s", Parser::Operations::ToString(op).c_str());
        return false;
    }
    return result;
}

bool BoolField::Query(Parser::operator_type_t op) const 
{
    bool result;
    switch (op)
    {
    case Parser::OPERATOR_NOTNULL:
        result = true;
        break;
    case Parser::OPERATOR_ISNULL:
        result = false;
        break;
    default:
        LOG_ERROR("Unsupported operator type %s", Parser::Operations::ToString(op).c_str());
        return false;
    }
    return result;
}

FieldPtr BoolField::Op(Parser::operator_type_t op, const Field* other) const
{
    bool result;
    bool left = GetData();
    bool right = dynamic_cast<const BoolField*>(other)->GetData();
    switch (op)
    {
    case Parser::OPERATOR_AND:
        result = left && right;
        break;
    case Parser::OPERATOR_OR:
        result = left || right;
        break;
    default:
        LOG_ERROR("Unsupported operator type %s", Parser::Operations::ToString(op).c_str());
        return nullptr;
    }

    BoolFieldPtr ret = move(FieldsCreator::CreateBoolField());
    ret->SetData(result);
    return ret;
}

FieldPtr BoolField::Op(Parser::operator_type_t op) const
{
    BoolFieldPtr ret;
    bool result = GetData();
    switch (op)
    {
    case Parser::OPERATOR_NOT:
        result = !result;
        break;
    default:
        LOG_ERROR("Unsupported operator type %s", Parser::Operations::ToString(op).c_str());
        return nullptr;
    }
    ret = move(FieldsCreator::CreateBoolField());
    ret->SetData(result);
    return ret;
}

void BoolField::UpdateWithOp(Parser::operator_type_t op, const Field* other) 
{
    bool result;
    bool left = GetData();
    bool right = dynamic_cast<const BoolField*>(other)->GetData();
    switch (op)
    {
    case Parser::OPERATOR_AND:
        result = left && right;
        break;
    case Parser::OPERATOR_OR:
        result = left || right;
        break;
    default:
        LOG_ERROR("Unsupported operator type %s", Parser::Operations::ToString(op).c_str());
        return;
    }
    SetData(result);
}

void BoolField::UpdateWithOp(Parser::operator_type_t op) 
{
    bool result = GetData();
    switch (op)
    {
    case Parser::OPERATOR_NOT:
        result = !result;
        break;
    default:
        LOG_ERROR("Unsupported operator type %s", Parser::Operations::ToString(op).c_str());
    }
    SetData(result);
}

}