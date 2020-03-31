#pragma once
#include "defs.h"
#include "ExecutorContext.h"
#include "../Parser/IAST.h"
#include "../Common/CommandWrap.h"
#include "../Databases/Database.h"
#include "../Utils/ThreadPool.h"
#include "../Utils/ConcurrentHashSet.h"
#include <memory>

namespace Executor {

/// The execute engine class
/// It holds an executePool, supports One Write Multiple Read on every table 
/// Executor is a single instance

class Executor : public std::enable_shared_from_this<Executor>
{
private:
    Utils::ThreadPool executePool;
    Utils::ConcurrentHashSet<Common::ClientID> clients;
    static constexpr size_t runningThreadNums = 4;

public:
    Executor() : executePool("executePool", runningThreadNums) {}
    ~Executor() {}

public:
    /// Try execute the statement
    /// If write lock is hold by other, return false
    bool TryExecuteStatement(Common::CommandWrapPtr stmt);
    
    /// Add Client by server
    void AddClient(Common::ClientID clientID);

    /// Is none clients
    bool IsNoneClients() const;

    /// Get the instance of executor
    static ExecutorPtr GetInstance();

private:
    /// Execute a statement (command)
    void ExecuteStatementImpl(Common::CommandWrapPtr stmt);

    /// Remove Client
    void RemoveClient(Common::ClientID clientID);

    /// Execute the optimized plan
    void ExecutePlan(Plan::PlanPtr plan, ExecutorContextPtr context, bool isReadOnly);

    /// Execute the sql statement without plan
    void ExecuteNoPlan(Parser::IASTNotNeedPlan* stmt, ExecutorContextPtr context, bool isReadOnly);

    /// Get the context of executor now
    ExecutorContextPtr GetExecutorContext(const std::vector<std::string>& tableRefs, bool isReadOnly) const;
};

}