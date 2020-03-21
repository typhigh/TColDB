#include "Plan.h"
#include "../Columns/TupleDesc.h"
#include "../Parser/TableFrom.h"
#include <vector>
#include <string>
namespace Plan {

class ScanPlan : public Plan
{
private:
    /* data */
    std::string tableName;
    Columns::TupleDescPtr desc;
    // helper
    std::vector<int> columns;
public:
    ScanPlan(Parser::TableFrom* tableFrom);
    virtual ~ScanPlan() {};
    virtual void AcceptRule (Optimizer::RulePtr rule); 
};

using ScanPlanPtr = std::shared_ptr<ScanPlan>;
}