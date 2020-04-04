#include "TreeOperations.h"
using namespace std;

namespace Plan {
    
bool TreeOperations::VisitPlansTreeRoot(PlanPtr root, PlanVisitorPtr visitor, PlanPtr& result)
{
    return VisitPlansTreeRoot(root, {visitor}, result);
}

bool TreeOperations::VisitPlansTreeRoot(PlanPtr root, const PlanVisitors& visitors, PlanPtr& result)
{
    return VisitPlansTreeImpl(root, visitors, result);    
}

bool TreeOperations::VisitPlansTreeImpl(PlanPtr current, const PlanVisitors& visitors, PlanPtr& result)
{
    bool ret = false;
    Plans children = current->GetChildren();

    /// We use top-down DFS to visit the plans-tree
    /// Visit the children
    for (size_t i = 0; i < children.size(); ++i) {
        PlanPtr child = children[i];
        ret |= VisitPlansTreeImpl(child, visitors, children[i]);
        
        /// Maybe the sub-root changed, re-visit the new root
        if (children[i] != child) {
            --i;
        }
    }

    /// Now every sub-tree is the most optimized
    /// Visit the current node
    /// If it can be optimized and sub-root changed, just break and re-visit the new root
    ret |= VisitPlansNode(current, visitors, result);
    return ret;
}

bool TreeOperations::VisitPlansNode(PlanPtr current, const PlanVisitors& visitors, PlanPtr& result)
{
    bool ret =  false;
    for (PlanVisitorPtr visitor : visitors) {
        ret |= current->Accept(visitor, result);
    }
}

}