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

//#define GUI 1

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
        fgetc(fp); // skip first character in row
        for (int j=0; j<ant->map_height; j++) {
            ant->food[i*ant->map_width + j] = fgetc(fp) == '1';
        }
    }
    delete ant;


    TreeConstructor *tc = new TreeConstructor();

    size_t population_size = 80;
    std::vector<Solution<AbstractNode *>> population(population_size);

    for( size_t i=0; i<population_size; i++ ) {
        population[i].data = tc->construct_tree_full( 3 );
    }

    TreeCrossover<Solution<AbstractNode *>> *crossover = new TreeCrossover<Solution<AbstractNode *>>();
    TreeSelection<Solution<AbstractNode *>> *selection = new TreeSelection<Solution<AbstractNode *>>();
    TreeMutation<Solution<AbstractNode *>> *mutation = new TreeMutation<Solution<AbstractNode *>>();

    TreeFunction *test_function = new TreeFunction();

    unsigned int generation_number = 400;
    Solution<AbstractNode *> result;

    GeneticAlgorithm<Solution<AbstractNode *>> *algorithm = new GeneticAlgorithm<Solution<AbstractNode *>>
            ( crossover, mutation, selection, test_function, generation_number, population_size, 0 );
    algorithm->get_solution( population, result );

    delete tc;
    delete algorithm;
    return 0;
}
