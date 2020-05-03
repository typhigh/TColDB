#include "DateCoder.h"
#include "IntCoder.h"
#include "../Utils/StringUtils.h"
using namespace std;
using namespace Storages;

namespace Compression {
const int32_t DateCoder::BaseDateEncode = GetBaseEncode("2000-01-01");

Slice DateCoder::EnCodeDate(Slice output, const string& data)
{
    int32_t encode;
    if (!ConvertDateToInt32(data, encode)) {
        LOG_WARN("Date format is wrong (should like xxxx-xx-xx): %s", data.c_str());
        return output;
    }
    
    return IntCoder::EncodeVarSInt32(output, encode);
}

Slice DateCoder::DeCodeDate(Slice input, string& data)
{
    int32_t encode;
    input = IntCoder::DecodeVarSInt32(input, encode);
    if (!ConvertInt32ToDate(encode, data)) {
        LOG_WARN("Disk format is wrong");
        return input;
    }
    return input;
}

bool DateCoder::ConvertDateToInt32(const string& data, int32_t& encode)
{
    if (!Utils::CheckDate(data)) {
        return false;
    }

    /// Get delt encode
    encode = GetBaseEncode(data) - BaseDateEncode;
    return true;
}

bool DateCoder::ConvertInt32ToDate(int32_t encode, string& date)
{
    encode += BaseDateEncode;
    date = DateCoder::GetDateFromBaseEncode(encode);
    
    /// TODO: directly check encode
    if (!Utils::CheckDate(date)) {
        return false;
    }
    
    return true;
}

int32_t DateCoder::GetBaseEncode(const string& data)
{
    int year, month, day;
    sscanf(data.c_str(), "%d-%d-%d", &year, &month, &day);
    assert(year >= 0 && month >= 1 && month <= 12 && day >= 1 && day <= 31);
    int encode = year * 31 * 12 + month * 31 + day - 1;
    return encode;
}

string DateCoder::GetDateFromBaseEncode(int32_t encode)
{
    int year, month, day;
    year = encode / (31 * 12);
    encode %= (31 * 12);
    month = encode / 31;
    day = encode % 31 + 1;
    return Utils::GetDate(year, month, day);
}

}