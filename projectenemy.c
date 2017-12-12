#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "mipslab.h"  /* Declatations for these labs */
#include "project.h"

/* 
    Move this enemy left one step, ie. its speed.
*/
void move_left_enemy(struct enemy *e){
    e->x -= e->speed;
}

/*
    Resets enemy coordinate to outside right edge if dead.
    Otherwise:
        Move one step left.
        Set collision on the collision matrix.
        Blip the enemy to the screen bitmap array.
*/
void update_enemy(struct enemy *e) {
    if(e->x + e->width < 0) reset_enemy(e);
    move_left_enemy(e);
    collision_set_enemy(*e);
    blip_enemy(*e);
}

/*
  Blip this enemy to the screen bitmap array.  
*/
void blip_enemy(struct enemy e) {
    int x, y;
    for(x = e.x - e.width; x <= e.x + e.width; x++) {
        for(y = e.y - e.height; y <= e.y + e.height; y++) {
            if(within_bounds(x, y)) enable_pixel(x, y);
        }
    }
}

/*
    Set collision bits on the collision bitmap array for this enemy.
*/
void collision_set_enemy(struct enemy e) {
    int x, y;
    for(x = e.x - e.width; x <= e.x + e.width; x++) {
        for(y = e.y - e.height; y <= e.y + e.height; y++) {
            if(within_bounds(x, y)) {
                collision[x][y] |= 1;
                // if(collision[x][y] & 1) collision[x][y] |= 2;
                // else collision[x][y] |= 1;
            }
        }
    }
}

/*
    Not really used, doesn't fit current structure of program.
    Check whether this enemy collides with something else.
*/
uint8_t check_collision_enemy(struct enemy e) {
    int x, y;
    for(x = e.x - e.width; x <= e.x + e.width; x++) {
        for(y = e.y - e.height; y <= e.y + e.height; y++) {
            if(collision[x][y] & 2) return 1;
        }
    }
    return 0;
}

/*
    Reset all values for this enemy.
    Except for the x coordinate, all are randomized.
*/
void reset_enemy(struct enemy *e) {
    score += 2;

    e->height = 2 + new_rnd()%5;
    e->y = e->height + new_rnd() % (31 - e->height) ;
    e-> width = 3 + new_rnd()%5;
    e->x = 128 + e->width;
    e->speed = 2 + new_rnd()%5;
}