#pragma once
#include "defs.h"
#include <memory>
#include <string>
#include <mutex>
#include <condition_variable>
#include <atomic>

namespace Common {

class Command
{
private:
    /// content
    const std::string cmd;
    std::string result;
    const ClientID clientID;

private:
    /// state
    bool done = false;
    std::mutex mutex;
    std::condition_variable cond;

public:
    Command(const std::string& cmd, ClientID clientID) : cmd (cmd), clientID(clientID) {}
    ~Command() {}

    /// Get content
    std::string GetContent() const;
    
    /// Set result
    void SetResult(const std::string& result);
    
    /// Get result (waiting future Set)
    std::string GetResult();

    /// Get client id
    ClientID GetclientID() const;

};

using CommandPtr = std::shared_ptr<Command>;

}

