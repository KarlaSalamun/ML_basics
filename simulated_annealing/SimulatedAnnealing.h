//
// Created by karla on 24. 10. 2019..
//

#ifndef SIMULATED_ANNEALING_SIMULATEDANNEALING_H
#define SIMULATED_ANNEALING_SIMULATEDANNEALING_H

#include "../optimization_function.h"
#include "CoolingScheme.h"

class SimulatedAnnealing : public OptimizationFcn {
    public:
        SimulatedAnnealing( CoolingScheme *scheme );
        std::vector<double> get_solution( std::vector<double> solution, Function *test_function );
    private:
        double compute_probability( int step );
        const double  INIT_PROB = 0.5;
        const double PROB_DECREASE = 0.5;
        CoolingScheme *scheme;
};

#endif //SIMULATED_ANNEALING_SIMULATEDANNEALING_H
