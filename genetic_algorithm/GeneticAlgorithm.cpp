//
// Created by karla on 06. 11. 2019..
//

#include <cstdlib>
#include <cmath>
#include <cassert>
#include <iostream>
#include "GeneticAlgorithm.h"
#include "UniformMutation.h"

GeneticAlgorithm::~GeneticAlgorithm()
{
    delete crossover;
    delete mutation;
}

void GeneticAlgorithm::set_crossover( CrossoverOperator *crossover )
{
    // TODO: ako se napravi smart pointer, ovdje se radi move
    delete this->crossover;
    this->crossover = crossover;
}

void GeneticAlgorithm::set_mutation( MutationOperator *mutation )
{
    // ako je mutation smart pointer ovo je visak...
    delete this->mutation;
    this->mutation = mutation;
}

std::vector<std::vector<double>> GeneticAlgorithm::get_best_members(std::vector<std::vector<double>> population,
        Function *test_function )
{
    std::vector<std::vector<double>> best_members(2, std::vector<double>(population[0].size(), 0));
    best_members[0] = population[0];
    double fitness, best_fitness;
    int best_index = 0;
    best_fitness = test_function->get_value(population[0]);
    for(int i=1; i<population.size(); i++) {
        fitness = test_function->get_value( population[i] );
        if( fitness < best_fitness ) {
            best_members[0] = population[i];
            best_index = i;
            best_fitness = fitness;
        }
    }
    if ( best_index == 0 ) {
        best_fitness = test_function->get_value( population[1] );
        best_members[1] = population[1];
    } else {
        best_fitness = test_function->get_value( population[0] );
        best_members[1] = population[0];
    }
    for(int i=1; i<population.size(); i++) {
        if(i == best_index) {
            continue;
        }
        fitness = test_function->get_value( population[i] );
        if( fitness < best_fitness ) {
            best_members[1] = population[i];
            best_fitness = fitness;
        }
    }
    return best_members;
}

std::vector<std::vector<double>> GeneticAlgorithm::get_parents(std::vector<std::vector<double>> population)
{
    std::vector<std::vector<double>> parents(2, std::vector<double>(dim_size, 0));
    for(int i=0; i<2; i++) {
        int rand_index = rand() % population.size();
        for (int j = 0; j < dim_size; j++) {
            parents[i][j] = population[rand_index][j];
        }
    }
    return parents;
}

std::vector<double> GeneticAlgorithm::evaluate_population(std::vector<std::vector<double>> population, Function *test_function)
{
    std::vector<double> best_result = population[0];
    double best_fitness = test_function->get_value(best_result);
    for ( int i=1; i<population.size(); i++ ) {
        if( test_function->get_value(population[i]) < best_fitness ) {
            best_result = population[i];
        }
    }
    return best_result;
}

void GeneticAlgorithm::add_members( std::vector<std::vector<double>> &population, std::vector<std::vector<double>> members )
{
    for ( int i=0; i<members.size(); i++ ) {
        population.push_back(members[i]);
    }
}

std::vector<std::vector<double>> GeneticAlgorithm::create_population(){
   std::vector<std::vector<double>> population( population_size, std::vector<double>(dim_size, 0));
    for ( int i=0; i<population_size; i++ ) {
       for ( int j=0; j<dim_size; j++ ) {
           population[i][j] = -5 + 10*(static_cast <double> (rand()) / ( static_cast <double> (RAND_MAX)));
       }
   }
    return population;
}

std::vector<double> GeneticAlgorithm::get_solution( std::vector<double> solution, Function *test_function )
{
    std::vector<std::vector<double>> population = create_population();
    std::vector<std::vector<double>> parents(2, std::vector<double>(dim_size, 0));
    std::vector<std::vector<double>> children(2, std::vector<double>(dim_size, 0));
    extern int generations;

    for ( int i=0; i<generation_number; i++ ) {
        std::vector<double> best_result = evaluate_population( population, test_function );
        std::vector<std::vector<double>> best_members = get_best_members(population, test_function);
        assert( test_function->get_value(best_members[0]) < test_function->get_value(best_members[1]) );
        //printf("value of best members: %lf %lf \n",
         //       test_function->get_value(best_members[0]), test_function->get_value(best_members[1]) );
        std::vector<std::vector<double>> new_population;
        add_members( new_population, best_members );

        // TODO: probati reciklirati isti vektor jer je ovo suboptimalno (svaki put se radi novi vektor
        while( new_population.size() < population_size ) {
            parents = get_parents( population );
            children = crossover->get_children( parents );
            mutation->mutate_solution(children[0]);
            mutation->mutate_solution(children[1]);
            add_members(new_population, children);
        }
        //printf("Generation: %d/1000\n", i+1);
        population = new_population;
/*
        if( test_function->get_value( evaluate_population( population, test_function ) ) == static_cast<double> (0) ) {
            generations++;
            break;
        }
*/
    }

    return evaluate_population( population, test_function );
}