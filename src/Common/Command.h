#pragma once
#include "Common.h"
#include "../Concurrency/TransactionID.h"
#include <string>

namespace Common {

struct Command
{
    std::string cmd;
    Concurrency::TransactionIDPtr txn;  
};

}