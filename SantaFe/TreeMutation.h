//
// Created by karla on 12. 12. 2019..
//

#ifndef SANTAFE_TREEMUTATION_H
#define SANTAFE_TREEMUTATION_H

#include "../MutationOperator.h"
#include "AbstractNode.h"
#include "../Solution.h"

template <typename T>
class TreeMutation : public MutationOperator<T> {
public:
    void mutate_solution ( T &solution );
};


#endif //SANTAFE_TREEMUTATION_H
