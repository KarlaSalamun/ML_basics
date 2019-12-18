//
// Created by karla on 12. 12. 2019..
//

#include <algorithm>
#include <random>
#include <cassert>
#include "TreeSelection.h"
/*
std::vector<Solution<AbstractNode *>> TreeSelection::get_members(std::vector<Solution<AbstractNode *>> population) {
    std::vector<Solution<AbstractNode *>> result;
    result.push_back(population[0]);
    result.push_back(population[1]);
    return result;
}
*/

template <typename T>
std::vector<T> TreeSelection<T>::get_members(std::vector<T> population)
{
    std::vector<T> selected_members;
    std::vector<T> rand_members;

//    std::shuffle(population.begin(), population.end(), std::mt19937{std::random_device{}()});

    std::shuffle(population.begin(), population.end(), std::default_random_engine());
    rand_members.assign(population.begin(), population.begin() + 7 );

    std::sort(rand_members.begin(), rand_members.end(),
              [](const T& a, const T& b) {
                  return (a.fitness <= b.fitness);
              });

    selected_members.push_back( rand_members[0] );
    selected_members.push_back( rand_members[1] );

    return selected_members;
}
