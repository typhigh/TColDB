#include "FieldsCreator.h"
#include <memory>

using namespace std;

namespace Columns {

/// Define the ObjectPools
Utils::ObjectPool<BoolField>    FieldsCreator::BoolFieldPool    = Utils::ObjectPool<BoolField>();
Utils::ObjectPool<CharField>    FieldsCreator::CharFieldPool    = Utils::ObjectPool<CharField>();
Utils::ObjectPool<DateField>    FieldsCreator::DateFieldPool    = Utils::ObjectPool<DateField>();
Utils::ObjectPool<DoubleField>  FieldsCreator::DoubleFieldPool  = Utils::ObjectPool<DoubleField>();
Utils::ObjectPool<IntField>     FieldsCreator::IntFieldPool     = Utils::ObjectPool<IntField>();
Utils::ObjectPool<VarcharField> FieldsCreator::VarcharFieldPool = Utils::ObjectPool<VarcharField>();

void FieldsCreator::DeleteField(Field* field) 
{
    switch (field->GetType())
    {
    case Parser::FIELD_TYPE_BOOL:
        BoolFieldPool.Add(dynamic_cast<BoolField*>(field));
        break;
    case Parser::FIELD_TYPE_CHAR:
        CharFieldPool.Add(dynamic_cast<CharField*>(field));
        break;
    case Parser::FIELD_TYPE_DATE:
        DateFieldPool.Add(dynamic_cast<DateField*>(field));
        break;
    case Parser::FIELD_TYPE_FLOAT:
        DoubleFieldPool.Add(dynamic_cast<DoubleField*>(field));
        break;
    case Parser::FIELD_TYPE_INT:
        IntFieldPool.Add(dynamic_cast<IntField*>(field));
        break;
    case Parser::FIELD_TYPE_VARCHAR:
        VarcharFieldPool.Add(dynamic_cast<VarcharField*>(field));
        break;
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

}