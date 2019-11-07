//
// Created by karla on 06. 11. 2019..
//
#include "ArithmeticCrossover.h"

std::vector<std::vector<double>> ArithmeticCrossover::get_children(std::vector<std::vector<double>> parents)
{
    std::vector<std::vector<double>> children(2, std::vector<double>(parents[0].size(), 0));

    for(int i=0; i<parents[0].size(); i++) {
        children[0][i] = lambda * parents[0][i] + (1 - lambda) * parents[1][i];
        children[1][i] = lambda * parents[1][i] + (1 - lambda) * parents[0][i];
    }
    return children;
}