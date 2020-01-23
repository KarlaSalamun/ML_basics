//
// Created by karla on 06. 11. 2019..
//
#include "ArithmeticCrossover.h"

template <typename T>
void ArithmeticCrossover<T>::get_children(std::vector<T> &parents, std::vector<T> &children )
{
    children[0].data.assign( parents[0].data.size(), 0 );
    children[1].data.assign( parents[1].data.size(), 0 );

    for(int i=0; i<parents[0].data.size(); i++) {
        children[0].data[i] = lambda * parents[0].data[i] + (1 - lambda) * parents[1].data[i];
        children[1].data[i] = lambda * parents[1].data[i] + (1 - lambda) * parents[0].data[i];
    }
}