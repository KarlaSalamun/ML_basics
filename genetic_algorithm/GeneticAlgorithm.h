//
// Created by karla on 06. 11. 2019..
//

#ifndef GENETIC_ALGORITHM_GENETICALGORITHM_H
#define GENETIC_ALGORITHM_GENETICALGORITHM_H

#include "../optimization_function.h"
#include "CrossoverOperator.h"
#include "MutationOperator.h"

class GeneticAlgorithm : public OptimizationFcn {
    public:
        GeneticAlgorithm( CrossoverOperator *crossover, MutationOperator *mutation, int generation_number, int population_size, int dim_size ) :
            crossover(crossover), mutation(mutation), generation_number(generation_number), population_size(population_size), dim_size(dim_size) {}
        ~GeneticAlgorithm();
        std::vector<double> get_solution ( std::vector<double> solution, Function *test_function );
        void set_crossover ( CrossoverOperator *crossover );
        void set_mutation ( MutationOperator *mutation );
        CrossoverOperator *crossover;
private:
        std::vector<std::vector<double>> get_best_members ( std::vector<std::vector<double>> population, Function *test_function );
        std::vector<double> evaluate_population ( std::vector<std::vector<double>> population, Function *test_function );
        std::vector<std::vector<double>> get_parents( std::vector<std::vector<double>> population );
        void add_members( std::vector<std::vector<double>> &population,std::vector<std::vector<double>> members );
        std::vector<std::vector<double>> create_population();
        MutationOperator *mutation;
        int generation_number, population_size, dim_size;
};


#endif //GENETIC_ALGORITHM_GENETICALGORITHM_H
