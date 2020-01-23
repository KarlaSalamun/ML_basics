//
// Created by karla on 06. 11. 2019..
//
#include <random>
#include "NormalMutation.h"

template <typename T>
void NormalMutation<T>::mutate_solution(T &solution)
{
    std::default_random_engine generator;
    std::normal_distribution<double> distribution(0, deviation);

    for(int i=0; i<solution.data.size(); i++) {
        solution.data[i] += distribution(generator) * deviation;
    }
}