#pragma once
#include <unordered_set>
#include <mutex>
#include <shared_mutex>
namespace Utils {

template<typename T>
class ConcurrentHashSet 
{
private:
    mutable std::mutex mLock;
    std::unordered_set<T> datas;
public:
    ConcurrentHashSet(/* args */) {}
    ~ConcurrentHashSet() {}

public: 
    void Insert(const T& value);
    void Remove(const T& value);
    bool IsEmpty() const;
};

template<typename T>
void ConcurrentHashSet<T>::Insert(const T& value) 
{
    std::lock_guard<std::mutex> lock(mLock);
    datas.insert(value);
}

template<typename T>
void ConcurrentHashSet<T>::Remove(const T& value) 
{
    std::lock_guard<std::mutex> lock(mLock);
    datas.erase(value);
}

template<typename T>
bool ConcurrentHashSet<T>::IsEmpty() const
{
    std::lock_guard<std::mutex> lock(mLock);
    return datas.empty();
} 

}
