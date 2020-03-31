#pragma once
#include "IAST.h"

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
    virtual Plan::PlanPtr MakePlan(Plan::PlanContextPtr planContext) const = 0;
};


}
