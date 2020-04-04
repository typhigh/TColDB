#include "Executor.h"
#include "../Parser/SQLParser.h"
#include "../Parser/IAST.h"
#include "../Parser/IASTNeedPlan.h"
#include "../Parser/IASTNotNeedPlan.h"
#include "../Optimizer/Optimizer.h"
#include "../Columns/TableMeta.h"

using namespace std;

namespace Executor {

bool Executor::TryExecuteStatement(Common::CommandWrapPtr command) 
{
    /// Step 1 : parse
    if (command->GetParserResult() == nullptr) {  
        string sql = command->GetContent();
        Parser::SQLParserResult* parserResult;
        bool hasError = !Parser::SQLParser::Parse(sql, parserResult);
    
        /// If has error, just delete result and send back
        if (hasError) {
            command->SetResult(parserResult->GetErrorMsg());  
            if (parserResult != nullptr) {
                delete parserResult;
            }
            return true;
        }

        /// Otherwise, set the parser result
        command->SetParserResult(parserResult->Get());
        delete parserResult;
    }

    /// Step 2: For write sql, try get lease
    Parser::IAST* parserResult = command->GetParserResult();
    vector<string> tableRefs = parserResult->GetTablesRef();
    if (parserResult->IsWriteSQL()) {
        if (tableRefs.size() != 1) {
            command->SetResult("Write sql only support just a table");
            delete parserResult;
            return true;
        }

        /// Try one write lock
        Databases::CatalogPtr catalog = Databases::Database::GetInstance()->GetCatalog();
        Columns::TableID tableID = catalog->GetTableID(tableRefs[0]);
        Columns::TablePtr table = catalog->GetTable(tableID);

        /// 
        if (table != nullptr) {
            bool fetchLock = table->TryWriteLock();
            if (!fetchLock) {
                return false;
            }
        }
    }

    /// Step 3: For read/write sql, now make plan or execute
    /// This step is on thread pool
    executePool.Submit(
        [this, command] {
            this->ExecuteStatementImpl(command);
        }
    );
    return true;
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

void Executor::ExecutePlan(Plan::PlanPtr plan, ExecutorContextPtr context, bool isReadOnly) 
{   

}

void Executor::ExecuteNoPlan(Parser::IASTNotNeedPlan* stmt, ExecutorContextPtr context, bool isReadOnly)
{

}

void Executor::ExecuteStatementImpl(Common::CommandWrapPtr command) 
{
    /// Make plan or execute
    Parser::IAST* stmt = command->GetParserResult();
    if (stmt == nullptr) {
        LOG_WARN("statemnet is null");
        return;
    }

    vector<string> tablesRef = stmt->GetTablesRef();
    bool isReadOnly = !stmt->IsWriteSQL();
    ExecutorContextPtr context = GetExecutorContext(tablesRef, isReadOnly);
    if (stmt->NeedMakePlan()) {
        Plan::PlanContextPtr planContext = context->GetPlanContext();
        Plan::PlanPtr plan = dynamic_cast<Parser::IASTNeedPlan*>(stmt)->MakePlan(planContext);
        Optimizer::Optimizer::Optimize(plan);
        ExecutePlan(plan, context, isReadOnly);
    } else {
        ExecuteNoPlan(dynamic_cast<Parser::IASTNotNeedPlan*>(stmt), context, isReadOnly);
    }

    /// Delete the stmt
    delete stmt;
}

void Executor::RemoveClient(Common::ClientID clientID)
{
    clients.Remove(clientID);
}

ExecutorContextPtr Executor::GetExecutorContext(const vector<string>& tableRefs, bool isReadOnly)
{
    Databases::CatalogPtr catalog = Databases::Database::GetInstance()->GetCatalog();
    vector<Columns::TableMetaReadOnlyPtr> tableMetas;   
    vector<Columns::TableID> tableIDs;
    for (const string& name : tableRefs) {
        Columns::TableID tableID = catalog->GetTableID(name);
        Columns::TableMetaReadOnlyPtr tableMeta = catalog->GetTable(tableID)->GetCurrentTableMeta(isReadOnly);
        tableMetas.push_back(move(tableMeta));
    }
    return make_shared<ExecutorContext>(tableMetas, tableIDs, shared_from_this());
}

}