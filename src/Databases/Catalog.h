#pragma once
#include "../Columns/Table.h"
#include "../Columns/TableID.h"
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
    std::unordered_map<std::string, Columns::TableID> tableIDs;
    std::unordered_map<Columns::TableID, Columns::TablePtr> tableMap;
    mutable std::shared_mutex rwLock;
    Columns::TableID currentTableID;

protected:  
    void LoadInfo();
    void StoreInfo();

public:
    Catalog() : currentTableID(0){}
    ~Catalog() {}
    /// Get table id by tableName
    Columns::TableID GetTableID(const std::string& tableName);
    
    /// Get table by table id
    Columns::TablePtr GetTable(Columns::TableID tableID);

    /// Insert a table
    void InsertTable(const std::string& tableName, Columns::TablePtr table);
    friend class Database;

private:
    Columns::TableID GetTableIDImpl(const std::string& tableName);    
    Columns::TablePtr GetTableImpl(Columns::TableID tableID);

    void InsertTableImpl(const std::string& tableName, Columns::TablePtr table);
    Columns::TableID GetNewTableID();
};

using CatalogPtr = std::shared_ptr<Catalog>;

}