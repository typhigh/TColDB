#pragma once
#include <string>
#include <memory>
namespace Optimizer {

class Rule
{
private:
    /* data */

public:
    Rule(/* args */);
    virtual ~Rule();

};
using RulePtr = std::shared_ptr<Rule>;

}