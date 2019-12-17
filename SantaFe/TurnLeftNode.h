//
// Created by karla on 05. 12. 2019..
//

#ifndef SANTAFE_TURNLEFTNODE_H
#define SANTAFE_TURNLEFTNODE_H


#include "AbstractNode.h"

class TurnLeftNode : public AbstractNode {
    public:
        TurnLeftNode()
        {
            children_number = 0;
            is_terminal = true;
            name = "Left";
        }


        AbstractNode * copy() override;

        int action( Ant &ant ) override;
};


#endif //SANTAFE_TURNLEFTNODE_H
