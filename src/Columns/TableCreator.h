#pragma once
#include "Table.h"
namespace Columns {

class TableCreator
{
public:
    static TablePtr CreateTable(Columns::TableID tableID);
};

}