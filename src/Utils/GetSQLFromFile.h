#pragma once
#include "Logger.h"
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

namespace Utils {

inline std::string GetSQLFromFile(const std::string path)
{
    std::ifstream reader(path);
    if (!reader.is_open()) {
        LOG_ERROR("open %s fails", path.c_str());
        return "";
    }

    std::string ret;
    std::stringstream in;
    char buf[256];
    while (!reader.eof()) {
        reader.getline(buf, 256);
        in << buf << "\n";
    }
    ret = in.str();
    return ret;
} 

}