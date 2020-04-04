#pragma once
#include <memory>
#include <string>
#include <vector>
#include "../Utils/Logger.h"
namespace Plan {
class AggregatePlan;
class DeletePlan;
class FilterPlan;
class JoinPlan;
class Plan;
class ProjectPlan;
class ScanPlan;
class UpdatePlan;
class PlanVisitor;
class PlanContext;

using PlanPtr           = std::shared_ptr<Plan>;
using AggregatePlanPtr  = std::shared_ptr<AggregatePlan>;
using DeletePlanPtr     = std::shared_ptr<DeletePlan>;
using FilterPlanPtr     = std::shared_ptr<FilterPlan>;
using JoinPlanPtr       = std::shared_ptr<JoinPlan>;
using ProjectPlanPtr    = std::shared_ptr<ProjectPlan>;
using ScanPlanPtr       = std::shared_ptr<ScanPlan>;
using UpdatePlanPtr     = std::shared_ptr<UpdatePlan>;
using PlanVisitorPtr    = std::shared_ptr<PlanVisitor>;
using PlanContextPtr    = std::shared_ptr<PlanContext>;

enum PlanType_t {
    PLAN_AGGREGATE,
    PLAN_FILTER,
    PLAN_JOIN,
    PLAN_PROJECT,
    PLAN_SCAN,
    PLAN_TABLESCAN,
    PLAN_INDEXSCAN,
    PLAN_ORDER,
    PLAN_UPDATE,
    PLAN_DELETE
};

inline std::string ToString(PlanType_t type)
{
    switch (type)
    {
    case PLAN_AGGREGATE:    return "AGGREGATE";
    case PLAN_FILTER:       return "FILTER";
    case PLAN_JOIN:         return "JOIN";
    case PLAN_PROJECT:      return "PROJECT";
    case PLAN_SCAN:         return "SCAN";
    case PLAN_ORDER:        return "ORDER";
    case PLAN_UPDATE:       return "UPDATE";
    case PLAN_DELETE:       return "DELETE";
    default:                return "UNKNOWN";
    }
}

using FieldNames = std::vector<std::string>;
}