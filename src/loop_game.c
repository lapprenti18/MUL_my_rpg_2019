/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** loop_game.c
*/

#include "../include/my.h"

void loop_game(all_t *store)
{
    while (sfRenderWindow_isOpen(store->window)) {
        sfRenderWindow_clear(store->window, sfBlack);
        while (sfRenderWindow_pollEvent(store->window, &store->event))
            analyse_events(store);
        draw_scene(store);
        //for (game_object_t *copy = store->objects[MENU]; copy; copy = copy->next)
        //    copy->change_pos(copy, (sfVector2f){0, 0});
        sfRenderWindow_display(store->window);
    }
}