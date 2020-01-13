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

        void copy_node( AbstractNode *&original ) override
        {
            original = new MoveNode(*this);
        }

        int action( Ant &ant ) override;
        int action(Ant &ant, std::vector<std::pair<int, int>> &coordinates,
                std::vector<std::array<bool, 32*32>> &food) override;

};


#endif //SANTAFE_MOVENODE_H
