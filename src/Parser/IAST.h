#pragma once
#include "defs.h"

namespace Parser {

// The base class for AST Node
// Use Clone to create AST Node
class IAST
{
private:
    /* data */
public:
    virtual ~IAST() = default;
    IAST() = default;
    IAST(const IAST &) = default;
    IAST & operator=(const IAST &) = default;
    
    virtual IASTPtr Clone() const = 0;
};

using IASTPtr = std::shared_ptr<IAST>;



}