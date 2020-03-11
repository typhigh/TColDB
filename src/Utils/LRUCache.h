#pragma once
#include "Logger.h"
#include <unordered_map>
#include <list>
#include <memory>
#include <chrono>
#include <mutex>
#include <atomic>
#include <vector>

namespace Utils {

template <typename TKey, typename TVal, typename HashFuncType = std::hash<TKey>>
class LRUCache
{
public:
    using TValPtr = std::shared_ptr<TVal>;
    using Queue = std::list<TKey>; 

private:
    /* data */
    struct MapResult
    {
        TValPtr val;
        typename Queue::iterator queueIter;
    };
    using Map = std::unordered_map<TKey, MapResult, HashFuncType>;    

public:
    LRUCache(size_t maxSize = 1) : maxSize(std::max((size_t) 1, maxSize)) {}
    virtual ~LRUCache() {};

    // Insert a (key, val) pair into the Cache     
    void Insert(TKey key, TValPtr val) 
    {
        std::lock_guard<std::mutex> lock(mLock);
        InsertImpl(key, val);
    }

    // Get a val's pointer, if the val not exists, just return null pointer
    TValPtr Get(TKey key) 
    {
        std::lock_guard<std::mutex> lock(mLock);
        TValPtr ret = GetImpl(key);
        if (ret) {
            ++hits;
        } else {
            ++misses;
        }
        return ret;
    }

    // Clear the cache without change base configure
    void Clear() 
    {
        std::lock_guard<std::mutex> lock(mLock);
        overflowQueue.clear();
        queue.clear();
        hashMap.clear();
        hits = misses = 0;
    }

    double GetHitRatio() const 
    {
        return 1.0 * hits / (hits + misses);
    }

private:
    static constexpr size_t DEFAULT_OVERFLOWMAXSIZE = 100;
    mutable std::mutex mLock;
    size_t maxSize;
    size_t overflowMaxSize = DEFAULT_OVERFLOWMAXSIZE;

    Map hashMap;
    Queue queue;
    std::vector<TValPtr> overflowQueue;
    // History information for hits and misses of LRUCache
    size_t hits = 0;
    size_t misses = 0;

private:
    void InsertImpl(TKey key, TValPtr val) 
    {
        auto res = hashMap.emplace(
            key, 
            MapResult {
                val,
                /**/
            }
        );
        // inserted may be false if there exists the same key
        bool inserted = res.second;
        MapResult& mRes = res.first->second;
        if (inserted) {
            queue.push_front(key);
        } else {
            queue.erase(mRes.queueIter);
            queue.push_front(key);
        }
        mRes.queueIter = queue.begin();
        RemoveOverflowIfNeed();
    }

    TValPtr GetImpl(TKey key) 
    {
        typename Map::iterator iter = hashMap.find(key);
        if (iter == hashMap.end()) {
            return TValPtr();
        }
        MapResult& mRes = iter->second;
        TValPtr ret = mRes.val;
        queue.erase(mRes.queueIter);
        queue.push_front(key);
        mRes.queueIter = queue.begin();
        return ret;   
    }

    void RemoveOverflowIfNeed() 
    {
        // Free sapce in a lazy way
        while (queue.size() > maxSize) {
            TKey key = queue.back();
            queue.pop_back();
            auto it = hashMap.find(key);
            if (it == hashMap.end()) {
                LOG_ERROR("Expected hashMap element");
                continue;
            }
            overflowQueue.push_back(it->second.val);
            hashMap.erase(it);
        }

        if (overflowQueue.size() > overflowMaxSize) {
            overflowQueue.clear();
            LOG_INFO("Clear the overflowQueue");
        }
    }
    
};



}