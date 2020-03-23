#pragma once
#include "../Columns/Table.h"
#include <unordered_map>
#include <string>
#include <memory>
#include <mutex>
#include <shared_mutex>

namespace Databases {

class Catalog
{
private:
    /* lock data */
    std::unordered_map<std::string, Columns::TablePtr> tableMap; 
    mutable std::shared_mutex rwLock;

protected:  
    void LoadInfo();
    void StoreInfo();

public:
    Columns::TablePtr GetTable(std::string tableName);
    void InsertTable(std::string tableName, Columns::TablePtr);
    friend class Database;
};

using CatalogPtr = std::shared_ptr<Catalog>;

}