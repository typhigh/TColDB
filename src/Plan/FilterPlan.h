#pragma once
#include "defs.h"
#include "Plan.h"
#include "../Executor/Predicator.h"
#include "../Optimizer/Rules/Rule.h"
namespace Plan {

class FilterPlan : public Plan
{
private:
    /* data */
    Executor::PredicatorPtr predicator;
    PlanPtr subPlan;

public:
    FilterPlan() {}
    virtual ~FilterPlan() {}
    void SetPredicator(Parser::ExprNode* cond);
    void SetPredicator(Executor::PredicatorPtr predicator);
    void SetSubPlan(PlanPtr subPlan);
    
private:
    void AcceptRule(Optimizer::RulePtr rule);
};
using FilterPlanPtr = std::shared_ptr<FilterPlan>;

}