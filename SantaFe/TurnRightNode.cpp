//
// Created by karla on 05. 12. 2019..
//

#include "TurnRightNode.h"

AbstractNode *TurnRightNode::copy()
{
    return new TurnRightNode();
}

int TurnRightNode::action(Ant &ant)
{
    ant.turn_right();
    return 0;
}
