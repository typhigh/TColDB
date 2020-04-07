#pragma once
#include "IAST.h"
#include "../Executor/ExecutorContext.h"
#include "../Plan/Plan.h"

namespace Parser {

class IASTNotNeedPlan : public IAST
{
private:
    /* data */
public:
    IASTNotNeedPlan(/* args */) {}
    virtual ~IASTNotNeedPlan() {}
    virtual std::string ToString() const = 0;
    bool NeedMakePlan() const {return false;}
    virtual bool IsWriteSQL() const = 0;
    virtual std::vector<std::string> GetTablesRef() const = 0;
    virtual void Execute(Executor::ExecutorContextPtr context) const = 0;

private:
    Plan::PlanPtr MakePlan() const {}
};



}