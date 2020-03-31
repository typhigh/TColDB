#pragma once
#include "../Plan/Plan.h"
namespace Optimizer {

class Optimizer
{
private:
    /* data */
public:
    Optimizer(/* args */) {}
    ~Optimizer() {}

    static void Optimize(Plan::PlanPtr plan);
    
private:
    static void LogicalOptimize(Plan::PlanPtr plan);
    static void PhysicalOptimize(Plan::PlanPtr plan);
};


}