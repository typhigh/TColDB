#include "ColumnsEliminate.h"
#include "../../Utils/VectorUtils.h"
#include "../defs.h"
namespace Plan {

bool ColumnsEliminate::DoitPrevious() const 
{
    return true;
}
 
bool ColumnsEliminate::VisitPlan(PlanPtr plan, PlanPtr& result) const
{
    FieldNames need = plan->GetColumnsRef();
    PlanPtr parent = plan->GetParent();
    if (parent != nullptr) {
        FieldNames parentNeed = parent->GetFieldNames();
        Utils::MergeVectors(need, parentNeed);
    }
    plan->SetFieldNames(need);
    Columns::TupleDescPtr desc = plan->GetTupleDescCopy();
    desc->MaskByFieldNames(need);
    plan->SetTupleDesc(desc);
}

}