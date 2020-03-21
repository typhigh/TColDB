#include "ASTCreator.h"

using namespace std;
namespace Parser {

ExprNode* ASTCreator::MakeExprNode() 
{
    return new ExprNode();
}

}
