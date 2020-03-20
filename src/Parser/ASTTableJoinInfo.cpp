#include "ASTTableJoinInfo.h"
using namespace std;

namespace Parser {

string ASTTableJoinInfo::ToString() const 
{
    return "ASTTableJoinInfo";
}

Plan::PlanPtr ASTTableJoinInfo::MakePlan() const 
{
    return Plan::PlanPtr();
}
}