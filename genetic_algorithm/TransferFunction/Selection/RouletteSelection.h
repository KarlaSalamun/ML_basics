//
// Created by karla on 14. 11. 2019..
//

#ifndef GENETIC_ALGORITHM_ROULETTESELECTION_H
#define GENETIC_ALGORITHM_ROULETTESELECTION_H

#include "../../SelectionOperator.h"

template <typename T>
class RouletteSelection : public SelectionOperator<T> {
    public:
        void get_members( std::vector<T> &population, std::vector<T> &members );
};


#endif //GENETIC_ALGORITHM_ROULETTESELECTION_H
