#pragma once
#include "defs.h"
#include "Plan.h"
#include "../Executor/Operators/Predicator.h"
#include "../Optimizer/Rules/Rule.h"
namespace Plan {

class FilterPlan : public Plan, public std::enable_shared_from_this<FilterPlan>
{
private:
    /* data */
    Executor::PredicatorPtr predicator;
    PlanPtr subPlan;

public:
    FilterPlan(PlanContextPtr context) : Plan(context) {}
    virtual ~FilterPlan() {}

public:
    void SetPredicator(Parser::ExprNode* cond);
    void SetPredicator(Executor::PredicatorPtr predicator);
    Executor::PredicatorPtr GetPredicator();
    void SetSubPlan(PlanPtr subPlan);
    
public:
    std::string ToString(const std::string& prefix) const;
    bool Accept (PlanVisitorPtr visitor, PlanPtr& result);
    PlanType_t GetType() const;
    Plans GetChildren();
    FieldNames GetColumnsRef() const;
};
using FilterPlanPtr = std::shared_ptr<FilterPlan>;

}