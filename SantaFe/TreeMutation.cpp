//
// Created by karla on 12. 12. 2019..
//

#include <cstdlib>
#include <queue>
#include "TreeMutation.h"
#include "TreeConstructor.h"
#include <iostream>

#define MAX_SUBTREE_DEPTH 3

// replaces random node with randomly generated subtree

template <typename T>
void TreeMutation<T>::mutate_solution ( T &solution )
{
    AbstractNode *new_node;
    /*
    TreeConstructor *tc = new TreeConstructor;
//    int random_depth = rand() % solution[0].data->depth;
    int random_depth = 3;
    int ref_depth = 1;
    int random_child = 0;

    AbstractNode *current = solution.data;
    while( ref_depth < random_depth ) {
        current = current->children[0];
        ref_depth++;
    }
    random_child = rand() % current->children_number;
    current->children[random_child] = tc->construct_tree_full( rand() % MAX_SUBTREE_DEPTH );
    solution = current;
     */
    TreeConstructor *tc = new TreeConstructor();
    //AbstractNode *data = solution.data;
/*
    if( rand() % 2 ) {
        tc->construct_tree_grow(rand() % MAX_SUBTREE_DEPTH + 1, new_node );
        solution.data->replace_random( new_node );
    }
    else {
        tc->construct_tree_full(rand() % MAX_SUBTREE_DEPTH + 1, new_node );
        solution.data->replace_random( new_node );
    }
*/
    if (solution.data == nullptr) {
        std::cout << "NULL8" << endl;
    }
    tc->construct_tree_grow(rand() % MAX_SUBTREE_DEPTH + 1, new_node );
    solution.data->replace_random( new_node );
/*
    AbstractNode *new_node = tc->construct_tree_grow( rand() % MAX_SUBTREE_DEPTH );
    solution.data->replace_random( new_node );
*/
    tc->rehash_tree( solution.data );
    delete tc;
//    solution.data->pick_random( solution.data, 5 ) = tc->construct_tree_full( 3 );
}
