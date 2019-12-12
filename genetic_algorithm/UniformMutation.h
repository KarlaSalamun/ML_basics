//
// Created by karla on 06. 11. 2019..
//

#ifndef GENETIC_ALGORITHM_UNIFORMMUTATION_H
#define GENETIC_ALGORITHM_UNIFORMMUTATION_H


#include "MutationOperator.h"
template <typename T>
class UniformMutation : public MutationOperator<T> {
    public:
        UniformMutation( double lim_d, double lim_u ) : lim_l(lim_l), lim_u(lim_u) {}
        void mutate_solution( std::vector<T> &solution );
    private:
        double lim_u, lim_l;
};


#endif //GENETIC_ALGORITHM_UNIFORMMUTATION_H
