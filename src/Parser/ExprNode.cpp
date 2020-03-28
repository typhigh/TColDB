#include "ExprNode.h"
#include "ASTCreator.h"
using namespace std;

namespace Parser {

ExprNode::ExprNode() 
{
    val_i = 0;
    right = nullptr;
    op = OPERATOR_NONE;
    term_type = TERM_NONE;

    constVal = nullptr;
}

}
