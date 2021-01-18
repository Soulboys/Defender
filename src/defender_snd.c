/*
** EPITECH PROJECT, 2019
** Documents
** File description:
** principal file defender
*/

#include "my.h"

int clock_snd(int g, spr_t *tkt)
{
    if (g >= 1) {
        tkt->gold++;
        g = 0;
    }
    return (0);
}

int add_new_enemy(enemy_t *tmp, spr_t *tkt)
{
    int i = 0;
    int *coor = malloc(sizeof(int) * 2);
    int static nb = 0;

    coor[0] = 0;
    coor[1] = 0;
    if (tmp->etat == 0)
        tmp = tmp->next;
        i = beginthe_map(coor, tmp, tkt);
        walk(tkt, i, tmp);
        sfRenderWindow_drawSprite(tkt->window , tmp->all, NULL);

}

void draw_tex(spr_t *tkt)
{
    char *pv_c = int_to_str(tkt->pv);
    char *golde = int_to_str(tkt->gold);
    my_revstr(pv_c);
    my_revstr(golde);
    sfVector2f position = {1692, 430};
    sfVector2f position1 = {800, 10};

    sfText_setPosition(tkt->Tpv, position);
    sfText_setPosition(tkt->Tgold, position1);
    sfText_setString(tkt->Tpv, pv_c);
    sfText_setString(tkt->Tgold, golde);
    sfRenderWindow_drawText(tkt->window, tkt->Tpv, NULL);
    sfRenderWindow_drawText(tkt->window, tkt->Tgold, NULL);
}

char *readl(char *file)
{
    int thecat = 6;
    char *buff = malloc(sizeof(char) * 2975);
    int size = 1;

    thecat = open(file, O_RDONLY);
    if (thecat == -1) {
        write(1, "No such file or directory\n use -h\n", 26);
        return (NULL);
    }
    size = read(thecat, buff, 2975);
    buff[size] = '\0';
    close(thecat);
    return (buff);
}
