/*
** EPITECH PROJECT, 2019
** MUL_my_world_2019
** File description:
** my_getfloat.c
*/

int my_getnbr(char *str);

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