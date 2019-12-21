//
// Created by karla on 05. 12. 2019..
//

#ifndef SANTAFE_TURNRIGHTNODE_H
#define SANTAFE_TURNRIGHTNODE_H


#include <array>
#include "AbstractNode.h"

class TurnRightNode : public AbstractNode {
    public:
        TurnRightNode()
        {
            children_number = 0;
            is_terminal = true;
            name = "Right";
        }


        AbstractNode *copy_node() override {
            return new TurnRightNode(*this);
        }

    int action( Ant &ant ) override;
    int action(Ant &ant, std::vector<std::pair<int, int>> &coordinates, std::vector<std::array<bool, 32*32>> &food) override;
    //int action(Ant &ant, std::vector<std::pair<int, int>> &coordinates, std::vector<bool[32*32]> &food) override;
};


#endif //SANTAFE_TURNRIGHTNODE_H
