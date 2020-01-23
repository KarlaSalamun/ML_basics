//
// Created by karla on 06. 11. 2019..
//
#include <cstdlib>
#include "BLX_alpha.h"

template<typename T>
void BLX_alpha<T>::get_children( std::vector<T> &parents, std::vector<T> &children )
{
    double cmin, cmax, I;


    for(int i=0; i<2; i++) {
        children[i].data.assign( parents[i].data.size(), 0 );
        for (int j = 0; j < parents[0].data.size(); j++) {
            if (parents[0].data[j] > parents[1].data[j]) {
                cmax = parents[0].data[j];
                cmin = parents[1].data[j];
            } else {
                cmax = parents[1].data[j];
                cmin = parents[0].data[j];
            }
            I = cmax - cmin;

            children[i].data[j] = static_cast <double> (rand()) /
                                    ( static_cast <double> (RAND_MAX))* ((cmax+I*alpha - cmin-I*alpha) + (cmin-I*alpha));
        }
    }
}