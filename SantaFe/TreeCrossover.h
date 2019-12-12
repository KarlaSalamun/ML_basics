//
// Created by karla on 12. 12. 2019..
//

#ifndef SANTAFE_TREECROSSOVER_H
#define SANTAFE_TREECROSSOVER_H

#include "../CrossoverOperator.h"
#include "AbstractNode.h"

class TreeCrossover : public CrossoverOperator<AbstractNode* > {
    public:
        std::vector<Solution<AbstractNode *>> get_children(std::vector<Solution<AbstractNode *>> parents );
};


#endif //SANTAFE_TREECROSSOVER_H
