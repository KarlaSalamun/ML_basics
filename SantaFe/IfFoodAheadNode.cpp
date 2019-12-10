//
// Created by karla on 04. 12. 2019..
//

#include "IfFoodAheadNode.h"

AbstractNode *IfFoodAheadNode::copy()
{
    return new IfFoodAheadNode( duplicate_children(), depth, subtree_num );
}

int IfFoodAheadNode::action(Ant &ant)
{
    if( ant.is_food_ahead() ) {
        return get_child(0)->action( ant );
    }
    else {
        return get_child(1)->action( ant );
    }
}