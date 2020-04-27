#pragma once
#include "Catalog.h"
#include "../Storages/BufferPool.h"

namespace Databases {

class Database;
using DatabasePtr = std::shared_ptr<Database>;
class Database
{
private:
    /* data */
    CatalogPtr catalog;
    std::string name;
    Storages::BufferPoolPtr bufferPool;

private:
    void LoadInfo();
    void StoreInfo();
    
public:
    Database(const std::string& name = "DefaultDB");
    ~Database();
    static DatabasePtr GetInstance();
    CatalogPtr GetCatalog();
    Storages::BufferPoolPtr GetBufferPool();
    
public:
    void Commit(Columns::TableID tableID);
};


}