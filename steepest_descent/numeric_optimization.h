//
// Created by karla on 18. 10. 2019..
//

#ifndef STEEPEST_DESCENT_NUMERIC_OPTIMIZATION_H
#define STEEPEST_DESCENT_NUMERIC_OPTIMIZATION_H

#include <vector>
#include "optimization_function.h"
#include "function.h"
#include "quadratic_function.h"

class NumericOptimization : public OptimizationFcn {
    public:
        std::vector<double> get_solution( std::vector<double> solution, Function *test_function );
};

#endif //STEEPEST_DESCENT_NUMERIC_OPTIMIZATION_H
