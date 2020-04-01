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
    bool Accept (PlanVisitorPtr visitor);
    PlanType_t GetType() const;
};

using UpdatePlanPtr = std::shared_ptr<UpdatePlan>;
}