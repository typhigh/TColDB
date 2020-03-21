#pragma once
#include "../Common/Common.h"
#include "../Optimizer/Rule.h"
#include <memory>

namespace Plan {

class Plan
{
private:
    /* data */
public:
    Plan();
    virtual ~Plan() {}

    virtual void AcceptRule (Optimizer::RulePtr rule) = 0;
};

using PlanPtr = std::shared_ptr<Plan>;

}