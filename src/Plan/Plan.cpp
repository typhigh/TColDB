#include "Plan.h"
using namespace std;

namespace Plan {

void Plan::SetPlanContext(PlanContextPtr planContext) 
{
    this->planContext = planContext;
}

void Plan::SetPlanContext(const vector<string>& tableNames, bool readOnly)
{
    this->planContext = make_shared<PlanContext>(tableNames, readOnly);
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