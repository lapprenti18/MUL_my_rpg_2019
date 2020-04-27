/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** handle_pause_click.c
*/

#include "../include/my.h"

void handle_pause_click(all_t *store, game_object_t *copy)
{
    if (copy->type == PAUSE_CONTINUE) {
        store->show_particules = false;
        store->scene = PLAYING;
        return;
    }
    if (copy->type == PAUSE_OPTIONS)
        store->scene = MENU_OPTIONS;
    if (copy->type == PAUSE_QUIT)
        store->scene = MENU;
    write_in_file(store);
}