//
// Created by karla on 18. 10. 2019..
//

#ifndef STEEPEST_DESCENT_OPTIMIZATION_FUNCTION_H
#define STEEPEST_DESCENT_OPTIMIZATION_FUNCTION_H
#include <vector>
#include "function.h"
#include "quadratic_function.h"

class OptimizationFcn {
public:
    virtual std::vector<double> get_solution( std::vector<double> solution, Function *test_function ) = 0;
};

#endif //STEEPEST_DESCENT_OPTIMIZATION_FUNCTION_H
