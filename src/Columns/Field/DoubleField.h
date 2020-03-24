#pragma once
#include "Field.h"

namespace Columns {

class DoubleField : public Field
{
private:
    /* data */
    double data;
    
public:
    DoubleField(/* args */) {}
    ~DoubleField() {}
    bool IsType(Parser::FieldType type) const;
    std::string ToString() const;
};


}
