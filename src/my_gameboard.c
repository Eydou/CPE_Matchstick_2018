/*
** EPITECH PROJECT, 2019
** my_gameboard.
** File description:
** my_gameboard.
*/

#include "../include/my.h"

void my_setup_player(int matches, int line)
{
    my_putstr("Player removed ");
    my_put_nbr(matches);
    my_putstr(" match(es) from line ");
    my_put_nbr(line);
    my_putchar('\n');
}

int my_check_pipe(game_t *po, int line, int ct)
{
    for (int j = 1; j != po->x * 2 + 1; j++) {
        if (po->arry[line][j] == '|') {
            ct = ct + 1;
        }
    }
    return (ct);
}

void my_gamev2(game_t *po, int line, int matches)
{
    for (int i = po->x * 2; i != 0; i--) {
        if (po->arry[line][i] == '|') {
            po->arry[line][i] = ' ';
            matches--;
        }
        if (matches == 0)
            break;
    }
    print_map(po);
}

int my_player(game_t *po, int matches, int line)
{
    while (1) {
        my_putstr("\nLine: ");
        if (po->chara = getline(&(po->buffer), &(po->bufsize), stdin) == - 1)
            return (12);
        line = my_atoi(po->buffer);
        if (error_line(line, po) == 84) {
        } else {
            my_putstr("Matches: ");
            if (po->chara = getline(&(po->buffer), &(po->bufsize), stdin) == -1)
                return (12);
            matches = my_atoi(po->buffer);
            if (error_matches(po, line, matches) == 84) {
            } else {
                my_setup_player(matches, line);
                my_gamev2(po, line, matches);
                return (1);
            }
        }
    }
}

int my_gameboard(game_t *po)
{
    int matches = 0;
    int line = 0;

    while (1) {
        my_putstr("\nYour turn:");
        if (my_player(po, matches, line) == 12)
            return (0);
        if (my_looser(po) == 12)
            return (2);
        my_putstr("\nAI's turn...\n");
        if (my_ai(po, matches, line) == 12)
            return (0);
        if (my_winner(po) == 12)
            return (1);
    }
}
