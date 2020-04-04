#pragma once
#include <vector>
#include <algorithm>
#include <set>
namespace Utils {

/// Keep the vector to be unique and sorted
template<typename T>
void NormalizeVector(std::vector<T>& result)
{
    std::sort(result.begin(), result.end());
    result.erase(std::unique(result.begin(), result.end()), result.end());
} 

/// Merge two vectors, and normalize the result
template<typename T>
void MergeVectors(std::vector<T>& result, const std::vector<T>& other)
{
    result.insert(result.end(), other.begin(), other.end());
    NormalizeVector(result);
} 

}