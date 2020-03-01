#pragma once
#include "TransactionID.h"

namespace Concurrency {

class TransactionManager
{
private:
    /* data */

public:
    
    void SetClient(uint64_t clientID);
    
    // clientID must be set before. And it will set hash code by clientID and databaseID
    void SetDatabaseID(uint64_t databaseID);
};


}