//
// Created by karla on 06. 11. 2019..
//

#ifndef GENETIC_ALGORITHM_NORMALMUTATION_H
#define GENETIC_ALGORITHM_NORMALMUTATION_H

#include "MutationOperator.h"

class NormalMutation : public MutationOperator {
    public:
        NormalMutation( double deviation ) : deviation(deviation) {}
        void mutate_solution( std::vector<double> &solution );

    private:
        double deviation;
};


#endif //GENETIC_ALGORITHM_NORMALMUTATION_H
