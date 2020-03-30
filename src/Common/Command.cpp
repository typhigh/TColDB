#include "Command.h"
using namespace std;

namespace Common {

string Command::GetContent() const 
{
    return cmd;
}
    
void Command::SetResult(const string& result) 
{
    lock_guard<std::mutex> lock(mutex);
    if (done) {
        return;
    }
    done = true;
    cond.notify_all();
    this->result = result;
}

string Command::GetResult() {
    unique_lock<std::mutex> lock(mutex);
    cond.wait(lock, [this] { return done;});
    return result;
}

}