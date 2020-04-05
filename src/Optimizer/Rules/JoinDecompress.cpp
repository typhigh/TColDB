#include "JoinDecompress.h"
#include "../../Plan/PlansCreator.h"
using namespace std;
using namespace Plan;

namespace Optimizer {

bool JoinDecompress::VisitPlan(PlanPtr          plan, PlanPtr& result) const
{
    return false;
}

bool JoinDecompress::VisitPlan(JoinPlanPtr      plan, PlanPtr& result) const
{
    /// Use greed al
    Plans children = plan->GetChildren();
    vector<TableInfo> infos;
    for (size_t i = 0; i < children.size(); ++i) {
        PlanPtr child = children[i];
        string tableName = child->GetTupleDescCopy()->GetTableName();
        Columns::TableID tableID = plan->GetPlanContext()->GetTableID(tableName);
        infos.push_back({
            plan->GetPlanContext()->GetTupleCount(tableID),
            tableID,
            child    
        });
    }
    sort(infos.begin(), infos.end());
    vector<PlanPtr> plans;
    size_t n = infos.size();
    for (size_t i = 0; i < n; ++i) {
        plans[i] = infos[i].plan;
    }

    for (size_t i = 0; i + 2 < n; ++i) {
        JoinPlanPtr newPlan = PlansCreator::CreateJoinPlan(plan->GetPlanContext());
        newPlan->SetSubPlans({plans[i], plans[i+1]});
        plans[i+1] = newPlan;
    }

    plan->SetSubPlans({plans[n-2], plans[n-1]});
    return false;
}

}