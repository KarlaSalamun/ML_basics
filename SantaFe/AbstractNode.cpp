//
// Created by karla on 04. 12. 2019..
//
#include <cstdlib>
#include <algorithm>
#include <cstdio>
#include "AbstractNode.h"

AbstractNode::AbstractNode()
{}

AbstractNode::~AbstractNode()
{
    for( size_t i=0; i<children.size(); i++ ) {
        delete children[i];
    }

}

AbstractNode *AbstractNode::get_child( unsigned int index )
{
    if( index >= this->children.size() ) {
        return NULL;
    }
     return this->children[index];
}

void AbstractNode::add_child( AbstractNode &node )
{
    children.push_back( &node );
}

int AbstractNode::calculate_children()
{
    subtree_num = 0;
    depth = 1;
    for( size_t i=0; i<children.size(); i++ ) {
        subtree_num += children[i]->calculate_children() + 1;
        depth = std::max( depth, children[i]->depth + 1 );
    }
    return subtree_num;
}

AbstractNode *AbstractNode::pick_random( AbstractNode *&node, int rand_depth )
{
    if( rand_depth == 0 ) {
        return node;
    }
    if ( rand_depth > depth ) {
        rand_depth = depth;             // kako se ovo hendla, na ovaj nacin preferiram vecu dubinu
    }
    int random_child = rand() % children.size();
    return pick_random( children[random_child], rand_depth-1 );
}

void AbstractNode::replace_random( AbstractNode *&new_node )
{
    int random_node = rand() % children.size();
    AbstractNode *random = pick_random( children[random_node], children[random_node]->depth );

    if( random->is_terminal ) {
        return;
    }

    int random_index = rand() % random->children_number;
    random->children[random_index] = new_node;
    random->depth = new_node->depth;
    this->depth = ( this->depth > new_node->depth + this->depth - random->depth ) ?
            this->depth : ( new_node->depth + this->depth - random->depth );

}

void AbstractNode::set_child( AbstractNode *&child_node, AbstractNode *&new_node )
{
//    child_node = new_node;
    std::swap( child_node, new_node );
    //children[i] = new_node;
}

std::vector<AbstractNode *> AbstractNode::duplicate_children()
{
    std::vector<AbstractNode *> duplicated;
    for ( size_t i=0; i<children.size(); i++ ) {
        duplicated.push_back( children[i] );
    }
    return duplicated;
}

void AbstractNode::copy_tree( AbstractNode *original, AbstractNode *& copy )
{
    if( original != NULL ) {
        original->copy_node( copy );
        copy->depth = original->depth;
        for( int i=0; i<original->children_number; i++ ) {
            AbstractNode *new_child;
            original->children[i]->copy_node( new_child );
            new_child->depth = original->children[i]->depth;
            copy->children[i] = new_child;
            copy_tree( original->children[i], copy->children[i] );
        }
    }
}
