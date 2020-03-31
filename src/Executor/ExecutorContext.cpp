#include "ExecutorContext.h"
using namespace std;

namespace Executor {

ExecutorContext::ExecutorContext(const std::vector<Columns::TableMetaReadOnlyPtr> tableMetas, ExecutorPtr executor)
    : tableMetas(tableMetas)
    , executor(move(executor))
{
}

}