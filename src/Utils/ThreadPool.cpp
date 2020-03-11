#include "ThreadPool.h"
using namespace std;

namespace Utils {
ThreadPool::ThreadPool(string poolName, size_t sizes) 
    : poolName(poolName)
    , isRunning(false)
    , sizes(sizes)
{

}

void ThreadPool::StartUp() 
{
    {
        lock_guard<mutex> lock(mLock);
        if (isRunning) return;
        isRunning = true;
    }

    LOG_INFO("ThreadPool %s starts up", poolName.c_str());
    
    for (size_t i = 0; i < sizes; ++i) {
        string name = poolName + "_workers_" + to_string(i);
        works.emplace_back(
            [this] (string name)
            {    
                LOG_INFO("Thread %s begins ...", name.c_str());
                while (1) {
                    function<void()> task;
                    {
                        unique_lock<mutex> lock(mLock);
                        condition.wait(
                            lock,
                            [this] { return !isRunning || !tasks.empty();}
                        );
                        if (!isRunning && tasks.empty()) break;
                        task = std::move(tasks.front());
                        tasks.pop();
                    }
                    task();
                }
                LOG_INFO("Thread %s exits ...", name.c_str());
            } , 
            name
        ); 
    }
}

void ThreadPool::ShutDown() 
{
    {
        lock_guard<mutex> lock(mLock);
        if (!isRunning) {
            return;
        }
        isRunning = false;
    }

    condition.notify_all();
    for (int i = 0; i < sizes; ++i) {
        works[i].join();
    }
    works.clear();
    LOG_INFO("ThreadPool %s shuts down", poolName.c_str());
}

ThreadPool::~ThreadPool() 
{
    ShutDown();
}

}