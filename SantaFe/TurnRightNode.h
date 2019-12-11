//
// Created by karla on 05. 12. 2019..
//

#ifndef SANTAFE_TURNRIGHTNODE_H
#define SANTAFE_TURNRIGHTNODE_H


#include "AbstractNode.h"

class TurnRightNode : public AbstractNode {
    public:
        TurnRightNode()
        {
            children_number = 0;
            is_terminal = true;
            name = "TurnRight";
        }
        AbstractNode * copy() override;

        int action( Ant &ant ) override;
};


#endif //SANTAFE_TURNRIGHTNODE_H
