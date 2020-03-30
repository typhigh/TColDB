#pragma once
#include "defs.h"
#include "../Common/Command.h"
#include "../Databases/Database.h"
#include "../Utils/ThreadPool.h"
#include "../Utils/ConcurrentHashSet.h"
#include <memory>

namespace Executor {

/// The execute engine class
/// It holds an executePool, supports One Write Multiple Read on every table 
/// Executor is a single instance

class Executor
{
private:
    Utils::ThreadPool executePool;
    Utils::ConcurrentHashSet<Common::ClientID> clients;
    static constexpr size_t runningThreadNums = 4;

public:
    Executor() : executePool("executePool", runningThreadNums) {}
    ~Executor() {}

public:
    /// Execute a statement (command)
    void ExecuteStatement(Common::CommandPtr stmt);
    
    /// Add Client by server
    void AddClient(Common::ClientID clientID);

    /// Is none clients
    bool IsNoneClients() const;

    /// Get the instance of executor
    static ExecutorPtr GetInstance();

private:
    
    /// Remove Client
    void RemoveClient(Common::ClientID clientID);

    /// Get the context of executor now
    ExecutorContextPtr GetExecutorContext(std::vector<std::string> tableRefs) const;
};

}