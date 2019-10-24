//
// Created by karla on 24. 10. 2019..
//

#ifndef SIMULATED_ANNEALING_SIMULATEDANNEALING_H
#define SIMULATED_ANNEALING_SIMULATEDANNEALING_H

#include "../optimization_function.h"

class SimulatedAnnealing : public OptimizationFcn {
    public:
        std::vector<double> get_solution( std::vector<double> solution, Function *test_function );
    private:
        void temp_schedule( int cnt, double &temp );
        double compute_probability( int step );
        const double TEMP_COEFF = 0.99;
        const double INIT_TEMP = 10e5;
        const double  INIT_PROB = 0.5;
        const double PROB_DECREASE = 0.5;
};


#endif //SIMULATED_ANNEALING_SIMULATEDANNEALING_H
