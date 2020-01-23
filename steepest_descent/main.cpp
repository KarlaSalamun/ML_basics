#include <iostream>
#include <cstdio>
#include <vector>
#include "main.h"
#include "quadratic_function.h"
#include "numeric_optimization.h"

int main()
{
    std::vector<double> solution;
    solution.assign(3, 0);

    QuadraticFunction* test_function = new QuadraticFunction();
    NumericOptimization opt_function = NumericOptimization();

    solution = opt_function.get_solution(solution, test_function);

    printf("%f %f %f\n", solution[0], solution[1], solution[2]);

    printf( "value: %f\n", test_function->get_value( solution ) );

    delete test_function;
    return 0;
}