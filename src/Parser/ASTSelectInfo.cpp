#include "ASTSelectInfo.h"
using namespace std;

namespace Parser {
string ASTSelectInfo::ToString() const 
{
    return "ASTSelectInfo";
}

Plan::PlanPtr ASTSelectInfo::MakePlan() const 
{
    return Plan::PlanPtr();
}

}