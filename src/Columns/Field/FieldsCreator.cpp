#include "FieldsCreator.h"
#include <memory>

using namespace std;

namespace Columns {

BoolFieldPtr FieldsCreator::CreateBoolField(bool data) 
{
    BoolFieldPtr ret = move(BoolFieldPool.Get());
    ret->SetData(data);
    return ret;
}

CharFieldPtr FieldsCreator::CreateCharField(const string& data)
{
    CharFieldPtr ret = move(CharFieldPool.Get());
    ret->SetData(data);
    return ret;
}
}