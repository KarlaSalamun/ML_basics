#include <iostream>
#include <vector>
#include "Ant.h"
#include "TreeConstructor.h"

int main()
{
    FILE *fp;
    fp = fopen( "/home/karla/faks/9. semestar/projekt/SantaFe/13-SantaFeAntTrail.txt", "r" );

    Ant *ant = new Ant();

    int height, width;

    fscanf( fp, "%d", &height );
    char ch = fgetc(fp);
    fscanf( fp, "%d", &width );

    ant->set_dimensions( width, height );
    ant->food = new bool[ant->map_height * ant->map_width];

    for (int i=0; i<ant->map_width; i++) {
        ch = fgetc(fp);                                             // skip first character in row
        for (int j=0; j<ant->map_height; j++) {
            ant->food[i*ant->map_width + j] = fgetc(fp) == '1';
        //    printf("%d ", ant->food[i*ant->map_height + j]);
        }
        //printf("\n");
    }
    while(ant->is_food_ahead()) {
        ant->move();
    }
    ant->turn_right();

    while(ant->is_food_ahead()) {
        ant->move();
    }
    ant->turn_left();
    while(ant->is_food_ahead()) {
        ant->move();
    }

    printf("%d %d %d\n", ant->ant_position.x, ant->ant_position.y, ant->food_cnt);

    TreeConstructor *tc = new TreeConstructor();
    AbstractNode *root = tc->construct_tree_grow( 5 );
    tc->draw_tree( root );
//    root->action(reinterpret_cast<Ant &>(ant) );

}
