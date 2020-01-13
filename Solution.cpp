//
// Created by karla on 13. 11. 2019..
//

#include "Solution.h"
#include "SantaFe/AbstractNode.h"

template <typename T>
void Solution<T>::copy_data( T &dest, const T &src )
{
    if( src!= NULL ) {
        src->copy_node( dest );
        dest->depth = src->depth;

        for (int i = 0; i < src->children_number; i++) {
            T new_child;
            src->children[i]->copy_node( new_child );
            new_child->depth = src->children[i]->depth;
            dest->children[i] = new_child;
            copy_data(dest->children[i], src->children[i]);
        }
    }
}
