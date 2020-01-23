//
// Created by karla on 13. 11. 2019..
//

#include <cstdlib>
#include <algorithm>
#include <iterator>
#include <random>
#include "TournamentSelection.h"

template <typename T>
void TournamentSelection<T>::get_members(std::vector<T> &population, std::vector<T> &members )
{
    std::vector<T> rand_members;

//    std::shuffle(population.begin(), population.end(), std::mt19937{std::random_device{}()});

    std::shuffle(population.begin(), population.end(), std::default_random_engine());
    rand_members.assign(population.begin(), population.begin() + sample_size );

    std::sort(rand_members.begin(), rand_members.end(),
              [](const T& a, const T& b) {
                  return (a.fitness < b.fitness);
              });

    members[0] = rand_members[0];
    members[1] = rand_members[1];
}
