#pragma once
#include "../Plan.h"
#include "../PlanVisitor.h"

namespace Plan {

class SetFieldsNo : public PlanVisitor
{
public:
    SetFieldsNo() {
        SetName("SetFieldsNo");
    }
    ~SetFieldsNo() {}

public:
    bool DoitPrevious() const;

    /// Set the tuple(columns) desc basic information
    /// From top to down (inherent) 
    /// plan will set the fieldName by merge the parent's fieldName and itself's columnsRef
    bool Accept(PlanPtr plan, PlanPtr& result) const;
};

}