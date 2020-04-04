#pragma once
#include "../Plan.h"
#include "../PlanVisitor.h"

namespace Plan {

using PlanVisitors = std::vector<PlanVisitorPtr>;
class TreeOperations
{
public:
    /// Visit the whole tree by one visitor
    /// Return whether visitor is been accepted
    static bool VisitPlansTreeRoot(PlanPtr root, PlanVisitorPtr visitor, PlanPtr& result);

    /// Visit the whole tree by some visitor(s)
    /// Return whether exists one visitor is been accepted
    static bool VisitPlansTreeRoot(PlanPtr root, const PlanVisitors& visitors, PlanPtr& result);

private:
    /// The implement of visit tree
    static bool VisitPlansTreeImpl(PlanPtr current, const PlanVisitors& visitors, PlanPtr& result);

    /// Visit the single node
    /// Return whether visitor is been accepted
    static bool VisitPlansNode(PlanPtr current, const PlanVisitors& visitors, PlanPtr& result);
};

}