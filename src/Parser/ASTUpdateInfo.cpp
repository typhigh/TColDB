#include "ASTUpdateInfo.h"
using namespace std;

namespace Parser {

string ASTUpdateInfo::ToString() const 
{
    return "ASTUpdateInfo";
}

Plan::PlanPtr ASTUpdateInfo::MakePlan() const 
{
    return Plan::PlanPtr();
}

}