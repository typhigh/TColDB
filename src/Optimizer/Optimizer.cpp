#include "Optimizer.h"
using namespace std;

namespace Optimizer {


Rules rules = vector<RulePtr> {
    make_shared<ConstOptimize>(),
    make_shared<PredicatePushDown>()
};


void Optimizer::Optimize(Plan::PlanPtr& plan) 
{
    LogicalOptimize(plan);
    PhysicalOptimize(plan);
}

void Optimizer::LogicalOptimize(Plan::PlanPtr& plan)
{
    /// select * xxx don't need columns eliminate 
    bool NeedColumnsEliminate = true;
    if (plan->IsWithSelectAll()) {
        NeedColumnsEliminate = false;
    }
}

void Optimizer::PhysicalOptimize(Plan::PlanPtr& plan)
{

}

}