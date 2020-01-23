//
// Created by karla on 06. 11. 2019..
//

#ifndef GENETIC_ALGORITHM_BLX_ALPHA_H
#define GENETIC_ALGORITHM_BLX_ALPHA_H


#include "../../CrossoverOperator.h"

template <typename T>
class BLX_alpha : public CrossoverOperator<T> {
    public:
        BLX_alpha(double alpha) : alpha(alpha) {}
        void get_children( std::vector<T> &parents, std::vector<T> &children );
private:
        double alpha;
};


#endif //GENETIC_ALGORITHM_BLX_ALPHA_H
