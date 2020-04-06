#include "Convertion.h"
using namespace std;

namespace Columns {

FieldPtr Convertion::Convert(FieldPtr field, Parser::FieldType_t type)
{
    /// If type is the same, do nothing
    if (field->GetType() == type) {
        return field;
    }

    /// String term default's field type is varchar from parser
    /// But it can be date or char
    if (field->GetType() == Parser::FIELD_TYPE_VARCHAR) {
        string data = dynamic_cast<VarcharField*>(field.get())->GetData();
        if (type == Parser::FIELD_TYPE_CHAR) {
            return FieldsCreator::CreateCharField(data);
        }
        
        if (type == Parser::FIELD_TYPE_DATE) {
            return FieldsCreator::CreateDateField(data);
        }
    }

    LOG_ERROR("unsupported convertion at %s to %s", 
        Parser::ToString(field->GetType()).c_str(),
        Parser::ToString(type).c_str()
    );

    return field;
}

}