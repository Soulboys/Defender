/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** utils.c
*/

#include "my.h"

sfSprite *create_sprite(sfTexture *texture, float size)
{
    sfSprite *sprite;
    sfVector2f scale = {size, size};

    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, scale);
    return (sprite);
}

sfText *create_text(char *string, int size, sfFont *font)
{
    sfText *text;

    text = sfText_create();
    sfText_setString(text, string);
    sfText_setFont(text, font);
    sfText_setColor(text, sfWhite);
    sfText_setCharacterSize(text, size);
    return (text);
}

void draw_sprite(sfSprite *sprite, int x, int y, sfRenderWindow *window)
{
    sfVector2f position = {x, y};

    sfSprite_setPosition(sprite, position);
    sfRenderWindow_drawSprite(window , sprite, NULL);
}

void draw_text(sfText *text, int x, int y, sfRenderWindow *window)
{
    sfVector2f position = {x, y};

    sfText_setPosition(text, position);
    sfRenderWindow_drawText(window, text, NULL);
}

sfIntRect create_rec(int top, int left, int width, int height)
{
    sfIntRect rec;

    rec.top = top;
    rec.left = left;
    rec.width = width;
    rec.height = height;
    return (rec);
}
