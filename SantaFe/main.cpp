#include <vector>
#include "Ant.h"
#include "../Solution.h"
#include "TreeConstructor.h"
#include "GeneticAlgorithm.h"
#include "TreeFunction.h"
#include "TreeCrossover.h"
#include "TreeMutation.h"
#include "TreeSelection.h"
#include "DrawTrail.h"
#include "GeneticAlgorithm.cpp"
#include "TreeSelection.cpp"
#include "TreeMutation.cpp"
#include "TreeCrossover.cpp"

//#define GUI 0

int main()
{
    //srand(static_cast<double> (time(NULL)));
    srand(static_cast<double> (0));
    FILE *fp;
    fp = fopen( "../13-SantaFeAntTrail.txt", "r" );

    Ant *ant = new Ant();

    int height, width;

    fscanf( fp, "%d", &height );
    fgetc(fp);
    fscanf( fp, "%d", &width );

    ant->set_dimensions( width, height );
    ant->food = new bool[ant->map_height * ant->map_width];

    for (int i=0; i<ant->map_width; i++) {
        for (int j=0; j<ant->map_height; j++) {
            ant->food[i*ant->map_width + j] = fgetc(fp) == '1';
        }
        fgetc(fp); // skip first character in row
    }
    //delete ant;

    TreeConstructor *tc = new TreeConstructor();

    size_t population_size = 10;
    std::vector<Solution<AbstractNode *>> population(population_size);

    for( size_t i=0; i<population_size; i++ ) {
        tc->construct_tree_full( 5, population[i].data );
    }

    fclose(fp);

    TreeCrossover<Solution<AbstractNode *>> *crossover = new TreeCrossover<Solution<AbstractNode *>>();
    TreeSelection<Solution<AbstractNode *>> *selection = new TreeSelection<Solution<AbstractNode *>>();
    TreeMutation<Solution<AbstractNode *>> *mutation = new TreeMutation<Solution<AbstractNode *>>();

    TreeFunction *test_function = new TreeFunction();

    unsigned int generation_number = 1;
    Solution<AbstractNode *> result;

    GeneticAlgorithm<Solution<AbstractNode *>> *algorithm = new GeneticAlgorithm<Solution<AbstractNode *>>
            ( crossover, mutation, selection, test_function, generation_number, population_size, 0 );

    Solution<AbstractNode *> rj1, rj2;
    std::vector<Solution<AbstractNode *>> roditelji(2);
    std::vector<Solution<AbstractNode *>> djeca(2);
   // Solution<AbstractNode *> test1, test2;
/*
    AbstractNode *stablo1, *stablo2;
    tc->construct_tree_full( 5, stablo1 );
    tc->construct_tree_full( 5, stablo2 );

    rj1.data = stablo1;
    rj2.data = stablo2;

    //roditelji2[0] =  move( rj2 );
    //roditelji[1] =  move( rj2 );


    roditelji[0] =  move( rj1 );
    roditelji[1] = move( rj2 );

    crossover->get_children( roditelji, djeca );
    mutation->mutate_solution( djeca[0] );

*/


    //delete stablo1;
    //delete stablo2;


    algorithm->get_solution( population, result );

    tc->check_tree( result.data, result.data->depth );

    tc->draw_tree(result.data, "rezultat.dot" );

    delete algorithm;
    delete tc;

#ifdef GUI
    std::vector<std::pair<int, int>> coordinates;
    vector<std::array<bool, 32 * 32>> food;

    while( ant->food_cnt < 89 ) {
        result.data->action( *ant, coordinates, food );
    }

    DrawTrail *dt = new DrawTrail();
    dt->print_trail( coordinates, food );
    delete dt;
#endif

    delete ant;

    return 0;
}

