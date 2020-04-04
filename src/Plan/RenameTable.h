#pragma once
#include "defs.h"
#include <vector>

namespace Plan {

class RenameTable
{
private:
    /// Table Rename
    std::string tableOriginName;
    std::string tableAlisName;

    /// columns Rename
    std::vector<std::pair<std::string, std::string>> colTable;

public:
    RenameTable() = default;
    void Set(const std::string& tableOriginName, const std::string& tableAlisName);
    void Set(const std::vector<std::pair<std::string, std::string> >& colTable);
    ~RenameTable() {}

public:
    /// find the origin name by alis
    bool FindOrigin(const std::string& alis, std::string& result) const;
    
    /// find the alis name by origin
    bool FindAlis(const std::string& origin, std::string& result) const;
};

}