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
};


}