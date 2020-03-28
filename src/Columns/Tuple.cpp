#include "Tuple.h"
using namespace std;

namespace Columns {

FieldPtr Tuple::GetFieldCopy(int fieldNo) const
{
    if (fieldNo < 0 || fieldNo > fields.size()) {
        LOG_ERROR("fieldNo is out of range");
        return nullptr;
    }   
    return fields[fieldNo]->Clone();
}

FieldPtr Tuple::GetFieldCopy(const std::string fieldName) const
{
    /*
    for (size_t i = 0; i < fields.size(); ++i) {
        if (desc->
    }
    */
}

}