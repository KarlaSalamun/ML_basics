//
// Created by karla on 24. 10. 2019..
//

#include "LinearScheme.h"

double LinearScheme::get_new_temperature(int step)
{
    return init_temp - step * temp_coeff;
}