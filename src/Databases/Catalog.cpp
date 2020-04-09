#include "Catalog.h"
#include "../Utils/Logger.h"
#include "../Columns/TableCreator.h"
using namespace std;
namespace Databases {

Columns::TableID Catalog::GetTableID(const string& tableName)
{
    return GetTableIDImpl(tableName);
}   

Columns::TablePtr Catalog::GetTable(Columns::TableID tableID)
{
    shared_lock<shared_mutex> rLock(rwLock);
    return GetTableImpl(tableID);
}

void Catalog::InsertTable(const string& tableName, Columns::TablePtr table)
{
    lock_guard<shared_mutex> mlock(rwLock);
    InsertTableImpl(tableName, table);
}

Columns::TableID Catalog::GetTableIDImpl(const string& tableName)
{
    /// Try read
    {
        shared_lock<shared_mutex> rLock(rwLock);
        auto item = tableIDs.find(tableName);
        if (item != tableIDs.end()) {
            return item->second;
        }
    }

    /// Not exists, need Insert an empty table
    {
        lock_guard<shared_mutex> wLock(rwLock);

        /// Try read again, maybe others has inserted it
        auto item = tableIDs.find(tableName);
        if (item != tableIDs.end()) {
            return item->second;
        }
        
        /// Gengerate a new tableID and table
        Columns::TableID tableID = GetNewTableID();
        Columns::TablePtr table = Columns::TableCreator::CreateTable(tableID);
        tableIDs.emplace(tableName, tableID);
        tableMap.emplace(tableID, table);
        return tableID;
    }
}

Columns::TablePtr Catalog::GetTableImpl(Columns::TableID tableID)
{
    /// Under rlock or wlock
    auto item = tableMap.find(tableID);
    if (item == tableMap.end()) {
        LOG_ERROR("no such tableID %lu", tableID);
        return nullptr;
    }
    return item->second;
}

void Catalog::InsertTableImpl(const string& tableName, Columns::TablePtr table)
{
    /// Under wlock
    Columns::TableID tableID = table->GetTableID();
    tableIDs.emplace(tableName, tableID);
    tableMap.emplace(tableID, table);
}

Columns::TableID Catalog::GetNewTableID()
{
    /// Under wlock
    return ++currentTableID;
}

void Catalog::LoadInfo()
{
    LOG_INFO("Load Catalog begin");
    /*TODO*/
    LOG_INFO("Load Catalog end");
}

void Catalog::StoreInfo()
{
    LOG_INFO("Store Catalog begin");
    /*TODO*/
    LOG_INFO("Store Catalog end");
}

void Catalog::Commit(Columns::TableID tableID)
{
    shared_lock<shared_mutex> rLock(rwLock);
    Columns::TablePtr table = GetTableImpl(tableID);
    table->Update();
}

}