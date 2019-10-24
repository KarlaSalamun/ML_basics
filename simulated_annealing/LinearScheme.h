//
// Created by karla on 24. 10. 2019..
//

#ifndef SIMULATED_ANNEALING_LINEARSCHEME_H
#define SIMULATED_ANNEALING_LINEARSCHEME_H

#include "CoolingScheme.h"

class LinearScheme : public CoolingScheme {
    public:
        LinearScheme(double coeff, double init) : CoolingScheme(coeff, init) {}
        double get_new_temperature( int step );
};

#endif //SIMULATED_ANNEALING_LINEARSCHEME_H
