#include <iostream>
#include <vector>
#include "../function.h"
#include "../simulated_annealing/RastriginFunction.h"
#include "GeneticAlgorithm.h"
#include "ArithmeticCrossover.h"
#include "UniformMutation.h"
#include "BLX_alpha.h"
#include "SimpleCrossover.h"


int main()
{
//    srand(static_cast<double> (time(NULL)));
    srand(static_cast<double> (0));
    std::vector<double> solution(2, 0);

    GeneticAlgorithm algorithm = GeneticAlgorithm( new BLX_alpha(0.5 ),
            new UniformMutation( -0.08, 0.08 ), 10000, 10, 2 );

    RastriginFunction *test_function = new RastriginFunction();

    solution = algorithm.get_solution( solution, test_function );

    for(int i=0; i<solution.size(); i++) {
        printf("solution[%d] : %f\n", i, solution[i] );
    }
    return 0;

}