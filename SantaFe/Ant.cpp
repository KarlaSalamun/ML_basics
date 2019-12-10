//
// Created by karla on 20. 11. 2019..
//

#include "Ant.h"

Ant::Ant()
{
    dir = right;
    ant_position.x = 0;
    ant_position.y = 0;
    steps_cnt = 0;
    food_cnt = 0;
}

void Ant::move()
{

    switch( dir ) {
        case up:
            ant_position.y -= 1;
            if( ant_position.y < 0 ) {
                ant_position.y = 0;
            }
            break;
        case right:
            ant_position.x += 1;
            if( ant_position.x > map_width - 1 ) {
                ant_position.x = map_width - 1;
            }
            break;
        case down:
            ant_position.y += 1;
            if( ant_position.y > map_height - 1 ) {
                ant_position.y = map_height -1;
            }
            break;
        case left:
            ant_position.x -= 1;
            if( ant_position.x < 0 ) {
                ant_position.x = 0;
            }
    }
    if( food[ant_position.y*map_width + ant_position.x] ) {
        food_cnt++;
        food[ant_position.y*map_width + ant_position.x] = false;
    }
}

void Ant::turn_left()
{
    switch(dir) {
        case up:
            dir = left;
            break;
        case right:
            dir = up;
            break;
        case down:
            dir = right;
            break;
        case left:
            dir = down;
        default:
            dir = left;
    }
}

void Ant::turn_right()
{
    switch(dir) {
        case up:
            dir = right;
            break;
        case right:
            dir = down;
            break;
        case down:
            dir = left;
            break;
        case left:
            dir = up;
        default:
            dir = right;
    }
}

void Ant::set_dimensions(int width, int height)
{
    map_width = width;
    map_height = height;
}

bool Ant::is_food_ahead()
{
    switch(dir) {
        case up:
            if ( ant_position.y == 0 ) {
                return false;
            }
            return food[(ant_position.y - 1) * map_width + ant_position.x];
        case right:
            if ( ant_position.x + 1 == map_width - 1 ) {
                return false;
            }
            return food[ant_position.y * map_width + ant_position.x + 1];
        case down:
            if ( ant_position.y + 1 == map_height - 1 ) {
                return false;
            }
            return food[(ant_position.y + 1) * map_width + ant_position.x];
        case left:
            if ( ant_position.x == 0 ) {
                return false;
            }
            return food[ant_position.y * map_width + ant_position.x - 1];
    }
}

