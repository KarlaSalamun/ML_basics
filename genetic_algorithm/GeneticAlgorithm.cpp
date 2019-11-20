//
// Created by karla on 06. 11. 2019..
//

#include <cstdlib>
#include <cmath>
#include <cassert>
#include <iostream>
#include <algorithm>
#include "GeneticAlgorithm.h"
#include "UniformMutation.h"

using namespace std;

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

void GeneticAlgorithm::set_selection(SelectionOperator *selection){
    delete this->selection;
    this->selection = selection;
}


std::vector<Solution> GeneticAlgorithm::get_best_members(std::vector<Solution> population,
        Function *test_function )
{
    std::vector<Solution> best_members;
    std::sort(population.begin(), population.end(),
              [](const Solution& a, const Solution& b) {
                  return (a.fitness < b.fitness);
              });
    best_members.push_back(population[0]);
    best_members.push_back(population[1]);
    return best_members;
}
/*
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
 */

 void GeneticAlgorithm::evaluate_population(std::vector<Solution> &population)
{
    for ( int i=0; i<population.size(); i++ ) {
        population[i].fitness = test_function->get_value( population[i].vector );
    }

    std::sort(population.begin(), population.end(),
              [](const Solution& a, const Solution& b) {
                  return (a.fitness < b.fitness);
              });
}

void GeneticAlgorithm::add_members( std::vector<Solution> &population, std::vector<Solution> members )
{
    /*
    for ( int i=0; i<population.size(); i++ ) {
        if ( population[i].fitness == members[0].fitness || population[i].fitness == members[1].fitness ) {
            printf("duplic\n");
        }
    }
     */
    for( int i=0; i<members.size(); i++ ) {
        population.push_back(members[i]);
    }
}

std::vector<Solution> GeneticAlgorithm::create_population()
{
   std::vector<Solution> population;
   Solution solution(dim_size);
    for ( int i=0; i<population_size; i++ ) {
       for ( int j=0; j<dim_size; j++ ) {
           solution.vector[j] =  -5 + 10*(static_cast <double> (rand()) / ( static_cast <double> (RAND_MAX)));
       }
       population.push_back(solution);
   }
    return population;
}

Solution GeneticAlgorithm::get_best_result( std::vector<Solution> population )
{
    std::sort(population.begin(), population.end(),
              [](const Solution& a, const Solution& b) {
                  return (a.fitness < b.fitness);
              });
    return  population[0];
}

Solution GeneticAlgorithm::get_solution()
{
    std::vector<Solution> population = create_population();
    evaluate_population(population);
    Solution best_solution = population[0];

    std::vector<Solution> best_population = create_population();
    std::vector<Solution> parents(2, Solution(dim_size));
    std::vector<Solution> children(2, Solution(dim_size));
    extern int generations;

    for ( int i=0; i<generation_number; i++ ) {
        evaluate_population(population);
        std::vector<Solution> best_members = get_best_members(population, test_function);
        //best_members[0].print_value();
        //best_members[1].print_value();
        if(best_members[0].fitness < best_solution.fitness) {
            best_solution = best_members[0];
        }
        best_solution.print_value();
        std::vector<Solution> new_population;
        add_members( new_population, best_members );
        add_members( best_population, best_members );
        // TODO: probati reciklirati isti vektor jer je ovo suboptimalno (svaki put se radi novi vektor
        while( new_population.size() < population_size ) {
            parents = selection->get_members( population );
            children = crossover->get_children( parents );
            mutation->mutate_solution(children[0].vector );
            mutation->mutate_solution(children[1].vector );
            evaluate_population(children);
            /*
            if(children[0].fitness == children[1].fitness) {
                printf("iteration %d\n", i);
            }
             */
            add_members(new_population, children );

        }
        printf("Generation: %d/%d\n", i+1, generation_number);
        population = new_population;
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