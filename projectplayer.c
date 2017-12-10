#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "mipslab.h"  /* Declatations for these labs */
#include "project.h"

struct player p = {5, 10, 2, 2};

void move_player(struct player *p, int i) {
	p->y += i;
	if(p->y - p->height < 0) p->y = p->height;
	if(p->y + p->height > 32) p->y = 32 - p->height;
}

void move_up_player(struct player *p) {
	if(p->y - p->height > 0) move_player(p, -3);
}

void move_down_player(struct player *p) {
	if(p->y + p->height < 32) move_player(p, 3);
}

void set_collision_player(struct player p) {
	collision[p.x][p.y] |= 1;
}

uint8_t check_collision_player(struct player *p) {
	return check_collision_body(p->x, p->y, p->width, p->height);
}

void update_player(struct player *p) {
	if(btn_4_pressed()) move_up_player(p);
	if(btn_2_pressed()) move_down_player(p);
}

void blip_player(struct player p) {
	int x, y;
	for(x = p.x - p.width; x <= p.x + p.width; x++) {
		for (y = p.y - p.height; y <= p.y + p.height; y++) {
			if(within_bounds(x, y)) enable_pixel(x, y);
		}
	}
	disable_pixel(p.x, p.y);
}