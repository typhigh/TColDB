#include "Command.h"
using namespace std;

namespace Common {

string Command::GetContent() const 
{
    return cmd;
}
    
void Command::SetResult(const string& result) 
{
    {
        lock_guard<std::mutex> lock(mutex);
        if (done) {
            return;
        }
        this->result = result;
        done = true;
    }
    cond.notify_all();
}

string Command::GetResult() 
{
    unique_lock<std::mutex> lock(mutex);
    cond.wait(lock, [this] { return done;});
    return result;
}

ClientID Command::GetclientID() const
{
    return clientID;
}

}