//
// Created by karla on 13. 11. 2019..
//

#include "Solution.h"
#include "SantaFe/AbstractNode.h"

template <typename T>
void Solution<T>::copy_data( const T &src )
{
    this->data = src->copy_node();
    this->data->depth = src->depth;
/*
    for( int i=0; i<src->children_number; i++ ) {
        T new_child = src->children[i]->copy_node();
        new_child->depth = src->children[i]->depth;
        this->data->children[i] = new_child;
        copy_data( src->children[i] );
    }
    */
}
