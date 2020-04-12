#include "Optimizer.h"
#include "../Plan/Operations/TupleDescOrigin.h"
#include "../Plan/Operations/ColumnsEliminate.h"
#include "../Plan/Operations/ParentDeletor.h"
#include "../Plan/Operations/TreeOperations.h"
using namespace std;
using namespace Plan;

namespace Optimizer {


PlanVisitors rules = {
    make_shared<ConstOptimize>(),
    make_shared<PredicatePushDown>(),
};


void Optimizer::Optimize(PlanPtr& plan) 
{
    LogicalOptimize(plan);
    PhysicalOptimize(plan);
    LOG_DEBUG("Optimize done");
}

void Optimizer::LogicalOptimize(PlanPtr& plan)
{
    /// select * xxx don't need columns eliminate 
    bool NeedColumnsEliminate = true;
    if (plan->IsWithSelectAll()) {
        NeedColumnsEliminate = false;
    }

    /// Decompress join node
    PlanVisitorPtr joinDecompress = make_shared<JoinDecompress>();
    TreeOperations::VisitPlansTreeRoot(plan, joinDecompress, plan);
    
    /// Set origin tuple for each plan node
    PlanVisitorPtr tupleDescOrigin = make_shared<TupleDescOrigin>();
    TreeOperations::VisitPlansTreeRoot(plan, tupleDescOrigin, plan);

    /// Maybe need columns eliminate
    if (NeedColumnsEliminate) {
        PlanVisitorPtr columnsEliminate = make_shared<ColumnsEliminate>();
        TreeOperations::VisitPlansTreeRoot(plan, columnsEliminate, plan);
    }

    /// Logical rules optimized
    TreeOperations::VisitPlansTreeRoot(plan, rules, plan);
    
    PlanVisitorPtr parentDeletor = make_shared<ParentDeletor>();
    TreeOperations::VisitPlansTreeRoot(plan, parentDeletor, plan);
}

void Optimizer::PhysicalOptimize(PlanPtr& plan)
{

}

}