//
// Created by karla on 04. 12. 2019..
//

#include "MoveNode.h"

int MoveNode::action(Ant &ant)
{
    ant.move();
    return 0;
}

int MoveNode::action(Ant &ant, std::vector<std::pair<int, int>> &coordinates, std::vector<bool *> &food)
{
    ant.move();
    coordinates.push_back( std::make_pair( ant.ant_position.x, ant.ant_position.y ) );
    food.push_back( ant.food );
    return 0;
}
