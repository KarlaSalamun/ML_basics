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
    //delete ant;

    TreeConstructor *tc = new TreeConstructor();

    size_t population_size = 300;
    std::vector<Solution<AbstractNode *>> population(population_size);

    for( size_t i=0; i<population_size; i++ ) {
        tc->construct_tree_full( 5, population[i].data );
    }

    fclose(fp);

    TreeCrossover<Solution<AbstractNode *>> *crossover = new TreeCrossover<Solution<AbstractNode *>>();
    TreeSelection<Solution<AbstractNode *>> *selection = new TreeSelection<Solution<AbstractNode *>>();
    TreeMutation<Solution<AbstractNode *>> *mutation = new TreeMutation<Solution<AbstractNode *>>();

    TreeFunction *test_function = new TreeFunction();

    unsigned int generation_number = 100;
    Solution<AbstractNode *> result;

    GeneticAlgorithm<Solution<AbstractNode *>> *algorithm = new GeneticAlgorithm<Solution<AbstractNode *>>
            ( crossover, mutation, selection, test_function, generation_number, population_size, 0 );

    algorithm->get_solution( population, result );

    tc->draw_tree(result.data, "rezultat.dot");

    delete algorithm;
    delete tc;

#ifdef GUI
    std::vector<std::pair<int, int>> coordinates;
    vector<std::array<bool, 32 * 32>> food;

    while( ant->actions_cnt < 600 ) {
        result.data->action( *ant, coordinates, food );
    }

    DrawTrail *dt = new DrawTrail();
    dt->print_trail( coordinates, food );
#endif

    return 0;
}

