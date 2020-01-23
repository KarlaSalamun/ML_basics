//
// Created by karla on 10. 12. 2019..
//
#include <cstdlib>
#include <stdio.h>
#include <cstring>
#include <string>
#include <queue>
#include <cassert>
#include "TreeConstructor.h"
#include "MoveNode.h"
#include "TurnLeftNode.h"
#include "TurnRightNode.h"
#include "IfFoodAheadNode.h"
#include "Prog2Node.h"
#include "Prog3Node.h"

using std::queue;

// FIXME stavi parametre preko reference svugdje

void TreeConstructor::get_random_terminal_node( AbstractNode *&new_node )
{
    int random = rand() % TERM_NDOES;
    switch(random) {
        case 0:
            new_node = new MoveNode;
            break;
        case 1:
            new_node = new TurnLeftNode;
            break;
        case 2:
            new_node = new TurnRightNode;
            break;
        default:
            new_node = new MoveNode;
            break;
    }
}

void TreeConstructor::get_random_function_node( AbstractNode *&new_node )
{
    int random = rand() % FUNC_NODES;
    switch(random) {
        case 0:
            new_node =  new IfFoodAheadNode;
            break;
        case 1:
            new_node = new Prog2Node;
            break;
        case 2:
            new_node = new Prog3Node;
            break;
        default:
            new_node = new IfFoodAheadNode;
            break;
    }
}

void TreeConstructor::get_random_any( AbstractNode *&new_node )
{
    int random = rand() % ( TERM_NDOES + FUNC_NODES );
    switch(random) {
        case 0:
            new_node = new MoveNode;
            break;
        case 1:
            new_node = new TurnRightNode;
            break;
        case 2:
            new_node = new TurnLeftNode;
            break;
        case 3:
            new_node = new IfFoodAheadNode;
            break;
        case 4:
            new_node = new Prog2Node;
            break;
        case 5:
            new_node = new Prog3Node;
            break;
        default:
            new_node = new MoveNode;
            break;
    }
}

void TreeConstructor::construct_tree_full( int max_depth, AbstractNode *&root )
{
    get_random_function_node( root );
    int depth = rand() % max_depth + 1;
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
                get_random_function_node( current->children[j] );
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
            get_random_terminal_node( current->children[j] );
            current->children[j]->id = identifier;
            identifier++;
            current->children[j]->depth = depth;
        }
    }
    root->depth = depth;
}

void TreeConstructor::construct_tree_grow( int max_depth, AbstractNode *&root )
{
//    int depth = rand() % max_depth + 1;
    int depth = 3;
    int identifier = 0;
    get_random_function_node( root );
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
                get_random_any( current->children[j] );
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
            get_random_terminal_node( current->children[j] );
            current->children[j]->id = identifier;
            identifier++;
            current->children[j]->depth = depth;
        }
    }
    root->depth = depth;
}

void TreeConstructor::rehash_tree( AbstractNode *&root )
{
    std::queue<AbstractNode *> queue;
    queue.push( root );

    int identifier = 0;

    while( !queue.empty() ) {
        AbstractNode *current = queue.front();
        queue.pop();
        current->id = identifier++;

        for( int i=0; i<current->children_number; i++ ) {
            queue.push( current->children[i] );
        }
    }
}

// TODO napravi BFS pomocnu funkciju koja radi obilazak stabla
void TreeConstructor::draw_tree( AbstractNode *&root, std::string filename )
{
    std::queue<AbstractNode *> queue;
    std::string tmp = "../graphs/";

    //strcat( tmp, filename );
    FILE *fp = fopen( (tmp+filename).c_str(), "w+");
    fprintf( fp, "digraph D {\n\n" );


    fprintf( fp, "\t%d [label=\"%s\"]\n", root->id, root->name );

    queue.push( root );
    while( !queue.empty() ) {
        AbstractNode *current = queue.front();
        queue.pop();

        for (int i = 0; i < current->children_number; i++) {
            fprintf(fp, "\t%d [label=\"%s\"]\n", current->children[i]->id, current->children[i]->name);
            fprintf(fp, "\t%d -> %d;\n", current->id, current->children[i]->id);
            queue.push(current->children[i]);
        }
    }

    fprintf( fp, "}\n" );
    fclose( fp );
}

void TreeConstructor::destroy_tree(AbstractNode *&root)
{
    /*
    std::queue<AbstractNode *> queue;
    std::vector<AbstractNode *> delete_nodes;
    queue.push( root );

    int ref_depth = 1;
    while( ref_depth < root->depth ) {
        int size = queue.size();
        for( int i=0; i<size; i++ ) {
            AbstractNode *current = queue.front();
            queue.pop();
            for( int j=0; j<current->children_number; j++ ) {
                queue.push( current->children[j] );
                delete_nodes.push_back( current->children[j] );
            }
        }
        ref_depth++;
    }

    for( size_t i=0; i<delete_nodes.size(); i++ ) {
        delete delete_nodes[i];
    }

    delete root;
     */
}

void TreeConstructor::check_tree(AbstractNode *&root, int depth)
{
    AbstractNode *current;

//    assert( depth == root->depth );
    depth = root->depth;

    current = root;
    if( current != nullptr ) {
        for (int i = 0; i < current->children.size(); i++) {
            if (current->children[i] != nullptr) {
                check_tree(current->children[i], depth - 1);
            }
        }
    }
}

