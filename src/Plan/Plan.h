#pragma once
#include "defs.h"
#include "PlanContext.h"
#include "../Common/Common.h"
#include "../Optimizer/Rules/Rule.h"
#include <memory>

namespace Plan {

class Plan
{
private:
    PlanPtr parent;

public:
    Plan() {};
    virtual ~Plan() {}
    void SetPlanContext(PlanContextPtr planContext);
    void SetPlanContext(const std::vector<std::string>& tableNames, bool ReadOnly);
    PlanPtr GetParent();
    void SetParent(PlanPtr parent);
    
protected:
    PlanContextPtr planContext;

private:
    virtual void AcceptRule (Optimizer::RulePtr rule) = 0;
    virtual PlanType_t GetType() const = 0;

};


}