#include "../Columns/Table.h"
#include <unordered_map>
#include <string>
#include <memory>
namespace Databases {

class Catalog
{
private:
    /* data */
    std::unordered_map<std::string, Columns::TablePtr> tableMap; 

public:
    Columns::TablePtr GetTable(std::string tableName);
};

using CatalogPtr = std::shared_ptr<Catalog>;

}