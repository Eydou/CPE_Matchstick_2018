/*
** EPITECH PROJECT, 2019
** myai.c
** File description:
** myai.c
*/

#include "../include/my.h"

void my_setup_ai(int matches, int line)
{
    my_putstr("AI removed ");
    my_put_nbr(matches);
    my_putstr(" match(es) from line ");
    my_put_nbr(line);
    my_putchar('\n');
}

int brain_of_ai(game_t *po, int ct, int matches)
{
    if (matches % 4 == 0 || matches % 4 == 1
        || matches % 4 == 2 || matches % 4 == 3)
        matches = matches - 1;
    if (matches == 0)
        matches = 1;
    return (matches);
}

int ai_pipe(game_t *po)
{
    for (int i = 0; i != po->x + 1; i++) {
        for (int j = 0; j != po->x * 2 + 1; j++) {
            if (po->arry[i][j] == '|')
                return (i);
        }
    }
}

int my_ai(game_t *po, int matches, int line)
{
    int ct = 0;

    line = ai_pipe(po);
    matches = po->y;
    ct = my_check_pipe(po, line, ct);
    if (matches > ct)
        matches = ct;
    if (matches > po->y)
        matches = po->y;
    else {
        ct = my_check_pipe(po, line, ct);
        if (matches > ct)
            matches = ct;
        matches = brain_of_ai(po, ct, matches);
        my_setup_ai(matches, line);
        my_gamev2(po, line, matches);
        return (2);
    }
}
