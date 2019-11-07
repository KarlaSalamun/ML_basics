//
// Created by karla on 06. 11. 2019..
//

#ifndef GENETIC_ALGORITHM_ARITHMETICCROSSOVER_H
#define GENETIC_ALGORITHM_ARITHMETICCROSSOVER_H


#include "CrossoverOperator.h"

class ArithmeticCrossover : public CrossoverOperator {
    public:
        ArithmeticCrossover(double lambda) : lambda(lambda) {}
        std::vector<std::vector<double>> get_children ( std::vector<std::vector<double>> parents );

    private:
        double lambda;
};


#endif //GENETIC_ALGORITHM_ARITHMETICCROSSOVER_H
