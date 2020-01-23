//
// Created by karla on 12. 12. 2019..
//

#ifndef SANTAFE_TREEFUNCTION_H
#define SANTAFE_TREEFUNCTION_H

#include "../../function.h"
#include "TreeSolution.h"
#include "AbstractNode.h"

class TreeFunction : public Function<TreeSolution<AbstractNode *>> {
public:
    virtual ~TreeFunction() {}
    double get_value( TreeSolution<AbstractNode *> &solution ) override;
};


#endif //SANTAFE_TREEFUNCTION_H
