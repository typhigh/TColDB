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

private:
    Columns::TablePtr GetTableImpl(const std::string& tableName);
    void InsertTableImpl(const std::string& tableName, Columns::TablePtr table);

public:
    Columns::TablePtr GetTable(const std::string& tableName);
    void InsertTable(const std::string& tableName, Columns::TablePtr table);
    friend class Database;
};

using CatalogPtr = std::shared_ptr<Catalog>;

}