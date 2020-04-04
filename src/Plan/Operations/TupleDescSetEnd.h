#pragma once
#include "../PlanVisitor.h"
#include "../Plan.h"

namespace Plan {

class TupleDescSetEnd : public PlanVisitor
{
private:
    /* data */
public:
    TupleDescSetEnd() {
        SetName("TupleDescSetEnd");
    }
    ~TupleDescSetEnd() {}

public: 
    bool DoitPrevious() const;

    /// Set the tuple(columns) desc helper information
    /// From down to top
    /// plan will set tupledesc
    bool Accept(PlanPtr plan, PlanPtr& result) const;
};

}