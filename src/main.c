/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** main.c
*/

#include "../include/my.h"

int main(void)
{
    all_t store;

    set_structures(&store);
    loop_game(&store);
    return (0);
}