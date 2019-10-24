//
// Created by karla on 24. 10. 2019..
//

#include "SimulatedAnnealing.h"
#include <cmath>

void SimulatedAnnealing::temp_schedule( int cnt, double &temp )
{
    temp = pow( TEMP_COEFF, cnt ) * INIT_TEMP;
}

double SimulatedAnnealing::compute_probability( int step )
{
    return INIT_PROB * pow( PROB_DECREASE, step-1 );
}

std::vector<double> SimulatedAnnealing::get_solution( std::vector<double> solution, Function *test_function )
{

    std::vector<double> solution_new;
    solution_new.assign( 2, 0 );

    int k = 1;
    int m = 0;
    int success = 0;
    int acc_sol = 0;
    double temp = INIT_TEMP;
    double init_prob = 0.2;
    double init_prob_decrease = 0.2;
    int total_accepted = 0;

    //srand (static_cast<double> (time(NULL)));
    srand(0);
    while ( temp > 1e-5 ) {

        for ( m=0; m<1000; m++ ) {
            for ( auto i=0; i<solution.size(); i++) {
                double random_coeff = 4 * (static_cast <double> (rand()) / ( static_cast <double> (RAND_MAX)));
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
        //printf("success: %d ", success);
        //printf("accepted solutions: %d\n", acc_sol);
        acc_sol = 0;
        temp_schedule( k, temp );
        //printf("new temperature: %f\n", temp);
        k++;
        success=0;
    }
    return solution;
}
