//
// Created by karla on 12. 12. 2019..
//

#include <algorithm>
#include <random>
#include <cstdlib>
#include <cassert>
#include "TreeSelection.h"
#include "GeneticAlgorithm.h"
/*
std::vector<Solution<AbstractNode *>> TreeSelection::get_members(std::vector<Solution<AbstractNode *>> population) {
    std::vector<Solution<AbstractNode *>> result;
    result.push_back(population[0]);
    result.push_back(population[1]);
    return result;
}
*/
template <typename T>
void TreeSelection<T>::get_members( std::vector<T> population, std::vector<T> &members )
{
    std::vector<T> rand_members;
    members.clear();

//    std::shuffle(population.begin(), population.end(), std::mt19937{std::random_device{}()});

    //std::shuffle(population.begin(), population.end(), std::default_random_engine());
    rand_members.assign(population.begin(), population.begin() + 4 );

    qsort( rand_members.data(), rand_members.size(), sizeof(T), compare_members );
    /*
    std::sort(rand_members.begin(), rand_members.end(),
              [](const T& a, const T& b) {
                  return (a.fitness <= b.fitness);
              });
    */
    members.push_back( move( rand_members[0] ) );
    members.push_back( move( rand_members[1] ) );

}
