#pragma once
#include <memory>
namespace Executor {

class Executor;
using ExecutorPtr = std::shared_ptr<Executor>;

class ExecutorContext;
using ExecutorContextPtr = std::shared_ptr<ExecutorContext>;
}