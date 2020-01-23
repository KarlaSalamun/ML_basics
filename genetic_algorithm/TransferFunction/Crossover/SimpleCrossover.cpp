//
// Created by karla on 06. 11. 2019..
//
#include <cstdlib>
#include <ctime>
#include "SimpleCrossover.h"

template <typename T>
void SimpleCrossover<T>::get_children(std::vector<T> &parents, std::vector<T> &children )
{
    children[0].data.assign( parents[0].data.size(), 0 );
    children[1].data.assign( parents[1].data.size(), 0 );

    srand (static_cast<double> (time(NULL)));
    int breakpoint = rand() % parents[0].data.size();

    for(int i=0; i<breakpoint; i++) {
        children[0].data[i] = parents[0].data[i];
        children[1].data[i] = parents[1].data[i];
    }
    for(int i=breakpoint; i<parents[0].data.size(); i++) {
        children[0].data[i] = parents[1].data[i];
        children[1].data[i] = parents[0].data[i];
    }
}
