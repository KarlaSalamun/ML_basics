#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <cstdlib>
#include <ctime>
#include "RastriginFunction.h"
#include "HimmelblauFunction.h"

#define TEMP_COEFF 0.99
#define INIT_TEMP 10e5

void temp_schedule( int cnt, double &temp )
{
    temp = pow( TEMP_COEFF, cnt ) * INIT_TEMP;
}

int main()
{
    std::vector<double> w;
    std::vector<double> w_new;

    w.assign( 2, 10 );
    w_new.assign( 2, 0 );

    //RastriginFunction *test_function = new RastriginFunction();
    HimmelblauFunction *test_function = new HimmelblauFunction();
    int k = 1;
    int m = 0;
    int success = 0;
    int acc_sol = 0;
    double temp = INIT_TEMP;
    double init_prob = 0.5;
    double init_prob_decrease = 0.5;
    int total_accepted = 0;

    //srand (static_cast<double> (time(NULL)));
    srand(0);
    while ( temp > 1e-5 ) {
        double probability = init_prob * pow(init_prob_decrease, k - 1);

        for ( m=0; m<1000; m++ ) {
            for ( auto i=0; i<w.size(); i++) {
                double random_coeff = 4 * (static_cast <double> (rand()) / ( static_cast <double> (RAND_MAX)));
                double random = -0.5 + static_cast <double> (rand()) / ( static_cast <double> (RAND_MAX));
                w_new[i] = w[i] + random*random_coeff;
            }
            double delta = test_function->get_value(w_new) - test_function->get_value(w);
            if ( delta <= 0 ) {
                w = w_new;
                success++;
                acc_sol++;
            //    printf("delta: %f\n", delta);
            }
            else {
                if ((static_cast <float> (rand()) / (static_cast <float> (RAND_MAX))) < probability) {
                    w = w_new;
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
    for( auto i=0; i<w.size(); i++ ) {
        std::cout << w[i];
        std::cout << "\n";
    }
    std::cout << k;
    std::cout << "\n";
    std::cout << total_accepted;

    printf("%f\n", sqrt( pow( w[0], 2 ) + pow( w[1], 2 ) ));

}