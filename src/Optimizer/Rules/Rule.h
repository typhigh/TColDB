#pragma once
#include "../../Plan/defs.h"
#include "../../Plan/PlanVisitor.h"
#include "../../Plan/Plan.h"
#include "../../Plan/AggregatePlan.h"
#include "../../Plan/FilterPlan.h"
#include "../../Plan/JoinPlan.h"
#include "../../Plan/ProjectPlan.h"
#include "../../Plan/ScanPlan.h"
#include <string>
#include <memory>
namespace Optimizer {

class Rule : public PlanVisitor
{
public:
    /// Do it at previous step or end step in plan-tree
    bool DoitPrevious() const {return false;}

    /// Visit Plan func
    virtual bool VisitPlan(PlanPtr          plan, PlanPtr& result) const = 0;
    virtual bool VisitPlan(AggregatePlanPtr plan, PlanPtr& result) const;
    virtual bool VisitPlan(DeletePlanPtr    plan, PlanPtr& result) const;
    virtual bool VisitPlan(FilterPlanPtr    plan, PlanPtr& result) const;
    virtual bool VisitPlan(JoinPlanPtr      plan, PlanPtr& result) const;
    virtual bool VisitPlan(ProjectPlanPtr   plan, PlanPtr& result) const;
    virtual bool VisitPlan(ScanPlanPtr      plan, PlanPtr& result) const;
    virtual bool VisitPlan(UpdatePlan       plan, PlanPtr& result) const;
};
using RulePtr = std::shared_ptr<Rule>;
using Rules = std::vector<RulePtr>;

}