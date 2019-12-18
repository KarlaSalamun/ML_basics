//
// Created by karla on 18. 12. 2019..
//

#ifndef SANTAFE_DRAWTRAIL_H
#define SANTAFE_DRAWTRAIL_H

#include <ncurses.h>
#include "AbstractNode.h"
#include "Ant.h"

class DrawTrail {
public:
    ~DrawTrail() {
        endwin();
    }

    DrawTrail() {
        initscr();
        cbreak();
        noecho();
        refresh();
    }

    void print_trail( std::vector<std::pair<int, int>> coordinates, std::vector<bool *> food );

private:
    void print_grid();
    void print_food( bool *food );
};


#endif //SANTAFE_DRAWTRAIL_H
