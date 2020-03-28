#pragma once
#include <memory>

namespace Plan {
class AggregatePlan;
class FilterPlan;
class JoinPlan;
class Plan;
class ProjectPlan;
class ScanPlan;
class PlanVisitor;

using PlanPtr           = std::shared_ptr<Plan>;
using AggregatePlanPtr  = std::shared_ptr<AggregatePlan>;
using FilterPlanPtr     = std::shared_ptr<FilterPlan>;
using JoinPlanPtr       = std::shared_ptr<JoinPlan>;
using ProjectPlanPtr    = std::shared_ptr<ProjectPlan>;
using ScanPlanPtr       = std::shared_ptr<ScanPlan>;
using PlanVisitorPtr    = std::shared_ptr<PlanVisitor>;

enum PlanType_t {
    PLAN_AGGREGATE,
    PLAN_FILTER,
    PLAN_JOIN,
    PLAN_PROJECT,
    PLAN_SCAN,
    PLAN_TABLESCAN,
    PLAN_INDEXSCAN,
    PLAN_ORDER
};

}