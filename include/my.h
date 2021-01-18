/*
** EPITECH PROJECT, 2019
** MUL_my_DEFENDER_2018
** File description:
** __DESCRIPTION__
*/

#ifndef MUL_MY_DEFENDER_2018_INCLUDE_H
    #define MUL_MY_DEFENDER_2018_INCLUDE_H

#include <fcntl.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <SFML/Graphics.h>
#include <SFML/Window/Types.h>
#include <SFML/Window/Export.h>
#include <SFML/System/Vector2.h>

#define MAX_WIDTH (1920)
#define MAX_LENGTH (1080)
#define RI (1)
#define UP (2)
#define DOWN (3)
#define LE (4)
#define PV (5)
#define BACK (0)
#define ROCK (1)
#define RIGHT (2)
#define PLACE (3)
#define TURN (4)
#define TURRET (5)
#define TOWER (6)
#define BACK_T (7)
#define GOB (0)

typedef struct enemy_s {
    sfSprite *all;
    int etat;
    int tmp;
    int move_on_map;
    int nb_gob;
    sfTexture *goblin;
    int move;
    sfIntRect rect_enemy;
    struct enemy_s *next;
    struct enemy_s *prev;
} enemy_t;

typedef struct spr_s {
    sfSprite **back;
    sfSprite **mouse;
    int pv;
    int nb_turret;
    int *if_turret;
    sfEvent event;
    int state_turret;
    sfText *Tpv;
    sfIntRect *rect_back;
    sfIntRect *rect_mouse;
    sfRenderWindow *window;
    char *map;
    int gold;
    sfText *Tgold;
    sfClock *clock;
    int etat_game;
} spr_t;



//--------------------------------defender-------------------------------//
int clock(spr_t *tkt, int i, enemy_t *enemy);
int analyse_events(spr_t *tkt);
void begin_game(spr_t *tkt, enemy_t *enemy);
int create_window(spr_t *tkt, enemy_t *enemy);
char *readl(char *file);
int move_enemy(enemy_t *enemy, int i);

//-------------------------------game------------------------------------//
int move_gob(enemy_t *enemy);
int if_mouse(sfSprite *mouse, int *coor, sfSprite *back, spr_t *tkt);
int walk(spr_t *tkt, int i, enemy_t *enemy);
void set_enemy(enemy_t *enemy);
void enemy_tower(enemy_t *enemy, spr_t *tkt);
int init_game(spr_t *tkt, enemy_t *enemy);

//------------------------------sprite-----------------------------------//
int set_rect(spr_t *tkt);
int set_rect_sprite(spr_t *tkt);
int drawback(spr_t *tkt, enemy_t *enemy);
int rotate_sprite_turn(spr_t *tkt, int i, int *coor);
int rotate_sprite_right(spr_t *tkt, int i, int *coor);

//------------------------------utils_csfml------------------------------//
sfSprite *create_sprite(sfTexture *texture, float size);
sfText *create_text(char *string, int size, sfFont *font);
void draw_sprite(sfSprite *sprite, int x, int y, sfRenderWindow *window);
void draw_text(sfText *text, int x, int y, sfRenderWindow *window);
sfIntRect create_rec(int top, int left, int width, int height);

//------------------------------utils------------------------------------//
int my_strlen(char *str);
void my_putchar(char c);
void my_putstr(char *c);

//------------------------------utils_csfml_2----------------------------//
int button_sprite(spr_t *tkt, sfVector2f pos_sprite, int h_spr);
//------------------------------enemy_init-------------------------------//
int add_element(enemy_t **enemy);
//------------------------------number-----------------------------------//
int my_getnbr(char const *str);
char *int_to_str(int nb);
int get_int_size(int nb);
char *my_revstr(char *str);
char *int_to_str2(int nb);

int clock_snd(int g, spr_t *tkt);
int add_element_snd(enemy_t **enemy, enemy_t *tmp, enemy_t *new, int nb);

#endif
