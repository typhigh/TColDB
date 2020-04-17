#include "LazyField.h"
#include "FieldsCreator.h"
#include "../../Parser/Expression/Operations.h"
using namespace std;

namespace Columns {

Parser::FieldType_t LazyField::GetType() const 
{
    return Parser::FIELD_TYPE_LAZY;
}

std::string LazyField::ToString() const
{
    return "";
}

FieldPtr LazyField::Clone() const
{
    LazyFieldPtr ret =  FieldsCreator::CreateLazyField();
    ret->cid = this->cid;
    ret->rid = this->rid;
    ret->tableID = this->tableID;
    return ret;
}

FieldPtr LazyField::Fetch(Executor::ExecutorContextPtr context) const
{
    context->FetchField(tableID, rid, cid);
}

bool LazyField::Compare(Parser::operator_type_t op, const Field* other) const
{
    /*TODO*/
    return false;
}

bool LazyField::Query(Parser::operator_type_t op) const
{
    switch (op)
    {
    case Parser::OPERATOR_ISNULL:   return true;
    case Parser::OPERATOR_NOTNULL:  return false;
    }
    LOG_ERROR("Unsupported operator type %s", Parser::Operations::ToString(op).c_str());
    return false;
}

FieldPtr LazyField::Op(Parser::operator_type_t op, const Field* other) const
{
    LOG_ERROR("Unsupported operator type %s", Parser::Operations::ToString(op).c_str());
}

FieldPtr LazyField::Op(Parser::operator_type_t op) const
{
    LOG_ERROR("Unsupported operator type %s", Parser::Operations::ToString(op).c_str());
}

void LazyField::UpdateWithOp(Parser::operator_type_t op, const Field* other)
{
    LOG_ERROR("Unsupported operator type %s", Parser::Operations::ToString(op).c_str());
}

void LazyField::UpdateWithOp(Parser::operator_type_t op)
{
    LOG_ERROR("Unsupported operator type %s", Parser::Operations::ToString(op).c_str());
}

}