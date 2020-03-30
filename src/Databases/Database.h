#pragma once
#include "Catalog.h"

namespace Databases {

class Database;
using DatabasePtr = std::shared_ptr<Database>;
class Database
{
private:
    /* data */
    CatalogPtr catalog;
    std::string name;

private:
    void LoadInfo();
    void StoreInfo();
    
public:
    Database(const string& name = "DefaultDB");
    ~Database();
    static DatabasePtr GetInstance();
    CatalogPtr GetCatalog();
};


}