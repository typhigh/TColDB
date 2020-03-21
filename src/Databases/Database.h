#pragma once
#include "Catalog.h"

namespace Databases {
class Database
{
private:
    /* data */
    CatalogPtr catalog;

public:
    Database(/* args */);
    ~Database();
    static DatabasePtr GetInstance();
    CatalogPtr GetCatalog();
};

using DatabasePtr = std::shared_ptr<Database>;
}