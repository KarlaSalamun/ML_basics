//
// Created by karla on 12. 12. 2019..
//

#include "TreeFunction.h"
#include "Ant.h"
#define FOOD_TOTAL 89

void TreeFunction::get_value( Solution<AbstractNode *> &solution )
{
    double fitness;
    Ant *test_ant = new Ant();
    test_ant->set_food();

    while ( test_ant->actions_cnt < 600 ) {
        solution.data->action(*test_ant);
    }

    fitness = (double)(FOOD_TOTAL - test_ant->food_cnt);

    delete(test_ant);
    solution.fitness = fitness;
}
