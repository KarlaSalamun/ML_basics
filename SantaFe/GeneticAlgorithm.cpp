//
// Created by karla on 06. 11. 2019..
//

#include <cstdlib>
#include <cmath>
#include <cassert>
#include <iostream>
#include <algorithm>
#include "GeneticAlgorithm.h"
#include "../genetic_algorithm/UniformMutation.h"
#include "Population.h"

using namespace std;

template <typename T>
std::vector<Solution<T>> GeneticAlgorithm<T>::get_best_members(std::vector<Solution<T>> population,
        Function<Solution<T>> *test_function )
{
    std::vector<Solution<T>> best_members;
    std::sort(population.begin(), population.end(),
              [](const Solution<T>& a, const Solution<T>& b) {
                  return (a.fitness < b.fitness);
              });
    best_members.push_back(population[0]);
    best_members.push_back(population[1]);
    return best_members;
}

template <typename T>
 void GeneticAlgorithm<T>::evaluate_population(std::vector<Solution<T>> &population)
{
    for ( int i=0; i<population.size(); i++ ) {
        population[i].fitness = test_function->get_value( population[i].data );
        printf("population[%d]: food remaining: %d\n", i, (int)population[i].fitness );
    }

    std::sort(population.begin(), population.end(),
              [](const Solution<T>& a, const Solution<T>& b) {
                  return (a.fitness < b.fitness);
              });

}

template <typename T>
void GeneticAlgorithm<T>::add_members( std::vector<Solution<T>> &population, std::vector<Solution<T>> members )
{
    for( int i=0; i<members.size(); i++ ) {
        population.push_back(members[i]);
    }
}

template <typename T>
std::vector<Solution<T>> GeneticAlgorithm<T>::create_population()
{/*
   Population<T> *pop = new Population<T>( population_size );
//   Solution solution(dim_size);
    for ( int i=0; i<population_size; i++ ) {
       for ( int j=0; j<dim_size; j++ ) {
           solution.vector[j] =  -5 + 10*(static_cast <double> (rand()) / ( static_cast <double> (RAND_MAX)));
       }
       population.push_back(solution);
   }
//    return population;
    return*/
}

template <typename T>
Solution<T> GeneticAlgorithm<T>::get_best_result( std::vector<Solution<T>> population )
{
    std::sort(population.begin(), population.end(),
              [](const Solution<T>& a, const Solution<T>& b) {
                  return (a.fitness < b.fitness);
              });
    return  population[0];
}

template <typename T>
Solution<T> GeneticAlgorithm<T>::get_solution ( std::vector<Solution<T>> population )
{
    Solution<T> best_solution = population[0];

    std::vector<Solution<T>> parents(2);
    std::vector<Solution<T>> children(2);
    extern int generations;

    for ( int i=0; i<generation_number; i++ ) {
        evaluate_population(population);
        std::vector<Solution<T>> best_members = get_best_members(population, test_function);
        //best_members[0].print_value();
        //best_members[1].print_value();
        if(best_members[0].fitness < best_solution.fitness) {
            best_solution = best_members[0];
        }
        //best_solution.print_value();
        std::vector<Solution<T>> new_population;
        add_members( new_population, best_members );
        //add_members( best_population, best_members );
        /*
        // TODO: probati reciklirati isti vektor jer je ovo suboptimalno (svaki put se radi novi vektor
        while( new_population.size() < population_size ) {
            parents = selection->get_members( population );
            children = crossover->get_children( parents );
            mutation->mutate_solution(children[0].vector );
            mutation->mutate_solution(children[1].vector );
            evaluate_population(children);
            add_members(new_population, children );
        }
         */
        //printf("Generation: %d/%d\n", i+1, generation_number);
        //population = new_population;
/*
        if( test_function->get_value( evaluate_population( population, test_function ) ) == static_cast<double> (0) ) {
            generations++;
            break;
        }
*/
    }
    evaluate_population(population);

    return get_best_result( population );

}

