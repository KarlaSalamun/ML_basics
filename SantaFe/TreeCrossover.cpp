//
// Created by karla on 12. 12. 2019..
//
#include <cstdlib>
#include "TreeCrossover.h"
#include "TreePopulation.h"
/*
std::vector<Solution<AbstractNode *>> TreeCrossover::get_children(std::vector<Solution<AbstractNode *>> parents){

    AbstractNode *tree1 = parents[0].data;
    AbstractNode *tree2 = parents[1].data;
    AbstractNode *random1, *random2;
    Solution<AbstractNode *> child1;
    Solution<AbstractNode *> child2;
    std::vector<Solution<AbstractNode *>> result;

    int rand_depth = rand() % MAX_DEPTH + 1;
    random1 = tree1->pick_random( tree1, rand_depth );
    random2 = tree2->pick_random( tree2, rand_depth );

    tree1->replace_random( *random2 );
    child1.data = tree1;
    tree2->replace_random( *random1 );
    child2.data = tree2;
    result.push_back(child1);
    result.push_back(child2);
    return result;

}
*/

template <typename T>
std::vector<T> TreeCrossover<T>::get_children(std::vector<T> parents) {
    return parents;
}

