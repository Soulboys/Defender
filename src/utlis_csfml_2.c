/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** __DESCRIPTION__
*/

#include "my.h"

int button_sprite(spr_t *tkt, sfVector2f pos_sprite, int h_spr)
{
    sfEvent event;
    sfVector2i mou_pos = sfMouse_getPositionRenderWindow(tkt->window);

    while (sfRenderWindow_pollEvent(tkt->window, &event)) {
        if ((sfMouse_isButtonPressed(sfMouseLeft)) && (
            mou_pos.x <= pos_sprite.x + h_spr && mou_pos.x >= pos_sprite.x
            && mou_pos.y >= pos_sprite.y && mou_pos.y <= pos_sprite.y + h_spr))
                return (1);
    }
    return (1);
}
