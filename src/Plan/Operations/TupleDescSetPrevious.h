#include "../PlanVisitor.h"
#include "../Plan.h"

namespace Plan {

class TupleDescSetPrevious : public PlanVisitor
{
public:
    TupleDescSetPrevious(/* args */) {
        SetName("TupleDescSetPrevious");
    }
    ~TupleDescSetPrevious() {}

public:
    bool DoitPrevious() const;

    /// Set the tuple(columns) desc basic information
    bool Accept(PlanPtr plan, PlanPtr& result) const;
};

}