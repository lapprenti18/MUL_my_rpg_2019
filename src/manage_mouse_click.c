/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** manage_mouse_click.c
*/

#include "../include/my.h"

void handle_audio_click(all_t *store, game_object_t *copy)
{
    if (copy->type == BACK)
        store->scene = MENU_OPTIONS;
}

void handle_options_click(all_t *store, game_object_t *copy)
{
    if (copy->type == BACK)
        store->scene = MENU;
    if (copy->type == AUDIO)
        store->scene = MENU_AUDIO;
}

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

void handle_click(all_t *store, game_object_t *copy)
{
    if (store->scene == MENU_AUDIO)
        return (handle_audio_click(store, copy));
    if (store->scene == MENU)
        return (handle_menu_click(store, copy));
    if (store->scene == MENU_OPTIONS)
        return (handle_options_click(store, copy));
}

void manage_mouse_clicked(all_t *store)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(store->window);

    for (game_object_t *copy = store->objects[store->scene]; \
    copy; copy = copy->next) {
        if (mouse.x >= copy->pos.x - (copy->length / 2) \
        && mouse.x <= copy->pos.x + (copy->length / 2) \
        && mouse.y >= copy->pos.y - (copy->height / 2) \
        && mouse.y <= copy->pos.y + (copy->height / 2))
            handle_click(store, copy);
    }
}