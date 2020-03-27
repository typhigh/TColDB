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
    static Utils::ObjectPool<BoolField> BoolFieldPool;
    static Utils::ObjectPool<CharField> CharFieldPool;
    static Utils::ObjectPool<DateField> DateFieldPool;
    static Utils::ObjectPool<DoubleField> DoubleFieldPool;
    static Utils::ObjectPool<IntField> IntFieldPool;
    static Utils::ObjectPool<VarcharField> VarcharFieldPool;

/// Delete Operation
private:
    static void DeleteField(Field* field);

/// Create Operations
public:
    static BoolFieldPtr CreateBoolField();
    static CharFieldPtr CreateCharField();
    static DateFieldPtr CreateDateField();
    static DoubleFieldPtr CreateDoubleField();
    static IntFieldPtr CreateIntField();
    static VarcharFieldPtr CreateVarcharField();

    static BoolFieldPtr CreateBoolField(bool data);
    static CharFieldPtr CreateCharField(const std::string& data);
    static DateFieldPtr CreateDateField(const std::string& data);
    static DoubleFieldPtr CreateDoubleField(const DoubleField::ValT data);
    static IntFieldPtr CreateIntField(int data);
    static VarcharFieldPtr CreateVarcharField(const std::string& data);
};

}