
/*
	GAME
*/
typedef enum {INITIAL, MENU, GAME, OPTIONS, CREDITS} State;
typedef struct menu_item {
	char name[16];
	State target;
}menu_item;
extern uint8_t selected_menu_item;
extern uint8_t menu_size;
extern menu_item menu_items[];
extern uint8_t score;
extern uint8_t inverted_colors;

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

void run_options(void);
void run(void);
void init_credits(void);
void run_credits(void);
void clear_credits(void);
void clear_score(void);
void clear_enemies(void);
int new_rnd();

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
extern const uint8_t enemies_size;
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