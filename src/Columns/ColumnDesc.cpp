#include "ColumnDesc.h"
#include "../Utils/StringUtils.h"

using namespace std;

namespace Columns {

void ColumnDesc::SetAlis(string alis, bool isTableAlis) {
    if (!isTableAlis) {
        // Rename column name : select person as x from xxx;
        fieldName = alis;
        return;
    } 

    // Rename table name : select * from xxx as x;
    fieldName = alis + "." + Utils::GetPointAfter(fieldName);
}

}