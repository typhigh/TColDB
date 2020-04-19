#pragma once
#include "../defs.h"
#include "../../Parser/defs.h"
#include "../../Utils/ObjectPool.h"
#include <memory>

namespace Columns {

/// A base Field Class 
class Field
{
private:
    /* data */
public:
    Field(/* args */) {}
    virtual ~Field() {}

    /// Get the field type
    virtual Parser::FieldType_t GetType() const = 0;
    
    /// Get the string-format
    virtual std::string ToString() const = 0;
    
    /// Clone (deep copy)
    virtual FieldPtr Clone() const = 0;
    
/// Operation between this and another field
public:
    /// Compare with other field
    virtual bool Compare(Parser::operator_type_t op, const Field* other) const = 0;
    virtual bool Query(Parser::operator_type_t op) const = 0;

    /// Op with other field, return a new field 
    virtual FieldPtr Op(Parser::operator_type_t op, const Field* other) const = 0;
    
    /// Op seft, return a new field
    virtual FieldPtr Op(Parser::operator_type_t op) const = 0;
    
    /// Update this data with op (and other field)
    virtual void UpdateWithOp(Parser::operator_type_t op, const Field* other) = 0;
    virtual void UpdateWithOp(Parser::operator_type_t op) = 0;
};

}