//
// Created by karla on 30. 10. 2019..
//
#include <cmath>
#include "TF_optimization.h"


double TFOptimization::get_value(std::vector<double> args)
{
    double residual_sum = 0;
    double residual;
    for(int i=0; i<y.size(); i++) {
        residual = x[i][0]*args[0] + args[1]*pow( x[i][0], 3 )*x[i][1] + args[2]*exp( args[3]*x[i][2] )
                * ( 1 + cos( args[4] * x[i][3] ) ) + args[5] * x[i][3] * pow(x[i][4], 2);
        residual = pow( (y[i] - residual), 2);
        residual_sum+=residual;
    }
    return sqrt(residual_sum);
}

