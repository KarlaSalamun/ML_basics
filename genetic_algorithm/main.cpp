#include <iostream>
#include <vector>
#include "../function.h"
#include "../simulated_annealing/RastriginFunction.h"
#include "GeneticAlgorithm.h"
#include "ArithmeticCrossover.h"
#include "UniformMutation.h"
#include "BLX_alpha.h"
#include "SimpleCrossover.h"
#include "NormalMutation.h"
#include "../simulated_annealing/TF_optimization.h"
#include "../Solution.h"
#include "TournamentSelection.h"
#include "RouletteSelection.h"

//#define TESTING 0

int generations = 0;

int main()
{
     srand(static_cast<double> (time(NULL)));
//    srand(static_cast<double> (0));
    Solution sol(6);

    double limit_d = -1;
    double  limit_u = 1;
    int generation_number = 20000;
    int population_size = 100;

    double alpha = 0.4;

    // TODO: staviti kao smart pointer
    CrossoverOperator *crossover = new BLX_alpha(1);
    MutationOperator *mutation = new NormalMutation(0.4);
    SelectionOperator *selection = new RouletteSelection();

    std::vector<std::vector<double>> x( 20, std::vector<double>(6, 0));
    std::vector<double> y(20, 0);

    FILE *fp_in = fopen("/home/karla/faks/9. semestar/projekt/simulated_annealing/tf_file.txt", "r");
    //FILE *fp_in = fopen("../../simulated_annealing/tf_file.txt", "r");
    for(int i=0; ; i++) {
        if (fscanf(fp_in, "[%lf, %lf, %lf, %lf, %lf, %lf]\n", &x[i][0], &x[i][1], &x[i][2], &x[i][3], &x[i][4],
                   &y[i]) != 6) {
            break;
        }
    }

    RastriginFunction *test_function = new RastriginFunction();
    TFOptimization *tf = new TFOptimization( x, y );
    GeneticAlgorithm algorithm = GeneticAlgorithm( crossover,
            mutation, selection, tf, generation_number, population_size, 6 );

    sol = algorithm.get_solution();
    sol.print_value();

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
