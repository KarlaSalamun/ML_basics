//
// Created by karla on 17. 10. 2019..
//

#include "quadratic_function.h"
#include <cmath>

double QuadraticFunction::get_value( std::vector<double> &args )
{
    return pow( (args[0]-4), 2) + pow((args[1]+8), 2) + pow((args[2]+5), 2);
}

std::vector<double> QuadraticFunction::get_gradient(std::vector<double> args)
{
    std::vector<double> gradient(3);
    gradient[0] = 2*args[0] - 8;
    gradient[1] = 2*args[1] + 16;
    gradient[2] = 2*args[2] + 10;
    return gradient;
}

std::vector<double> QuadraticFunction::get_gradient_approximation(std::vector<double> args, double delta)
{
    std::vector<double> gradient;
    std::vector<double> epsilon_shift;

    epsilon_shift.assign(args.size(), 0);

    for (auto i = 0; i < args.size(); i++) {
        std::fill(epsilon_shift.begin(), epsilon_shift.end(), 0);
        epsilon_shift[i] = delta;
        gradient.push_back(compute_derivative( args, epsilon_shift, delta ));
    }

    return gradient;
}

double QuadraticFunction::compute_derivative( std::vector<double> point, std::vector<double> epsilon, double epsilon_scalar )
{
    double derivative;
    std::vector<double> solution_u(point.size()), solution_l(point.size());
    int i;

    for( i=0; i<point.size(); i++ ) {
        solution_l[i] = point[i] - epsilon[i];
    }

    for( i=0; i<point.size(); i++ ) {
        solution_u[i] = point[i] + epsilon[i];
    }

    derivative = (get_value( solution_u ) - get_value( solution_l )) / ( 2*epsilon_scalar );
    return derivative;
}