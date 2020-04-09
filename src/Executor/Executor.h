#pragma once
#include "defs.h"
#include "ExecutorContext.h"
#include "../Parser/IAST.h"
#include "../Parser/IASTNeedPlan.h"
#include "../Parser/IASTNotNeedPlan.h"
#include "../Common/CommandWrap.h"
#include "../Databases/Database.h"
#include "../Utils/ThreadPool.h"
#include "../Utils/ConcurrentHashSet.h"
#include "../Utils/ProductConsumerQueue.h"
#include <memory>

namespace Executor {

/// The execute engine class
/// It holds an executePool, supports One Write Multiple Read on every table 
/// Executor is a single instance

class Executor : public std::enable_shared_from_this<Executor>
{
private:
    Utils::ProductConsumerQueue<Common::CommandWrapPtr> commandQueue;
    Utils::ThreadPool executePool;
    Utils::ConcurrentHashSet<Common::ClientID> clients;
    static constexpr size_t runningThreadNums = 4;
    Databases::DatabasePtr db;

public:
    Executor() : executePool("executePool", runningThreadNums) {
        db = Databases::Database::GetInstance();
    }
    ~Executor() {}

/// commandQueue
public:
    void Produce(Common::CommandWrapPtr cmd);
    void Consume(Common::CommandWrapPtr& cmd);

/// Execute func
public:
    /// Start up (mainly executePool)
    void StartUp();
    
    /// Shut down (mainly executePool)
    void ShutDown();

    /// Try execute the statement
    /// If write lock is hold by other, return false
    bool TryExecuteStatement(Common::CommandWrapPtr stmt);
    
    /// Add Client by server
    void AddClient(Common::ClientID clientID);

    /// Remove Client
    void RemoveClient(Common::ClientID clientID);
    
    /// Is none clients
    bool IsNoneClients() const;

    /// Get the instance of executor
    static ExecutorPtr GetInstance();

    void SumbitTableMeta(Columns::TableID tableID, Columns::TableMetaWritePtr tableMeta);

    void SubmitCommit(Columns::TableID tableID); 

private:
    /// Execute a statement (command)
    /// Note: statement has been parsed.
    void ExecuteStatementImpl(Common::CommandWrapPtr stmt);

    /// Execute the optimized plan
    void ExecutePlan(Plan::PlanPtr plan, ExecutorContextPtr context, bool isReadOnly);

    /// Execute the sql statement without plan
    void ExecuteNoPlan(Parser::IASTNotNeedPlan* stmt, ExecutorContextPtr context, bool isReadOnly);

    /// Get the context of executor now
    ExecutorContextPtr GetExecutorContext(const std::vector<std::string>& tableRefs, Common::CommandWrapPtr command, bool isReadOnly);

};

}