//
// Created by karla on 06. 11. 2019..
//

#ifndef GENETIC_ALGORITHM_GENETICALGORITHM_H
#define GENETIC_ALGORITHM_GENETICALGORITHM_H

#include "../optimization_function.h"
#include "../CrossoverOperator.h"
#include "../MutationOperator.h"
#include "../SelectionOperator.h"
#include "../Solution.h"
#include "AbstractNode.h"

using namespace std;

static int compare_members(const void *m1, const void *m2)
{
    const Solution<AbstractNode *>* member1 = static_cast<const Solution<AbstractNode *>*>(m1);
    const Solution<AbstractNode *>* member2 = static_cast<const Solution<AbstractNode *>*>(m2);
    return member1->fitness - member2->fitness;
}

template <typename T>
class GeneticAlgorithm  {
    public:
        GeneticAlgorithm( CrossoverOperator<T> *crossover, MutationOperator<T> *mutation, SelectionOperator<T> *selection, Function<T> *test_function, unsigned int generation_number, size_t population_size, unsigned int dim_size ) :
            crossover(crossover), mutation(mutation), selection(selection), test_function(test_function), generation_number(generation_number), population_size(population_size), dim_size(dim_size) {}
        ~GeneticAlgorithm()
        {
            delete test_function;
            delete crossover;
            delete mutation;
            delete selection;
        }
        void get_solution ( std::vector<T> &population, T& result );
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
        void evaluate_population ( std::vector<T> &population );
        void add_members( std::vector<T> &population,std::vector<T> &members );
        //int compare_members( const void *m1, const void *m2 );
        CrossoverOperator<T> *crossover;
        MutationOperator<T> *mutation = nullptr;
        SelectionOperator<T> *selection = nullptr;
        Function<T> *test_function = nullptr;
        unsigned int generation_number;
        size_t population_size;
        unsigned int dim_size;
};



#endif //GENETIC_ALGORITHM_GENETICALGORITHM_H
