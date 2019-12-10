//
// Created by karla on 05. 12. 2019..
//

#include "TurnLeftNode.h"

AbstractNode *TurnLeftNode::copy()
{
    return new TurnLeftNode();
}

int TurnLeftNode::action(Ant &ant)
{
    ant.turn_left();
    return 0;
}
