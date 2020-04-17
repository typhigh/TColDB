#include "Tuple.h"
#include "../Utils/StringUtils.h"
#include "Field/LazyField.h"

using namespace std;

namespace Columns {

FieldPtr Tuple::GetFieldCopy(int fieldNo, Executor::ExecutorContextPtr context)
{
    if (fieldNo < 0 || fieldNo > fields.size()) {
        LOG_ERROR("fieldNo is out of range");
        return nullptr;
    }   

    if (fields[fieldNo]->GetType() == Parser::FIELD_TYPE_LAZY) {
        fields[fieldNo] = move(dynamic_cast<LazyField*>(fields[fieldNo].get())->Fetch(context));
    }
    return fields[fieldNo]->Clone();
}

FieldPtr Tuple::GetFieldCopy(const std::string& fieldName, int& fieldNo, Executor::ExecutorContextPtr context)
{
    if (!desc->GetFieldNo(fieldName, fieldNo)) {
        LOG_ERROR("No such fieldName %s", fieldName.c_str());
        return nullptr;
    }
    return GetFieldCopy(fieldNo, context);
}

}