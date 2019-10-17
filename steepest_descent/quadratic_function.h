//
// Created by karla on 17. 10. 2019..
//

#ifndef PROJEKT_QUADRATIC_FUNCTION_H
#define PROJEKT_QUADRATIC_FUNCTION_H

#include "function.h"

class QuadraticFunction : public Function {
    public:
        double get_value( std::vector<double> args );
        std::vector<double> get_gradient( std::vector<double> args);
};


#endif //PROJEKT_QUADRATIC_FUNCTION_H
