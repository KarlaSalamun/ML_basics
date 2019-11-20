//
// Created by karla on 13. 11. 2019..
//

#include <cstdlib>
#include <algorithm>
#include <iterator>
#include <random>
#include "TournamentSelection.h"

std::vector<Solution> TournamentSelection::get_members(std::vector<Solution> population){
    std::vector<Solution> selected_members;
    std::vector<Solution> rand_members;

//    std::shuffle(population.begin(), population.end(), std::mt19937{std::random_device{}()});

    std::shuffle(population.begin(), population.end(), std::default_random_engine());
    rand_members.assign(population.begin(), population.begin() + sample_size );

    std::sort(rand_members.begin(), rand_members.end(),
              [](const Solution& a, const Solution& b) {
                  return (a.fitness < b.fitness);
              });

    selected_members.push_back( rand_members[0] );
    selected_members.push_back( rand_members[1] );

    return selected_members;
}
