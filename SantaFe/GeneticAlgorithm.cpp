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

    qsort( population.data(), population.size(), sizeof(T), compare_members );

    /*
    std::sort(population.begin(), population.end(),
              [](const T& a, const T& b) {
                  return (a.fitness < b.fitness);
              });
              */
    best_members.push_back(move(population[0]));
    best_members.push_back(move(population[1]));
    return best_members;
}

template <typename T>
 void GeneticAlgorithm<T>::evaluate_population(std::vector<T> &population, int size )
{
    for ( size_t i=0; i<size; i++ ) {
        test_function->get_value( population[i] );
    }

    qsort( population.data(), size, sizeof(T), compare_members );

    /*
    std::sort(population.begin(), population.end(),
              [](const T& a, const T& b) {
                  return (a.fitness < b.fitness);
              });
              */
}

template <typename T>
void GeneticAlgorithm<T>::add_members( std::vector<T> &population, std::vector<T>& members, int size )
{

    for( int i=0; i<members.size(); i++ ) {
        population[size + i] = move( members[i] );
        delete members[i].data;
    }
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
void GeneticAlgorithm<T>::get_solution ( std::vector<T> &population, T& result )
{

    for ( size_t i=0; i<generation_number; i++ ) {
        std::vector<T> best_members(2);
        std::vector<T> parents(2);
        std::vector<T> children(2);
        std::vector<T> new_population( population.size() );
        int new_size = 0;

        evaluate_population(population, population.size() );

        best_members[0] = population[0];
        best_members[1] = population[1];
/*
        population[0].data->copy_tree( population[0].data, best_members[0].data );
        population[1].data->copy_tree( population[1].data, best_members[1].data );

        best_members[0].fitness = population[0].fitness;
        best_members[1].fitness = population[1].fitness;
*/
        add_members( new_population, best_members, new_size );
        new_size += best_members.size();

        evaluate_population( new_population, new_size );

        // TODO: probati reciklirati isti vektor jer je ovo suboptimalno (svaki put se radi novi vektor
        while( new_size < population_size ) {

            selection->get_members( population, parents );

            crossover->get_children( parents, children );
            mutation->mutate_solution( children[0] );
            mutation->mutate_solution( children[1] );
            //assert( children[0].data->depth <= 5 );
            //assert( children[1].data->depth <= 5 );

            add_members(new_population, children, new_size );
            new_size += children.size();
        }

        //population.clear();
        for ( size_t j=0; j<new_population.size(); j++ ) {
            //population.push_back(move(new_population[j]));
            population[j] = move( new_population[j] );
            delete new_population[j].data;
        }
        printf("generation[%lu]\tbest members: %f %f \n", i, population[0].fitness, population[1].fitness );
    }
    evaluate_population(population, population.size() );
    result = move( population[0] );
}


