//
// Created by karla on 24. 10. 2019..
//

#ifndef SIMULATED_ANNEALING_LINEARSCHEME_H
#define SIMULATED_ANNEALING_LINEARSCHEME_H

#include "CoolingScheme.h"

class LinearScheme : public CoolingScheme {
    public:
        void update_temperature( int step, double &temp );
};

#endif //SIMULATED_ANNEALING_LINEARSCHEME_H
