#include "Plan.h"
#include "PlanVisitor.h"

namespace Plan {

class PlanOperations
{
public:
    /// Visit the whole tree by one visitor
    /// Return whether visitor is been accepted
    static bool VisitPlansTreeRoot(PlanPtr root, PlanVisitorPtr visitor);

    /// Visit the whole tree by some visitor(s)
    /// Return whether exists one visitor is been accepted
    static bool VisitPlansTreeRoot(PlanPtr root, const std::vector<PlanVisitorPtr>& visitors);

private:
    /// The implement of visit tree
    static bool VisitPlansTreeImpl(PlanPtr current, const std::vector<PlanVisitorPtr>& visitors);

    /// Visit the single node
    /// Return whether visitor is been accepted
    static bool VisitPlansNode(PlanPtr current, const std::vector<PlanVisitorPtr>& visitors);
};

}