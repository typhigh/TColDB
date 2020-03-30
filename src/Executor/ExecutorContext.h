#pragma once
#include "defs.h"
#include "../Plan/PlanContext.h"
namespace Executor {

class ExecutorContext
{
private:
    /* data */
    
public:
    ExecutorContext(/* args */) {}
    ~ExecutorContext() {}

    Plan::PlanContextPtr GetPlanContext() const;
};

using ExecutorContextPtr = std::shared_ptr<ExecutorContext>;
}