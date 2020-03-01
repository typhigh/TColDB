#include <queue>
#include <mutex>
#include <condition_variable>

namespace Utils {

// A thread-safe product consumer queue
template <typename T>
class ProductConsumerQueue
{
private:
    std::mutex mutexLock;
    std::queue<T> dataQueue;
    std::condition_variable dataCond;

public:
    ProductConsumerQueue();
    ~ProductConsumerQueue();

    // Push data into queue
    void Push(T value);

    // Pop data with waiting
    void WaitAndPop(T& value);
};


}