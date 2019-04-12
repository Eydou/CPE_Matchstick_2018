/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** Display numbers.
*/

#include "../../include/my.h"

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        my_put_nbr(nb * (-1));
    } else {
        if (nb < 10) {
            my_putchar(nb + 48);
        } else {
            my_put_nbr(nb / 10);
            my_put_nbr(nb % 10);
        }
    }
    return (0);
}
