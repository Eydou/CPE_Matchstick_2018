/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/

#include "include/my.h"

void print_map(game_t *po)
{
    for (int i = 0; i <= po->x + 1; i++) {
        my_putstr(po->arry[i]);
        my_putchar('\n');
    }
}

int my_pyramid(game_t *po)
{
    int pipe = 1;

    for (int i = 1; i != po->x + 1; i++) {
        for (int j = 1; j != po->x * 2 + 1; j++) {
            po->arry[i][j] = ' ';
        }
    }
    for (int i = 1; i != po->x + 1; i++, pipe += 2) {
        for (int j = 1; j != po->x * 2 + 1; j++) {
            po->arry[i][po->x] = '|';
            if (po->arry[i + 1][po->x] != pipe) {
                po->arry[i + j - 1][po->x + pipe / 2] = '|';
                po->arry[i + j - 1][po->x - pipe / 2] = '|';
            }
        }
    }
}

int my_column(game_t *po)
{
    my_pyramid(po);
    for (int a = 0; a < po->x * 2 + 1; a++) {
        po->arry[0][a] = '*';
        po->arry[po->x + 1][a] = '*';
    }
    for (int i = 1; i < po->x + 1; i++) {
        po->arry[i][0] = '*';
        po->arry[i][po->x * 2] = '*';
    }
    print_map(po);
}

int main(int ac, char **av)
{
    game_t *po;
    int value = 0;

    if (ac != 3)
        return (84);
    if (check_error(ac, av) == 84) {
        my_putstr("Error: letter or argument\n");
        return (84);
    }
    po = my_struct(po, ac, av);
    my_column(po);
    value = my_gameboard(po);
    if (value == 0)
        return (0);
    if (value == 1)
        return (1);
    if (value == 2)
        return (2);
}
