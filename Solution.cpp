//
// Created by karla on 13. 11. 2019..
//
#include <stdio.h>
#include "Solution.h"

Solution::Solution( int dimension )
{
    vector.assign( dimension, 0 );
}

double Solution::get_fitness(std::vector<double> solution, Function *test_function)
{
    return test_function->get_value( solution );
}

void Solution::print_value()
{
    for (int i=0; i<this->vector.size(); i++ ) {
        printf("Solution [%d]: %lf \n", i+1, this->vector[i]);
    }
    printf("Residual: %lf\n", this->fitness );
}