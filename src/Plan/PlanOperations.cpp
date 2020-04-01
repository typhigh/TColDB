#include "PlanOperations.h"
using namespace std;

namespace Plan {
    
bool PlanOperations::VisitPlansTreeRoot(PlanPtr root, PlanVisitorPtr visitor)
{
    return VisitPlansTreeRoot(root, {visitor});
}

bool PlanOperations::VisitPlansTreeRoot(PlanPtr root, const vector<PlanVisitorPtr>& visitors)
{
    return VisitPlansTreeImpl(root, visitors);    
}

bool PlanOperations::VisitPlansTreeImpl(PlanPtr current, const vector<PlanVisitorPtr>& visitors)
{
    bool ret = false;
    Plans children = current->GetChildren();

    /// We use top-down DFS to visit the plans-tree
    /// Visit the children
    for (auto& child : children) {
        ret |= VisitPlansTreeImpl(child, visitors);
    }

    /// Visit the current node
    ret |= VisitPlansNode(current, visitors);
    return ret;
}

bool PlanOperations::VisitPlansNode(PlanPtr current, const vector<PlanVisitorPtr>& visitors)
{
    bool ret = false;
    for (auto visitor : visitors) {
        /// TODO
        ret |= current->Accept(visitor);
    }
    return ret;
}

}