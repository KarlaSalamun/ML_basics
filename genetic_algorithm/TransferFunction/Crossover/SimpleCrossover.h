//
// Created by karla on 06. 11. 2019..
//

#ifndef GENETIC_ALGORITHM_SIMPLECROSSOVER_H
#define GENETIC_ALGORITHM_SIMPLECROSSOVER_H


#include "../../CrossoverOperator.h"

template <typename T>
class SimpleCrossover : public CrossoverOperator<T> {
    public:
        void get_children(std::vector<T> &parents, std::vector<T> &children );
};


#endif //GENETIC_ALGORITHM_SIMPLECROSSOVER_H
