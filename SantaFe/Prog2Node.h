//
// Created by karla on 05. 12. 2019..
//

#ifndef SANTAFE_PROG2NODE_H
#define SANTAFE_PROG2NODE_H

#include <vector>
#include "AbstractNode.h"

class Prog2Node : public AbstractNode {
    public:
        Prog2Node() : AbstractNode()
        {
            is_terminal = false;
            children_number = 2;
            children.assign( children_number, nullptr );
            name = "Prog2";
        }

        AbstractNode *copy_node() override {
            return new Prog2Node(*this);
        }

        int action( Ant &ant ) override;
    int action(Ant &ant, std::vector<std::pair<int, int>> &coordinates, std::vector<std::array<bool, 32*32>> &food) override;
    //    int action(Ant &ant, std::vector<std::pair<int, int>> &coordinates, std::vector<bool[32*32]> &food) override;

};


#endif //SANTAFE_PROG2NODE_H
