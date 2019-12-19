//
// Created by karla on 12. 12. 2019..
//

#include <cstdlib>
#include <queue>
#include "TreeMutation.h"
#include "TreeConstructor.h"

#define MAX_SUBTREE_DEPTH 5

// replaces random node with randomly generated subtree

template <typename T>
void TreeMutation<T>::mutate_solution ( T &solution )
{
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
    AbstractNode *new_node = tc->construct_tree_grow( rand() % MAX_SUBTREE_DEPTH );
    solution.data->replace_random( new_node );
    tc->rehash_tree( solution.data );
//    solution.data->pick_random( solution.data, 5 ) = tc->construct_tree_full( 3 );
}
