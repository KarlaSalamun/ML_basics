//
// Created by karla on 24. 10. 2019..
//

#ifndef SIMULATED_ANNEALING_GEOMETRICSCHEME_H
#define SIMULATED_ANNEALING_GEOMETRICSCHEME_H

#include "CoolingScheme.h"

class GeometricScheme : public CoolingScheme {
    public:
        GeometricScheme(double coeff, double init) : CoolingScheme(coeff, init) {}
        double get_new_temperature( int step );
};

#endif //SIMULATED_ANNEALING_GEOMETRICSCHEME_H
