/*
** EPITECH PROJECT, 2019
** getnbr
** File description:
** getnbr
*/

#include "../../include/my.h"

char *my_int_to_ascii(int number)
{
    char *result = NULL;
    int len = 0;

    if (number == 0)
        return ("0");
    for (int save = number; save > 0; save /= 10)
        len += 1;
    result = my_malloc(sizeof(char) * len + 1);
    my_memset(result, 0, len + 1);
    for (int index = 0; number > 0; number /= 10) {
        result[index] = number % 10 + '0';
        index += 1;
    }
    return (my_revstr(result));
}

int my_getnbr(char const *str)
{
    int nb_moins = 0;
    int cursor = 0;
    int result = 0;

    for (cursor = 0; str[cursor] == '-'; cursor += 1)
        nb_moins += 1;
    for (; str[cursor] && (str[cursor] >= '0' && str[cursor] <= '9'); \
    cursor += 1) {
        result *= 10;
        result += (str[cursor] - '0');
    }
    if (nb_moins % 2 == 1)
        result *= -1;
    return (result);
}