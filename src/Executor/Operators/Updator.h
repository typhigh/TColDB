#pragma once
#include "../../Parser/ExprNode.h"
#include "../../Columns/Field/Field.h"
#include "../../Plan/Plan.h"
namespace Executor {

class Updator
{
private:
    Parser::ExprNode* value;

public:
    Updator(Parser::ExprNode* value);
    ~Updator();
    Plan::FieldNames GetColumnsRef() const;
};

using UpdatorPtr = std::shared_ptr<Updator>;

}