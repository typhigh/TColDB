#pragma once
#include "Field.h"
#include "BoolField.h"
#include "CharField.h"
#include "DateField.h"
#include "DoubleField.h"
#include "IntField.h"
#include "NullField.h"
#include "VarcharField.h"
#include "../../Utils/ObjectPool.h"
#include <functional>
#include <thread>

namespace Columns {
/// FieldsCreator is not thread-safe
/// Every exector thread pool holds a FieldsCreator
class FieldsCreator
{
/// Every field type refer to a ObjectPool
private:
    thread_local static Utils::ObjectPool<BoolField> BoolFieldPool;
    thread_local static Utils::ObjectPool<CharField> CharFieldPool;
    thread_local static Utils::ObjectPool<DateField> DateFieldPool;
    thread_local static Utils::ObjectPool<DoubleField> DoubleFieldPool;
    thread_local static Utils::ObjectPool<IntField> IntFieldPool;
    thread_local static Utils::ObjectPool<NullField> NullFieldPool;
    thread_local static Utils::ObjectPool<VarcharField> VarcharFieldPool;

/// Delete Operation
private:
    static void DeleteField(Field* field);

/// Create Operations
public:
    static BoolFieldPtr     CreateBoolField();
    static CharFieldPtr     CreateCharField();
    static DateFieldPtr     CreateDateField();
    static DoubleFieldPtr   CreateDoubleField();
    static IntFieldPtr      CreateIntField();
    static NullFieldPtr     CreateNullField();
    static VarcharFieldPtr  CreateVarcharField();

    static BoolFieldPtr     CreateBoolField(bool data);
    static CharFieldPtr     CreateCharField(const std::string& data);
    static DateFieldPtr     CreateDateField(const std::string& data);
    static DoubleFieldPtr   CreateDoubleField(const DoubleField::ValT data);
    static IntFieldPtr      CreateIntField(int data);
    static VarcharFieldPtr  CreateVarcharField(const std::string& data);

public:
    /// Estimate the memory use
    static size_t EstimateMemoryUse();
};

}