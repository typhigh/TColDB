#pragma once
#include "defs.h"
#include "Plan.h"
#include "../Executor/Predicator.h"
#include "../Optimizer/Rules/Rule.h"
namespace Plan {

class FilterPlan : public Plan, public std::enable_shared_from_this<FilterPlan>
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
    Executor::PredicatorPtr GetPredicator();
    void SetSubPlan(PlanPtr subPlan);
    
public:
    bool Accept (PlanVisitorPtr visitor);
    PlanType_t GetType() const;
};
using FilterPlanPtr = std::shared_ptr<FilterPlan>;

}