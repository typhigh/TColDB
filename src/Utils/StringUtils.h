#include <string>

namespace Utils {

// Trim string with predict, usage:
//      string a = "aaababaaa"
//      Trim(a, [](char ch){return ch == 'a';})-> "bab"

template<typename Func>
std::string Trim(const std::string& s, Func && Predict) {
    if (s.empty()) return s;
    size_t start = 0;
    size_t end = s.length()-1;
    while (start <= end && Predict(s[start])) ++start;
    while (start <= end && Predict(s[end])) --end;
    if (start > end) return "";
    return s.substr(start, end-start+1);
}

// Normalize command string: "  select 1; " -> "select 1;"
std::string NormalizeCommand(const std::string& s) {
    return Trim(s, [](char ch) {return ch == ' ' || ch == '\t' || ch == '\r' || ch == '\n';});
}

}