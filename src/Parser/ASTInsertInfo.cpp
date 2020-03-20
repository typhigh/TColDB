#include "ASTInsertInfo.h"
using namespace std;

namespace Parser {

string ASTInsertInfo::ToString() const 
{
    return "ASTInsertInfo";
}

Plan::PlanPtr ASTInsertInfo::MakePlan() const 
{
    return Plan::PlanPtr();
}

}