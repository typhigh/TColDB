#pragma once
#include "IAST.h"

namespace Parser {

class IASTNeedPlan : public IAST
{
private:
    /* data */
public:
    IASTNeedPlan(/* args */)  {}
    virtual std::string ToString() const = 0;
    bool NeedMakePlan() const {return true;}
    virtual Plan::PlanPtr MakePlan() const = 0;
    virtual bool IsWriteSQL() const = 0;
    virtual std::vector<std::string> GetTablesRef() const = 0;
    virtual ~IASTNeedPlan() {}
};


}
