//
// Created by karla on 24. 10. 2019..
//

#ifndef SIMULATED_ANNEALING_COOLINGSCHEME_H
#define SIMULATED_ANNEALING_COOLINGSCHEME_H

class CoolingScheme {
    public:
        CoolingScheme (double coeff, double init):temp_coeff(coeff), init_temp(init) {}
        double temp_coeff;
        double init_temp;
        virtual double get_new_temperature( int step ) = 0;
};

#endif //SIMULATED_ANNEALING_COOLINGSCHEME_H
