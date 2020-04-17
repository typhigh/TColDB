#pragma once
#include "Field.h"
#include "../RowID.h"
#include "../ColID.h"
#include "../TableID.h"
#include "../../Executor/ExecutorContext.h"

namespace Columns {

class LazyField : public Field
{
private:
    RowID rid;
    ColID cid;
    TableID tableID;

public:
    LazyField(/* args */) {}
    ~LazyField() {}
    Parser::FieldType_t GetType() const;
    std::string ToString() const;
    FieldPtr Clone() const;
    FieldPtr Fetch(Executor::ExecutorContextPtr context) const;

public:
    bool Compare(Parser::operator_type_t op, const Field* other) const;
    bool Query(Parser::operator_type_t op) const;

    FieldPtr Op(Parser::operator_type_t op, const Field* other) const;
    FieldPtr Op(Parser::operator_type_t op) const;

    void UpdateWithOp(Parser::operator_type_t op, const Field* other);
    void UpdateWithOp(Parser::operator_type_t op); 
};

using LazyFieldPtr = std::unique_ptr<LazyField, FieldDeleteFunc>;
}