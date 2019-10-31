//
// Created by karla on 30. 10. 2019..
//

#ifndef SIMULATED_ANNEALING_TF_OPTIMIZATION_H
#define SIMULATED_ANNEALING_TF_OPTIMIZATION_H


#include "../function.h"

class TFOptimization : public Function {
    public:
        TFOptimization( std::vector<std::vector<double>> x, std::vector<double> y ) : x(x), y(y) {}
        double get_value( std::vector<double> args );
    private:
        std::vector<std::vector<double>> x;
        std::vector<double> y;
};


#endif //SIMULATED_ANNEALING_TF_OPTIMIZATION_H
