#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include "main.h"
#include "quadratic_function.h"

double euclid_norm ( std::vector<double> x )
{
    double norm=0;
    for (int i=0; i<x.size(); i++) {
        norm += pow( x[i], 2 );
    }
    return sqrt(norm);
}

void negative_vector(std::vector<double> &x)
{
    for(int i=0; i<x.size(); i++) {
        x[i] = -x[i];
    }
}

int main()
{
    std::vector<double> solution;
    std::vector<double> direction;

    solution.assign(3, 0);
    direction.assign(3, 0);

    QuadraticFunction my_function = QuadraticFunction();

    solution[0] = 6;
    solution[1] = -10;
    solution[2] = -9;

    double delta = 0.1;

    double lambda_lower, lambda_upper, lambda;
    lambda_lower = 0;
    lambda_upper = 2; /* TODO: implementiraj uvrstavanje za gornju granicu */

    while(true) {
        if (  euclid_norm( my_function.get_gradient_approximation(solution, delta))  < 0.01 )
            break;
        direction = my_function.get_gradient_approximation( solution, delta );
        negative_vector(direction);
        while(true) {
            lambda = (lambda_lower + lambda_upper) / 2;
            std::vector<double> sol_theta(3);
            for (int i=0; i<solution.size(); i++) {
                sol_theta[i] = solution[i] + lambda*direction[i];
            }

            std::vector<double> der_theta = my_function.get_gradient_approximation (sol_theta, delta);

            double tmp=0;

            for(int i=0; i<direction.size(); i++) {
                tmp += der_theta[i] * direction[i];
            }
            if ( fabs(tmp) < 0.01 ) {
                break;
            }
            else if ( tmp > 0 ) {
                lambda_upper = lambda;
            }
            else {
                lambda_lower = lambda;
            }
        }

        for(int i=0; i<solution.size(); i++) {
            solution[i] = solution[i] + lambda*direction[i];
       }

    }
    printf("%f %f %f\n", solution[0], solution[1], solution[2]);
    return 0;
}