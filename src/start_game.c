/*
** EPITECH PROJECT, 2019
** Documents
** File description:
** principal file defender
*/

#include "my.h"

int init_game(spr_t *tkt, enemy_t *enemy)
{
    sfTexture *back = sfTexture_createFromFile("obj/back.png", NULL);

    tkt->clock = sfClock_create();
    tkt->back = malloc(sizeof(sfSprite*) * 8);
    tkt->mouse = malloc(sizeof(sfSprite*) * 5);
    for (int i = 0; i < 8; i++)
        tkt->back[i] = create_sprite(back, 0.5);
    for (int i = 0; i < 5; i++)
        tkt->mouse[i] = create_sprite(back, 0.5);
    add_element(&enemy);
    set_rect(tkt);
    return (0);
}

void begin_game(spr_t *tkt, enemy_t *enemy)
{
    int i = 0;

    tkt->etat_game = 1;
    if (enemy != NULL)
        add_new_enemy(enemy, tkt);
}

int create_window(spr_t *tkt, enemy_t *enemy)
{
    sfVideoMode video_mode = {MAX_WIDTH, MAX_LENGTH, 32};

    tkt->window = sfRenderWindow_create(video_mode, "DDDDEEEFFFEEENNNDDDEERR",
    sfResize | sfClose, NULL);
    while (sfRenderWindow_isOpen(tkt->window)) {
        sfRenderWindow_display(tkt->window);
        sfRenderWindow_clear(tkt->window, sfBlack);
        drawback(tkt, enemy);
        analyse_events(tkt);
        draw_tex(tkt);
        begin_game(tkt, enemy);
    }
    return (0);
}
