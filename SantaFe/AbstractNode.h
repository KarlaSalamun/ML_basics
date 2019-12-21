//
// Created by karla on 04. 12. 2019..
//

#ifndef SANTAFE_ABSTRACTNODE_H
#define SANTAFE_ABSTRACTNODE_H

#include <vector>
#include <array>
#include "Ant.h"

#define TERM_NDOES 3
#define FUNC_NODES 3

class AbstractNode {
    public:
        std::vector<AbstractNode *> children;
        int depth;
        int subtree_num;
        int children_number;
        int id;
        bool is_terminal;
        const char *name;

        AbstractNode();
        virtual ~AbstractNode();

        void copy_tree( AbstractNode *original, AbstractNode *& copy );
        virtual AbstractNode *copy_node() = 0;

        virtual int action( Ant &ant ) = 0;

        virtual int action(Ant &ant, std::vector<std::pair<int, int>> &coordinates, std::vector<std::array<bool, 32*32>> &food) = 0;

    AbstractNode *get_child( int index );
        void add_child( AbstractNode &node );

        int calculate_children();

        AbstractNode *pick_random( AbstractNode *&node, int rand_depth );
        void replace_random(AbstractNode *&new_node );

        void set_child( AbstractNode *&child_node, AbstractNode *&new_node );
        std::vector<AbstractNode *> duplicate_children();
};


#endif //SANTAFE_ABSTRACTNODE_H
