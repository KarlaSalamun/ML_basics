//
// Created by karla on 06. 11. 2019..
//
#include <cstdlib>
#include <ctime>
#include "SimpleCrossover.h"

std::vector<Solution> SimpleCrossover::get_children(std::vector<Solution> parents )
{

    srand (static_cast<double> (time(NULL)));
    std::vector<Solution> children(2, Solution(parents[0].vector.size()));
    int breakpoint = rand() % parents[0].vector.size();

    for(int i=0; i<breakpoint; i++) {
        children[0].vector[i] = parents[0].vector[i];
        children[1].vector[i] = parents[1].vector[i];
    }
    for(int i=breakpoint; i<parents[0].vector.size(); i++) {
        children[0].vector[i] = parents[1].vector[i];
        children[1].vector[i] = parents[0].vector[i];
    }
    return children;
}
