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
#include "TreeSelection.cpp"
#include "TreeMutation.cpp"
#include "TreeCrossover.cpp"
#include "DrawTrail.h"

int main()
{
    //srand(static_cast<double> (time(NULL)));
    srand(static_cast<double> (0));
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
          //  printf("%d ", ant->food[i*ant->map_height + j]);
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

    int population_size = 100;

    for( int i=0; i<population_size; i++ ) {
        tmp.data = tc->construct_tree_full( 5 );
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

//    tc->draw_tree( parents[0].data, "input.dot" );

    TreeCrossover<Solution<AbstractNode *>> *crossover = new TreeCrossover<Solution<AbstractNode *>>();
    TreeSelection<Solution<AbstractNode *>> *selection = new TreeSelection<Solution<AbstractNode *>>();
    TreeMutation<Solution<AbstractNode *>> *mutation = new TreeMutation<Solution<AbstractNode *>>();

    TreeFunction *test_function = new TreeFunction();

    int generation_number = 5;
/*
    std::vector<Solution<AbstractNode *>> test_parents;
    std::vector<Solution<AbstractNode *>> test_children;
    AbstractNode *test1 = tc->construct_tree_full(3);
    tc->draw_tree( test1, "parent1.dot" );
    AbstractNode *test2 = tc->construct_tree_full(3);
    tc->draw_tree( test2, "parent2.dot" );
    Solution<AbstractNode *> test_sol = Solution<AbstractNode *>();
    test_sol.data = test1;
    test_parents.push_back(test1);
    test_parents.push_back(test2);
    */
    //tc->draw_tree( test_sol.data, "test.dot" );

    //mutation->mutate_solution( test_sol );
    //test_children = crossover->get_children( test_parents );

    //tc->draw_tree( test_children[0].data, "parent1_after.dot" );
    //tc->draw_tree( test_children[1].data, "parent2_after.dot" );
    //tc->draw_tree( test_sol.data, "test_output.dot" );

        GeneticAlgorithm<Solution<AbstractNode *>> *algorithm = new GeneticAlgorithm<Solution<AbstractNode *>> ( crossover, mutation,
            selection, test_function, generation_number, population_size, 0 );

    result = algorithm->get_solution( population );

/*
    std::vector<std::pair<int, int>> coordinates;
    std::vector<std::array<bool, 32*32>> food;
    result.data->action( *ant, coordinates, food );
    assert( coordinates.size() == food.size() );
    assert( coordinates.size() );

    DrawTrail *dt = new DrawTrail();
    dt->print_trail(coordinates, food);
    delete (dt);
    */
    tc->draw_tree(result.data, "result.dot");
    //printf("\n\n\n");
    //result.data->action( *ant );
    //printf("final result: %d\n", (int)result.fitness);
}
