//
// Created by karla on 06. 11. 2019..
//

#ifndef GENETIC_ALGORITHM_NORMALMUTATION_H
#define GENETIC_ALGORITHM_NORMALMUTATION_H

#include "../../MutationOperator.h"

template <typename T>
class NormalMutation : public MutationOperator<T> {
    public:
        NormalMutation( double deviation ) : deviation(deviation) {}
        void mutate_solution ( T &solution );

    private:
        double deviation;
};


#endif //GENETIC_ALGORITHM_NORMALMUTATION_H
