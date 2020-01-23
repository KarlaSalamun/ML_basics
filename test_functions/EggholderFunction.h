//
// Created by karla on 24. 10. 2019..
//

#ifndef SIMULATED_ANNEALING_EGGHOLDERFUNCTION_H
#define SIMULATED_ANNEALING_EGGHOLDERFUNCTION_H

#include <vector>
#include "../NumericFunction.h"

class EggholderFunction : public NumericFunction {
public:
    double get_value( std::vector<double> args );
};

#endif //SIMULATED_ANNEALING_EGGHOLDERFUNCTION_H
