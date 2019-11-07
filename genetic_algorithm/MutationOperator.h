//
// Created by karla on 06. 11. 2019..
//

#ifndef GENETIC_ALGORITHM_MUTATIONOPERATOR_H
#define GENETIC_ALGORITHM_MUTATIONOPERATOR_H

#include <vector>

class MutationOperator {
public:
    virtual void mutate_solution ( std::vector<double> &solution ) = 0;
};


#endif //GENETIC_ALGORITHM_MUTATIONOPERATOR_H
