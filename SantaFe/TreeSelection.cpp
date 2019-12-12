//
// Created by karla on 12. 12. 2019..
//

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
    std::vector<T> result;
    result.push_back(population[0]);
    result.push_back(population[1]);
    return result;
}
