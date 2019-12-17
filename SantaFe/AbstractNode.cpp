//
// Created by karla on 04. 12. 2019..
//
#include <cstdlib>
#include <algorithm>
#include <cstdio>
#include "AbstractNode.h"

AbstractNode::AbstractNode()
{}

AbstractNode::AbstractNode( std::vector <AbstractNode *> children, int depth, int subtree_num )
{
    children = children;
    depth = depth;
    subtree_num = subtree_num;
}

AbstractNode *AbstractNode::get_child( int index )
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
    for( int i=0; i<children.size(); i++ ) {
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
    AbstractNode *random = pick_random( children[random_node], depth );

    int random_index = rand() % random->children_number;
    random->children[random_index] = new_node;
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
    for ( int i=0; i<children.size(); i++ ) {
        duplicated.push_back( children[i] );
    }
    return duplicated;
}