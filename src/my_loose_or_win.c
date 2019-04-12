/*
** EPITECH PROJECT, 2019
** my_loose_or_win.c
** File description:
** my_loose_or_win.
*/

#include "../include/my.h"

int my_winner(game_t *po)
{
    int a = 0;

    for (int i = 1; i != po->x + 1; i++) {
        for (int j = 1; j != po->x * 2 + 1; j++) {
            if (po->arry[i][j] == '|') {
                a = a + 1;
            }
        }
    }
    if (a == 0) {
        my_putstr("I lost... snif... but I'll get you next time!!\n");
        return (12);
    }
    a = 0;
}

int my_looser(game_t *po)
{
    int a = 0;

    for (int i = 1; i != po->x + 1; i++) {
        for (int j = 1; j != po->x * 2 + 1; j++) {
            if (po->arry[i][j] == '|') {
                a = a + 1;
            }
        }
    }
    if (a == 0) {
        my_putstr("You lost, too bad...\n");
        return (12);
    }
    a = 0;
}
