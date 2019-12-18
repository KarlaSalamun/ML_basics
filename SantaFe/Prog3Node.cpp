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
