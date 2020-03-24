#pragma once
#include "Field.h"

namespace Columns {

class IntField : public Field
{
private:
    /* data */
    int data;
    
public:
    IntField(/* args */) {}
    ~IntField() {}
    bool IsType(Parser::FieldType type) const;
    std::string ToString() const;
};


}
