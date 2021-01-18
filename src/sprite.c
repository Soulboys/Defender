/*
** EPITECH PROJECT, 2019
** Documents
** File description:
** sprite defender
*/

#include "my.h"

int set_rect(spr_t *tkt)
{
    tkt->rect_back = malloc(sizeof(sfIntRect) * 8);
    tkt->rect_mouse = malloc(sizeof(sfIntRect) * 5);
    tkt->rect_back[BACK] = create_rec(0, 0, 200, 200);
    tkt->rect_back[ROCK] = create_rec(0, 400, 200, 200);
    tkt->rect_back[RIGHT] = create_rec(0, 800, 200, 200);
    tkt->rect_back[PLACE] = create_rec(0, 1400, 200, 200);
    tkt->rect_back[TURN] = create_rec(800, 0, 200, 200);
    tkt->rect_back[TURRET] = create_rec(400, 1800, 200, 200);
    tkt->rect_back[TOWER] = create_rec(0, 1800, 200, 200);
    tkt->rect_back[BACK_T] = create_rec(800, 800, 200, 200);
    tkt->rect_mouse[BACK] = create_rec(400, 0, 200, 200);
    tkt->rect_mouse[ROCK] = create_rec(400, 400, 200, 200);
    tkt->rect_mouse[RIGHT] = create_rec(400, 800, 200, 200);
    tkt->rect_mouse[PLACE] = create_rec(400, 1400, 200, 200);
    tkt->rect_mouse[TURN] = create_rec(800, 400, 200, 200);
    set_rect_sprite(tkt);
    return (0);
}

void set_text(spr_t *tkt)
{
    int size = 60;
    char *pv = int_to_str(tkt->pv);
    char *g = int_to_str(tkt->gold);
    sfFont* font = sfFont_createFromFile("obj/font_test.otf");

    tkt->Tpv = sfText_create();
    tkt->Tgold = sfText_create();
    sfText_setString(tkt->Tpv, pv);
    sfText_setString(tkt->Tgold, g);
    sfText_setFont(tkt->Tgold, font);
    sfText_setFont(tkt->Tpv, font);
    sfText_setColor(tkt->Tpv, sfWhite);
    sfText_setColor(tkt->Tgold, sfBlack);
    sfText_setCharacterSize(tkt->Tpv, size);
    sfText_setCharacterSize(tkt->Tgold, size);
}

int set_rect_sprite(spr_t *tkt)
{
    sfVector2f origin = {100, 100};

    for (int i = 0; tkt->map[i]; i++)
        if (tkt->map[i] == 'd')
            tkt->nb_turret++;
    tkt->nb_turret--;
    tkt->if_turret = malloc(sizeof(int) * tkt->nb_turret);
    for (int i = 0; i <= tkt->nb_turret + 1; i++) {
        tkt->if_turret[i] = 0;
    }
    sfSprite_setOrigin(tkt->back[TURRET], origin);
    for (int i = 0; i < 8; i++)
        sfSprite_setTextureRect(tkt->back[i], tkt->rect_back[i]);
    for (int i = 0; i < 5; i++)
        sfSprite_setTextureRect(tkt->mouse[i], tkt->rect_mouse[i]);
    tkt->pv = 10000;
    tkt->gold = 50;
    set_text(tkt);
    return (0);
}

int turn_turret(spr_t *tkt, int *coor, enemy_t *enemy)
{
    float angle = 0;
    sfFloatRect a = sfSprite_getGlobalBounds(tkt->back[TURRET]);
    sfFloatRect b = sfSprite_getGlobalBounds(enemy->all);
    float x = b.left - a.left;
    float y = b.top - a.top;

    if (x == 0)
        x++;
    angle = atan(y / x) * (180/M_PI);
    if ((y <= 0) && (x >= 0)) {
        sfSprite_setRotation(tkt->back[TURRET], angle - 270);
    }
    else if ((y >= 0) && (x >= 0)) {
        sfSprite_setRotation(tkt->back[TURRET], angle + 90);
    }
    else if ((y <= 0) && (x <= 0)) {
        sfSprite_setRotation(tkt->back[TURRET], angle + 270);
    }
    else if ((y >= 0) && (x <= 0)) {
        sfSprite_setRotation(tkt->back[TURRET], angle + 270);
    }
    draw_sprite(tkt->back[TURRET], coor[0] + 50, coor[1] + 50, tkt->window);
    return (0);
}

int tower(spr_t *tkt, enemy_t *enemy, int *coor)
{
    sfVector2i mou_pos = sfMouse_getPositionRenderWindow(tkt->window);
    int h_spr = 100;
    static int nb_t = 0;

    if (tkt->state_turret == 1 && (mou_pos.x <= coor[0] +
    h_spr && mou_pos.x >= coor[0]
    && mou_pos.y >= coor[1] && mou_pos.y <= coor[1] + h_spr)) {
        if_mouse(tkt->mouse[PLACE], coor, tkt->back[PLACE], tkt);
        draw_sprite(tkt->back[TURRET], coor[0] + 50, coor[1]+ 50,  tkt->window);
    }
    if (tkt->state_turret == 1 &&
    (tkt->event.type == sfEvtMouseButtonPressed && mou_pos.x <= coor[0] +
    h_spr && mou_pos.x >= coor[0] && mou_pos.y >= coor[1] &&
    mou_pos.y <= coor[1] + h_spr) && tkt->if_turret[nb_t] == 0 && tkt->gold >= 50) {
        tkt->if_turret[nb_t] = 1;
        tkt->gold -= 50;
    } else if (tkt->if_turret[nb_t] == 0)
    if_mouse(tkt->mouse[PLACE], coor, tkt->back[PLACE], tkt);
    else if (tkt->if_turret[nb_t] == 1) {
        if_mouse(tkt->mouse[PLACE], coor, tkt->back[PLACE], tkt);
        turn_turret(tkt, coor, enemy);
    }
    nb_t >= tkt->nb_turret ? (nb_t = 0) : (nb_t++);
    return (0);
}
