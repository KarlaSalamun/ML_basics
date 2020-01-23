//
// Created by karla on 18. 01. 2020..
//

#ifndef SANTAFE_TREESOLUTION_H
#define SANTAFE_TREESOLUTION_H

#include "../Solution.h"

template <typename T>
class TreeSolution : public Solution<T> {
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

    TreeSolution( TreeSolution&& sol) : data(sol.data), fitness(sol.fitness)
    {
        sol.data = nullptr;
//            printf("move ctor\n");
    }


    TreeSolution& operator = ( TreeSolution&& other )
    {
        // printf("calling move assignment on %s\n", other.data->name );
        if( &other == this ) {
            return *this;
        }
        delete data;
        this->data = other.data;
        other.data = nullptr;
        return *this;
    }

    // copy constructor - deep copy of obj.data to this->data

    TreeSolution( const TreeSolution& obj )
    {
//            printf( "calling copy ctor on %s\n", obj.data->name );
        //data = new T;
        //*data = *obj.data;
        //printf("copy ctor\n")
        this->copy_data( data, obj.data );
        this->fitness = obj.fitness;
    }


    // copy assignment - deep copy of obj.data to this-> data

    TreeSolution<T>&operator = ( const TreeSolution<T>& obj )
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
    TreeSolution( T data ) : data( data ) {}
    TreeSolution() {}

    void copy_data( T &dest, const T &src );

    ~TreeSolution() {
        delete data;
    }

};


#endif //SANTAFE_TREESOLUTION_H
