/*
** EPITECH PROJECT, 2018
** my_atoi.c
** File description:
** char to int.
*/

int my_atoi(char const *str)
{
    int i = 0;
    int nb = 0;

    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            nb = nb * 10;
            nb = nb + str[i] - '0';
        }
        i = i + 1;
    }
    return (nb);
}
