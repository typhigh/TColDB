#pragma once
#include "Logger.h"
#include <queue>
#include <thread>
#include <memory>
#include <future>
#include <functional>
#include <stdexcept>
#include <string>
#include <mutex>
#include <condition_variable>

namespace Utils {

class ThreadPool
{
public:
    ThreadPool(std::string poolName, size_t sizes);
    template <typename Func, typename... Args>
    auto Submit(Func&& func, Args&&... args) 
        -> std::future<typename std::result_of<Func(Args...)>::type>;
    void StartUp();
    void ShutDown();
    ~ThreadPool();

private:
    std::string poolName;
    size_t sizes;

    // lock and variable with lock
    std::condition_variable condition;
    mutable std::mutex mLock;
    bool isRunning;
    std::vector<std::thread> works;
    // TODO: maybe use lock-free queue
    std::queue <std::function<void()>> tasks;
};

template <typename Func, typename... Args>
auto ThreadPool::Submit(Func&& func, Args&&... args) 
    -> std::future<typename std::result_of<Func(Args...)>::type>
{
    using ResultType = typename std::result_of<Func(Args...)>::type;
    auto task = std::make_shared<std::packaged_task<ResultType()> > (
        std::bind(std::forward<Func>(func), std::forward<Args>(args)...)
    );
    std::future<ResultType> res = task->get_future();
    {
        std::unique_lock<std::mutex> lock(mLock);
        if (!isRunning) {
            LOG_ERROR("excepted running ThreadPool %s", poolName.c_str());
        }
        tasks.emplace(
            [task]() {
                (*task)();
            }
        );
    }
    condition.notify_one();
    return res;
}
}