#include <iostream>
#include <vector>
#include "../../function.h"
#include "../../test_functions/RastriginFunction.h"
#include "../GeneticAlgorithm.h"
#include "../GeneticAlgorithm.cpp"
#include "Crossover/ArithmeticCrossover.h"
#include "Mutation/UniformMutation.h"
#include "Crossover/BLX_alpha.h"
#include "Crossover/BLX_alpha.cpp"
#include "Crossover/SimpleCrossover.cpp"
#include "Crossover/ArithmeticCrossover.cpp"
#include "Crossover/SimpleCrossover.h"
#include "Mutation/NormalMutation.h"
#include "Mutation/NormalMutation.cpp"
#include "Mutation/UniformMutation.cpp"
#include "TF_optimization.h"
#include "TF_optimization.cpp"
#include "../../test_functions/RastriginFunction.cpp"
#include "../Solution.h"
#include "Selection/TournamentSelection.h"
#include "Selection/TournamentSelection.cpp"
#include "Selection/RouletteSelection.h"
#include "Selection/RouletteSelection.cpp"
#include "NumericSolution.h"

//#define TESTING 0

int generations = 0;

int main()
{
    // srand(static_cast<double> (time(NULL)));
    srand(static_cast<double> (0));
    NumericSolution<std::vector<double>> sol;

    double limit_d = -2;
    double  limit_u = 2;
    unsigned int generation_number = 10000;
    size_t population_size = 1000;
    int dim_size = 6;

    double alpha = 0.4;
    double stddev = 2;

    std::vector<NumericSolution<std::vector<double>>> population;
    NumericSolution<std::vector<double>> solution;
    solution.data.assign( dim_size, 0 );

    for ( int i=0; i<population_size; i++ ) {
        for ( int j=0; j<dim_size; j++ ) {
            solution.data[j] =  -5 + 10*(static_cast <double> (rand()) / ( static_cast <double> (RAND_MAX)));
        }
        population.push_back(solution);
    }


    // TODO: staviti kao smart pointer
    CrossoverOperator<NumericSolution<std::vector<double>>> *crossover
        = new ArithmeticCrossover<NumericSolution<std::vector<double>>>(0.9);
    MutationOperator<NumericSolution<std::vector<double>>> *mutation
        = new UniformMutation<NumericSolution<std::vector<double>>>( limit_d, limit_u );
    SelectionOperator<NumericSolution<std::vector<double>>> *selection
        = new TournamentSelection<NumericSolution<std::vector<double>>>(10);

    std::vector<std::vector<double>> x( 20, std::vector<double>(6, 0));
    std::vector<double> y(20, 0);

    FILE *fp_in = fopen("../tf_file.txt", "r");
    for(int i=0; ; i++) {
        if (fscanf(fp_in, "[%lf, %lf, %lf, %lf, %lf, %lf]\n", &x[i][0], &x[i][1], &x[i][2], &x[i][3], &x[i][4],
                   &y[i]) != 6) {
            break;
        }
    }

    //RastriginFunction *test_function = new RastriginFunction;
    TFOptimization<NumericSolution<std::vector<double>>> *tf
        = new TFOptimization<NumericSolution<std::vector<double>>>( x, y );
    GeneticAlgorithm<NumericSolution<std::vector<double>>> *algorithm
        = new GeneticAlgorithm<NumericSolution<std::vector<double>>>( crossover, mutation, selection, tf, generation_number, population_size, 6 );

    algorithm->get_solution( population, solution );

#ifdef TESTING

 //   RastriginFunction *test_function = new RastriginFunction();

    FILE *fp = fopen( "/home/karla/faks/9. semestar/projekt/genetic_algorithm/results.txt", "w" );
    fprintf(fp, "testing results: \n");
    fprintf(fp, "population size: \t%d\n", population_size );
    fprintf(fp, "==================================================\n");
    fprintf(fp, "crossover method: \tBLX alpha\n");
    fprintf(fp, "mutation method: \tUniform mutation\t[%f, %f]\n", limit_d, limit_u);
    fprintf(fp, "------------------------------\n");

    for( alpha=0; alpha<1; alpha=alpha+0.1 ) {
        algorithm.set_crossover( new BLX_alpha( alpha ) );
        sol = algorithm.get_solution( );
        fprintf( fp, "alpha :\t%1.2f\t", alpha );
        //fprintf(fp, "solution found in %d generations\n", generations+1);
        fprintf(fp,"residual :\t%1.2f\n", sol.fitness );
        sol.print_value();
        generations = 0;
    }

    double stddev = 0.5;

    fprintf(fp, "==================================================\n");
    fprintf(fp, "crossover method: \tBLX alpha\n");
    fprintf(fp, "mutation method: \tNormal mutation\t[dev = %1.1f]\n", stddev);
    fprintf(fp, "------------------------------\n");

    algorithm.set_mutation( new NormalMutation( stddev ) );

    for( alpha=0; alpha<1; alpha=alpha+0.1 ) {
        algorithm.set_crossover( new BLX_alpha( alpha ) );
        sol= algorithm.get_solution(  );
        fprintf( fp, "alpha :\t%1.2f\t", alpha );

        fprintf(fp,"residual :\t%1.2f\n", sol.fitness );
//        fprintf(fp, "solution found in %d generations\n", generations+1);
        sol.print_value();
        generations = 0;
    }

    fprintf(fp, "==================================================\n");
    fprintf(fp, "crossover method: \tArithmetic Crossover\n");
    fprintf(fp, "------------------------------\n");

    for( double lambda=0.1; lambda<1; lambda=lambda+0.1 ) {
        algorithm.set_crossover( new ArithmeticCrossover( lambda ) );
        sol = algorithm.get_solution(  );
        fprintf( fp, "lambda :\t%1.2f\t", lambda );

        fprintf(fp,"residual :\t%1.2f\n", sol.fitness );
       // fprintf(fp, "solution found in %d generations\n", generations+1);
       sol.print_value();
       generations = 0;
    }

    fprintf(fp, "==================================================\n");
    fprintf(fp, "crossover method: \tSimple Crossover\n");
    fprintf(fp, "------------------------------\n");

    algorithm.set_crossover( new SimpleCrossover() );
    sol = algorithm.get_solution();
//    fprintf(fp, "solution found in %d generations\n", generations+1);
    sol.print_value();

    fprintf(fp,"residual :\t%1.2f\n", sol.fitness );
    generations = 0;

    fclose(fp);
#endif

    return 0;

}
