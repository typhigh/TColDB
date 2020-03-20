#include "ASTDeleteInfo.h"

using namespace std;
namespace Parser {

string ASTDeleteInfo::ToString() const 
{
    return "ASTDeleteInfo";
}

Plan::PlanPtr ASTDeleteInfo::MakePlan() const 
{
    return Plan::PlanPtr();
}

}