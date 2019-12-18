//
// Created by karla on 04. 12. 2019..
//

#ifndef SANTAFE_MOVENODE_H
#define SANTAFE_MOVENODE_H


#include "AbstractNode.h"

class MoveNode : public AbstractNode {
    public:
        MoveNode()
        {
            is_terminal = true;
            children_number = 0;
            name = "M";
        }

        AbstractNode *copy_node() override {
            return new MoveNode(*this);
        }

        int action( Ant &ant ) override;
        int action(Ant &ant, std::vector<std::pair<int, int>> &coordinates, std::vector<bool *> &food) override;

};


#endif //SANTAFE_MOVENODE_H
