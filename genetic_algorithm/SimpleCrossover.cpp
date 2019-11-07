//
// Created by karla on 06. 11. 2019..
//
#include <cstdlib>
#include <ctime>
#include "SimpleCrossover.h"

std::vector<std::vector<double>> SimpleCrossover::get_children(std::vector<std::vector<double>> parents){

    srand (static_cast<double> (time(NULL)));
    std::vector<std::vector<double>> children(2, std::vector<double>(parents[0].size(), 0));
    int breakpoint = rand() % parents[0].size();

    for(int i=0; i<breakpoint; i++) {
        children[0][i] = parents[0][i];
        children[1][i] = parents[1][i];
    }
    for(int i=breakpoint; i<parents[0].size(); i++) {
        children[0][i] = parents[1][i];
        children[1][i] = parents[0][i];
    }
    return children;
}
