
/*
	GAME
*/
void clear(void);
void update(void);
void blip(void);
void draw(void);
uint8_t has_ended(void);
void clear_collision(void);

/* Declare 2D int array used for collision detection */
extern uint8_t collision[128][32];
typedef enum {INITIAL, MENU, OTHER, CLOSING} State;

/*
	ENEMIES
*/
typedef struct enemy {
	int x;
	int y;
	int speed;
	int width;
	int height;
}enemy;
void move_left_enemy(struct enemy *);
void blip_enemy(struct enemy);
void collision_set_enemy(struct enemy);
uint8_t collision_check_enemy(struct enemy);
void reset_enemy(struct enemy *);
void update_enemies(void);
void blip_enemies(void);
extern struct enemy enemies[10];

/*
	PLAYER
*/
typedef struct player {
	int x;
	int y;
	int width;
	int height;
}player;
void move_up_player(struct player *);
void move_down_player(struct player *);
void move_player(struct player *, int i);
void blip_player(struct player);
extern struct player p;

/*
	IO
*/
void display_screen(const uint8_t *data);
void clear_screen(void);
void enable_pixel(int x, int y);
void disable_pixel(int x, int y);
int translate_coordinates(int x, int y);

int btn_2_pressed(void);
int btn_3_pressed(void);
int btn_4_pressed(void);

/* Declare bitmap array containing screen */
extern uint8_t screen[128*4];