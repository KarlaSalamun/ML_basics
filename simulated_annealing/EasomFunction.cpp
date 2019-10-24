//
// Created by karla on 24. 10. 2019..
//

#include <cmath>
#include "EasomFunction.h"

double EasomFunction::get_value(std::vector<double> args)
{
    return -cos(args[0])*cos(args[1])*exp(-((pow(args[0]-M_PI, 2)+pow(args[1]-M_PI, 2))));
}