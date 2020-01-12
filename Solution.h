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
        // disable calling copy ctor and copy assignment
  //      Solution<T> (const Solution<T>& ) = delete;
  //      Solution<T>&operator=(const Solution<T>&) = delete;

        // move ctor - transfer ownership of sol.data to data
        /*
        Solution( Solution&& sol) : data(move(sol.data)), fitness(fitness)
        {
        }
         */

        Solution& operator = ( Solution&& other )
        {
            printf("move assignment\n");
            if( &other == this ) {
                return *this;
            }
            delete data;
            this->data = other.data;
            other.data = nullptr;
            return *this;
        }

        // copy constructor - deep copy of obj.data to this->data

        Solution( const Solution& obj )
        {
            //data = new T;
            //*data = *obj.data;
            //printf("copy ctor\n")
            this->copy_data( data, obj.data );
            this->fitness = obj.fitness;
        }


        // copy assignment - deep copy of obj.data to this-> data

        Solution<T>&operator = ( const Solution<T>& obj )
        {
            if ( &obj == this ) {
                return *this;
            }
            delete data;
            //data = new T;
            this->copy_data( data, obj.data );

            return *this;
        }

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
