#pragma once
#include "../Common/Client.h"

namespace Concurrency {

class TransactionID
{
private:
    /* data */
    uint64_t clientID;
    uint64_t databaseID;
    // txnHashCode = {clientID, databaseID}
    uint64_t txnHashCode;

public:
    TransactionID(/* args */);
    ~TransactionID();
};

using TransactionIDPtr = std::shared_ptr<TransactionID>;

}