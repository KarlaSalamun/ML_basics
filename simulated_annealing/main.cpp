#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <cstdlib>
#include <ctime>
#include "RastriginFunction.h"
#include "HimmelblauFunction.h"
#include "EasomFunction.h"
#include "function.h"
#include "EggholderFunction.h"
#include "RosenbrockFunction.h"
#include "SimulatedAnnealing.h"


int main()
{
    std::vector<double> w;
    std::vector<double> solution;

    w.assign( 2, 5 );
    solution.assign(2, 0);

    RastriginFunction *test_function = new RastriginFunction();
    //HimmelblauFunction *test_function = new HimmelblauFunction();
    //EasomFunction *test_function = new EasomFunction();
    //EggholderFunction *test_function = new EggholderFunction();
    //RosenbrockFunction *test_function = new RosenbrockFunction();

    SimulatedAnnealing opt_function = SimulatedAnnealing();

    solution = opt_function.get_solution( w, test_function );

    for( auto i=0; i<w.size(); i++ ) {
        std::cout << solution[i];
        std::cout << "\n";
    }
    /*
    std::cout << k;
    std::cout << "\n";
    std::cout << total_accepted;
    */
    printf("%f\n", sqrt( pow( solution[0], 2 ) + pow( solution[1], 2 ) ));

}