#include "Logger.h"
#include <memory>
#include <vector>
#include <stack>
#include <functional>

namespace Utils {

/// A simple ObjectPool. It's not thread-safe
/// We use stack to manage pool because the near object may be in cache with high possibility  
template<typename Object>
class ObjectPool 
{
public:
    using ObjectBlock = Object*;
    using ObjectDeleteFunc = std::function<void(Object*)>;
    using ObjectPtr = std::unique_ptr<Object, ObjectDeleteFunc>;
    static const DEFAULT_BLOCKSIZE = 100;
    
private:
    std::vector<ObjectBlock> blocks;
    std::stack<Object*> objectPool;
    size_t blockSize;
    std::string name;

public:
    ObjectPool() = default;
    ObjectPool(const std::string& name, size_t BlockSize = DEFAULT_BLOCKSIZE) : name(name), blockSize(max(static_cast<size_t>(1), BlockSize)) {}  
    
    ~ObjectPool();

    /// Get one object from pool
    ObjectPtr Get();
    
    /// Add (return) one object to pool
    /// Gengerally we don't use it
    void Add(ObjectPtr object);

    /// Get pool's name
    std::string GetName() const;

    /// Get Memory use size
    size_t EstimateMemoryUseSize() const;

private:
    void GrowPool();
};

template <typename Object>
ObjectPool<Object>::~ObjectPool() 
{
    for (auto block : blocks) {
        delete block;
    }
}

template <typename Object>
ObjectPool<Object>::ObjectPtr ObjectPool<Object>::Get() 
{
    if (objectPool.empty()) {
        GrowPool();
    }

    if (objectPool.empty()) {
        LOG_ERROR("ObjectPool %s Alloc object fails", name.c_str());
        return NULL;
    }

    Object* ret = objectPool.top();
    objectPool.pop();
    return ObjectPtr(
        ret, 
        [this](Object* object) { ObjectPool.push_back(object); }
    );
}

template <typename Object>
void ObjectPool<Object>::Add(ObjectPtr object) 
{
    objectPool.push(object.release());
}

template <typename Object>
void ObjectPool<Object>::GrowPool() 
{
    ObjectBlock block = new Object[blockSize];
    blocks.push_back(block);
    for (size_t i = 0; i < blockSize; ++i) {
        objectPool.push(&block[i]);
    }
}

template <typename Object>
std::string ObjectPool<Object>::GetName() const 
{
    return name;
} 

template <typename Object>
size_t ObjectPool<Object>::EstimateMemoryUseSize() const
{
    return blocks.size() * blockSize * (sizeof(Object));
}

}