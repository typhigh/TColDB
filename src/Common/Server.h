#pragma once
#include "../Utils/ProductConsumerQueue.h"
#include "../Executor/Executor.h"
#include "defs.h"
#include "Command.h"
#include <atomic>
#include <set>

namespace Common {

using ClientID = uint64_t;

class Server
{
private:
    /* data */
    Utils::ProductConsumerQueue<CommandPtr> commandQueue;
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
    void Produce(CommandPtr cmd);
    void Consume(CommandPtr& cmd);

};

using ServerPtr = std::shared_ptr<Server>;
}