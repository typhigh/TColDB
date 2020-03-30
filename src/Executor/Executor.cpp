#include "Executor.h"
#include "../Parser/SQLParser.h"
#include "../Parser/IAST.h"
#include "../Parser/IASTNeedPlan.h"
#include "../Parser/IASTNotNeedPlan.h"
#include "ExecutorContext.h"

using namespace std;

namespace Executor {

void Executor::ExecuteStatement(Common::CommandPtr command) 
{
    string sql = command->GetContent();
    
    /// Step 1: Parse
    Parser::SQLParserResult* parserResult;
    bool hasError = !Parser::SQLParser::Parse(sql, parserResult);
    
    /// If has error, just delete result and send back
    if (hasError) {
        command->SetResult(parserResult->GetErrorMsg());  
        goto Done;
    }

    /// Otherwise, we just create ExecutorPlan for the parser
    Parser::IAST* stmt = parserResult->Get();
    vector<string> tablesRef = stmt->GetTablesRef();
    ExecutorContextPtr executorContext = GetExecutorContext(tablesRef);
    
    if (stmt->NeedMakePlan()) {
        Plan::PlanContextPtr planContext = executorContext->GetPlanContext();
        Plan::PlanPtr plan = stmt->MakePlan(planContext);
//        Optimizer::optimize(plan);
        Execute(plan);
    } else {
        Execute();
    }
Done:
    /// Last step : Done
    if (parserResult != nullptr) {
        delete parserResult;
    }


}

void Executor::AddClient(Common::ClientID clientID)
{
    clients.Insert(clientID);       
}

bool Executor::IsNoneClients() const 
{
    return clients.IsEmpty();
}

ExecutorPtr Executor::GetInstance() 
{
    static ExecutorPtr executor = make_shared<Executor>();
    return executor;
}

void Executor::RemoveClient(Common::ClientID clientID)
{
    clients.Remove(clientID);
}

}