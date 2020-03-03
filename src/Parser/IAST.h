#pragma once
#include "defs.h"
namespace Parser {

// The base class for AST Node
// Use Clone to create AST Node
class IAST
{
public:
    virtual ~IAST() {};
    virtual std::string ToString() const {
        return "";
    };
    IAST() {}
};

}