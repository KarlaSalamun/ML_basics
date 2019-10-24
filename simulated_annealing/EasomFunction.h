//
// Created by karla on 24. 10. 2019..
//

#ifndef SIMULATED_ANNEALING_EASOMFUNCTION_H
#define SIMULATED_ANNEALING_EASOMFUNCTION_H

#include "function.h"

class EasomFunction : public Function {
    public:
        double get_value( std::vector<double> args );
};


#endif //SIMULATED_ANNEALING_EASOMFUNCTION_H
