/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** my_getfloat.c
*/

#include "../../include/my.h"

int int_to_ascii(int number, char *buffer, int afterpoint)
{
    int index = 0;

    for (; number > 0; number /= 10) {
        buffer[index] = (number % 10) + '0';
        index += 1;
    }
    while (index < afterpoint) {
        buffer[index] = 0;
        index += 1;
    }
    buffer[index] = 0;
    my_revstr(buffer);
    return (index);
}

char *get_neg(char *buffer)
{
    int index = 0;

    my_revstr(buffer);
    for (; buffer[index]; index += 1);
    buffer[index] = '-';
    return (my_revstr(buffer));
}

char *my_ftoa(float number, char *buffer, int afterpoint)
{
    int i_part = 0;
    float f_part = 0.0;
    int index = 0;
    int check = 0;

    (number < 0) ? check = 1 : 0;
    (check == 1) ? number *= -1 : 0;
    i_part = (int)number;
    f_part = number - (float)i_part;
    index = int_to_ascii(i_part, buffer, 0);
    if (afterpoint != 0) {
        buffer[index] = '.';
        f_part = f_part * pow(10, afterpoint);
        int_to_ascii((int)f_part, buffer + index + 1, afterpoint);
    }
    if (check == 1)
        buffer = get_neg(buffer);
    return (buffer);
}

int is_num(char c)
{
    return (c >= '0' && c <= '9');
}

double my_getfloat(char *str)
{
    double result = 0.0;
    int index = 0;
    int pow = 1.0;
    int sign = 0;

    for (index = 0; str[index] == '+' || str[index] == '-'; index += 1)
        (str[index] == '-') ? sign += 1 : 0;
    for (; is_num(str[index]); index += 1)
        result = result * 10 + str[index] - '0';
    if (!str[index] || str[index] != '.' || !str[index + 1])
        return ((sign % 2 == 1) ? result * - 1 : result);
    for (index += 1; is_num(str[index]); index += 1) {
        result = result * 10 + str[index] - '0';
        pow *= 10;
    }
    result /= pow;
    if (sign % 2 == 1)
        result *= -1;
    return (result);
}