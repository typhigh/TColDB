#include "TableCreator.h"
using namespace std;

namespace Columns {

TablePtr TableCreator::CreateTable(Columns::TableID tableID) 
{
    return make_shared<Table>(tableID);
}

}