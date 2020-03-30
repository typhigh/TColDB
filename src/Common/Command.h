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
    ClientID clientID;

    /// state
    bool done;
    std::mutex mutex;
    std::condition_variable cond;

public:
    Command(const std::string& cmd, ClientID clientID) : cmd (cmd), clientID(clientID) {}
    ~Command() {}
    /// Get Content
    std::string GetContent() const;
    
    /// Set Result
    void SetResult(const std::string& result);
    
    /// Get Result (waiting future Set)
    std::string GetResult();
};

using CommandPtr = std::shared_ptr<Command>;


}