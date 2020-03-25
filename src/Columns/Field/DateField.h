#include "Field.h"

namespace Columns {

class DateField : public Field
{
private:
    /* data */
    std::string data;
    
public:
    DateField(/* args */) {}
    ~DateField() {}
    bool IsType(Parser::FieldType type) const;
    std::string ToString() const;
    std::string GetData() const;

/// Operations def
public:
    FieldPtr Op(Parser::operator_type_t op, const FieldPtr other) const;
    FieldPtr Op(Parser::operator_type_t op) const;
};
using DateFieldPtr = std::shared_ptr<DateField>;

}