#include "Projector.h"
#include "../../Parser/Expression/Expression.h"
using namespace std;

namespace Executor {

Projector::Projector(const Parser::ExprNodeList* exprs) 
{
    this->exprs = Parser::Expression::Copy(exprs);

    // Not know whether if it's column ref yet
    fieldsNo = vector<int>(exprs->size(), YET_UNKNOWN);
    for (size_t i = 0; i < exprs->size(); ++i) {
        if (!Parser::Expression::IsColumnRef(exprs->at(i))) {
            // Not column ref, we use NOT_COLREF
            // o.w. we just set it at run time
            fieldsNo[i] = NOT_COLREF;
        }
    }
}

int Projector::GetFieldsNo(size_t kth) const 
{
    if (kth > fieldsNo.size()) {
        LOG_ERROR("fieldsNo out of range");
        return -1;
    }
    return fieldsNo[kth];
}

void Projector::SetFieldsNo(size_t kth, int no) 
{
    if (kth > fieldsNo.size()) {
        LOG_ERROR("fieldsNo out of range");
        return;
    }
    if (no < 0) {
        LOG_ERROR("no out of range");
        return;
    }
    fieldsNo[kth] = no;
}

Plan::FieldNames Projector::GetColumnsRef() const 
{
    return Parser::Expression::GetColumnsRef(exprs);
}

}