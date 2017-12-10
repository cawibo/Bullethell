#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "mipslab.h"  /* Declatations for these labs */
#include "project.h"

// void enemy_move_left(struct enemy *);
void move_left_enemy(struct enemy *e){
    e->x -= e->speed;
}

void update_enemy(struct enemy *e) {
    if(e->x + e->width < 0) reset_enemy(e);
    move_left_enemy(e);
    collision_set_enemy(*e);
    blip_enemy(*e);
}

// void blip(struct enemy);
void blip_enemy(struct enemy e) {
    int x, y;
    for(x = e.x - e.width; x <= e.x + e.width; x++) {
        for(y = e.y - e.height; y <= e.y + e.height; y++) {
            if(within_bounds(x, y)) enable_pixel(x, y);
        }
    }
}

// void collision_set_enemy(struct enemy);
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

// void check_collision_enemy(struct enemy);
uint8_t check_collision_enemy(struct enemy e) {
    int x, y;
    for(x = e.x - e.width; x <= e.x + e.width; x++) {
        for(y = e.y - e.height; y <= e.y + e.height; y++) {
            if(collision[x][y] & 2) return 1;
        }
    }
    return 0;
}

// void reset(struct enemy *);
void reset_enemy(struct enemy *e) {
    e->x = 128;
}