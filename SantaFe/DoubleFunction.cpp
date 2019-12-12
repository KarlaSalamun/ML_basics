//
// Created by karla on 12. 12. 2019..
//

#include "DoubleFunction.h"

double DoubleFunction::compute_derivative( std::vector<double> point, std::vector<double> epsilon, double epsilon_scalar )
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

std::vector<double> DoubleFunction::get_gradient_approximation(std::vector<double> args, double delta)
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
