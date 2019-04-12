/*
** EPITECH PROJECT, 2019
** my_h.
** File description:
** my_h.
*/

#ifndef my_h
#define my_h

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>

typedef struct game {
    size_t bufsize;
    size_t chara;
    char *buffer;
    char **arry;
    int a;
    int x;
    int y;
} game_t;

    /* src */

void my_gamev2(game_t *po, int line, int matches);
int my_ai(game_t *po, int matches, int line);
int my_looser(game_t *po);
int my_winner(game_t *po);
game_t *my_struct(game_t *po, int ac, char **av);
int my_gameboard(game_t *po);
void print_map(game_t *po);
int check_error(int ac, char **av);
int error_line(int line, game_t *po);
int error_matches(game_t *po, int line, int matches);
int my_check_pipe(game_t *po, int line, int ct);

    /* lib */

void my_putchar(char c);
int my_atoi(char const *str);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_put_nbr(int nb);

#endif /* my.h */
