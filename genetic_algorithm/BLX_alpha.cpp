//
// Created by karla on 06. 11. 2019..
//
#include <cstdlib>
#include "BLX_alpha.h"

std::vector<std::vector<double>> BLX_alpha::get_children(std::vector<std::vector<double>> parents){
    double cmin, cmax, I;
    std::vector<std::vector<double>> children(2, std::vector<double>(parents[0].size(), 0));

    for(int i=0; i<2; i++) {
        for (int j = 0; j < parents[0].size(); j++) {
            if (parents[0][j] > parents[1][j]) {
                cmax = parents[0][j];
                cmin = parents[1][j];
            } else {
                cmax = parents[1][j];
                cmin = parents[0][j];
            }
            I = cmax - cmin;

            children[i][j] = static_cast <double> (rand()) /
                    ( static_cast <double> (RAND_MAX))* ((cmax+I*alpha - cmin-I*alpha) + (cmin-I*alpha));
        }
    }
    return children;
}