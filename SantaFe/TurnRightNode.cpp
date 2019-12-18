//
// Created by karla on 05. 12. 2019..
//

#include "TurnRightNode.h"

int TurnRightNode::action(Ant &ant)
{
    ant.turn_right();
    return 0;
}
