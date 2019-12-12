#include <iostream>
#include <vector>
#include "Ant.h"
#include "../Solution.h"
#include "TreeConstructor.h"
#include "TreePopulation.h"
#include "../genetic_algorithm/CrossoverOperator.h"
#include "../genetic_algorithm/SelectionOperator.h"
#include "../genetic_algorithm/MutationOperator.h"
#include "GeneticAlgorithm.h"
#include "TreeFunction.h"
#include "TreeCrossover.h"
#include "TreeMutation.h"
#include "TreeSelection.h"
#include "GeneticAlgorithm.cpp"
//#include "TreeConstructor.cpp"

int main()
{
    srand(static_cast<double> (time(NULL)));
    FILE *fp;
    fp = fopen( "/home/karla/faks/9. semestar/projekt/SantaFe/13-SantaFeAntTrail.txt", "r" );

    Ant *ant = new Ant();

    int height, width;

    fscanf( fp, "%d", &height );
    char ch = fgetc(fp);
    fscanf( fp, "%d", &width );

    ant->set_dimensions( width, height );
    ant->food = new bool[ant->map_height * ant->map_width];

    for (int i=0; i<ant->map_width; i++) {
        ch = fgetc(fp);                                             // skip first character in row
        for (int j=0; j<ant->map_height; j++) {
            ant->food[i*ant->map_width + j] = fgetc(fp) == '1';
        //    printf("%d ", ant->food[i*ant->map_height + j]);
        }
        //printf("\n");
    }
/*
    while(ant->is_food_ahead()) {
        ant->move();
    }
    ant->turn_right();

    while(ant->is_food_ahead()) {
        ant->move();
    }
    ant->turn_left();
    while(ant->is_food_ahead()) {
        ant->move();
    }
*/

//    printf("%d %d %d\n", ant->ant_position.x, ant->ant_position.y, ant->food_cnt);

    TreeConstructor *tc = new TreeConstructor();
    std::vector<Solution<AbstractNode *>> population;
    Solution<AbstractNode *> result;
    Solution<AbstractNode *> tmp;
    int population_size = 10;
    for( int i=0; i<population_size; i++ ) {
        tmp.data = tc->construct_tree_full( 3 );
        population.push_back( tmp );
    }

    Solution<AbstractNode *> *sol = new Solution<AbstractNode *>;
    Solution<AbstractNode *> *sol1 = new Solution<AbstractNode *>;
    AbstractNode *root = tc->construct_tree_full( 5 );
    AbstractNode *root1 = tc->construct_tree_full( 5 );
    sol->data = root;
    sol1->data = root1;
    std::vector<Solution<AbstractNode *>> parents;
    parents.push_back(*sol);
    parents.push_back(*sol1);
    //std::vector<Solution<AbstractNode *>> offspring = c->get_children(parents);
    //tc->draw_tree( root );
    //root->action( *ant );
    //printf( "food eaten: %d\n", ant->food_cnt );

    tc->draw_tree( parents[0].data, "input.dot" );

    //TreePopulation *p = new TreePopulation(1, 2);

    //std::vector<Solution<AbstractNode *>> population = p->create(1);

    CrossoverOperator<Solution<AbstractNode *>> *crossover = nullptr;
    MutationOperator<Solution<AbstractNode *>> *mutation = nullptr;
    SelectionOperator<Solution<AbstractNode *>> *selection = nullptr;

    TreeFunction *test_function = new TreeFunction();

    int generation_number = 10;

    GeneticAlgorithm<AbstractNode *> *algorithm = new GeneticAlgorithm<AbstractNode *> ( crossover, mutation,
            selection, test_function, generation_number, population_size, 0 );

    result = algorithm->get_solution( population );
    tc->draw_tree(result.data, "result.dot");
    printf("final result: %d\n", (int)result.fitness);
}
