//
// Created by karla on 24. 10. 2019..
//
#include <cmath>
#include "GeometricScheme.h"

void GeometricScheme::update_temperature( int step, double &temp )
{
    temp = pow( TEMP_COEFF, step ) * INIT_TEMP;
}
