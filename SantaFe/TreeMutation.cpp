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

    TreeConstructor *tc = new TreeConstructor();
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

    tc->construct_tree_grow( rand() % MAX_SUBTREE_DEPTH + 1, new_node );

    solution.data->replace_random( new_node );
    delete new_node;

    tc->rehash_tree( solution.data );

    delete tc;
}
