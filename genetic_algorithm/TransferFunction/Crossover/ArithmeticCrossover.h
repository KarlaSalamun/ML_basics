//
// Created by karla on 06. 11. 2019..
//

#ifndef GENETIC_ALGORITHM_ARITHMETICCROSSOVER_H
#define GENETIC_ALGORITHM_ARITHMETICCROSSOVER_H


#include "../../CrossoverOperator.h"

template <typename T>
class ArithmeticCrossover : public CrossoverOperator<T> {
    public:
        ArithmeticCrossover(double lambda) : lambda(lambda) {}
        void get_children(std::vector<T> &parents, std::vector<T> &children );
    private:
        double lambda;
};


#endif //GENETIC_ALGORITHM_ARITHMETICCROSSOVER_H
