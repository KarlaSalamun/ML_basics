//
// Created by karla on 06. 11. 2019..
//

#ifndef GENETIC_ALGORITHM_CROSSOVEROPERATOR_H
#define GENETIC_ALGORITHM_CROSSOVEROPERATOR_H
#include <vector>
#include "../Solution.h"

class CrossoverOperator {
    public:
        virtual std::vector<Solution> get_children(std::vector<Solution> parents ) = 0;
};

#endif //GENETIC_ALGORITHM_CROSSOVEROPERATOR_H
