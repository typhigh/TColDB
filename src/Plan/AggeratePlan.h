#pragma once
#include "Plan.h"
#include "../Executor/Aggerator.h"
#include <vector>
namespace Plan {

class AggeratePlan : public Plan
{
private:
    /* data */
    std::vector<Executor::Aggerator> aggs;

public:
    AggeratePlan(/* args */) {};
    virtual ~AggeratePlan() {};

    virtual void RuleOptimize (Optimizer::RulePtr rule) ;
};


}