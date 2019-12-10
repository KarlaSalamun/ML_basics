//
// Created by karla on 05. 12. 2019..
//

#ifndef SANTAFE_PROG2NODE_H
#define SANTAFE_PROG2NODE_H

#include <vector>
#include "AbstractNode.h"

class Prog2Node : public AbstractNode {
    public:
        Prog2Node() : AbstractNode() {}
        Prog2Node( std::vector<AbstractNode *> children, int depth, int subtree_num ) :
            AbstractNode( children, depth, subtree_num ) {}

        AbstractNode * copy() override;

        int action( Ant &ant ) override;

        int children_number = 2;
};


#endif //SANTAFE_PROG2NODE_H
