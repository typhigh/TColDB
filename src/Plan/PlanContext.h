#include "Plan.h"
#include "defs.h"
namespace Plan {

class PlanContext
{
private:
    /* data */
public:
    PlanContext(/* args */);
    ~PlanContext();
};
using PlanContextPtr = std::shared_ptr<PlanContext>;

}