#include "ProductConsumerQueue.h"
#include "../Common/CommandWrap.h"
using namespace std;

namespace Utils {

template<typename T> 
ProductConsumerQueue<T>::ProductConsumerQueue() 
{
}

template<typename T> 
ProductConsumerQueue<T>::~ProductConsumerQueue() 
{
}

// Refer to "c++ concurrency in action" 
template<typename T>
void ProductConsumerQueue<T>::Push(T value) 
{
    lock_guard<mutex> lock(mutexLock);
    dataQueue.push(value);
    dataCond.notify_one();
}

template<typename T>
void ProductConsumerQueue<T>::WaitAndPop(T& value) 
{
    unique_lock<mutex> lock(mutexLock);
    dataCond.wait(lock, [this]{return !dataQueue.empty();});
    value = dataQueue.front();
    dataQueue.pop();
}


template class ProductConsumerQueue<Common::CommandWrapPtr>;

}

