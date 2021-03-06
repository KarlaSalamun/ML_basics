//
// Created by karla on 24. 10. 2019..
//

#include <cmath>
#include <iostream>
#include "SimulatedAnnealing.h"
#include "CoolingScheme.h"
#include "GeometricScheme.h"

SimulatedAnnealing::~SimulatedAnnealing()
{
    delete scheme;
}

double SimulatedAnnealing::compute_probability( int step )
{
    return init_prob * pow( prob_decrease, step-1 );
}

std::vector<double> SimulatedAnnealing::get_solution( std::vector<double> solution, NumericFunction *test_function )
{

    std::vector<double> solution_new;
    solution_new.assign( solution.size(), 0 );

    int k = 1;
    int m = 0;
    int success = 0;
    int acc_sol = 0;
    double temp = scheme->init_temp;

    srand(0);
    //srand (static_cast<double> (time(NULL)));
    while ( temp > 1e-5 ) {
        for ( m=0; m<1000; m++ ) {
            for ( auto i=0; i<solution.size(); i++) {
                double random_coeff = 8.6 * (static_cast <double> (rand()) / ( static_cast <double> (RAND_MAX)));
                double random = -0.5 + static_cast <double> (rand()) / ( static_cast <double> (RAND_MAX));
                solution_new[i] = solution[i] + random*random_coeff;
            }
            double delta = test_function->get_value(solution_new) - test_function->get_value(solution);
            if ( delta <= 0 ) {
                solution = solution_new;
                success++;
                acc_sol++;
            }
            else {
                if ((static_cast <float> (rand()) / (static_cast <float> (RAND_MAX))) < compute_probability( k )) {
                    solution = solution_new;
                    acc_sol++;
                }
            }

            if (success == 100) {
                break;
            }
        }
        acc_sol = 0;
        temp = scheme->get_new_temperature( k );
        k++;
        success=0;
        double residual = test_function->get_value(solution);
        printf("Current residual: %lf\n", residual);
    }
    printf("k=%d\n", k);
    return solution;
}
