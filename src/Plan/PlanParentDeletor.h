#include "PlanVisitor.h"
#include "Plan.h"
namespace Plan {

class PlanParentDeletor : public PlanVisitor
{
public:
    PlanParentDeletor() {
        SetName("PlanParentDelete");
    }

    ~PlanParentDeletor(){};

public:
    bool Accept(PlanPtr plan) const {
        plan->SetParent(nullptr);
    }
};

}