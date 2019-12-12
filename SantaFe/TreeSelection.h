//
// Created by karla on 12. 12. 2019..
//

#ifndef SANTAFE_TREESELECTION_H
#define SANTAFE_TREESELECTION_H

#include "../SelectionOperator.h"
#include "AbstractNode.h"

class TreeSelection : public SelectionOperator<AbstractNode *> {
    public:
        std::vector<Solution<AbstractNode *>> get_members( std::vector<Solution<AbstractNode *>> population );
};


#endif //SANTAFE_TREESELECTION_H
