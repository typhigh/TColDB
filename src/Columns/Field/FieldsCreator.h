#pragma once
#include "Field.h"
#include "BoolField.h"
#include "CharField.h"
#include "DateField.h"
#include "DoubleField.h"
#include "IntField.h"
#include "VarcharField.h"

namespace Columns {
class FieldsCreator
{
public:
    static BoolFieldPtr CreateBoolField(bool data);
    static CharFieldPtr CreateCharField(const std::string& data);
    static DateFieldPtr CreateDateField(const std::string& data);
    static DoubleFieldPtr CreateDoubleField(double data);
    static IntFieldPtr CreateIntField(int data);
    static VarcharFieldPtr CreateVarcharField(const std::string& data);
};

}