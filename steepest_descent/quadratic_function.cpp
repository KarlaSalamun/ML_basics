//
// Created by karla on 17. 10. 2019..
//

#include "quadratic_function.h"
#include <cmath>

double QuadraticFunction::get_value( std::vector<double> args )
{
    return pow( (args[0]-4), 2) + pow((args[1]+8), 2) + pow((args[2]+5), 2);
}

std::vector<double> QuadraticFunction::get_gradient(std::vector<double> args)
{
    std::vector<double> gradient(3);
    gradient[0] = 2*args[0] - 8;
    gradient[1] = 2*args[1] + 16;
    gradient[2] = 2*args[2] + 10;
    return gradient;
}

