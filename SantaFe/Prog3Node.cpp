//
// Created by karla on 05. 12. 2019..
//

#include <vector>
#include "Prog3Node.h"
#include "AbstractNode.h"

int Prog3Node::action( Ant &ant )
{
    return get_child(0)->action( ant ) + get_child(1)->action( ant ) + get_child(2)->action( ant );
}

int Prog3Node::action(Ant &ant, std::vector<std::pair<int, int>> &coordinates, std::vector<bool *> &food)
{
    return get_child(0)->action( ant, coordinates, food ) + get_child(1)->action( ant, coordinates, food ) + get_child(2)->action( ant, coordinates, food );
}
