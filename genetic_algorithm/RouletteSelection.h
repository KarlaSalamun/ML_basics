//
// Created by karla on 14. 11. 2019..
//

#ifndef GENETIC_ALGORITHM_ROULETTESELECTION_H
#define GENETIC_ALGORITHM_ROULETTESELECTION_H

#include "SelectionOperator.h"

class RouletteSelection : public SelectionOperator {
    public:
        std::vector<Solution> get_members( std::vector<Solution> population );
};


#endif //GENETIC_ALGORITHM_ROULETTESELECTION_H
