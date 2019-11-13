//
// Created by karla on 06. 11. 2019..
//

#ifndef GENETIC_ALGORITHM_SIMPLECROSSOVER_H
#define GENETIC_ALGORITHM_SIMPLECROSSOVER_H


#include "CrossoverOperator.h"

class SimpleCrossover : public CrossoverOperator {
    public:
        std::vector<Solution> get_children(std::vector<Solution> parents );
};


#endif //GENETIC_ALGORITHM_SIMPLECROSSOVER_H
