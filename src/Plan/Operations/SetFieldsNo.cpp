#include "SetFieldsNo.h"
using namespace std;

namespace Plan {

bool SetFieldsNo::DoitPrevious() const 
{
    return false;
}

bool SetFieldsNo::VisitPlan(PlanPtr plan, PlanPtr& result) const
{
    Plans children = plan->GetChildren();
    
    /// Scan plan, do nothing
    if (children.empty()) {
        return true;
    }

    /// Single child
    if (children.size() == 1) {
        Columns::TupleDescPtr from = children[0]->GetTupleDescCopy();
        from->SetAlis(plan->GetRenameTable());
        Columns::TupleDescPtr to = plan->GetTupleDescCopy();
        plan->SetFieldsNo(to->GetFieldsNoByFrom(from));
        return true;
    }

    /// Join
    Columns::TupleDescPtr from = children[0]->GetTupleDescCopy();
    for (size_t i = 1; i < children.size(); ++i) {
        from->MergeOnJoin(children[i]->GetTupleDescCopy());
    }
    from->SetAlis(plan->GetRenameTable());
    Columns::TupleDescPtr to = plan->GetTupleDescCopy();
    plan->SetFieldsNo(to->GetFieldsNoByFrom(from));
    return true;
}

}