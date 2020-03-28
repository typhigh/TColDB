#include "NullField.h"
#include "FieldsCreator.h"
#include "../../Parser/Expression/Operations.h"

using namespace std;

namespace Columns {
Parser::FieldType_t NullField::GetType() const 
{
    return Parser::FIELD_TYPE_NULL;
}

std::string NullField::ToString() const
{
    return "";
}

FieldPtr NullField::Clone() const
{
    return FieldsCreator::CreateNullField();
}

bool NullField::Compare(Parser::operator_type_t op, const Field* other) const
{
    /*TODO*/
    return false;
}

bool NullField::Query(Parser::operator_type_t op) const
{
    switch (op)
    {
    case Parser::OPERATOR_ISNULL:   return true;
    case Parser::OPERATOR_NOTNULL:  return false;
    }
    LOG_ERROR("Unsupported operator type %s", Parser::Operations::ToString(op).c_str());
    return false;
}

FieldPtr NullField::Op(Parser::operator_type_t op, const Field* other) const
{
    LOG_ERROR("Unsupported operator type %s", Parser::Operations::ToString(op).c_str());
}

FieldPtr NullField::Op(Parser::operator_type_t op) const
{
    LOG_ERROR("Unsupported operator type %s", Parser::Operations::ToString(op).c_str());
}

void NullField::UpdateWithOp(Parser::operator_type_t op, const Field* other)
{
    LOG_ERROR("Unsupported operator type %s", Parser::Operations::ToString(op).c_str());
}

void NullField::UpdateWithOp(Parser::operator_type_t op)
{
    LOG_ERROR("Unsupported operator type %s", Parser::Operations::ToString(op).c_str());
}

}