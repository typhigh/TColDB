#pragma once
#include "defs.h"

namespace Plan {

class PlanVisitor
{
protected:
    std::string name;

protected:
    void SetName(const std::string& name) {
        this->name = name;
    }
public:
    std::string GetName() const {
        return name;
    }
    PlanVisitor(/* args */) {}
    virtual ~PlanVisitor() {}

public:
    /// Do it at previous step or end step in plan-tree
    virtual bool DoitPrevious() const = 0;

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


}
