/*
** EPITECH PROJECT, 2019
** Documents
** File description:
** utils
*/

#include "my.h"

int my_strlen(char *str)
{
    int i = 0;

    for (; str[i] != '\n'; i++);
    return (i + 1);
}

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *c)
{
    for (int i = 0; c[i]; i++)
        my_putchar(c[i]);
}
