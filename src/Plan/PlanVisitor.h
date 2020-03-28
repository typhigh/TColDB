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

/// Visit Plan func
public:
    virtual bool VisitPlan(PlanPtr          plan) const = 0;
    virtual bool VisitPlan(AggregatePlanPtr plan) const;
    virtual bool VisitPlan(FilterPlanPtr    plan) const;
    virtual bool VisitPlan(JoinPlanPtr      plan) const;
    virtual bool VisitPlan(ProjectPlanPtr   plan) const;
    virtual bool VisitPlan(ScanPlanPtr      plan) const;
};


}
