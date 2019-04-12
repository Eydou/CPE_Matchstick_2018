/*
** EPITECH PROJECT, 2019
** my_struct.
** File description:
** my_struct.
*/

#include "../include/my.h"

char **my_mallocarry(game_t *po)
{
    po->arry = malloc(sizeof(char *) * po->x + 20000);
    for (int i = 0; i != po->x + 300; i++)
        po->arry[i] = malloc(sizeof(char) * po->x * 2 + 20000);
    return (po->arry);
}

game_t *my_struct(game_t *po, int ac, char **av)
{
    po = malloc(sizeof(game_t));
    po->bufsize = 0;
    po->buffer = NULL;
    po->a = 1;
    po->x = my_atoi(av[1]);
    po->y = my_atoi(av[2]);
    po->arry = my_mallocarry(po);

    return (po);
}
