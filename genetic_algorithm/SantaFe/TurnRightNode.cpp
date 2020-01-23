//
// Created by karla on 05. 12. 2019..
//

#include <cstring>
#include "TurnRightNode.h"

int TurnRightNode::action(Ant &ant)
{
    ant.turn_right();
    return 0;
}

int TurnRightNode::action(Ant &ant, std::vector<std::pair<int, int>> &coordinates, std::vector<std::array<bool, 32*32>> &food)
{
    std::array<bool, 32*32> tmp;
    ant.turn_right();
    memcpy( &tmp, ant.food, 32*32*sizeof(bool) );
    coordinates.push_back( std::make_pair( ant.ant_position.x, ant.ant_position.y ) );
    food.push_back( tmp );
    return 0;
}
