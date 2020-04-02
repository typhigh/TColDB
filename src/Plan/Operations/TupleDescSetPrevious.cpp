#include "TupleDescSetPrevious.h"

using namespace std;
namespace Plan {

bool TupleDescSetPrevious::DoitPrevious() const 
{
    return true;
}

bool TupleDescSetPrevious::Accept(PlanPtr plan, PlanPtr& result) const
{
    PlanPtr parent = plan->GetParent();
    
    if (plan == nullptr) {
        
    }    
}

}