//
// Created by karla on 12. 12. 2019..
//

#ifndef SANTAFE_DOUBLEFUNCTION_H
#define SANTAFE_DOUBLEFUNCTION_H

#include "../function.h"

class DoubleFunction : public Function {
    private:
        double compute_derivative( std::vector<Solution<double>> point, std::vector<double> epsilon, double epsilon_scalar );
    public:
        double get_value( std::vector<Solution<double>> args );
        std::vector<double> get_gradient_approximation( std::vector<Solution<double>> args, double delta);
        std::vector<double> get_gradient( std::vector<Solution<double>> args ) {
            return std::vector<Solution<double>> (args.size(), 0);
        };
    };
};


#endif //SANTAFE_DOUBLEFUNCTION_H
