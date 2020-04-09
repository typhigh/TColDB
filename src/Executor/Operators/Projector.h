#pragma once
#include "../../Parser/defs.h"
#include "../../Parser/ExprNode.h"
#include "../../Parser/Expression/Expression.h"
#include "../../Plan/Plan.h"
#include <memory>
#include <vector>
namespace Executor {

#define YET_UNKNOWN -1
#define NOT_COLREF  -2 

class Projector
{
private:
    // If >= 0 means fieldNo, o.w. means NULL or EXPR
    std::vector<int> fieldsNo;
    Parser::ExprNodeList* exprs = nullptr;

public:
    Projector() {}
    ~Projector() {}
    Projector(const Parser::ExprNodeList* exprs);
    int GetFieldsNo(size_t kth) const;
    void SetFieldsNo(size_t kth, int no);
    Plan::FieldNames GetColumnsRef() const;
};

using ProjectorPtr = std::shared_ptr<Projector>;
}