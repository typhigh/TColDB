#include "FieldsCreator.h"
#include <memory>

using namespace std;

namespace Columns {

/// Define the ObjectPools
thread_local Utils::ObjectPool<BoolField>    FieldsCreator::BoolFieldPool    = Utils::ObjectPool<BoolField>("BoolFieldPool");
thread_local Utils::ObjectPool<CharField>    FieldsCreator::CharFieldPool    = Utils::ObjectPool<CharField>("CharFieldPool");
thread_local Utils::ObjectPool<DateField>    FieldsCreator::DateFieldPool    = Utils::ObjectPool<DateField>("DateFieldPool");
thread_local Utils::ObjectPool<DoubleField>  FieldsCreator::DoubleFieldPool  = Utils::ObjectPool<DoubleField>("DoubleFieldPool");
thread_local Utils::ObjectPool<IntField>     FieldsCreator::IntFieldPool     = Utils::ObjectPool<IntField>("IntFieldPool");
thread_local Utils::ObjectPool<NullField>    FieldsCreator::NullFieldPool    = Utils::ObjectPool<NullField>("NullFieldPool");
thread_local Utils::ObjectPool<VarcharField> FieldsCreator::VarcharFieldPool = Utils::ObjectPool<VarcharField>("VarcharFieldPool");

void FieldsCreator::DeleteField(Field* field) 
{
    switch (field->GetType())
    {
    case Parser::FIELD_TYPE_BOOL:   return BoolFieldPool.Add(dynamic_cast<BoolField*>(field));
    case Parser::FIELD_TYPE_CHAR:   return CharFieldPool.Add(dynamic_cast<CharField*>(field));
    case Parser::FIELD_TYPE_DATE:   return DateFieldPool.Add(dynamic_cast<DateField*>(field));
    case Parser::FIELD_TYPE_FLOAT:  return DoubleFieldPool.Add(dynamic_cast<DoubleField*>(field));
    case Parser::FIELD_TYPE_INT:    return IntFieldPool.Add(dynamic_cast<IntField*>(field));
    case Parser::FIELD_TYPE_NULL:   return NullFieldPool.Add(dynamic_cast<NullField*>(field));
    case Parser::FIELD_TYPE_VARCHAR:return VarcharFieldPool.Add(dynamic_cast<VarcharField*>(field));
    default:
        LOG_ERROR("Unknown field type");
    }   
}

BoolFieldPtr FieldsCreator::CreateBoolField() 
{
    return BoolFieldPtr(
        BoolFieldPool.Get(), 
        [] (Field* field) {DeleteField(field);}
    );
}

CharFieldPtr FieldsCreator::CreateCharField()
{
    return CharFieldPtr(
        CharFieldPool.Get(),
        [] (Field* field) {DeleteField(field);}  
    );
}

DateFieldPtr FieldsCreator::CreateDateField()
{
    return DateFieldPtr(
        DateFieldPool.Get(),
        [] (Field* field) {DeleteField(field);}
    );
}

DoubleFieldPtr FieldsCreator::CreateDoubleField()
{
    return DoubleFieldPtr(
        DoubleFieldPool.Get(),
        [] (Field* field) {DeleteField(field);}  
    );
}

IntFieldPtr FieldsCreator::CreateIntField()
{
    return IntFieldPtr(
        IntFieldPool.Get(),
        [] (Field* field) {DeleteField(field);}  
    );
}

NullFieldPtr FieldsCreator::CreateNullField()
{
    return NullFieldPtr(
        NullFieldPool.Get(),
        [] (Field* field) {DeleteField(field);}
    );
}
VarcharFieldPtr FieldsCreator::CreateVarcharField()
{
    return VarcharFieldPtr(
        VarcharFieldPool.Get(),
        [] (Field* field) {DeleteField(field);}  
    );
}

BoolFieldPtr FieldsCreator::CreateBoolField(bool data)
{
    BoolFieldPtr ret = CreateBoolField();
    ret->SetData(data);
    return ret;
}

CharFieldPtr FieldsCreator::CreateCharField(const std::string& data)
{
    CharFieldPtr ret = CreateCharField();
    ret->SetData(data);
    return ret;
}

DateFieldPtr FieldsCreator::CreateDateField(const std::string& data)
{
    DateFieldPtr ret = CreateDateField();
    ret->SetData(data);
    return ret;
}

DoubleFieldPtr FieldsCreator::CreateDoubleField(const DoubleField::ValT data)
{
    DoubleFieldPtr ret = CreateDoubleField();
    ret->SetData(data);
    return ret;
}

IntFieldPtr FieldsCreator::CreateIntField(int data)
{
    IntFieldPtr ret = CreateIntField();
    ret->SetData(data);
    return ret;
}

VarcharFieldPtr FieldsCreator::CreateVarcharField(const std::string& data)
{
    VarcharFieldPtr ret = CreateVarcharField();
    ret->SetData(data);
    return ret;
}

size_t FieldsCreator::EstimateMemoryUse()
{
    return BoolFieldPool.EstimateMemoryUseSize()
         + CharFieldPool.EstimateMemoryUseSize()
         + DateFieldPool.EstimateMemoryUseSize()
         + DoubleFieldPool.EstimateMemoryUseSize()
         + IntFieldPool.EstimateMemoryUseSize()
         + NullFieldPool.EstimateMemoryUseSize()
         + VarcharFieldPool.EstimateMemoryUseSize();  
}

}