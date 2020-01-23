//
// Created by karla on 06. 11. 2019..
//
#include <cstdlib>
#include "UniformMutation.h"

template<typename  T>
void UniformMutation<T>::mutate_solution( T &solution)
{
    int random_index = rand() % solution.data.size();
    solution.data[random_index] += (static_cast <double> (rand()) / ( static_cast <double> (RAND_MAX)) * (lim_u - lim_l) + lim_l);
/*
    for (int i=0; i<solution.size(); i++) {
        double random_factor = static_cast<double> (rand()) / (static_cast <double> (RAND_MAX)) * 4;
        solution[i] += (static_cast <double> (rand()) / ( static_cast <double> (RAND_MAX))) * ((lim_u - lim_l) + lim_l)
           * random_factor;
    }
*/
}