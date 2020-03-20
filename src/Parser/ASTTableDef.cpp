#include "ASTTableDef.h"
using namespace std;

namespace Parser {

string ASTTableDef::ToString() const 
{
    return "ASTTableDef";
}

Plan::PlanPtr ASTTableDef::MakePlan() const 
{
    return Plan::PlanPtr();
}

}