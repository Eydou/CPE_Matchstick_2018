/*
** EPITECH PROJECT, 2019
** check_error.c
** File description:
** check error.
*/

#include "../include/my.h"

int setup_matches(game_t *po, int matches)
{
    if (matches > po->y) {
        my_putstr("you cannot remove more than ");
        my_put_nbr(po->y);
        my_putstr(" matches per turn");
        return (84);
    }
    if (matches == 0) {
        my_putstr("Error: you have to remove at least one match");
        return (84);
    }
}

int error_matches(game_t *po, int line, int matches)
{
    int ct = 0;

    ct = my_check_pipe(po, line, ct);

    if (setup_matches(po, matches) == 84)
        return (84);
    for (int i = 0; po->buffer[i] != '\n'; i++) {
        if (po->buffer[i] == '-' || matches == 0) {
            my_putstr("Error: you have to remove at least one match");
            return (84);
        }
        if (po->buffer[i] < '0' || po->buffer[i] > '9') {
            my_putstr("Error: invalid input (positive number expected)");
            return (84);
        }
    }
    if (matches > ct) {
        my_putstr("Error: not enough matches on this line");
        return (84);
    }
}

int error_line(int line, game_t *po)
{
    if (line > po->x) {
        my_putstr("Error: this line is out of range");
        return (84);
    }
    for (int i = 0; po->buffer[i] != '\n'; i++) {
        if (po->buffer[i] == '-') {
            my_putstr("Error: this line is out of range");
            return (84);
        }
        if (po->buffer[i] < '0' || po->buffer[i] > '9') {
            my_putstr("Error: invalid input (positive number expected)");
            return (84);
        }
    }
    if (line == 0) {
        my_putstr("Error: this line is out of range");
        return (84);
    }
}

int check_error(int ac, char **av)
{
    if (ac != 3 || av[1][0] == '0' || av[2][0] == '0'
        || my_atoi(av[1]) > 99 || my_atoi(av[1]) == 1)
        return (84);
    for (int i = 1; av[i] != NULL; i++) {
        for (int j = 0; av[i][j] != '\0'; j++) {
            if (av[i][j] < 48 || av[i][j] > 57)
                return (84);
        }
    }
}
