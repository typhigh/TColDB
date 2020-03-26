#include "BoolField.h"
#include "FieldsCreator.h"
#include "../../Parser/Expression/Operations.h"
#include "../../Utils/Logger.h"
using namespace std;

namespace Columns {
bool BoolField::IsType(Parser::FieldType type) const
{
    return type.IsType(Parser::FIELD_TYPE_BOOL);
} 

string BoolField::ToString() const 
{
    return to_string(data);
}

bool BoolField::GetData() const 
{
    return data;
}

void BoolField::SetData(bool data) 
{
    this->data = data;
}

FieldPtr BoolField::Op(Parser::operator_type_t op, const FieldPtr other) const 
{
    bool ret;
    bool left = GetData();
    bool right = dynamic_cast<BoolField*>(other.get())->GetData();
    switch (op)
    {
    case Parser::OPERATOR_AND:
        ret = left && right;
        break;
    case Parser::OPERATOR_OR:
        ret = left || right;
        break;
    case Parser::OPERATOR_EQ:
        ret = (left == right);
        break;
    case Parser::OPERATOR_NEQ:
        ret = (left != right);
        break;
    default:
        LOG_ERROR("Unsupported operator type %s", Parser::Operations::ToString(op).c_str());
//        return FieldPtr();
    }
//    return move(FieldsCreator::CreateBoolField(ret));
}

FieldPtr BoolField::Op(Parser::operator_type_t op) const
{
    bool ret;
    bool left = GetData();
    switch (op)
    {
    case Parser::OPERATOR_NEGATE:
        ret = !left;
        break;
    case Parser::OPERATOR_NOTNULL:
        ret = true;
        break;
    case Parser::OPERATOR_ISNULL:
        ret = false;
        break;
    default:
        LOG_ERROR("Unsupported operator type %s", Parser::Operations::ToString(op).c_str());
//        return FieldPtr();
    }
//    return FieldsCreator::CreateBoolField(ret);
}
}