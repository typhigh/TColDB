#pragma once
#include <string>
#include <cstdlib>
#include <cstring>

namespace Utils {

// Trim string with predict, usage:
//      string a = "aaababaaa"
//      Trim(a, [](char ch){return ch == 'a';})-> "bab"

template<typename Func>
std::string Trim(const std::string& s, Func && Predict) 
{
    if (s.empty()) return s;
    size_t start = 0;
    size_t end = s.length()-1;
    while (start <= end && Predict(s[start])) ++start;
    while (start <= end && Predict(s[end])) --end;
    if (start > end) return "";
    return s.substr(start, end-start+1);
}

// Normalize command string: "  select 1; " -> "select 1;"
inline std::string NormalizeCommand(const std::string& s) 
{
    return Trim(s, [](char ch) {return ch == ' ' || ch == '\t' || ch == '\r' || ch == '\n';});
}

inline std::string RandomString(int len)
{
    std::string ret(len, 0);
    srand((unsigned) time(NULL));
    for (int i = 0; i < len; ++i) {
        ret[i] = rand() % len;
    }
    return ret;
}


/// Get string after the point
/// Example: "1.233" -> "233"
inline std::string GetPointAfter(const std::string& s) 
{
    size_t pos = s.find_first_of('.');
    if (pos == s.size()) {
        return s;
    }
    return s.substr(pos+1, s.size() - pos);
}

/// Return if two field name equal
inline bool EqualFieldName(const std::string& lhs, const std::string& rhs)
{
    if (lhs == rhs) {
        return true;
    }
    return GetPointAfter(lhs) == rhs || GetPointAfter(rhs) == lhs;
}

/// Get string vector from a string by splite some char
/// Example: char = ';', "1;2;3;" -> vector<string>{"1","2","3"}
inline std::vector<std::string> Splite(const std::string& s, char ch)
{
    std::vector<std::string> ret; 
    for (size_t i = 0, j = 0; i < s.size(); ++i) {
        if (s[i] == ch) {
            std::string now = s.substr(j, i - j + 1);
            ret.push_back(move(now));
            j = i;
        }
    }

    return ret;
}

/// Copy a new c style string, return c-style
inline char* CopyCStringFromCString(const char* s)
{
    if (s == nullptr) {
        return nullptr;
    }
    size_t len = strlen(s);
    char* ret = new char[len];
    memcpy(ret, s, len);
    return ret;
}

// Copy a new c style string, return c-style
inline std::string CopyStringFromCString(const char* s) 
{
    if (s == nullptr) {
        return " ";
    }
    size_t len = strlen(s);
    std::string ret;
    ret.reserve(len);
    ret.append(s);
    return ret;
}

}