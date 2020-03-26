/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** handle_options_click.c
*/

#include "../include/my.h"

void handle_options_click(all_t *store, game_object_t *copy)
{
    if (copy->type == BACK)
        store->scene = MENU;
    if (copy->type == AUDIO)
        store->scene = MENU_AUDIO;
    if (copy->type == VIDEO)
        store->scene = MENU_VIDEO;
    if (copy->type == KEYBOARD)
        store->scene = MENU_KEYBOARD;
}