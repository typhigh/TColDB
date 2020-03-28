#pragma once
namespace Plan {
class AggregatePlan;
class FilterPlan;
class JoinPlan;
class Plan;
class ProjectPlan;
class ScanPlan;

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

class Plan;
using PlanPtr = std::shared_ptr<Plan>;


}