//
// Created by karla on 06. 11. 2019..
//

#include <cstdlib>
#include <cmath>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include "GeneticAlgorithm.h"
#include "../genetic_algorithm/UniformMutation.h"
#include "Population.h"
#include "../Solution.h"
#include "AbstractNode.h"
#include "../Solution.cpp"

using namespace std;

template <typename T>
std::vector<T> GeneticAlgorithm<T>::get_best_members(std::vector<T> population,
        Function<T> *test_function )
{
    std::vector<T> best_members;
    std::sort(population.begin(), population.end(),
              [](const T& a, const T& b) {
                  return (a.fitness < b.fitness);
              });
    best_members.push_back(population[0]);
    best_members.push_back(population[1]);
    return best_members;
}

template <typename T>
 void GeneticAlgorithm<T>::evaluate_population(std::vector<T> &population)
{
    for ( int i=0; i<population.size(); i++ ) {
        population[i].fitness = test_function->get_value( population[i].data );
        //printf("population[%d]: food remaining: %d\n", i, (int)population[i].fitness );
    }

    std::sort(population.begin(), population.end(),
              [](const T& a, const T& b) {
                  return (a.fitness < b.fitness);
              });

}

template <typename T>
void GeneticAlgorithm<T>::add_members( std::vector<T> &population, std::vector<T> members )
{
    std::vector<T> tmp_population(2);
    for( int i=0; i<members.size(); i++ ) {
        members[i].data->copy_tree( members[i].data, tmp_population[i].data );
        //population.push_back(members[i]);
    }
    population.push_back( tmp_population[0] );
    population.push_back( tmp_population[1] );
}

template <typename T>
std::vector<T> GeneticAlgorithm<T>::create_population()
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
T GeneticAlgorithm<T>::get_best_result( std::vector<T> population )
{
    std::sort(population.begin(), population.end(),
              [](const T& a, const T& b) {
                  return (a.fitness < b.fitness);
              });
    return  population[0];
}

template <typename T>
T GeneticAlgorithm<T>::get_solution ( std::vector<T> population )
{
    for ( int i=0; i<generation_number; i++ ) {
        std::vector<T> best_members(2);
        std::vector<T> parents(2);
        std::vector<T> tmp_parents(2);
        std::vector<T> children(2);

        evaluate_population(population);

        population[0].data->copy_tree( population[0].data, best_members[0].data );
        population[1].data->copy_tree( population[1].data, best_members[1].data );
        evaluate_population( best_members );

        std::vector<T> new_population;
        add_members( new_population, best_members );
        evaluate_population( new_population );

        // TODO: probati reciklirati isti vektor jer je ovo suboptimalno (svaki put se radi novi vektor
        while( new_population.size() < population_size ) {

            parents = selection->get_members( population );
            parents[0].data->copy_tree( parents[0].data, tmp_parents[0].data );
            parents[1].data->copy_tree( parents[1].data, tmp_parents[1].data );
            children = crossover->get_children( tmp_parents );
            //children = parents;
            mutation->mutate_solution( children[0] );
            mutation->mutate_solution( children[1] );
            assert( children[0].data->depth <= 5 );
            assert( children[1].data->depth <= 5 );
            evaluate_population( children );
            add_members(new_population, children );
        }

        //printf("Generation: %d/%d\n", i+1, generation_number);
        for ( int j=0; j<population.size(); j++ ) {
            population[j] = std::move(new_population[j].data );
        }

        //population = new_population;
/*
        if( test_function->get_value( evaluate_population( population, test_function ) ) == static_cast<double> (0) ) {
            generations++;
            break;
        }
*/
        evaluate_population( population );

        printf("generation[%d]\tbest members: %f %f \n", i, population[0].fitness, population[1].fitness );
    }
    evaluate_population(population);

    //return get_best_result( population );
    return population[0];
}


