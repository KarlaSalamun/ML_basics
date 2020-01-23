//
// Created by karla on 24. 10. 2019..
//

#include <cmath>
#include "EggholderFunction.h"


double EggholderFunction::get_value(std::vector<double> args)
{
    return -(args[1]+47)*sin( sqrt( fabs( args[0]/2 + args[1] + 47 ) ) ) -
        args[0] * sin( sqrt( fabs( args[0] - args[1] - 47 ) ) );
}