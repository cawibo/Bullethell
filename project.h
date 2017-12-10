
/*
	GAME
*/
typedef enum {INITIAL, MENU, GAME, CLOSING, CREDITS} State;
typedef struct menu_item {
	char name[16];
	State target;
}menu_item;


void clear(void);
void update(void);
void blip(void);
void draw(void);
uint8_t has_ended(void);
void clear_collision(void);
void start_game(void);
void stop_game(void);
void init_menu(void);
void update_menu(void);
void show_menu(void);
void clear_menu(void);
void run_menu(void);
void init_game(void);
void run_game(void);
void clear_game(void);
void run(void);
void init_credits(void);
void run_credits(void);
void clear_credits(void);
extern uint8_t selected_menu_item;
extern uint8_t menu_size;
extern menu_item menu_items[];

/* Declare 2D int array used for collision detection */
extern uint8_t collision[128][32];


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
extern struct enemy enemies[];

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