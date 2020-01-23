//
// Created by karla on 20. 11. 2019..
//

#ifndef SANTAFE_ANT_H
#define SANTAFE_ANT_H

enum direction{ up, right, down, left };

class Ant {
    public:
        struct position {
            int x,y;
        };
        position ant_position;

        direction dir;

        Ant();
        ~Ant();

        int steps_cnt;
        int food_cnt;
        int actions_cnt;

        bool *food;
        int map_height;
        int map_width;

        void move();
        void turn_left();
        void turn_right();
        bool is_food_ahead();

        void set_dimensions( int width, int height );
        void set_food();
};


#endif //SANTAFE_ANT_H
