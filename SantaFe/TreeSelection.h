//
// Created by karla on 12. 12. 2019..
//

#ifndef SANTAFE_TREESELECTION_H
#define SANTAFE_TREESELECTION_H

#include "../SelectionOperator.h"
#include "AbstractNode.h"

template <typename  T>
class TreeSelection : public SelectionOperator<T> {
    public:
    virtual ~TreeSelection() {}
        std::vector<T> get_members( std::vector<T> population );
};


#endif //SANTAFE_TREESELECTION_H
