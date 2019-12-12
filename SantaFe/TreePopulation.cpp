//
// Created by karla on 11. 12. 2019..
//

#include "TreePopulation.h"
#include "TreeConstructor.h"

std::vector<Solution<AbstractNode *>> TreePopulation::create( int size )
{
    std::vector<Solution<AbstractNode *>> population(size);
    TreeConstructor *tc = new TreeConstructor();
    for( int i=0; i<size; i++ ) {
        population[i].data = tc->construct_tree_full( max_depth );
    }
    return population;
}
