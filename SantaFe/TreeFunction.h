//
// Created by karla on 12. 12. 2019..
//

#ifndef SANTAFE_TREEFUNCTION_H
#define SANTAFE_TREEFUNCTION_H

#include "../function.h"
#include "../Solution.h"
#include "AbstractNode.h"

class TreeFunction : public Function<Solution<AbstractNode *>> {
public:
    virtual ~TreeFunction() {}
    void get_value( Solution<AbstractNode *> &solution );
};


#endif //SANTAFE_TREEFUNCTION_H
