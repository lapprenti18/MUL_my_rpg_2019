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
    if (copy->type == PLAY) {
        sfMusic_pause(store->musics[MENU]);
        sfMusic_play(store->musics[PLAYING]);
        store->scene = PLAYING;
    }
    if (copy->type == QUIT)
        sfRenderWindow_close(store->window);
}