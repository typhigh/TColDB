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
};


}
