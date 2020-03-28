#include "ASTCreator.h"

using namespace std;
namespace Parser {

ExprNode* ASTCreator::MakeExprNode() 
{
    return new ExprNode();
}

ExprNode* ASTCreator::FreeExprNode(ExprNode* expr)
{
    delete expr;
}

}
