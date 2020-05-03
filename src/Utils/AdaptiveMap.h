#pragma once
#include <vector>
#include <map>
#include <unordered_map>
#include <cassert>

namespace Utils {

/// AaptiveMap is a aptive map which size will not be reduced
/// Only insert operation and get query supported
/// And no same key
template <typename TKey, typename TVal>
class AdaptiveMap
{
public:
    using KeyValue = std::pair<TKey, TVal>;
    constexpr static size_t MapMinSize = 16;

private:
    /// Use vector or unorder_map up to the size 
    std::vector<TKey> keys;
    std::vector<TVal> values;
    std::map<TKey, size_t> mp;
    size_t size = 0;

public:
    AdaptiveMap(/* args */) {}
    ~AdaptiveMap() {}

    void Insert(const TKey& key, const TVal& val);

    bool Get(const TKey& key, TVal& val) const;

    bool LowBound(const TKey& key, TVal& val) const;
};

template <typename TKey, typename TVal>
void AdaptiveMap<TKey, TVal>::Insert(const TKey& key, const TVal& val)
{
    values.push_back(val);
    if (size < MapMinSize) {
        keys.push_back(key);
    } else {
        mp[key] = values.size() - 1;
    }

    if (++size == MapMinSize) {
        for (size_t i = 0; i < keys.size(); ++i) {
            mp[keys[i]] = i;
        }
        keys.clear();
    }
}

template <typename TKey, typename TVal>
bool AdaptiveMap<TKey, TVal>::Get(const TKey& key, TVal& val) const
{
    assert(values.size() == size);
    size_t offset;
    if (size < MapMinSize) {
        /// In vector
        assert(keys.size() == size);        
        assert(mp.size() == 0);
        auto iter = find(keys.begin(), keys.end(), key);
        if (iter == keys.end()) {
            return false;
        }
        offset = iter - keys.begin();
    } else {
        /// In map
        assert(keys.size() == 0);
        assert(mp.size() == size);
        auto iter = mp.find(key);
        if (iter == mp.end()) {
            return false;
        }
        offset = iter->second;
    }
    val = values[offset];
    return true;
}

template <typename TKey, typename TVal>
bool AdaptiveMap<TKey, TVal>::LowBound(const TKey& key, TVal& val) const
{
    size_t offset;
    if (size < MapMinSize) {
        auto iter = find(keys.begin(), keys.end(), key);
        if (iter == keys.end()) {
            return false;
        }
        offset = iter - keys.begin();
    } else {
        auto iter = mp.lower_bound(key);
        if (iter == mp.end()) {
            return false;
        }
        offset = iter->second;
    }
    assert(offset < size);
    val = values[offset];
    return true;
}

}