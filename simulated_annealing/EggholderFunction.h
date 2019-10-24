//
// Created by karla on 24. 10. 2019..
//

#ifndef SIMULATED_ANNEALING_EGGHOLDERFUNCTION_H
#define SIMULATED_ANNEALING_EGGHOLDERFUNCTION_H

#include <vector>
#include "../function.h"

class EggholderFunction : public Function {
public:
    double get_value( std::vector<double> args );
};

#endif //SIMULATED_ANNEALING_EGGHOLDERFUNCTION_H
