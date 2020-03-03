#pragma once
#include "defs.h"
#include <string>
namespace Parser {

class TermType
{
public: 
    TermType_t type;

    TermType(TermType_t type) : type(type) {}
    std::string ToString() {
        std::string ret;
        switch (type)
        {
        case TERM_NONE:
            ret = "TERM_NONE";
            break;
        case TERM_COLUMN_REF:
            ret = "COLUMN_REF";
            break;
        case TERM_INT:
            ret = "TERM_INT";
            break;
        case TERM_STRING:
            ret = "TERM_STRING";
            break;
        case TERM_DATE:
            ret = "TERM_DATA";
            break;        
        case TERM_FLOAT:
            ret = "TERM_FLOAT";
            break;
        case TERM_BOOL:
            ret = "TERM_BOOL";
            break;
        case TERM_LITERAL_LIST:
            ret = "TERM_LITERAL_LIST";
            break;
        case TERM_NULL:
            ret = "TERM_NULL";
            break;
        default:
            ret = "UNKNOWN";
            break;
        }
        return ret;
    }
};


}