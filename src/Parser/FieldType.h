#pragma once 
#include "defs.h"
#include <string>

namespace Parser {

class FieldType
{
public:
    FieldType_t type;
    FieldType() {}
    FieldType(FieldType_t type) : type(type) {}
    std::string ToString() {
        std::string ret;
        switch (type)
        {
        case FIELD_TYPE_INT:
            ret = "FIELD_INT";
            break;
        case FIELD_TYPE_FLOAT:
            ret = "FIELD_FLOAT";
            break;
        case FIELD_TYPE_CHAR:
            ret = "FIELD_CHAR";
            break;
        case FIELD_TYPE_DATE:
            ret = "FIELD_DATA";
            break;
        case FIELD_TYPE_VARCHAR:
            ret = "FIELD_VARCHAR";
            break;
        default:
            ret = "FIELD_UNKNOWN";
            break;
        }
    }

};


}