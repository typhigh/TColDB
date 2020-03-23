#pragma once
#include "../../Plan/defs.h"
#include <string>
#include <memory>
namespace Optimizer {

class Rule
{
private:
    /* data */

public:
    Rule(/* args */) {}
    virtual ~Rule() {}

public:
    virtual void AcceptPlan(Plan::Plan& plan);
};
using RulePtr = std::shared_ptr<Rule>;

}