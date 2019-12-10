//
// Created by karla on 04. 12. 2019..
//

#ifndef SANTAFE_ABSTRACTNODE_H
#define SANTAFE_ABSTRACTNODE_H

#include <vector>
#include "Ant.h"

class AbstractNode {
    public:
        std::vector<AbstractNode *> children;
        int depth;
        int subtree_num;

        AbstractNode( std::vector<AbstractNode *> children, int depth, int subtree_num );
        AbstractNode();

        virtual AbstractNode *copy() = 0;
        virtual int action( Ant &ant ) = 0;

        AbstractNode *get_child( int index );
        void add_child( AbstractNode &node );

        int calculate_children();

        AbstractNode *pick_random( AbstractNode *&node, int rand_depth );
        void replace_random( AbstractNode &new_node );

        void set_child( int i, AbstractNode &new_node );
        std::vector<AbstractNode *> duplicate_children();
};


#endif //SANTAFE_ABSTRACTNODE_H
