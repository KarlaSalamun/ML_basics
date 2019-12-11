//
// Created by karla on 10. 12. 2019..
//
#include <cstdlib>
#include <stdio.h>
#include <queue>
#include "TreeConstructor.h"
#include "MoveNode.h"
#include "TurnLeftNode.h"
#include "TurnRightNode.h"
#include "IfFoodAheadNode.h"
#include "Prog2Node.h"
#include "Prog3Node.h"

using std::queue;

AbstractNode *TreeConstructor::get_random_terminal_node()
{
    int random = rand() % TERM_NDOES;
    switch(random) {
        case 0:
            return new MoveNode;
        case 1:
            return new TurnLeftNode;
        case 2:
            return new TurnRightNode;
    }
}

AbstractNode *TreeConstructor::get_random_function_node()
{
    int random = rand() % FUNC_NODES;
    switch(random) {
        case 0:
            return new IfFoodAheadNode;
        case 1:
            return new Prog2Node;
        case 2:
            return new Prog3Node;
    }
}

AbstractNode *TreeConstructor::get_random_any()
{
    int random = rand() % ( TERM_NDOES + FUNC_NODES );
    switch(random) {
        case 0:
            return new MoveNode;
        case 1:
            return new TurnRightNode;
        case 2:
            return new TurnLeftNode;
        case 3:
            return new IfFoodAheadNode;
        case 4:
            return new Prog2Node;
        case 5:
            return new Prog3Node;
    }
}

AbstractNode *TreeConstructor::construct_tree_full( int max_depth )
{
    AbstractNode *root = get_random_function_node();
    //int depth = rand() % max_depth + 1;
    int depth = 5;
    int identifier = 0;
    root->id = identifier;
    identifier++;
    std::queue<AbstractNode *> queue;
    queue.push( root );

    int ref_depth = 1;
    while( ref_depth < depth - 1 ) {
        int size = queue.size();
        for( int i=0; i<size; i++ ) {
            AbstractNode *current = queue.front();
            queue.pop();
            current->depth = ref_depth;
            for( int j=0; j<current->children_number; j++ ) {
                current->children[j] = get_random_function_node();
                current->children[j]->id = identifier;
                identifier++;
                queue.push( current->children[j] );
            }
        }
        ref_depth++;
    }

    int size = queue.size();
    for( int i=0; i<size; i++ ) {
        AbstractNode *current = queue.front();
        queue.pop();
        current->depth = ref_depth;
        for( int j=0; j<current->children_number; j++ ) {
            current->children[j] = get_random_terminal_node();
            current->children[j]->id = identifier;
            identifier++;
            current->children[j]->depth = depth;
        }
    }
    root->depth = depth;
    return root;
}

AbstractNode *TreeConstructor::construct_tree_grow( int max_depth )
{
//    int depth = rand() % max_depth + 1;
    int depth = 5;
    int identifier = 0;
    AbstractNode *root = get_random_function_node();
    root->id = identifier;
    identifier++;

    std::queue<AbstractNode *> queue;
    queue.push( root );

    int ref_depth = 1;
    while( ref_depth < depth-1 ) {
        int size = queue.size();
        for( int i=0; i<size; i++ ) {
            AbstractNode *current = queue.front();
            queue.pop();
            current->depth = ref_depth;
            if( current->is_terminal ) {
                continue;
            }
            for( int j=0; j<current->children_number; j++ ) {
                current->children[j] = get_random_any();
                current->children[j]->id = identifier;
                identifier++;
                queue.push( current->children[j] );
            }
        }
        ref_depth++;
    }
    int size = queue.size();
    for( int i=0; i<size; i++ ) {
        AbstractNode *current = queue.front();
        queue.pop();
        if( current->is_terminal ) {
            continue;
        }
        for( int j=0; j<current->children_number; j++ ) {
            current->children[j] = get_random_terminal_node();
            current->children[j]->id = identifier;
            identifier++;
            current->children[j]->depth = depth;
        }
    }
    root->depth = depth;
    return root;
}

void TreeConstructor::draw_tree( AbstractNode *&root )
{
    FILE *fp = fopen( "../tree.dot",  "w+");
    fprintf( fp, "digraph D {\n\n" );

    std::queue<AbstractNode *> queue;
    queue.push( root );

    fprintf( fp, "\t%d [label=\"%s\"]\n", root->id, root->name );
    int ref_depth = 1;
    while( ref_depth < root->depth ) {
        int size = queue.size();
        for( int i=0; i<size; i++ ) {
            AbstractNode *current = queue.front();
            queue.pop();
            for( int j=0; j<current->children_number; j++ ) {
                fprintf( fp, "\t%d [label=\"%s\"]\n", current->children[j]->id, current->children[j]->name );
                fprintf( fp, "\t%d -> %d;\n", current->id, current->children[j]->id );
                queue.push( current->children[j] );
            }
        }
        ref_depth++;
    }
    fprintf( fp, "}\n" );
    fclose( fp );
}


