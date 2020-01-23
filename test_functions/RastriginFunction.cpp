//
// Created by karla on 23. 10. 2019..
//

#include <cmath>
#include "RastriginFunction.h"

double RastriginFunction::get_value( std::vector<double> &args )
{
    double sum = 0;
    for (auto i=0; i<args.size(); i++) {
        sum += pow( args[i], 2 ) - 10*cos( 2* M_PI * args[i] );
    }
    return 10*args.size() + sum;
}