//
// Created by karla on 13. 11. 2019..
//

#include "Solution.h"
#include "SantaFe/AbstractNode.h"

template <typename T>
void Solution<T>::copy_data( T &dest, const T &src )
{

    std::queue<AbstractNode *> queue_src;
    std::queue<AbstractNode *> queue_dest;

    src->copy_node( dest );
    queue_src.push( src );
    queue_dest.push( dest );

    while ( !queue_dest.empty() ) {
        AbstractNode *current_src = queue_src.front();
        queue_src.pop();

        AbstractNode *current_dest = queue_dest.front();
        queue_dest.pop();

        for (int i = 0; i < current_src->children_number; i++) {
            current_src->children[i]->copy_node(current_dest->children[i] );
            queue_src.push( current_src->children[i] );
            queue_dest.push( current_dest->children[i] );
        }
    }
}

/*
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
*/