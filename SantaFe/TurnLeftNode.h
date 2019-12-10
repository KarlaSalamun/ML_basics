//
// Created by karla on 05. 12. 2019..
//

#ifndef SANTAFE_TURNLEFTNODE_H
#define SANTAFE_TURNLEFTNODE_H


#include "AbstractNode.h"

class TurnLeftNode : public AbstractNode {
    public:
        AbstractNode * copy() override;

        int action( Ant &ant ) override;

        int children_num = 0;
};


#endif //SANTAFE_TURNLEFTNODE_H
