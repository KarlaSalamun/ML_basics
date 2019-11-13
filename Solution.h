//
// Created by karla on 13. 11. 2019..
//

#ifndef PROJEKT_SOLUTION_H
#define PROJEKT_SOLUTION_H

#include <vector>
#include "function.h"

class Solution {
    public:
        double get_fitness( std::vector<double> solution, Function *test_function );
        void print_value();
        Solution( int dimension );
        std::vector<double> vector;
        double fitness;
};


#endif //PROJEKT_SOLUTION_H
