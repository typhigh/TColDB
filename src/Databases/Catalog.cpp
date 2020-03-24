#include "Catalog.h"
#include "../Utils/Logger.h"
using namespace std;
namespace Databases {

Columns::TablePtr Catalog::GetTable(const string& tableName)
{
    shared_lock<shared_mutex> mlock(rwLock);
    GetTableImpl(tableName);
}   

Columns::TablePtr Catalog::GetTableImpl(const string& tableName)
{
    auto item = tableMap.find(tableName);
    if (item == tableMap.end()) {
        return Columns::TablePtr();
    }
    return item->second;
}
void Catalog::InsertTable(const string& tableName, Columns::TablePtr table)
{
    lock_guard<shared_mutex> mlock(rwLock);
    InsertTable(tableName, table);
}

void Catalog::InsertTableImpl(const string& tableName, Columns::TablePtr table)
{
    tableMap.emplace(tableName, table);
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

}