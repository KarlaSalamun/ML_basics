//
// Created by karla on 05. 12. 2019..
//

#ifndef SANTAFE_TURNLEFTNODE_H
#define SANTAFE_TURNLEFTNODE_H


#include <array>
#include "AbstractNode.h"

class TurnLeftNode : public AbstractNode {
    public:
        TurnLeftNode()
        {
            children_number = 0;
            is_terminal = true;
            name = "Left";
        }


        void copy_node( AbstractNode *&original ) override
        {
            original = new TurnLeftNode(*this);
        }

    int action( Ant &ant ) override;
    int action(Ant &ant, std::vector<std::pair<int, int>> &coordinates, std::vector<std::array<bool, 32*32>> &food) override;
    //int action(Ant &ant, std::vector<std::pair<int, int>> &coordinates, std::vector<bool[32*32]> &food) override;
};


#endif //SANTAFE_TURNLEFTNODE_H
