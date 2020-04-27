#include "Executor.h"
#include "../Parser/SQLParser.h"
#include "../Parser/IAST.h"
#include "../Parser/IASTNeedPlan.h"
#include "../Parser/IASTNotNeedPlan.h"
#include "../Optimizer/Optimizer.h"
#include "../Columns/TableMeta.h"
#include "../Utils/StringUtils.h"

using namespace std;

namespace Executor {

void Executor::Consume(Common::CommandWrapPtr& cmd) 
{
    commandQueue.WaitAndPop(cmd);
}

void Executor::Produce(Common::CommandWrapPtr cmd)
{
    commandQueue.Push(cmd);
}

void Executor::StartUp()
{
    executePool.StartUp();
}

void Executor::ShutDown()
{
    executePool.ShutDown();
}

bool Executor::TryExecuteStatement(Common::CommandWrapPtr command) 
{
    /// Step 1 : parse
    if (command->GetParserResult() == nullptr) {  
        string sql = command->GetContent();
        Parser::SQLParserResult* parserResult = new Parser::SQLParserResult();
        bool hasError = !Parser::SQLParser::Parse(sql, parserResult);
    
        /// If has error, just delete result and send back
        if (hasError) {
            string errorMsg = Utils::CopyStringFromCString(parserResult->GetErrorMsg());
            LOG_INFO("Parser get wrong %s", errorMsg.c_str());
            command->SetResult(errorMsg);  
            if (parserResult != nullptr) {
                delete parserResult;
            }
            LOG_INFO("YES, right here");
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
        if (tableRefs.size() > 1) {
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
    LOG_INFO("add client %lu", clientID);
}

void Executor::RemoveClient(Common::ClientID clientID)
{
    clients.Remove(clientID);
    
    /// Send a null command to avoid dead wait
    Produce(nullptr); 
    LOG_INFO("remove client %lu", clientID);
}

bool Executor::IsNoneClients() const 
{
    return clients.IsEmpty();
}

Databases::DatabasePtr Executor::GetDB()
{
    return db;
}

void Executor::SumbitTableMeta(Columns::TableID tableID, Columns::TableMetaWritePtr tableMeta)
{
    db->GetCatalog()->GetTable(tableID)->SetCurrentWriteTableMeta(tableMeta);
}

void Executor::SubmitCommit(Columns::TableID tableID)
{
    db->Commit(tableID);
}

ExecutorPtr Executor::GetInstance() 
{
    static ExecutorPtr executor = make_shared<Executor>();
    return executor;
}

void Executor::ExecutePlan(Plan::PlanPtr plan, ExecutorContextPtr context, bool isReadOnly) 
{   
    LOG_DEBUG("Plan tree is like: \n%s", plan->ToString("").c_str());
    
    /**/
    context->SubmitResult("Done");
}

void Executor::ExecuteNoPlan(Parser::IASTNotNeedPlan* stmt, ExecutorContextPtr context, bool isReadOnly)
{
    stmt->Execute(context);
    LOG_DEBUG("Yes oh 2");
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
    ExecutorContextPtr context = GetExecutorContext(tablesRef, command, isReadOnly);
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
    if (!isReadOnly) {
        for (auto& tableName: tablesRef) {
            Databases::CatalogPtr catalog = Databases::Database::GetInstance()->GetCatalog();
            Columns::TableID tableID = catalog->GetTableID(tableName);
            Columns::TablePtr table = catalog->GetTable(tableID);
            table->ReleaseWriteLock();
        }
        LOG_DEBUG("Release the lease");
    }
}

ExecutorContextPtr Executor::GetExecutorContext(const vector<string>& tableRefs, Common::CommandWrapPtr command, bool isReadOnly)
{
    Databases::CatalogPtr catalog = Databases::Database::GetInstance()->GetCatalog();
    vector<Columns::TableMetaReadOnlyPtr> tableMetas;   
    vector<Columns::TableID> tableIDs;

    for (const string& name : tableRefs) {
        Columns::TableID tableID = catalog->GetTableID(name);
        Columns::TableMetaReadOnlyPtr tableMeta = catalog->GetTable(tableID)->GetCurrentTableMeta(isReadOnly);
        tableMetas.push_back(move(tableMeta));
        tableIDs.push_back(tableID);
    }
    return make_shared<ExecutorContext>(tableMetas, tableIDs, tableRefs, command, shared_from_this(), this->db->GetBufferPool());
}

}