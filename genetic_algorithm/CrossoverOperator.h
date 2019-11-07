//
// Created by karla on 06. 11. 2019..
//

#ifndef GENETIC_ALGORITHM_CROSSOVEROPERATOR_H
#define GENETIC_ALGORITHM_CROSSOVEROPERATOR_H
#include <vector>

class CrossoverOperator {
    public:
        virtual std::vector<std::vector<double>> get_children ( std::vector<std::vector<double>> parents ) = 0;
};

#endif //GENETIC_ALGORITHM_CROSSOVEROPERATOR_H
