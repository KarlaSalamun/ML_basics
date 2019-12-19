//
// Created by karla on 05. 12. 2019..
//
#include <tuple>
#include "Prog2Node.h"

int Prog2Node::action( Ant &ant )
{
    return get_child(0)->action( ant ) + get_child(1)->action( ant );
}

int Prog2Node::action(Ant &ant, std::vector<std::pair<int, int>> &coordinates, std::vector<std::array<bool, 32*32>> &food)
{
    return get_child(0)->action( ant, coordinates, food ) + get_child(1)->action( ant, coordinates, food );
}
