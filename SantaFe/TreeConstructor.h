//
// Created by karla on 10. 12. 2019..
//

#ifndef SANTAFE_TREECONSTRUCTOR_H
#define SANTAFE_TREECONSTRUCTOR_H

#include <string>
#include "AbstractNode.h"

class TreeConstructor {
    public:
        AbstractNode *get_random_terminal_node();
        AbstractNode *get_random_function_node();
        AbstractNode *get_random_any();
        AbstractNode *construct_tree_full( int max_depth );
        AbstractNode *construct_tree_grow( int max_depth );
        void rehash_tree( AbstractNode *&root );
        void draw_tree( AbstractNode *&root, std::string filename );
};


#endif //SANTAFE_TREECONSTRUCTOR_H
