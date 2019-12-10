//
// Created by karla on 05. 12. 2019..
//
#include <tuple>
#include "Prog2Node.h"

AbstractNode *Prog2Node::copy()
{
    return new Prog2Node( duplicate_children(), depth, subtree_num );
}

int Prog2Node::action( Ant &ant )
{
    return get_child(0)->action( ant ) + get_child(1)->action( ant );
}

