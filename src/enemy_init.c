/*
** EPITECH PROJECT, 2019
** Delivery
** File description:
** __DESCRIPTION__
*/

#include "my.h"

int add_element_snd(enemy_t **enemy, enemy_t *tmp, enemy_t *new, int nb)
{
    if (tmp == NULL) {
        *enemy = new;
    } else {
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        new->prev = tmp;
        tmp->next = new;
    }
    nb++;
    return (nb);
}

int add_element(enemy_t **enemy)
{
    enemy_t *new = malloc(sizeof(*new));
    enemy_t *tmp;
    static int nb = 0;

    tmp = *enemy;
    new->tmp = 0;
    new->move = 0;
    new->move_on_map = 0;
    new->etat = 1;
    new->nb_gob = nb;
    set_enemy(new);
    new->next = NULL;
    new->prev = NULL;
    nb = add_element_snd(enemy, tmp, new, nb);
}
