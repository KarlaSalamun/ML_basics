//
// Created by karla on 24. 10. 2019..
//
#include <cmath>
#include "GeometricScheme.h"

double GeometricScheme::get_new_temperature( int step )
{
    return pow( temp_coeff, step ) * init_temp;
}
