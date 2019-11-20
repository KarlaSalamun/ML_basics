//
// Created by karla on 14. 11. 2019..
//
#include <random>
#include <algorithm>
#include "RouletteSelection.h"

std::vector<Solution> RouletteSelection::get_members(std::vector<Solution> population){
    std::vector<Solution> selected_members;
    int i,j;
    double fit_sum = 0;
    std::vector<Solution> rand_population;
    rand_population.assign(population.begin(), population.end() );
    double max_fitness = rand_population[rand_population.size()-1].fitness;

    for (int i=0; i<rand_population.size(); i++) {
        rand_population[i].fitness = max_fitness - rand_population[i].fitness;
        fit_sum += rand_population[i].fitness;
    }

    double sum_prob = 0;
    std::vector<double> len(rand_population.size(), 0);
    for (i=0; i<rand_population.size(); i++) {
        double prob = rand_population[i].fitness / fit_sum;
        len[i] = sum_prob + prob;
        sum_prob += prob;
    }
    for (j=0; j<2; j++) {
        double rand_interval = static_cast <double> (rand()) / (static_cast <double> (RAND_MAX));
        for (i = 0; i < rand_population.size() - 1; i++) {
            if (rand_interval > len[i] && rand_interval < len[i + 1]) {
                break;
            }
        }
        selected_members.push_back(rand_population[i]);
    }
    return selected_members;
}
