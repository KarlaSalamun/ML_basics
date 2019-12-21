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

using namespace std;

template <typename T>
class GeneticAlgorithm  {
    public:
        GeneticAlgorithm( CrossoverOperator<T> *crossover, MutationOperator<T> *mutation, SelectionOperator<T> *selection, Function<T> *test_function, unsigned int generation_number, size_t population_size, unsigned int dim_size ) :
            crossover(crossover), mutation(mutation), selection(selection), test_function(test_function), generation_number(generation_number), population_size(population_size), dim_size(dim_size) {}
        ~GeneticAlgorithm()
        {
            delete crossover;
            delete mutation;
        }
        T get_solution ( std::vector<T> population );
        void set_crossover ( CrossoverOperator<T> *crossover )
        {
            delete this->crossover;
            this->crossover = crossover;
        }
        void set_mutation ( MutationOperator<T> *mutation )
        {
            delete this->mutation;
            this->mutation = mutation;
        }
        void set_selection ( SelectionOperator<T> *selection )
        {
            delete this->selection;
            this->selection = selection;
        }
private:
        std::vector<T> get_best_members ( std::vector<T> population, Function<T> *test_function );
        void evaluate_population ( std::vector<T> &population );
        void add_members( std::vector<T> &population,std::vector<T> members );
        std::vector<T> create_population();
        T get_best_result( std::vector<T> population );
        CrossoverOperator<T> *crossover;
        MutationOperator<T> *mutation = nullptr;
        SelectionOperator<T> *selection = nullptr;
        Function<T> *test_function = nullptr;
        unsigned int generation_number;
        size_t population_size;
        unsigned int dim_size;
};



#endif //GENETIC_ALGORITHM_GENETICALGORITHM_H
