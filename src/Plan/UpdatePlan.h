#pragma once
#include "Plan.h"
#include "PlanContext.h"
#include "../Parser/ExprNode.h"
#include "../Executor/Operators/Updator.h"
namespace Plan {

class UpdatePlan : public Plan , std::enable_shared_from_this<UpdatePlan>
{
private:
    /* data */
    std::string fieldName;
    Executor::UpdatorPtr updator;
    PlanPtr subPlan;

public:
    UpdatePlan(const std::string& fieldName, Parser::ExprNode* value, PlanContextPtr context);
    ~UpdatePlan() {}
    void SetSubPlan(PlanPtr subPlan);

public:
    std::string ToString(const std::string& prefix) const;
    bool Accept (PlanVisitorPtr visitor, PlanPtr& result);
    PlanType_t GetType() const;
    Plans GetChildren();
    FieldNames GetColumnsRef() const;
};

using UpdatePlanPtr = std::shared_ptr<UpdatePlan>;
}