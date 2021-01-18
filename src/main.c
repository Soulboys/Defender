/*
** EPITECH PROJECT, 2019
** MUL_my_defender_2018
** File description:
** __DESCRIPTION__
*/

#include "my.h"

void helpb(void)
{
    my_putstr("Finite defender created with CSFML.\n USAGE\n./my_defender map");
    my_putstr(".txt\nOPTIONS\n-h pri");
    my_putstr("nt the usage and quit.\nUSER INTERACTIONS\n");
}

int main(int argc, char **argv)
{
    spr_t *tkt = malloc(sizeof(*tkt));
    enemy_t *enemy = malloc(sizeof(*enemy));

    tkt->pv = 0;
    for (int i = 0; argv[i]; i++)
        if (argv[i][0] == '-')
            if (argv[i][1] == 'h') {
                helpb();
                return (1);
            }
    if (argc == 2)
        tkt->map = readl(argv[1]);
    else
        my_putstr("invalid file\n");
    if (tkt->map == NULL)
        return (84);
    init_game(tkt, enemy);
    create_window(tkt, enemy);
    return (0);
}
