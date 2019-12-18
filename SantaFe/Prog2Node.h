//
// Created by karla on 05. 12. 2019..
//

#ifndef SANTAFE_PROG2NODE_H
#define SANTAFE_PROG2NODE_H

#include <vector>
#include "AbstractNode.h"

class Prog2Node : public AbstractNode {
    public:
        Prog2Node() : AbstractNode()
        {
            is_terminal = false;
            children_number = 2;
            children.assign( children_number, nullptr );
            name = "Prog2";
        }
        Prog2Node( std::vector<AbstractNode *> children, int depth, int subtree_num ) :
            AbstractNode( children, depth, subtree_num ) {}

        AbstractNode *copy_node() override {
            return new Prog2Node(*this);
        }

        int action( Ant &ant ) override;

};


#endif //SANTAFE_PROG2NODE_H
