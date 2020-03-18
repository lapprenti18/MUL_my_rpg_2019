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

    srand(time(NULL));
    set_structures(&store);
    loop_game(&store);
    destroy_structures(&store);
    return (0);
}