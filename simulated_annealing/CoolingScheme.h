//
// Created by karla on 24. 10. 2019..
//

#ifndef SIMULATED_ANNEALING_COOLINGSCHEME_H
#define SIMULATED_ANNEALING_COOLINGSCHEME_H

class CoolingScheme {
    public:
        const double TEMP_COEFF = 100;
        const double INIT_TEMP = 10e5;
        virtual void update_temperature( int step, double &temp ) = 0;
};

#endif //SIMULATED_ANNEALING_COOLINGSCHEME_H
