//
// Created by karla on 04. 12. 2019..
//

#ifndef SANTAFE_MOVENODE_H
#define SANTAFE_MOVENODE_H


#include "AbstractNode.h"

class MoveNode : public AbstractNode {
    public:
        AbstractNode * copy() override;

        int action( Ant &ant ) override;

        int children_num = 0;
};


#endif //SANTAFE_MOVENODE_H
