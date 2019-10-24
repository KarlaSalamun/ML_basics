//
// Created by karla on 24. 10. 2019..
//
#include <cmath>
#include "RosenbrockFunction.h"

double RosenbrockFunction::get_value( std::vector<double> args )
{
    double sum = 0;
    for (auto i=0; i<args.size()-1; i++) {
        sum += ( 100 * pow( ( args[i+1] - pow( args[i], 2 )), 2 ) + pow( (1-args[i]), 2 ));
    }
    return sum;
}
