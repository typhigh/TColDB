#include "TupleDescSetEnd.h"
#include "../ScanPlan.h"
using namespace std;

namespace Plan {

bool TupleDescSetEnd::DoitPrevious() const 
{
    return false;
}

bool TupleDescSetEnd::Accept(PlanPtr plan, PlanPtr& result) const
{   
    Plans children = plan->GetChildren();
    
    /// Leaf Node
    if (children.empty()) {
        /// Only support scan plan as leaf node
        if (plan->GetType() != PLAN_SCAN) {
            LOG_ERROR("Not support plan type %s at leaf node", ToString(plan->GetType()));
            return false;
        }

        string tableName = dynamic_pointer_cast<ScanPlan>(plan)->GetTableName();
        Columns::TupleDescPtr desc = plan->GetPlanContext()->GetTableTupleDesc(tableName);
        plan->SetTupleDesc(desc);
        return true;
    }

    /// Trivial single child plan node
    if (children.size() == 1) {
        Columns::TupleDescPtr desc = children[0]->GetTupleDescCopy();
        desc->SetAlis(plan->GetRenameTable());
        if (plan->GetType == PLAN_PROJECT) {
            desc->MaskByFieldNames(plan->GetColumnsRef());
        }
        plan->SetTupleDesc(desc);
        return true;
    }

    /// Join plan
    
}

}