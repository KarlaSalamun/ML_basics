//
// Created by karla on 20. 11. 2019..
//
#include <cstdio>
#include "Ant.h"

Ant::Ant()
{
    dir = up;
    ant_position.x = 0;
    ant_position.y = 0;
    steps_cnt = 0;
    food_cnt = 0;
    actions_cnt = 0;
}

Ant::~Ant()
{
    delete[] food;
}

void Ant::move()
{

    switch( dir ) {
        case up:
            ant_position.y -= 1;
            if( ant_position.y < 0 ) {
                ant_position.y = map_height - 1;
            }
            break;
        case right:
            ant_position.x += 1;
            if( ant_position.x > map_width - 1 ) {
                ant_position.x = 0;
            }
            break;
        case down:
            ant_position.y += 1;
            if( ant_position.y > map_height - 1 ) {
                ant_position.y = 0;
            }
            break;
        case left:
            ant_position.x -= 1;
            if( ant_position.x < 0 ) {
                ant_position.x = map_width - 1;
            }
    }
    if( food[ant_position.y*map_width + ant_position.x] ) {
        food_cnt++;
        food[ant_position.y*map_width + ant_position.x] = false;
    }
    steps_cnt++;
    actions_cnt++;

    //printf("moving\t");
    //printf( "coordinates: %d %d\n", ant_position.x, ant_position.y );

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
            break;
        default:
            dir = left;
    }
    actions_cnt++;
    //printf( "turning left\t" );
    //printf( "coordinates: %d %d\t direction: %d\n", ant_position.x, ant_position.y, dir );

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
    actions_cnt++;

    //printf( "turning right\t" );
    //printf( "coordinates: %d %d\t direction: %d\n", ant_position.x, ant_position.y, dir );

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

void Ant::set_food()
{
    FILE *fp = fopen( "../13-SantaFeAntTrail.txt" , "r" );

    int height, width;

    fscanf( fp, "%d", &height );
    char ch = fgetc(fp);
    fscanf( fp, "%d", &width );

    set_dimensions( width, height );
    food = new bool[map_height * map_width];

    for (int i=0; i<map_width; i++) {
        ch = fgetc(fp);                                             // skip first character in row
        for (int j=0; j<map_height; j++) {
            food[i*map_width + j] = fgetc(fp) == '1';
        }
    }
}
