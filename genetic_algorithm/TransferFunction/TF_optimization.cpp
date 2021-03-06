//
// Created by karla on 30. 10. 2019..
//
#include <cmath>
#include "TF_optimization.h"

template <typename T>
double TFOptimization<T>::get_value(T &args)
{
    double residual_sum = 0;
    double residual;
    for(int i=0; i<y.size(); i++) {
        residual = x[i][0]*args.data[0] + args.data[1]*pow( x[i][0], 3 )*x[i][1] + args.data[2]*exp( args.data[3]*x[i][2] )
                * ( 1 + cos( args.data[4] * x[i][3] ) ) + args.data[5] * x[i][3] * pow(x[i][4], 2);
        residual = pow( (y[i] - residual), 2);
        residual_sum+=residual;
    }
    return sqrt(residual_sum);
}

