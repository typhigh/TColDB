#include "Catalog.h"
#include "../Utils/Logger.h"
using namespace std;
namespace Databases {

Columns::TablePtr Catalog::GetTable(string tableName)
{
    shared_lock<shared_mutex> mlock(rwLock);
    auto item = tableMap.find(tableName);
    if (item == tableMap.end()) {
        return Columns::TablePtr();
    }
    return item->second;
}   

void Catalog::InsertTable(string tableName, Columns::TablePtr table)
{
    lock_guard<shared_mutex> mlock(rwLock);
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