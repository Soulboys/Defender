/*
** EPITECH PROJECT, 2019
** Documents
** File description:
** principal file defender
*/

#include "my.h"

int move_enemy(enemy_t *enemy, int i)
{
    sfVector2f move_right = {1, 0};
    sfVector2f move_up = {0, -1};
    sfVector2f move_down = {0, 1};
    sfVector2f move_left = {-1, 0};

    if (i == RI)
        sfSprite_move(enemy->all, move_right);
    if (i == UP)
        sfSprite_move(enemy->all, move_up);
    if (i == DOWN)
        sfSprite_move(enemy->all, move_down);
    if (i == LE)
        sfSprite_move(enemy->all, move_left);
    return (1);
}

int clock(spr_t *tkt, int i, enemy_t *enemy)
{
    float time = 0;
    static float g = 0;
    time = sfClock_getElapsedTime(tkt->clock).microseconds;
    if (time >= 100000 && i != 0) {
        move_gob(enemy);
        if (i == PV)
            enemy_tower(enemy, tkt);
        g+=0.25;
        sfClock_restart(tkt->clock);
    }
    if (i != 0) {
        enemy->move_on_map++;
        move_enemy(enemy, i);
        if (enemy->move_on_map >= 100) {
            enemy->move_on_map = 0;
            return (1);
        }
    }
    return (clock_snd(g, tkt));
}

int analyse_events(spr_t *tkt)
{
    int h_spr = 200;
    sfVector2i mou_pos = sfMouse_getPositionRenderWindow(tkt->window);

    while (sfRenderWindow_pollEvent(tkt->window, &tkt->event)) {
        if (tkt->event.type == sfEvtClosed ||
            sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(tkt->window);
        if ((tkt->event.type == sfEvtMouseButtonReleased) && (
            mou_pos.x <= 1000 + h_spr && mou_pos.x >= 1000
            && mou_pos.y >= 0 && mou_pos.y <= 0 + h_spr))
            tkt->state_turret = 1;
        else if ((tkt->event.type == sfEvtMouseButtonReleased) && (!(
            mou_pos.x <= 1000 + h_spr && mou_pos.x >= 1000
            && mou_pos.y >= 0 && mou_pos.y <= 0 + h_spr)))
            tkt->state_turret = 2;
    }
    return (0);
}

int beginthe_map(int *coor, enemy_t *enemy, spr_t *tkt)
{
    int nb_col = my_strlen(tkt->map);
    static int nb = 0;
    int i = 0;

    for (; tkt->map[i]; i = i + nb_col, coor[1] = coor[1] + 100) {
        if (tkt->map[i] == 'x')
            break;
        }
    clock(tkt, 0, enemy);
    if (nb == 0) {
        sfSprite_setPosition(enemy->all, (sfVector2f){coor[0], coor[1] - 30});
        nb++;
    }
    return (i);
}

enemy_t *reset_lc(enemy_t *tmp)
{
    while (tmp->prev != NULL) {
        tmp = tmp->prev;
    }
    return (tmp);
}
