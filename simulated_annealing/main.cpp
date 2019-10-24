#include <iostream>
#include <vector>
#include "RastriginFunction.h"
#include "HimmelblauFunction.h"
#include "EasomFunction.h"
#include "../function.h"
#include "EggholderFunction.h"
#include "RosenbrockFunction.h"
#include "SimulatedAnnealing.h"
#include "GeometricScheme.h"
#include "LinearScheme.h"

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

    SimulatedAnnealing opt_function = SimulatedAnnealing(new LinearScheme(100, 10e5));

    solution = opt_function.get_solution( w, test_function );

    for( auto i=0; i<w.size(); i++ ) {
        std::cout << "solution [" << i << "]: " << solution[i] << "\n";
    }

    delete test_function;
   // printf("%f\n", sqrt( pow( solution[0], 2 ) + pow( solution[1], 2 ) ));
   return 0;
}