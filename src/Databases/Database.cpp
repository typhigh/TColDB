#include "Database.h"
#include "../Utils/Logger.h"
using namespace std;

namespace Databases {

Database::Database(const string& name) : name(name)  
{
    catalog = make_shared<Catalog>();
    LoadInfo();
}

Database::~Database() 
{

}

void Database::LoadInfo()
{
    LOG_INFO("Load Database %s begin", name.c_str());
    catalog->LoadInfo();
    /*TODO*/
    LOG_INFO("Load Database %s end", name.c_str());
}

void Database::StoreInfo() 
{
    LOG_INFO("Store Database %s begin", name.c_str());
    catalog->StoreInfo();
    /*TODO*/
    LOG_INFO("Store Database %s end", name.c_str());
}

CatalogPtr Database::GetCatalog()
{
    return catalog;
}

Storages::BufferPoolPtr Database::GetBufferPool()
{
    return bufferPool;
}
DatabasePtr Database::GetInstance() 
{
    static DatabasePtr db = make_shared<Database>();
    return db;
}

void Database::Commit(Columns::TableID tableID)
{
    catalog->Commit(tableID);
}

}