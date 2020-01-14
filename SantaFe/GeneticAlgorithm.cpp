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
 void GeneticAlgorithm<T>::evaluate_population(std::vector<T> &population)
{
    for ( size_t i=0; i<population.size(); i++ ) {
        population[i].fitness = test_function->get_value( population[i] );
        //printf("population[%d]: food remaining: %d\n", i, (int)population[i].fitness );
    }

    qsort( population.data(), population.size(), sizeof(T), compare_members );

    /*
    std::sort(population.begin(), population.end(),
              [](const T& a, const T& b) {
                  return (a.fitness < b.fitness);
              });
              */
}

template <typename T>
void GeneticAlgorithm<T>::add_members( std::vector<T> &population, std::vector<T>& members )
{
    size_t old_size = population.size();
    population.resize( old_size + 2 );
    for( size_t i=0; i<members.size(); i++ ) {
        members[i].data->copy_tree( members[i].data, population[old_size+i].data );
    }
   // population.push_back( tmp_population[0] );
   // population.push_back( tmp_population[1] );
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
        std::vector<T> tmp_parents(2);
        std::vector<T> children(2);
        std::vector<T> new_population;

        evaluate_population(population);

        population[0].data->copy_tree( population[0].data, best_members[0].data );
        population[1].data->copy_tree( population[1].data, best_members[1].data );
        evaluate_population( best_members );

        add_members( new_population, best_members );
        evaluate_population( new_population );

        // TODO: probati reciklirati isti vektor jer je ovo suboptimalno (svaki put se radi novi vektor
        while( new_population.size() < population_size ) {

            selection->get_members( population, parents );
            parents[0].data->copy_tree( parents[0].data, tmp_parents[0].data );
            parents[1].data->copy_tree( parents[1].data, tmp_parents[1].data );
            crossover->get_children( tmp_parents, children );
            //children = parents;
            if (children[1].data == nullptr) {
                cout << "NULL5" << endl;
            }
            mutation->mutate_solution( children[0] );
            if (children[1].data == nullptr) {
                cout << "NULL6" << endl;
            } else {
                cout << "MUTACIJA" << endl;
            }
            mutation->mutate_solution( children[1] );
            assert( children[0].data->depth <= 5 );
            assert( children[1].data->depth <= 5 );
            evaluate_population( children );
            add_members(new_population, children );
        }

        population.clear();

        for ( size_t j=0; j<new_population.size(); j++ ) {

            population.push_back(move(new_population[j]));
         //   population[j].data->copy_tree( new_population[j].data, population[j].data );
         //   population[j].fitness = new_population[j].fitness;
        }


        //population = new_population;
/*
        if( test_function->get_value( evaluate_population( population, test_function ) ) == static_cast<double> (0) ) {
            generations++;
            break;
        }
*/
       // evaluate_population( population );

        printf("generation[%lu]\tbest members: %f %f \n", i, population[0].fitness, population[1].fitness );
    }
    evaluate_population(population);
    result = move( population[0] );

}


