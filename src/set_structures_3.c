/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** set_structures_3.c
*/

#include "../include/my.h"

char **init_filepath(void)
{
    char **tab = my_malloc(sizeof(char *) * 6);

    tab[0] = "assets/textures/map1_premier_plan.png";
    tab[1] = "assets/textures/mapshop_premier_plan.png";
    tab[2] = "assets/textures/map3_premier_plan.png";
    tab[3] = "assets/textures/map4_premier_plan.png";
    tab[4] = "assets/textures/map5_premier_plan.png";
    tab[5] = "assets/textures/map6_premier_plan.png";
    tab[6] = NULL;
    return (tab);
}