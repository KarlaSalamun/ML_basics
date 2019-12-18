//
// Created by karla on 05. 12. 2019..
//

#include "TurnLeftNode.h"

int TurnLeftNode::action(Ant &ant)
{
    ant.turn_left();
    return 0;
}

int TurnLeftNode::action(Ant &ant, std::vector<std::pair<int, int>> &coordinates, std::vector<bool *> &food)
{
    ant.turn_left();
    coordinates.push_back( std::make_pair( ant.ant_position.x, ant.ant_position.y ) );
    food.push_back( ant.food );
    return 0;
}
