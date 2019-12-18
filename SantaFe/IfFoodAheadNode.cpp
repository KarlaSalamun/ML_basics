//
// Created by karla on 04. 12. 2019..
//

#include "IfFoodAheadNode.h"

int IfFoodAheadNode::action(Ant &ant)
{
    if( ant.is_food_ahead() ) {
        return get_child(0)->action( ant );
    }
    else {
        return get_child(1)->action( ant );
    }
}

int IfFoodAheadNode::action(Ant &ant, std::vector<std::pair<int, int>> &coordinates, std::vector<bool *> &food)
{
    if( ant.is_food_ahead() ) {
        return get_child(0)->action( ant, coordinates, food );
    }
    else {
        return get_child(1)->action( ant, coordinates, food );
    }
}
