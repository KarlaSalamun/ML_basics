//
// Created by karla on 06. 11. 2019..
//

#ifndef GENETIC_ALGORITHM_SIMPLECROSSOVER_H
#define GENETIC_ALGORITHM_SIMPLECROSSOVER_H


#include "CrossoverOperator.h"

class SimpleCrossover : public CrossoverOperator {
    std::vector<std::vector<double>> get_children ( std::vector<std::vector<double>> parents );
};


#endif //GENETIC_ALGORITHM_SIMPLECROSSOVER_H
