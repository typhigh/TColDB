#pragma once
#include "defs.h"
#include "../Common/Common.h"
#include "../Optimizer/Rules/Rule.h"
#include <memory>

namespace Plan {

class Plan
{
private:
    /* data */
public:
    Plan() {};
    virtual ~Plan() {}

private:
    virtual void AcceptRule (Optimizer::RulePtr rule) = 0;
};

using PlanPtr = std::shared_ptr<Plan>;

}