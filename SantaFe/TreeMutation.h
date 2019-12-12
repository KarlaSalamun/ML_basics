//
// Created by karla on 12. 12. 2019..
//

#ifndef SANTAFE_TREEMUTATION_H
#define SANTAFE_TREEMUTATION_H

#include "../MutationOperator.h"
#include "AbstractNode.h"

class TreeMutation : public MutationOperator<AbstractNode *> {
public:
    void mutate_solution ( std::vector<AbstractNode *> &solution );
};


#endif //SANTAFE_TREEMUTATION_H
