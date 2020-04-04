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

class Rule : public Plan::PlanVisitor
{
public:
    /// Do it at previous step or end step in plan-tree
    bool DoitPrevious() const {return false;}

    /// Visit Plan func
    virtual bool VisitPlan(Plan::PlanPtr          plan, Plan::PlanPtr& result) const = 0;
    virtual bool VisitPlan(Plan::AggregatePlanPtr plan, Plan::PlanPtr& result) const;
    virtual bool VisitPlan(Plan::DeletePlanPtr    plan, Plan::PlanPtr& result) const;
    virtual bool VisitPlan(Plan::FilterPlanPtr    plan, Plan::PlanPtr& result) const;
    virtual bool VisitPlan(Plan::JoinPlanPtr      plan, Plan::PlanPtr& result) const;
    virtual bool VisitPlan(Plan::ProjectPlanPtr   plan, Plan::PlanPtr& result) const;
    virtual bool VisitPlan(Plan::ScanPlanPtr      plan, Plan::PlanPtr& result) const;
    virtual bool VisitPlan(Plan::UpdatePlan       plan, Plan::PlanPtr& result) const;
};
using RulePtr = std::shared_ptr<Rule>;
using Rules = std::vector<RulePtr>;

}