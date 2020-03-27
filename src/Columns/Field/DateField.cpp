#include "DateField.h"
#include "FieldsCreator.h"
#include "../../Parser/Expression/Operations.h"
using namespace std;

namespace Columns {
Parser::FieldType_t DateField::GetType() const
{
    return Parser::FIELD_TYPE_DATE;
}

string DateField::ToString() const
{
    return this->data;
}

FieldPtr DateField::Clone() const 
{
    return FieldsCreator::CreateDateField(data);
}

string DateField::GetData() const 
{
    return data;
}

void DateField::SetData(const string& data) 
{
    this->data = data;
}

bool DateField::Compare(Parser::operator_type_t op, const Field* other) const
{
    /*TODO*/
    return true;
}

bool DateField::Query(Parser::operator_type_t op) const
{
    switch (op)
    {
    case Parser::OPERATOR_ISNULL:   return false;
    case Parser::OPERATOR_NOTNULL:  return true;   
    }
    LOG_ERROR("Unsupported operator type %s", Parser::Operations::ToString(op).c_str());
    return false;
}

FieldPtr DateField::Op(Parser::operator_type_t op, const Field* other) const
{
    LOG_ERROR("Unsupported operator type %s", Parser::Operations::ToString(op).c_str());
    return nullptr;
}

FieldPtr DateField::Op(Parser::operator_type_t op) const
{
    LOG_ERROR("Unsupported operator type %s", Parser::Operations::ToString(op).c_str());
    return nullptr;
}

void DateField::UpdateWithOp(Parser::operator_type_t op, const Field* other) 
{
    LOG_ERROR("Unsupported operator type %s", Parser::Operations::ToString(op).c_str());
}

void DateField::UpdateWithOp(Parser::operator_type_t op)
{
    LOG_ERROR("Unsupported operator type %s", Parser::Operations::ToString(op).c_str());
}

}