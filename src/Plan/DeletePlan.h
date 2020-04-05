#pragma once
#include "Plan.h"
namespace Plan {

class DeletePlan : public Plan, std::enable_shared_from_this<DeletePlan>
{
private:
    PlanPtr subPlan;
    
public:
    DeletePlan(PlanContextPtr context) : Plan(context) {}
    ~DeletePlan() {}
    void SetSubPlan(PlanPtr subPlan);

public:
    bool Accept (PlanVisitorPtr visitor, PlanPtr& result);
    PlanType_t GetType() const;
    Plans GetChildren();
    FieldNames GetColumnsRef() const;
};

}