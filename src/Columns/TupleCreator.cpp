#include "TupleCreator.h"
using namespace std;

namespace Columns {

TuplePtr TupleCreator::CreateTuple(TupleDescPtr desc)
{
    return make_shared<Tuple>(desc);
}

}