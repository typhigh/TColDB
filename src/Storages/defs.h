#pragma once
#include <vector>
#include <memory>
#include <string>
#include <cassert>

namespace Storages {

class InMemoryTable;
using InMemoryTablePtr = std::shared_ptr<InMemoryTable>;

class OnDiskTable;
using OnDiskTablePtr = std::shared_ptr<OnDiskTable>;

class OnDiskColumn;
using OnDiskColumnPtr = std::shared_ptr<OnDiskColumn>;
using OnDiskColumns = std::vector<OnDiskColumnPtr>;

class ColumnBlockMeta;
using ColumnBlockMetaPtr = std::shared_ptr<ColumnBlockMeta>;
}