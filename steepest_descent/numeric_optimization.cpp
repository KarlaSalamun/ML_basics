//
// Created by karla on 18. 10. 2019..
//

#include <cmath>
#include <cstdio>
#include "numeric_optimization.h"
#include "quadratic_function.h"

double euclid_norm ( std::vector<double> x )
{
    double norm=0;
    for (auto i=0; i<x.size(); i++) {
        norm += pow( x[i], 2 );
    }
    return sqrt(norm);
}

void negative_vector(std::vector<double> &x)
{
    for(auto i=0; i<x.size(); i++) {
        x[i] = -x[i];
    }
}

std::vector<double> NumericOptimization::get_solution(std::vector<double> solution, NumericFunction *test_function) {

    std::vector<double> direction;

    solution.assign(3, 0);
    direction.assign(3, 0);

    solution[0] = 6;
    solution[1] = -10;
    solution[2] = -9;

    double delta = 0.1;

    double lambda_lower, lambda_upper, lambda;
    lambda_lower = 0;
    lambda_upper = 2; /* TODO: implementiraj uvrstavanje za gornju granicu lambda */

    int i=0;
    int iterations=0;
    while(true) {
        if (  euclid_norm( test_function->get_gradient_approximation(solution, delta))  < 0.00001 )
            break;
        direction = test_function->get_gradient_approximation( solution, delta );
        negative_vector(direction);

        while(true) {
            lambda = (lambda_lower + lambda_upper) / 2;
            std::vector<double> sol_theta(3);
            for (int i=0; i<solution.size(); i++) {
                sol_theta[i] = solution[i] + lambda*direction[i];
            }

            std::vector<double> der_theta = test_function->get_gradient_approximation (sol_theta, delta);

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
        for (i=0; i<solution.size(); i++) {
            solution[i] = solution[i] + lambda * direction[i];
        }
        iterations++;
    }
    printf("iterations: %d\n", iterations);
    return solution;
}

