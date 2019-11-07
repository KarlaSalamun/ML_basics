//
// Created by karla on 06. 11. 2019..
//

#ifndef GENETIC_ALGORITHM_BLX_ALPHA_H
#define GENETIC_ALGORITHM_BLX_ALPHA_H


#include "CrossoverOperator.h"

class BLX_alpha : public CrossoverOperator {
    public:
        BLX_alpha(double alpha) : alpha(alpha) {}
        std::vector<std::vector<double>> get_children ( std::vector<std::vector<double>> parents );
    private:
        double alpha;
};


#endif //GENETIC_ALGORITHM_BLX_ALPHA_H
