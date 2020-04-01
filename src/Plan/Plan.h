#pragma once
#include "defs.h"
#include "PlanContext.h"
#include "PlanVisitor.h"
#include <memory>

namespace Plan {

class Plan
{
private:
    PlanPtr parent;
    
protected:
    PlanContextPtr context;

public:
    Plan(PlanContextPtr context) : context(context){};
    virtual ~Plan() {}

public:
    void SetPlanContext(PlanContextPtr context);
    PlanPtr GetParent();
    void SetParent(PlanPtr parent);

public:
    virtual bool Accept (PlanVisitorPtr visitor) = 0;
    virtual PlanType_t GetType() const = 0;
    
//    virtual void Execute(Executor::ExecutorContext context) const = 0;
};


}