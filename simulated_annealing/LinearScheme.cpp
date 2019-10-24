//
// Created by karla on 24. 10. 2019..
//

#include "LinearScheme.h"

void LinearScheme::update_temperature(int step, double &temp)
{
    temp = INIT_TEMP - step * TEMP_COEFF;
}