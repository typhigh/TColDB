#pragma once
#include "../PlanVisitor.h"
#include "../Plan.h"

namespace Plan {

class ColumnsEliminate : public PlanVisitor
{
private:
    /* data */
public:
    ColumnsEliminate(/* args */) {
        SetName("ColumnsEliminate");
    }
    ~ColumnsEliminate() {}

public:
    bool DoitPrevious() const ;
    
    /// Set the node's parent to null to eliminate shared_ptr's circle refer
    bool VisitPlan(PlanPtr plan, PlanPtr& result) const;
};

}