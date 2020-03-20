#pragma once
#include "defs.h"
#include "../Plan/Plan.h"
namespace Parser {

// The base class for AST Node
// Use Clone to create AST Node
class IAST
{
public:
    virtual ~IAST() {};
    virtual std::string ToString() const = 0;
    virtual Plan::PlanPtr MakePlan() const = 0;
    IAST() {}
};

}