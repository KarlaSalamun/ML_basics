//
// Created by karla on 17. 10. 2019..
//

#ifndef PROJEKT_FUNCTION_H
#define PROJEKT_FUNCTION_H

#include <vector>

class Function {
    private:
        double compute_derivative( std::vector<double> point, std::vector<double> epsilon, double epsilon_scalar );
    public:
        virtual double get_value( std::vector<double> args ) = 0;
        std::vector<double> get_gradient_approximation( std::vector<double> args, double delta);
        virtual std::vector<double> get_gradient( std::vector<double> args ) {
            return std::vector<double> (args.size(), 0);
        };
};

#endif //PROJEKT_FUNCTION_H
