#include "Plan.h"
using namespace std;

namespace Plan {

void Plan::SetPlanContext(PlanContextPtr context) 
{
    this->context = context;
}

PlanPtr Plan::GetParent() 
{
    return parent;
}

void Plan::SetParent(PlanPtr parent) 
{
    this->parent = parent;
}

}