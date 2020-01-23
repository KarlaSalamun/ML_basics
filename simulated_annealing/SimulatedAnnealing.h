//
// Created by karla on 24. 10. 2019..
//

#ifndef SIMULATED_ANNEALING_SIMULATEDANNEALING_H
#define SIMULATED_ANNEALING_SIMULATEDANNEALING_H

#include "../optimization_function.h"
#include "CoolingScheme.h"

class SimulatedAnnealing : public OptimizationFcn {
    public:
        ~SimulatedAnnealing();
        SimulatedAnnealing(CoolingScheme *scheme, double prob, double dec) :
            scheme(scheme), init_prob(prob), prob_decrease(dec) {}
        SimulatedAnnealing(CoolingScheme *scheme ) : SimulatedAnnealing(scheme, 0.5, 0.5) {}
        std::vector<double> get_solution( std::vector<double> solution, NumericFunction *test_function );
    private:
        double compute_probability( int step );
        double init_prob;
        double prob_decrease;
        CoolingScheme *scheme;
};

#endif //SIMULATED_ANNEALING_SIMULATEDANNEALING_H
