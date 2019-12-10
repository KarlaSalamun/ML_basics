//
// Created by karla on 05. 12. 2019..
//

#ifndef SANTAFE_TURNRIGHTNODE_H
#define SANTAFE_TURNRIGHTNODE_H


#include "AbstractNode.h"

class TurnRightNode : public AbstractNode {
    public:
        AbstractNode * copy() override;

        int action( Ant &ant ) override;

        int children_num = 0;
};


#endif //SANTAFE_TURNRIGHTNODE_H
