//
// Created by karla on 06. 11. 2019..
//
#include <random>
#include "NormalMutation.h"

void NormalMutation::mutate_solution(std::vector<double> &solution)
{
    std::default_random_engine generator;
    std::normal_distribution<double> distribution(0, deviation);

    for(int i=0; i<solution.size(); i++) {
        solution[i] += distribution(generator) * deviation;
    }
}