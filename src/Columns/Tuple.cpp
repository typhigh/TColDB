#include "Tuple.h"
#include "../Utils/StringUtils.h"
using namespace std;

namespace Columns {

FieldPtr Tuple::GetFieldCopyImpl(const string& fieldName, int& fieldNo) const 
{
    for (size_t i = 0; i < fields.size(); ++i) {
        if (desc->GetFieldName(i) == fieldName) {
            fieldNo = i;
            return fields[i]->Clone();
        }
    }
    return nullptr;
}

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
    /// Try match fully first
    FieldPtr ret = GetFieldCopyImpl(fieldName, fieldNo);
    if (ret == nullptr) {
        /// Try match string after point
        ret = GetFieldCopyImpl(Utils::GetPointAfter(fieldName), fieldNo);
    }
    return ret;
}

}