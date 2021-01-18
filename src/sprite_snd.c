/*
** EPITECH PROJECT, 2019
** Documents
** File description:
** sprite defender
*/

#include "my.h"

int drawback(spr_t *tkt, enemy_t *enemy)
{
    int i = 0;
    int *coor = malloc(sizeof(int) * 2);
    coor[0] = 0;
    coor[1] = 0;

    for (; tkt->map[i]; i++, coor[0] = coor[0] + 100) {
        if (i != 0 && tkt->map[i - 1] == '\n') {
            coor[1] = coor[1] + 100;
            coor[0] = 0;
        }
        switch (tkt->map[i]) {
            case ('o'):
            if_mouse(tkt->mouse[BACK], coor, tkt->back[BACK], tkt);
            break;
            case ('c'):
            if_mouse(tkt->mouse[ROCK], coor, tkt->back[ROCK], tkt);
            break;
            case ('d'):
            tower(tkt, enemy, coor);
            break;
            case ('x'):
            rotate_sprite_right(tkt, i, coor);
            rotate_sprite_turn(tkt, i, coor);
            break;
            case ('t'):
            draw_sprite(tkt->back[TOWER], coor[0], coor[1], tkt->window);
            break;
            case ('m'):
            draw_sprite(tkt->back[BACK_T], coor[0], coor[1], tkt->window);
            break;
        }
    }
    return (0);
}

int rotate_sprite_turn(spr_t *tkt, int i, int *coor)
{
    int nb_col = my_strlen(tkt->map);

    if (tkt->map[i - 1] == 'x' && tkt->map[i + nb_col] == 'x') {
        sfSprite_setRotation(tkt->back[TURN], 180);
        draw_sprite(tkt->back[TURN], coor[0] + 100, coor[1] + 100, tkt->window);
    } else if (tkt->map[i - 1] == 'x' && tkt->map[i - nb_col] == 'x') {
        sfSprite_setRotation(tkt->back[TURN], 270);
        draw_sprite(tkt->back[TURN], coor[0], coor[1] + 100, tkt->window);
    } else if (tkt->map[i + 1] == 'x' && tkt->map[i + nb_col] == 'x') {
        sfSprite_setRotation(tkt->back[TURN], 90);
        draw_sprite(tkt->back[TURN], coor[0] + 100, coor[1], tkt->window);
    } else if (tkt->map[i + 1] == 'x' && tkt->map[i - nb_col] == 'x') {
        sfSprite_setRotation(tkt->back[TURN], 0);
        draw_sprite(tkt->back[TURN], coor[0], coor[1], tkt->window);
    }
    sfSprite_setRotation(tkt->back[TURN], 0.0);
    return (0);
}

int rotate_sprite_right(spr_t *tkt, int i, int *coor)
{
    int nb_col = my_strlen(tkt->map);

    if (tkt->map[i - 1] == 'x' || tkt->map[i + 1] == 'x') {
        sfSprite_setRotation(tkt->back[RIGHT], 90);
        draw_sprite(tkt->back[RIGHT], coor[0] + 100, coor[1], tkt->window);
    } else if (tkt->map[i - nb_col] == 'x' && tkt->map[i + nb_col] == 'x') {
        sfSprite_setRotation(tkt->back[RIGHT], 0);
        draw_sprite(tkt->back[RIGHT], coor[0], coor[1], tkt->window);
    }
    sfSprite_setRotation(tkt->back[RIGHT], 0.0);
    return (0);
}
