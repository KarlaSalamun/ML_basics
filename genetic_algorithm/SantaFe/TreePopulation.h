//
// Created by karla on 11. 12. 2019..
//

#ifndef SANTAFE_TREEPOPULATION_H
#define SANTAFE_TREEPOPULATION_H

#define MAX_DEPTH 2

#include "Population.h"
#include "../Solution.h"

class TreePopulation : public Population<AbstractNode*> {
    public:
        TreePopulation( int size, int max_depth ) : size( size ), max_depth( max_depth ) {}
        std::vector<Solution<AbstractNode *>> create( int size );
        int size, max_depth;
};


#endif //SANTAFE_TREEPOPULATION_H
