#pragma once
#include "IAST.h"
#include "../Plan/Plan.h"
#include "../Plan/PlanContext.h"

namespace Parser {

class IASTNeedPlan : public IAST
{
private:
    /* data */
public:
    IASTNeedPlan(/* args */)  {}
    virtual ~IASTNeedPlan() {}
    virtual std::string ToString() const = 0;
    bool NeedMakePlan() const {return true;}
    virtual bool IsWriteSQL() const = 0;
    virtual std::vector<std::string> GetTablesRef() const = 0;
    virtual Plan::PlanPtr MakePlan(Plan::PlanContextPtr context) const = 0;
};


}
