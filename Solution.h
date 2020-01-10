//
// Created by karla on 13. 11. 2019..
//

#ifndef PROJEKT_SOLUTION_H
#define PROJEKT_SOLUTION_H

#include <vector>
#include <cstdio>
#include "function.h"

using namespace std;

template <typename  T>
class Solution {
    public:
        T data = nullptr;
        double fitness;
/*
        Solution<T>& operator=( Solution<T> other)
        {
            this->copy_data(  )
            data->copy_tree( data, other.data );
            return *this;
        }
*/

    Solution<T> (const Solution<T>& ) = delete;
    Solution<T>&operator=(const Solution<T>&) = delete;

    Solution& operator = ( Solution&& other )
        {
            printf("move assignment\n");
            this->data = other.data;
            other.data = nullptr;
            return *this;
        }

        Solution(Solution&& sol) : data(data), fitness(fitness) {
            sol.data = nullptr;
        }
/*
        Solution( const Solution& obj )
        {
            //printf("copy ctor\n")ss by value which will make a copy, but you cannot copy a std::unique_ptr. Passing by reference should work:;
            this->copy_data( data, obj.data );
            this->fitness = obj.fitness;
        }
*/
        double get_fitness(T solution, Function<T> *test_function )
        {
            return test_function->get_value( solution );
        }
/*
        void print_value() {
            for (int i=0; i<this->vector.size(); i++ ) {
                std::printf("Solution [%d]: %lf \n", i+1, this->vector[i]);
            }
            std::printf("Residual: %lf\n", this->fitness );
        }
        */
//        Solution( int dimension ) { data.assign( dimension, 0 ); }
        Solution( T data ) : data( data ) {}
        Solution() {}

        void copy_data( T &dest, const T &src );

        ~Solution() {
            delete data;
        }

};

#endif //PROJEKT_SOLUTION_H
