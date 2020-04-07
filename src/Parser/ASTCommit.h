#include "IASTNotNeedPlan.h"

namespace Parser {

class ASTCommit : public IASTNotNeedPlan
{
private:
    /* data */
public:
    ASTCommit(/* args */){}
    ~ASTCommit() {}

public:
	std::string ToString() const;
	bool IsWriteSQL() const;
    std::vector<std::string> GetTablesRef() const;
	void Execute(Executor::ExecutorContextPtr context) const;
};


}