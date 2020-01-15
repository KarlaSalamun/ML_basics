//
// Created by karla on 18. 12. 2019..
//
#include <utility>
#include <unistd.h>
#include "DrawTrail.h"

void DrawTrail::print_trail( std::vector<std::pair<int, int>> coordinates, std::vector<std::array<bool, 32*32>> food ) {

    for (size_t i = 0; i < coordinates.size(); i++) {
        clear();
        print_grid();
        print_food(food[0]);
        mvprintw(2 * std::get<0>(coordinates[i]), 2 * std::get<1>(coordinates[i]), "m");
        refresh();
        usleep(2e5);
    }
}

void DrawTrail::print_grid()
{
    for( int i=0; i<2*32; i++ ) {
        if( i%2 == 0 ) {
            for( int j=1; j<2*32; j+=2 ) {
                mvprintw( i, j, "|" );
            }
        } else {
            for( int j=0; j<2*32; j++ ) {
                mvprintw( i, j, "-" );
            }
        }
    }
}

void DrawTrail::print_food( std::array<bool, 32*32> food ) {
    for( int i=0; i<32; i++ ) {
        for( int j=0; j<32; j++ ) {
            if( food[ 32*i +j ] ) {
                mvprintw( 2*i, 2*j, "+" );
            }
        }
    }
}
