//
// Created by karla on 23. 10. 2019..
//

#ifndef SIMULATED_ANNEALING_RASTRIGINFUNCTION_H
#define SIMULATED_ANNEALING_RASTRIGINFUNCTION_H


#include <vector>

class RastriginFunction {
    public:
        double get_value( std::vector<double> args );
};


#endif //SIMULATED_ANNEALING_RASTRIGINFUNCTION_H
