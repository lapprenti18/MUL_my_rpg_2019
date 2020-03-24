/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** loop_game.c
*/

#include "../include/my.h"

void loop_game(all_t *store)
{
    sfMusic_play(store->musics[MENU]);
    while (sfRenderWindow_isOpen(store->window)) {
        sfRenderWindow_clear(store->window, sfCyan);
        while (sfRenderWindow_pollEvent(store->window, &store->event))
            analyse_events(store);
        manage_all_clock(store);
        draw_scene(store);
        sfRenderWindow_display(store->window);
    }
}