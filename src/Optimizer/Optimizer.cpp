#include "Optimizer.h"
using namespace std;

namespace Optimizer {

void Optimizer::Optimize(Plan::PlanPtr plan) 
{
    LogicalOptimize(plan);
    PhysicalOptimize(plan);
}

void Optimizer::LogicalOptimize(Plan::PlanPtr plan)
{
    
}

void Optimizer::PhysicalOptimize(Plan::PlanPtr plan)
{

}

}