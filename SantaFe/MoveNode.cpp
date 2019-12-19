//
// Created by karla on 04. 12. 2019..
//

#include <cstring>
#include <array>
#include "MoveNode.h"

int MoveNode::action(Ant &ant)
{
    ant.move();
    return 0;
}

int MoveNode::action(Ant &ant, std::vector<std::pair<int, int>> &coordinates, std::vector<std::array<bool, 32*32>> &food)
{
    ant.move();
    //bool tmp[32*32];
    std::array<bool, 32*32> tmp;
    memcpy( &tmp, ant.food, 32*32*sizeof(bool) );
    coordinates.push_back( std::make_pair( ant.ant_position.x, ant.ant_position.y ) );
    food.push_back( tmp );
    return 0;
}
