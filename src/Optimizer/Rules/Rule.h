#pragma once
#include "../../Plan/defs.h"
#include "../../Plan/PlanVisitor.h"
#include "../../Plan/Plan.h"
#include "../../Plan/AggregatePlan.h"
#include "../../Plan/FilterPlan.h"
#include "../../Plan/JoinPlan.h"
#include "../../Plan/ProjectPlan.h"
#include "../../Plan/ScanPlan.h"
#include <string>
#include <memory>
namespace Optimizer {

using Rule = Plan::PlanVisitor;
using RulePtr = Plan::PlanVisitorPtr;

}