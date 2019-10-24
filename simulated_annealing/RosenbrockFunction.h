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
};


#endif //SIMULATED_ANNEALING_ROSENBROCKFUNCTION_H
