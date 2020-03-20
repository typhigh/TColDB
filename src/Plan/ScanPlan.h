#include "Plan.h"
#include "../Columns/TupleDesc.h"
#include <vector>
#include <string>
namespace Plan {

class ScanPlan : public Plan
{
private:
    /* data */
    std::string tableName;
    Columns::TupleDescPtr desc;
    std::vector<int> columns;
public:
    ScanPlan(/* args */);
    virtual ~ScanPlan() {};

    virtual void RuleOptimize (Optimizer::RulePtr rule); 
};

using ScanPlanPtr = std::shared_ptr<ScanPlan>;
}