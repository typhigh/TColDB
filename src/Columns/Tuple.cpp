#include "Tuple.h"
#include "../Utils/StringUtils.h"
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

FieldPtr Tuple::GetFieldCopy(const std::string& fieldName, int& fieldNo) const
{
    if (!desc->GetFieldNo(fieldName, fieldNo)) {
        LOG_ERROR("No such fieldName %s", fieldName.c_str());
        return nullptr;
    }
    return GetFieldCopy(fieldNo);
}

}