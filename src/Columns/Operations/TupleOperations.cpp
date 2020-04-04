#include "TupleOperations.h"
#include "TupleDescOrigin.h"
#include "../../Utils/VectorUtils.h"
using namespace std;

namespace Columns {

TupleDescPtr TupleOperations::MergeTupleDescsOnJoin(TupleDescs descs)
{
    TupleDescPtr desc = descs[0]->Clone();
    desc->SetAlis(desc->GetTableName());
    for (size_t i = 1; i < descs.size(); ++i) {
        TupleDescPtr ele = descs[i]->Clone();
        ele->SetAlis(ele->GetTableName());
        desc->MergeOnJoin(ele);
    }
    return desc;
}

}