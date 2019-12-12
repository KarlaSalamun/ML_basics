//
// Created by karla on 11. 12. 2019..
//

#ifndef SANTAFE_POPULATION_H
#define SANTAFE_POPULATION_H

#include "AbstractNode.h"
#include "TreeConstructor.h"
#include "../Solution.h"

template <typename  T>
class Population {
    public:
        virtual std::vector<Solution<T>> create( int size ) = 0;
};


#endif //SANTAFE_POPULATION_H
