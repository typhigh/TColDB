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
    constexpr static size_t MapMinSize = 16;
    using KeyValue = std::pair<TKey, TVal>;

private:
    /// Use vector or unorder_map up to the size 
    std::vector<KeyValue> vec;
    std::map<TKey, TVal> mp;
    size_t size = 0;

public:
    AdaptiveMap(/* args */) {}
    ~AdaptiveMap() {}

    void Insert(TKey key, TVal val);

    bool Get(TKey key, TVal& val);
};

template <typename TKey, typename TVal>
void AdaptiveMap<TKey, TVal>::Insert(TKey key, TVal val)
{
    if (size < MapMinSize) {
        vec.emplace_back(key, val);
    } else {
        mp[key] = val;
    }

    if (++size == MapMinSize) {
        for (KeyValue& value : vec) {
            mp.insert(value);
        }
        vec.clear();
    }
}

template <typename TKey, typename TVal>
bool AdaptiveMap<TKey, TVal>::Get(TKey key, TVal& val)
{
    /// In vector
    if (size < MapMinSize) {
        assert(vec.size() == size);        
        assert(mp.size() == 0);
        auto iter = find(vec.begin(), vec.end(), key);
        if (iter == vec.end()) {
            return false;
        }
        val = *iter;
        return true;
    }

    /// In map
    assert(vec.size() == 0);
    assert(mp.size() == size);
    auto iter = mp.find(key);
    if (iter == mp.end()) {
        return false;
    }
    val = *iter;
    return true;
}

}
