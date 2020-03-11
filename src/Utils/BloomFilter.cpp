#include "BloomFilter.h"
using namespace std;


namespace Utils {


BloomFilter::BloomFilter(size_t len, size_t hashes, size_t seed, HashFuncType hashFunc)
    : len(len)
    , hashes(hashes)
    , seed(seed)
    , container((len + sizeof(Container::value_type) * 8 - 1) / (sizeof (Container::value_type) * 8), 0) 
    , hashFunc(hashFunc)
{

}

void BloomFilter::Add(const char* data, size_t len) 
{
    size_t hash1 = hashFunc(data, len, seed);
    size_t hash2 = hashFunc(data, len, seed * DEFUALT_SEED2);
    for (size_t i = 0; i < hashes; ++i) {
        size_t pos = hash1 + hash2 * i;
        pos = (pos << 17) | (pos >> 47);
        pos %= this->len;
        container[pos / (8 * sizeof(Container::value_type))] |= 1ULL << (pos % (8 * sizeof(Container::value_type)));
    }
}

bool BloomFilter::Contain(const char* data, size_t len) const 
{
    size_t hash1 = hashFunc(data, len, seed);
    size_t hash2 = hashFunc(data, len, seed * DEFUALT_SEED2);
    for (size_t i = 0; i < hashes; ++i) {
        size_t pos = hash1 + hash2 * i;
        pos = (pos << 17) | (pos >> 47);
        pos %= this->len;
        if (!((container[pos / (8 * sizeof(Container::value_type))] >> (pos % (8 * sizeof(Container::value_type)))) & 1ULL))
            return false;
    }
    return true;
}

void BloomFilter::Clear() 
{
    using namespace std;
    for (auto &content: container) {
        content = 0;
    }
}

}