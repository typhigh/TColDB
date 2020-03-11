#pragma once
#include "../ThreePart/CityHash101/city.h"

#include <vector>
#include <functional>
namespace Utils {

// Bloom Filter, maybe used in hash join or point find
class BloomFilter
{
public:
    using Container = std::vector<uint64_t>;
    using HashFuncType = std::function<size_t (const char*, size_t, size_t)>;

private:
    static constexpr size_t DEFUALT_SEED = 213712973;
    static constexpr size_t DEFUALT_SEED2 = 98123721;
    // The bit-array
    Container container;
    
    // The length of bits; 
    size_t len;
    
    // The hash times
    size_t hashes;
    
    // The hash seed
    size_t seed;

    // The hash func
    HashFuncType hashFunc;
public:

    BloomFilter(size_t len, size_t hashes, size_t seed = DEFUALT_SEED, HashFuncType hashFunc = CityHash64WithSeed);
    ~BloomFilter() {};
    
    // Add data
    void Add(const char* data, size_t len);
    
    // Check data maybe be contained
    bool Contain(const char* data, size_t len) const;
    
    // Clear the bloom filter
    void Clear();
};


}