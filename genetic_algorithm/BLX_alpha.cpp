//
// Created by karla on 06. 11. 2019..
//
#include <cstdlib>
#include "BLX_alpha.h"

std::vector<Solution> BLX_alpha::get_children(std::vector<Solution> parents){
    double cmin, cmax, I;
    std::vector<Solution> children(2, Solution(parents[0].vector.size()));

    for(int i=0; i<2; i++) {
        for (int j = 0; j < parents[0].vector.size(); j++) {
            if (parents[0].vector[j] > parents[1].vector[j]) {
                cmax = parents[0].vector[j];
                cmin = parents[1].vector[j];
            } else {
                cmax = parents[1].vector[j];
                cmin = parents[0].vector[j];
            }
            I = cmax - cmin;

            children[i].vector[j] = static_cast <double> (rand()) /
                    ( static_cast <double> (RAND_MAX))* ((cmax+I*alpha - cmin-I*alpha) + (cmin-I*alpha));
        }
    }
    return children;
}