//
// Created by karla on 06. 11. 2019..
//

#ifndef GENETIC_ALGORITHM_GENETICALGORITHM_H
#define GENETIC_ALGORITHM_GENETICALGORITHM_H

#include "../optimization_function.h"
#include "../genetic_algorithm/CrossoverOperator.h"
#include "../genetic_algorithm/MutationOperator.h"
#include "../genetic_algorithm/SelectionOperator.h"
#include "../Solution.h"

template <typename T>
class GeneticAlgorithm  {
    public:
        GeneticAlgorithm( CrossoverOperator<Solution<T>> *crossover, MutationOperator<Solution<T>> *mutation, SelectionOperator<Solution<T>> *selection, Function<Solution<T>> *test_function, int generation_number, int population_size, int dim_size ) :
            crossover(crossover), mutation(mutation), selection(selection), test_function(test_function), generation_number(generation_number), population_size(population_size), dim_size(dim_size) {}
        ~GeneticAlgorithm()
        {
            delete crossover;
            delete mutation;
        }
        Solution<T> get_solution ( std::vector<Solution<T>> population );
        void set_crossover ( CrossoverOperator<Solution<T>> *crossover )
        {
            delete this->crossover;
            this->crossover = crossover;
        }
        void set_mutation ( MutationOperator<Solution<T>> *mutation )
        {
            delete this->mutation;
            this->mutation = mutation;
        }
        void set_selection ( SelectionOperator<Solution<T>> *selection )
        {
            delete this->selection;
            this->selection = selection;
        }
        CrossoverOperator<Solution<T>> *crossover;
private:
        std::vector<Solution<T>> get_best_members ( std::vector<Solution<T>> population, Function<Solution<T>> *test_function );
        void evaluate_population ( std::vector<Solution<T>> &population );
        void add_members( std::vector<Solution<T>> &population,std::vector<Solution<T>> members );
        std::vector<Solution<T>> create_population();
        Solution<T> get_best_result( std::vector<Solution<T>> population );
        MutationOperator<Solution<T>> *mutation = nullptr;
        SelectionOperator<Solution<T>> *selection = nullptr;
        int generation_number, population_size, dim_size;
        Function<Solution<T>> *test_function = nullptr;
};



#endif //GENETIC_ALGORITHM_GENETICALGORITHM_H
