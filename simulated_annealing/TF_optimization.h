//
// Created by karla on 30. 10. 2019..
//

#ifndef SIMULATED_ANNEALING_TF_OPTIMIZATION_H
#define SIMULATED_ANNEALING_TF_OPTIMIZATION_H


#include "../function.h"
#include "../NumericFunction.h"

class TFOptimization : public NumericFunction {
    public:
        TFOptimization( std::vector<std::vector<double>> x, std::vector<double> y ) : x(x), y(y) {}
        double get_value( std::vector<double> &args );
        std::vector<double> get_gradient_approximation(std::vector<double> args, double delta) {}
    private:
        std::vector<std::vector<double>> x;
        std::vector<double> y;
};


#endif //SIMULATED_ANNEALING_TF_OPTIMIZATION_H
