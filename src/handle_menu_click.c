/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** handle_menu_click.c
*/

#include "../include/my.h"

void handle_menu_click(all_t *store, game_object_t *copy)
{
    if (copy->type == OPTIONS)
        store->scene = MENU_OPTIONS;
    if (copy->type == PLAY)
        store->scene = SAVES_SCREEN;
    if (copy->type == QUIT)
        sfRenderWindow_close(store->window);
    if (copy->type == EXTRAS) {
        store->show_particules = false;
        store->scene = CREDITS;
    }
}