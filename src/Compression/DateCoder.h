#pragma once
#include "defs.h"

namespace Compression {

class DateCoder
{
public:
    /// The "2000-00-00" 's encode 
    static const int32_t BaseDateEncode;

    /// Encode date by converting it to int32
    static Storages::Slice EnCodeDate(Storages::Slice output, const std::string& data);

    static Storages::Slice DeCodeDate(Storages::Slice input, std::string& data);

private:
 
    /// convert date to int, if it's not date, return false
    static bool ConvertDateToInt32(const std::string& data, int32_t& encode);

    /// convert int to date, if it's not date, return false
    static bool ConvertInt32ToDate(int32_t encode, std::string& data);

    /// Get base encode for date
    static int32_t GetBaseEncode(const std::string& data);

    /// Get date from base encode
    static std::string GetDateFromBaseEncode(int32_t encode);
};

}