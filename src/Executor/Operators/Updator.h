#include "../../Parser/ExprNode.h"
#include "../../Columns/Field/Field.h"
namespace Executor {

class Updator
{
private:
    Parser::ExprNode* value;

public:
    Updator(Parser::ExprNode* value);
    ~Updator();
};

using UpdatorPtr = std::shared_ptr<Updator>;

}