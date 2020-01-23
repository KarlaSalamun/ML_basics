//
// Created by karla on 23. 10. 2019..
//

#ifndef SIMULATED_ANNEALING_RASTRIGINFUNCTION_H
#define SIMULATED_ANNEALING_RASTRIGINFUNCTION_H

#include <vector>
#include "../NumericFunction.h"

class RastriginFunction : public NumericFunction {
    public:
        double get_value( std::vector<double> &args );
        std::vector<double> get_gradient_approximation(std::vector<double> args, double delta) {}
};

#endif //SIMULATED_ANNEALING_RASTRIGINFUNCTION_H
