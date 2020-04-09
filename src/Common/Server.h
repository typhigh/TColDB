#pragma once
#include "../Executor/Executor.h"
#include "defs.h"
#include "CommandWrap.h"
#include <atomic>
#include <set>

namespace Common {

using ClientID = uint64_t;

class Server
{
private:
    /* data */
    std::atomic<bool> started;
    Executor::ExecutorPtr executor;

public:
    Server();
    ~Server();

    /// Is the server has started
    bool IsStarted() const;

    /// Run the new thread as server
    void Start();

    /// Add Client
    void AddClient(ClientID clientID);

    /// Query command by client
    void Query(CommandPtr cmd);

private:
    void StartImpl();
    bool ShouldShutDown() const;
    void Produce(CommandWrapPtr cmd);
    void Consume(CommandWrapPtr& cmd);

};

using ServerPtr = std::shared_ptr<Server>;
}