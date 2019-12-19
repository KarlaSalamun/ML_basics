//
// Created by karla on 12. 12. 2019..
//
#include <cstdlib>
#include <algorithm>
#include "TreeCrossover.h"
#include "TreePopulation.h"

template <typename T>
std::vector<T> TreeCrossover<T>::get_children(std::vector<T> &parents) {

    TreeConstructor *tc = new TreeConstructor();
    std::vector<T> result;

    int rand_depth = rand() % parents[0].data->depth;
    AbstractNode *random_tree1 = parents[0].data->pick_random( parents[0].data, 0 );

    rand_depth = rand() % parents[1].data->depth;
    AbstractNode *random_tree2 = parents[1].data->pick_random( parents[1].data, 0 );

    if( parents[0].data->depth - random_tree1->depth + random_tree2->depth > 5 ) {
       // printf("preskoceno krizanje\n");
        result.push_back( parents[0] );
        result.push_back( parents[1] );
        return  result;
    }

    int random_index1 = rand() % random_tree1->children_number;
    int random_index2 = rand() % random_tree2->children_number;
    std::swap( random_tree2->children[random_index2], random_tree1->children[random_index1] );

    tc->rehash_tree( parents[0].data );
    tc->rehash_tree( parents[1].data );

    result.push_back( parents[0] );
    result.push_back( parents[1] );

    delete tc;
    return result;
}

