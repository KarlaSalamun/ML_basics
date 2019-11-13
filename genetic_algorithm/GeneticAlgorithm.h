//
// Created by karla on 06. 11. 2019..
//

#ifndef GENETIC_ALGORITHM_GENETICALGORITHM_H
#define GENETIC_ALGORITHM_GENETICALGORITHM_H

#include "../optimization_function.h"
#include "CrossoverOperator.h"
#include "MutationOperator.h"
#include "SelectionOperator.h"
#include "../Solution.h"

class GeneticAlgorithm  {
    public:
        GeneticAlgorithm( CrossoverOperator *crossover, MutationOperator *mutation, SelectionOperator *selection, Function *test_function, int generation_number, int population_size, int dim_size ) :
            crossover(crossover), mutation(mutation), selection(selection), test_function(test_function), generation_number(generation_number), population_size(population_size), dim_size(dim_size) {}
        ~GeneticAlgorithm();
        Solution get_solution ( );
        void set_crossover ( CrossoverOperator *crossover );
        void set_mutation ( MutationOperator *mutation );
        void set_selection ( SelectionOperator *selection );
        CrossoverOperator *crossover;
private:
        std::vector<Solution> get_best_members ( std::vector<Solution> population, Function *test_function );
        void evaluate_population ( std::vector<Solution> &population );
        void add_members( std::vector<Solution> &population,std::vector<Solution> members );
        std::vector<Solution> create_population();
        Solution get_best_result( std::vector<Solution> population );
        MutationOperator *mutation = nullptr;
        SelectionOperator *selection = nullptr;
        int generation_number, population_size, dim_size;
        Function *test_function = nullptr;
};


#endif //GENETIC_ALGORITHM_GENETICALGORITHM_H
