#include "TupleDescOrigin.h"
#include "../../Utils/VectorUtils.h"
#include "../JoinPlan.h"
using namespace std;
namespace Plan {

bool TupleDescOrigin::DoitPrevious() const 
{
    return false;
}

bool TupleDescOrigin::VisitPlan(PlanPtr plan, PlanPtr& result) const
{
    Plans children = plan->GetChildren();
    
    /// Leaf node No need to set
    if (children.empty()) {
        return true;
    }

    /// Trivial node
    if (children.size() == 1) {
        Columns::TupleDescPtr desc = children[0]->GetTupleDescCopy();
        desc->SetAlis(plan->GetRenameTable());
        if (plan->GetType() == PLAN_PROJECT) {
            desc->MaskByFieldNames(plan->GetColumnsRef());
        }
        plan->SetTupleDesc(desc);
        return true;
    }
    
    /// Join node
    Columns::TupleDescPtr desc = children[0]->GetTupleDescCopy();
    desc->FillFieldName();
    for (size_t i = 1; i < children.size(); ++i) {
        Columns::TupleDescPtr other = children[i]->GetTupleDescCopy();
        other->FillFieldName();
        desc->MergeOnJoin(other);
    }
    plan->SetTupleDesc(desc);
    return true;
}

}