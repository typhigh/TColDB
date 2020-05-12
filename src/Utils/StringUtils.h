#pragma once
#include <string>
#include <cstdlib>
#include <cstring>
#include <cassert>

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

/// Get random string with given length
inline std::string RandomString(int len)
{
    std::string ret(len, 0);
    srand((unsigned) time(NULL));
    for (int i = 0; i < len; ++i) {
        ret[i] = rand() % len;
    }
    return ret;
}

/// Get random string with given length, and every character is in [lower, upper]
inline std::string RandomString(int len, unsigned char lower, unsigned char upper)
{   
    assert(upper >= lower);
    std::string ret(len, 0);
    srand((unsigned) time(NULL));
    for (int i = 0; i < len; ++i) {
        ret[i] = rand() %  (upper - lower + 1) + lower; 
    }
    return ret;
}

/// Get Date string by (year, month, day) like "2010-10-06"
inline std::string GetDate(int year, int month, int day)
{
    std::string sYear = std::to_string(year);
    if (sYear.size() < 4) sYear = std::string(4-sYear.size(), '0') + sYear;
    std::string sMonth = std::to_string(month);
    if (sMonth.size() == 1) sMonth = "0" + sMonth;
    std::string sDay = std::to_string(day);
    if (sDay.size() == 1) sDay = "0" + sDay;
    std::string ret = sYear + "-" + sMonth + "-" + sDay; 
    return ret;
}

/// Get random date
inline std::string RandomDate()
{
    int year = rand() % 10000;
    int month = rand() % 12 + 1;
    int day = rand() % 31 + 1;
    return GetDate(year, month, day);
}

/// Check the date format is right or not
inline bool CheckDate(const std::string& date)
{
    if (date.size() != 10) {
        return false;
    }
    if (date[4] != '-' || date[7] != '-') {
        return false;
    } 
    int year, month, day;
    sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day);
    if (year > 9999 || year < 0 || month > 12 || month < 1 || day > 31 || day < 1) {
        return false;
    }
    return true;
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
            j = i+1;
        }
    }

    return ret;
}

/// Copy a new c style string, return c-style
inline char* CopyCStringFromCString(const char* s, size_t len = 0)
{
    if (s == nullptr) {
        return nullptr;
    }
    if (!len) {
        len = strlen(s);
    }
    char* ret = new char[len+1];
    memcpy(ret, s, len);
    ret[len] = 0;
    return ret;
}

// Copy a new c style string, return c-style
inline std::string CopyStringFromCString(const char* s, size_t len = 0) 
{
    if (s == nullptr) {
        return " ";
    }
    if (!len) {
        len = strlen(s);
    }
    std::string ret;
    ret.reserve(len);
    ret.append(s);
    return ret;
}

}