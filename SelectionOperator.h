//
// Created by karla on 13. 11. 2019..
//

#ifndef GENETIC_ALGORITHM_SELECTIONOPERATOR_H
#define GENETIC_ALGORITHM_SELECTIONOPERATOR_H

#include "Solution.h"

template <typename T>
class SelectionOperator {
    public:
        virtual std::vector<Solution<T>> get_members( std::vector<Solution<T>> population ) = 0;
};


#endif //GENETIC_ALGORITHM_SELECTIONOPERATOR_H
