//
// Created by karla on 23. 10. 2019..
//

#include "HimmelblauFunction.h"
#include <cmath>


double HimmelblauFunction::get_value( std::vector<double> &args ) {

    return pow( ( pow( args[0], 2 ) + args[1] -11 ), 2 ) +
        pow( ( pow( args[1], 2 ) + args[0] -7 ), 2 );

}
