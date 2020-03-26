#pragma once
#include "Field.h"
#include "BoolField.h"
#include "CharField.h"
#include "DateField.h"
#include "DoubleField.h"
#include "IntField.h"
#include "VarcharField.h"
#include "../../Utils/ObjectPool.h"
#include <functional>

namespace Columns {
/// FieldsCreator is not thread-safe
/// Every exector thread pool holds a FieldsCreator
class FieldsCreator
{
/// Every field type refer to a ObjectPool
private:
    Utils::ObjectPool<BoolField> BoolFieldPool;
    Utils::ObjectPool<CharField> CharFieldPool;
    Utils::ObjectPool<DateField> DateFieldPool;
    Utils::ObjectPool<DoubleField> DoubleFieldPool;
    Utils::ObjectPool<IntField> IntFieldPool;
    Utils::ObjectPool<VarcharField> VarcharFieldPool;

/// Create Operations
public:
    BoolFieldPtr CreateBoolField(bool data);
    CharFieldPtr CreateCharField(const std::string& data);
    DateFieldPtr CreateDateField(const std::string& data);
    DoubleFieldPtr CreateDoubleField(double data);
    IntFieldPtr CreateIntField(int data);
    VarcharFieldPtr CreateVarcharField(const std::string& data);
};

}