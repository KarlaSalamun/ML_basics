#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <sstream>
#include <string.h>
#include <stdio.h>
#include "../test_functions/RastriginFunction.h"
#include "../test_functions/HimmelblauFunction.h"
#include "../test_functions/EasomFunction.h"
#include "../function.h"
#include "../test_functions/EggholderFunction.h"
#include "../test_functions/RosenbrockFunction.h"
#include "SimulatedAnnealing.h"
#include "GeometricScheme.h"
#include "LinearScheme.h"
#include "TF_optimization.h"

using namespace std;

int main()
{
    std::vector<double> w(2, 1);
    std::vector<double> solution(2, 0);

    //  TODO makni ovaj path i stavi relativni

    FILE *fp = fopen("/home/karla/faks/9. semestar/projekt/simulated_annealing/tf_file.txt", "r");
    if ( fp == NULL ) {
        exit(1);
    }

    std::vector<double> args(2, 0 );
    std::vector<std::vector<double>> x( 20, std::vector<double>(5, 0));
    std::vector<double> y(20, 0);

    SimulatedAnnealing opt_function = SimulatedAnnealing(new LinearScheme(10, 100000));

    w.assign( 2, 1 );

    for(int i=0; ; i++) {
        if (fscanf(fp, "[%lf, %lf, %lf, %lf, %lf, %lf]\n", &x[i][0], &x[i][1], &x[i][2], &x[i][3], &x[i][4],
                   &y[i]) != 6) {
            break;
        }
    }

    RastriginFunction *test_function = new RastriginFunction();
    //TFOptimization *test_function = new TFOptimization( x, y );

    printf("residual: %lf\n", test_function->get_value(solution));
    solution = opt_function.get_solution( w, test_function );

    for( auto i=0; i<w.size(); i++ ) {
        printf("solution [%d] : %f\n", i, solution[i]);
    }

    printf("residual: %lf\n", test_function->get_value(solution));

    delete test_function;
    fclose(fp);

   return 0;
}