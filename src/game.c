/*
** EPITECH PROJECT, 2019
** Documents
** File description:
** game defender
*/

#include "my.h"

int move_gob(enemy_t *enemy)
{
    int max_value = 600;
    int offset = 100;

    enemy->rect_enemy.left = enemy->rect_enemy.left + offset;
    if (enemy->rect_enemy.left >= max_value)
        enemy->rect_enemy.left = enemy->rect_enemy.left - max_value;
    sfSprite_setTextureRect(enemy->all, enemy->rect_enemy);
    return (0);
}

int if_mouse(sfSprite *mouse, int *coor, sfSprite *back, spr_t *tkt)
{
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(tkt->window);
    sfVector2u resize = sfRenderWindow_getSize(tkt->window);
    float x = (float)resize.x / (float)MAX_WIDTH;
    float y = (float)resize.y / (float)MAX_LENGTH;

    if (coor[0] * x + 100 * x > pos_mouse.x && coor[0] * x < pos_mouse.x &&
        coor[1] * y + 100 * y > pos_mouse.y && coor[1] * y < pos_mouse.y)
        draw_sprite(mouse, coor[0], coor[1], tkt->window);
    else
        draw_sprite(back, coor[0], coor[1], tkt->window);
    return (0);
}

int walk(spr_t *tkt, int i, enemy_t *enemy)
{
    static int move = 0;
    int len = my_strlen(tkt->map);
    static int tmp = 0;
    if ((tkt->map[i + 1 + move] == 'x') && (tmp != LE)) {
        if (clock(tkt, RI, enemy) == 1)
            move++;
        tmp = RI;
    } else if ((tkt->map[i - len + move] == 'x') && (tmp != DOWN)) {
        if (clock(tkt, UP, enemy) == 1)
            move = move - len;
        tmp = UP;
    } else if ((tkt->map[i + len + move] == 'x') && (tmp != UP)) {
        if (clock(tkt, DOWN, enemy) == 1)
            move = move + len;
        tmp = DOWN;
    } else if ((tkt->map[i - 1 + move] == 'x') && (tmp != RI)) {
        if (clock(tkt, LE, enemy) == 1)
            move--;
        tmp = LE;
    } else if (tkt->map[i + 1 + move] == 't')
        clock(tkt, PV, enemy);
}

void enemy_tower(enemy_t *enemy, spr_t *tkt)
{
    tkt->pv = tkt->pv - 100;
    if (tkt->pv <= 0)
        tkt->etat_game = 0;
}

void set_enemy(enemy_t *enemy)
{
    sfTexture *goblin = sfTexture_createFromFile("obj/goblin run.png", NULL);

    enemy->all = create_sprite(goblin, 1);
    enemy->rect_enemy = create_rec(0, 0, 100, 100);
    sfSprite_setTextureRect(enemy->all, enemy->rect_enemy);
}
