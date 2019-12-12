//
// Created by karla on 13. 11. 2019..
//

#ifndef PROJEKT_SOLUTION_H
#define PROJEKT_SOLUTION_H

#include <vector>
#include <cstdio>
#include "function.h"


template <typename  T>
class Solution {
    public:
        T data;
        double fitness;

        double get_fitness(T solution, Function<T> *test_function )
        {
            return test_function->get_value( solution );
        }
/*
        void print_value() {
            for (int i=0; i<this->vector.size(); i++ ) {
                std::printf("Solution [%d]: %lf \n", i+1, this->vector[i]);
            }
            std::printf("Residual: %lf\n", this->fitness );
        }
        */
//        Solution( int dimension ) { data.assign( dimension, 0 ); }
        Solution( T data ) : data( data ) {}
        Solution() {}
};


#endif //PROJEKT_SOLUTION_H
