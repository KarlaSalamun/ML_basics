//
// Created by karla on 04. 12. 2019..
//

#include "MoveNode.h"

AbstractNode *MoveNode::copy()
{
    return new MoveNode();
}

int MoveNode::action(Ant &ant)
{
    ant.move();
    return 0;
}