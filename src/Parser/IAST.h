#pragma once
#include "defs.h"

namespace Parser {

// The base class for AST Node
// Use Clone to create AST Node
class IAST
{
public:
    virtual ~IAST() {};
    virtual std::string ToString() const = 0;
    virtual bool NeedMakePlan() const = 0;
    virtual bool IsWriteSQL() const = 0;
    virtual std::vector<std::string> GetTablesRef() const = 0;
    IAST() {}
};

}