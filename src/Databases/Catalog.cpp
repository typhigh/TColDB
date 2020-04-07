#include "Catalog.h"
#include "../Utils/Logger.h"
using namespace std;
namespace Databases {

Columns::TableID Catalog::GetTableID(const string& tableName)
{
    shared_lock<shared_mutex> mlock(rwLock);
    return GetTableIDImpl(tableName);
}   

Columns::TablePtr Catalog::GetTable(Columns::TableID tableID)
{
    shared_lock<shared_mutex> mlock(rwLock);
    return GetTableImpl(tableID);
}

void Catalog::InsertTable(const string& tableName, Columns::TablePtr table)
{
    lock_guard<shared_mutex> mlock(rwLock);
    InsertTableImpl(tableName, table);
}

Columns::TableID Catalog::GetTableIDImpl(const string& tableName)
{
    auto item = tableIDs.find(tableName);
    if (item != tableIDs.end()) {
        return item->second;
    }
    Columns::TableID tableID = GetNewTableID();
    tableIDs.emplace(tableName, tableID);
    tableMap.emplace(tableID, nullptr);
    return tableID;
}

Columns::TablePtr Catalog::GetTableImpl(Columns::TableID tableID)
{
    auto item = tableMap.find(tableID);
    if (item == tableMap.end()) {
        return nullptr;
    }
    return item->second;
}

void Catalog::InsertTableImpl(const string& tableName, Columns::TablePtr table)
{
    auto item = tableIDs.find(tableName);
    Columns::TableID tableID;
    if (item == tableIDs.end()) {
        tableID = GetNewTableID();
        tableIDs.emplace(tableName, tableID);
    } else {
        tableID = item->second;
    }
    tableMap.emplace(tableID, table);
}

Columns::TableID Catalog::GetNewTableID()
{
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

void Catalog::UpdateAllTableMetas()
{
    for (auto iter = tableMap.begin(); iter != tableMap.end(); ++iter) {
        iter->second->Update();
    }
}

}