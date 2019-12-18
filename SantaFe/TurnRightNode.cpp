//
// Created by karla on 05. 12. 2019..
//

#include "TurnRightNode.h"

int TurnRightNode::action(Ant &ant)
{
    ant.turn_right();
    return 0;
}

int TurnRightNode::action(Ant &ant, std::vector<std::pair<int, int>> &coordinates, std::vector<bool *> &food)
{
    ant.turn_right();
    coordinates.push_back( std::make_pair( ant.ant_position.x, ant.ant_position.y ) );
    food.push_back( ant.food );
    return 0;
}
