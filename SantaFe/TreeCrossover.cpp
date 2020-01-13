//
// Created by karla on 12. 12. 2019..
//
#include <cstdlib>
#include <algorithm>
#include "TreeCrossover.h"
#include "TreePopulation.h"

template <typename T>
void TreeCrossover<T>::get_children( std::vector<T> parents, std::vector<T> &children )
{
    children.clear();

    TreeConstructor *tc = new TreeConstructor();

    int rand_depth = rand() % parents[0].data->depth;
    AbstractNode *random_tree1 = parents[0].data->pick_random( parents[0].data, rand_depth );

    rand_depth = rand() % parents[1].data->depth;
    AbstractNode *random_tree2 = parents[1].data->pick_random( parents[1].data, rand_depth );

    if( random_tree1->children_number==0 || random_tree2->children_number==0 ) {
        children.push_back( move( parents[0] ) );
        children.push_back( move( parents[1] ) );
        return;
    }

    if( parents[0].data->depth - random_tree1->depth + random_tree2->depth > 3 ) {
        children.push_back( move( parents[0] ) );
        children.push_back( move( parents[1] ) );
        delete tc;
       // printf("preskoceno krizanje\n");
        return;
    }

    int random_index1 = rand() % random_tree1->children_number;
    int random_index2 = rand() % random_tree2->children_number;
    std::swap( random_tree2->children[random_index2], random_tree1->children[random_index1] );

    tc->rehash_tree( parents[0].data );
    tc->rehash_tree( parents[1].data );

    children.push_back( move( parents[0] ) );
    children.push_back( move( parents[1] ) );

    delete tc;
}

