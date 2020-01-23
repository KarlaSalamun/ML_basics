//
// Created by karla on 17. 10. 2019..
//

#ifndef PROJEKT_QUADRATIC_FUNCTION_H
#define PROJEKT_QUADRATIC_FUNCTION_H

#include "../NumericFunction.h"

class QuadraticFunction : public NumericFunction {
    public:
        double get_value( std::vector<double> &args );
        std::vector<double> get_gradient( std::vector<double> args);
        std::vector<double> get_gradient_approximation(std::vector<double> args, double delta);
        double compute_derivative( std::vector<double> point, std::vector<double> epsilon, double epsilon_scalar );
};


#endif //PROJEKT_QUADRATIC_FUNCTION_H
