//
// Created by karla on 04. 12. 2019..
//

#ifndef SANTAFE_IFFOODAHEADNODE_H
#define SANTAFE_IFFOODAHEADNODE_H

#include "AbstractNode.h"

class IfFoodAheadNode : public AbstractNode {
    public:
        IfFoodAheadNode() : AbstractNode()
        {
            is_terminal = false;
            children_number = 2;
            children.assign( children_number, nullptr );
            name = "If";
        }
        IfFoodAheadNode( std::vector<AbstractNode *> children, int depth, int subtree_num ) :
            AbstractNode( children, depth, subtree_num ) {}

        AbstractNode * copy() override;
        int action( Ant &ant ) override;
};


#endif //SANTAFE_IFFOODAHEADNODE_H
