//
// Created by karla on 05. 12. 2019..
//

#ifndef SANTAFE_PROG3NODE_H
#define SANTAFE_PROG3NODE_H

#include "AbstractNode.h"

class Prog3Node : public AbstractNode {
    public:
        Prog3Node() : AbstractNode() {}
        Prog3Node( std::vector<AbstractNode *> children, int depth, int subtree_num ) :
            AbstractNode( children, depth, subtree_num ) {}

        AbstractNode *copy() override;

        int action( Ant &ant ) override;

        int children_number = 3;
};

#endif //SANTAFE_PROG3NODE_H
