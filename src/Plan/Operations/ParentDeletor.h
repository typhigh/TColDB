#include "../Plan.h"
#include "../PlanVisitor.h"

namespace Plan {

class ParentDeletor : public PlanVisitor
{
public:
    ParentDeletor() {
        SetName("PlanParentDelete");
    }

    ~ParentDeletor(){};

public:
    bool DoitPrevious() const ;
    
    /// Set the node's parent to null to eliminate shared_ptr's circle refer
    bool Accept(PlanPtr plan, PlanPtr& result) const;
};

}