#include "ParentDeletor.h"
using namespace std;

namespace Plan {

bool ParentDeletor::DoitPrevious() const 
{
    return false;
}

bool ParentDeletor::VisitPlan(PlanPtr plan, PlanPtr& result) const
{
    plan->SetParent(nullptr);
    return true;
}

}