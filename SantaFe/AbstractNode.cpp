//
// Created by karla on 04. 12. 2019..
//
#include <cstdlib>
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

/* TODO; ovo nije dobro, trebalo bi random cvor na random dubini
    ili da se povecava vjerojatnost mutacije svakog djeteta sa subtree_num */
AbstractNode *AbstractNode::pick_random( AbstractNode *&node, int rand_depth )
{
    if( rand_depth == 0 ) {
        return this;
    }
    if ( rand_depth > depth ) {
        rand_depth = depth;             // kako se ovo hendla, na ovaj nacin preferiram vecu dubinu
    }
    int random_child = rand() % children.size();
    return pick_random( children[random_child], rand_depth-1 );
}

/* TODO napraviti da se mijenja bilo koji cvor iz podstabla, kombinacija sa pick_random?? */
void AbstractNode::replace_random( AbstractNode &new_node )
{
    int random_node = rand() % children.size();
    AbstractNode *random = pick_random( children[random_node], depth );
    set_child( random_node, new_node );
}

void AbstractNode::set_child( int i, AbstractNode &new_node )
{
    children[i] = &new_node;
}

std::vector<AbstractNode *> AbstractNode::duplicate_children()
{
    std::vector<AbstractNode *> duplicated;
    for ( int i=0; i<children.size(); i++ ) {
        duplicated.push_back( children[i] );
    }
    return duplicated;
}