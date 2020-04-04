#pragma once
#include "../PlanVisitor.h"
#include "../Plan.h"

namespace Plan {

class TupleDescOrigin : public PlanVisitor
{
public:
    TupleDescOrigin(/* args */) {
        SetName("TupleDescOrigin");
    }
    ~TupleDescOrigin() {}

public:
    bool DoitPrevious() const;

    /// Set the tuple(columns) desc basic information
    /// From top to down (inherent) 
    /// plan will set the fieldName by merge the parent's fieldName and itself's columnsRef
    bool Accept(PlanPtr plan, PlanPtr& result) const;
};

}