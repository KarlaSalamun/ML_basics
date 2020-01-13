//
// Created by karla on 04. 12. 2019..
//

#ifndef SANTAFE_IFFOODAHEADNODE_H
#define SANTAFE_IFFOODAHEADNODE_H

#include <array>
#include "AbstractNode.h"

class IfFoodAheadNode : public AbstractNode {
    public:
        IfFoodAheadNode() : AbstractNode()
        {
            is_terminal = false;
            children_number = 2;
            children.assign( children_number, nullptr );
            name = "If";
        }

        void copy_node( AbstractNode *&copy ) override
        {                // FIXME parametri preko reference??
            copy = new IfFoodAheadNode(*this);
        }

        int action( Ant &ant ) override;
        int action(Ant &ant, std::vector<std::pair<int, int>> &coordinates, std::vector<std::array<bool, 32*32>> &food) override;
    //    int action(Ant &ant, std::vector<std::pair<int, int>> &coordinates, std::vector<bool[32*32]> &food) override;
};


#endif //SANTAFE_IFFOODAHEADNODE_H
