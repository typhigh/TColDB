#include "RenameTable.h"
#include "../Utils/StringUtils.h"
using namespace std;

namespace Plan {

void RenameTable::Set(const std::string& tableOriginName, const std::string& tableAlisName)
{
    this->tableOriginName = tableOriginName;
    this->tableAlisName = tableAlisName;
}

void RenameTable::Set(const std::vector<std::pair<std::string, std::string> >& colTable) 
{
    this->colTable = colTable;
}

bool RenameTable::FindAlis(const string& origin, string& result) const 
{
    if (tableAlisName != tableOriginName) {
        result = tableAlisName + "." + Utils::GetPointAfter(origin);
        return true;
    }

    for (const auto& ele : colTable) {
        if (origin == ele.first) {
            result = ele.second;
            return true;
        }
    }

    return false;
}

bool RenameTable::FindOrigin(const string& alis, string& result) const 
{
    if (tableAlisName != tableOriginName) 
    {
        result = tableOriginName + "." + Utils::GetPointAfter(alis);
        return true;
    }

    for (const auto& ele : colTable) {
        if (alis == ele.second) {
            result = ele.first;
            return true;
        }
    }
    return false;
}

}