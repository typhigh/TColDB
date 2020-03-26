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
    void SetData(const std::string& data);
/// Operations def
public:
    FieldPtr Op(Parser::operator_type_t op, const FieldPtr other) const;
    FieldPtr Op(Parser::operator_type_t op) const;
};

using DateFieldPtr = Utils::ObjectPool<DateField>::ObjectPtr;

}