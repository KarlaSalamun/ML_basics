//
// Created by karla on 05. 12. 2019..
//

#ifndef SANTAFE_PROG3NODE_H
#define SANTAFE_PROG3NODE_H

#include <array>
#include <vector>
#include "AbstractNode.h"

class Prog3Node : public AbstractNode {
    public:
        Prog3Node() : AbstractNode()
        {
            is_terminal = false;
            children_number = 3;
            children.assign( children_number, nullptr );
            name = "Prog3";
        }

        AbstractNode *copy_node() override {
            return new Prog3Node(*this);
        }

    int action( Ant &ant ) override;
    int action(Ant &ant, std::vector<std::pair<int, int>> &coordinates, std::vector<std::array<bool, 32*32>> &food) override;
    //int action(Ant &ant, std::vector<std::pair<int, int>> &coordinates, std::vector<bool[32*32]> &food) override;

};

#endif //SANTAFE_PROG3NODE_H
