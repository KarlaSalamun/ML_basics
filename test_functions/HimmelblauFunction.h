//
// Created by karla on 23. 10. 2019..
//

#ifndef SIMULATED_ANNEALING_HIMMELBLAUFUNCTION_H
#define SIMULATED_ANNEALING_HIMMELBLAUFUNCTION_H

#include <vector>
#include "../NumericFunction.h"

class HimmelblauFunction : public NumericFunction {
    public:
        double get_value( std::vector<double> &args );
};


#endif //SIMULATED_ANNEALING_HIMMELBLAUFUNCTION_H
