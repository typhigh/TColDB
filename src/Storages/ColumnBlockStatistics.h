#pragma once
#include "../Columns/Field/Field.h"
namespace Storages {

struct ColumnBlockStatistics
{
/// Statistics Data
    Columns::FieldPtr minValue;
    Columns::FieldPtr maxValue;
    Columns::FieldPtr sumValue;
    size_t count;

/// Clone Func
    ColumnBlockStatistics Clone() const {
        ColumnBlockStatistics ret;
        if (minValue != nullptr) {
            ret.minValue = this->minValue->Clone();
        }
        if (maxValue != nullptr) {
            ret.maxValue = this->maxValue->Clone();
        }
        if (sumValue != nullptr) {
            ret.sumValue = this->sumValue->Clone();
        }
        ret.count = this->count;
        return ret;
    }
};

}