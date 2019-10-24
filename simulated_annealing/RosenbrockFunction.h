//
// Created by karla on 24. 10. 2019..
//

#ifndef SIMULATED_ANNEALING_ROSENBROCKFUNCTION_H
#define SIMULATED_ANNEALING_ROSENBROCKFUNCTION_H

#include <vector>
#include "function.h"

class RosenbrockFunction : public Function {
public:
    double get_value( std::vector<double> args );

    std::vector<double> get_gradient( std::vector<double> args ) {
        std::vector<double> dummy(args.size(), 0);
        return dummy;
    };
};


#endif //SIMULATED_ANNEALING_ROSENBROCKFUNCTION_H
