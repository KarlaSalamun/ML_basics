//
// Created by karla on 06. 11. 2019..
//
#include "ArithmeticCrossover.h"

std::vector<Solution> ArithmeticCrossover::get_children(std::vector<Solution> parents )
{
    std::vector<Solution> children(2, Solution(parents[0].vector.size()));

    for(int i=0; i<parents[0].vector.size(); i++) {
        children[0].vector[i] = lambda * parents[0].vector[i] + (1 - lambda) * parents[1].vector[i];
        children[1].vector[i] = lambda * parents[1].vector[i] + (1 - lambda) * parents[0].vector[i];
    }
    return children;
}