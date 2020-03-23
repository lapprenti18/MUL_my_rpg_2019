/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** handle_saves_click.c
*/

#include "../include/my.h"

void handle_saves_click(all_t *store, game_object_t *copy)
{
    if (copy->type == BACK)
        store->scene = MENU;
    if (copy->type >= SAVE_1 && copy->type <= SAVE_4)
        store->scene = PLAYING;
}