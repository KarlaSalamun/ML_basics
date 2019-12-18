//
// Created by karla on 12. 12. 2019..
//

#include "TreeFunction.h"
#include "Ant.h"
#define FOOD_TOTAL 89

double TreeFunction::get_value( Solution<AbstractNode *> tree )
{
    Ant *test_ant = new Ant();
    test_ant->set_food();
    tree.data->action( *test_ant );
    double fitness = (double)(FOOD_TOTAL - test_ant->food_cnt);
    delete(test_ant);
    return fitness;
}
